---
title: Erro do compilador C2681
ms.date: 11/04/2016
f1_keywords:
- C2681
helpviewer_keywords:
- C2681
ms.assetid: eb42da6d-8d2c-43fd-986b-e73e2b004885
ms.openlocfilehash: 8b311052d3a3525090d954c0dc8cee20e985b1b4
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62282134"
---
# <a name="compiler-error-c2681"></a>Erro do compilador C2681

'type': tipo de expressão inválido para nome

Um operador de conversão tentou converter de um tipo inválido. Por exemplo, se você usar o [dynamic_cast](../../cpp/dynamic-cast-operator.md) operador para converter uma expressão em um tipo de ponteiro, a expressão de origem deve ser um ponteiro.

O exemplo a seguir gera C2681:

```
// C2681.cpp
class A { virtual void f(); };

void g(int i) {
    A* pa;
    pa = dynamic_cast<A*>(i);  // C2681
}
```