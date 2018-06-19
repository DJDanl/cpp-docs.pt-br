---
title: C3367 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3367
dev_langs:
- C++
helpviewer_keywords:
- C3367
ms.assetid: e675d42b-f5b0-4d43-aab1-1f5024233102
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2884e38d1ad1aecef8e7b0723674ebd9849d8f40
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33257068"
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