---
title: Aviso do compilador (nível 4) C4937
ms.date: 11/04/2016
f1_keywords:
- C4937
helpviewer_keywords:
- C4937
ms.assetid: 2bb9f0e7-bbd6-4697-84de-95955e32ae29
ms.openlocfilehash: dd7a7f9ac3d0ce0798a88f753cb0ccb4addbd5bc
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988748"
---
# <a name="compiler-warning-level-4-c4937"></a>Aviso do compilador (nível 4) C4937

' text1 ' e ' Texto2 ' são indistinguíveis como argumentos para ' diretiva '

Devido à maneira como o compilador processa argumentos para diretivas, os nomes que têm significado para o compilador, como palavras-chave com várias representações de texto (formulários de sublinhado simples e duplo), não podem ser diferenciados.

Exemplos dessas cadeias de caracteres são __cdecl e \__forceinline.  Observe que em/Za, somente os formulários de sublinhado duplo são habilitados.

O exemplo a seguir gera C4937:

```cpp
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
