---
title: Compilador aviso (nível 1) C4606
ms.date: 11/04/2016
f1_keywords:
- C4606
helpviewer_keywords:
- C4606
ms.assetid: c1b45fb6-672b-42eb-9e1c-c67b3e4150d3
ms.openlocfilehash: e471ca3e478d1166b150e49bf25efa4b9d5803cb
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50569267"
---
# <a name="compiler-warning-level-1-c4606"></a>Compilador aviso (nível 1) C4606

\#Aviso de Pragma: 'warning_number' ignorado; Avisos da análise de código não estão associados com níveis de aviso

Avisos de análise de código, apenas `error`, `once`, e `default` são compatíveis com o [aviso](../../preprocessor/warning.md) pragma.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4606.

```
// C4606.cpp
// compile with: /c /W1
#pragma warning(1: 6001)   // C4606
#pragma warning(once: 6001)   // OK
```