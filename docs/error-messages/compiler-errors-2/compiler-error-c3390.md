---
title: Erro do compilador C3390 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3390
dev_langs:
- C++
helpviewer_keywords:
- C3390
ms.assetid: 84800a87-c8e6-45aa-82ae-02f816dc8d97
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f7f1a19d86e133d01a17703f7ef4b3a79d5eb601
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46111986"
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