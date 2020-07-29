---
title: Aviso do compilador (nível 1) C4561
ms.date: 11/04/2016
f1_keywords:
- C4561
helpviewer_keywords:
- C4561
ms.assetid: 3a10c12c-601b-4b6c-9861-331fd022e021
ms.openlocfilehash: fe8ae1f8ef8180f2d3c5ba9ae2401b9447b22527
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230630"
---
# <a name="compiler-warning-level-1-c4561"></a>Aviso do compilador (nível 1) C4561

' __fastcall ' incompatível com a opção '/CLR ': convertendo para ' \_ _stdcall '

A Convenção de chamada de função [__fastcall](../../cpp/fastcall.md) não pode ser usada com a opção de compilador [/CLR](../../build/reference/clr-common-language-runtime-compilation.md) . O compilador ignora as chamadas para **`__fastcall`** . Para corrigir esse aviso, remova as chamadas para **`__fastcall`** ou compile sem **/CLR**.

O exemplo a seguir gera C4561:

```cpp
// C4561.cpp
// compile with: /clr /W1 /c
// processor: x86
void __fastcall Func(void *p);   // C4561, remove __fastcall to resolve
```
