---
title: ilogb, ilogbf, ilogbl2
ms.date: 04/05/2018
apiname:
- ilogb
- ilogbf
- ilogbl
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
ms.openlocfilehash: 272544124dd8a8a666fc434516d3c45c73b1d011
ms.sourcegitcommit: afd6fac7c519dbc47a4befaece14a919d4e0a8a2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2018
ms.locfileid: "51519562"
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

Se for bem-sucedido, retorna o expoente de base 2 de *x* como com um sinal **int** valor.

Caso contrário, retorna um dos valores a seguir, definidos em É um dos valores a seguir, definidos em \<math.h>:

|Entrada|Resultado|
|-----------|------------|
|±0|FP_ILOGB0|
|±inf, ±nan, indefinido|FP_ILOGBNAN|

Os erros são relatados conforme especificado em [_matherr](matherr.md).

## <a name="remarks"></a>Comentários

Como C++ permite sobrecargas, é possível chamar sobrecargas de **ilogb** que usam e retornam **float** e **longo** **double** tipos. Em um programa do C **ilogb** sempre usa e retorna um **duplo**.

Chamar essa função é semelhante a chamar o equivalente **logb** função, em seguida, converter o valor de retorno **int**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho C|Cabeçalho C++|
|-------------|--------------|------------------|
|**ilogb**, **ilogbf**, **ilogbl**|\<math.h>|\<cmath>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[frexp](frexp.md)<br/>
[logb, logbf, logbl, _logb, _logbf](logb-logbf-logbl-logb-logbf.md)<br/>
