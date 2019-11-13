---
title: Aviso do compilador (nível 1) C4391
ms.date: 11/04/2016
f1_keywords:
- C4391
helpviewer_keywords:
- C4391
ms.assetid: 95c6182c-fae9-4174-8f7b-98aa352e68ca
ms.openlocfilehash: 60b68906697f76d56ff6c0e13f1b4ec105ef1c25
ms.sourcegitcommit: e5192a25c084eda9eabfa37626f3274507e026b3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2019
ms.locfileid: "73966124"
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