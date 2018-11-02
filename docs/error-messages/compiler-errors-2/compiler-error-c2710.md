---
title: Erro do compilador C2710
ms.date: 11/04/2016
f1_keywords:
- C2710
helpviewer_keywords:
- C2710
ms.assetid: a2a6bb5b-86ad-4a6c-acd0-e2bef8464e0e
ms.openlocfilehash: 54d501d43652bb8e54092d44042a9525ef6f708f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50618940"
---
# <a name="compiler-error-c2710"></a>Erro do compilador C2710

'Criar': '__declspec(modifier)' só pode ser aplicado a uma função que retorna um ponteiro

Uma função cujo valor de retorno é um ponteiro é a construção somente para o qual `modifier` podem ser aplicadas.

O exemplo a seguir gera C2710:

```
// C2710.cpp
__declspec(restrict) void f();   // C2710
// try the following line instead
__declspec(restrict) int * g();
```