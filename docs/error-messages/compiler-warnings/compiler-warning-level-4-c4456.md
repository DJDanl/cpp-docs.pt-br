---
title: Compilador aviso (nível 4) C4456
ms.date: 11/04/2016
f1_keywords:
- C4456
helpviewer_keywords:
- C4456
ms.assetid: 5ab39fc1-0e19-461b-842b-4da80560b044
ms.openlocfilehash: 006628721598d838070412c895f64b9a8d3de4e9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62391498"
---
# <a name="compiler-warning-level-4-c4456"></a>Compilador aviso (nível 4) C4456

> declaração de '*identificador*' oculta uma declaração local anterior

A declaração de *identificador* no escopo local oculta a declaração da declaração de local anterior do mesmo nome. Este aviso informa que faz referência à *identificador* no escopo local resolver para a versão declarada localmente, não o local anterior, que pode ou não ser sua intenção. Para corrigir esse problema, recomendamos que você atribua nomes de variáveis locais que não entrem em conflito com outros nomes de locais.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4456 porque a variável de controle de loop `int x` e a variável local `double x` em `member_fn` têm os mesmos nomes. Para corrigir esse problema, use nomes diferentes para as variáveis locais.

```cpp
// C4456_hide.cpp
// compile with: cl /W4 /c C4456_hide.cpp

struct S {
    void member_fn(unsigned u) {
        double x = 0;
        for (int x = 0; x < 10; ++x) {  // C4456
            u += x; // uses local int x
        }
        x += u; // uses local double x
    }
} s;
```
