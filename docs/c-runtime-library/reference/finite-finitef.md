---
title: isfinite, _finite, _finitef
ms.date: 01/31/2019
api_name:
- _finite
- _finitef
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
- ntoskrnl.exe
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- isfinite
- finite
- _finite
- _finitef
- math/isfinite
- math/_finite
- math/_finitef
- float/_finite
helpviewer_keywords:
- finite function
- _finite function
- _finitef function
ms.assetid: 5a7d7ca7-befb-4e1f-831d-28713c6eb805
ms.openlocfilehash: a2cde4d3a57884413f0c48aa299b171334c5f988
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70957175"
---
# <a name="isfinite-_finite-_finitef"></a>isfinite, _finite, _finitef

Determina se um valor de ponto flutuante é finito.

## <a name="syntax"></a>Sintaxe

```C
int isfinite(
   /* floating-point */ x
); /* C-only macro */

template <class FloatingType>
inline bool isfinite(
   FloatingType x
) throw(); /* C++-only template function */

int _finite(
   double x
);

int _finitef(
   float x
); /* x64 and ARM/ARM64 only */
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O valor de ponto flutuante a ser testado.

## <a name="return-value"></a>Valor retornado

A `isfinite` macro e as `_finite` funções `_finitef` e retornarão um valor diferente de zero se *x* for um valor finito normal ou de subnormal. Eles retornam 0 se o argumento é infinito ou um NaN. A C++ função `isfinite` de modelo embutida se comporta da mesma maneira, mas retorna **true** ou **false**.

## <a name="remarks"></a>Comentários

`isfinite`é uma macro quando compilada como C e uma função de modelo embutida quando C++compilada como. As `_finite` funções `_finitef` e são específicas da Microsoft. A função `_finitef` só está disponível quando compilada para plataformas x86, ARM ou ARM64.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|--------------|---------------------------|-------------------------------|
|`_finite`|\<float.h> ou \<math.h>|\<float.h>, \<math.h>, \<cfloat> ou \<cmath>|
|`isfinite`, `_finitef`|\<math.h>|\<math.h> ou \<cmath>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[fpclassify](fpclassify.md)<br/>
[_fpclass, _fpclassf](fpclass-fpclassf.md)<br/>
[isinf](isinf.md)<br/>
[isnan, _isnan, _isnanf](isnan-isnan-isnanf.md)<br/>
[isnormal](isnormal.md)<br/>
