---
title: Erro do compilador C3225
ms.date: 11/04/2016
f1_keywords:
- C3225
helpviewer_keywords:
- C3225
ms.assetid: f5f66973-256e-4298-ac46-c87819cbde34
ms.openlocfilehash: 1caa1e7ce787ffc14e615c946b5d670c75e0332a
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74757612"
---
# <a name="compiler-error-c3225"></a>Erro do compilador C3225

argumento de tipo genérico para ' arg ' não pode ser ' type ', deve ser um tipo de valor ou tipo de identificador

O argumento de tipo genérico não era do tipo correto.

Para obter mais informações, consulte [Genéricos](../../extensions/generics-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

Você não pode criar uma instância de um tipo genérico com um tipo nativo. O exemplo a seguir gera C3225.

```cpp
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

O exemplo a seguir cria um componente C#usando. Observe que a restrição especifica que o tipo genérico só pode ser instanciado com um tipo de valor.

```
// C3225_b.cs
// compile with: /target:library
// a C# program
public class MyList<T> where T: struct {}
```

## <a name="example"></a>Exemplo

Esta amostra consome o C#componente-autoria e viola a restrição de que myList só pode ser instanciada com um tipo de valor diferente de <xref:System.Nullable>. O exemplo a seguir gera C3225.

```cpp
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
