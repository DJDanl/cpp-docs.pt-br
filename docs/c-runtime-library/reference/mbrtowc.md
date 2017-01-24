---
title: "mbrtowc | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "mbrtowc"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-convert-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "mbrtowc"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função mbrtowc"
ms.assetid: a1e87fcc-6de0-4ca1-bf26-508d28490286
caps.latest.revision: 15
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# mbrtowc
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converta um caractere multibyte na localidade atual do caractere largo equivalente, com a capacidade de reinicialização no meio de um caractere multibyte.  
  
## Sintaxe  
  
```  
size_t mbrtowc(  
   wchar_t *wchar,  
   const char *mbchar,  
   size_t count,  
   mbstate_t *mbstate  
);  
```  
  
#### Parâmetros  
 `wchar`  
 Endereço de um caractere largo para receber a cadeia de caracteres largos convertido \(tipo `wchar_t`\).  Esse valor pode ser um ponteiro nulo se nenhum caractere de retorno de longa é necessário.  
  
 `mbchar`  
 Endereço de uma seqüência de bytes \(um caractere multibyte\).  
  
 `count`  
 Número de bytes para verificar.  
  
 `mbstate`  
 Ponteiro para o objeto de estado de conversão.  Se esse valor for um ponteiro nulo, a função usa um objeto de estado estático conversão interna.  Porque o interno `mbstate_t` objeto não é thread\-safe, recomendamos que você sempre passa seu próprio `mbstate` argumento.  
  
## Valor de retorno  
 Um dos seguintes valores:  
  
 0  
 O próximo `count` ou menos bytes concluir os caracteres multibyte que representa o caractere largo null, que é armazenado em `wchar`, se `wchar` não for um ponteiro nulo.  
  
 1 para `count`, inclusive  
 O próximo `count` ou menos bytes concluir um caractere multibyte válido.  O valor retornado é o número de bytes que concluir os caracteres multibyte.  O equivalente de caractere largo é armazenado em `wchar`, se `wchar` não for um ponteiro nulo.  
  
 \(size\_t\) \(\-1\)  
 Erro de codificação.  O próximo `count` ou menos bytes não contribuem para um caractere multibyte completo e válido.  Nesse caso, `errno` é definido como EILSEQ e o estado de shift conversão em `mbstate` for especificado.  
  
 \(size\_t\) \-\(2\)  
 O próximo `count` bytes contribuem para um caractere multibyte incompleto, mas potencialmente válido e todos os `count` bytes foram processadas.  Nenhum valor é armazenado em `wchar`, mas `mbstate` é atualizada para reiniciar a função.  
  
## Comentários  
 Se `mbchar` for um ponteiro nulo, a função é equivalente à chamada:  
  
 `mbrtowc(NULL, "", 1, &mbstate)`  
  
 Nesse caso, o valor dos argumentos `wchar` e `count` são ignorados.  
  
 Se `mbchar` não é um ponteiro nulo, examina a função `count` bytes do `mbchar` para determinar o número necessário de bytes que são necessárias para concluir o próximo caractere multibyte.  Se o próximo caractere for válido, o caractere multibyte correspondente é armazenado em `wchar` se não for um ponteiro nulo.  Se o caractere for correspondente nulo ampla de caracteres, o estado resultante do `mbstate` é o estado inicial de conversão.  
  
 O `mbrtowc` função difere da [mbtowc, \_mbtowc\_l](../Topic/mbtowc,%20_mbtowc_l.md) por sua capacidade de reinicialização.  O estado de conversão é armazenado em `mbstate` para chamadas subseqüentes para o mesmo ou outras funções reinicializáveis.  Resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciável.  Por exemplo, um aplicativo deve usar `wcsrlen` em vez de `wcslen` se uma chamada subsequente `wcsrtombs` é usado em vez de `wcstombs`.  
  
## Exemplo  
 Converte um caractere multibyte em seu equivalente de caractere largo.  
  
```  
// crt_mbrtowc.cpp  
  
#include <stdio.h>  
#include <mbctype.h>  
#include <string.h>  
#include <locale.h>  
#include <wchar.h>  
  
#define BUF_SIZE 100  
  
int Sample(char* szIn, wchar_t* wcOut, int nMax)  
{  
    mbstate_t   state = {0}; // Initial state  
    size_t      nConvResult,   
                nmbLen = 0,  
                nwcLen = 0;  
    wchar_t*    wcCur = wcOut;  
    wchar_t*    wcEnd = wcCur + nMax;  
    const char* mbCur = szIn;  
    const char* mbEnd = mbCur + strlen(mbCur) + 1;  
    char*       szLocal;  
  
    // Sets all locale to French_Canada.1252  
    szLocal = setlocale(LC_ALL, "French_Canada.1252");  
    if (!szLocal)  
    {  
        printf("The fuction setlocale(LC_ALL, \"French_Canada.1252\") failed!\n");  
        return 1;  
    }  
  
    printf("Locale set to: \"%s\"\n", szLocal);  
  
    // Sets the code page associated current locale's code page  
    // from a previous call to setlocale.  
    if (_setmbcp(_MB_CP_SBCS) == -1)  
    {  
        printf("The fuction _setmbcp(_MB_CP_SBCS) failed!");  
        return 1;  
    }  
  
    while ((mbCur < mbEnd) && (wcCur < wcEnd))  
    {  
        //  
        nConvResult = mbrtowc(wcCur, mbCur, 1, &state);  
        switch (nConvResult)  
        {  
            case 0:  
            {  // done  
                printf("Conversion succeeded!\nMultibyte String: ");  
                printf(szIn);  
                printf("\nWC String: ");  
                wprintf(wcOut);  
                printf("\n");  
                mbCur = mbEnd;  
                break;  
            }  
  
            case -1:  
            {  // encoding error  
                printf("The call to mbrtowc has detected an encoding error.\n");  
                mbCur = mbEnd;  
                break;  
            }  
  
            case -2:  
            {  // incomplete character  
                if   (!mbsinit(&state))  
                {  
                    printf("Currently in middle of mb conversion, state = %x\n", state);  
                    // state will contain data regarding lead byte of mb character  
                }  
  
                ++nmbLen;  
                ++mbCur;  
                break;  
            }  
  
            default:  
            {  
                if   (nConvResult > 2) // The multibyte should never be larger than 2  
                {  
                    printf("Error: The size of the converted multibyte is %d.\n", nConvResult);  
                }  
  
                ++nmbLen;  
                ++nwcLen;  
                ++wcCur;  
                ++mbCur;  
            break;  
            }  
        }  
    }  
  
   return 0;  
}  
  
int main(int argc, char* argv[])  
{  
    char    mbBuf[BUF_SIZE] = "AaBbCc\x9A\x8B\xE0\xEF\xF0xXyYzZ";  
    wchar_t wcBuf[BUF_SIZE] = {L''};  
  
    return Sample(mbBuf, wcBuf, BUF_SIZE);  
}  
```  
  
## Saída de Exemplo  
  
```  
Locale set to: "French_Canada.1252"  
Conversion succeeded!  
Multibyte String: AaBbCcÜïα∩≡xXyYzZ  
WC String: AaBbCcÜïα∩≡xXyYzZ  
```  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`mbrtowc`|\< WCHAR. h \>|  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)