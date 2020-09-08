---
title: asin, asinf, asinl
description: Referência de API para Asen, asinf e asenl; que calcula o arco seno de um valor de ponto flutuante.
ms.date: 08/31/2020
api_name:
- asinf
- asinl
- asin
- _o_asin
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
- asin
- asinl
- asinf
helpviewer_keywords:
- asin function
- asinl function
- asinf function
- trigonometric functions
- arcsine function
ms.assetid: ca05f9ea-b711-49f6-9f32-2f4019abfd69
ms.openlocfilehash: 7167debcfb605ab05720d9441943439ea9982324
ms.sourcegitcommit: 4ed2d68634eb2fb77e18110a2d26bc0008be369c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/08/2020
ms.locfileid: "89556652"
---
# <a name="asin-asinf-asinl"></a>asin, asinf, asinl

Calcula o arco seno.

## <a name="syntax"></a>Sintaxe

```C
double asin( double x );
float asinf ( float x );
long double asinl( long double x );
#define asin(X) // Requires C11 or higher

float asin( float x );  // C++ only
long double asin( long double x );  // C++ only
```

### <a name="parameters"></a>Parâmetros

*w.x.y.*\
Valor cujo arco seno é calculado.

## <a name="return-value"></a>Valor Retornado

A função **Asen** retorna o arco seno (a função de seno inversa) de *x* no intervalo de-π/2 a π/2 radianos.

Por padrão, se *x* for menor que-1 ou maior que 1, **Asen** retornará um indefinido.

|Entrada|Exceção SEH|Exceção Matherr|
|-----------|-------------------|-----------------------|
|± ∞|**Inválido**|**_DOMAIN**|
|± **QNAN**, **Ind**|nenhum|**_DOMAIN**|
|&#124;x&#124;>1|**Inválido**|**_DOMAIN**|

## <a name="remarks"></a>Comentários

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **Asen** com **`float`** valores e **`long double`** . Em um programa C, a menos que você esteja usando a \<tgmath.h> macro para chamar essa função, **Asen** sempre pega e retorna um **`double`** .

Se você usar a \<tgmath.h> `asin()` macro, o tipo do argumento determinará qual versão da função está selecionada. Consulte [tipo-matemática genérica](../../c-runtime-library/tgmath.md) para obter detalhes.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|-------------|---------------------|-|
|**Asen**, **asinf**, **asenl**|\<math.h>|\<cmath> ou \<math.h>|
|macro **Asen ()** | \<tgmath.h> ||

## <a name="example"></a>Exemplo

Para obter mais informações, consulte [acos, acosf, acosl](acos-acosf-acosl.md).

## <a name="see-also"></a>Confira também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[acos, acosf, acosl](acos-acosf-acosl.md)<br/>
[atan, atanf, atanl, atan2, atan2f, atan2l](atan-atanf-atanl-atan2-atan2f-atan2l.md)<br/>
[cos, cosf, cosl](cos-cosf-cosl.md)<br/>
[_matherr](matherr.md)<br/>
[sin, sinf, sinl](sin-sinf-sinl.md)<br/>
[tan, tanf, tanl](tan-tanf-tanl.md)<br/>
