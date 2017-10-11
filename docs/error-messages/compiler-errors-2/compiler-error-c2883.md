---
title: C2883 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2883
dev_langs:
- C++
helpviewer_keywords:
- C2883
ms.assetid: 5c6d689d-ed42-41ad-b5c0-e9c2e0b8c356
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 28c2031c3e659099507a8e59758e27f364dd29b9
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2883"></a>C2883 de erro do compilador
'name': declaração da função está em conflito com 'Identificador' introduzido por declaração de using  
  
 Você tentou definir uma função de mais de uma vez. A primeira definição foi feita de um namespace com um `using` declaração. A segunda é uma definição de local.  
  
 O exemplo a seguir gera C2883:  
  
```  
// C2883.cpp  
namespace A {  
   void z(int);  
}  
  
int main() {  
   using A::z;  
   void z(int);   // C2883  z is already defined  
}  
```
