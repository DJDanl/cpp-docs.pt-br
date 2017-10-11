---
title: C3367 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3367
dev_langs:
- C++
helpviewer_keywords:
- C3367
ms.assetid: e675d42b-f5b0-4d43-aab1-1f5024233102
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: d1d144399ca42ba321d8f3d11425bf2ff8e65891
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3367"></a>C3367 de erro do compilador
'static_member_function': não é possível usar função static para criar um delegate não associado  
  
Quando você chama um delegate não associado, você deve passar uma instância de um objeto. Como uma função de membro estático é chamada através do nome de classe, você pode criar um delegate não associado com uma função de membro de instância.  
  
Para obter mais informações sobre delegados não associados, consulte [como: definir e usar delega (C + + CLI)](../../dotnet/how-to-define-and-use-delegates-cpp-cli.md).  
  
## <a name="example"></a>Exemplo  
O exemplo a seguir gera C3367.  
  
```cpp  
// C3367.cpp  
// compile with: /clr  
ref struct R {  
   void b() {}  
   static void f() {}  
};  
  
delegate void Del(R^);  
  
int main() {  
   Del ^ a = gcnew Del(&R::b);   // OK  
   Del ^ b = gcnew Del(&R::f);   // C3367  
}  
```
