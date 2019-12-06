---
title: nextafter, nextafterf, nextafterl, _nextafter, _nextafterf, nexttoward, nexttowardf, nexttowardl
ms.date: 04/05/2018
api_name:
- nextafterf
- _nextafterf
- nextafter
- nextafterl
- _nextafter
- nexttoward
- nexttowardf
- nexttowardl
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
- nextafter
- _nextafter
- nextafterf
- nextafterl
- _nextafterf
- math/nextafter
- math/nextafterf
- math/nextafterl
- nexttoward
- nexttowardf
- nexttowardl
- math/nexttoward
- math/nexttowardf
- math/nexttowardl
helpviewer_keywords:
- _nextafter function
- nextafter function
- _nextafterf function
- nextafterf function
- nextafterl function
- nexttoward function
- nexttowardf function
- nexttowardl function
ms.assetid: 9785bfb9-de53-4bd0-9637-f05fa0c1f6ab
ms.openlocfilehash: c6b100fb24d879a16780650d8a374ec26f28c048
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857717"
---
# <a name="nextafter-nextafterf-nextafterl-_nextafter-_nextafterf-nexttoward-nexttowardf-nexttowardl"></a>nextafter, nextafterf, nextafterl, _nextafter, _nextafterf, nexttoward, nexttowardf, nexttowardl

Retorna o próximo valor de ponto flutuante representável.

## <a name="syntax"></a>Sintaxe

```C
double nextafter( double x, double y );
float nextafterf( float x, float y );
long double nextafterl( long double x, long double y );

double _nextafter( double x, double y );
float _nextafterf( float x, float y ); /* x64 only */

double nexttoward( double x, long double y );
float nexttowardf( float x, long double y );
long double nexttowardl( long double x, long double y );
```

```cpp
float nextafter( float x, float y ); /* C++ only, requires <cmath> */
long double nextafter( long double x, long double y ); /* C++ only, requires <cmath> */

float nexttoward( float x, long double y ); /* C++ only, requires <cmath> */
long double nexttoward( long double x, long double y ); /* C++ only, requires <cmath> */
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O valor do ponto flutuante a ser iniciado.

*y*<br/>
O valor do ponto flutuante a ser destinado.

## <a name="return-value"></a>Valor retornado

Retorna o próximo valor de ponto flutuante reapresentável do tipo de retorno após *x* na direção de *y*. Se *x* e *y* forem iguais, a função retornará *y*, convertida no tipo de retorno, sem exceção disparada. Se *x* não for igual a *y*e o resultado for um desnormal ou zero, os Estados de exceção de ponto flutuante **FE_UNDERFLOW** e **FE_INEXACT** serão definidos e o resultado correto será retornado. Se *x* ou *y* for um NaN, o valor de retorno será um dos NANs de entrada. Se *x* é finito e o resultado é infinito ou não representável no tipo, um infinito ou NaN assinado corretamente é retornado, os **FE_OVERFLOW** e **FE_INEXACT** Estados de exceção de ponto flutuante são definidos e **errno** é definido como **ERANGE**.

## <a name="remarks"></a>Comentários

As famílias de funções **nextafter** e **nexttoward** são equivalentes, exceto para o tipo de parâmetro de *y*. Se *x* e *y* forem iguais, o valor retornado será *y* convertido para o tipo de retorno.

Como C++ o permite sobrecarga, se você incluir \<cmath > poderá chamar sobrecargas de **nextafter** e **nexttoward** que retornam tipos **float** e **Long** **Double** . Em um programa C, **nextafter** e **nexttoward** sempre retornam **Double**.

As funções **_nextafter** e **_nextafterf** são específicas da Microsoft. A função **_nextafterf** só está disponível durante a compilação para x64.

## <a name="requirements"></a>Requisitos do

|Rotina|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|-------------|---------------------------|-------------------------------|
|**nextafter**, **nextafterf**, **nextafterl**, **_nextafterf**, **nexttoward**, **nexttowardf**, **nexttowardl**|\<math.h>|\<math.h> ou \<cmath>|
|**_nextafter**|\<float.h>|\<float.h> ou \<cfloat>|

Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[isnan, _isnan, _isnanf](isnan-isnan-isnanf.md)<br/>
