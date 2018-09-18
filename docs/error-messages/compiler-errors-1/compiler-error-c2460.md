---
title: Erro do compilador C2460 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2460
dev_langs:
- C++
helpviewer_keywords:
- C2460
ms.assetid: d969fca9-3ac5-4e4e-88fc-df05510e2093
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: cb2d85ffbc7aa799f0688fbb10021a04ef9455ad
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46022586"
---
# <a name="compiler-error-c2460"></a>Erro do compilador C2460

'identifier1': usa 'identifier2', que está sendo definido

Uma classe ou estrutura (`identifier2`) é declarada como um membro de si mesmo (`identifier1`). Não são permitidas definições de recursiva de classes e estruturas.

O exemplo a seguir gera C2460:

```
// C2460.cpp
class C {
   C aC;    // C2460
};
```

Em vez disso, use uma referência de ponteiro na classe.

```
// C2460.cpp
class C {
   C * aC;    // OK
};
```