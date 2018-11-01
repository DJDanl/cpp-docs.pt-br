---
title: Compilador aviso (nível 1) C4392
ms.date: 11/04/2016
f1_keywords:
- C4392
helpviewer_keywords:
- C4392
ms.assetid: 817806ad-06a6-4b9e-8355-e25687c782dc
ms.openlocfilehash: 1dc0c546509b17132358f432f6a781035a314a72
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50472192"
---
# <a name="compiler-warning-level-1-c4392"></a>Compilador aviso (nível 1) C4392

'assinatura': número incorreto de argumentos para função intrínseca, esperado 'números' argumentos

Uma declaração de função para um intrínseco de compilador tinha um número incorreto de argumentos. A imagem resultante pode não funcionar corretamente.

Para corrigir este aviso, corrija a declaração ou excluir a declaração e simplesmente #include do arquivo de cabeçalho apropriado.

O exemplo a seguir gera C4392:

```
// C4392.cpp
// compile with: /W1
// processor: x86
// uncomment the following line and delete the line that
// generated the warning to resolve
// #include "xmmintrin.h"

#ifdef  __cplusplus
extern "C" {
#endif

extern void _mm_stream_pd(double *dp);   // C4392

#ifdef  __cplusplus
}
#endif

int main()
{
}
```