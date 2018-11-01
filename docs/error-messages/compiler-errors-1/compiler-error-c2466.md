---
title: Erro do compilador C2466
ms.date: 11/04/2016
f1_keywords:
- C2466
helpviewer_keywords:
- C2466
ms.assetid: 75b251d1-7d0b-4a86-afca-26adedf74486
ms.openlocfilehash: 516f9b024947e0100a753e4e010a5b51b1fb24a1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50526302"
---
# <a name="compiler-error-c2466"></a>Erro do compilador C2466

não é possível alocar uma matriz de tamanho da constante 0

Uma matriz está alocada ou declarada com tamanho zero. A expressão de constante para o tamanho da matriz deve ser um inteiro maior que zero. Uma declaração de matriz com um zero subscrito é válida somente para uma classe, estrutura ou membro de união e somente com extensões Microsoft ([/Ze](../../build/reference/za-ze-disable-language-extensions.md)).

O exemplo a seguir gera C2466:

```
// C2466.cpp
// compile with: /c
int i[0];   // C2466
int j[1];   // OK
char *p;
```