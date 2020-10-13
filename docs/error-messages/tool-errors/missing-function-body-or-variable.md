---
title: Corpo de função ou variável ausente
ms.date: 11/04/2016
helpviewer_keywords:
- function body
- variables, missing
ms.assetid: 1a88d809-b14f-46a4-97c4-3e48beb418f2
ms.openlocfilehash: 835bd968035b355ded9636d446d44d4ce069c248
ms.sourcegitcommit: 43cee7a0d41a062661229043c2f7cbc6ace17fa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/13/2020
ms.locfileid: "92008892"
---
# <a name="missing-function-body-or-variable"></a>Corpo de função ou variável ausente

Com apenas um protótipo de função, o compilador pode continuar sem erros, mas o vinculador não pode resolver uma chamada para um endereço porque não há nenhum código de função ou espaço variável reservado. Você não verá esse erro até que você crie uma chamada para a função que o vinculador deve resolver.

## <a name="example-call-to-an-undefined-function"></a>Exemplo: chamar para uma função indefinida

A chamada de função no Main causará LNK2019 porque o protótipo permite que o compilador ache que a função existe.  O vinculador descobre que ele não faz isso.

```cpp
// LNK2019_MFBV.cpp
// LNK2019 expected
void DoSomething(void);
int main() {
   DoSomething();
}
```

## <a name="example-call-to-an-implemented-function"></a>Exemplo: chamar para uma função implementada

Em C++, certifique-se de incluir a implementação de uma função específica para uma classe e não apenas um protótipo na definição de classe. Se você estiver definindo a classe fora do arquivo de cabeçalho, certifique-se de incluir o nome da classe antes da função ( `Classname::memberfunction` ).

```cpp
// LNK2019_MFBV_2.cpp
// LNK2019 expected
struct A {
   static void Test();
};

// Should be void A::Test() {}
void Test() {}

int main() {
   A AObject;
   AObject.Test();
}
```

## <a name="see-also"></a>Veja também

[Erro de ferramentas do vinculador LNK2019](../../error-messages/tool-errors/linker-tools-error-lnk2019.md)
