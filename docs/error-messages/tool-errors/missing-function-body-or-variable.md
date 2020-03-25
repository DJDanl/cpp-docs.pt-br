---
title: Corpo de função ou variável ausente
ms.date: 11/04/2016
helpviewer_keywords:
- function body
- variables, missing
ms.assetid: 1a88d809-b14f-46a4-97c4-3e48beb418f2
ms.openlocfilehash: 6d2ef22b90009d320485fb6fe3f7e308ae05c442
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80173615"
---
# <a name="missing-function-body-or-variable"></a>Corpo de função ou variável ausente

Com apenas um protótipo de função, o compilador pode continuar sem erros, mas o vinculador não pode resolver uma chamada para um endereço porque não há nenhum código de função ou espaço variável reservado. Você não verá esse erro até que você crie uma chamada para a função que o vinculador deve resolver.

## <a name="example"></a>Exemplo

A chamada de função no Main causará LNK2019 porque o protótipo permite que o compilador ache que a função existe.  O vinculador descobre que ele não faz isso.

```cpp
// LNK2019_MFBV.cpp
// LNK2019 expected
void DoSomething(void);
int main() {
   DoSomething();
}
```

## <a name="example"></a>Exemplo

No C++, certifique-se de incluir a implementação de uma função específica para uma classe e não apenas um protótipo na definição de classe. Se você estiver definindo a classe fora do arquivo de cabeçalho, certifique-se de incluir o nome da classe antes da função (`Classname::memberfunction`).

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

## <a name="see-also"></a>Confira também

[Erro das ferramentas de vinculador LNK2019](../../error-messages/tool-errors/linker-tools-error-lnk2019.md)
