---
title: Erro do compilador C2766
ms.date: 11/04/2016
f1_keywords:
- C2766
helpviewer_keywords:
- C2766
ms.assetid: 8032f4ca-6827-4f04-9c61-c44643c85cc4
ms.openlocfilehash: 48faee02bba18754972954a2ca464417bd552758
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74759796"
---
# <a name="compiler-error-c2766"></a>Erro do compilador C2766

especialização explícita; ' especialização ' já foi definido

Não são permitidas especializações explícitas duplicadas. Para obter mais informações, consulte [especialização explícita dos modelos de função](../../cpp/explicit-specialization-of-function-templates.md).

O exemplo a seguir gera C2766:

```cpp
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
