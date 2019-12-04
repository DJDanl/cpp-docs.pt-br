---
title: Erro do compilador C3155
ms.date: 11/04/2016
f1_keywords:
- C3155
helpviewer_keywords:
- C3155
ms.assetid: b04a42e1-64e7-40f8-81fe-c7945348b2cf
ms.openlocfilehash: ccbe96075a22ef67d7ebd1f2998b42820bbc79f9
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74745896"
---
# <a name="compiler-error-c3155"></a>Erro do compilador C3155

atributos não são permitidos em um indexador de propriedade

Uma propriedade indexada foi declarada incorretamente. Para obter mais informações, consulte [como: usar propriedades em C++/CLI](../../dotnet/how-to-use-properties-in-cpp-cli.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3155.

```cpp
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
