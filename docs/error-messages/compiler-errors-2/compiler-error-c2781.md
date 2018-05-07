---
title: C2781 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2781
dev_langs:
- C++
helpviewer_keywords:
- C2781
ms.assetid: f29b9963-f55b-427c-8db6-50f37713df5a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fa42627085494047e10644f86a938b9311cb1625
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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