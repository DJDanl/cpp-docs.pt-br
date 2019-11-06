---
title: Aviso do compilador (nível 1) C4114
ms.date: 11/04/2016
f1_keywords:
- C4114
helpviewer_keywords:
- C4114
ms.assetid: 3983e1c6-e8bb-46dc-8894-e1827db48797
ms.openlocfilehash: 5662dba4339765db27d225eff2ad382ed56396ac
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73626289"
---
# <a name="compiler-warning-level-1-c4114"></a>Aviso do compilador (nível 1) C4114

mesmo qualificador de tipo usado mais de uma vez

Uma declaração ou definição de tipo usa um qualificador de tipo (**const**, **volátil**, **assinado**ou **não assinado**) mais de uma vez. Isso causa um aviso com as extensões da Microsoft (/Ze) e um erro em compatibilidade com ANSI (/Za).

O exemplo a seguir gera C4114:

```cpp
// C4114.cpp
// compile with: /W1 /c
volatile volatile int i;   // C4114
```

O exemplo a seguir gera C4114:

```cpp
// C4114_b.cpp
// compile with: /W1 /c
static const int const * ii;   // C4114
static const int * const iii;   // OK
```
