---
title: isnormal
ms.date: 01/31/2019
f1_keywords:
- isnormal
- math/isnormal
helpviewer_keywords:
- isnormal function
ms.openlocfilehash: 2e12cabb57f2e51c08b4d93af33dae85164d016b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213522"
---
# <a name="isnormal"></a>isnormal

Determina se um valor de ponto flutuante é um valor normal.

## <a name="syntax"></a>Sintaxe

```C
int isnormal(
   /* floating-point */ x
); /* C-only macro */

template <class FloatingType>
inline bool isnormal(
   FloatingType x
) throw(); /* C++-only function template */
```

### <a name="parameters"></a>parâmetros

*x*<br/>
O valor de ponto flutuante a ser testado.

## <a name="return-value"></a>Valor retornado

**IsNormal** retorna um valor diferente de zero ( **`true`** em código C++) se o argumento *x* não for zero, subnormal, infinito, nem NaN. Caso contrário, **IsNormal** retornará 0 ( **`false`** em código C++).

## <a name="remarks"></a>Comentários

**IsNormal** é uma macro quando compilada como C e um modelo de função embutido quando compilado como C++.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|--------------|---------------------------|-------------------------------|
|**isnormal**|\<math.h>|\<math.h> ou \<cmath>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[isfinite, _finite, _finitef](finite-finitef.md)<br/>
[isinf](isinf.md)<br/>
[isnan, _isnan, _isnanf](isnan-isnan-isnanf.md)<br/>
[_fpclass, _fpclassf](fpclass-fpclassf.md)<br/>
