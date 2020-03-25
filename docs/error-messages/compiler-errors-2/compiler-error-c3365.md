---
title: Erro do compilador C3365
ms.date: 11/04/2016
f1_keywords:
- C3365
helpviewer_keywords:
- C3365
ms.assetid: 875ec3a4-522c-4e3d-9b67-48808b857f6d
ms.openlocfilehash: 355c4530fffa89470ac495aff8bc2822278e2da3
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80201189"
---
# <a name="compiler-error-c3365"></a>Erro do compilador C3365

operador ' operator ': operandos diferentes do tipo ' type1 ' e ' type2 '

Foi feita uma tentativa de compor delegados com tipos diferentes.  Consulte [como: definir e usar delegados (C++/CLI)](../../dotnet/how-to-define-and-use-delegates-cpp-cli.md) para obter mais informações sobre delegados.

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
