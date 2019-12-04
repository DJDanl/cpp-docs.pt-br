---
title: Erro do compilador C2870
ms.date: 11/04/2016
f1_keywords:
- C2870
helpviewer_keywords:
- C2870
ms.assetid: 80523ee9-1fd3-4dc4-8a77-5083deb99066
ms.openlocfilehash: 3b006592723df1222d05e39b3bc9e5729efc8aa6
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74755025"
---
# <a name="compiler-error-c2870"></a>Erro do compilador C2870

' name ': uma definição de namespace deve aparecer no escopo do arquivo ou imediatamente dentro de outra definição de namespace

Você definiu o namespace `name` incorretamente. Os namespaces devem ser definidos no escopo do arquivo (fora de todos os blocos e classes) ou imediatamente dentro de outro namespace.

O exemplo a seguir gera C2870:

```cpp
// C2870.cpp
// compile with: /c
int main() {
   namespace A { int i; };   // C2870
}
```
