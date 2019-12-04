---
title: Erro fatal C1022
ms.date: 11/04/2016
f1_keywords:
- C1022
helpviewer_keywords:
- C1022
ms.assetid: edada720-dc73-49bc-bd93-a7945a316312
ms.openlocfilehash: b709d4bd855e38cb3721dec6d09b95ed02454def
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74756871"
---
# <a name="fatal-error-c1022"></a>Erro fatal C1022

esperado #endif

Uma diretiva `#if`, `#ifdef`ou `#ifndef` não tem nenhuma diretiva `#endif` correspondente. Certifique-se de que cada `#if`, `#ifdef`ou `#ifndef` tenha um `#endif`correspondente.

O exemplo a seguir gera C1022:

```cpp
// C1022.cpp
#define true 1

#if (true)
#else
#else    // C1022
```

Resolução possível:

```cpp
// C1022b.cpp
// compile with: /c
#define true 1

#if (true)
#else
#endif
```
