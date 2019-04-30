---
title: Compilador aviso (nível 1) C4090
ms.date: 11/04/2016
f1_keywords:
- C4090
helpviewer_keywords:
- C4090
ms.assetid: baad469d-23d4-45aa-ad9c-305b32d61e9a
ms.openlocfilehash: b47d0bfbb6eab24fbe811d3e4f79b6bd86b3bb11
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62406464"
---
# <a name="compiler-warning-level-1-c4090"></a>Compilador aviso (nível 1) C4090

'operation': qualificadores 'modificador' diferente

Uma variável usada em uma operação é definida com um modificador especificado que impede que ele seja modificado sem detecção pelo compilador. A expressão é compilada sem modificação.

Esse aviso pode ser causado quando um ponteiro para um **const** ou `volatile` item for atribuído a um ponteiro não declarado como apontando para **const** ou `volatile`.

Esse aviso é emitido para programas em C. Em um C++ programa, o compilador emitirá um erro: [C2440](../../error-messages/compiler-errors-1/compiler-error-c2440.md).

O exemplo a seguir gera C4090:

```
// C4090.c
// compile with: /W1
int *volatile *p;
int *const *q;
int **r;

int main() {
   p = q;   // C4090
   p = r;
   q = p;   // C4090
   q = r;
   r = p;   // C4090
   r = q;   // C4090
}
```