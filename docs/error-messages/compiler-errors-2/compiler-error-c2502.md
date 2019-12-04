---
title: Erro do compilador C2502
ms.date: 11/04/2016
f1_keywords:
- C2502
helpviewer_keywords:
- C2502
ms.assetid: affa0b86-15fc-4e17-b7f2-6aad4a3771c4
ms.openlocfilehash: 4ff3523ac803e7804ca56532631fe77b240c215d
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74746910"
---
# <a name="compiler-error-c2502"></a>Erro do compilador C2502

' identifier ': muitos modificadores de acesso na classe base

A classe base tem mais de um modificador de acesso. Somente um modificador de acesso (`public`, `private`ou `protected`) é permitido.

O exemplo a seguir gera C2502:

```cpp
// C2502.cpp
// compile with: /c
class A { };
class B { };
class C : private public A { };   // C2502

// OK
class D : private A {};
class E : public A, private B {};
```
