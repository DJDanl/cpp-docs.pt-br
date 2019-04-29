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
ms.openlocfilehash: 748360cae1dd0ee43645dee369c60c835246ed03
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62333697"
---
# <a name="isgreater-isgreaterequal-isless-islessequal-islessgreater-isunordered"></a>isgreater, isgreaterequal, isless, islessequal, islessgreater, isunordered

Determina a relação entre dois valores de ponto flutuantes de ordenação.

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

### <a name="parameters"></a>Parâmetros

*x*, *y*<br/>
Os valores de ponto flutuantes a ser comparado.

## <a name="return-value"></a>Valor de retorno

Em todas as comparações, infinitos do sinal de mesmo comparam como iguais. Infinito negativo é menor do que qualquer valor finito ou infinito positivo. Infinito positivo é maior do que qualquer valor finito ou infinito negativo. Zeros são iguais, independentemente da entrada. NaNs não são menor, igual ou maior que qualquer valor, incluindo outra NaN.

Quando nenhum argumento for NaN, as macros de ordenação **isgreater**, **isgreaterequal**, **isless**, e **islessequal** de retorno diferente de zero valor se a relação especificada de ordenação entre *x* e *y* se aplica. Essas macros retornam 0 se um ou ambos os argumentos são NaNs ou se a relação de ordenação é false. Os formulários de função se comportam da mesma forma, mas retornam **verdadeira** ou **falso**.

O **islessgreater** macro retorna um valor diferente de zero se *x* e *y* não são NaNs, e *x* é menor que ou maior que *y*. Ele retorna 0 se um ou ambos os argumentos são NaNs, ou se os valores forem iguais. O formulário de função se comporta da mesma forma, mas retorna **verdadeira** ou **falso**.

O **isunordered** macro retorna um valor diferente de zero se *x*, *y*, ou ambos são NaNs. Caso contrário, retorna 0. O formulário de função se comporta da mesma forma, mas retorna **verdadeira** ou **falso**.

## <a name="remarks"></a>Comentários

Essas operações de comparação são implementadas como macros quando compilado como C e como as funções de modelo embutidos quando compilada como C++.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|--------------|---------------------------|-------------------------------|
| **isgreater**, **isgreaterequal**, **isless**,<br/>**islessequal**, **islessgreater**, **isunordered** | \<math.h> | \<math.h> ou \<cmath> |

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[isfinite, _finite, _finitef](finite-finitef.md)<br/>
[isinf](isinf.md)<br/>
[isnan, _isnan, _isnanf](isnan-isnan-isnanf.md)<br/>
[_fpclass, _fpclassf](fpclass-fpclassf.md)<br/>
