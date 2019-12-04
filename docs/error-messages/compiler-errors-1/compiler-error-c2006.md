---
title: Erro do compilador C2006
ms.date: 11/04/2016
f1_keywords:
- C2006
helpviewer_keywords:
- C2006
ms.assetid: caaed6f7-ceb9-4742-8820-d66657c0b04d
ms.openlocfilehash: 64f81929916cd3a4adf38a302ea34d46d9a5c070
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74756546"
---
# <a name="compiler-error-c2006"></a>Erro do compilador C2006

' diretivo ' esperava um nome de arquivo, encontrou ' token '

Diretivas como [#include](../../preprocessor/hash-include-directive-c-cpp.md) ou [#import](../../preprocessor/hash-import-directive-cpp.md) exigem um nome de arquivo. Para resolver o erro, verifique se o *token* é um nome de arquivo válido. Além disso, coloque o nome de arquivo entre aspas duplas ou colchetes angulares.

O exemplo a seguir gera C2006:

```cpp
// C2006.cpp
#include stdio.h   // C2006
```

Resolução possível:

```cpp
// C2006b.cpp
// compile with: /c
#include <stdio.h>
```
