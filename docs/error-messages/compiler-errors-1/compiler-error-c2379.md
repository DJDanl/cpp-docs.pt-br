---
title: Erro do compilador C2379
ms.date: 11/04/2016
f1_keywords:
- C2379
helpviewer_keywords:
- C2379
ms.assetid: 37dc3015-a4af-4341-bbf3-da6150df7e51
ms.openlocfilehash: 1b3256efb6c0ff8236ba80a9ac681780f34fa8dd
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50643840"
---
# <a name="compiler-error-c2379"></a>Erro do compilador C2379

número de parâmetros formais possui tipo diferente quando promovido

O tipo do parâmetro especificado não é compatível, por meio de promoções de padrão, com o tipo em uma declaração anterior. Este é um erro em ANSI C ([/Za](../../build/reference/za-ze-disable-language-extensions.md)) e um aviso com extensões da Microsoft (**/Ze**).

O exemplo a seguir gera C2379:

```
// C2379.c
// compile with: /Za
void func();
void func(char);   // C2379, char promotes to int
```