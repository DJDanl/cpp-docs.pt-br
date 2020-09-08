---
title: nearbyint, nearbyintf, nearbyintl
description: Referência de API para nearbyint, nearbyintf e nearbyintl; que arredonda o valor de ponto flutuante especificado para um número inteiro e retorna esse valor em um formato de ponto flutuante.
ms.date: 9/1/2020
api_name:
- nearbyint
- nearbyintf
- nearbyintl
- _o_nearbyint
- _o_nearbyintf
- _o_nearbyintl
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
ms.openlocfilehash: 9717559518032c6f1f2126c7ded7cb90603bce64
ms.sourcegitcommit: 4ed2d68634eb2fb77e18110a2d26bc0008be369c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/08/2020
ms.locfileid: "89556379"
---
# <a name="nearbyint-nearbyintf-nearbyintl"></a>nearbyint, nearbyintf, nearbyintl

Arredonda o valor especificado de ponto flutuante para um inteiro e retorna esse valor em um formato de ponto flutuante.

## <a name="syntax"></a>Sintaxe

```C
double nearbyint( double x );
float nearbyintf( float x );
long double nearbyintl( long double x );
#define nearbyint( X ) // Requires C11 or higher

float nearbyint( float x ); //C++ only
long double nearbyint( long double x ); //C++ only
```

### <a name="parameters"></a>Parâmetros

*w.x.y.*\
O valor a ser arredondado.

## <a name="return-value"></a>Valor Retornado

Se for bem-sucedido, retorna *x*, arredondado para o número inteiro mais próximo, usando o formato de arredondamento atual conforme relatado por [fegetround](fegetround-fesetround2.md). Caso contrário, a função pode retornar um dos seguintes valores:

|Problema|Retorno|
|-----------|------------|
|*x* = ± infinito|±INFINITY, sem modificações|
|*x* = ± 0|±0, sem modificações|
|*x* = Nan|NaN|

Os erros não são relatados por meio de [_matherr](matherr.md); especificamente, essa função não relata nenhuma exceção **FE_INEXACT** .

## <a name="remarks"></a>Comentários

A principal diferença entre essa função e [rimir](rint-rintf-rintl.md) é que essa função não gera a exceção de ponto flutuante inexata.

Como os valores máximos de ponto flutuante são inteiros exatos, essa função nunca estourará sozinha. Em vez disso, a saída pode estourar o valor retornado, dependendo da versão da função que você usar.

O C++ permite sobrecarga, portanto, você pode chamar sobrecargas de **nearbyint** que usam e retornam **`float`** **`long double`** parâmetros. Em um programa C, a menos que você esteja usando a \<tgmath.h> macro para chamar essa função, **nearbyint** sempre usa dois valores double e retorna um valor Double.

Se você usar a \<tgmath.h> `nearbyint()` macro, o tipo do argumento determinará qual versão da função está selecionada. Consulte [tipo-matemática genérica](../../c-runtime-library/tgmath.md) para obter detalhes.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**nearbyint**, **nearbyintf**, **nearbyintl**|\<math.h>|\<cmath> ou \<math.h>|
|macro **nearbyint** | \<tgmath.h> ||

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Referência de função alfabética](crt-alphabetical-function-reference.md)<br/>
[Suporte matemático e de ponto flutuante](../floating-point-support.md)<br/>
