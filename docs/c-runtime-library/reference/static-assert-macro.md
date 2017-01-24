---
title: "Macro _STATIC_ASSERT | Microsoft Docs"
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
apitype: "DLLExport"
f1_keywords: 
  - "_STATIC_ASSERT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro _STATIC_ASSERT"
ms.assetid: 89b0350c-2c2f-4be6-9786-8b1f0780a5da
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Macro _STATIC_ASSERT
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Avalia uma expressão em tempo de compilação e gerencia um erro quando o resultado é `FALSE`.  
  
## Sintaxe  
  
```  
_STATIC_ASSERT(  
    booleanExpression  
);  
```  
  
#### Parâmetros  
 `booleanExpression`  
 Expressão \(inclusive ponteiros\) que avalia como diferente de zero \(`TRUE`\) ou 0 \(`FALSE`\).  
  
## Comentários  
 Esta macro é semelhante a [macros de \_ASSERT e de \_ASSERTE](../Topic/_ASSERT,%20_ASSERTE,%20_ASSERT_EXPR%20Macros.md), exceto que `booleanExpression` é avaliada em tempo de compilação em vez de em tempo de execução.  Se `booleanExpression` avalia a `FALSE` \(0\), [Erro do Compilador C2466](../../error-messages/compiler-errors-1/compiler-error-c2466.md) será gerado.  
  
## Exemplo  
 Neste exemplo, é verifique se `sizeof``int` seja maior que ou igual a 2 bytes e se `sizeof``long` é 1 bytes.  O programa não criará e gerará [Erro do Compilador C2466](../../error-messages/compiler-errors-1/compiler-error-c2466.md) porque `long` é maior que 1 bytes.  
  
```  
// crt__static_assert.c  
  
#include <crtdbg.h>  
#include <stdio.h>  
  
_STATIC_ASSERT(sizeof(int) >= 2);  
_STATIC_ASSERT(sizeof(long) == 1);  // C2466  
  
int main()  
{  
    printf("I am sure that sizeof(int) will be >= 2: %d\n",  
        sizeof(int));  
    printf("I am not so sure that sizeof(long) == 1: %d\n",  
        sizeof(long));  
}  
```  
  
## Requisitos  
  
|Macro|Cabeçalho necessário|  
|-----------|--------------------------|  
|`_STATIC_ASSERT`|\<crtdbg.h\>|  
  
## Equivalência do .NET Framework  
 [System::Diagnostics::Debug::Assert](https://msdn.microsoft.com/en-us/library/system.diagnostics.debug.assert.aspx)  
  
## Consulte também  
 [Referência da função alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [Assert, asserte, \_ASSERT\_EXPR macros](../Topic/_ASSERT,%20_ASSERTE,%20_ASSERT_EXPR%20Macros.md)