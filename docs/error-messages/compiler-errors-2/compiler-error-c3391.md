---
title: Erro do compilador C3391
ms.date: 11/04/2016
f1_keywords:
- C3391
helpviewer_keywords:
- C3391
ms.assetid: c32532b9-7db4-4ccd-84b9-479e5a1a19d1
ms.openlocfilehash: 32ba1ca63a3a6fafa3290946a976e6845385126f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62328686"
---
# <a name="compiler-error-c3391"></a>Erro do compilador C3391

'type_arg': argumento de tipo inválido para parâmetro de generic param de genérico 'generic_type' deve ser um tipo de valor não anulável

Um tipo genérico foi instanciado incorretamente. Verifique a definição de tipo. Para obter mais informações, consulte <xref:System.Nullable> e [genéricos](../../extensions/generics-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir usa C# para criar um componente que contém um tipo genérico que tem certas restrições que não têm suporte durante a criação de tipos genéricos no C++/CLI. Para obter mais informações, consulte [Restrições a parâmetros de tipo](/dotnet/csharp/programming-guide/generics/constraints-on-type-parameters).

```cs
// C3391.cs
// Compile by using: csc /target:library C3391.cs
// a C# program
public class GR<N>
where N : struct {}
```

Quando o componente C3391.dll estiver disponível, o exemplo a seguir gera C3391.

```cpp
// C3391_b.cpp
// Compile by using: cl /clr C3391_b.cpp
#using <C3391.dll>
using namespace System;
value class VClass {};

int main() {
   GR< Nullable<VClass> >^ a =
      gcnew GR< Nullable<VClass> >();   // C3391 can't be Nullable
   GR<VClass>^ aa = gcnew GR<VClass>(); // OK
}
```