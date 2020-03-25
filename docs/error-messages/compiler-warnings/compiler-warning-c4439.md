---
title: Aviso do compilador C4439
ms.date: 11/04/2016
f1_keywords:
- C4439
helpviewer_keywords:
- C4439
ms.assetid: 9449958f-f407-4824-829b-9e092f2af97d
ms.openlocfilehash: c125fa84119c62e3090611c9a841f46eee759711
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80165204"
---
# <a name="compiler-warning-c4439"></a>Aviso do compilador C4439

' function ': definição de função com um tipo gerenciado na assinatura deve ter um __clrcall Convenção de chamada

O compilador substituiu implicitamente uma Convenção de chamada por [__clrcall](../../cpp/clrcall.md). Para resolver esse aviso, remova o `__cdecl` ou `__stdcall` Convenção de chamada.

C4439 é sempre emitido como um erro. Você pode desativar esse aviso com o `#pragma warning` ou **/WD**; consulte [Warning](../../preprocessor/warning.md) ou [/w,/W0,/W1,/W2,/W3,/W4,/W1,/W2,/W3,/W4,/Wall,/WD,/We,/wo,/WV,/WX (nível de aviso)](../../build/reference/compiler-option-warning-level.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4439.

```cpp
// C4439.cpp
// compile with: /clr
void __stdcall f( System::String^ arg ) {}   // C4439
void __clrcall f2( System::String^ arg ) {}   // OK
void f3( System::String^ arg ) {}   // OK
```
