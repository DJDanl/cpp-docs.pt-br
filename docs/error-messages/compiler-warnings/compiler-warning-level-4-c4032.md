---
title: Compilador aviso (nível 4) C4032
ms.date: 11/04/2016
f1_keywords:
- C4032
helpviewer_keywords:
- C4032
ms.assetid: 70dd0c85-0239-43f9-bb06-507f6a57d206
ms.openlocfilehash: fa1602d63ed9822725fea8e1b842929f221d3926
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62401456"
---
# <a name="compiler-warning-level-4-c4032"></a>Compilador aviso (nível 4) C4032

o parâmetro formal 'número' tem um tipo diferente quando promovido

O tipo de parâmetro não é compatível, por meio de promoções de padrão, com o tipo em uma declaração anterior.

Este é um erro em ANSI C ([/Za](../../build/reference/za-ze-disable-language-extensions.md)) e um aviso em extensões da Microsoft (/Ze).

## <a name="example"></a>Exemplo

```
// C4032.c
// compile with: /W4
void func();
void func(char);   // C4032, char promotes to int

int main()
{
}
```