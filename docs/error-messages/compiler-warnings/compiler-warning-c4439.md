---
title: Aviso do compilador C4439
ms.date: 11/04/2016
f1_keywords:
- C4439
helpviewer_keywords:
- C4439
ms.assetid: 9449958f-f407-4824-829b-9e092f2af97d
ms.openlocfilehash: 7cab2e55fca640438051fbb79ac933e83d5f3cbb
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73623650"
---
# <a name="compiler-warning-c4439"></a>Aviso do compilador C4439

' function ': a definição de função com um tipo gerenciado na assinatura deve ter uma Convenção de chamada ir_ clrcall

O compilador substituiu implicitamente uma Convenção de chamada por [_ unclrcall](../../cpp/clrcall.md). Para resolver esse aviso, remova o `__cdecl` ou `__stdcall` Convenção de chamada.

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