---
title: Erro do compilador C3413
ms.date: 11/04/2016
f1_keywords:
- C3413
helpviewer_keywords:
- C3413
ms.assetid: de6c9b05-c373-4bd8-8cb0-12c2cd2e5674
ms.openlocfilehash: e344d06345c0f3a79b86e9cab4e1c5dacb47e9c2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62173407"
---
# <a name="compiler-error-c3413"></a>Erro do compilador C3413

'name': instanciação explícita inválida

O compilador detectou uma instanciação explícita mal formado.

O exemplo a seguir gera C3413:

```
// C3413.cpp
template
class MyClass {};   // C3413
```

Solução possível:

```
// C3413b.cpp
// compile with: /c
template <class T>
class MyClass {};

template <>
class MyClass<int> {};
```