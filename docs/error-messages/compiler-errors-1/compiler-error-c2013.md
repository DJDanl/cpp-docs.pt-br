---
title: Erro do compilador C2013
ms.date: 11/04/2016
f1_keywords:
- C2013
helpviewer_keywords:
- C2013
ms.assetid: 6b5c955c-53da-48ee-8533-64ef5b905173
ms.openlocfilehash: b279202b8b32197a99d230040207aa50bc100495
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50618472"
---
# <a name="compiler-error-c2013"></a>Erro do compilador C2013

faltando ' >'

Um `#include` diretiva não tem um colchete angular de fechamento. Adicione o colchete de fechamento para resolver o erro.

O exemplo a seguir gera C2013:

```
// C2013.cpp
#include <stdio.h    // C2013
```

Solução possível:

```
// C2013b.cpp
// compile with: /c
#include <stdio.h>
```