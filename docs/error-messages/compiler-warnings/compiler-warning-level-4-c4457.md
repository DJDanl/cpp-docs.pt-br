---
title: Compilador aviso (nível 4) C4457 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4457
dev_langs:
- C++
helpviewer_keywords:
- C4457
ms.assetid: 02fd149a-917d-4f67-97a6-eb714572271f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 62232a814bed47f8b6a5041d20e6f37776abffe8
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46093526"
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
