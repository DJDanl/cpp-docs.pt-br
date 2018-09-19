---
title: Compilador aviso (nível 4) C4937 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4937
dev_langs:
- C++
helpviewer_keywords:
- C4937
ms.assetid: 2bb9f0e7-bbd6-4697-84de-95955e32ae29
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e7bc6232458b357f41e859c58d4b6b77f78ef2a7
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46118284"
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