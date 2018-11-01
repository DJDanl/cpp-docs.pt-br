---
title: Erro do compilador C2311
ms.date: 11/04/2016
f1_keywords:
- C2311
helpviewer_keywords:
- C2311
ms.assetid: 1aff9bd5-ed0b-4db6-bbc0-01ac89850cf2
ms.openlocfilehash: f4eff6f88a247dd17a2c9399b9009717f8fb8e62
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50444065"
---
# <a name="compiler-error-c2311"></a>Erro do compilador C2311

'exceções': é capturado por '...' no número de linha

O manipulador catch para o botão de reticências (...) deve ser o último manipulador para um throw.

O exemplo a seguir gera C2311:

```
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