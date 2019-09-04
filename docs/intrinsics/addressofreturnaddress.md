---
title: _AddressOfReturnAddress
ms.date: 09/02/2019
f1_keywords:
- _AddressOfReturnAddress_cpp
- _AddressOfReturnAddress
helpviewer_keywords:
- _AddressOfReturnAddress intrinsic
- AddressOfReturnAddress intrinsic
ms.assetid: c7e10b8c-445e-4236-a602-e2d90200f70a
ms.openlocfilehash: d705029c30fdbc117c4c6e96923691e43e072e23
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70221067"
---
# <a name="_addressofreturnaddress"></a>_AddressOfReturnAddress

**Seção específica da Microsoft**

Fornece o endereço do local da memória que contém o endereço de retorno da função atual. Esse endereço não pode ser usado para acessar outros locais de memória (por exemplo, os argumentos da função).

## <a name="syntax"></a>Sintaxe

```C
void * _AddressOfReturnAddress();
```

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`_AddressOfReturnAddress`|x86, x64, ARM, ARM64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

Quando `_AddressOfReturnAddress` é usado em um programa compilado com [/CLR](../build/reference/clr-common-language-runtime-compilation.md), a função que contém `_AddressOfReturnAddress` a chamada é compilada como uma função nativa. Quando uma função compilada como chamadas gerenciadas para a `_AddressOfReturnAddress`função `_AddressOfReturnAddress` que contém o, pode não se comportar conforme o esperado.

Essa rotina só está disponível como função intrínseca.

## <a name="example"></a>Exemplo

```cpp
// compiler_intrinsics_AddressOfReturnAddress.cpp
// processor: x86, x64
#include <stdio.h>
#include <intrin.h>

// This function will print three values:
//   (1) The address retrieved from _AddressOfReturnAdress
//   (2) The return address stored at the location returned in (1)
//   (3) The return address retrieved the _ReturnAddress* intrinsic
// Note that (2) and (3) should be the same address.
__declspec(noinline)
void func() {
   void* pvAddressOfReturnAddress = _AddressOfReturnAddress();
   printf_s("%p\n", pvAddressOfReturnAddress);
   printf_s("%p\n", *((void**) pvAddressOfReturnAddress));
   printf_s("%p\n", _ReturnAddress());
}

int main() {
   func();
}
```

```Output
0012FF78
00401058
00401058
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[Palavras-chave](../cpp/keywords-cpp.md)
