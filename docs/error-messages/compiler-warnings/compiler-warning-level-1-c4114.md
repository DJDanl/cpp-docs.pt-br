---
title: Compilador aviso (nível 1) C4114 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4114
dev_langs:
- C++
helpviewer_keywords:
- C4114
ms.assetid: 3983e1c6-e8bb-46dc-8894-e1827db48797
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a8d67148c2b9fb22c90013905eb246bf8d3bdf75
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46067555"
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
