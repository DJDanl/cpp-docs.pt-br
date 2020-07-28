---
title: Aviso do compilador (nível 4) C4459
ms.date: 11/04/2016
f1_keywords:
- C4459
helpviewer_keywords:
- C4459
ms.assetid: ee9f6287-9c70-4b10-82a0-add82a13997f
ms.openlocfilehash: d6d0a802f9f628145fbc5910aca805a5b01b94d2
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87214367"
---
# <a name="compiler-warning-level-4-c4459"></a>Aviso do compilador (nível 4) C4459

> a declaração de '*Identifier*' oculta a declaração global

A declaração do *identificador* no escopo local oculta a declaração do *identificador* nomeado de forma idêntica no escopo global. Esse aviso informa que as referências ao *identificador* nesse escopo resolvem a versão declarada localmente, não a versão global, que pode ou não ser sua intenção. Em geral, recomendamos que você minimize o uso de variáveis globais como uma boa prática de engenharia. Para minimizar a poluição do namespace global, recomendamos o uso de um namespace nomeado para variáveis globais.

Esse aviso foi novo no Visual Studio 2015, no compilador do Microsoft C++ versão 18, 0. Para suprimir os avisos dessa versão do compilador ou mais tarde ao migrar seu código, use a opção de compilador [/WV: 18](../../build/reference/compiler-option-warning-level.md) .

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

Uma maneira de corrigir esse problema é criar um namespace para seus globais, mas não usar uma **`using`** diretiva para trazer esse namespace para o escopo, de modo que todas as referências devem usar os nomes qualificados não ambíguos:

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
