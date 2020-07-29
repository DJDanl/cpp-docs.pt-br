---
title: __ll_lshift
ms.date: 09/02/2019
f1_keywords:
- __ll_lshift_cpp
- __ll_lshift
helpviewer_keywords:
- ll_lshift intrinsic
- __ll_lshift intrinsic
ms.assetid: fe98f733-426d-44b3-8f24-5d0d6d44bd94
ms.openlocfilehash: 988284b81c9f04ee5d7f09f8a2f173a689f9fb55
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230513"
---
# <a name="__ll_lshift"></a>__ll_lshift

**Específico da Microsoft**

Desloca o valor de 64 bits fornecido para a esquerda pelo número especificado de bits.

## <a name="syntax"></a>Sintaxe

```C
unsigned __int64 __ll_lshift(
   unsigned __int64 Mask,
   int nBit
);
```

### <a name="parameters"></a>parâmetros

*Mascara*\
no O valor inteiro de 64 bits a ser deslocado para a esquerda.

*nBit*\
no O número de bits a ser deslocado.

## <a name="return-value"></a>Valor retornado

A máscara foi deslocada para a esquerda por `nBit` bits.

## <a name="requirements"></a>Requisitos

|Intrinsic|Arquitetura|
|---------------|------------------|
|`__ll_lshift`|x86, x64|

**Arquivo de cabeçalho** \<intrin.h>

## <a name="remarks"></a>Comentários

Se você compilar seu programa para a arquitetura de 64 bits e `nBit` for maior que 63, o número de bits a serem deslocados será o `nBit` módulo 64. Se você compilar seu programa para a arquitetura de 32 bits e `nBit` for maior que 31, o número de bits a serem deslocados será o `nBit` módulo 32.

O `ll` no nome indica que é uma operação em **`long long`** ( **`__int64`** ).

## <a name="example"></a>Exemplo

```cpp
// ll_lshift.cpp
// compile with: /EHsc
// processor: x86, x64
#include <iostream>
#include <intrin.h>
using namespace std;

#pragma intrinsic(__ll_lshift)

int main()
{
   unsigned __int64 Mask = 0x100;
   int nBit = 8;
   Mask = __ll_lshift(Mask, nBit);
   cout << hex << Mask << endl;
}
```

## <a name="output"></a>Saída

```Output
10000
```

> [!NOTE]
> Não há nenhuma versão não assinada da operação de deslocamento à esquerda. Isso porque o `__ll_lshift` já usa um parâmetro de entrada não assinado. Ao contrário do deslocamento à direita, não há nenhuma dependência de sinal para o deslocamento à esquerda, porque o bit menos significativo no resultado é sempre definido como zero, independentemente do sinal do valor deslocado.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[__ll_rshift](../intrinsics/ll-rshift.md)\
[__ull_rshift](../intrinsics/ull-rshift.md)\
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
