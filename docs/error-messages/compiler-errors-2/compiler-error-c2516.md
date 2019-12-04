---
title: Erro do compilador C2516
ms.date: 11/04/2016
f1_keywords:
- C2516
helpviewer_keywords:
- C2516
ms.assetid: cd3accc1-0179-4a13-9587-616908c4ad1d
ms.openlocfilehash: fb0636edd621de06bea553c9975626249ae06d80
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74746494"
---
# <a name="compiler-error-c2516"></a>Erro do compilador C2516

' name ': não é uma classe base válida

A classe é derivada de um nome de tipo definido por uma instrução `typedef`.

O exemplo a seguir gera C2516:

```cpp
// C2516.cpp
typedef unsigned long ulong;
class C : public ulong {}; // C2516
```
