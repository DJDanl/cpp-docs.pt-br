---
title: "Especifica&#231;&#227;o de largura printf | Microsoft Docs"
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
  - "msvcr110.dll"
  - "msvcr80.dll"
  - "msvcr100.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr90.dll"
  - "msvcr120.dll"
apitype: "DLLExport"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "printf - função, campos de especificação de formato"
  - "printf - função, especificação de largura"
ms.assetid: 8b4a1b1e-bf6e-414f-a1b6-a9b6f1b6ce92
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Especifica&#231;&#227;o de largura printf
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Em uma especificação de formato, o segundo campo opcional é a especificação de largura.  O argumento de `width` é um inteiro decimal não negativo que controla o número mínimo de caracteres que são geradas.  Se o número de caracteres no valor de saída é menor do que a largura especificada, os espaços em branco são adicionadas à esquerda ou à direita da dependência sobre se o sinalizador esquerdo do alinhamento \(`-`\) é especificar\- até que a largura mínima é atingida.  Se `width` é prefixado por 0, os zeros à esquerda serão adicionados ao inteiro ou as conversões de ponto flutuante até que a largura mínima seja alcançada, exceto quando a conversão é a uma infinito ou a um NAN.  
  
 A especificação de largura nunca causa um valor a ser truncado.  Se o número de caracteres no valor de saída é maior que a largura especificada, ou se `width` não for fornecido, todos os caracteres de valor são saída, sujeitam a [precisão](../c-runtime-library/precision-specification.md) a especificação.  
  
 Se a especificação de largura é um asterisco \(`*`\), um argumento de `int` da lista de argumento fornece o valor.  O argumento de `width` deve preceder o valor que está sendo formatado na lista de argumentos, conforme mostrado neste exemplo:  
  
 `printf("%0*f", 5, 3);  /* 00003 is output */`  
  
 Ausente ou um valor pequeno de `width` em uma especificação de formato não causam truncamento de um valor de saída.  Se o resultado de uma conversão é mais amplo que o valor de `width` , o campo é expandida para conter o resultado da conversão.  
  
## Consulte também  
 [printf, \_printf\_l, wprintf, \_wprintf\_l](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [Sintaxe de especificação de formato: funções printf e and wprintf](../Topic/Format%20Specification%20Syntax:%20printf%20and%20wprintf%20Functions.md)   
 [Diretivas de sinalizador](../Topic/Flag%20Directives.md)   
 [Especificação da precisão](../c-runtime-library/precision-specification.md)   
 [Especificação de arquivo](../c-runtime-library/size-specification.md)   
 [Caracteres de campo de tipo printf](../c-runtime-library/printf-type-field-characters.md)