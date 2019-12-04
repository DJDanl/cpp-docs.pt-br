---
title: Erro de compilador C3200
ms.date: 11/04/2016
f1_keywords:
- C3200
helpviewer_keywords:
- C3200
ms.assetid: 44bb5e77-f0ec-421c-a732-b9ee7c0a3529
ms.openlocfilehash: 7f6b514231bcda18404e891e0acbe457c8f95146
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74738772"
---
# <a name="compiler-error-c3200"></a>Erro de compilador C3200

' template ': argumento de template inválido para parâmetro de modelo ' Parameter ', esperado um template de classe

Você passou um argumento inválido para um modelo de classe. O modelo de classe espera o modelo como um parâmetro. No exemplo a seguir, chamar `Y<int, int> aY` irá gerar C3200. O primeiro parâmetro deve ser um modelo, como `Y<X, int> aY`.

```cpp
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
