---
title: Compilador aviso (nível 1) C4391 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4391
dev_langs:
- C++
helpviewer_keywords:
- C4391
ms.assetid: 95c6182c-fae9-4174-8f7b-98aa352e68ca
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d0b3873beb635afe81cee3030a78d2b1223197a7
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46047077"
---
# <a name="compiler-warning-level-1-c4391"></a>Compilador aviso (nível 1) C4391

'assinatura': tipo de retorno incorreto para função intrínseca, esperado 'type'

Uma declaração de função para um intrínseco de compilador tinha o tipo de retorno incorreto. A imagem resultante pode não funcionar corretamente.

Para corrigir este aviso, corrija a declaração ou excluir a declaração e simplesmente #include do arquivo de cabeçalho apropriado.

O exemplo a seguir gera C4391:

```
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