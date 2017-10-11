---
title: C2781 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2781
dev_langs:
- C++
helpviewer_keywords:
- C2781
ms.assetid: f29b9963-f55b-427c-8db6-50f37713df5a
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 71358a4f8082591a5d54c93e7874fc5d26ba18ad
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2781"></a>C2781 de erro do compilador
'declaração de ': espera pelo menos value1 argumento - value2 fornecido  
  
 Um modelo de função com uma lista de parâmetros variáveis tem muito poucos argumentos.  
  
 O exemplo a seguir gera C2781:  
  
```  
// C2781.cpp  
template<typename T>  
void f(T, T, ...){}  
  
int main() {  
   f(1);   // C2781  
  
   // try the following line instead  
   f(1,1);  
}  
```
