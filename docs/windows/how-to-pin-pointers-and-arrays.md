---
title: 'Como: Fixar ponteiros e matrizes | Microsoft Docs'
ms.custom: ''
ms.date: 10/12/2018
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- pointers, pinning
- arrays [C++], pinning
ms.assetid: ee783260-e676-46b8-a38e-11a06f1d57b0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 7adf9d4d45b4acafd65adc27e28d8eb0639d32c8
ms.sourcegitcommit: 3f4e92266737ecb70507871e87dc8e2965ad7e04
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/15/2018
ms.locfileid: "49327889"
---
# <a name="how-to-pin-pointers-and-arrays"></a>Como fixar ponteiros e matrizes

A fixação de um Subobjeto definido em um objeto gerenciado tem o efeito de fixar o objeto inteiro.  Por exemplo, se qualquer elemento de uma matriz é fixado, toda a matriz também é fixada. Não existem extensões para o idioma para declarar uma matriz fixada. Para fixar uma matriz, declare um ponteiro de fixação para seu tipo de elemento e fixar um de seus elementos.

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

## <a name="see-also"></a>Consulte também

[pin_ptr (C++/CLI)](../windows/pin-ptr-cpp-cli.md)