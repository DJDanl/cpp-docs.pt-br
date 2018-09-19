---
title: Aviso do compilador C4439 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4439
dev_langs:
- C++
helpviewer_keywords:
- C4439
ms.assetid: 9449958f-f407-4824-829b-9e092f2af97d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 646b057f3f25bec8b686b08d50f0e473542ddcfc
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46076106"
---
# <a name="compiler-warning-c4439"></a>Aviso do compilador C4439

'function': definição de função com um tipo gerenciado na assinatura deve ter um clrcall convenção de chamada

O compilador implicitamente substituído uma convenção de chamada com [clrcall](../../cpp/clrcall.md). Para resolver este aviso, remova os `__cdecl` ou `__stdcall` convenção de chamada.

C4439 sempre é emitido como um erro. Você pode desativar esse aviso com a `#pragma warning` ou **/wd**; consulte [aviso](../../preprocessor/warning.md) ou [/w, /W0, / W1, / w2, / w3, / W4, / W1, / w2, / w3, / W4, /Wall, /wd, /, /wo, /Wv, /WX (nível de aviso)](../../build/reference/compiler-option-warning-level.md)para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4439.

```
// C4439.cpp
// compile with: /clr
void __stdcall f( System::String^ arg ) {}   // C4439
void __clrcall f2( System::String^ arg ) {}   // OK
void f3( System::String^ arg ) {}   // OK
```