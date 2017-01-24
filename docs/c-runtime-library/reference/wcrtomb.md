---
title: "wcrtomb | Microsoft Docs"
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
  - "wcrtomb"
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
  - "wcrtomb"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "caracteres, convertendo"
  - "caracteres multibyte"
  - "Função wcrtomb"
  - "caracteres largos, convertendo"
ms.assetid: 717f1b21-2705-4b7f-b6d0-82adc5224340
caps.latest.revision: 26
caps.handback.revision: 24
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# wcrtomb
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converter um caractere largo em sua representação de caracteres multibyte.  Uma versão mais segura dessa função está disponível; consulte [wcrtomb\_s](../../c-runtime-library/reference/wcrtomb-s.md).  
  
## Sintaxe  
  
```  
size_t wcrtomb(  
   char *mbchar,  
   wchar_t wchar,  
   mbstate_t *mbstate  
);  
template <size_t size>  
size_t wcrtomb(  
   char (&mbchar)[size],  
   wchar_t wchar,  
   mbstate_t *mbstate  
); // C++ only  
```  
  
#### Parâmetros  
 \[saída\] `mbchar`  
 O caractere convertido multibyte resultante.  
  
 \[entrada\] `wchar`  
 Um caractere largo a ser convertida.  
  
 \[entrada\] `mbstate`  
 Um ponteiro para um objeto `mbstate_t`.  
  
## Valor de retorno  
 Retorna o número de bytes necessários para representar o caracteres multibyte, caso contrário A\-1 convertidos se ocorrer um erro.  
  
## Comentários  
 A função de `wcrtomb` converte um caractere largo, começando no estado especificado de conversão contido em `mbstate`, do valor contido em `wchar`, no endereço representado por `mbchar`.  O valor de retorno é o número de bytes necessários para representar o caractere correspondente multibyte, mas não retornará mais de bytes de `MB_CUR_MAX` .  
  
 Se `mbstate` for nulo, o objeto interno de `mbstate_t` que contém o estado da conversão de `mbchar` será usado.  Se a sequência `wchar` de caracteres não tem uma representação de caracteres correspondente multibyte, A\-1 será retornado e `errno` é definido como `EILSEQ`.  
  
 A função de `wcrtomb` difere de [wctomb, \_wctomb\_l](../../c-runtime-library/reference/wctomb-wctomb-l.md) por seu restartability.  O estado da conversão é armazenado em `mbstate` para chamadas subsequentes à mesma ou a outras funções restartable.  Os resultados são definidos ao misturar o uso de funções restartable e nonrestartable.  Por exemplo, um aplicativo use `wcsrlen` em vez de `wcsnlen`, se uma chamada subsequente a `wcsrtombs` foi usado em vez de `wcstombs`.  
  
 Em C\+\+, essa função tem uma sobrecarga de modelo que invoca a contraparte mais novos, seguros dessa função.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
## Exceções  
 A função de `wcrtomb` é seguro multi\-threaded desde que nenhuma função no thread atual chama `setlocale` quando essa função é executada e quando `mbstate` é nulo.  
  
## Exemplo  
  
```  
// crt_wcrtomb.c  
// compile with: /W3  
// This program converts a wide character  
// to its corresponding multibyte character.  
  
#include <string.h>  
#include <stdio.h>  
#include <wchar.h>  
  
int main( void )  
{  
    size_t      sizeOfCovertion = 0;  
    mbstate_t   mbstate;  
    char        mbStr = 0;  
    wchar_t*    wcStr = L"Q";  
  
    // Reset to initial conversion state  
    memset(&mbstate, 0, sizeof(mbstate));  
  
    sizeOfCovertion = wcrtomb(&mbStr, *wcStr, &mbstate); // C4996  
    // Note: wcrtomb is deprecated; consider using wcrtomb_s instead  
    if (sizeOfCovertion > 0)  
    {  
        printf("The corresponding wide character \"");  
        wprintf(L"%s\"", wcStr);  
        printf(" was converted to the \"%c\" ", mbStr);  
        printf("multibyte character.\n");  
    }  
    else  
    {  
        printf("No corresponding multibyte character "  
               "was found.\n");  
    }  
}  
```  
  
  **O caractere largo correspondente “Q” foi convertidos em caracteres multibyte de “Q”.**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`wcrtomb`|\<wchar.h\>|  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [mbsinit](../../c-runtime-library/reference/mbsinit.md)