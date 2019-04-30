---
title: Erro do compilador C3201
ms.date: 11/04/2016
f1_keywords:
- C3201
helpviewer_keywords:
- C3201
ms.assetid: ec19cd64-1789-40a3-b2db-dff2852b9d98
ms.openlocfilehash: 92e068103563f7427de7b394536e72b06fab3374
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62402756"
---
# <a name="compiler-error-c3201"></a>Erro do compilador C3201

a lista de parâmetros de modelo para o modelo de classe 'template' não coincide com a lista de parâmetros de modelo para o parâmetro de modelo 'template'

Você passou um modelo de classe no argumento para um modelo de classe que não utilize um parâmetro de modelo, ou você passou um número incompatível de argumentos de modelo para o argumento de modelo padrão.

```
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