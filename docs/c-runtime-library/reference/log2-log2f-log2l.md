---
title: log2, log2f, log2l
ms.date: 04/05/2018
apiname:
- log2
- log2l
- log2f
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
ms.assetid: 94d11b38-70b7-4d3a-94ac-523153c92b2e
ms.openlocfilehash: d70d074b13b0f24f1f040ef0e861e073e303ac7b
ms.sourcegitcommit: afd6fac7c519dbc47a4befaece14a919d4e0a8a2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2018
ms.locfileid: "51520459"
---
# <a name="log2-log2f-log2l"></a>log2, log2f, log2l

Determina o logaritmo binário (base 2) do valor especificado.

## <a name="syntax"></a>Sintaxe

```C
double log2(
   double x
);

float log2(
   float x
); //C++ only

long double log2(
   long double x
); //C++ only

float log2f(
   float x
);

long double log2l(
   long double x
);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O valor para determinar o logaritmo de base 2.

## <a name="return-value"></a>Valor de retorno

Em caso de sucesso, retorna o log2 de retorno *x*.

Caso contrário, pode retornar um dos seguintes valores:

|Problema|Valor de|
|-----------|------------|
|*x* < 0|NaN|
|*x* = ±0|-INFINITY|
|*x* = 1|+0|
|+INFINITY|+INFINITY|
|NaN|NaN|
|erro de domínio|NaN|
|erro de polo|-HUGE_VAL, -HUGE_VALF ou -HUGE_VALL|

Os erros são relatados conforme especificado em [_matherr](matherr.md).

## <a name="remarks"></a>Comentários

Se x for um número inteiro, essa função retornará essencialmente o índice baseado em zero do bit mais significativo 1 de *x*.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**log2**, **log2f**, **log2l**|\<math.h>|\<cmath>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[exp2, exp2f, exp2l](exp2-exp2f-exp2l.md)<br/>
[log, logf, log10, log10f](log-logf-log10-log10f.md)<br/>
