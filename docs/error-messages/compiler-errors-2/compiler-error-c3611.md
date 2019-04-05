---
title: Erro do compilador C3611
ms.date: 11/04/2016
f1_keywords:
- C3611
helpviewer_keywords:
- C3611
ms.assetid: 42f3e320-41de-420a-bd05-8924cab765aa
ms.openlocfilehash: 2d4c5cb02b1b8c5472502380fe7c74ff4a91954a
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "58781920"
---
# <a name="compiler-error-c3611"></a>Erro do compilador C3611

'function': uma função selada não pode ter um especificador puro

Uma função selada foi declarada incorretamente.  Para obter mais informações, consulte [lacrado](../../extensions/sealed-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3611.

```
// C3611.cpp
// compile with: /clr /c

ref struct V {
   virtual void Test() sealed = 0;   // C3611
   virtual void Test2() sealed;   // OK
   virtual void Test3() = 0;   // OK
};
```