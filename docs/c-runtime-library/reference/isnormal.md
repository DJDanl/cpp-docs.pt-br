---
title: isnormal
ms.date: 01/31/2019
f1_keywords:
- isnormal
- math/isnormal
helpviewer_keywords:
- isnormal function
ms.openlocfilehash: e426fbce71efff1e810a03b8347e7c48aa0d91d2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62286434"
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

### <a name="parameters"></a>Parâmetros

*x*<br/>
O valor de ponto flutuante a ser testado.

## <a name="return-value"></a>Valor retornado

**isnormal** retorna um valor diferente de zero (**verdadeira** em C++ código) se o argumento *x* não é zero, subnormal, infinito, nem um NaN. Caso contrário, **isnormal** retorna 0 (**falso** em C++ código).

## <a name="remarks"></a>Comentários

**isnormal** é uma macro quando compilado como C e um modelo de função embutida quando compilado como C++.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|--------------|---------------------------|-------------------------------|
|**isnormal**|\<math.h>|\<math.h> ou \<cmath>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[isfinite, _finite, _finitef](finite-finitef.md)<br/>
[isinf](isinf.md)<br/>
[isnan, _isnan, _isnanf](isnan-isnan-isnanf.md)<br/>
[_fpclass, _fpclassf](fpclass-fpclassf.md)<br/>
