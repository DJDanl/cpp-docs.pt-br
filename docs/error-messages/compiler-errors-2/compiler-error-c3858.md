---
title: Erro do compilador C3858
ms.date: 11/04/2016
f1_keywords:
- C3858
helpviewer_keywords:
- C3858
ms.assetid: 46e178d5-a55f-4ac6-a9dc-561fbcba5c1f
ms.openlocfilehash: b4246ba76b453e8cc841062a4184dc2cb02df479
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62265445"
---
# <a name="compiler-error-c3858"></a>Erro do compilador C3858

'type': não pode ser redeclarado no escopo atual

O tipo não pode ser declarado duas vezes no mesmo escopo.

O exemplo a seguir gera C3858:

```
// C3858.cpp
// compile with: /LD
template <class T>
struct Outer
{
   struct Inner;
};

template <class T>
struct Outer<T>::Inner;   // C3858
// try the following line instead
// struct Outer<T>::Inner{};
```