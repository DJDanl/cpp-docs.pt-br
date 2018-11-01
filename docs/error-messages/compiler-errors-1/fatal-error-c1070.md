---
title: Erro fatal C1070
ms.date: 11/04/2016
f1_keywords:
- C1070
helpviewer_keywords:
- C1070
ms.assetid: 1058269a-5db6-4c23-a97f-b5269eb9188b
ms.openlocfilehash: 7e156a230ce9550b65d1b8775947fc7294c15377
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50445013"
---
# <a name="fatal-error-c1070"></a>Erro fatal C1070

incompatíveis #if / par #endif no arquivo 'filename'

Uma `#if`, `#ifdef`, ou `#ifndef` diretiva não tem correspondente `#endif`.

O exemplo a seguir gera C1070:

```
// C1070.cpp
#define TEST

#ifdef TEST

#ifdef TEST
#endif
// C1070
```

Solução possível:

```
// C1070b.cpp
// compile with: /c
#define TEST

#ifdef TEST
#endif

#ifdef TEST
#endif
```