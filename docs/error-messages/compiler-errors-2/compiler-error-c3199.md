---
title: Erro do compilador C3199
ms.date: 11/04/2016
f1_keywords:
- C3199
helpviewer_keywords:
- C3199
ms.assetid: e7a478d3-115a-40a3-991b-c7454fd2e28e
ms.openlocfilehash: 2f0ca98dc44a78adde378a0f80078ae30c590e11
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74738811"
---
# <a name="compiler-error-c3199"></a>Erro do compilador C3199

uso inválido de pragmas de ponto flutuante: exceções não são suportadas em modo não preciso

O [float_control](../../preprocessor/float-control.md) pragma foi usado para especificar o modelo de exceção de ponto flutuante em uma configuração do [/FP](../../build/reference/fp-specify-floating-point-behavior.md) diferente de **/fp: preciso**.

O exemplo a seguir gera C3199:

```cpp
// C3199.cpp
// compile with: /fp:fast
#pragma float_control(except, on)   // C3199
```
