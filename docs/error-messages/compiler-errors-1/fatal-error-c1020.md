---
title: Erro fatal C1020
ms.date: 11/04/2016
f1_keywords:
- C1020
helpviewer_keywords:
- C1020
ms.assetid: 42f429e2-5e3b-4086-a10d-b99e032e51c5
ms.openlocfilehash: 67cf5067c85d07215f6391d9e5d3d1bcb4978e42
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74756897"
---
# <a name="fatal-error-c1020"></a>Erro fatal C1020

#endif inesperado

A diretiva `#endif` não tem nenhuma diretiva `#if`, `#ifdef`ou `#ifndef` correspondente. Certifique-se de que cada `#endif` tenha uma diretiva correspondente.

O exemplo a seguir gera C1020:

```cpp
// C1020.cpp
#endif     // C1020
```

Resolução possível:

```cpp
// C1020b.cpp
// compile with: /c
#if 1
#endif
```
