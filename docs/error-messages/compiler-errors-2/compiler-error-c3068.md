---
title: Erro do compilador C3068
ms.date: 11/04/2016
f1_keywords:
- C3068
helpviewer_keywords:
- C3068
ms.assetid: 613e3447-b4a8-4268-a661-297bed63ccdf
ms.openlocfilehash: 4790c9caafd28722f3631104cfe5cfc762cf6426
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50575468"
---
# <a name="compiler-error-c3068"></a>Erro do compilador C3068

'function': uma função 'naked' não pode conter objetos que possam requerer liberação caso uma exceção de C++

O compilador não pôde executar o desenrolamento de pilha em um [naked](../../cpp/naked-cpp.md) função que gerou uma exceção porque um objeto temporário foi criado a função e o tratamento de exceções C++ ([/EHsc](../../build/reference/eh-exception-handling-model.md)) foi especificado.

Para resolver esse erro, faça pelo menos um dos seguintes:

- Não compile com /EHsc.

- Não marcar a função como `naked`.

- Não crie um objeto temporário na função.

Se uma função cria um objeto temporário na pilha, se a função lançará uma exceção, e se o tratamento de exceções C++ estiver habilitado, o compilador limpará a pilha se uma exceção é lançada.

Quando uma exceção é lançada, o compilador gerou o código, chamado de prólogo e epílogo e que não estão presentes em uma função naked, é executado para uma função.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3068:

```
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