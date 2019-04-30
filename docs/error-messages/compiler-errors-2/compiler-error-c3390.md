---
title: Erro do compilador C3390
ms.date: 11/04/2016
f1_keywords:
- C3390
helpviewer_keywords:
- C3390
ms.assetid: 84800a87-c8e6-45aa-82ae-02f816dc8d97
ms.openlocfilehash: 3f1149d4584a0ea3d0061a3ec4e2b77830603ef2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62400312"
---
# <a name="compiler-error-c3390"></a>Erro do compilador C3390

'type_arg': argumento de tipo inválido para parâmetro de generic param de genérico 'generic_type' deve ser um tipo de referência

Um tipo genérico foi instanciado incorretamente.  Verifique a definição de tipo.  Para obter mais informações, consulte [Genéricos](../../extensions/generics-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O primeiro exemplo usa C# para criar um componente que contém um tipo genérico que tem certas restrições que não têm suporte durante a criação de tipos genéricos no C++/CLR. Para obter mais informações, consulte [Restrições a parâmetros de tipo](/dotnet/csharp/programming-guide/generics/constraints-on-type-parameters).

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