---
title: C2652 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2652
dev_langs:
- C++
helpviewer_keywords:
- C2652
ms.assetid: 6e3d1a90-a989-4088-8afd-dc82f6a2d66f
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 56cfdf52ec3a6947a6a82774f551fc1a6880c959
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2652"></a>C2652 de erro do compilador
'Identificador': construtor de cópia inválido: primeiro parâmetro não deve ser um identificador  
  
 O primeiro parâmetro do construtor de cópia tem o mesmo tipo de classe, estrutura ou união para o qual ela está definida. O primeiro parâmetro pode ser uma referência para o tipo, mas não o próprio tipo.  
  
 O exemplo a seguir gera C2651:  
  
```  
// C2652.cpp  
// compile with: /c  
class A {  
   A( A );   // C2652 takes an A  
};  
class B {  
   B( B& );   // OK, reference to B  
};  
```
