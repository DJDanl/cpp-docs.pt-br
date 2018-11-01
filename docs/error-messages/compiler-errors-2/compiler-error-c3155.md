---
title: Erro do compilador C3155
ms.date: 11/04/2016
f1_keywords:
- C3155
helpviewer_keywords:
- C3155
ms.assetid: b04a42e1-64e7-40f8-81fe-c7945348b2cf
ms.openlocfilehash: 85ee53dff7ae50717eabfd1ac6504ebb74deaa2d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50644350"
---
# <a name="compiler-error-c3155"></a>Erro do compilador C3155

atributos não são permitidos em um indexador de propriedades

Uma propriedade indexada foi declarada incorretamente. Para obter mais informações, consulte [como: usar propriedades no C + + c++ CLI](../../dotnet/how-to-use-properties-in-cpp-cli.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3155.

```
// C3155.cpp
// compile with: /clr /c
using namespace System;
ref struct R {
   property int F[[ParamArray] int] {   // C3155
   // try the following line instead
   // property int F[ int] {   // OK
      int get(int i) {
         return 0;
      }
   }
};
```