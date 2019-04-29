---
title: Compilador aviso (nível 1) C4114
ms.date: 11/04/2016
f1_keywords:
- C4114
helpviewer_keywords:
- C4114
ms.assetid: 3983e1c6-e8bb-46dc-8894-e1827db48797
ms.openlocfilehash: 41e951e7c4a8b23ddbec14c5421f66702e70c937
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62300252"
---
# <a name="compiler-warning-level-1-c4114"></a>Compilador aviso (nível 1) C4114

mesmo qualificador de tipo usado mais de uma vez

Uma declaração de tipo ou definição usa um qualificador de tipo (**const**, **volátil**, **assinado**, ou **sem sinal**) mais de uma vez. Isso faz com que um aviso com extensões da Microsoft (/Ze) e um erro de compatibilidade com ANSI (/Za).

O exemplo a seguir gera C4114:

```
// C4114.cpp
// compile with: /W1 /c
volatile volatile int i;   // C4114
```

O exemplo a seguir gera C4114:

```
// C4114_b.cpp
// compile with: /W1 /c
static const int const * ii;   // C4114
static const int * const iii;   // OK
```
