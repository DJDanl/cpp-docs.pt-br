---
title: Erro do compilador C2516
ms.date: 11/04/2016
f1_keywords:
- C2516
helpviewer_keywords:
- C2516
ms.assetid: cd3accc1-0179-4a13-9587-616908c4ad1d
ms.openlocfilehash: 678c90c5f4d41b0a05bbb07f2aada82e9bfcdb1e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87214653"
---
# <a name="compiler-error-c2516"></a>Erro do compilador C2516

' name ': não é uma classe base válida

A classe é derivada de um nome de tipo definido por uma **`typedef`** instrução.

O exemplo a seguir gera C2516:

```cpp
// C2516.cpp
typedef unsigned long ulong;
class C : public ulong {}; // C2516
```
