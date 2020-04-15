---
title: asin, asinf, asinl
ms.date: 4/2/2020
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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: 424fee6995fae4a7f878054ede1bb85d33d1706d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81334126"
---
# <a name="asin-asinf-asinl"></a>asin, asinf, asinl

Calcula o arco seno.

## <a name="syntax"></a>Sintaxe

```C
double asin( double x );
float asinf ( float x );
long double asinl( long double x );
```

```cpp
float asin( float x );  // C++ only
long double asin( long double x );  // C++ only
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Valor cujo arco seno é calculado.

## <a name="return-value"></a>Valor retornado

A função **asin** retorna o arco (a função seno inversa) de *x* na faixa -π/2 a π/2 radianos.

Por padrão, se *x* for menor que -1 ou maior que 1, **como in** retorna por tempo indeterminado.

|Entrada|Exceção SEH|Exceção Matherr|
|-----------|-------------------|-----------------------|
|± ∞|**Inválido**|**_DOMAIN**|
|± **QNAN,** **IND**|none|**_DOMAIN**|
|&#124;x&#124;>1|**Inválido**|**_DOMAIN**|

## <a name="remarks"></a>Comentários

Como c++ permite sobrecarga, você pode chamar sobrecargas de **asin** com **flutuação** e valores **duplos** **longos.** Em um programa C, **como sempre** leva e retorna um **duplo**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|-------------|---------------------|-|
|**asin,** **asinf,** **asinl**|\<math.h>|\<cmath> ou \<math.h>|

## <a name="example"></a>Exemplo

Para obter mais informações, consulte [acos, acosf, acosl](acos-acosf-acosl.md).

## <a name="see-also"></a>Confira também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[acos, acosf, acosl](acos-acosf-acosl.md)<br/>
[atan, atanf, atanl, atan2, atan2f, atan2l](atan-atanf-atanl-atan2-atan2f-atan2l.md)<br/>
[cos, cosf, cosl](cos-cosf-cosl.md)<br/>
[_matherr](matherr.md)<br/>
[sin, sinf, sinl](sin-sinf-sinl.md)<br/>
[tan, tanf, tanl](tan-tanf-tanl.md)<br/>
