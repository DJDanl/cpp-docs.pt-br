---
title: Compilador aviso (nível 3) C4686
ms.date: 08/27/2018
f1_keywords:
- C4686
helpviewer_keywords:
- C4686
ms.assetid: 767c83c2-9e4b-4f9e-88c8-02128ba563f4
ms.openlocfilehash: 5e23e6aa69fe8a59e3dfd22af7e33780c223cdd3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50584504"
---
# <a name="compiler-warning-level-3-c4686"></a>Compilador aviso (nível 3) C4686

> '*tipo definido pelo usuário*': possível alteração no comportamento, alteração na UDT retorne a convenção de chamada

## <a name="remarks"></a>Comentários

Uma especialização de modelo de classe não era é definida antes de ser usada em um tipo de retorno. Tudo o que instancia a classe resolverá C4686; declarar uma instância ou acesso a um membro (C\<int >:: nada) também são opções.

Esse aviso é desativado por padrão. Ver [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

## <a name="example"></a>Exemplo

Tente o seguinte em vez disso:

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