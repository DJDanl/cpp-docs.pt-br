---
title: Aviso do compilador (nível 1) C4103
ms.date: 11/04/2016
f1_keywords:
- C4103
helpviewer_keywords:
- C4103
ms.assetid: 9021b514-375e-4d62-b261-ccb06f299e8e
ms.openlocfilehash: 456e7d393eb751e99c1969619ccfdcc649193c75
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73627059"
---
# <a name="compiler-warning-level-1-c4103"></a>Aviso do compilador (nível 1) C4103

' FileName ': alinhamento alterado após incluir header, pode ser devido a um pacote de #pragma ausente (pop)

A compactação afeta o layout das classes e, normalmente, se as alterações de empacotamento entre arquivos de cabeçalho, pode haver problemas.

Use o [pacote](../../preprocessor/pack.md)de #pragma (pop) antes de sair do arquivo de cabeçalho para resolver este aviso.

O exemplo a seguir gera C4103:

```cpp
// C4103.h
#pragma pack(push, 4)

// defintions and declarations

// uncomment the following line to resolve
// #pragma pack(pop)
```

E, em seguida,

```cpp
// C4103.cpp
// compile with: /LD /W1
#include "c4103.h"   // C4103
```