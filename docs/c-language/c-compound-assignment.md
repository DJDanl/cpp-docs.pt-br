---
title: "Atribuição composta C | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- operators [C], assignment
- compound assignment operators
- assignment operators, compound
ms.assetid: db7b5893-cd56-4f1c-9981-5a024200ab63
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2b8b9166c1beae167f6d31913c3df10a8f57bbef
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="c-compound-assignment"></a>Atribuição composta C
Os operadores de atribuição composta combinam o operador de atribuição simples com outro operador binário. Os operadores de atribuição composta executam a operação especificada pelo operador adicional e, em seguida, atribuem o resultado ao operando esquerdo. Por exemplo, uma expressão de atribuição composta, como  
  
```  
  
expression1  
+=  
expression2  
  
```  
  
 pode ser entendida como  
  
```  
  
expression1  
=  
expression1  
+  
expression2  
  
```  
  
 No entanto, a expressão de atribuição composta não é equivalente à versão expandida porque a expressão de atribuição composta avalia *expression1* apenas uma vez, enquanto a versão expandida avalia *expression1* duas vezes: na operação de adição e na operação de atribuição.  
  
 Os operandos de um operador de atribuição composta devem ser do tipo integral ou flutuação. Cada operador de atribuição composta executa as conversões que o operador binário correspondente executa e restringe os tipos de seus operandos de acordo. Os operadores de atribuição de adição (`+=`) e de subtração (**-=**) também podem ter um operando esquerdo do tipo ponteiro. Nesse caso, o operando direito deve ser do tipo integral. O resultado de uma operação de atribuição composta tem o valor e o tipo do operando esquerdo.  
  
```  
#define MASK 0xff00  
  
n &= MASK;  
```  
  
 Neste exemplo, a operação AND inclusivo bit a bit é executada em `n` e em `MASK`, e o resultado é atribuído a `n`. A constante de manifesto `MASK` é definida com uma diretiva do pré-processador [#define](../preprocessor/hash-define-directive-c-cpp.md).  
  
## <a name="see-also"></a>Consulte também  
 [Operadores de atribuição C](../c-language/c-assignment-operators.md)