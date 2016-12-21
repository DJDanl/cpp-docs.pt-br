---
title: "_get_output_format | Microsoft Docs"
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
  - "_get_output_format"
apilocation: 
  - "msvcr110_clr0400.dll"
  - "msvcr100.dll"
  - "msvcr80.dll"
  - "msvcrt.dll"
  - "msvcr90.dll"
  - "msvcr120.dll"
  - "msvcr110.dll"
apitype: "DLLExport"
f1_keywords: 
  - "get_output_format"
  - "_get_output_format"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "formatação de saída"
  - "Função get_output_format"
  - "Função _get_output_format"
ms.assetid: 0ce42f3b-3479-41c4-bcbf-1d21f7ee37e7
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _get_output_format
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Obtém o valor atual do sinalizador de formato de saída.  
  
> [!IMPORTANT]
>  Essa função é obsoleta. A partir do Visual Studio 2015, ele não está disponível no CRT.  
  
## Sintaxe  
  
```  
unsigned int _get_output_format();  
```  
  
## Valor de retorno  
 O valor atual do sinalizador de formato de saída.  
  
## Comentários  
 O sinalizador de formato de saída controla os recursos de e\/s formatada. No momento, o sinalizador tem dois valores possíveis: 0 e `_TWO_DIGIT_EXPONENT`. Se `_TWO_DIGIT_EXPONENT` for definido, o flutuante números de ponto é impresso com apenas dois dígitos do expoente, a menos que um terceiro dígito é necessária para o tamanho do expoente. Se o sinalizador for zero, o ponto flutuante saída exibe três dígitos do expoente, usando zeros, se necessário, para preencher o valor a três dígitos.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_get_output_format`|\< stdio \>|  
  
 Para obter informações de compatibilidade, consulte [compatibilidade](../c-runtime-library/compatibility.md) na introdução.  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [printf, \_printf\_l, wprintf, \_wprintf\_l](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [printf\_s, \_printf\_s\_l, wprintf\_s, \_wprintf\_s\_l](../c-runtime-library/reference/printf-s-printf-s-l-wprintf-s-wprintf-s-l.md)   
 [Caracteres de campo de tipo printf](../c-runtime-library/printf-type-field-characters.md)   
 [\_set\_output\_format](../c-runtime-library/set-output-format.md)