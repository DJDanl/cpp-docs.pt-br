---
title: Compilador aviso (nível 4) C4296 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4296
dev_langs:
- C++
helpviewer_keywords:
- C4296
ms.assetid: 9d99aafe-f6bd-4ee0-b8d0-98ce5712274d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a687c885a3388e01b2089aca1b399d0559803128
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46045608"
---
# <a name="compiler-warning-level-4-c4296"></a>Compilador aviso (nível 4) C4296

'operator': expressão sempre é false

Uma variável sem sinal foi usada em uma operação de comparação com zero.

Esse aviso é desativado por padrão. Ver [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

O exemplo a seguir gera C4296:

```
// C4296.cpp
// compile with: /W4
#pragma warning(default : 4296)
int main()
{
   unsigned int u = 9;
   if (u < 0)    // C4296
      u++;
   if (u >= 0)   // C4296
      u++;
}
```