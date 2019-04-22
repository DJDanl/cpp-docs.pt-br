---
title: 'Como: Usar gcnew para criar tipos de valor e usar conversão Boxing implícita'
ms.date: 11/04/2016
helpviewer_keywords:
- gcnew keyword [C++], creating value types
- boxing, implicit
- value types, creating
ms.assetid: ceb48841-d6bd-47be-a167-57f44c961603
ms.openlocfilehash: c67f8e0b9511f4ed1610e72e4a7df41c949b1d27
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58770782"
---
# <a name="how-to-use-gcnew-to-create-value-types-and-use-implicit-boxing"></a>Como: Usar gcnew para criar tipos de valor e usar conversão Boxing implícita

Usando o [gcnew](../extensions/ref-new-gcnew-cpp-component-extensions.md) em um valor de tipo será criar um tipo de valor demarcado, o que, em seguida, pode ser colocado no heap gerenciado, coleta de lixo.

## <a name="example"></a>Exemplo

```
// vcmcppv2_explicit_boxing4.cpp
// compile with: /clr
public value class V {
public:
   int m_i;
   V(int i) : m_i(i) {}
};

public ref struct TC {
   void do_test(V^ v) {
      if (v != nullptr)
         ;
      else
         ;
   }
};

int main() {
   V^ v = gcnew V(42);
   TC^ tc = gcnew TC;
   tc->do_test(v);
}
```

## <a name="see-also"></a>Consulte também

[Conversão boxing](../extensions/boxing-cpp-component-extensions.md)
