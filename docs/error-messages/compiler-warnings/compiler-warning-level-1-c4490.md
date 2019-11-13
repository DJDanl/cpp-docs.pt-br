---
title: Aviso do compilador (nível 1) C4490
ms.date: 11/04/2016
f1_keywords:
- C4490
helpviewer_keywords:
- C4490
ms.assetid: f9b03ecf-41a1-4f4d-a74c-2c1e88234ccc
ms.openlocfilehash: 41fa124eed365b87b419a4019262c0c673399295
ms.sourcegitcommit: e5192a25c084eda9eabfa37626f3274507e026b3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2019
ms.locfileid: "73966189"
---
# <a name="compiler-warning-level-1-c4490"></a>Aviso do compilador (nível 1) C4490

' override ': uso incorreto de especificador de substituição; ' function ' não corresponde a um método base ref class

Um especificador de substituição foi usado incorretamente. Por exemplo, você não substitui uma função de interface, você a implementa.

Para obter mais informações, consulte [especificadores de substituição](../../extensions/override-specifiers-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4490.

```cpp
// C4490.cpp
// compile with: /clr /c /W1

interface struct IFace {
   void Test();
};

ref struct Class1 : public IFace {
   virtual void Test() override {}   // C4490
   // try the following line instead
   // virtual void Test() {}
};
```