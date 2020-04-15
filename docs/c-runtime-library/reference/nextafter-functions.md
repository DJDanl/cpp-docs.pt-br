---
title: nextafter, nextafterf, nextafterl, _nextafter, _nextafterf, nexttoward, nexttowardf, nexttowardl
ms.date: 4/2/2020
api_name:
- nextafterf
- _nextafterf
- nextafter
- nextafterl
- _nextafter
- nexttoward
- nexttowardf
- nexttowardl
- _o__nextafter
- _o_nextafter
- _o_nextafterf
- _o_nextafterl
- _o_nexttoward
- _o_nexttowardf
- _o_nexttowardl
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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: 7b1416147ed000dd3dd9a13bd52e41a474a8e9d5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81338558"
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

*Y*<br/>
O valor do ponto flutuante a ser destinado.

## <a name="return-value"></a>Valor retornado

Retorna o próximo valor de ponto flutuante representando do tipo de retorno após *x* na direção de *y*. Se *x* e *y* forem iguais, a função retorna *y*, convertida para o tipo de retorno, sem exceção acionada. Se *x* não for igual a *y*, e o resultado for um denormal ou zero, os **FE_UNDERFLOW** e **FE_INEXACT** estados de exceção de ponto flutuante são definidos, e o resultado correto é devolvido. Se *x* ou *y* é um NAN, então o valor de retorno é uma das NANs de entrada. Se *x* for finito e o resultado for infinito ou não representável no tipo, um infinito ou NAN corretamente assinado é devolvido, o **FE_OVERFLOW** e **FE_INEXACT** estados de exceção de ponto flutuante são definidos e **errno** é definido como **ERANGE**.

## <a name="remarks"></a>Comentários

As famílias de funções **seguintes** e **próximas** são equivalentes, exceto pelo tipo de parâmetro *de y*. Se *x* e *y* forem iguais, o valor retornado é *y* convertido para o tipo de retorno.

Como c++ permite sobrecarga, \<se você incluir cmath> você pode chamar sobrecargas de **próximos** e **próximos em direção a** esse **flutuador** de retorno e tipos **duplos** **longos.** Em um programa C, **depois** e **próximo sempre** retornam **em dobro**.

As **funções _nextafter** e **_nextafterf** são específicas da Microsoft. A função **_nextafterf** só está disponível quando compilada para x64.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|-------------|---------------------------|-------------------------------|
|**em seguida,** **nextafterf**, **nextafterl**, **_nextafterf**, **nexttowards**, **nexttowardsf**, **nexttowardsl , nexttowardsl**|\<math.h>|\<math.h> ou \<cmath>|
|**_nextafter**|\<float.h>|\<float.h> ou \<cfloat>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[isnan, _isnan, _isnanf](isnan-isnan-isnanf.md)<br/>
