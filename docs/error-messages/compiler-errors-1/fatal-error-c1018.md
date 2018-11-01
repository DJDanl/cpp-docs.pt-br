---
title: Erro fatal C1018
ms.date: 11/04/2016
f1_keywords:
- C1018
helpviewer_keywords:
- C1018
ms.assetid: 2ceb8a99-30b2-4b80-bf42-e9f3305b3c52
ms.openlocfilehash: 327bc0d5200fc348611da107257f2086063648fa
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50532646"
---
# <a name="fatal-error-c1018"></a>Erro fatal C1018

#elif inesperado

O `#elif` diretiva aparece fora de um `#if`, `#ifdef`, ou `#ifndef` construir. Use `#elif` apenas dentro de uma dessas construções.

O exemplo a seguir gera C1018:

```
// C1018.cpp
#elif      // C1018
#endif

int main() {}
```

Solução possível:

```
// C1018b.cpp
#if 1
#elif
#endif

int main() {}
```