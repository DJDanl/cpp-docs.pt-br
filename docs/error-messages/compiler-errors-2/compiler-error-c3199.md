---
title: Erro do compilador C3199
ms.date: 11/04/2016
f1_keywords:
- C3199
helpviewer_keywords:
- C3199
ms.assetid: e7a478d3-115a-40a3-991b-c7454fd2e28e
ms.openlocfilehash: 934e980149ad893e6799b0ab119a148fc5652fdc
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62402782"
---
# <a name="compiler-error-c3199"></a>Erro do compilador C3199

Uso inválido de pragmas de ponto flutuante: exceções não têm suporte no modo não preciso

O [float_control](../../preprocessor/float-control.md) pragma foi usada para especificar o modelo de exceção de ponto flutuante em uma [/fp](../../build/reference/fp-specify-floating-point-behavior.md) configuração diferente de **/fp: preciso**.

O exemplo a seguir gera C3199:

```
// C3199.cpp
// compile with: /fp:fast
#pragma float_control(except, on)   // C3199
```