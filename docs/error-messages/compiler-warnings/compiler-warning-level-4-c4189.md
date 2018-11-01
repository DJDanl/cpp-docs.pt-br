---
title: Compilador aviso (nível 4) C4189
ms.date: 11/04/2016
f1_keywords:
- C4189
helpviewer_keywords:
- C4189
ms.assetid: 7ad9242c-228e-4054-8244-5e914b618ef3
ms.openlocfilehash: 6463379529897598d560d6bcc22bd3a278a66477
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50447235"
---
# <a name="compiler-warning-level-4-c4189"></a>Compilador aviso (nível 4) C4189

'identifier': variável local é inicializado, mas não referenciado

Uma variável é declarada e inicializada mas não usada.

O exemplo a seguir gera C4189:

```
// C4189.cpp
// compile with: /W4
int main() {
   int a = 1;   // C4189, remove declaration to resolve
}
```