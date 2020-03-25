---
title: Como fixar ponteiros e matrizes
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- pointers, pinning
- arrays [C++], pinning
ms.assetid: ee783260-e676-46b8-a38e-11a06f1d57b0
ms.openlocfilehash: 8dc42690f0f56b97b2af3ed54dfb17d49b081695
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80172211"
---
# <a name="how-to-pin-pointers-and-arrays"></a>Como fixar ponteiros e matrizes

Fixar um subobjeto definido em um objeto gerenciado tem o efeito de fixar todo o objeto.  Por exemplo, se qualquer elemento de uma matriz for fixado, a matriz inteira também será fixada. Não há extensões da linguagem para declarar uma matriz fixada. Para fixar uma matriz, declare um ponteiro de anexação ao seu tipo de elemento e fixe um dos seus elementos.

## <a name="example"></a>Exemplo

### <a name="code"></a>Código

```cpp
// pin_ptr_array.cpp
// compile with: /clr
#include <stdio.h>
using namespace System;

int main() {
   array<Byte>^ arr = gcnew array<Byte>(4);
   arr[0] = 'C';
   arr[1] = '+';
   arr[2] = '+';
   arr[3] = '\0';
   pin_ptr<Byte> p = &arr[1];   // entire array is now pinned
   unsigned char * cp = p;

   printf_s("%s\n", cp); // bytes pointed at by cp
                         // will not move during call
}
```

```Output
++
```

## <a name="see-also"></a>Confira também

[pin_ptr (C++/CLI)](pin-ptr-cpp-cli.md)
