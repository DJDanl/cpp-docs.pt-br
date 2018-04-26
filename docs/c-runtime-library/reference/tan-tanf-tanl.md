---
title: tan, tanf, tanl | Microsoft Docs
ms.custom: ''
ms.date: 04/10/2018
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- tan
- tanf
- tanl
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
- tan
- tanf
- _tanl
- tanl
dev_langs:
- C++
helpviewer_keywords:
- tanl function
- _tanl function
- tan function
- calculating tangents
- tangent
- tanf function
- trigonometric functions
ms.assetid: 36cc0ce8-9c80-4653-b354-ddb3b378b6bd
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0dc25d2e197f31cce332b4cea67d8ba1c132bf42
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="tan-tanf-tanl"></a>Marrom-Claro, tanf, tanl

Calcula a tangente.

## <a name="syntax"></a>Sintaxe

```C
double tan( double x );
float tanf( float x );
long double tanl( long double x );
```

```cpp
float tan( float x );  // C++ only
long double tan( long double x );  // C++ only
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Ângulo em radianos.

## <a name="return-value"></a>Valor retornado

O **tan** funções retornam a tangente do *x*. Se *x* é maior que ou igual a 263 ou menor que ou igual a -263, ocorre uma perda de significância no resultado.

|Entrada|Exceção SEH|**Matherr** exceção|
|-----------|-------------------|-------------------------|
|± QNAN,IND|nenhum|_DOMAIN|
|± INF|**INVÁLIDO**|_DOMAIN|

## <a name="remarks"></a>Comentários

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **tan** que levar e retornar **float** ou **longo** **duplo** valores. Em um programa C, **tan** sempre usa e retorna **duplo**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|-------------|---------------------|-|
|**tan**, **tanf**, **tanl**|\<math.h>|\<cmath> ou \<math.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_tan.c
// This program displays the tangent of pi / 4
// Compile by using: cl crt_tan.c

#include <math.h>
#include <stdio.h>

int main( void )
{
   double pi = 3.1415926535;
   double x;

   x = tan( pi / 4 );
   printf( "tan( %f ) = %f\n", pi/4, x );
}
```

```Output
tan( 0.785398 ) = 1.000000
```

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[acos, acosf, acosl](acos-acosf-acosl.md)<br/>
[asin, asinf, asinl](asin-asinf-asinl.md)<br/>
[atan, atanf, atanl, atan2, atan2f, atan2l](atan-atanf-atanl-atan2-atan2f-atan2l.md)<br/>
[cos, cosf, cosl](cos-cosf-cosl.md)<br/>
[sin, sinf, sinl](sin-sinf-sinl.md)<br/>
[_CItan](../../c-runtime-library/citan.md)<br/>