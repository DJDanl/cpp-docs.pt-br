---
title: Aviso do compilador (nível 1) C4090
ms.date: 11/04/2016
f1_keywords:
- C4090
helpviewer_keywords:
- C4090
ms.assetid: baad469d-23d4-45aa-ad9c-305b32d61e9a
ms.openlocfilehash: 88ed48e9bf7057c55ee4004ca1bb1eb18cd4be51
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73626161"
---
# <a name="compiler-warning-level-1-c4090"></a>Aviso do compilador (nível 1) C4090

' Operation ': qualificadores ' modificadores ' diferentes

Uma variável usada em uma operação é definida com um modificador especificado que impede que ele seja modificado sem detecção pelo compilador. A expressão é compilada sem modificação.

Esse aviso pode ser causado quando um ponteiro para um item **const** ou `volatile` é atribuído a um ponteiro não declarado como apontando para **const** ou `volatile`.

Esse aviso é emitido para programas do C. Em um C++ programa, o compilador emite um erro: [C2440](../../error-messages/compiler-errors-1/compiler-error-c2440.md).

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