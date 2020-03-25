---
title: Como declarar ponteiros de fixação e tipos de valor
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- value types, declaring
- pinning pointers
ms.assetid: 57c5ec8a-f85a-48c4-ba8b-a81268bcede0
ms.openlocfilehash: 88ef7e82161703a272a571392fd66e6055371c61
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80181961"
---
# <a name="how-to-declare-pinning-pointers-and-value-types"></a>Como declarar ponteiros de fixação e tipos de valor

Um tipo de valor pode ter conversão boxing implícita. Você pode então declarar um ponteiro de anexação para o objeto de tipo de valor propriamente dito e usar um **pin_ptr** para o tipo de valor com conversão boxing.

## <a name="example"></a>Exemplo

### <a name="code"></a>Código

```cpp
// pin_ptr_value.cpp
// compile with: /clr
value struct V {
   int i;
};

int main() {
   V ^ v = gcnew V;   // imnplicit boxing
   v->i=8;
   System::Console::WriteLine(v->i);
   pin_ptr<V> mv = &*v;
   mv->i = 7;
   System::Console::WriteLine(v->i);
   System::Console::WriteLine(mv->i);
}
```

```Output
8
7
7
```

## <a name="see-also"></a>Confira também

[pin_ptr (C++/CLI)](pin-ptr-cpp-cli.md)
