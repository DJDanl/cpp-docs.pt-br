---
title: Erro do compilador C3225 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3225
dev_langs:
- C++
helpviewer_keywords:
- C3225
ms.assetid: f5f66973-256e-4298-ac46-c87819cbde34
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a8d8b1251b9c13a71faf771c85924a75681deab7
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46033245"
---
# <a name="compiler-error-c3225"></a>Erro do compilador C3225

argumento de tipo genérico para 'arg' não pode ser 'type', ele deve ser um tipo de valor ou tipo de identificador

O argumento de tipo genérico não era do tipo correto.

Para obter mais informações, consulte [Genéricos](../../windows/generics-cpp-component-extensions.md).

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