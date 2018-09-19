---
title: Erro do compilador C2134 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2134
dev_langs:
- C++
ms.assetid: d45cb3e8-0be4-4bd6-8be9-5f8d2384363f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e616540fdb83619096ae24533380c559aa4759da
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46101443"
---
# <a name="compiler-error-c2134"></a>Erro do compilador C2134

'function': chamada não resulta em uma expressão constante

Uma função declarada como constexpr só pode chamar outras funções declaradas como constexpr.

O exemplo a seguir gera C2134:

```
// C2134.cpp
// compile with: /c
int A() {
    return 42;
};

constexpr int B() {
    return A();  // Error C2134: 'A': call does not result in a constant expression.
}
```

Solução possível:

```
// C2134b.cpp
constexpr int A() {  // add constexpr to A, since it meets the requirements of constexpr.
    return 42;
};

constexpr int B() {
    return A();  // No error
}
```