---
title: Erro do compilador C2466
ms.date: 11/04/2016
f1_keywords:
- C2466
helpviewer_keywords:
- C2466
ms.assetid: 75b251d1-7d0b-4a86-afca-26adedf74486
ms.openlocfilehash: aba4de518b9296fadc4746540e4e738c74908617
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74743816"
---
# <a name="compiler-error-c2466"></a>Erro do compilador C2466

Não é possível alocar uma matriz de tamanho constante 0

Uma matriz é alocada ou declarada com o tamanho zero. A expressão constante para o tamanho da matriz deve ser um número inteiro maior que zero. Uma declaração de matriz com um subscript zero é válida apenas para um membro de classe, estrutura ou União e somente com extensões da Microsoft ([/ze](../../build/reference/za-ze-disable-language-extensions.md)).

O exemplo a seguir gera C2466:

```cpp
// C2466.cpp
// compile with: /c
int i[0];   // C2466
int j[1];   // OK
char *p;
```
