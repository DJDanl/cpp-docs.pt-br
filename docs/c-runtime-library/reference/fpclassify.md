---
title: fpclassify | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.topic: reference
apiname:
- fpclassify
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
apitype: HeaderDef
f1_keywords:
- fpclassify
- math/fpclassify
helpviewer_keywords:
- fpclassify macro
- fpclassify function
ms.assetid: bf549499-7ff9-4a58-8692-f2d1cb6bab81
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: da55cb87804d178d5a305ed466aa498de4bc1ee5
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32398426"
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

### <a name="parameters"></a>Parâmetros

*x*<br/>
O valor de ponto flutuante a ser testado.

## <a name="return-value"></a>Valor de retorno

**fpclassify** retorna um valor inteiro que indica a classe de ponto flutuante do argumento *x*. Esta tabela mostra os possíveis valores retornados por **fpclassify**, definido em \<math.h >.

|Valor|Descrição|
|-----------|-----------------|
|**FP_NAN**|Um NaN silencioso, indeterminado ou com sinalização|
|**FP_INFINITE**|Um infinito positivo ou negativo|
|**FP_NORMAL**|Um valor positivo ou negativo normalizado diferente de zero|
|**FP_SUBNORMAL**|Um valor positivo ou negativo desnormalizado|
|**FP_ZERO**|Um valor de zero positivo ou negativo|

## <a name="remarks"></a>Comentários

Em C, **fpclassify** é uma macro; em C++, **fpclassify** é uma função sobrecarregada usando tipos de argumento de **float**, **duplo**, ou **longo** **duplo**. Nos dois casos, o valor retornado depende do tipo efetivo da expressão de argumento e não de qualquer representação intermediária. Por exemplo, um normal **duplo** ou **longo** **duplo** valor pode se tornar um infinito, desnormalizado ou zero quando convertido em um **float**.

## <a name="requirements"></a>Requisitos

|Função/Macro|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|---------------------|---------------------------|-------------------------------|
|**fpclassify**|\<math.h>|\<math.h> ou \<cmath>|

O **fpclassify** macro e **fpclassify** funções em conformidade com o ISO C99 e especificações de 11 C + +. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[isnan, _isnan, _isnanf](isnan-isnan-isnanf.md)<br/>
