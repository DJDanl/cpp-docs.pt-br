---
title: hypot, hypotf, hypotl, _hypot, _hypotf, _hypotl
ms.date: 04/05/2018
apiname:
- _hypotf
- hypot
- hypotf
- _hypot
- _hypotl
- hypotl
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
- hypotf
- hypotl
- _hypotl
- hypot
- _hypot
- _hypotf
helpviewer_keywords:
- hypotenuse calculation
- hypot function
- hypotf function
- triangles, calculating hypotenuse
- hypotl function
- calculating hypotenuses
- _hypot function
ms.assetid: 6a13887f-bd53-43fc-9d77-5b42d6e49925
ms.openlocfilehash: ea25ea87a0ec23a0e98dbdc7bb92ce691fc2fa0f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62157390"
---
# <a name="hypot-hypotf-hypotl-hypot-hypotf-hypotl"></a>hypot, hypotf, hypotl, _hypot, _hypotf, _hypotl

Calcula a hipotenusa.

## <a name="syntax"></a>Sintaxe

```C
double hypot(
   double x,
   double y
);
float hypotf(
   float x,
   float y
);
long double hypotl(
   long double x,
   long double y
);
double _hypot(
   double x,
   double y
);
float _hypotf(
   float x,
   float y
);
long double _hypotl(
   long double x,
   long double y
);
```

### <a name="parameters"></a>Parâmetros

*x*, *y*<br/>
Valores de ponto flutuante.

## <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, **hypot** retorna o comprimento da hipotenusa, no estouro, **hypot** retorna INF (infinito) e o **errno** variável é definida como **ERANGE** . Você pode usar **matherr** para modificar o tratamento de erros.

Para obter mais informações sobre os códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **hypot** funções calculam o comprimento da hipotenusa de um triângulo retângulo, dado o comprimento dos dois lados *x* e *y* (em outras palavras, a raiz quadrada de *x*<sup>2</sup> + *y*<sup>2</sup>).

As versões das funções que têm sublinhados iniciais são fornecidas para compatibilidade com os padrões anteriores. Seu comportamento é idêntico ao das versões que não têm sublinhados iniciais. É recomendável usar as versões sem sublinhados iniciais para o novo código.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**hypot**, **hypotf**, **hypotl**, **_hypot**, **_hypotf**, **_hypotl**|\<math.h>|

Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_hypot.c
// This program prints the hypotenuse of a right triangle.

#include <math.h>
#include <stdio.h>

int main( void )
{
   double x = 3.0, y = 4.0;

   printf( "If a right triangle has sides %2.1f and %2.1f, "
           "its hypotenuse is %2.1f\n", x, y, _hypot( x, y ) );
}
```

```Output
If a right triangle has sides 3.0 and 4.0, its hypotenuse is 5.0
```

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[_cabs](cabs.md)<br/>
[_matherr](matherr.md)<br/>