---
title: "wcsrtombs | Microsoft Docs"
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
  - "wcsrtombs"
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
  - "wcsrtombs"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função wcsrtombs"
  - "conversão de cadeia de caracteres, caracteres largos"
  - "caracteres largos, cadeias de caracteres"
ms.assetid: a8d21fec-0d36-4085-9d81-9b1c61c7259d
caps.latest.revision: 26
caps.handback.revision: 24
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# wcsrtombs
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converter uma cadeia de caracteres amplas em sua representação de cadeia de caracteres de vários bytes.  Uma versão mais segura dessa função está disponível; consulte [wcsrtombs\_s](../../c-runtime-library/reference/wcsrtombs-s.md).  
  
## Sintaxe  
  
```  
size_t wcsrtombs(  
   char *mbstr,  
   const wchar_t **wcstr,  
   sizeof count,  
   mbstate_t *mbstate  
);  
template <size_t size>  
size_t wcsrtombs(  
   char (&mbstr)[size],  
   const wchar_t **wcstr,  
   sizeof count,  
   mbstate_t *mbstate  
); // C++ only  
```  
  
#### Parâmetros  
 \[saída\] `mbstr`  
 O local do endereço da cadeia de caracteres convertida resultante multibyte.  
  
 \[entrada\] `wcstr`  
 Indiretamente aponta para o local da cadeia de caracteres amplas a ser convertida.  
  
 \[entrada\] `count`  
 O número de caracteres a ser convertido.  
  
 \[entrada\] `mbstate`  
 Um ponteiro para um objeto do estado da conversão de `mbstate_t` .  
  
## Valor de retorno  
 Retorna o número de bytes convertidos com êxito, não incluindo o zero que encerram o byte nulo \(se houver\), caso contrário A\-1 se um erro ocorreu.  
  
## Comentários  
 A função de `wcsrtombs` converte uma cadeia de caracteres de caracteres amplos, começando no estado especificado de conversão contido em `mbstate`, de aguçado indireto dos valores em `wcstr`, no endereço de `mbstr`.  A conversão para cada caractere continuará até: depois que um zero que finaliza o caractere largo está localizado, quando um caractere não correspondente seja atingido ou quando o próximo caractere exceder o limite contido em `count`.  Se `wcsrtombs` encontrar o caractere nulo ampla de caracteres \(L \\ 0 '\) ou antes ou `count` quando ocorrer, o converte a 0 de 8 bits e o para.  
  
 Assim, a cadeia de caracteres multibyte `mbstr` é terminada em nulo apenas se `wcsrtombs` encontrar um caractere nulo de caractere largo durante a conversão.  Se as sequências apontadas por `wcstr` e a sobreposição de `mbstr` , o comportamento de `wcsrtombs` são indefinidas.  `wcsrtombs` é afetado por categoria de LC\_TYPE de localidade atual.  
  
 A função de `wcsrtombs` difere de [wcstombs, \_wcstombs\_l](../Topic/wcstombs,%20_wcstombs_l.md) por seu restartability.  O estado da conversão é armazenado em `mbstate` para chamadas subsequentes à mesma ou a outras funções restartable.  Os resultados são definidos ao misturar o uso de funções restartable e nonrestartable.  Por exemplo, um aplicativo use `wcsrlen` em vez de `wcsnlen`, se uma chamada subsequente a `wcsrtombs` foi usado em vez de `wcstombs`.  
  
 Se o argumento de `mbstr` é `NULL`, `wcsrtombs` retorna o tamanho necessário em bytes da cadeia de caracteres de destino.  Se `mbstate` for nulo, o estado interno da conversão de `mbstate_t` será usado.  Se a sequência `wchar` de caracteres não tem uma representação de caracteres correspondente multibyte, A\-1 será retornado e `errno` é definido como `EILSEQ`.  
  
 Em C\+\+, essa função tem uma sobrecarga de modelo que invoca a contraparte mais novos, seguros dessa função.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
## Exceções  
 A função de `wcsrtombs` é seguro multi\-threaded desde que nenhuma função no thread atual chama `setlocale` quando essa função executar e `mbstate` não for nulo.  
  
## Exemplo  
  
```  
// crt_wcsrtombs.cpp  
// compile with: /W3  
// This code example converts a wide  
// character string into a multibyte  
// character string.  
  
#include <stdio.h>  
#include <memory.h>  
#include <wchar.h>  
#include <errno.h>  
  
#define MB_BUFFER_SIZE 100  
  
int main()  
{  
    const wchar_t   wcString[] =   
                    {L"Every good boy does fine."};  
    const wchar_t   *wcsIndirectString = wcString;  
    char            mbString[MB_BUFFER_SIZE];  
    size_t          countConverted;  
    mbstate_t       mbstate;  
  
    // Reset to initial shift state  
    ::memset((void*)&mbstate, 0, sizeof(mbstate));  
  
    countConverted = wcsrtombs(mbString, &wcsIndirectString,  
                               MB_BUFFER_SIZE, &mbstate); // C4996  
    // Note: wcsrtombs is deprecated; consider using wcsrtombs_s  
    if (errno == EILSEQ)  
    {  
        printf( "An encoding error was detected in the string.\n" );  
    }  
    else   
    {  
        printf( "The string was successfuly converted.\n" );  
    }  
}  
```  
  
  **A cadeia de caracteres foi convertida com êxito.**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`wcsrtombs`|\<wchar.h\>|  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [wcrtomb](../../c-runtime-library/reference/wcrtomb.md)   
 [wcrtomb\_s](../../c-runtime-library/reference/wcrtomb-s.md)   
 [wctomb, \_wctomb\_l](../../c-runtime-library/reference/wctomb-wctomb-l.md)   
 [wcstombs, \_wcstombs\_l](../Topic/wcstombs,%20_wcstombs_l.md)   
 [mbsinit](../../c-runtime-library/reference/mbsinit.md)