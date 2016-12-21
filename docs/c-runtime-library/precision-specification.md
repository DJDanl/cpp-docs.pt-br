---
title: "Especifica&#231;&#227;o da precis&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apilocation: 
  - "msvcr100.dll"
  - "msvcr120.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr90.dll"
  - "msvcr80.dll"
apitype: "DLLExport"
f1_keywords: 
  - "c.math"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "função printf, campos de especificação de formato"
ms.assetid: dc59ea4e-d23a-4f1f-9881-2c919ebefb82
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Especifica&#231;&#227;o da precis&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Em uma especificação de formato, o terceiro campo opcional é a especificação de precisão. Ele consiste em um ponto \(.\) seguido por um inteiro de decimal não negativo que, dependendo do tipo de conversão, especifica o número de caracteres de cadeia de caracteres, o número de casas decimais ou o número de dígitos significativos para a saída.  
  
 Ao contrário da especificação de largura, a especificação de precisão pode causar o truncamento do valor de saída ou arredondamento de um valor de ponto flutuante. Se `precision` é especificado como 0 e o valor a ser convertido é 0, o resultado não é nenhuma saída de caracteres, conforme mostrado neste exemplo:  
  
 `printf( "%.0d", 0 );      /* No characters output */`  
  
 Se a especificação de precisão for um asterisco \(\*\), um `int` argumento da lista de argumentos fornece o valor. Na lista de argumentos, o `precision` argumento deve preceder o valor que está sendo formatado, conforme mostrado neste exemplo:  
  
 `printf( "%.*f", 3, 3.14159265 );  /* 3.142 output */`  
  
 O tipo determina o a interpretação de `precision` ou a precisão padrão quando `precision` for omitido, conforme mostrado na tabela a seguir.  
  
### Como os valores de precisão afetam tipo  
  
|Tipo|Significado|Padrão|  
|----------|-----------------|------------|  
|`a`, `A`|A precisão especifica o número de dígitos após o ponto.|Precisão padrão é 6. Se a precisão for 0, nenhum ponto decimal é impresso, a menos que o `#` sinalizador é usado.|  
|`c`, `C`|A precisão não tem nenhum efeito.|Caractere é impresso.|  
|`d`, `i`, `u`, `o`, `x`, `X`|A precisão especifica o número mínimo de dígitos a serem impressas. Se o número de dígitos no argumento for menor que `precision`, o valor de saída é preenchido com zeros à esquerda. O valor não é truncado quando excede o número de dígitos `precision`.|Precisão padrão é 1.|  
|`e`, `E`|A precisão especifica o número de dígitos a ser impresso após o ponto decimal. O último dígito impresso será arredondado.|Precisão padrão é 6. Se `precision` for 0 ou o ponto \(.\) aparece sem um número a seguir, sem ponto decimal é impresso.|  
|`f`|O valor de precisão especifica o número de dígitos após o ponto decimal. Se aparecer um ponto decimal, pelo menos um dígito aparecerá antes dele. O valor é arredondado para o número apropriado de dígitos.|Precisão padrão é 6. Se `precision` for 0, ou se o ponto \(.\) aparece sem um número a seguir, sem ponto decimal é impresso.|  
|`g`, `G`|A precisão especifica o número máximo de dígitos significativos impresso.|Seis dígitos significativos são impressos e os zeros à direita são truncados.|  
|`s`, `S`|A precisão especifica o número máximo de caracteres a ser impresso. Caracteres além de `precision` não são impressos.|Os caracteres são impressos até que seja encontrado um caractere nulo.|  
  
## Consulte também  
 [printf, \_printf\_l, wprintf, \_wprintf\_l](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [Sintaxe de especificação de formato: funções printf e and wprintf](../Topic/Format%20Specification%20Syntax:%20printf%20and%20wprintf%20Functions.md)   
 [Diretivas de sinalizador](../Topic/Flag%20Directives.md)   
 [Especificação de largura printf](../c-runtime-library/printf-width-specification.md)   
 [Especificação de arquivo](../c-runtime-library/size-specification.md)   
 [Caracteres de campo de tipo printf](../c-runtime-library/printf-type-field-characters.md)