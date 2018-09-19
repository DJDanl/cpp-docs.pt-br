---
title: Compilador aviso (nível 1 e nível 4) C4949 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4949
dev_langs:
- C++
helpviewer_keywords:
- C4949
ms.assetid: 34f45a05-c115-49cb-9f67-0bd4f0735d9b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f806912188ada3a4f97f0b1500e811d1271f40fe
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46077302"
---
# <a name="compiler-warning-level-1-and-level-4-c4949"></a>Compilador aviso (nível 1 e nível 4) C4949

pragmas 'managed' e 'unmanaged' são significativos apenas quando compilado com ' / clr [: opção]'

O compilador ignora os [managed](../../preprocessor/managed-unmanaged.md) e não gerenciados pragmas, se o código-fonte não é compilado com [/clr](../../build/reference/clr-common-language-runtime-compilation.md). Esse aviso é informativo.

O exemplo a seguir gera C4949:

```
// C4949.cpp
// compile with: /LD /W1
#pragma managed   // C4949
```

Quando **#pragma não gerenciado** for usado sem **/clr**, C4949 é um aviso de nível 4.

O exemplo a seguir gera C4949:

```
// C4949b.cpp
// compile with: /LD /W4
#pragma unmanaged   // C4949
```