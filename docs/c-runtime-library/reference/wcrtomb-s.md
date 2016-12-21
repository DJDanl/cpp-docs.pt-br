---
title: "wcrtomb_s | Microsoft Docs"
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
  - "wcrtomb_s"
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
  - "wcrtomb_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "caracteres largos, convertendo"
  - "Função wcrtomb_s"
  - "caracteres multibyte"
  - "caracteres, convertendo"
ms.assetid: 9a8a1bd0-1d60-463d-a3a2-d83525eaf656
caps.latest.revision: 22
caps.handback.revision: 22
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# wcrtomb_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converta um caractere largo em sua representação de caracteres multibyte. Uma versão de [wcrtomb](../../c-runtime-library/reference/wcrtomb.md) com aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
errno_t wcrtomb_s(  
   size_t *pReturnValue,  
   char *mbchar,  
   size_t sizeOfmbchar,  
   wchar_t *wchar,  
   mbstate_t *mbstate  
);  
template <size_t size>  
errno_t wcrtomb_s(  
   size_t *pReturnValue,  
   char (&mbchar)[size],  
   wchar_t *wchar,  
   mbstate_t *mbstate  
); // C++ only  
```  
  
#### Parâmetros  
 \[out\] `pReturnValue`  
 Retorna o número de bytes gravados ou \-1 se ocorreu um erro.  
  
 \[out\] `mbchar`  
 O multibyte resultante convertido de caractere.  
  
 \[in\] `sizeOfmbchar`  
 O tamanho do `mbchar` variável em bytes.  
  
 \[in\] `wchar`  
 Um caractere largo para converter.  
  
 \[in\] `mbstate`  
 Um ponteiro para um `mbstate_t` objeto.  
  
## Valor de retorno  
 Retorna zero ou uma `errno` valor se ocorrer um erro.  
  
## Comentários  
 O `wcrtomb_s` função converte um caractere largo, começando no estado de conversão especificada contido no `mbstate`, do valor contido no `wchar`, no endereço representado por `mbchar`. O `pReturnValue` valor será o número de bytes convertidos, mas não mais de `MB_CUR_MAX` bytes ou um \-1 se ocorreu um erro.  
  
 Se `mbstate` for nulo, interno `mbstate_t` estado de conversão é usado. Se o caractere contido em `wchar` não tem um caractere multibyte correspondente, o valor de `pReturnValue` será \-1 e a função retornará o `errno` valor de `EILSEQ`.  
  
 O `wcrtomb_s` função difere da [wctomb\_s, \_wctomb\_s\_l](../../c-runtime-library/reference/wctomb-s-wctomb-s-l.md) por sua capacidade de reinicialização. O estado de conversão é armazenado em `mbstate` para chamadas subseqüentes para o mesmo ou outras funções reiniciáveis. Resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciável. Por exemplo, um aplicativo usaria `wcsrlen` em vez de `wcslen`, se uma chamada subsequente para `wcsrtombs_s` foram usados em vez de `wcstombs_s.`  
  
 No C\+\+, usando essa função é simplificado pela sobrecargas de modelo; as sobrecargas podem inferir o comprimento do buffer automaticamente \(eliminando a necessidade de especificar um argumento de tamanho\) e eles podem substituir automaticamente funções mais antigas e não seguras com suas contrapartes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
## Exceções  
 O `wcrtomb_s` função é safe multithread desde que nenhuma função no thread atual chama `setlocale` enquanto esta função está em execução e o `mbstate` é nulo.  
  
## Exemplo  
  
```  
// crt_wcrtomb_s.c  
// This program converts a wide character  
// to its corresponding multibyte character.  
//  
  
#include <string.h>  
#include <stdio.h>  
#include <wchar.h>  
  
int main( void )  
{  
    errno_t     returnValue;  
    size_t      pReturnValue;  
    mbstate_t   mbstate;  
    size_t      sizeOfmbStr = 1;  
    char        mbchar = 0;  
    wchar_t*    wchar = L"Q\0";  
  
    // Reset to initial conversion state  
    memset(&mbstate, 0, sizeof(mbstate));  
  
    returnValue = wcrtomb_s(&pReturnValue, &mbchar, sizeof(char),  
                            *wchar, &mbstate);  
    if (returnValue == 0) {  
        printf("The corresponding wide character \"");  
        wprintf(L"%s\"", wchar);  
        printf(" was converted to a the \"%c\" ", mbchar);  
        printf("multibyte character.\n");  
    }  
    else  
    {  
        printf("No corresponding multibyte character "  
               "was found.\n");  
    }  
}  
```  
  
```Output  
O caractere largo correspondente "Q" foi convertido em um caractere multibyte "Q".  
```  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`wcrtomb_s`|\< WCHAR \>|  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [mbsinit](../../c-runtime-library/reference/mbsinit.md)