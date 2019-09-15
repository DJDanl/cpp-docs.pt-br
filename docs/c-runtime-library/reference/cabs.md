---
title: _cabs
ms.date: 11/04/2016
api_name:
- _cabs
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
- cabsl
- _cabs
- _cabsl
helpviewer_keywords:
- cabs function
- cabsl function
- absolute values
- _cabsl function
- _cabs function
- calculating absolute values
ms.assetid: fea292ee-1a39-4a0a-b416-4a189346ff26
ms.openlocfilehash: 5e2536fbeed2f466d3795e2ed26e643279e8bc67
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70943418"
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

## <a name="return-value"></a>Valor de retorno

**_cabs** retorna o valor absoluto de seu argumento, se for bem-sucedido. Em Overflow, **_cabs** retorna **HUGE_VAL** e define **errno** como **ERANGE**. Você pode alterar o tratamento de erro com [_matherr](matherr.md).

## <a name="remarks"></a>Comentários

A função **_cabs** calcula o valor absoluto de um número complexo, que deve ser uma estrutura do tipo [_complex](../../c-runtime-library/standard-types.md). A estrutura *z* é composta por um componente real *x* e um componente imaginário de *y*. Uma chamada para **_cabs** produz um valor equivalente ao da expressão `sqrt( z.x * z.x + z.y * z.y )`.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_cabs**|\<math.h>|

Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[abs, labs, llabs, _abs64](abs-labs-llabs-abs64.md)<br/>
[fabs, fabsf, fabsl](fabs-fabsf-fabsl.md)