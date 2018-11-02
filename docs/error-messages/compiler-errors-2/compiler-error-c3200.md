---
title: Erro do compilador C3200
ms.date: 11/04/2016
f1_keywords:
- C3200
helpviewer_keywords:
- C3200
ms.assetid: 44bb5e77-f0ec-421c-a732-b9ee7c0a3529
ms.openlocfilehash: 7eb0c00f4f4c5c59766bf305acfef89e12a6cfb1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50505060"
---
# <a name="compiler-error-c3200"></a>Erro do compilador C3200

'template': argumento de template inválido para parâmetro de modelo 'parameter', esperado um modelo de classe

Você passou um argumento inválido para um modelo de classe. O modelo de classe espera que o modelo como um parâmetro. No exemplo a seguir, chamar `Y<int, int> aY` gerará C3200. O primeiro parâmetro precisa ser um modelo, como `Y<X, int> aY`.

```
// C3200.cpp
template<typename T>
class X
{
};

template<template<typename U> class T1, typename T2>
class Y
{
};

int main()
{
   Y<int, int> y;   // C3200
}
```