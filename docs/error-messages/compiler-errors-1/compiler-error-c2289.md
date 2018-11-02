---
title: Erro do compilador C2289
ms.date: 11/04/2016
f1_keywords:
- C2289
helpviewer_keywords:
- C2289
ms.assetid: cb41a29e-1b06-47dc-bfce-8d73bd63a0df
ms.openlocfilehash: 9fe9b765af72a8864e3e899cafcf648a9facb67e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50528106"
---
# <a name="compiler-error-c2289"></a>Erro do compilador C2289

mesmo qualificador de tipo usado mais de uma vez

Uma declaração de tipo ou definição usa um qualificador de tipo (`const`, `volatile`, `signed`, ou `unsigned`) mais de uma vez, causando um erro de compatibilidade com ANSI (**/Za**).

O exemplo a seguir gera C2286:

```
// C2289.cpp
// compile with: /Za /c
volatile volatile int i;   // C2289
volatile int j;   // OK
```