---
title: "mbrlen | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "mbrlen"
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
  - "api-ms-win-crt-string-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "mbrlen"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função mbrlen"
ms.assetid: dde8dee9-e091-4c4c-81b3-639808885ae1
caps.latest.revision: 16
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# mbrlen
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determine o número de bytes que são necessárias para concluir um caractere multibyte na localidade atual, com a capacidade de reinicialização no meio de um caractere multibyte.  
  
## Sintaxe  
  
```  
size_t mbrlen(  
   const char * str,  
   size_t count,  
   mbstate_t * mbstate  
);  
```  
  
#### Parâmetros  
 `str`  
 Ponteiro para o próximo byte para inspecionar em uma cadeia de caracteres multibyte.  
  
 `count`  
 O número máximo de bytes a ser inspecionado.  
  
 `mbstate`  
 Ponteiro para o estado atual do deslocamento do byte inicial do `str`.  
  
## Valor de retorno  
 Um dos seguintes valores:  
  
 0  
 O próximo `count` ou menos bytes concluir os caracteres multibyte que representa o caractere nulo de largo.  
  
 1 para `count`, inclusive  
 O próximo `count` ou menos bytes concluir um caractere multibyte válido.  O valor retornado é o número de bytes que concluir os caracteres multibyte.  
  
 \(size\_t\) \-\(2\)  
 O próximo `count` bytes contribuem para um caractere multibyte incompleto, mas potencialmente válido e todos os `count` bytes foram processadas.  
  
 \(size\_t\) \(\-1\)  
 Erro de codificação.  O próximo `count` ou menos bytes não contribuem para um caractere multibyte completo e válido.  Nesse caso, `errno` é definido como EILSEQ e o estado da conversão em `mbstate` for especificado.  
  
## Comentários  
 O `mbrlen` função inspeciona no máximo `count` bytes, começando com o byte apontado por `str` para determinar o número de bytes que são necessários para concluir o próximo caractere multibyte, incluindo todas as sequências de turno.  É equivalente à chamada `mbrtowc(NULL, str, count, &mbstate)` onde `mbstate` é qualquer um fornecido pelo usuário `mbstate_t` objeto ou um objeto interno estático fornecida pela biblioteca.  
  
 O `mbrlen` função salva e usa o estado de mudança de um caractere multibyte incompleto no `mbstate` parâmetro.  Isso permite `mbrlen` a capacidade de reinicialização no meio de um caractere multibyte se precisa ser, no máximo examinando `count` bytes.  Se `mbstate` for um ponteiro nulo, `mbrlen` usa um estático interno, `mbstate_t` objeto para armazenar o estado de shift.  Porque o interno `mbstate_t` objeto não é thread\-safe, recomendamos que você sempre alocar e passa seu próprio `mbstate` parâmetro.  
  
 O `mbrlen` função difere da [\_mbclen, mblen, \_mblen\_l](../../c-runtime-library/reference/mbclen-mblen-mblen-l.md) por sua capacidade de reinicialização.  O estado de shift é armazenado em `mbstate` para chamadas subseqüentes para o mesmo ou outras funções reinicializáveis.  Resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciável.  Por exemplo, um aplicativo deve usar `wcsrlen` em vez de `wcslen` se uma chamada subsequente `wcsrtombs` é usado em vez de `wcstombs.`  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|não aplicável|não aplicável|`mbrlen`|não aplicável|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`mbrlen`|\< WCHAR. h \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
 Este exemplo mostra como a interpretação de caracteres multibyte depende de página de código atual e demonstra a capacidade de retomada do `mbrlen`.  
  
```  
 // crt_mbrlen.c  
// Compile by using: cl crt_mbrlen.c  
#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>  
#include <locale.h>  
#include <wchar.h>  
  
size_t Example(const char * pStr)  
{  
    size_t      charLen = 0;  
    size_t      charCount = 0;  
    mbstate_t   mbState = {0};  
  
    while ((charLen = mbrlen(pStr++, 1, &mbState)) != 0 &&  
            charLen != (size_t)-1)  
    {  
        if (charLen != (size_t)-2) // if complete mbcs char,  
        {  
            charCount++;  
        }  
    }   
    return (charCount);  
}   
  
int main( void )  
{  
    int         cp;  
    size_t      charCount = 0;  
    const char  *pSample =   
        "\x82\xD0\x82\xE7\x82\xAA\x82\xC8: Shift-jis hiragana.";  
  
    cp = _getmbcp();  
    charCount = Example(pSample);  
    printf("\nCode page: %d\n%s\nCharacter count: %d\n",   
        cp, pSample, charCount);  
  
    setlocale(LC_ALL, "ja-JP"); // Set Japanese locale  
    _setmbcp(932); // and Japanese multibyte code page  
    cp = _getmbcp();  
    charCount = Example(pSample);  
    printf("\nCode page: %d\n%s\nCharacter count: %d\n",   
        cp, pSample, charCount);  
}  
```  
  
  **Página de código: 0**  
**é╨éτé¬é╚: hiragana Shift\-jis.  Contagem de caracteres: 29**  
**Página de código: 932**  
**???: Hiragana shift\-jis.  Contagem de caracteres: 25**    
## Equivalência do .NET Framework  
 [System::String::Length](https://msdn.microsoft.com/en-us/library/system.string.length.aspx)  
  
## Consulte também  
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [Localidade](../../c-runtime-library/locale.md)