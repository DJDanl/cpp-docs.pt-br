---
title: cos, cosf, cosl
description: Referência de API para cos, cosf e COSL; que calculam o valor do cosseno de um número de ponto flutuante.
ms.date: 08/31/2020
api_name:
- cos
- cosf
- cosl
- _o_cos
- _o_cosf
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
- cos
- cosf
- cosl
helpviewer_keywords:
- cosines
- cosl function
- calculating cosine
- cosf function
- cos function
- trigonometric functions
- cosines, calculating
ms.assetid: ae90435e-6b68-4a47-a81f-be87d5c08f16
ms.openlocfilehash: b0e723708076067cf4d2ed896542ac08406a87ee
ms.sourcegitcommit: 4ed2d68634eb2fb77e18110a2d26bc0008be369c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/08/2020
ms.locfileid: "89556795"
---
# <a name="cos-cosf-cosl"></a>cos, cosf, cosl

Calcula o cosseno.

## <a name="syntax"></a>Sintaxe

```C
double cos( double x );
float cosf( float x );
long double cosl( long double x );
#define cos(X) // Requires C11 or higher

float cos( float x );  // C++ only
long double cos( long double x );  // C++ only
```

### <a name="parameters"></a>Parâmetros

*w.x.y.*\
Ângulo em radianos.

## <a name="return-value"></a>Valor Retornado

O cosseno de *x*. Se *x* for maior ou igual a 263, ou menor ou igual a-263, uma perda de significância no resultado ocorrerá.

|Entrada|Exceção SEH|Exceção Matherr|
|-----------|-------------------|-----------------------|
|± QNAN, IND|nenhum|**_DOMAIN**|
|± INF|**Inválido**|**_DOMAIN**|

## <a name="remarks"></a>Comentários

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **cos** que usam e retornam **`float`** **`long double`** valores. Em um programa C, a menos que você esteja usando a \<tgmath.h> macro para chamar essa função, o **cos** sempre toma e retorna um **`double`** .

Se você usar a \<tgmath.h> `cos()` macro, o tipo do argumento determinará qual versão da função está selecionada. Consulte [tipo-matemática genérica](../../c-runtime-library/tgmath.md) para obter detalhes.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho C necessário|Cabeçalho C++ necessário|
|-------------|---------------------|-|
|**cos**, **cosh**, **cosf**|\<math.h>|\<cmath> ou \<math.h>|
|macro **cos ()** | \<tgmath.h> ||

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo em [sin, sinf, sinl](sin-sinf-sinl.md).

## <a name="see-also"></a>Confira também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[acos, acosf, acosl](acos-acosf-acosl.md)<br/>
[asin, asinf, asinl](asin-asinf-asinl.md)<br/>
[atan, atanf, atanl, atan2, atan2f, atan2l](atan-atanf-atanl-atan2-atan2f-atan2l.md)<br/>
[_matherr](matherr.md)<br/>
[sin, sinf, sinl](sin-sinf-sinl.md)<br/>
[tan, tanf, tanl](tan-tanf-tanl.md)<br/>
[_CIcos](../../c-runtime-library/cicos.md)<br/>
