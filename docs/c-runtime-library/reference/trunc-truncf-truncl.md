---
title: trunc, truncf, truncl
ms.date: 04/05/2018
api_name:
- trunc
- truncf
- truncl
api_location:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-math-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- trunc
- truncf
- truncl
- math/trunc
- math/truncf
- math/truncl
helpviewer_keywords:
- trunc function
- truncf function
- truncl function
ms.assetid: de2038ac-ac0b-483e-870c-e8992dcd4fd0
ms.openlocfilehash: b47d07cbe1e86e3f53d3a562cd5e1b3dca7f4814
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87232385"
---
# <a name="trunc-truncf-truncl"></a>trunc, truncf, truncl

Determina o inteiro mais próximo que é menor ou igual ao valor de ponto flutuante especificado.

## <a name="syntax"></a>Sintaxe

```C
double trunc( double x );
float trunc( float x ); //C++ only
long double truncl( long double x );
```

```cpp
long double trunc( long double x ); //C++ only
float trunc( float x ); //C++ only
```

### <a name="parameters"></a>parâmetros

*x*<br/>
O valor a ser truncado.

## <a name="return-value"></a>Valor retornado

Se for bem-sucedido, retorna um valor inteiro de *x*, arredondado para zero.

Caso contrário, pode retornar um dos seguintes:

|Problema|Retorno|
|-----------|------------|
|*x* = ± infinito|x|
|*x* = ± 0|x|
|*x* = Nan|NaN|

Os erros são relatados conforme especificado em [_matherr](matherr.md).

## <a name="remarks"></a>Comentários

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **truncar** que usam e retornam **`float`** **`long double`** tipos. Em um programa C, **trunc** sempre pega e retorna um **`double`** .

Como os maiores valores de ponto flutuantes são inteiros exatos, essa função não estourará por conta própria. No entanto, você pode causar o estouro, retornando um valor para um tipo inteiro.

Você também pode arredondar para baixo pela conversão implícita de ponto flutuante para integral; no entanto, isso é limitado aos valores que podem ser armazenados no tipo de destino.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**truncar**, **truncf**, **truncl**|\<math.h>|\<cmath>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Referência de função alfabética](crt-alphabetical-function-reference.md)<br/>
[floor, floorf, floorl](floor-floorf-floorl.md)<br/>
[ceil, ceilf, ceill](ceil-ceilf-ceill.md)<br/>
[round, roundf, roundl](round-roundf-roundl.md)<br/>
