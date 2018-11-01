---
title: Aviso do compilador C4394
ms.date: 11/04/2016
f1_keywords:
- C4394
helpviewer_keywords:
- C4394
ms.assetid: 5de94de0-17e3-4e7c-92f4-5c3c1b825120
ms.openlocfilehash: 00c9e139e920473590389c05f076a7cd91a4fb8d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50548844"
---
# <a name="compiler-warning-c4394"></a>Aviso do compilador C4394

'function': símbolo per-appdomain não deve ser marcado com dllexport

Uma função marcada com o [appdomain](../../cpp/appdomain.md) `__declspec` modificador é compilado para MSIL (não para nativo) e tabelas de exportação ([exportar](../../windows/export.md) `__declspec` modificador) não têm suporte para funções gerenciadas.

Você pode declarar uma função gerenciada para ter acessibilidade pública. Para obter mais informações, consulte [visibilidade de tipo](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Type_visibility) e [visibilidade de membro](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Member_visibility).

C4394 sempre é emitido como um erro.  Você pode desativar esse aviso com a `#pragma warning` ou **/wd**; consulte [aviso](../../preprocessor/warning.md) ou [/w, /W0, / W1, / w2, / w3, / W4, / W1, / w2, / w3, / W4, /Wall, /wd, /, /wo, /Wv, /WX (nível de aviso)](../../build/reference/compiler-option-warning-level.md)para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4394.

```
// C4394.cpp
// compile with: /clr /c
__declspec(dllexport) __declspec(appdomain) int g1 = 0;   // C4394
__declspec(dllexport) int g2 = 0;   // OK
```