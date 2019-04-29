---
title: Erro do compilador C2013
ms.date: 11/04/2016
f1_keywords:
- C2013
helpviewer_keywords:
- C2013
ms.assetid: 6b5c955c-53da-48ee-8533-64ef5b905173
ms.openlocfilehash: b279202b8b32197a99d230040207aa50bc100495
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62351125"
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