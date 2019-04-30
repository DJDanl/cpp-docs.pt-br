---
title: Compilador aviso (nível 1) C4384
ms.date: 11/04/2016
f1_keywords:
- C4384
helpviewer_keywords:
- C4384
ms.assetid: fafa8eb2-cbfc-4edb-8b0f-511ff5d37ac0
ms.openlocfilehash: 0f2666011e88dfd59eaaca154f4407bece7c963c
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64344590"
---
# <a name="compiler-warning-level-1-c4384"></a>Compilador aviso (nível 1) C4384

\#pragma 'make_public' deve ser usado somente no escopo global

O [make_public](../../preprocessor/make-public.md) pragma foi aplicada incorretamente.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4384.

```
// C4384.cpp
// compile with: /c /W1
namespace n {
   #pragma make_public(N::C)   // C4384
   namespace N {
      class C {};
   }
}
```