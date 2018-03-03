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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ebb9f16375ccde7e684cdeac14116657c1495bda
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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