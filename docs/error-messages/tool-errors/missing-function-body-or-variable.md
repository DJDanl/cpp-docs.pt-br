---
title: Corpo de função ou variável ausente
ms.date: 11/04/2016
helpviewer_keywords:
- function body
- variables, missing
ms.assetid: 1a88d809-b14f-46a4-97c4-3e48beb418f2
ms.openlocfilehash: 88470272192520e9aa0582fd06ff36a0542803ba
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50647116"
---
# <a name="missing-function-body-or-variable"></a>Corpo de função ou variável ausente

Com apenas um protótipo de função, o compilador pode continuar sem erro, mas o vinculador não pode resolver uma chamada para um endereço, porque não há nenhum código de função ou variável espaço reservado. Você não verá esse erro até que você crie uma chamada para a função que o vinculador deve resolver.

## <a name="example"></a>Exemplo

A chamada de função em main causará LNK2019, porque o protótipo permite que o compilador acha que a função existe.  O vinculador localiza que ele não.

```
// LNK2019_MFBV.cpp
// LNK2019 expected
void DoSomething(void);
int main() {
   DoSomething();
}
```

## <a name="example"></a>Exemplo

No C++, certifique-se de que você inclua a implementação de uma função específica para uma classe e não apenas um protótipo na definição de classe. Se você estiver definindo a classe fora do arquivo de cabeçalho, certifique-se de incluir o nome da classe antes da função (`Classname::memberfunction`).

```
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

## <a name="see-also"></a>Consulte também

[Erro das ferramentas de vinculador LNK2019](../../error-messages/tool-errors/linker-tools-error-lnk2019.md)