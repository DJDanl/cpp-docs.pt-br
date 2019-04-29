---
title: Erro do compilador C2766
ms.date: 11/04/2016
f1_keywords:
- C2766
helpviewer_keywords:
- C2766
ms.assetid: 8032f4ca-6827-4f04-9c61-c44643c85cc4
ms.openlocfilehash: 87ea9f693265080d744746c6a8014b2b8b6db13a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62257550"
---
# <a name="compiler-error-c2766"></a>Erro do compilador C2766

especialização explícita; 'especialização' já foi definida

Especializações explícitas duplicadas não são permitidas. Para obter mais informações, consulte [especialização explícita de modelos de função](../../cpp/explicit-specialization-of-function-templates.md).

O exemplo a seguir gera C2766:

```
// C2766.cpp
// compile with: /c
template<class T>
struct A {};

template<>
struct A<int> {};

template<>
struct A<int> {};   // C2766
// try the following line instead
// struct A<char> {};
```