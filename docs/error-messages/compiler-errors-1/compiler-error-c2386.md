---
title: Erro do compilador C2386
ms.date: 11/04/2016
f1_keywords:
- C2386
helpviewer_keywords:
- C2386
ms.assetid: aaaa1284-34a0-4da2-8547-9fcbb559dae0
ms.openlocfilehash: 1ac58d63498df32488c1a0743aa6ad9f7b77b7ca
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74745090"
---
# <a name="compiler-error-c2386"></a>Erro do compilador C2386

' Symbol ': já existe um símbolo com este nome no escopo atual

Você tentou criar um alias de namespace, mas o nome escolhido já existe.

O exemplo a seguir gera C2386:

```cpp
// C2386.cpp
namespace A {
   int k;
}

int i;
namespace i = A;   // C2386, i already exists
```
