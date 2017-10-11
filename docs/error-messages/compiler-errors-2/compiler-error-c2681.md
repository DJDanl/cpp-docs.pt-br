---
title: C2681 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2681
dev_langs:
- C++
helpviewer_keywords:
- C2681
ms.assetid: eb42da6d-8d2c-43fd-986b-e73e2b004885
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 9978a520b4682e4e2c7c4856d4e42675be0ab901
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2681"></a>C2681 de erro do compilador
'type': tipo de expressão inválido para nome  
  
 Tentativa de um operador de conversão converter de um tipo inválido. Por exemplo, se você usar o [dynamic_cast](../../cpp/dynamic-cast-operator.md) para converter uma expressão em um tipo de ponteiro, a expressão de origem deve ser um ponteiro.  
  
 O exemplo a seguir gera C2681:  
  
```  
// C2681.cpp  
class A { virtual void f(); };  
  
void g(int i) {  
    A* pa;  
    pa = dynamic_cast<A*>(i);  // C2681  
}  
```
