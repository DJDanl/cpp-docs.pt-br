---
title: fpclassify
ms.date: 04/05/2018
api_name:
- fpclassify
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
api_type:
- HeaderDef
f1_keywords:
- fpclassify
- math/fpclassify
helpviewer_keywords:
- fpclassify macro
- fpclassify function
ms.assetid: bf549499-7ff9-4a58-8692-f2d1cb6bab81
ms.openlocfilehash: 75cfdc33c21059e190fd04f4cd1b73716e74ac42
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213574"
---
# <a name="fpclassify"></a>fpclassify

Retorna a classificação de ponto flutuante do argumento.

## <a name="syntax"></a>Sintaxe

```C
int fpclassify(
   /* floating-point */ x
);

int fpclassify(
   float x
); // C++ only

int fpclassify(
   double x
); // C++ only

int fpclassify(
   long double x
); // C++ only
```

### <a name="parameters"></a>parâmetros

*x*<br/>
O valor de ponto flutuante a ser testado.

## <a name="return-value"></a>Valor retornado

**fpclassify** retorna um valor inteiro que indica a classe de ponto flutuante do argumento *x*. Esta tabela mostra os valores possíveis retornados por **fpclassify**, definidos em \<math.h> .

|Valor|Descrição|
|-----------|-----------------|
|**FP_NAN**|Um NaN silencioso, indeterminado ou com sinalização|
|**FP_INFINITE**|Um infinito positivo ou negativo|
|**FP_NORMAL**|Um valor positivo ou negativo normalizado diferente de zero|
|**FP_SUBNORMAL**|Um valor positivo ou negativo desnormalizado|
|**FP_ZERO**|Um valor de zero positivo ou negativo|

## <a name="remarks"></a>Comentários

Em C, **fpclassify** é uma macro; em C++, **fpclassify** é uma função sobrecarregada usando tipos de argumento de **`float`** , **`double`** ou **`long double`** . Nos dois casos, o valor retornado depende do tipo efetivo da expressão de argumento e não de qualquer representação intermediária. Por exemplo, um **`double`** valor normal **`long double`** pode se tornar um valor infinito, desnormal ou zero quando convertido em um **`float`** .

## <a name="requirements"></a>Requisitos

|Função/Macro|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|---------------------|---------------------------|-------------------------------|
|**fpclassify**|\<math.h>|\<math.h> ou \<cmath>|

A macro **fpclassify** e as funções **fpclassify** estão em conformidade com as especificações ISO C99 e c++ 11. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[isnan, _isnan, _isnanf](isnan-isnan-isnanf.md)<br/>
