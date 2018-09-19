---
title: Erro do compilador C2042 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2042
dev_langs:
- C++
helpviewer_keywords:
- C2042
ms.assetid: e111788f-41ce-405a-9824-a4c1c26059e6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: cbc1d0d5ec0781ebf203a2cebcd99a58996c6547
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46079993"
---
# <a name="compiler-error-c2042"></a>Erro do compilador C2042

não assinado/assinado palavras-chave mutuamente exclusivas

As palavras-chave `signed` e `unsigned` são usados em uma única declaração.

O exemplo a seguir gera C2042:

```
// C2042.cpp
unsigned signed int i;   // C2042
```

Solução possível:

```
// C2042b.cpp
// compile with: /c
unsigned int i;
signed int ii;
```