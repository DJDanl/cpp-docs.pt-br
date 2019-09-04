---
title: __ll_rshift
ms.date: 09/02/2019
f1_keywords:
- __ll_rshift_cpp
- __ll_rshift
helpviewer_keywords:
- __ll_rshift intrinsic
- ll_rshift intrinsic
ms.assetid: ef13b732-d122-44a0-add9-f5544a2c4ab2
ms.openlocfilehash: ad17991d84acb7e531baf9435610ebd566197a22
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70217491"
---
# <a name="__ll_rshift"></a>__ll_rshift

**Seção específica da Microsoft**

Desloca um valor de 64 bits especificado pelo primeiro parâmetro para a direita, por um número de bits especificado pelo segundo parâmetro.

## <a name="syntax"></a>Sintaxe

```C
__int64 __ll_rshift(
   __int64 Mask,
   int nBit
);
```

### <a name="parameters"></a>Parâmetros

*Mascara*\
no O valor inteiro de 64 bits a ser deslocado para a direita.

*nBit*\
no O número de bits a serem deslocados, o módulo 64 em x64 e o módulo 32 no x86.

## <a name="return-value"></a>Valor retornado

A máscara mudada por `nBit` bits.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__ll_rshift`|x86, x64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

Se o segundo parâmetro for maior que 64 em x64 (32 no x86), esse número será tirado do módulo 64 (32 no x86) para determinar o número de bits a serem deslocados. O `ll` prefixo indica que é uma operação em `long long`, outro nome para `__int64`, o tipo integral assinado de 64 bits.

## <a name="example"></a>Exemplo

```cpp
// ll_rshift.cpp
// compile with: /EHsc
// processor: x86, x64
#include <iostream>
#include <intrin.h>
using namespace std;

#pragma intrinsic(__ll_rshift)

int main()
{
   __int64 Mask = - 0x100;
   int nBit = 4;
   cout << hex << Mask << endl;
   cout << " - " << (- Mask) << endl;
   Mask = __ll_rshift(Mask, nBit);
   cout << hex << Mask << endl;
   cout << " - " << (- Mask) << endl;
}
```

## <a name="output"></a>Saída

```Output
ffffffffffffff00
- 100
fffffffffffffff0
- 10
```

> [!NOTE]
> Se `_ull_rshift` tiver sido usado, o MSB do valor com SHIFT direita teria sido zero, portanto, o resultado desejado não teria sido obtido no caso de um valor negativo.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[__ll_lshift](../intrinsics/ll-lshift.md)\
[__ull_rshift](../intrinsics/ull-rshift.md)
