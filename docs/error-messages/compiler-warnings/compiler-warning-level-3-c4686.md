---
title: Aviso do compilador (nível 3) C4686
description: Aviso do compilador do Microsoft C++ C4686.
ms.date: 08/29/2020
f1_keywords:
- C4686
helpviewer_keywords:
- C4686
ms.assetid: 767c83c2-9e4b-4f9e-88c8-02128ba563f4
ms.openlocfilehash: 6886ae7f413de630457b53e85b5cd75c4542ee19
ms.sourcegitcommit: 3628707bc17c99aac7aac27eb126cc2eaa4d07b4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/31/2020
ms.locfileid: "89194491"
---
# <a name="compiler-warning-level-3-c4686"></a>Aviso do compilador (nível 3) C4686

> '*tipo definido pelo usuário*': possível alteração no comportamento, alteração na Convenção de chamada de retorno UDT

## <a name="remarks"></a>Comentários

Uma especialização de modelo de classe não foi definida antes de ser usada em um tipo de retorno. Tudo que instancia a classe resolve C4686; declarar uma instância ou acessar um membro (por exemplo, `C<int>::some_member` ) também são opções.

Esse aviso está desativado por padrão. Para obter mais informações, consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).

## <a name="example"></a>Exemplo

Em vez disso, tente o seguinte:

```cpp
// C4686.cpp
// compile with: /W3
#pragma warning (default : 4686)
template <class T>
class C;

template <class T>
C<T> f(T);

template <class T>
class C {};

int main() {
   f(1);   // C4686
}

template <class T>
C<T> f(T) {
   return C<int>();
}
```
