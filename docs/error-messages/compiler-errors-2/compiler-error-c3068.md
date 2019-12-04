---
title: Erro do compilador C3068
ms.date: 11/04/2016
f1_keywords:
- C3068
helpviewer_keywords:
- C3068
ms.assetid: 613e3447-b4a8-4268-a661-297bed63ccdf
ms.openlocfilehash: 9e20333a4fc18219f7f2514f3aefe73b81f284a6
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74759484"
---
# <a name="compiler-error-c3068"></a>Erro do compilador C3068

' function ': uma função ' naked ' não pode conter objetos que exijam desenrolar se C++ uma exceção ocorreu

O compilador não pôde executar o desenrolamento de pilha em uma função [Naked](../../cpp/naked-cpp.md) que gerou uma exceção porque um objeto temporário foi criado na função e C++ o tratamento de exceção ([/EHsc](../../build/reference/eh-exception-handling-model.md)) foi especificado.

Para resolver esse erro, faça pelo menos um dos seguintes:

- Não compilar com/EHsc.

- Não marque a função como `naked`.

- Não crie um objeto temporário na função.

Se uma função criar um objeto temporário na pilha, se a função lançar uma exceção e se C++ a manipulação de exceção estiver habilitada, o compilador limpará a pilha se uma exceção for lançada.

Quando uma exceção é lançada, o código gerado pelo compilador, chamado prólogo e epílogo e que não estão presentes em uma função Naked, é executado para uma função.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3068:

```cpp
// C3068.cpp
// compile with: /EHsc
// processor: x86
class A {
public:
   A(){}
   ~A(){}
};

void b(A){}

__declspec(naked) void c() {
   b(A());   // C3068
};
```
