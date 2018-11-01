---
title: _BitScanForward, _BitScanForward64
ms.date: 11/04/2016
f1_keywords:
- _BitScanForward
- _BitScanForward_cpp
- _BitScanForward64_cpp
- _BitScanForward64
helpviewer_keywords:
- _BitScanForward intrinsic
- bsf instruction
- BitScanForward intrinsic
ms.assetid: 405e60fb-0815-42a7-9b02-6fc035122203
ms.openlocfilehash: 87bb2a20e786982d8e0c710696f0339f579a84e5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50440463"
---
# <a name="bitscanforward-bitscanforward64"></a>_BitScanForward, _BitScanForward64

**Seção específica da Microsoft**

Pesquise os dados de máscara do bit menos significativo (LSB) para o bit mais significativo (MSB) para um conjunto de bits (1).

## <a name="syntax"></a>Sintaxe

```
unsigned char _BitScanForward(
   unsigned long * Index,
   unsigned long Mask
);
unsigned char _BitScanForward64(
   unsigned long * Index,
   unsigned __int64 Mask
);
```

#### <a name="parameters"></a>Parâmetros

*Índice*<br/>
[out] Carregado com a posição de bit do primeiro bit definido (1) encontrada.

*Máscara*<br/>
[in] O valor de 32 bits ou 64 bits a pesquisar.

## <a name="return-value"></a>Valor de retorno

0 se a máscara for zero. diferente de zero, caso contrário.

## <a name="remarks"></a>Comentários

Se bit definido for encontrado, a posição de bit do primeiro bit definido encontrado será retornada ao primeiro parâmetro. Se nenhum bit definido for encontrado, 0 será retornado; caso contrário, 1.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`_BitScanForward`|x86, ARM, x64|
|`_BitScanForward64`|ARM, x64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="example"></a>Exemplo

```
// BitScanForward.cpp
// compile with: /EHsc
#include <iostream>
#include <intrin.h>
using namespace std;

#pragma intrinsic(_BitScanForward)

int main()
{
   unsigned long mask = 0x1000;
   unsigned long index;
   unsigned char isNonzero;

   cout << "Enter a positive integer as the mask: " << flush;
   cin >> mask;
   isNonzero = _BitScanForward(&index, mask);
   if (isNonzero)
   {
      cout << "Mask: " << mask << " Index: " << index << endl;
   }
   else
   {
      cout << "No set bits found.  Mask is zero." << endl;
   }
}
```

## <a name="input"></a>Entrada

```
12
```

## <a name="sample-output"></a>Saída de Exemplo

```
Enter a positive integer as the mask:
Mask: 12 Index: 2
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)