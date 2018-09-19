---
title: Erro do compilador C3058 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3058
dev_langs:
- C++
helpviewer_keywords:
- C3058
ms.assetid: 669d08c8-0b58-4351-88aa-c6e6e1af481c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 56862c411a31781f85afb280453c43b3611ff31e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46093968"
---
# <a name="compiler-error-c3058"></a>Erro do compilador C3058

'symbol': símbolo não declarado como 'threadprivate' antes de ser usada na cláusula 'copyin'

Um símbolo deve ser declarado primeiro [threadprivate](../../parallel/openmp/reference/threadprivate.md) antes que ele pode ser usado em uma [copyin](../../parallel/openmp/reference/copyin.md) cláusula.

O exemplo a seguir gera C3058:

```
// C3058.cpp
// compile with: /openmp
int x, y, z;
#pragma omp threadprivate(x, z)

void test() {
   #pragma omp parallel copyin(x, y)   // C3058
   {
   }
}
```

Solução possível:

```
// C3058b.cpp
// compile with: /openmp /LD
int x, y, z;
#pragma omp threadprivate(x, y)

void test() {
   #pragma omp parallel copyin(x, y)
   {
   }
}
```