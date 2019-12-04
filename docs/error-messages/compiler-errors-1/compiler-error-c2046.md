---
title: Erro do compilador C2046
ms.date: 11/04/2016
f1_keywords:
- C2046
helpviewer_keywords:
- C2046
ms.assetid: f0c8f9dd-dbd7-4c4a-8838-fde54208ec71
ms.openlocfilehash: e83860e9f69bab864ad2cf02503d9af802e86d29
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74740358"
---
# <a name="compiler-error-c2046"></a>Erro do compilador C2046

caso ilegal

A palavra-chave `case` pode aparecer apenas em uma instrução `switch`.

O exemplo a seguir gera C2046:

```cpp
// C2046.cpp
int main() {
   case 0:   // C2046
}
```

Resolução possível:

```cpp
// C2046b.cpp
int main() {
   int i = 0;

   switch(i) {
      case 0:
      break;

      default:
      break;
   }
}
```
