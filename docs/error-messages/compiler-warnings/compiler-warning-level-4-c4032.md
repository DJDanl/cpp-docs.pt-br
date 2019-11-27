---
title: Aviso do compilador (nível 4) C4032
ms.date: 11/04/2016
f1_keywords:
- C4032
helpviewer_keywords:
- C4032
ms.assetid: 70dd0c85-0239-43f9-bb06-507f6a57d206
ms.openlocfilehash: 52e80340a5157e9350b6d4bbf3bcabea0487e089
ms.sourcegitcommit: 3ee06ec53153cf21910fc8cfef78a4f25f9633f3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/26/2019
ms.locfileid: "74541252"
---
# <a name="compiler-warning-level-4-c4032"></a>Aviso do compilador (nível 4) C4032

o parâmetro formal ' Number ' tem um tipo diferente quando promovido

O tipo de parâmetro não é compatível, por meio de promoções padrão, com o tipo em uma declaração anterior.

Isso é um erro em ANSI C ([/za](../../build/reference/za-ze-disable-language-extensions.md)) e um aviso em extensões da Microsoft (/Ze).

## <a name="example"></a>Exemplo

```c
// C4032.c
// compile with: /W4
void func();
void func(char);   // C4032, char promotes to int

int main()
{
}
```