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
ms.openlocfilehash: 158ecbf39320d70b51f1f498a0b689ba58fec363
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70221817"
---
# <a name="__ll_lshift"></a>__ll_lshift

**Seção específica da Microsoft**

Desloca o valor de 64 bits fornecido para a esquerda pelo número especificado de bits.

## <a name="syntax"></a>Sintaxe

```C
unsigned __int64 __ll_lshift(
   unsigned __int64 Mask,
   int nBit
);
```

### <a name="parameters"></a>Parâmetros

*Mascara*\
no O valor inteiro de 64 bits a ser deslocado para a esquerda.

*nBit*\
no O número de bits a ser deslocado.

## <a name="return-value"></a>Valor retornado

A máscara foi deslocada para `nBit` a esquerda por bits.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__ll_lshift`|x86, x64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

Se você compilar seu programa para a arquitetura de 64 bits e `nBit` for maior que 63, o número de bits a serem deslocados será `nBit` o módulo 64. Se você compilar seu programa para a arquitetura de 32 bits e `nBit` for maior que 31, o número de bits a serem deslocados será `nBit` o módulo 32.

O `ll` no nome indica que é uma operação em `long long` (`__int64`).

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
> Não há nenhuma versão não assinada da operação de deslocamento à esquerda. Isso porque `__ll_lshift` o já usa um parâmetro de entrada não assinado. Ao contrário do deslocamento à direita, não há nenhuma dependência de sinal para o deslocamento à esquerda, porque o bit menos significativo no resultado é sempre definido como zero, independentemente do sinal do valor deslocado.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[__ll_rshift](../intrinsics/ll-rshift.md)\
[__ull_rshift](../intrinsics/ull-rshift.md)\
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
