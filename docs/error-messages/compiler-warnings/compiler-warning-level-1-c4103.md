---
title: Compilador aviso (nível 1) C4103
ms.date: 11/04/2016
f1_keywords:
- C4103
helpviewer_keywords:
- C4103
ms.assetid: 9021b514-375e-4d62-b261-ccb06f299e8e
ms.openlocfilehash: 15d7403d461467e33b7e89957821a311179d33a7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62300278"
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