---
title: Erro do compilador C3412
ms.date: 11/04/2016
f1_keywords:
- C3412
helpviewer_keywords:
- C3412
ms.assetid: aa4dd43b-54ce-4cda-85c1-1a77dd6e34fa
ms.openlocfilehash: 7c16ffa37f4d7192956afae26c825b63add1bfdd
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62173451"
---
# <a name="compiler-error-c3412"></a>Erro do compilador C3412

'template': não é possível especializar template no escopo atual

Um modelo não pode ser especializado no escopo de classe, no modelo global ou escopo de namespace.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3412.

```
// C3412.cpp
template <class T>
struct S {
   template <>
   struct S<int> {};   // C3412 in a class
};
```

## <a name="example"></a>Exemplo

O exemplo a seguir mostra uma possível resolução.

```
// C3412b.cpp
// compile with: /c
template <class T>
struct S {};

template <>
struct S<int> {};
```