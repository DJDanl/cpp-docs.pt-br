---
title: Aviso do compilador (nível 1) C4391
ms.date: 11/04/2016
f1_keywords:
- C4391
helpviewer_keywords:
- C4391
ms.assetid: 95c6182c-fae9-4174-8f7b-98aa352e68ca
ms.openlocfilehash: 6dc5e2c7a40a276e225d030bc0340fb0bfe25bb5
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80162719"
---
# <a name="compiler-warning-level-1-c4391"></a>Aviso do compilador (nível 1) C4391

' Signature ': tipo de retorno incorreto para função intrínseca, esperado ' type '

Uma declaração de função para um compilador intrínseco tinha o tipo de retorno incorreto. A imagem resultante pode não ser executada corretamente.

Para corrigir esse aviso, corrija a declaração ou exclua a declaração e simplesmente #include o arquivo de cabeçalho apropriado.

O exemplo a seguir gera C4391:

```cpp
// C4391.cpp
// compile with: /W1
// processor: x86
// uncomment the following line and delete the line that
// generated the warning to resolve
// #include "xmmintrin.h"

#ifdef  __cplusplus
extern "C" {
#endif

extern void _mm_load_ss(float *p);   // C4391

#ifdef  __cplusplus
}
#endif

int main()
{
}
```
