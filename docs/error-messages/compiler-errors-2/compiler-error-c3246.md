---
title: Erro do compilador C3246
ms.date: 11/04/2016
f1_keywords:
- C3246
helpviewer_keywords:
- C3246
ms.assetid: ad85224a-e540-479b-a5eb-a3bc3964c30b
ms.openlocfilehash: e9396b3bc5eea5d15366fc94ffa308d78754c31e
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74754388"
---
# <a name="compiler-error-c3246"></a>Erro do compilador C3246

' class ': não pode herdar de ' type ' porque ele foi declarado como ' sealed '

Uma classe marcada como [sealed](../../extensions/sealed-cpp-component-extensions.md) não pode ser a classe base para outras classes.

O exemplo a seguir gera C3246:

```cpp
// C3246_2.cpp
// compile with: /clr /LD
ref class X sealed {};

ref class Y : public X {}; // C3246
```
