---
title: Erro do compilador C2053
ms.date: 11/04/2016
f1_keywords:
- C2053
helpviewer_keywords:
- C2053
ms.assetid: 13324c85-13a8-4996-bd42-a31bfe7ff80f
ms.openlocfilehash: be5517ce77872fe395a52c5b1e0070612e205a3d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50571217"
---
# <a name="compiler-error-c2053"></a>Erro do compilador C2053

'identifier': incompatibilidade de cadeia de caracteres largos

A cadeia de caracteres larga é atribuída a um tipo incompatível.

O exemplo a seguir gera C2053:

```
// C2053.c
int main() {
   char array[] = L"Rika";   // C2053
}
```