---
title: frexp, frexpf, frexpl
description: Referência de API para frexp, frexpf e frexpl; que obtém o mantissa e o expoente de um número de ponto flutuante.
ms.date: 9/1/2020
api_name:
- frexp
- _o_frexp
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
- frexp
- _frexpl
helpviewer_keywords:
- _frexpl function
- mantissas, floating-point variables
- frexpl function
- exponent, floating-point numbers
- frexp function
- floating-point functions, mantissa and exponent
ms.assetid: 9b020f2e-3967-45ec-a6a8-d467a071aa55
ms.openlocfilehash: a23de4160abcfab2518125bfa0fd35a389901674
ms.sourcegitcommit: 4ed2d68634eb2fb77e18110a2d26bc0008be369c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/08/2020
ms.locfileid: "89555742"
---
# <a name="frexp-frexpf-frexpl"></a>frexp, frexpf, frexpl

Obtém a mantissa e expoente de um número de ponto flutuante.

## <a name="syntax"></a>Sintaxe

```C
double frexp(
   double x,
   int *expptr
);
float frexpf(
   float x,
   int * expptr
);
long double frexpl(
   long double x,
   int * expptr
);
#define frexpl(X, INT_PTR) // Requires C11 or higher
```

```cpp
float frexp(
   float x,
   int * expptr
);  // C++ only
long double frexp(
   long double x,
   int * expptr
);  // C++ only
```

### <a name="parameters"></a>Parâmetros

*w.x.y.*\
Valor de ponto flutuante.

*expptr*\
Ponteiro para o expoente inteiro armazenado.

## <a name="return-value"></a>Valor Retornado

**frexp** retorna o mantissa. Se *x* for 0, a função retornará 0 para o mantissa e o expoente. Se *expptr* for **NULL**, o manipulador de parâmetro inválido será invocado conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essa função definirá **errno** como **EINVAL** e retornará 0.

## <a name="remarks"></a>Comentários

A função **frexp** divide o valor de ponto flutuante (*x*) em um mantissa (*m*) e um expoente (*n*), de modo que o valor absoluto de *m* seja maior ou igual a 0,5 e menor que 1,0 e *x*  =  *m* * 2<sup>*n*</sup>. O expoente inteiro *n* é armazenado no local apontado por *expptr*.

O C++ permite sobrecarga, portanto, você pode chamar sobrecargas de **frexp**. Em um programa C, a menos que você esteja usando a \<tgmath.h> macro para chamar essa função, **frexp** sempre pega um **`double`** **`int`** ponteiro e retorna um **`double`** .

Se você usar a \<tgmath.h> `frexp()` macro, o tipo do argumento determinará qual versão da função está selecionada. Consulte [tipo-matemática genérica](../../c-runtime-library/tgmath.md) para obter detalhes.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**frexp**, **frexpf**, **frexpl**|\<math.h>|
|macro **frexp** | \<tgmath.h> |

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_frexp.c
// This program calculates frexp( 16.4, &n )
// then displays y and n.

#include <math.h>
#include <stdio.h>

int main( void )
{
   double x, y;
   int n;

   x = 16.4;
   y = frexp( x, &n );
   printf( "frexp( %f, &n ) = %f, n = %d\n", x, y, n );
}
```

```Output
frexp( 16.400000, &n ) = 0.512500, n = 5
```

## <a name="see-also"></a>Confira também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[ldexp](ldexp.md)<br/>
[modf, modff, modfl](modf-modff-modfl.md)<br/>
