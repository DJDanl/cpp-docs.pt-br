---
title: "wctomb, _wctomb_l | Microsoft Docs"
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
  - "_wctomb_l"
  - "wctomb"
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
  - "wctomb"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _wctomb_l"
  - "caracteres, convertendo"
  - "conversão de cadeia de caracteres, cadeias de caracteres multibyte"
  - "conversão de cadeia de caracteres, caracteres largos"
  - "Função wctomb"
  - "Função wctomb_l"
  - "caracteres largos, convertendo"
ms.assetid: 4a543f0e-5516-4d81-8ff2-3c5206f02ed5
caps.latest.revision: 23
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# wctomb, _wctomb_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converter um caractere largo em caracteres multibyte correspondente.  Versões mais seguras dessas funções estão disponíveis; consulte [wctomb\_s, \_wctomb\_s\_l](../../c-runtime-library/reference/wctomb-s-wctomb-s-l.md).  
  
## Sintaxe  
  
```  
int wctomb(  
   char *mbchar,  
   wchar_t wchar   
);  
int _wctomb_l(  
   char *mbchar,  
   wchar_t wchar,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `mbchar`  
 O endereço de um caracteres multibyte.  
  
 `wchar`  
 Um caractere largo.  
  
## Valor de retorno  
 Se `wctomb` converte o caractere largo a um caracteres multibyte, retorna o número de bytes \(que nunca é maior que `MB_CUR_MAX`\) em caractere largo.  Se `wchar` é o caractere nulo ampla de caracteres \(L \\ 0 '\), retornará 1. `wctomb` de.  Se o ponteiro `mbchar` de destino for NULL, retornará 0 de `wctomb` .  Se a conversão não é possível na localidade atual, `wctomb` 1 será retornado e `errno` é definido como `EILSEQ`.  
  
## Comentários  
 A função de `wctomb` converte seu argumento de `wchar` correspondente em caracteres multibyte e armazena o resultado em `mbchar`.  Você pode chamar a função de qualquer ponto em qualquer programa.  `wctomb` usa a localidade atual para qualquer comportamento dependente de localidade; `_wctomb_l` é idêntico a `wctomb` exceto que usa a localidade passada por vez.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 `wctomb` valida seus parâmetros.  Se `mbchar` é `NULL`, o parâmetro de manipulador inválido é invocado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, `errno` está definido como `EINVAL` e a função retorna \-1.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`wctomb`|\<stdlib.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
 Esse programa ilustra o comportamento da função de wctomb.  
  
```  
// crt_wctomb.cpp  
// compile with: /W3  
#include <stdio.h>  
#include <stdlib.h>  
  
int main( void )  
{  
   int i;  
   wchar_t wc = L'a';  
   char *pmb = (char *)malloc( MB_CUR_MAX );  
  
   printf( "Convert a wide character:\n" );  
   i = wctomb( pmb, wc ); // C4996  
   // Note: wctomb is deprecated; consider using wctomb_s  
   printf( "   Characters converted: %u\n", i );  
   printf( "   Multibyte character: %.1s\n\n", pmb );  
}  
```  
  
  **Converter um caractere largo:**  
 **Caracteres convertidos: 1**  
 **Caractere de Multibyte: a**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [\_mbclen, mblen, \_mblen\_l](../../c-runtime-library/reference/mbclen-mblen-mblen-l.md)   
 [mbstowcs, \_mbstowcs\_l](../../c-runtime-library/reference/mbstowcs-mbstowcs-l.md)   
 [mbtowc, \_mbtowc\_l](../Topic/mbtowc,%20_mbtowc_l.md)   
 [wcstombs, \_wcstombs\_l](../Topic/wcstombs,%20_wcstombs_l.md)   
 [WideCharToMultiByte](http://msdn.microsoft.com/library/windows/desktop/dd374130)