---
title: C3365 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3365
dev_langs:
- C++
helpviewer_keywords:
- C3365
ms.assetid: 875ec3a4-522c-4e3d-9b67-48808b857f6d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a41fc5b1eb5c93bf73685b5141bd91ab7a6058e0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3365"></a>C3365 de erro do compilador
operador 'operator': operandos diferentes de tipo 'type1' e 'type2'  
  
Foi feita uma tentativa para compor delegados com tipos diferentes.  Consulte [como: definir e usar delega (C + + CLI)](../../dotnet/how-to-define-and-use-delegates-cpp-cli.md) para obter mais informações sobre delegados.  
  
## <a name="example"></a>Exemplo  
O exemplo a seguir gera C3365:  
  
```cpp  
// C3365.cpp  
// compile with: /clr  
delegate void D1();  
delegate void D2(int);  
  
ref class R {  
public:  
   void f(){}  
   void g(int){}  
};  
  
int main() {  
   D1^ d1 = gcnew D1(gcnew R, &R::f);  
   D2^ d2 = gcnew D2(gcnew R, &R::g);  
   D1^ d3 = gcnew D1(gcnew R, &R::f);  
  
   d1 += d2;   // C3365  
   d1 += d3;   // OK  
   d1();  
}  
```