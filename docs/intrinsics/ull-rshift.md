---
title: __ull_rshift
ms.date: 09/02/2019
f1_keywords:
- __ull_rshift
helpviewer_keywords:
- ull_rshift intrinsic
- __ull_rshift intrinsic
ms.assetid: b7ff5254-3540-4e6e-b57c-a6c4beb7dca2
ms.openlocfilehash: e914a019877482058c6b2842d3138cda02f1e228
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70219713"
---
# <a name="__ull_rshift"></a>__ull_rshift

**Seção específica da Microsoft**

em x64, desloca um valor de 64 bits especificado pelo primeiro parâmetro para a direita por um número de bits especificado pelo segundo parâmetro.

## <a name="syntax"></a>Sintaxe

```C
unsigned __int64 __ull_rshift(
   unsigned __int64 mask, 
   int nBit
);
```

### <a name="parameters"></a>Parâmetros

*mascara*\
no O valor inteiro de 64 bits a ser deslocado para a direita.

*nBit*\
no O número de bits a serem deslocados, o módulo 32 em x86 e o módulo 64 em x64.

## <a name="return-value"></a>Valor retornado

A máscara mudada por `nBit` bits.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__ull_rshift`|x86, x64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

Se o segundo parâmetro for maior que 31 no x86 (63 em x64), esse número será tirado do módulo 32 (64 em x64) para determinar o número de bits a serem deslocados. O `ull` no nome indica `unsigned long long (unsigned __int64)`.

## <a name="example"></a>Exemplo

```cpp
// ull_rshift.cpp
// compile with: /EHsc
// processor: x86, x64
#include <iostream>
#include <intrin.h>
using namespace std;

#pragma intrinsic(__ull_rshift)

int main()
{
   unsigned __int64 mask = 0x100;
   int nBit = 8;
   mask = __ull_rshift(mask, nBit);
   cout << hex << mask << endl;
}
```

```Output
1
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[__ll_lshift](../intrinsics/ll-lshift.md)\
[__ll_rshift](../intrinsics/ll-rshift.md)\
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
