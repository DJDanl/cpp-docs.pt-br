---
title: nextafter, nextafterf, nextafterl, _nextafter, _nextafterf, nexttoward, nexttowardf, nexttowardl | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- nextafterf
- _nextafterf
- nextafter
- nextafterl
- _nextafter
- nexttoward
- nexttowardf
- nexttowardl
apilocation:
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
apitype: DLLExport
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
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9c68d039ff1318ea082d409078a55c8d337a48de
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32403710"
---
# <a name="nextafter-nextafterf-nextafterl-nextafter-nextafterf-nexttoward-nexttowardf-nexttowardl"></a>nextafter, nextafterf, nextafterl, _nextafter, _nextafterf, nexttoward, nexttowardf, nexttowardl

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

## <a name="return-value"></a>Valor de retorno

Retorna o próximo valor de ponto flutuante representável do tipo de retorno após *x* na direção do *y*. Se *x* e *y* forem iguais, a função retorna *y*, convertido para o tipo de retorno, com nenhuma exceção acionada. Se *x* não é igual a *y*, e o resultado é um anormal ou zero, o **FE_UNDERFLOW** e **FE_INEXACT** estados de exceção de ponto flutuante são definidos, e o resultado correto é retornado. Se qualquer um dos *x* ou *y* é um NAN, em seguida, o valor de retorno é um dos NANs de entrada. Se *x* é finito e o resultado é infinito ou não representável no tipo, um assinados corretamente infinity ou NAN será retornado, o **FE_OVERFLOW** e **FE_INEXACT** estados de exceção de ponto flutuante são definidos, e **errno** é definido como **ERANGE**.

## <a name="remarks"></a>Comentários

O **nextafter** e **nexttoward** famílias de função são equivalentes, exceto o tipo de parâmetro *y*. Se *x* e *y* forem iguais, o valor retornado é *y* convertido para o tipo de retorno.

Como o C++ permite sobrecarga, se você incluir \<cmath > você pode chamar sobrecargas de **nextafter** e **nexttoward** que retornam **float** e **longo** **duplo** tipos. Em um programa C, **nextafter** e **nexttoward** sempre retornam **duplo**.

O **nextafter** e **_nextafterf** funções são específicas da Microsoft. O **_nextafterf** função está disponível somente quando se estiver compilando para x64.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|-------------|---------------------------|-------------------------------|
|**nextafter**, **nextafterf**, **nextafterl**, **_nextafterf**, **nexttoward**, **nexttowardf** , **nexttowardl**|\<math.h>|\<math.h> ou \<cmath>|
|**_nextafter**|\<float.h>|\<float.h> ou \<cfloat>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[isnan, _isnan, _isnanf](isnan-isnan-isnanf.md)<br/>
