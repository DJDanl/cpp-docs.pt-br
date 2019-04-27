---
title: Erro do compilador C2870
ms.date: 11/04/2016
f1_keywords:
- C2870
helpviewer_keywords:
- C2870
ms.assetid: 80523ee9-1fd3-4dc4-8a77-5083deb99066
ms.openlocfilehash: f61281da23e46236e7fce496a4d89086e5d6c0ea
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62165029"
---
# <a name="compiler-error-c2870"></a>Erro do compilador C2870

'name': uma definição de namespace deve aparecer no escopo do arquivo ou imediatamente dentro de outra definição de namespace

Você definiu o namespace `name` incorretamente. Namespaces deve ser definidos no escopo de arquivo (fora de todos os blocos e classes) ou imediatamente dentro de outro namespace.

O exemplo a seguir gera C2870:

```
// C2870.cpp
// compile with: /c
int main() {
   namespace A { int i; };   // C2870
}
```