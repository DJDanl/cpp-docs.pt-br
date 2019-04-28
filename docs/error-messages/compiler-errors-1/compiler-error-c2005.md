---
title: Erro do compilador C2005
ms.date: 11/04/2016
f1_keywords:
- C2005
helpviewer_keywords:
- C2005
ms.assetid: 090530ed-e0ec-4358-833a-ca24260e7ffe
ms.openlocfilehash: 49d0375d5733410d728797d2a881075377b33ba6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62208991"
---
# <a name="compiler-error-c2005"></a>Erro do compilador C2005

\#linha esperado um número de linha, encontrado 'token'

O `#line` diretiva deve ser seguida por um número de linha.

O exemplo a seguir gera C2005:

```
// C2005.cpp
int main() {
   int i = 0;
   #line i   // C2005
}
```

Solução possível:

```
// C2005b.cpp
int main() {
   int i = 0;
   #line 0
}
```