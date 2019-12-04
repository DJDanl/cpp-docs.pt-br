---
title: Erro do compilador C3113
ms.date: 11/04/2016
f1_keywords:
- C3113
helpviewer_keywords:
- C3113
ms.assetid: 3afdc668-b29e-474e-9ea3-aa027d42db7c
ms.openlocfilehash: 067e8b14a0123691ee6368dccaa3ca3f5c763413
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760781"
---
# <a name="compiler-error-c3113"></a>Erro do compilador C3113

uma ' estrutura ' não pode ser um modelo/genérico

Você tentou tornar um modelo de classe ou classe genérica fora de uma interface ou uma enumeração.

O exemplo a seguir gera C3113:

```cpp
// C3113.cpp
// compile with: /c
template <class T>
enum E {};   // C3113
// try the following line instead
// class MyClass{};
```
