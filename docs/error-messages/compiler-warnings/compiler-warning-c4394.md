---
title: Aviso do compilador C4394
ms.date: 11/04/2016
f1_keywords:
- C4394
helpviewer_keywords:
- C4394
ms.assetid: 5de94de0-17e3-4e7c-92f4-5c3c1b825120
ms.openlocfilehash: ad6b9624a1bf510465843167d104d1bec189bc70
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87197352"
---
# <a name="compiler-warning-c4394"></a>Aviso do compilador C4394

' function ': símbolo Per-AppDomain não deve ser marcado com __declspec (dllexport)

Uma função marcada com o [appdomain](../../cpp/appdomain.md) **`__declspec`** modificador AppDomain é compilada para MSIL (não para nativo) e as tabelas de exportação (modificador de[exportação](../../windows/export.md) **`__declspec`** ) não têm suporte para funções gerenciadas.

Você pode declarar uma função gerenciada para ter acessibilidade pública. Para obter mais informações, consulte [visibilidade de tipos](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Type_visibility) e visibilidade de [Membros](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Member_visibility).

C4394 é sempre emitido como um erro.  Você pode desativar esse aviso com o `#pragma warning` ou **/WD**; Veja [Warning](../../preprocessor/warning.md) ou [/W,/W0,/W1,/W2,/W3,/W4,/W1,/W2,/W3,/W4,/Wall,/WD,/We,/wo,/WV,/WX (nível de aviso)](../../build/reference/compiler-option-warning-level.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4394.

```cpp
// C4394.cpp
// compile with: /clr /c
__declspec(dllexport) __declspec(appdomain) int g1 = 0;   // C4394
__declspec(dllexport) int g2 = 0;   // OK
```
