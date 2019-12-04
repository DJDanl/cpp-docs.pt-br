---
title: Erro do compilador C2311
ms.date: 11/04/2016
f1_keywords:
- C2311
helpviewer_keywords:
- C2311
ms.assetid: 1aff9bd5-ed0b-4db6-bbc0-01ac89850cf2
ms.openlocfilehash: e72ff7325e293697b0117e527b0d9edd55840481
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74748171"
---
# <a name="compiler-error-c2311"></a>Erro do compilador C2311

' Exception ': é capturado por '... ' em número de linha

O manipulador catch para as reticências (...) deve ser o último manipulador para um throw.

O exemplo a seguir gera C2311:

```cpp
// C2311.cpp
// compile with: /EHsc
#include <eh.h>
int main() {
   try {
      throw "ooops!";
   }
   catch( ... ) {}
   catch( int ) {}   // C2311  ellipsis handler not last catch
}
```
