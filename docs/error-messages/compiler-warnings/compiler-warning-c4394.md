---
title: Aviso do compilador C4394
ms.date: 11/04/2016
f1_keywords:
- C4394
helpviewer_keywords:
- C4394
ms.assetid: 5de94de0-17e3-4e7c-92f4-5c3c1b825120
ms.openlocfilehash: b97819a6f1b95f083eb594d3b9b2e68cbf30d19a
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73623689"
---
# <a name="compiler-warning-c4394"></a>Aviso do compilador C4394

' function ': símbolo Per-AppDomain não deve ser marcado com _ _ declspec (dllexport)

Uma função marcada com o modificador de`__declspec` de [AppDomain](../../cpp/appdomain.md) é compilada para MSIL (não para nativo) e não há suporte para exportar tabelas (modificador`__declspec` de[exportação](../../windows/export.md) ) para funções gerenciadas.

Você pode declarar uma função gerenciada para ter acessibilidade pública. Para obter mais informações, consulte [visibilidade de tipos](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Type_visibility) e visibilidade de [Membros](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Member_visibility).

C4394 é sempre emitido como um erro.  Você pode desativar esse aviso com o `#pragma warning` ou **/WD**; consulte [Warning](../../preprocessor/warning.md) ou [/w,/W0,/W1,/W2,/W3,/W4,/W1,/W2,/W3,/W4,/Wall,/WD,/We,/wo,/WV,/WX (nível de aviso)](../../build/reference/compiler-option-warning-level.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4394.

```cpp
// C4394.cpp
// compile with: /clr /c
__declspec(dllexport) __declspec(appdomain) int g1 = 0;   // C4394
__declspec(dllexport) int g2 = 0;   // OK
```