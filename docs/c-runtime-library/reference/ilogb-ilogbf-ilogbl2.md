---
title: ilogb, ilogbf, ilogbl2
ms.date: 04/05/2018
api_name:
- ilogb
- ilogbf
- ilogbl
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
- ilogb
- ilogbf
- ilogbl
- math/ilogb
- math/ilogbf
- math/ilogbl
helpviewer_keywords:
- ilogb function
- ilogbf function
- ilogbl function
ms.assetid: 9ef19d57-1caa-41d5-8233-2faad3562fcb
ms.openlocfilehash: fdafba039537358c9b6a1de21dc176ceea38b4fa
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70954759"
---
# <a name="ilogb-ilogbf-ilogbl"></a>ilogb, ilogbf, ilogbl

Recupera um inteiro que representa o expoente de base 2 neutro do valor especificado.

## <a name="syntax"></a>Sintaxe

```C
int ilogb(
   double x
);

int ilogb(
   float x
); //C++ only

int ilogb(
   long double x
); //C++ only

int ilogbf(
   float x
);

int ilogbl(
   long double x
);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O valor especificado.

## <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, retorna o expoente de base 2 de *x* como um valor **int** assinado.

Caso contrário, retorna um dos valores a seguir, definidos em É um dos valores a seguir, definidos em \<math.h>:

|Entrada|Resultado|
|-----------|------------|
|±0|FP_ILOGB0|
|±inf, ±nan, indefinido|FP_ILOGBNAN|

Os erros são relatados conforme especificado em [_matherr](matherr.md).

## <a name="remarks"></a>Comentários

Como C++ o permite sobrecarga, você pode chamar sobrecargas de **ilogb** que usam e retornam tipos **float** e **Long** **duplos** . Em um programa C, **ilogb** sempre pega e retorna um **Double**.

Chamar essa função é semelhante a chamar a função **logb** equivalente e, em seguida, converter o valor de retorno em **int**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho C|Cabeçalho C++|
|-------------|--------------|------------------|
|**ilogb**, **ilogbf**, **ilogbl**|\<math.h>|\<cmath>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[frexp](frexp.md)<br/>
[logb, logbf, logbl, _logb, _logbf](logb-logbf-logbl-logb-logbf.md)<br/>
