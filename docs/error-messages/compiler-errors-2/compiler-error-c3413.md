---
title: Erro do compilador C3413
ms.date: 11/04/2016
f1_keywords:
- C3413
helpviewer_keywords:
- C3413
ms.assetid: de6c9b05-c373-4bd8-8cb0-12c2cd2e5674
ms.openlocfilehash: 3065478cfff51f2463d4efba7f5a7dafc482fa65
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74743010"
---
# <a name="compiler-error-c3413"></a>Erro do compilador C3413

' name ': instanciação explícita inválida

O compilador detectou uma instanciação explícita malformada.

O exemplo a seguir gera C3413:

```cpp
// C3413.cpp
template
class MyClass {};   // C3413
```

Resolução possível:

```cpp
// C3413b.cpp
// compile with: /c
template <class T>
class MyClass {};

template <>
class MyClass<int> {};
```
