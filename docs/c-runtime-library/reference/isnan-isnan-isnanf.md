---
title: isnan, _isnan, _isnanf | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _isnan
- _isnanf
- isnan
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
- _isnan
- isnan
- math/isnan
- math/_isnan
- math/_isnanf
- _isnanf
dev_langs:
- C++
helpviewer_keywords:
- NAN (not a number)
- _isnan function
- IEEE floating-point representation
- Not a Number (NANs)
- isnan function
ms.assetid: 391fbc5b-89a4-4fba-997e-68f1131caf82
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: baf92397087ebbac27c7fea8cf5f524b33736b19
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="isnan-isnan-isnanf"></a>isnan, _isnan, _isnanf

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

Em C, o **isnan** macro e o **isNaN** e **_isnanf** funções retornam um valor diferente de zero se o argumento *x* é um NAN; caso contrário, eles retorne 0.

Em C++, o **isnan** modelo funções retornam **true** se o argumento *x* é um NAN; caso contrário, elas retornam **false**.

## <a name="remarks"></a>Comentários

C **isnan** macro e o **isNaN** e **_isnanf** funções testar o valor de ponto flutuante *x*, retornando um valor diferente de zero se *x* não é um valor de número (NAN). Um NAN é gerado quando o resultado de uma operação de ponto flutuante não puder ser representado no formato de ponto flutuante IEEE-754 para o tipo especificado. Para obter informações sobre como um NaN é representado para saída, consulte [printf](printf-printf-l-wprintf-wprintf-l.md).

Quando compilado como C++, o **isnan** macro não está definida e um **isnan** modelo de função é definido em vez disso. Retorna um valor do tipo **bool** em vez de um número inteiro.

O **isNaN** e **_isnanf** funções são específicas da Microsoft. O **_isnanf** função só está disponível quando compilado para x64.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|-------------|---------------------------|-------------------------------|
|**isNaN**, **_isnanf**|\<math.h>|\<math.h> ou \<cmath>|
|**_isnan**|\<float.h>|\<float.h> ou \<cfloat>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[_finite, _finitef](finite-finitef.md)<br/>
[_fpclass, _fpclassf](fpclass-fpclassf.md)<br/>
