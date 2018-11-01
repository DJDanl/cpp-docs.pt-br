---
title: Erro do compilador C3392
ms.date: 11/04/2016
f1_keywords:
- C3392
helpviewer_keywords:
- C3392
ms.assetid: e4757596-e2aa-4314-b01e-5c4bfd2110e9
ms.openlocfilehash: 34097de7d50e260ee82a8891cee988b1533debdd
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50556566"
---
# <a name="compiler-error-c3392"></a>Erro do compilador C3392

'type_arg': argumento de tipo inválido para parâmetro de generic param de genérico 'generic_type' deve ter um construtor público sem parâmetros

Um tipo genérico foi instanciado incorretamente. Verifique a definição de tipo. Para obter mais informações, consulte [genéricos](../../windows/generics-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir usa c# para criar um componente que contém um tipo genérico que tem certas restrições que não têm suporte durante a criação de tipos genéricos no C + + / CLI. Para obter mais informações, consulte [Restrições a parâmetros de tipo](/dotnet/csharp/programming-guide/generics/constraints-on-type-parameters).

```cs
// C3392.cs
// Compile by using: csc /target:library C3392.cs
// a C# program
public class GR<C, V, N>
where C : class
where V : struct
where N : new() {}
```

Quando o componente C3392.dll estiver disponível, o exemplo a seguir gera C3392.

```cpp
// C3392_b.cpp
// Compile by using: cl /clr C3392_b.cpp
#using <C3392.dll>

ref class R { R(int) {} };
ref class N { N() {} };

value class V {};

ref class N2 { public: N2() {} };
ref class R2 { public: R2() {} };

int main () {
   GR<R^, V, N^>^ gr1;   // C3392
   GR<R^, V, N2^>^ gr1a; // OK

   GR<R^, N^, N^>^ gr3;  // C3392
   GR<R^, V, N2^>^ gr3a; // OK

   GR<R^, V, R^>^ gr4;   // C3392
   GR<R^, V, R2^>^ gr4a; // OK
}
```