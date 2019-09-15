---
title: Primitivos de ponto flutuante
ms.date: 01/31/2019
api_name:
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
ms.openlocfilehash: 25d70062a76f9c32692f5df3f7abb96b49892725
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70957168"
---
# <a name="floating-point-primitives"></a>Primitivos de ponto flutuante

Funções primitivas específicas da Microsoft que são usadas para implementar algumas funções padrão de ponto flutuante da biblioteca de tempo de execução C (CRT). Eles estão documentados aqui para fins de integridade, mas não são recomendados para uso. Algumas dessas funções são indicadas como não utilizadas, pois elas são conhecidas por ter problemas de precisão, manipulação de exceção e conformidade com o comportamento do IEEE-754. Eles existem na biblioteca somente para compatibilidade com versões anteriores. Para o comportamento correto, a portabilidade e a adesão aos padrões, prefira as funções de ponto flutuante padrão sobre essas funções.

## <a name="_dclass-_ldclass-_fdclass"></a>_dclass, _ldclass, _fdclass

### <a name="syntax"></a>Sintaxe

```C
short __cdecl _dclass(double x);
short __cdecl _ldclass(long double x);
short __cdecl _fdclass(float x);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Argumento de função de ponto flutuante.

### <a name="remarks"></a>Comentários

Esses primitivos de ponto flutuante implementam as versões C da macro CRT [fpclassify](fpclassify.md) para tipos de ponto flutuante. A classificação do argumento *x* é retornada como uma dessas constantes, definida em Math. h:

|Valor|Descrição|
|-----------|-----------------|
| **FP_NAN** | Um NaN silencioso, indeterminado ou com sinalização |
| **FP_INFINITE** | Um infinito positivo ou negativo |
| **FP_NORMAL** | Um valor positivo ou negativo normalizado diferente de zero |
| **FP_SUBNORMAL** | Um valor positivo ou negativo subnormal (desnormalizado) |
| **FP_ZERO** | Um valor de zero positivo ou negativo |

Para obter detalhes adicionais, você pode usar as funções [_fpclass, _fpclassf](fpclass-fpclassf.md) específicas da Microsoft. Use a macro [fpclassify](fpclassify.md) ou a função para portabilidade.

## <a name="_dsign-_ldsign-_fdsign"></a>_dsign, _ldsign, _fdsign

### <a name="syntax"></a>Sintaxe

```C
int __cdecl _dsign(double x);
int __cdecl _ldsign(long double x);
int __cdecl _fdsign(float x);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Argumento de função de ponto flutuante.

### <a name="remarks"></a>Comentários

Esses primitivos de ponto flutuante implementam a macro ou função [signbit](signbit.md) no CRT. Eles retornarão um valor diferente de zero se o bit de sinal estiver definido no significante (mantissa) do argumento *x*e 0 se o bit de sinal não estiver definido.

## <a name="_dpcomp-_ldpcomp-_fdpcomp"></a>_dpcomp, _ldpcomp, _fdpcomp

### <a name="syntax"></a>Sintaxe

```C
int __cdecl _dpcomp(double x, double y);
int __cdecl _ldpcomp(long double x, long double y);
int __cdecl _fdpcomp(float x, float y);
```

### <a name="parameters"></a>Parâmetros

*x*, *y*<br/>
Argumentos de função de ponto flutuante.

### <a name="remarks"></a>Comentários

Esses primitivos de ponto flutuante usam dois argumentos, *x* e *y*, e retornam um valor que mostra a relação de ordenação, expressa como a bit a bit ou dessas constantes, definida em Math. h:

| Valor | Descrição |
|------------|-----------------|
| **_FP_LT** | *x* pode ser considerado menor que *y* |
| **_FP_EQ** | *x* pode ser considerado igual a *y* |
| **_FP_GT** | *x* pode ser considerado maior que *y* |

Esses primitivos implementam as macros [isgreaterequal, isless, islessequal, islessgreater e isunordered](floating-point-ordering.md) e as funções no CRT.

## <a name="_dtest-_ldtest-_fdtest"></a>_dtest, _ldtest, _fdtest

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

Esses primitivos de ponto flutuante implementam C++ as versões da função CRT [fpclassify](fpclassify.md) para tipos de ponto flutuante. O argumento *x* é avaliado e a classificação é retornada como uma dessas constantes, definidas em Math. h:

|Valor|Descrição|
|-----------|-----------------|
| **FP_NAN** | Um NaN silencioso, indeterminado ou com sinalização |
| **FP_INFINITE** | Um infinito positivo ou negativo |
| **FP_NORMAL** | Um valor positivo ou negativo normalizado diferente de zero |
| **FP_SUBNORMAL** | Um valor positivo ou negativo subnormal (desnormalizado) |
| **FP_ZERO** | Um valor de zero positivo ou negativo |

Para obter detalhes adicionais, você pode usar as funções [_fpclass, _fpclassf](fpclass-fpclassf.md) específicas da Microsoft. Use a função [fpclassify](fpclassify.md) para portabilidade.

## <a name="_d_int-_ld_int-_fd_int"></a>_d_int, _ld_int, _fd_int

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

Esses primitivos de ponto flutuante levam um ponteiro para um valor de ponto flutuante *PX* e um valor de expoente *exp*e removem a parte fracionária do valor de ponto flutuante abaixo do expoente fornecido, se possível. O valor retornado é o resultado de **fpclassify** no valor de entrada em *PX* , se for um Nan ou um infinito, e no valor de saída em *PX* de outra forma.

## <a name="_dscale-_ldscale-_fdscale"></a>_dscale, _ldscale, _fdscale

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

Esses primitivos de ponto flutuante usam um ponteiro para um valor de ponto flutuante *PX* e um valor de expoente *exp*e dimensionam o valor em *PX* por 2<sup>*exp*</sup>, se possível. O valor retornado é o resultado de **fpclassify** no valor de entrada em *PX* , se for um Nan ou um infinito, e no valor de saída em *PX* de outra forma. Para portabilidade, prefira as funções [ldexp, ldexpf e ldexpl](ldexp.md) .

## <a name="_dunscale-_ldunscale-_fdunscale"></a>_dunscale, _ldunscale, _fdunscale

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

Esses primitivos de ponto flutuante dividem o valor de ponto flutuante apontado por *PX* em um significante (mantissa) e um expoente, se possível. O significante é dimensionado de forma que o valor absoluto seja maior ou igual a 0,5 e menor que 1,0. O expoente é o valor *n*, em que o valor de ponto flutuante original é igual ao significante dimensionado em horas 2<sup>*n*</sup>. Esse expoente de inteiro *n* é armazenado no local apontado por *pexp*. O valor retornado é o resultado de **fpclassify** no valor de entrada em *PX* , se for um Nan ou um infinito, e no valor de saída, caso contrário. Para portabilidade, prefira as funções [frexp, frexpf e frexpl](frexp.md) .

## <a name="_dexp-_ldexp-_fdexp"></a>_dexp, _ldexp, _fdexp

### <a name="syntax"></a>Sintaxe

```C
short __cdecl _dexp(double* px, double y, long exp);
short __cdecl _ldexp(long double* px, long double y, long exp);
short __cdecl _fdexp(float* px, float y, long exp);
```

### <a name="parameters"></a>Parâmetros

*y*<br/>
Argumento de função de ponto flutuante.

*px*<br/>
Ponteiro para um argumento de ponto flutuante.

*exp*<br/>
Um expoente como um tipo integral.

### <a name="remarks"></a>Comentários

Esses primitivos de ponto flutuante constroem um valor de ponto flutuante no local apontado por *PX* igual a *y* * 2<sup>*exp*</sup>. O valor retornado é o resultado de **fpclassify** no valor de entrada em *y* se for um Nan ou infinito, e no valor de saída em *PX* de outra forma. Para portabilidade, prefira as funções [ldexp, ldexpf e ldexpl](ldexp.md) .

## <a name="_dnorm-_fdnorm"></a>_dnorm, _fdnorm

### <a name="syntax"></a>Sintaxe

```C
short __cdecl _dnorm(unsigned short* ps);
short __cdecl _fdnorm(unsigned short* ps);
```

### <a name="parameters"></a>Parâmetros

*ps*<br/>
Ponteiro para a representação de bit-de-vírgula de um valor de ponto flutuante expresso como uma matriz de **curto** **não assinado** .

### <a name="remarks"></a>Comentários

Esses primitivos de ponto flutuante normalizam a parte fracionária de um valor de ponto flutuante de estouro negativo e ajustam a *característica*, ou expoente tendenciosa, para corresponder. O valor é passado como a representação bit-de-vírgula do tipo de ponto flutuante convertido em uma matriz de **curto** `_double_val` **não assinado** por `_ldouble_val`meio de `_float_val` , ou tipo punning Union declarada em Math. h. O valor de retorno é o resultado de **fpclassify** no valor de ponto flutuante de entrada, se for um Nan ou um infinito, e no valor de saída, caso contrário.

## <a name="_dpoly-_ldpoly-_fdpoly"></a>_dpoly, _ldpoly, _fdpoly

### <a name="syntax"></a>Sintaxe

```C
double __cdecl _dpoly(double x, double const* table, int n);
long double __cdecl _ldpoly(long double x, long double const* table, int n);
float __cdecl _fdpoly(float x, _float const* table, int n);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Argumento de função de ponto flutuante.

*table*<br/>
Ponteiro para uma tabela de coeficientes constantes para um polinomial.

*n*<br/>
Ordem do polinomial a ser avaliada.

### <a name="remarks"></a>Comentários

Esses primitivos de ponto flutuante retornam a avaliação de *x* no polinomial da ordem *n* cujos coeficientes são representados pelos valores constantes correspondentes na *tabela*. Por exemplo, se *Table*\[0] = 3,0, *tabela*\[1] = 4,0, *Table*\[2] = 5,0 e *n* = 2, ele representa o polinomial 5.0 x<sup>2</sup> + 4.0 x + 3,0. Se esse polinomial for avaliado para *x* de 2,0, o resultado será 31,0. Essas funções não são usadas internamente.

## <a name="_dlog-_dlog-_dlog"></a>_dlog, _dlog, _dlog

### <a name="syntax"></a>Sintaxe

```C
double __cdecl _dlog(double x, int base_flag);
long double __cdecl _ldlog(long double x, int base_flag);
float __cdecl _fdlog(float x, int base_flag);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Argumento de função de ponto flutuante.

*base_flag*<br/>
Sinalizador que controla a base a ser usada, 0 para base *e e diferente* de zero para base 10.

### <a name="remarks"></a>Comentários

Esses primitivos de ponto flutuante retornam o log natural de *x*, ln (*x*) ou log<sub>*e*</sub>(*x*), quando *base_flag* é 0. Eles retornam a base de log 10 de *x*, ou log<sub>10</sub>(*x*), quando *base_flag* é diferente de zero. Essas funções não são usadas internamente. Para portabilidade, prefira o log de funções [, logf, logl, log10, log10f e log10l](log-logf-log10-log10f.md).

## <a name="_dsin-_ldsin-_fdsin"></a>_dsin, _ldsin, _fdsin

### <a name="syntax"></a>Sintaxe

```C
double __cdecl _dsin(double x, unsigned int quadrant);
long double __cdecl _ldsin(long double x, unsigned int quadrant);
float __cdecl _fdsin(float x, unsigned int quadrant);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Argumento de função de ponto flutuante.

*quadrant*<br/>
Deslocamento de quadrante de 0, 1, 2 ou 3 a ser usado `sin`para `cos`produzir `-sin`,, `-cos` e resultados.

### <a name="remarks"></a>Comentários

Esses primitivos de ponto flutuante retornam o seno de deslocamento *x* pelo módulo de *quadrante* 4. Efetivamente, elas retornam o seno, o cosseno, o seno e o cosseno de *x* quando o módulo de *quadrante* 4 é 0, 1, 2 ou 3, respectivamente. Essas funções não são usadas internamente. Para portabilidade, prefira as funções [sin, sinf, sinl](sin-sinf-sinl.md), [cos, cosf e COSL](cos-cosf-cosl.md) .

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
