---
title: Compilador aviso (níveis 1 e 4) C4112
ms.date: 11/04/2016
f1_keywords:
- C4112
helpviewer_keywords:
- C4112
ms.assetid: aff64897-bb79-4a67-9b6f-902c6d44f3dc
ms.openlocfilehash: 3678d0ce5d9eb9568f0272da4173e72502b0557f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62280328"
---
# <a name="compiler-warning-levels-1-and-4-c4112"></a>Compilador aviso (níveis 1 e 4) C4112

\#linha requer um número inteiro entre 1 e número

O [#line](../../preprocessor/hash-line-directive-c-cpp.md) diretiva especifica um parâmetro de inteiro que está fora do intervalo permitido.

Se o parâmetro especificado é menor que 1, o contador de linha é redefinido como 1. Se o parâmetro especificado é maior que *número*, que é o limite definido pelo compilador, o contador de linha é alterado. Este é um aviso de nível 1 em compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)) e um aviso de nível 4 com extensões da Microsoft ([/Ze](../../build/reference/za-ze-disable-language-extensions.md)).

O exemplo a seguir gera C4112:

```
// C4112.cpp
// compile with: /W4
#line 0   // C4112, value must be between 1 and number

int main() {
}
```