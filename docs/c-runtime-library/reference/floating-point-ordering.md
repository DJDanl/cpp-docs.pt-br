---
title: isgreater, isgreaterequal, isless, islessequal, islessgreater, isunordered
ms.date: 01/31/2019
f1_keywords:
- isgreater
- math/isgreater
- isgreaterequal
- math/isgreaterequal
- isless
- math/isless
- islessequal
- math/islessequal
- islessgreater
- math/islessgreater
- isunordered
- math/isunordered
helpviewer_keywords:
- isgreater function
- isgreaterequal function
- isless function
- islessequal function
- islessgreater function
- isunordered function
ms.openlocfilehash: 907b26f4e1824d7ef5c7c1a36b4e4d8ccb74c978
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220711"
---
# <a name="isgreater-isgreaterequal-isless-islessequal-islessgreater-isunordered"></a>isgreater, isgreaterequal, isless, islessequal, islessgreater, isunordered

Determina a relação de ordenação entre dois valores de ponto flutuante.

## <a name="syntax"></a>Sintaxe

```C
int isgreater(
   /* floating-point */ x,
   /* floating-point */ y
); /* C-only macro */

int isgreaterequal(
   /* floating-point */ x,
   /* floating-point */ y
); /* C-only macro */

int isless(
   /* floating-point */ x,
   /* floating-point */ y
); /* C-only macro */

int islessequal(
   /* floating-point */ x,
   /* floating-point */ y
); /* C-only macro */

int islessgreater(
   /* floating-point */ x,
   /* floating-point */ y
); /* C-only macro */

int isunordered(
   /* floating-point */ x,
   /* floating-point */ y
); /* C-only macro */
```

```C++
template <class FloatingType1, class FloatingType2>
inline bool isgreater(
   FloatingType1 x,
   FloatingType2 y
) throw(); /* C++-only template function */

template <class FloatingType1, class FloatingType2>
inline bool isgreaterequal(
   FloatingType1 x,
   FloatingType2 y
) throw(); /* C++-only template function */

template <class FloatingType1, class FloatingType2>
inline bool isless(
   FloatingType1 x,
   FloatingType2 y
) throw(); /* C++-only template function */

template <class FloatingType1, class FloatingType2>
inline bool islessequal(
   FloatingType1 x,
   FloatingType2 y
) throw(); /* C++-only template function */

template <class FloatingType1, class FloatingType2>
inline bool islessgreater(
   FloatingType1 x,
   FloatingType2 y
) throw(); /* C++-only template function */

template <class FloatingType1, class FloatingType2>
inline bool isunordered(
   FloatingType1 x,
   FloatingType2 y
) throw(); /* C++-only template function */
```

### <a name="parameters"></a>parâmetros

*x*, *y*<br/>
Os valores de ponto flutuante a serem comparados.

## <a name="return-value"></a>Valor retornado

Em todas as comparações, os infinitos do mesmo sinal se comparam como iguais. Infinito negativo é menor que qualquer valor finito ou infinito positivo. Infinito positivo é maior que qualquer valor finito ou infinito negativo. Zeros são iguais, independentemente do sinal. NaNs não são menores que, iguais ou maiores que qualquer valor, incluindo outro NaN.

Quando nenhum argumento é NaN, **as macros**de ordenação **isgreaterequal**, **isless**e **islessequal** retornarão um valor diferente de zero se a relação de ordenação especificada entre *x* e *y* for verdadeira. Essas macros retornarão 0 se um ou ambos os argumentos forem NaNs ou se a relação de ordenação for falsa. Os formulários de função se comportam da mesma maneira, mas retornam **`true`** ou **`false`** .

A macro **islessgreater** retornará um valor diferente de zero se *x* e *y* não forem Nans e *x* for menor ou maior que *y*. Retornará 0 se um ou ambos os argumentos forem NaNs ou se os valores forem iguais. O formulário de função se comporta da mesma maneira, mas retorna **`true`** ou **`false`** .

A macro **isunordered** retornará um valor diferente de zero se *x*, *y*ou ambos forem Nans. Caso contrário, retornará 0. O formulário de função se comporta da mesma maneira, mas retorna **`true`** ou **`false`** .

## <a name="remarks"></a>Comentários

Essas operações de comparação são implementadas como macros quando compiladas como C e como funções de modelo embutidas quando compiladas como C++.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|--------------|---------------------------|-------------------------------|
| **isexcelente**, **isgreaterequal**, **isless**,<br/>**islessequal**, **islessgreater**, **isunordered** | \<math.h> | \<math.h> ou \<cmath> |

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[isfinite, _finite, _finitef](finite-finitef.md)<br/>
[isinf](isinf.md)<br/>
[isnan, _isnan, _isnanf](isnan-isnan-isnanf.md)<br/>
[_fpclass, _fpclassf](fpclass-fpclassf.md)<br/>
