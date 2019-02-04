---
title: Primitivos de ponto flutuantes
ms.date: 01/31/2019
apiname:
- _dclass
- _ldclass
- _fdclass
- _dsign
- _ldsign
- _fdsign
- _dpcomp
- _ldpcomp
- _fdpcomp
- _dtest
- _ldtest
- _fdtest
- _d_int
- _ld_int
- _fd_int
- _dscale
- _ldscale
- _fdscale
- _dunscale
- _ldunscale
- _fdunscale
- _dexp
- _ldexp
- _fdexp
- _dnorm
- _fdnorm
- _dpoly
- _ldpoly
- _fdpoly
- _dlog
- _ldlog
- _fdlog
- _dsin
- _ldsin
- _fdsin
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
- _dclass
- _ldclass
- _fdclass
- _dsign
- _ldsign
- _fdsign
- _dpcomp
- _ldpcomp
- _fdpcomp
- _dtest
- _ldtest
- _fdtest
- _d_int
- _ld_int
- _fd_int
- _dscale
- _ldscale
- _fdscale
- _dunscale
- _ldunscale
- _fdunscale
- _dexp
- _ldexp
- _fdexp
- _dnorm
- _fdnorm
- _dpoly
- _ldpoly
- _fdpoly
- _dlog
- _ldlog
- _fdlog
- _dsin
- _ldsin
- _fdsin
helpviewer_keywords:
- _dclass
- _ldclass
- _fdclass
- _dsign
- _ldsign
- _fdsign
- _dpcomp
- _ldpcomp
- _fdpcomp
- _dtest
- _ldtest
- _fdtest
- _d_int
- _ld_int
- _fd_int
- _dscale
- _ldscale
- _fdscale
- _dunscale
- _ldunscale
- _fdunscale
- _dexp
- _ldexp
- _fdexp
- _dnorm
- _fdnorm
- _dpoly
- _ldpoly
- _fdpoly
- _dlog
- _ldlog
- _fdlog
- _dsin
- _ldsin
- _fdsin
ms.openlocfilehash: 230d0def145bcb443437b59303b2b36e348da2bb
ms.sourcegitcommit: e98671a4f741b69d6277da02e6b4c9b1fd3c0ae5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/04/2019
ms.locfileid: "55703401"
---
# <a name="floating-point-primitives"></a>Primitivos de ponto flutuantes

Funções primitivas específico da Microsoft que são usadas para implementar alguns padrão C runtime library (CRT) funções de ponto flutuante. Eles estão documentados aqui para fins de integridade, mas não são recomendados para uso. Algumas dessas funções são indicadas como não utilizado, pois elas são conhecidas por terem problemas na precisão, a manipulação de exceção e a conformidade com IEEE-754 comportamento. Eles existem na biblioteca do somente para compatibilidade com versões anteriores. Para o comportamento correto, portabilidade e adoção de padrões, prefira as funções de ponto flutuantes padrão dessas funções.

## <a name="dclass-ldclass-fdclass"></a>_dclass, _ldclass, _fdclass

### <a name="syntax"></a>Sintaxe

```C
short __cdecl _dclass(double x);
short __cdecl _ldclass(long double x);
short __cdecl _fdclass(float x);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Argumento da função de ponto flutuante.

### <a name="remarks"></a>Comentários

Esses primitivos de ponto flutuantes implementam as versões de C da macro do CRT [fpclassify](fpclassify.md) para tipos de ponto flutuante. A classificação do argumento *x* é retornado como uma das constantes, definidas em Math. h:

|Valor|Descrição|
|-----------|-----------------|
| **FP_NAN** | Um NaN silencioso, indeterminado ou com sinalização |
| **FP_INFINITE** | Um infinito positivo ou negativo |
| **FP_NORMAL** | Um valor positivo ou negativo normalizado diferente de zero |
| **FP_SUBNORMAL** | Um valor de (desnormalizado) subnormal positivo ou negativo |
| **FP_ZERO** | Um valor de zero positivo ou negativo |

Para obter mais detalhes, você pode usar o específico da Microsoft [fpclass, _fpclassf](fpclass-fpclassf.md) funções. Use o [fpclassify](fpclassify.md) macro ou função para fins de portabilidade.

## <a name="dsign-ldsign-fdsign"></a>_dsign, _ldsign, _fdsign

### <a name="syntax"></a>Sintaxe

```C
int __cdecl _dsign(double x);
int __cdecl _ldsign(long double x);
int __cdecl _fdsign(float x);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Argumento da função de ponto flutuante.

### <a name="remarks"></a>Comentários

Esses primitivos de ponto flutuantes é implementar o [signbit](signbit.md) macro ou função no CRT. Elas retornam um valor diferente de zero se o bit de sinal for definido em significando (mantissa) do argumento *x*e 0 se o bit de sinal não está definido.

## <a name="dpcomp-ldpcomp-fdpcomp"></a>_dpcomp, _ldpcomp, _fdpcomp

### <a name="syntax"></a>Sintaxe

```C
int __cdecl _dpcomp(double x, double y);
int __cdecl _ldpcomp(long double x, long double y);
int __cdecl _fdpcomp(float x, float y);
```

### <a name="parameters"></a>Parâmetros

*x*, *y*<br/>
Argumentos da função de ponto flutuante.

### <a name="remarks"></a>Comentários

Esses primitivos de ponto flutuantes usam dois argumentos, *x* e *y*e retornar um valor que mostra seu relacionamento de ordenação, expressado como o bit a bit ou de constantes, definidas em Math. h:

| Valor | Descrição |
|------------|-----------------|
| **_FP_LT** | *x* pode ser considerado menor que *y* |
| **_FP_EQ** | *x* pode ser considerado igual a *y* |
| **_FP_GT** | *x* pode ser considerado maior do que *y* |

Esses primitivos implementam o [isgreater, isgreaterequal, isless, islessequal, islessgreater e isunordered](floating-point-ordering.md) macros e funções no CRT.

## <a name="dtest-ldtest-fdtest"></a>_dtest, _ldtest, _fdtest

### <a name="syntax"></a>Sintaxe

```C
short __cdecl _dtest(double* px);
short __cdecl _ldtest(long double* px);
short __cdecl _fdtest(float* px);
```

### <a name="parameters"></a>Parâmetros

*px*<br/>
Ponteiro para um argumento de ponto flutuante.

### <a name="remarks"></a>Comentários

Esses primitivos de ponto flutuantes implementam as versões de C++ da função CRT [fpclassify](fpclassify.md) para tipos de ponto flutuante. O argumento *x* é avaliada e a classificação é retornada como uma das constantes, definidas em Math. h:

|Valor|Descrição|
|-----------|-----------------|
| **FP_NAN** | Um NaN silencioso, indeterminado ou com sinalização |
| **FP_INFINITE** | Um infinito positivo ou negativo |
| **FP_NORMAL** | Um valor positivo ou negativo normalizado diferente de zero |
| **FP_SUBNORMAL** | Um valor de (desnormalizado) subnormal positivo ou negativo |
| **FP_ZERO** | Um valor de zero positivo ou negativo |

Para obter mais detalhes, você pode usar o específico da Microsoft [fpclass, _fpclassf](fpclass-fpclassf.md) funções. Use o [fpclassify](fpclassify.md) função para fins de portabilidade.

## <a name="dint-ldint-fdint"></a>_d_int, _ld_int, _fd_int

### <a name="syntax"></a>Sintaxe

```C
short __cdecl _d_int(double* px, short exp);
short __cdecl _ld_int(long double* px, short exp);
short __cdecl _fd_int(float* px, short exp);
```

### <a name="parameters"></a>Parâmetros

*px*<br/>
Ponteiro para um argumento de ponto flutuante.

*exp*<br/>
Um expoente como um tipo integral.

### <a name="remarks"></a>Comentários

Esses primitivos de ponto flutuantes levam um ponteiro para um valor de ponto flutuante *px* e um valor de expoente *exp*e remova a parte fracionária do valor de ponto flutuante abaixo o expoente determinado, se possível . O valor retornado é o resultado de **fpclassify** no valor da entrada *px* se ele for um NaN ou infinito e no valor de saída na *px* caso contrário.

## <a name="dscale-ldscale-fdscale"></a>_dscale, _ldscale, _fdscale

### <a name="syntax"></a>Sintaxe

```C
short __cdecl _dscale(double* px, long exp);
short __cdecl _ldscale(long double* px, long exp);
short __cdecl _fdscale(float* px, long exp);
```

### <a name="parameters"></a>Parâmetros

*px*<br/>
Ponteiro para um argumento de ponto flutuante.

*exp*<br/>
Um expoente como um tipo integral.

### <a name="remarks"></a>Comentários

Esses primitivos de ponto flutuantes levam um ponteiro para um valor de ponto flutuante *px* e um valor de expoente *exp*, e o valor em escala *px* por 2<sup> *exp*</sup>, se possível. O valor retornado é o resultado de **fpclassify** no valor da entrada *px* se ele for um NaN ou infinito e no valor de saída na *px* caso contrário. Para fins de portabilidade, prefira a [ldexp, ldexpf e ldexpl](ldexp.md) funções.

## <a name="dunscale-ldunscale-fdunscale"></a>_dunscale, _ldunscale, _fdunscale

### <a name="syntax"></a>Sintaxe

```C
short __cdecl _dunscale(short* pexp, double* px);
short __cdecl _ldunscale(short* pexp, long double* px);
short __cdecl _fdunscale(short* pexp, float* px);
```

### <a name="parameters"></a>Parâmetros

*pexp*<br/>
Um ponteiro para um expoente como um tipo integral.

*px*<br/>
Ponteiro para um argumento de ponto flutuante.

### <a name="remarks"></a>Comentários

Esses primitivos de ponto flutuantes dividem o valor de ponto flutuante apontado por *px* em usam significandos de (mantissa) e um expoente, se possível. O significando é dimensionado, de modo que o valor absoluto é maior que ou igual a 0,5 e menor que 1.0. O expoente é o valor *n*, em que o valor de ponto flutuante original é igual ao significando dimensionado vezes 2<sup>*n*</sup>. Este expoente inteiro *n* é armazenado no local apontado por *pexp*. O valor retornado é o resultado de **fpclassify** no valor da entrada *px* se for um NaN ou infinito e, em caso contrário, o valor de saída. Para fins de portabilidade, prefira a [frexp, frexpf, frexpl](frexp.md) funções.

## <a name="dexp-ldexp-fdexp"></a>_dexp, _ldexp, _fdexp

### <a name="syntax"></a>Sintaxe

```C
short __cdecl _dexp(double* px, double y, long exp);
short __cdecl _ldexp(long double* px, long double y, long exp);
short __cdecl _fdexp(float* px, float y, long exp);
```

### <a name="parameters"></a>Parâmetros

*y*<br/>
Argumento da função de ponto flutuante.

*px*<br/>
Ponteiro para um argumento de ponto flutuante.

*exp*<br/>
Um expoente como um tipo integral.

### <a name="remarks"></a>Comentários

Esses primitivos de ponto flutuantes construir um valor de ponto flutuante no local apontado por *px* igual a *y* * 2<sup>*exp*</sup>. O valor retornado é o resultado de **fpclassify** no valor da entrada *y* se ele for um NaN ou infinito e no valor de saída na *px* caso contrário. Para fins de portabilidade, prefira a [ldexp, ldexpf e ldexpl](ldexp.md) funções.

## <a name="dnorm-fdnorm"></a>_dnorm, _fdnorm

### <a name="syntax"></a>Sintaxe

```C
short __cdecl _dnorm(unsigned short* ps);
short __cdecl _fdnorm(unsigned short* ps);
```

### <a name="parameters"></a>Parâmetros

*ps*<br/>
Ponteiro para a representação de bit a bit de um valor de ponto flutuante expressada como uma matriz de **sem sinal** **curto**.

### <a name="remarks"></a>Comentários

Esses primitivos de ponto flutuantes normalizar a parte fracionária de um valor de ponto flutuante underflowed e ajustar os *característica*, ou expoente polarizada, para corresponder. O valor é passado como a representação de bit a bit do tipo de ponto flutuante, convertido em uma matriz de **sem sinal** **curto** por meio do `_double_val`, `_ldouble_val`, ou `_float_val` tipo União punning declarada em Math. h. O valor de retorno é o resultado de **fpclassify** sobre o valor de ponto flutuante de entrada se ele for um NaN ou infinito e, em caso contrário, o valor de saída.

## <a name="dpoly-ldpoly-fdpoly"></a>_dpoly, _ldpoly, _fdpoly

### <a name="syntax"></a>Sintaxe

```C
double __cdecl _dpoly(double x, double const* table, int n);
long double __cdecl _ldpoly(long double x, long double const* table, int n);
float __cdecl _fdpoly(float x, _float const* table, int n);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Argumento da função de ponto flutuante.

*table*<br/>
Ponteiro para uma tabela de coeficientes de constante para um polinomial.

*n*<br/>
Ordem do polinômio para avaliar.

### <a name="remarks"></a>Comentários

Esses primitivos de ponto flutuantes retornam a avaliação de *x* em polinomial da ordem *n* cujos coeficientes são representadas por valores constantes correspondentes na *tabela*. Por exemplo, se *tabela*\[0] = 3.0, *tabela*\[1] = 4.0, *tabela*\[2] = 5.0, e *n* = 2, ele representa o x 5.0 polinomial<sup>2</sup> + 4.0 x + 3.0. Se esse polinomial é avaliada para *x* do 2.0, o resultado é 31.0. Essas funções não são usadas internamente.

## <a name="dlog-dlog-dlog"></a>_dlog, _dlog, _dlog

### <a name="syntax"></a>Sintaxe

```C
double __cdecl _dlog(double x, int base_flag);
long double __cdecl _ldlog(long double x, int base_flag);
float __cdecl _fdlog(float x, int base_flag);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Argumento da função de ponto flutuante.

*base_flag*<br/>
Sinalizador que controla a base a ser usado, 0 para base *eletrônico* e diferente de zero para a base 10.

### <a name="remarks"></a>Comentários

Esses primitivos de ponto flutuantes retornam o log natural da *x*, ln (*x*) ou de log<sub>*eletrônico*</sub>(*x*), Quando *base_flag* é 0. Elas retornam o log de base 10 da *x*, ou de log<sub>10</sub>(*x*), quando *base_flag* for diferente de zero. Essas funções não são usadas internamente. Para fins de portabilidade, prefira as funções [logf, log, log10, logl, log10f e log10l](log-logf-log10-log10f.md).

## <a name="dsin-ldsin-fdsin"></a>_dsin, _ldsin, _fdsin

### <a name="syntax"></a>Sintaxe

```C
double __cdecl _dsin(double x, unsigned int quadrant);
long double __cdecl _ldsin(long double x, unsigned int quadrant);
float __cdecl _fdsin(float x, unsigned int quadrant);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Argumento da função de ponto flutuante.

*quadrant*<br/>
Deslocamento do quadrante do 0, 1, 2 ou 3 para usar para produzir `sin`, `cos`, `-sin`, e `-cos` resultados.

### <a name="remarks"></a>Comentários

Esses primitivos de ponto flutuantes retornam o seno de *x* deslocamento pela *quadrante* módulo 4. Na verdade, eles retornam o seno, cosseno, - seno e - cosseno *x* quando *quadrante* módulo 4 é 0, 1, 2 ou 3, respectivamente. Essas funções não são usadas internamente. Para fins de portabilidade, prefira a [sin, sinf, sinl](sin-sinf-sinl.md), [cos, cosf e cosl](cos-cosf-cosl.md) funções.

## <a name="requirements"></a>Requisitos

Cabeçalho: \<Math. h >

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Suporte de ponto flutuante](../floating-point-support.md)<br/>
[fpclassify](fpclassify.md)<br/>
[_fpclass, _fpclassf](fpclass-fpclassf.md)<br/>
[isfinite, _finite, _finitef](finite-finitef.md)<br/>
[isinf](isinf.md)<br/>
[isnan, _isnan, _isnanf](isnan-isnan-isnanf.md)<br/>
[isnormal](isnormal.md)<br/>
[cos, cosf, cosl](cos-cosf-cosl.md)<br/>
[frexp, frexpf, frexpl](frexp.md)<br/>
[ldexp, ldexpf, and ldexpl](ldexp.md)<br/>
[log, logf, logl, log10, log10f, log10l](log-logf-log10-log10f.md)<br/>
[sin, sinf, sinl](sin-sinf-sinl.md)<br/>
