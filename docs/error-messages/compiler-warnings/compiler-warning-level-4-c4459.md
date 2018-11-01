---
title: Compilador aviso (nível 4) C4459
ms.date: 11/04/2016
f1_keywords:
- C4459
helpviewer_keywords:
- C4459
ms.assetid: ee9f6287-9c70-4b10-82a0-add82a13997f
ms.openlocfilehash: 0cbab7c7cca1fc88bb99210262be45c56b6be7a8
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50585062"
---
# <a name="compiler-warning-level-4-c4459"></a>Compilador aviso (nível 4) C4459

> declaração de '*identificador*' oculta uma declaração global

A declaração de *identificador* no escopo local oculta a declaração do idêntico *identificador* no escopo global. Este aviso informa que faz referência à *identificador* nesse escopo resolver para a versão declarada localmente, não a versão global, que pode ou não ser sua intenção. Em geral, recomendamos que você minimize o uso de variáveis globais como uma boa prática de engenharia. Para minimizar a poluição de namespace global, é recomendável o uso de um namespace nomeado para as variáveis globais.

Esse aviso era novo no Visual Studio 2015, no Visual C++ versão do compilador 18h00 Hora. Para suprimir avisos do que a versão do compilador ou posterior ao migrar seu código, use o [/wv:18](../../build/reference/compiler-option-warning-level.md) opção de compilador.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4459:

```cpp
// C4459_hide.cpp
// compile with: cl /W4 /EHsc C4459_hide.cpp
int global_or_local = 1;

int main() {
    int global_or_local; // warning C4459
    global_or_local = 2;
}
```

Uma maneira de corrigir esse problema é criar um namespace para seu globais, mas não usar um `using` nomes qualificados de diretiva para trazer esse namespace para o escopo, para que todas as referências devem usar o ambígua:

```cpp
// C4459_namespace.cpp
// compile with: cl /W4 /EHsc C4459_namespace.cpp
namespace globals {
    int global_or_local = 1;
}

int main() {
    int global_or_local; // OK
    global_or_local = 2;
    globals::global_or_local = 3;
}
```
