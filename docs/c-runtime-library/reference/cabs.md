---
title: _cabs
ms.date: 4/2/2020
api_name:
- _cabs
- _o__cabs
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
- _cabs
helpviewer_keywords:
- cabs function
- absolute values
- _cabs function
- calculating absolute values
ms.assetid: fea292ee-1a39-4a0a-b416-4a189346ff26
ms.openlocfilehash: 6e769d2caf65ef3c084bcb6add701f78b03a1b17
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82913348"
---
# <a name="_cabs"></a>_cabs

Calcula o valor absoluto de um número complexo.

## <a name="syntax"></a>Sintaxe

```C
double _cabs(
   struct _complex z
);
```

### <a name="parameters"></a>Parâmetros

*z*<br/>
Número complexo.

## <a name="return-value"></a>Valor retornado

**_cabs** retornará o valor absoluto de seu argumento se for bem-sucedido. Em Overflow, **_cabs** retorna **HUGE_VAL** e define **errno** como **ERANGE**. Você pode alterar o tratamento de erro com [_matherr](matherr.md).

## <a name="remarks"></a>Comentários

A função **_cabs** calcula o valor absoluto de um número complexo, que deve ser uma estrutura do tipo [_complex](../../c-runtime-library/standard-types.md). A estrutura *z* é composta por um componente real *x* e um componente imaginário de *y*. Uma chamada para **_cabs** produz um valor equivalente ao da expressão `sqrt( z.x * z.x + z.y * z.y )`.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_cabs**|\<math.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_cabs.c
// Using _cabs, this program calculates
// the absolute value of a complex number.

#include <math.h>
#include <stdio.h>

int main( void )
{
   struct _complex number = { 3.0, 4.0 };
   double d;

   d = _cabs( number );
   printf( "The absolute value of %f + %fi is %f\n",
           number.x, number.y, d );
}
```

```Output
The absolute value of 3.000000 + 4.000000i is 5.000000
```

## <a name="see-also"></a>Confira também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[abs, labs, llabs, _abs64](abs-labs-llabs-abs64.md)<br/>
[fabs, fabsf, fabsl](fabs-fabsf-fabsl.md)
