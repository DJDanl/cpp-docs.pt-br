---
title: Compilador (nível 1) de aviso C4669 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4669
dev_langs:
- C++
helpviewer_keywords:
- C4669
ms.assetid: 97730679-e3dc-44d4-b2a8-aa65badc17f2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: baffb413a5c07acaeea7f4706ab9d6e951c65f04
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4669"></a>Compilador C4669 de aviso (nível 1)
'cast': conversão não segura: 'class' é um serviço ou objeto de tipo de WinRT  
  
 Uma conversão contém um tempo de execução do Windows ou um tipo gerenciado. O compilador conclui a conversão, efetuar uma cópia de bit a bit de um ponteiro para o outro, mas não fornece nenhuma outra verificação. Para resolver este aviso, não converta classes que contêm membros gerenciados ou tipos de tempo de execução do Windows.  
  
 O exemplo a seguir gera C4669 e mostra como corrigi-lo:  
  
```  
// C4669.cpp  
// compile with: /clr /W1  
ref struct A {  
   int i;  
   Object ^ pObj;   // remove the managed member to fix the warning  
};  
  
ref struct B {  
   int j;  
};  
  
int main() {  
   A ^ a = gcnew A;  
   B ^ b = reinterpret_cast<B ^>(a);   // C4669  
}  
```