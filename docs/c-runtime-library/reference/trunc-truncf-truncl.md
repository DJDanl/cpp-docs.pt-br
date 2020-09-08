---
title: trunc, truncf, truncl
description: Referência de API para truncamento, truncf, truncl; que determinam o número inteiro mais próximo que é menor ou igual ao valor de ponto flutuante especificado.
ms.date: 9/1/2020
api_name:
- trunc
- truncf
- truncl
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
- trunc
- truncf
- truncl
- math/trunc
- math/truncf
- math/truncl
helpviewer_keywords:
- trunc function
- truncf function
- truncl function
ms.assetid: de2038ac-ac0b-483e-870c-e8992dcd4fd0
ms.openlocfilehash: f1f2fde95bb944aa461bb95a9ad30fac204552b9
ms.sourcegitcommit: 4ed2d68634eb2fb77e18110a2d26bc0008be369c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/08/2020
ms.locfileid: "89556626"
---
# <a name="trunc-truncf-truncl"></a>trunc, truncf, truncl

Determina o inteiro mais próximo que é menor ou igual ao valor de ponto flutuante especificado.

## <a name="syntax"></a>Sintaxe

```C
double trunc( double x );
long double truncl( long double x );
#define trunc(X) // Requires C11 or higher

long double trunc( long double x ); //C++ only
float trunc( float x ); //C++ only
```

### <a name="parameters"></a>Parâmetros

*w.x.y.*\
O valor a ser truncado.

## <a name="return-value"></a>Valor Retornado

Se for bem-sucedido, retorna um valor inteiro de *x*, arredondado para zero.

Caso contrário, pode retornar um dos seguintes:

|Problema|Retorno|
|-----------|------------|
|*x* = ± infinito|x|
|*x* = ± 0|x|
|*x* = Nan|NaN|

Os erros são relatados conforme especificado em [_matherr](matherr.md).

## <a name="remarks"></a>Comentários

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **truncar** que usam e retornam **`float`** **`long double`** tipos. Em um programa C, a menos que você esteja usando a \<tgmath.h> macro para chamar essa função, **trunc** sempre pega e retorna um **`double`** .

Se você usar a \<tgmath.h> `trunc()` macro, o tipo do argumento determinará qual versão da função está selecionada. Consulte [tipo-matemática genérica](../../c-runtime-library/tgmath.md) para obter detalhes.

Como os maiores valores de ponto flutuantes são inteiros exatos, essa função não estourará por conta própria. No entanto, você pode causar o estouro, retornando um valor para um tipo inteiro.

Você também pode arredondar para baixo pela conversão implícita de ponto flutuante para integral; no entanto, isso é limitado aos valores que podem ser armazenados no tipo de destino.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**truncar**, **truncf**, **truncl**|\<math.h>|\<cmath>|
|macro **truncar** | \<tgmath.h> ||

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Referência de função alfabética](crt-alphabetical-function-reference.md)<br/>
[floor, floorf, floorl](floor-floorf-floorl.md)<br/>
[ceil, ceilf, ceill](ceil-ceilf-ceill.md)<br/>
[round, roundf, roundl](round-roundf-roundl.md)<br/>
