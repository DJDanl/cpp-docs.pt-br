---
title: Erro do compilador C2182
ms.date: 11/04/2016
f1_keywords:
- C2182
helpviewer_keywords:
- C2182
ms.assetid: dfd8d47d-9606-496e-bd96-4bf41ba1f857
ms.openlocfilehash: 3c33e722143c15c566d96226429adbb8868b34ca
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50598426"
---
# <a name="compiler-error-c2182"></a>Erro do compilador C2182

'identifier': uso ilegal do tipo 'void'

Uma variável é declarada tipo `void`.

O exemplo a seguir gera C2182:

```
// C2182.cpp
// compile with: /c
int main() {
   int i = 10;
   void &ir = i;   // C2182 cannot have a reference to type void
   int &ir = i;   // OK
}
```