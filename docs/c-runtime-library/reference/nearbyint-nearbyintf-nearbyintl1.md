---
title: nearbyint, nearbyintf, nearbyintl
ms.date: 4/2/2020
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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: 92e3a744ef8069d45733c06b7a2681905c3eab55
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81338584"
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

## <a name="return-value"></a>Valor retornado

Se for bem-sucedido, retorna *x*, arredondado para o inteiro mais próximo, utilizando o formato de arredondamento atual conforme relatado pela [fegetround](fegetround-fesetround2.md). Caso contrário, a função pode retornar um dos seguintes valores:

|Problema|Retorno|
|-----------|------------|
|*x* = ±INFINITO|±INFINITY, sem modificações|
|*x* = ±0|±0, sem modificações|
|*x* = NaN|NaN|

Erros não são relatados através [de _matherr;](matherr.md) especificamente, esta função não reporta nenhuma **exceção FE_INEXACT.**

## <a name="remarks"></a>Comentários

A principal diferença entre esta função e [rint](rint-rintf-rintl.md) é que esta função não aumenta a exceção de ponto flutuante inexato.

Como os valores máximos de ponto flutuante são inteiros exatos, essa função nunca estourará sozinha. Em vez disso, a saída pode estourar o valor retornado, dependendo da versão da função que você usar.

C++ permite sobrecarga, para que você possa chamar sobrecargas de **nearbyint** que tomam e retornam **flutuam** **ou** longos parâmetros **duplos.** Em um programa C, **o próximo** sempre leva dois valores duplos e retorna um valor duplo.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**nearbyint**, **nearbyintf**, **nearbyintl**|\<math.h>|\<cmath> ou \<math.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[Suporte matemático e de ponto flutuante](../floating-point-support.md)<br/>
