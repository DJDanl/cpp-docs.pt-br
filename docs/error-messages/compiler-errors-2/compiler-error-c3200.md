---
title: Erro do compilador C3200 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3200
dev_langs:
- C++
helpviewer_keywords:
- C3200
ms.assetid: 44bb5e77-f0ec-421c-a732-b9ee7c0a3529
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 77be23b92d5237d2fa65557bdf36de31cd27d9d3
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46062627"
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