---
title: Erro fatal C1016
ms.date: 11/04/2016
f1_keywords:
- C1016
helpviewer_keywords:
- C1016
ms.assetid: 33f45c3e-2d8f-43ad-a445-c412d1d54ce1
ms.openlocfilehash: b5774503297c596a351d72f3af4de6040628b078
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74756949"
---
# <a name="fatal-error-c1016"></a>Erro fatal C1016

\#ifdef esperava que um identificador # ifndef esperava um identificador

A diretiva de compilação condicional ([#ifdef](../../preprocessor/hash-ifdef-and-hash-ifndef-directives-c-cpp.md) ou `#ifndef`) não tem identificador para avaliar. Para resolver o erro, especifique um identificador.

O exemplo a seguir gera C1016:

```cpp
// C1016.cpp
#ifdef   // C1016
#define FC1016
#endif

int main() {}
```

Resolução possível:

```cpp
// C1016b.cpp
#ifdef X
#define FC1016
#endif

int main() {}
```
