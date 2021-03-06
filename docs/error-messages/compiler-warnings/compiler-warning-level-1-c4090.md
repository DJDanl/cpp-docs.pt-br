---
title: Aviso do compilador (nível 1) C4090
ms.date: 11/04/2016
f1_keywords:
- C4090
helpviewer_keywords:
- C4090
ms.assetid: baad469d-23d4-45aa-ad9c-305b32d61e9a
ms.openlocfilehash: c4cb71355b4f3dca66c56ed4b89012ca9b9e646d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87197040"
---
# <a name="compiler-warning-level-1-c4090"></a>Aviso do compilador (nível 1) C4090

' Operation ': qualificadores ' modificadores ' diferentes

Uma variável usada em uma operação é definida com um modificador especificado que impede que ele seja modificado sem detecção pelo compilador. A expressão é compilada sem modificação.

Esse aviso pode ser causado quando um ponteiro para um **`const`** **`volatile`** item ou é atribuído a um ponteiro não declarado como apontar para **`const`** ou **`volatile`** .

Esse aviso é emitido para programas do C. Em um programa C++, o compilador emite um erro: [C2440](../../error-messages/compiler-errors-1/compiler-error-c2440.md).

O exemplo a seguir gera C4090:

```c
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
