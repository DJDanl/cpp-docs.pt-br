---
title: Compilador aviso (nível 4) C4457
ms.date: 11/04/2016
f1_keywords:
- C4457
helpviewer_keywords:
- C4457
ms.assetid: 02fd149a-917d-4f67-97a6-eb714572271f
ms.openlocfilehash: 11307ddc3b13a9cd9b36f1ee927082104792b07f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50648351"
---
# <a name="compiler-warning-level-4-c4457"></a>Compilador aviso (nível 4) C4457

> declaração de '*identificador*' oculta o parâmetro de função

A declaração de *identificador* no escopo local oculta a declaração do parâmetro de função idêntico. Este aviso informa que faz referência à *identificador* no escopo local resolver para a versão declarada localmente, não o parâmetro, o que pode ou não ser sua intenção. Para corrigir esse problema, recomendamos que você atribua nomes de variáveis locais que não entrem em conflito com nomes de parâmetro.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4457 porque o parâmetro `x` e a variável local `x` em `member_fn` têm os mesmos nomes. Para corrigir esse problema, use nomes diferentes para os parâmetros e variáveis locais.

```cpp
// C4457_hide.cpp
// compile with: cl /W4 /c C4457_hide.cpp

struct S {
    void member_fn(unsigned x) {
        double a = 0;
        for (int x = 0; x < 10; ++x) {  // C4457
            a += x; // uses local x
        }
        a += x; // uses parameter x
    }
} s;
```
