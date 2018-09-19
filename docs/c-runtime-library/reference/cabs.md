---
title: _cabs | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _cabs
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
- cabsl
- _cabs
- _cabsl
dev_langs:
- C++
helpviewer_keywords:
- cabs function
- cabsl function
- absolute values
- _cabsl function
- _cabs function
- calculating absolute values
ms.assetid: fea292ee-1a39-4a0a-b416-4a189346ff26
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: cad3c873dd7e0bab2a7b75e785fb91c704e616de
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46085272"
---
# <a name="cabs"></a>_cabs

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

**CABs** retorna o valor absoluto do argumento se for bem-sucedido. No estouro, **CABs** retorna **HUGE_VAL** e define **errno** para **ERANGE**. Você pode alterar o tratamento de erro com [_matherr](matherr.md).

## <a name="remarks"></a>Comentários

O **CABs** função calcula o valor absoluto de um número complexo, que deve ser uma estrutura do tipo [Complex](../../c-runtime-library/standard-types.md). A estrutura *z* é composto de um componente real *x* e um componente imaginário *y*. Uma chamada para **CABs** produz um valor equivalente da expressão `sqrt( z.x * z.x + z.y * z.y )`.

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