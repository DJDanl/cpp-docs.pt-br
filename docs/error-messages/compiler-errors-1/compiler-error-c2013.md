---
title: Erro do compilador C2013
ms.date: 11/04/2016
f1_keywords:
- C2013
helpviewer_keywords:
- C2013
ms.assetid: 6b5c955c-53da-48ee-8533-64ef5b905173
ms.openlocfilehash: 3dd8c315351ccf38989fc113e7ee31b25e38a07f
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74757404"
---
# <a name="compiler-error-c2013"></a>Erro do compilador C2013

' > ' ausente

Uma diretiva de `#include` não tem um colchete angular de fechamento. Adicione o colchete de fechamento para resolver o erro.

O exemplo a seguir gera C2013:

```cpp
// C2013.cpp
#include <stdio.h    // C2013
```

Resolução possível:

```cpp
// C2013b.cpp
// compile with: /c
#include <stdio.h>
```
