---
title: SINH, sinhf, sinhl | Microsoft Docs
ms.custom: ''
ms.date: 04/10/2018
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- sinhl
- sinhf
- sinhl
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
- sinh
- sinhf
- sinhl
dev_langs:
- C++
helpviewer_keywords:
- sinh function
- sinhl function
- sinhf function
- calculating hyperbolic sines
- trigonometric functions
- sinhf function
- sinhl function
- hyperbolic functions
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 220bbeb1d78957be153e23b578f217c8098f7e7d
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32410457"
---
# <a name="sinh-sinhf-sinhl"></a>SINH, sinhf, sinhl

Calcula o seno hiperbólico.

## <a name="syntax"></a>Sintaxe

```C
double sinh(double x);
float sinhf(float x);
long double sinhl(long double x);
```

```cpp
float sinh(float x);  // C++ only
long double sinh(long double x);  // C++ only
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Ângulo em radianos.

## <a name="return-value"></a>Valor de retorno

O **sinh** funções retornam o seno hiperbólico de *x*. Por padrão, se o resultado é muito grande, **sinh** define **errno** para **ERANGE** e retorna ±**HUGE_VAL**.

|Entrada|Exceção SEH|Exceção Matherr|
|-----------|-------------------|-----------------------|
|± QNAN,IND|Nenhum|_DOMAIN|
|&#124;x&#124; ≥ 7.104760e + 002|OVERFLOW+INEXACT|OVERFLOW|

Para obter mais informações sobre os códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **sinh** que levar e retornar **float** ou **longo** **duplo** valores. Em um programa C, **sinh** sempre usa e retorna **duplo**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|-|-|-|
|**SINH**, **sinhf**, **sinhl**|\<math.h>|\<cmath> ou \<math.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_sinhcosh.c
// This program displays the hyperbolic
// sine and hyperbolic cosine of pi / 2.
// Compile by using: cl /W4 crt_sinhcosh.c

#include <math.h>
#include <stdio.h>

int main( void)
{
   double pi = 3.1415926535;
   double x, y;

   x = pi / 2;
   y = sinh( x );
   printf( "sinh( %f ) = %f\n",x, y );
   y = cosh( x );
   printf( "cosh( %f ) = %f\n",x, y );
}
```

```Output
sinh( 1.570796 ) = 2.301299
cosh( 1.570796 ) = 2.509178
```

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[acosh, acoshf, acoshl](acosh-acoshf-acoshl.md)<br/>
[asinh, asinhf, asinhl](asinh-asinhf-asinhl.md)<br/>
[atanh, atanhf, atanhl](atanh-atanhf-atanhl.md)<br/>
[cosh, coshf, coshl](cosh-coshf-coshl.md)<br/>
[tanh, tanhf, tanhl](tanh-tanhf-tanhl.md)<br/>
