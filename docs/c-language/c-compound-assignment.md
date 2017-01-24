---
title: "Atribui&#231;&#227;o composta C | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "operadores de atribuição, composto"
  - "Operadores de atribuição composta"
  - "operadores [C], atribuição"
ms.assetid: db7b5893-cd56-4f1c-9981-5a024200ab63
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Atribui&#231;&#227;o composta C
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os operadores de atribuição composta combinam o operador de atribuição simples com outro operador binário.  Os operadores de atribuição composta executam a operação especificada pelo operador adicional e, em seguida, atribuem o resultado ao operando esquerdo.  Por exemplo, uma expressão de atribuição composta, como  
  
```  
  
expression1 += expression2  
```  
  
 pode ser entendida como  
  
```  
  
expression1 = expression1 + expression2  
```  
  
 No entanto, a expressão de atribuição composta não é equivalente à versão expandida porque a expressão de atribuição composta avalia *expression1* apenas uma vez, enquanto a versão expandida avaliou *expression1* duas vezes: na operação de adição e na operação de atribuição.  
  
 Os operandos de um operador de atribuição composta devem ser do tipo integral ou flutuação.  Cada operador de atribuição composta executa as conversões que o operador binário correspondente executa e restringe os tipos de seus operandos de acordo.  Os operadores de atribuição de adição \(`+=`\) e de subtração \(**–\=**\) também podem ter um operando esquerdo do tipo de ponteiro. Nesse caso, o operando direito deve ser do tipo integral.  O resultado de uma operação de atribuição composta tem o valor e o tipo do operando esquerdo.  
  
```  
#define MASK 0xff00  
  
n &= MASK;  
```  
  
 Neste exemplo, a operação AND inclusivo bit a bit é executada em `n` e em `MASK`, e o resultado é atribuído a `n`.  A constante de manifesto `MASK` é definida com uma política do pré\-processador [\#define](../preprocessor/hash-define-directive-c-cpp.md).  
  
## Consulte também  
 [Operadores de atribuição C](../c-language/c-assignment-operators.md)