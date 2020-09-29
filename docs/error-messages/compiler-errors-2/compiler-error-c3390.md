---
title: Erro do compilador C3390
description: Erro C3390 do compilador do Microsoft C++, suas causas e como resolvê-los.
ms.date: 09/26/2020
f1_keywords:
- C3390
helpviewer_keywords:
- C3390
ms.assetid: 84800a87-c8e6-45aa-82ae-02f816dc8d97
ms.openlocfilehash: 467b379d7f5a349a217b566dc55b28d5fbd789da
ms.sourcegitcommit: 94893973211d0b254c8bcdcf0779997dcc136b0c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/28/2020
ms.locfileid: "91414354"
---
# <a name="compiler-error-c3390"></a>Erro do compilador C3390

> '*type_arg*': argumento de tipo inválido para parâmetro de Generic '*param*' de Generic '*generic_type*', deve ser um tipo de referência

Um tipo genérico foi instanciado incorretamente. Verifique a definição de tipo.

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Genéricos](../../extensions/generics-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O primeiro exemplo usa C# para criar um componente que contém um tipo genérico. Este tipo tem determinadas restrições que não têm suporte durante a criação de tipos genéricos em C++/CLI. Para obter mais informações, consulte [Restrições a parâmetros de tipo](/dotnet/csharp/programming-guide/generics/constraints-on-type-parameters).

```csharp
// C3390.cs
// Compile by using: csc /target:library C3390.cs
// a C# program
public class GR<C, V, N>
where C : class
where V : struct
where N : new() {}
```

Quando o componente C3390.dll está disponível, o exemplo a seguir gera C3390.

```cpp
// C3390_b.cpp
// Compile by using: cl /clr C3390_b.cpp
#using <C3390.dll>
ref class R { R(int) {} };
value class V {};
ref struct N { N() {} };

int main () {
   GR<V, V, N^>^ gr2;   // C3390 first type must be a ref type
   GR<R^, V, N^>^ gr2b; // OK - do this instead
}
```
