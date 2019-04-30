---
title: Compilador aviso (nível 4) C4458
ms.date: 11/04/2016
f1_keywords:
- C4458
helpviewer_keywords:
- C4458
ms.assetid: 7bdaa1b1-0caf-4d68-98c4-6bdd441c23fb
ms.openlocfilehash: 9e5eb8dc44968332abc097bfbd16b48e3240695c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62391446"
---
# <a name="compiler-warning-level-4-c4458"></a>Compilador aviso (nível 4) C4458

> declaração de '*identificador*' oculta o membro da classe

A declaração de *identificador* no escopo local oculta a declaração do idêntico *identificador* no escopo da classe. Este aviso informa que faz referência à *identificador* nesse escopo resolver para a versão declarada localmente, não a versão de membro de classe, que pode ou não ser sua intenção. Para corrigir esse problema, recomendamos que você atribua nomes de variáveis locais que não entrem em conflito com nomes de membro de classe.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4458 porque o parâmetro `x` e a variável local `y` em `member_fn` têm os mesmos nomes de membros de dados na classe. Para corrigir esse problema, use nomes diferentes para os parâmetros e variáveis locais.

```cpp
// C4458_hide.cpp
// compile with: cl /W4 /c C4458_hide.cpp

struct S {
    int x;
    float y;
    void member_fn(long x) {   // C4458
        double y;  // C4458
        y = x;
        // To fix this issue, change the parameter name x
        // and local name y to something that does not
        // conflict with the data member names.
    }
} s;
```
