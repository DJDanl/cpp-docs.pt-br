---
title: Compilador aviso (nível 4) C4937
ms.date: 11/04/2016
f1_keywords:
- C4937
helpviewer_keywords:
- C4937
ms.assetid: 2bb9f0e7-bbd6-4697-84de-95955e32ae29
ms.openlocfilehash: 64565ad37c965aa0af3b912988586b37270be6a4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50548743"
---
# <a name="compiler-warning-level-4-c4937"></a>Compilador aviso (nível 4) C4937

'text1' e 'text2' são indistinguíveis como argumentos para 'diretiva'

Devido à maneira, o compilador processa argumentos para diretivas de nomes que têm significado para o compilador, como palavras-chave com várias representações de texto (formulários de sublinhado único e duplo), não podem ser diferenciadas.

Exemplos de tais cadeias de caracteres são cdecl e \__forceinline.  Observe que em /Za, somente os formulários de sublinhado duplo estão habilitados.

O exemplo a seguir gera C4937:

```
// C4937.cpp
// compile with: /openmp /W4
#include "omp.h"
int main() {
   #pragma omp critical ( __leave )   // C4937
   ;

   // OK
   #pragma omp critical ( leave )
   ;
}
```