---
title: Erro do compilador C3865
ms.date: 11/04/2016
f1_keywords:
- C3865
helpviewer_keywords:
- C3865
ms.assetid: 9bc62bb0-4fb8-4856-a5cf-c7cb4029a596
ms.openlocfilehash: 960c795fe934433e4e3cf79e4c01c49d00205b9b
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74761485"
---
# <a name="compiler-error-c3865"></a>Erro do compilador C3865

' calling_convention ': só pode ser usado em funções de membro nativo

Uma Convenção de chamada foi usada em uma função que era uma função global ou em uma função membro gerenciado. A Convenção de chamada só pode ser usada em uma função de membro nativa (não gerenciada).

Para obter mais informações, consulte [convenções de chamada](../../cpp/calling-conventions.md).

O exemplo a seguir gera C3865:

```cpp
// C3865.cpp
// compile with: /clr
// processor: x86
void __thiscall Func(){}   // C3865

// OK
struct MyType {
   void __thiscall Func(){}
};
```
