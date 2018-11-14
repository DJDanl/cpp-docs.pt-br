---
title: __shiftright128
ms.date: 11/04/2016
f1_keywords:
- __shiftright128
helpviewer_keywords:
- __shiftright128 intrinsic
ms.assetid: 5419a6c4-0de1-43fb-b314-4faa5b2d051f
ms.openlocfilehash: 8c35625efa9ddc4cf5de3900c6e3e37047b2aa10
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51332147"
---
# <a name="shiftright128"></a>__shiftright128

**Seção específica da Microsoft**

Desloca uma quantidade de 128 bits, representada como duas quantidades de 64 bits `LowPart` e `HighPart`, à esquerda por um número de bits especificado pelo `Shift` e retorna os 64 bits baixos do resultado.

## <a name="syntax"></a>Sintaxe

```
unsigned __int64 __shiftright128(
   unsigned __int64 LowPart,
   unsigned __int64 HighPart,
   unsigned char Shift
);
```

#### <a name="parameters"></a>Parâmetros

*Dinâmaico*<br/>
[in] Os 64 bits baixos da quantidade de 128 bits a deslocar.

*HighPart*<br/>
[in] Os 64 bits altos da quantidade de 128 bits a deslocar.

*Shift*<br/>
[in] O número de bits a deslocar.

## <a name="return-value"></a>Valor de retorno

64 bits baixos do resultado.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__shiftright128`|X64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

O valor `Shift` é sempre módulo 64 para que, por exemplo, se você chamar, `__shiftright128(0, 1, 64)`, a função deslocará os bits altos `0` para a esquerda e retornará uma parte baixa de `0` e não `1` como era previsto.

## <a name="example"></a>Exemplo

Por exemplo, consulte [__shiftleft128](../intrinsics/shiftleft128.md).

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[__shiftleft128](../intrinsics/shiftleft128.md)<br/>
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)