---
title: Erro do compilador C2007
ms.date: 11/04/2016
f1_keywords:
- C2007
helpviewer_keywords:
- C2007
ms.assetid: ecd09d99-5036-408b-9e46-bc15488f049e
ms.openlocfilehash: f3c7b1a18dda9b2f9af7e346c2a1ed2f0303bb61
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50434678"
---
# <a name="compiler-error-c2007"></a>Erro do compilador C2007

\#definir a sintaxe

Nenhum identificador aparece após um `#define`. Para resolver o erro, use um identificador.

O exemplo a seguir gera C2007:

```
// C2007.cpp
#define   // C2007
```

Solução possível:

```
// C2007b.cpp
// compile with: /c
#define true 1
```