---
title: Aviso do compilador (nível 1) C4103
ms.date: 11/04/2016
f1_keywords:
- C4103
helpviewer_keywords:
- C4103
ms.assetid: 9021b514-375e-4d62-b261-ccb06f299e8e
ms.openlocfilehash: dfc3a91b2dcb3ed1e8f4f4993edd67219a6bf1d8
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80163839"
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

e, em seguida,

```cpp
// C4103.cpp
// compile with: /LD /W1
#include "c4103.h"   // C4103
```
