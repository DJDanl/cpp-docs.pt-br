---
title: Erro do compilador C3894
ms.date: 11/04/2016
f1_keywords:
- C3894
helpviewer_keywords:
- C3894
ms.assetid: 6d5ac903-1dea-431d-8e3a-cebca4342983
ms.openlocfilehash: 4d935e140d89cb5c3714450597677a7a02a245e8
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50496038"
---
# <a name="compiler-error-c3894"></a>Erro do compilador C3894

'var': uso l-value de membro de dados estáticos initonly só é permitido no construtor da classe da classe 'class'

Estática [initonly](../../dotnet/initonly-cpp-cli.md) membros de dados só podem ser usados como l-values em seu ponto de declaração ou em um construtor estático.

Membros de dados initonly (não estático) de instância só podem ser usados como l-values em seu ponto de declaração ou em construtores de (não estático) da instância.

O exemplo a seguir gera C3894:

```
// C3894.cpp
// compile with: /clr
ref struct Y1 {
   initonly static int data_var = 0;

public:
   // class constructor
   static Y1() {
      data_var = 99;   // OK
      System::Console::WriteLine("in static constructor");
   }

   // not the class constructor
   Y1(int i) {
      data_var = i;   // C3894
   }

   static void Test() {}

};

int main() {
   Y1::data_var = 88;   // C3894
   int i = Y1::data_var;
   Y1 ^ MyY1 = gcnew Y1(99);
   Y1::Test();
}
```