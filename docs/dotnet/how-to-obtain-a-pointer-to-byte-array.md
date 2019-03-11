---
title: 'Como: Obter um ponteiro para a matriz de bytes'
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- pointers, to Byte array
- Byte arrays
ms.assetid: aea18073-3341-47f4-9f0e-04e03327037e
ms.openlocfilehash: 28feb039cf7b91bbf12d94b1abebe0e5b9501d7f
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57738868"
---
# <a name="how-to-obtain-a-pointer-to-byte-array"></a>Como: Obter um ponteiro para a matriz de bytes

Você pode obter um ponteiro para o bloco de matriz em um <xref:System.Byte> matriz utilizando o endereço do primeiro elemento e atribuí-la a um ponteiro.

## <a name="example"></a>Exemplo

```
// pointer_to_Byte_array.cpp
// compile with: /clr
using namespace System;
int main() {
   Byte bArr[] = {1, 2, 3};
   Byte* pbArr = &bArr[0];

   array<Byte> ^ bArr2 = gcnew array<Byte>{1,2,3};
   interior_ptr<Byte> pbArr2 = &bArr2[0];
}
```

## <a name="see-also"></a>Consulte também

[Usando interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)
