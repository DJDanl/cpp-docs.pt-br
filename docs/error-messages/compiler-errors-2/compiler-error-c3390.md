---
title: Erro do compilador C3390
ms.date: 11/04/2016
f1_keywords:
- C3390
helpviewer_keywords:
- C3390
ms.assetid: 84800a87-c8e6-45aa-82ae-02f816dc8d97
ms.openlocfilehash: e1146bf0ed2dd6d38a3c67cc6799c0e73f253323
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50532607"
---
# <a name="compiler-error-c3390"></a>Erro do compilador C3390

'type_arg': argumento de tipo inválido para parâmetro de generic param de genérico 'generic_type' deve ser um tipo de referência

Um tipo genérico foi instanciado incorretamente.  Verifique a definição de tipo.  Para obter mais informações, consulte [Genéricos](../../windows/generics-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O primeiro exemplo usa c# para criar um componente que contém um tipo genérico que tem certas restrições que não têm suporte durante a criação de tipos genéricos no C + + / CLR. Para obter mais informações, consulte [Restrições a parâmetros de tipo](/dotnet/csharp/programming-guide/generics/constraints-on-type-parameters).

```cs
// C3390.cs
// Compile by using: csc /target:library C3390.cs
// a C# program
public class GR<C, V, N>
where C : class
where V : struct
where N : new() {}
```

Quando o componente C3390.dll estiver disponível, o exemplo a seguir gera C3390.

```cpp
// C3390_b.cpp
// Compile by using: cl /clr C3390_b.cpp
#using <C3390.dll>
ref class R { R(int) {} };
value class V {};
ref struct N { N() {} };

int main () {
   GR<V, V, N^>^ gr2;   // C3390 first type must be a ref type
   GR<R^, V, N^>^ gr2b; // OK
}
```