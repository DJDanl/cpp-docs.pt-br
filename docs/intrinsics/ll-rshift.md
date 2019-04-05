---
title: __ll_rshift
ms.date: 11/04/2016
f1_keywords:
- __ll_rshift_cpp
- __ll_rshift
helpviewer_keywords:
- __ll_rshift intrinsic
- ll_rshift intrinsic
ms.assetid: ef13b732-d122-44a0-add9-f5544a2c4ab2
ms.openlocfilehash: e39f8fe797467569077dd24baf49670607915107
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59041014"
---
# <a name="llrshift"></a>__ll_rshift

**Específico da Microsoft**

Desloca um valor de 64 bits especificado pelo primeiro parâmetro para a direita em um número de bits especificado pelo segundo parâmetro.

## <a name="syntax"></a>Sintaxe

```
__int64 __ll_rshift(
   __int64 Mask,
   int nBit
);
```

#### <a name="parameters"></a>Parâmetros

*Máscara*<br/>
[in] O valor de inteiro de 64 bits a deslocar para a direita.

*nBit*<br/>
[in] O número de bits a deslocar, módulo 64 em x64 e de módulo 32 no x86.

## <a name="return-value"></a>Valor de retorno

A máscara deslocados em `nBit` bits.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__ll_rshift`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

Se o segundo parâmetro é maior que 64 em x64 (em x86 de 32), esse número é tirado módulo 64 (32 em x86) para determinar o número de bits a deslocar. O `ll` prefixo indica que esta é uma operação no `long long`, em outro nome para `__int64`, o tipo integral com sinal de 64 bits.

## <a name="example"></a>Exemplo

```
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

```
ffffffffffffff00
- 100
fffffffffffffff0
- 10
```

**Observação** se `_ull_rshift` tiver sido usado, o MSB do valor deslocados para a direita teria sido zero, portanto, o resultado desejado seria não ter sido obtido no caso de um valor negativo.

**FIM de Específico da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[__ll_lshift](../intrinsics/ll-lshift.md)<br/>
[__ull_rshift](../intrinsics/ull-rshift.md)