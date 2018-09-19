---
title: Erro fatal C1020 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1020
dev_langs:
- C++
helpviewer_keywords:
- C1020
ms.assetid: 42f429e2-5e3b-4086-a10d-b99e032e51c5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3ab0da342e575c0af452ec70d1759fe34188db9a
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46066863"
---
# <a name="fatal-error-c1020"></a>Erro fatal C1020

#endif inesperado

O `#endif` diretiva não tem nenhuma correspondência `#if`, `#ifdef`, ou `#ifndef` diretiva. Ser claro que cada `#endif` tem uma diretiva correspondente.

O exemplo a seguir gera C1020:

```
// C1020.cpp
#endif     // C1020
```

Solução possível:

```
// C1020b.cpp
// compile with: /c
#if 1
#endif
```