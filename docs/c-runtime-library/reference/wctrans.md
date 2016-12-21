---
title: "wctrans | Microsoft Docs"
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
  - "wctrans"
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
  - "wctrans"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "códigos de caractere, wctrans"
  - "caracteres, códigos"
  - "caracteres, convertendo"
  - "Função wctrans"
ms.assetid: 215404bf-6d60-489c-9ae9-880e6b586162
caps.latest.revision: 13
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# wctrans
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determina um mapeamento de um conjunto de códigos de caracteres para outro.  
  
## Sintaxe  
  
```  
wctrans_t wctrans(  
   const char *property   
);  
```  
  
#### Parâmetros  
 `property`  
 Uma cadeia de caracteres que especifica uma das transformações válidos.  
  
## Valor de retorno  
 Se a categoria de `LC_CTYPE` de localidade atual não define um mapeamento cujo nome corresponde a cadeia de caracteres `property`da propriedade, a função retornará zero.  Caso contrário, retorna um valor diferente de zero adequado para uso como o segundo argumento para uma chamada subsequente a [towctrans](../../c-runtime-library/reference/towctrans.md).  
  
## Comentários  
 Esta função determina um mapeamento de um conjunto de códigos de caracteres para outro.  
  
 Os seguintes pares de chamadas têm o mesmo comportamento em todas as localidades, mas é possível definir mapeamentos adicionais mesmo na localidade de C “2.0”:  
  
|Função|Igual a|  
|------------|-------------|  
|`tolower(`  `c`  `)`|`towctrans(`  `c` `, wctrans("towlower" ) )`|  
|`towupper(`  `c`  `)`|`towctrans(`  `c` `, wctrans( "toupper" ) )`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`wctrans`|\<wctype.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_wctrans.cpp  
// compile with: /EHsc  
// This example determines a mapping from one set of character  
// codes to another.   
  
#include <wchar.h>  
#include <wctype.h>  
#include <stdio.h>  
#include <iostream>  
  
int main()   
{  
    wint_t c = 'a';  
    printf_s("%d\n",c);  
  
    wctrans_t i = wctrans("toupper");  
    printf_s("%d\n",i);  
  
    wctrans_t ii = wctrans("towlower");  
    printf_s("%d\n",ii);  
  
    wchar_t wc = towctrans(c, i);  
    printf_s("%d\n",wc);  
}  
```  
  
  **97**  
**1**  
**0**  
**65**   
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md)