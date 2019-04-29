---
title: Erro do compilador C2792
ms.date: 11/04/2016
f1_keywords:
- C2792
helpviewer_keywords:
- C2792
ms.assetid: 392cf748-4f5e-4e62-a364-3118d5658408
ms.openlocfilehash: 40047cb557fba49f94e5c4e42f172cbcd999c65a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62360171"
---
# <a name="compiler-error-c2792"></a>Erro do compilador C2792

'super': esta palavra-chave deve ser seguido por ':: '

O token único que pode seguir a palavra-chave `__super` é `::`.

O exemplo a seguir gera C2792:

```
// C2792.cpp
struct B {
   void mf();
};

struct D : B {
   void mf() {
      __super.();   // C2792

      // try the following line instead
      // __super::mf();
   }
};
```