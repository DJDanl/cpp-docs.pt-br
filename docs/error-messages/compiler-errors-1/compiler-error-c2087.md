---
title: Erro do compilador C2087
ms.date: 11/04/2016
f1_keywords:
- C2087
helpviewer_keywords:
- C2087
ms.assetid: 89761e83-415a-4468-a4c6-b6dedfd1dd6a
ms.openlocfilehash: 576ac394585b91f7c6ceadcdd07d25c639854990
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74757898"
---
# <a name="compiler-error-c2087"></a>Erro do compilador C2087

' identifier ': subscrito ausente

A definição de uma matriz com vários subscritos não tem um valor de subscrito para uma dimensão maior que um.

O exemplo a seguir gera C2087:

```cpp
// C2087.cpp
int main() {
   char a[10][];   // C2087
}
```

Resolução possível:

```cpp
// C2087b.cpp
int main() {
   char b[4][5];
}
```
