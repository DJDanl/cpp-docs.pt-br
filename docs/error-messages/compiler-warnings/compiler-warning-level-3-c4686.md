---
title: Aviso do compilador (nível 3) C4686
ms.date: 08/27/2018
f1_keywords:
- C4686
helpviewer_keywords:
- C4686
ms.assetid: 767c83c2-9e4b-4f9e-88c8-02128ba563f4
ms.openlocfilehash: a8eae1ddeb875d267b82c67e989cb41e8c9b2afb
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80185445"
---
# <a name="compiler-warning-level-3-c4686"></a>Aviso do compilador (nível 3) C4686

> '*tipo definido pelo usuário*': possível alteração no comportamento, alteração na Convenção de chamada de retorno UDT

## <a name="remarks"></a>Comentários

Uma especialização de modelo de classe não foi definida antes de ser usada em um tipo de retorno. Qualquer coisa que instancie a classe resolverá C4686; declarar uma instância ou acessar um membro (C\<int >:: qualquer coisa) também são opções.

Esse aviso está desativado por padrão. Consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

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
