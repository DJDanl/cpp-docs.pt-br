---
title: Compilador aviso (nível 1) C4103 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4103
dev_langs:
- C++
helpviewer_keywords:
- C4103
ms.assetid: 9021b514-375e-4d62-b261-ccb06f299e8e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1942acc2d9c5c274806e06127f9f98d4bfcb5077
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46085531"
---
# <a name="compiler-warning-level-1-c4103"></a>Compilador aviso (nível 1) C4103

'filename': alinhamento mudou após inclusão de cabeçalho, pode ser devido à ausência de Pack (POP) #pragma

O layout das classes afeta o empacotamento e comumente, se as alterações em arquivos de cabeçalho de remessa, pode haver problemas.

Use #pragma [pack](../../preprocessor/pack.md)(pop) antes de sair do arquivo de cabeçalho para resolver este aviso.

O exemplo a seguir gera C4103:

```
// C4103.h
#pragma pack(push, 4)

// defintions and declarations

// uncomment the following line to resolve
// #pragma pack(pop)
```

E, em seguida,

```
// C4103.cpp
// compile with: /LD /W1
#include "c4103.h"   // C4103
```