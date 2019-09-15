---
title: isnan, _isnan, _isnanf
ms.date: 01/31/2019
api_name:
- _isnan
- _isnanf
- isnan
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
- _isnan
- isnan
- math/isnan
- math/_isnan
- math/_isnanf
- _isnanf
helpviewer_keywords:
- NAN (not a number)
- _isnan function
- IEEE floating-point representation
- Not a Number (NANs)
- isnan function
ms.assetid: 391fbc5b-89a4-4fba-997e-68f1131caf82
ms.openlocfilehash: a0cc60fb80f8d5b78ec2947a87fde82a536b413c
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70953758"
---
# <a name="isnan-_isnan-_isnanf"></a>isnan, _isnan, _isnanf

Testa se um valor de ponto flutuante não é um número (NAN).

## <a name="syntax"></a>Sintaxe

```C
int isnan(
   /* floating-point */ x
); /* C-only macro */

int _isnan(
   double x
);

int _isnanf(
   float x
); /* x64 only */

template <class T>
bool isnan(
   T x
) throw(); /* C++ only */
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O valor de ponto flutuante a ser testado.

## <a name="return-value"></a>Valor de retorno

Em C, a macro **IsNaN** e as funções **_isnan** e **_isnanf** retornarão um valor diferente de zero se o argumento *x* for um NaN; caso contrário, eles retornam 0.

No C++, a função de modelo **IsNaN** retornará **true** se o argumento *x* for um NaN; caso contrário, retornará **false**.

## <a name="remarks"></a>Comentários

Como um valor NaN não é comparado como igual a qualquer outro valor NaN, você deve usar uma dessas funções ou macros para detectar uma. Um NaN é gerado quando o resultado de uma operação de ponto flutuante não pode ser representado no formato de ponto flutuante do IEEE-754 para o tipo especificado. Para obter informações sobre como um NaN é representado para saída, consulte [printf](printf-printf-l-wprintf-wprintf-l.md).

Quando compilado como C++, a macro **IsNaN** não é definida e uma função de modelo **IsNaN** é definida em seu lugar. Ele se comporta da mesma forma que a macro, mas retorna um valor do tipo **bool** em vez de um inteiro.

As funções **_isnan** e **_isnanf** são específicas da Microsoft. A função **_isnanf** só estará disponível quando compilada para x64.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|-------------|---------------------------|-------------------------------|
|**isnan**, **_isnanf**|\<math.h>|\<math.h> ou \<cmath>|
|**_isnan**|\<float.h>|\<float.h> ou \<cfloat>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[fpclassify](fpclassify.md)<br/>
[_fpclass, _fpclassf](fpclass-fpclassf.md)<br/>
[isfinite, _finite, _finitef](finite-finitef.md)<br/>
[isinf](isinf.md)<br/>
[isnormal](isnormal.md)<br/>
