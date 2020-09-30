---
title: Erro do compilador C2504
ms.date: 11/04/2016
f1_keywords:
- C2504
helpviewer_keywords:
- C2504
ms.assetid: c9e002a6-a4ee-4ba7-970e-edf4adb83692
ms.openlocfilehash: 0860f4b860b370f96c2c29046b090d5b205c63ba
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91509387"
---
# <a name="compiler-error-c2504"></a>Erro do compilador C2504

' class ': classe base indefinida

A classe base é declarada, mas nunca definida.  Possíveis causas:

1. Arquivo de inclusão ausente.

1. Classe base externa não declarada com [extern](../../cpp/extern-cpp.md).

O exemplo a seguir gera C2504:

```cpp
// C2504.cpp
// compile with: /c
class A;
class B : public A {};   // C2504
```

Okey

```
class C{};
class D : public C {};
```
