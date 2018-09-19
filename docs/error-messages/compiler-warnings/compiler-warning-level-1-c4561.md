---
title: Compilador aviso (nível 1) C4561 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4561
dev_langs:
- C++
helpviewer_keywords:
- C4561
ms.assetid: 3a10c12c-601b-4b6c-9861-331fd022e021
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0ba0770a8b8b42c8174d421f55dd45ff7f335d06
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46115782"
---
# <a name="compiler-warning-level-1-c4561"></a>Compilador aviso (nível 1) C4561

fastcall' incompatível com o ' / clr' opção: convertendo para '\_stdcall '

O [fastcall](../../cpp/fastcall.md) convenção de chamada de função não pode ser usada com o [/clr](../../build/reference/clr-common-language-runtime-compilation.md) opção de compilador. O compilador ignora as chamadas para `__fastcall`. Para corrigir este aviso, remova as chamadas para **fastcall** ou compilar sem **/clr**.

O exemplo a seguir gera C4561:

```
// C4561.cpp
// compile with: /clr /W1 /c
// processor: x86
void __fastcall Func(void *p);   // C4561, remove __fastcall to resolve
```