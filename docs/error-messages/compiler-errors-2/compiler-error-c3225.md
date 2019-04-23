---
title: Erro do compilador C3225
ms.date: 11/04/2016
f1_keywords:
- C3225
helpviewer_keywords:
- C3225
ms.assetid: f5f66973-256e-4298-ac46-c87819cbde34
ms.openlocfilehash: cae0572002c849fb5aed771993d3a89ed82c726a
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59778263"
---
# <a name="compiler-error-c3225"></a>Erro do compilador C3225

argumento de tipo genérico para 'arg' não pode ser 'type', ele deve ser um tipo de valor ou tipo de identificador

O argumento de tipo genérico não era do tipo correto.

Para obter mais informações, consulte [Genéricos](../../extensions/generics-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

Você não pode criar uma instância de um tipo genérico com um tipo nativo. O exemplo a seguir gera C3225.

```
// C3225.cpp
// compile with: /clr
class A {};

ref class B {};

generic <class T>
ref class C {};

int main() {
   C<A>^ c = gcnew C<A>;   // C3225
   C<B^>^ c2 = gcnew C<B^>;   // OK
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir cria um componente usando a linguagem c#. Observe que a restrição Especifica que o tipo genérico só pode ser instanciado com um tipo de valor.

```
// C3225_b.cs
// compile with: /target:library
// a C# program
public class MyList<T> where T: struct {}
```

## <a name="example"></a>Exemplo

Este exemplo consome c#-autor de componente e viola a restrição de MyList só pode ser instanciado com um tipo de valor diferente de <xref:System.Nullable>. O exemplo a seguir gera C3225.

```
// C3225_c.cpp
// compile with: /clr
#using "C3225_b.dll"
ref class A {};
value class B {};
int main() {
   MyList<A> x;   // C3225
   MyList<B> y;   // OK
}
```