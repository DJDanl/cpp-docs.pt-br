---
title: nearbyint, nearbyintf, nearbyintl
ms.date: 04/05/2018
api_name:
- nearbyint
- nearbyintf
- nearbyintl
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
- nearbyint
- nearbyintf
- nearbyintl
- math/nearbyint
- math/narbyintf
- math/narbyintl
helpviewer_keywords:
- nearbyint function
- nearbyintf function
- nearbyintl function
ms.assetid: dd39cb68-96b0-434b-820f-6ff2ea65584f
ms.openlocfilehash: cd0a7d00c5019dd1e483d555df6db8d9770e61c1
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70951400"
---
# <a name="nearbyint-nearbyintf-nearbyintl"></a>nearbyint, nearbyintf, nearbyintl

Arredonda o valor especificado de ponto flutuante para um inteiro e retorna esse valor em um formato de ponto flutuante.

## <a name="syntax"></a>Sintaxe

```C
double nearbyint( double x );
float nearbyintf( float x );
long double nearbyintl( long double x );
```

```cpp
float nearbyint( float x ); //C++ only
long double nearbyint( long double x ); //C++ only
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O valor a ser arredondado.

## <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, retorna *x*, arredondado para o número inteiro mais próximo, usando o formato de arredondamento atual conforme relatado por [fegetround](fegetround-fesetround2.md). Caso contrário, a função pode retornar um dos seguintes valores:

|Problema|Valor de|
|-----------|------------|
|*x* = ±INFINITY|±INFINITY, sem modificações|
|*x* = ±0|±0, sem modificações|
|*x* = Nan|NaN|

Os erros não são relatados por meio de [_matherr](matherr.md); especificamente, essa função não relata nenhuma exceção **FE_INEXACT** .

## <a name="remarks"></a>Comentários

A principal diferença entre essa função e [rimir](rint-rintf-rintl.md) é que essa função não gera a exceção de ponto flutuante inexata.

Como os valores máximos de ponto flutuante são inteiros exatos, essa função nunca estourará sozinha. Em vez disso, a saída pode estourar o valor retornado, dependendo da versão da função que você usar.

C++permite sobrecarga, portanto, você pode chamar sobrecargas de **nearbyint** que usam e retornam parâmetros **duplos** **float** ou **Long** . Em um programa C, **nearbyint** sempre usa dois valores double e retorna um valor Double.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**nearbyint**, **nearbyintf**, **nearbyintl**|\<math.h>|\<cmath> ou \<math.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[Suporte a matemática e ponto flutuante](../floating-point-support.md)<br/>
