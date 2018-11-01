---
title: Erro do compilador C2279
ms.date: 11/04/2016
f1_keywords:
- C2279
helpviewer_keywords:
- C2279
ms.assetid: 1b5c88ef-2336-49b8-9ddb-d61f97c73e14
ms.openlocfilehash: f35e384a5b242eb28427e1ff62ac55a3e9b206c4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50666213"
---
# <a name="compiler-error-c2279"></a>Erro do compilador C2279

especificação de exceção não pode aparecer em uma declaração de typedef

Sob **/Za**, [especificações de exceção](../../cpp/exception-specifications-throw-cpp.md) não são permitidos em uma declaração de typedef.

O exemplo a seguir gera C2279:

```
// C2279.cpp
// compile with: /Za /c
typedef int (*xy)() throw(...);   // C2279
typedef int (*xyz)();   // OK
```