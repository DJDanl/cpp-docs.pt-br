---
title: nextafter, nextafterf, nextafterl, _nextafter, _nextafterf, nexttoward, nexttowardf, nexttowardl
description: Referência de API para nextafter, nextafterf, nextafterl, _nextafter, _nextafterf, nexttoward, nexttowardf e nexttowardl; que retornam o próximo valor de ponto flutuante representável.
ms.date: 9/1/2020
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
- api-ms-win-crt-private-l1-1-0.dll
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
ms.openlocfilehash: cdcfb1a1d0bf1523a0252d779dba603ce1814b14
ms.sourcegitcommit: 4ed2d68634eb2fb77e18110a2d26bc0008be369c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/08/2020
ms.locfileid: "89555820"
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

#define nextafter(X, Y) // Requires C11 or higher

double nexttoward( double x, long double y );
float nexttowardf( float x, long double y );
long double nexttowardl( long double x, long double y );

#define nexttoward(X, Y) // Requires C11 or higher

float nextafter( float x, float y ); /* C++ only, requires <cmath> */
long double nextafter( long double x, long double y ); /* C++ only, requires <cmath> */

float nexttoward( float x, long double y ); /* C++ only, requires <cmath> */
long double nexttoward( long double x, long double y ); /* C++ only, requires <cmath> */
```

### <a name="parameters"></a>Parâmetros

*w.x.y.*\
O valor do ponto flutuante a ser iniciado.

*Iar*\
O valor do ponto flutuante a ser destinado.

## <a name="return-value"></a>Valor Retornado

Retorna o próximo valor de ponto flutuante reapresentável do tipo de retorno após *x* na direção de *y*. Se *x* e *y* forem iguais, a função retornará *y*, convertida no tipo de retorno, sem exceção disparada. Se *x* não for igual a *y*e o resultado for um desnormal ou zero, os Estados de exceção de ponto flutuante **FE_UNDERFLOW** e **FE_INEXACT** serão definidos e o resultado correto será retornado. Se *x* ou *y* for um NaN, o valor de retorno será um dos NANs de entrada. Se *x* é finito e o resultado é infinito ou não representável no tipo, um infinito ou NaN assinado corretamente é retornado, os **FE_OVERFLOW** e **FE_INEXACT** Estados de exceção de ponto flutuante são definidos e **errno** é definido como **ERANGE**.

## <a name="remarks"></a>Comentários

As famílias de funções **nextafter** e **nexttoward** são equivalentes, exceto para o tipo de parâmetro de *y*. Se *x* e *y* forem iguais, o valor retornado será *y* convertido para o tipo de retorno.

Como o C++ permite sobrecarga, se você incluir, \<cmath> poderá chamar sobrecargas de **nextafter** e **nexttoward** que retornam **`float`** e **`long double`** tipos. Em um programa C, a menos que você esteja usando a \<tgmath.h> macro para chamar essa função, **nextafter** e **nexttoward** sempre retornam **`double`** .

Se você usar a \<tgmath.h> `nextafter()` `nexttoward()` macro ou, o tipo do argumento determinará qual versão da função está selecionada. Consulte [tipo-matemática genérica](../../c-runtime-library/tgmath.md) para obter detalhes.

As funções **_nextafter** e **_nextafterf** são específicas da Microsoft. A função **_nextafterf** só está disponível durante a compilação para x64.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|-------------|---------------------------|-------------------------------|
|**nextafter**, **nextafterf**, **nextafterl**, **_nextafterf**, **nexttoward**, **nexttowardf**, **nexttowardl**|\<math.h>|\<math.h> ou \<cmath>|
|**_nextafter**|\<float.h>|\<float.h> ou \<cfloat>|
|macro **nextafter** , macro **nexttoward**| \<tgmath.h> ||

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)\
[isnan, _isnan, _isnanf](isnan-isnan-isnanf.md)
