---
title: Erro do compilador C2448
ms.date: 11/04/2016
f1_keywords:
- C2448
helpviewer_keywords:
- C2448
ms.assetid: e255df3c-f861-4b4d-a193-8768cef061a5
ms.openlocfilehash: 915217ffbe848b2814e9960183854e09a80b9ee8
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50434847"
---
# <a name="compiler-error-c2448"></a>Erro do compilador C2448

'identifier': inicializador function-style parece ser uma definição de função

A definição de função está incorreta.

Esse erro pode ser causado por uma lista formal de linguagem C antiga.

O exemplo a seguir gera C2448:

```
// C2448.cpp
void func(c)
   int c;
{}   // C2448
```