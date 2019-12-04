---
title: Erro do compilador C3201
ms.date: 11/04/2016
f1_keywords:
- C3201
helpviewer_keywords:
- C3201
ms.assetid: ec19cd64-1789-40a3-b2db-dff2852b9d98
ms.openlocfilehash: 4da6616c59ea4b8a720c8e2dc9742e37a9939171
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74738759"
---
# <a name="compiler-error-c3201"></a>Erro do compilador C3201

a lista de parâmetros de modelo para o modelo de classe ' template ' não corresponde à lista de parâmetros de modelo para o parâmetro de modelo ' template '

Você passou um modelo de classe no argumento para um modelo de classe que não usa um parâmetro de modelo, ou que você passou um número incompatível de argumentos de modelo para o argumento de modelo padrão.

```cpp
// C3201.cpp
template<typename T1, typename T2>
class X1
{
};

template<template<typename T> class U = X1>   // C3201
class X2
{
};

template<template<typename T, typename V> class U = X1>   // OK
class X3
{
};
```
