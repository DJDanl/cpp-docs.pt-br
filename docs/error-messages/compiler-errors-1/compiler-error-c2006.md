---
title: Erro do compilador C2006
ms.date: 11/04/2016
f1_keywords:
- C2006
helpviewer_keywords:
- C2006
ms.assetid: caaed6f7-ceb9-4742-8820-d66657c0b04d
ms.openlocfilehash: c23f17483925f25468214165fb459db577e576fc
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50475082"
---
# <a name="compiler-error-c2006"></a>Erro do compilador C2006

'diretiva' esperado um nome de arquivo, encontrado 'token'

Diretivas, como [#include](../../preprocessor/hash-include-directive-c-cpp.md) ou [#import](../../preprocessor/hash-import-directive-cpp.md) exigem um nome de arquivo. Para resolver o erro, certifique-se *token* é um nome de arquivo válido. Além disso, coloque o nome do arquivo em aspas duplas ou colchetes angulares.

O exemplo a seguir gera C2006:

```
// C2006.cpp
#include stdio.h   // C2006
```

Solução possível:

```
// C2006b.cpp
// compile with: /c
#include <stdio.h>
```