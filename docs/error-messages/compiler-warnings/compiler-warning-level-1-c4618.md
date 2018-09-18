---
title: Compilador aviso (nível 1) C4618 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4618
dev_langs:
- C++
helpviewer_keywords:
- C4618
ms.assetid: 6ff10d0a-6d5b-4373-8196-1d57bb6b1611
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0ff6080d6315156a1dbaeb89fae1d5cb10865405
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46074260"
---
# <a name="compiler-warning-level-1-c4618"></a>Compilador aviso (nível 1) C4618

parâmetros de pragma incluíram uma cadeia de caracteres vazia; pragma ignorado

Uma cadeia de caracteres nula foi fornecida como um argumento para uma **#pragma**.

O pragma foi processado sem o argumento.

O exemplo a seguir gera C4618:

```
// C4618.cpp
// compile with: /W1 /LD
#pragma code_seg("")   // C4618
```