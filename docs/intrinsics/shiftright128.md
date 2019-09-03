---
title: __shiftright128
ms.date: 09/02/2019
f1_keywords:
- __shiftright128
helpviewer_keywords:
- __shiftright128 intrinsic
ms.assetid: 5419a6c4-0de1-43fb-b314-4faa5b2d051f
ms.openlocfilehash: a18a9958a51f291e4997c23e87ee48f739562416
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70220022"
---
# <a name="__shiftright128"></a>__shiftright128

**Seção específica da Microsoft**

Desloca uma quantidade de 128 bits, representada como duas quantidades de 64 bits `LowPart` e `HighPart`, à esquerda por um número de bits especificado pelo `Shift` e retorna os 64 bits baixos do resultado.

## <a name="syntax"></a>Sintaxe

```C
unsigned __int64 __shiftright128(
   unsigned __int64 LowPart,
   unsigned __int64 HighPart,
   unsigned char Shift
);
```

### <a name="parameters"></a>Parâmetros

*LowPart*\
no Os poucos 64 bits da quantidade de 128 bits a serem deslocados.

*HighPart*\
no Os bits de 64 altos da quantidade de 128 bits a serem deslocados.

*Alternância*\
no O número de bits a ser deslocado.

## <a name="return-value"></a>Valor retornado

64 bits baixos do resultado.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__shiftright128`|X64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

O valor `Shift` é sempre módulo 64 para que, por exemplo, se você chamar, `__shiftright128(0, 1, 64)`, a função deslocará os bits altos `0` para a esquerda e retornará uma parte baixa de `0` e não `1` como era previsto.

## <a name="example"></a>Exemplo

Para obter um exemplo, consulte [__shiftleft128](../intrinsics/shiftleft128.md).

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[__shiftleft128](../intrinsics/shiftleft128.md)\
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
