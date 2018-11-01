---
title: Erro do compilador C3913
ms.date: 11/04/2016
f1_keywords:
- C3913
helpviewer_keywords:
- C3913
ms.assetid: a678bfce-9524-470d-9f23-7d08ecb972c8
ms.openlocfilehash: bf83be5e95109c9e7fa0516cde780ca6907416ff
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50516371"
---
# <a name="compiler-error-c3913"></a>Erro do compilador C3913

propriedade padrão deve ser indexada.

Uma propriedade padrão foi definida incorretamente.

Para obter mais informações, consulte [propriedade](../../windows/property-cpp-component-extensions.md).

O exemplo a seguir gera C3913:

```
// C3913.cpp
// compile with: /clr /c
ref struct X {
   property int default {   // C3913
   // try the following line instead
   // property int default[int] {
      int get(int) { return 0; }
      void set(int, int) {}
   }
};
```