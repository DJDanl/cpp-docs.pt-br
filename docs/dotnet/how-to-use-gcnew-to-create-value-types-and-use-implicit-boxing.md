---
title: 'Como: Usar gcnew para criar tipos de valor e usar conversão Boxing implícita'
ms.date: 11/04/2016
helpviewer_keywords:
- gcnew keyword [C++], creating value types
- boxing, implicit
- value types, creating
ms.assetid: ceb48841-d6bd-47be-a167-57f44c961603
ms.openlocfilehash: 4b7d0560d8a80d0c09e7f8d0fce83748ec1f2f28
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57739273"
---
# <a name="how-to-use-gcnew-to-create-value-types-and-use-implicit-boxing"></a>Como: Usar gcnew para criar tipos de valor e usar conversão Boxing implícita

Usando o [gcnew](../windows/ref-new-gcnew-cpp-component-extensions.md) em um valor de tipo será criar um tipo de valor demarcado, o que, em seguida, pode ser colocado no heap gerenciado, coleta de lixo.

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

[Conversão boxing](../windows/boxing-cpp-component-extensions.md)
