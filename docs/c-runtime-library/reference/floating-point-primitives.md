---
title: Primitivos de ponto flutuante
ms.date: 4/2/2020
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
- _o__d_int
- _o__dclass
- _o__dlog
- _o__dnorm
- _o__dpcomp
- _o__dpoly
- _o__dscale
- _o__dsign
- _o__dsin
- _o__dtest
- _o__dunscale
- _o__fd_int
- _o__fdclass
- _o__fdexp
- _o__fdlog
- _o__fdpcomp
- _o__fdpoly
- _o__fdscale
- _o__fdsign
- _o__fdsin
- _o__ld_int
- _o__ldclass
- _o__ldexp
- _o__ldlog
- _o__ldpcomp
- _o__ldpoly
- _o__ldscale
- _o__ldsign
- _o__ldsin
- _o__ldtest
- _o__ldunscale
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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: d861fbf2b71d557354a60f65b8a76dc24ca1dd13
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81346710"
---
# <a name="floating-point-primitives"></a>Primitivos de ponto flutuante

Funções primitivas específicas da Microsoft que são usadas para implementar algumas funções padrão de ponto flutuante da Biblioteca de Tempo de Execução C (CRT). Eles estão documentados aqui para completude, mas não são recomendados para uso. Algumas dessas funções são notadas como não utilizadas, porque são conhecidas por ter problemas de precisão, manuseio de exceções e conformidade com o comportamento do IEEE-754. Eles existem na biblioteca apenas para compatibilidade retrógrada. Para o comportamento correto, portabilidade e adesão aos padrões, prefira as funções padrão de ponto flutuante em relação a essas funções.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="_dclass-_ldclass-_fdclass"></a>_dclass, _ldclass _fdclass

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

Esses primitivos de ponto flutuante implementam as versões C da macro CRT [fpclass](fpclassify.md) para tipos de pontos flutuantes. A classificação do argumento *x* é devolvida como uma dessas constantes, definida sem e-americana:

|Valor|Descrição|
|-----------|-----------------|
| **FP_NAN** | Um NaN silencioso, indeterminado ou com sinalização |
| **FP_INFINITE** | Um infinito positivo ou negativo |
| **FP_NORMAL** | Um valor positivo ou negativo normalizado diferente de zero |
| **FP_SUBNORMAL** | Um valor subnormal positivo ou negativo (desnormalizado) |
| **FP_ZERO** | Um valor de zero positivo ou negativo |

Para mais detalhes, você pode usar as funções [_fpclass e _fpclassf](fpclass-fpclassf.md) específicas da Microsoft. Use a [macro fpclass](fpclassify.md) ou função para portabilidade.

## <a name="_dsign-_ldsign-_fdsign"></a>_dsign _ldsign _fdsign

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

Esses primitivos de ponto flutuante implementam a macro ou função [de sinal](signbit.md) no CRT. Eles retornam um valor não-zero se o bit de sinal for definido no significand (mantissa) do argumento *x*, e 0 se a broca de sinal não estiver definida.

## <a name="_dpcomp-_ldpcomp-_fdpcomp"></a>_dpcomp _ldpcomp _fdpcomp

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

Esses primitivos de ponto flutuante pegam dois argumentos, *x* e *y*, e retornam um valor que mostra sua relação de pedidos, expresso como o bitwise ou dessas constantes, definidos em matemática.h:

| Valor | Descrição |
|------------|-----------------|
| **_FP_LT** | *x* pode ser considerado menos do que *y* |
| **_FP_EQ** | *x* pode ser considerado igual a *y* |
| **_FP_GT** | *x* pode ser considerado maior do que *y* |

Estes primitivos implementam o [ismaior, isgreaterequal, isless, islessequal, islessmaior, e isunordered](floating-point-ordering.md) macros e funções no CRT.

## <a name="_dtest-_ldtest-_fdtest"></a>_dtest, _ldtest _fdtest

### <a name="syntax"></a>Sintaxe

```C
short __cdecl _dtest(double* px);
short __cdecl _ldtest(long double* px);
short __cdecl _fdtest(float* px);
```

### <a name="parameters"></a>Parâmetros

*Px*<br/>
Ponteiro para um argumento de ponto flutuante.

### <a name="remarks"></a>Comentários

Esses primitivos de ponto flutuante implementam as versões C++ da função CRT [fpclass](fpclassify.md) para tipos de pontos flutuantes. O argumento *x* é avaliado e a classificação é retornada como uma dessas constantes, definidas em matemática.h:

|Valor|Descrição|
|-----------|-----------------|
| **FP_NAN** | Um NaN silencioso, indeterminado ou com sinalização |
| **FP_INFINITE** | Um infinito positivo ou negativo |
| **FP_NORMAL** | Um valor positivo ou negativo normalizado diferente de zero |
| **FP_SUBNORMAL** | Um valor subnormal positivo ou negativo (desnormalizado) |
| **FP_ZERO** | Um valor de zero positivo ou negativo |

Para mais detalhes, você pode usar as funções [_fpclass e _fpclassf](fpclass-fpclassf.md) específicas da Microsoft. Use a função [fpclassify](fpclassify.md) para portabilidade.

## <a name="_d_int-_ld_int-_fd_int"></a>_d_int, _ld_int _fd_int

### <a name="syntax"></a>Sintaxe

```C
short __cdecl _d_int(double* px, short exp);
short __cdecl _ld_int(long double* px, short exp);
short __cdecl _fd_int(float* px, short exp);
```

### <a name="parameters"></a>Parâmetros

*Px*<br/>
Ponteiro para um argumento de ponto flutuante.

*Exp*<br/>
Um expoente como um tipo integral.

### <a name="remarks"></a>Comentários

Esses primitivos de ponto flutuante levam um ponteiro para um *px* de valor de ponto flutuante e um *exp*de valor expoente , e removem a parte fracionada do valor de ponto flutuante abaixo do expoente dado, se possível. O valor devolvido é o resultado de **fpclassificar** sobre o valor de entrada em *px* se for um NaN ou infinito, e sobre o valor de saída em *px* de outra forma.

## <a name="_dscale-_ldscale-_fdscale"></a>_dscale, _ldscale _fdscale

### <a name="syntax"></a>Sintaxe

```C
short __cdecl _dscale(double* px, long exp);
short __cdecl _ldscale(long double* px, long exp);
short __cdecl _fdscale(float* px, long exp);
```

### <a name="parameters"></a>Parâmetros

*Px*<br/>
Ponteiro para um argumento de ponto flutuante.

*Exp*<br/>
Um expoente como um tipo integral.

### <a name="remarks"></a>Comentários

Esses primitivos de ponto flutuante levam um ponteiro para um *px* de valor de ponto flutuante e um *exp*de valor expoente , e dimensionam o valor em *px* por 2<sup>*exp*</sup>, se possível. O valor devolvido é o resultado de **fpclassificar** sobre o valor de entrada em *px* se for um NaN ou infinito, e sobre o valor de saída em *px* de outra forma. Para portabilidade, prefira as funções [ldexp, ldexpf e ldexpl.](ldexp.md)

## <a name="_dunscale-_ldunscale-_fdunscale"></a>_dunscale _ldunscale _fdunscale

### <a name="syntax"></a>Sintaxe

```C
short __cdecl _dunscale(short* pexp, double* px);
short __cdecl _ldunscale(short* pexp, long double* px);
short __cdecl _fdunscale(short* pexp, float* px);
```

### <a name="parameters"></a>Parâmetros

*Pexp*<br/>
Um ponteiro para um expoente como um tipo integral.

*Px*<br/>
Ponteiro para um argumento de ponto flutuante.

### <a name="remarks"></a>Comentários

Estes primitivos de ponto flutuante quebram o valor de ponto flutuante apontado por *px* em um significand (mantissa) e um expoente, se possível. O significand é dimensionado de tal forma que o valor absoluto seja maior ou igual a 0,5 e inferior a 1,0. O expoente é o valor *n*, onde o valor original de ponto flutuante é igual ao significe e vezes 2<sup>*n*</sup>. Este expoente inteiro *n* é armazenado no local apontado pela *pexp*. O valor devolvido é o resultado de **fpclassificar** sobre o valor de entrada em *px* se for um NaN ou infinito, e sobre o valor de saída de outra forma. Para portabilidade, prefira as funções [frexp, frexpf, frexpl.](frexp.md)

## <a name="_dexp-_ldexp-_fdexp"></a>_dexp _ldexp _fdexp

### <a name="syntax"></a>Sintaxe

```C
short __cdecl _dexp(double* px, double y, long exp);
short __cdecl _ldexp(long double* px, long double y, long exp);
short __cdecl _fdexp(float* px, float y, long exp);
```

### <a name="parameters"></a>Parâmetros

*Y*<br/>
Argumento de função de ponto flutuante.

*Px*<br/>
Ponteiro para um argumento de ponto flutuante.

*Exp*<br/>
Um expoente como um tipo integral.

### <a name="remarks"></a>Comentários

Estes primitivos de ponto flutuante constroem um valor de ponto flutuante no local apontado por *px* igual a *y* * 2<sup>*exp*</sup>. O valor devolvido é o resultado de **fpclassificar** sobre o valor de entrada em *y* se for um NaN ou infinito, e sobre o valor de saída em *px* de outra forma. Para portabilidade, prefira as funções [ldexp, ldexpf e ldexpl.](ldexp.md)

## <a name="_dnorm-_fdnorm"></a>_dnorm _fdnorm.

### <a name="syntax"></a>Sintaxe

```C
short __cdecl _dnorm(unsigned short* ps);
short __cdecl _fdnorm(unsigned short* ps);
```

### <a name="parameters"></a>Parâmetros

*Ps*<br/>
Ponteiro para a representação bitwise de um valor de ponto flutuante expresso como uma matriz de **curto** **não assinado** .

### <a name="remarks"></a>Comentários

Esses primitivos de ponto flutuante normalizam a parte fracionária de um valor de ponto flutuante subfluído e ajustam a *característica*, ou expoente tendencioso, para combinar. O valor é passado como a representação bitwise do tipo de ponto `_double_val`flutuante `_ldouble_val`convertida `_float_val` em uma matriz de **curto** **não assinado** através da , ou tipo punning união declarada em math.h. O valor de retorno é o resultado de **fpclassificar** no valor de ponto flutuante de entrada se for um NaN ou infinito, e no valor de saída de outra forma.

## <a name="_dpoly-_ldpoly-_fdpoly"></a>_dpoly, _ldpoly _fdpoly

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
Ponteiro para uma tabela de coeficientes constantes para um polinômio.

*n*<br/>
Ordem do polinômio para avaliar.

### <a name="remarks"></a>Comentários

Estes primitivos de ponto flutuante retornam a avaliação de *x* no polinômio da ordem *n* cujos coeficientes são representados pelos valores constantes correspondentes na *tabela*. Por exemplo, se *tabela*\[0] = 3,0, *tabela*\[1] = 4,0, *tabela*\[2] = 5,0, e *n* = 2, representa o polinômio 5,0x<sup>2</sup> + 4,0x + 3,0. Se este polinômio for avaliado para *x* de 2,0, o resultado será 31,0. Essas funções não são usadas internamente.

## <a name="_dlog-_dlog-_dlog"></a>_dlog, _dlog _dlog

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
Bandeira que controla a base a ser usada, 0 para base *e* e não-zero para base 10.

### <a name="remarks"></a>Comentários

Estes primitivos de ponto flutuante retornam o tronco natural de *x*, ln(*x*) ou log<sub>*e*</sub>*(x),* quando *base_flag* é 0. Eles retornam a base de registro 10 de *x*, ou log<sub>10</sub>*(x),* quando *base_flag* não é zero. Essas funções não são usadas internamente. Para portabilidade, prefira as funções [log, logf, logl, log10, log10f e log10l](log-logf-log10-log10f.md).

## <a name="_dsin-_ldsin-_fdsin"></a>_dsin _ldsin _fdsin

### <a name="syntax"></a>Sintaxe

```C
double __cdecl _dsin(double x, unsigned int quadrant);
long double __cdecl _ldsin(long double x, unsigned int quadrant);
float __cdecl _fdsin(float x, unsigned int quadrant);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Argumento de função de ponto flutuante.

*Quadrante*<br/>
Deslocamento do quadrante de 0, 1, `sin`2 `cos` `-sin`ou `-cos` 3 para produzir , e resultados.

### <a name="remarks"></a>Comentários

Estes primitivos de ponto flutuante retornam o seno de *x* compensado pelo *quadrante* modulo 4. Efetivamente, eles retornam o seno, cosseno, -seno e -cosseno de *x* quando *o módulo do quadrante* 4 é 0, 1, 2 ou 3, respectivamente. Essas funções não são usadas internamente. Para portabilidade, prefira as funções [sin, sinf, sinl,](sin-sinf-sinl.md) [cos, cosf e cosl.](cos-cosf-cosl.md)

## <a name="requirements"></a>Requisitos

Cabeçalho: \<math.h>

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Suporte de ponto flutuante](../floating-point-support.md)<br/>
[fpclassify](fpclassify.md)<br/>
[_fpclass, _fpclassf](fpclass-fpclassf.md)<br/>
[isfinite, _finite, _finitef](finite-finitef.md)<br/>
[isinf](isinf.md)<br/>
[isnan, _isnan, _isnanf](isnan-isnan-isnanf.md)<br/>
[isnormal](isnormal.md)<br/>
[cos, cosf, cosl](cos-cosf-cosl.md)<br/>
[frexp, frexpf, frexpl](frexp.md)<br/>
[Ldexp, Ldexpf e Ldexpl](ldexp.md)<br/>
[log, logf, logl, log10, log10f, log10l](log-logf-log10-log10f.md)<br/>
[sin, sinf, sinl](sin-sinf-sinl.md)<br/>
