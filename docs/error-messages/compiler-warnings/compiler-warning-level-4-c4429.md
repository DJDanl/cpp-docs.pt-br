---
title: Compilador aviso (nível 4) C4429
ms.date: 11/04/2016
f1_keywords:
- C4429
helpviewer_keywords:
- C4429
ms.assetid: a3e4cf1f-a869-4e47-834a-850c21eb5297
ms.openlocfilehash: d4eb7e7075c7adf418254e748f104a6d57c72741
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62391524"
---
# <a name="compiler-warning-level-4-c4429"></a>Compilador aviso (nível 4) C4429

possíveis incompleto ou formado incorretamente-nome de caractere universal

O compilador detectou uma sequência de caracteres que pode ser um nome de caractere universal mal formado. É um nome de caractere universal `\u` seguido por quatro dígitos hexadecimais, ou `\U` seguido por oito dígitos hexadecimais.

O exemplo a seguir gera C4429:

```
// C4429.cpp
// compile with: /W4 /WX
int \ug0e4 = 0;   // C4429
// Try the following line instead:
// int \u00e4 = 0;   // OK, a well-formed universal character name.
```