---
title: Compilador aviso (nível 4) C4456 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4456
dev_langs:
- C++
helpviewer_keywords:
- C4456
ms.assetid: 5ab39fc1-0e19-461b-842b-4da80560b044
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9ab6939fe37260b906a43c4e2ff6683733348952
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46039888"
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
