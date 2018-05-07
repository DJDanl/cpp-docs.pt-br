---
title: C3854 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3854
dev_langs:
- C++
helpviewer_keywords:
- C3854
ms.assetid: 32a9ead0-c6c7-485a-8802-c7b1fe921d3a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dbaed18984dbcc06b976a367ef9911528792ce52
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3854"></a>C3854 de erro do compilador
avalia a expressão à esquerda de '=' para uma função. Não é possível atribuir a uma função (uma função não é um l-value)  
  
 Uma referência não pode ser reinicializada. Uma referência a uma função de referência resulta em uma função, que é um rvalue, para que você não pode atribuir. Portanto, não é possível atribuir através de uma referência a uma função.  
  
 O exemplo a seguir gera C3854:  
  
```  
// C3854.cpp  
int afunc(int i)  
{  
   return i;  
}  
  
typedef int (& rFunc_t)(int);  
typedef int (* pFunc_t)(int);  
  
int main()  
{  
   rFunc_t rf = afunc;   // OK binding a reference to function  
   pFunc_t pf = &afunc;   // OK initializing a pointer to function  
  
   *pf = &afunc;   // C3854  
   // try the following line instead  
   // pf = &afunc;  
   *rf = &afunc;   // C3854  
}  
```