---
title: _Cmulcr, _FCmulcr, _LCmulcr | Microsoft Docs
ms.custom: ''
ms.date: 03/30/2018
ms.technology:
- cpp
- devlang-cpp
ms.topic: reference
apiname:
- _Cmulcr
- _FCmulcr
- _LCmulcr
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
- _Cmulcr
- _FCmulcr
- _LCmulcr
- complex/_Cmulcr
- complex/_FCmulcr
- complex/_LCmulcr
dev_langs:
- C++
helpviewer_keywords:
- _Cmulcr function
- _FCmulcr function
- _LCmulcr function
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a1de966b1eb5bd48d4a3120d23c9ffc0de647956
ms.sourcegitcommit: 0523c88b24d963c33af0529e6ba85ad2c6ee5afb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/08/2018
---
# <a name="cmulcr-fcmulcr-lcmulcr"></a>_Cmulcr, _FCmulcr, _LCmulcr

Multiplica um número complexo por um número de ponto flutuante.

## <a name="syntax"></a>Sintaxe

```C
_Dcomplex _Cmulcr( _Dcomplex x, double y );
_Fcomplex _FCmulcr( _Fcomplex x, float y );
_Lcomplex _LCmulcr( _Lcomplex x, long double y );
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Um dos operandos complexos para multiplicar.

*y*<br/>
O operando de ponto flutuante para multiplicar.

## <a name="return-value"></a>Valor de retorno

Um **_Dcomplex**, **_Fcomplex**, ou **_Lcomplex** estrutura que representa o produto complexo de número complexo *x* e número de ponto de flaoting *y*.

## <a name="remarks"></a>Comentários

Como os operadores aritméticos internos não funciona na implementação da Microsoft de tipos complexos, o **_Cmulcr**, **_FCmulcr**, e **_LCmulcr** funções simplifica a multiplicação de tipos complexos por tipos de ponto flutuante.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho C|Cabeçalho C++|
|-------------|--------------|------------------|
|`_Cmulcr`,`_FCmulcr`, `_LCmulcr`|\<complex.h>|\<ccomplex>|

Essas funções são específicas da Microsoft. Os tipos de **_Dcomplex**, **_Fcomplex**, e **_Lcomplex** são equivalentes específicas da Microsoft para os tipos nativos de C99 não implementados **Complex duplo** , **float Complex**, e **Complex long double**, respectivamente. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)<br/>
[_Cbuild, _FCbuild, _LCbuild](../../c-runtime-library/reference/cbuild-fcbuild-lcbuild.md)<br/>
[_Cmulcc, _FCmulcc, _LCmulcc](../../c-runtime-library/reference/cmulcc-fcmulcc-lcmulcc.md)<br/>
[norm, normf, norml](../../c-runtime-library/reference/norm-normf-norml1.md)<br/>
[cproj, cprojf, cprojl](../../c-runtime-library/reference/cproj-cprojf-cprojl.md)<br/>
[conj, conjf, conjl](../../c-runtime-library/reference/conj-conjf-conjl.md)<br/>
[creal, crealf, creall](../../c-runtime-library/reference/creal-crealf-creall.md)<br/>
[cimag, cimagf, cimagl](../../c-runtime-library/reference/cimag-cimagf-cimagl.md)<br/>
[carg, cargf, cargl](../../c-runtime-library/reference/carg-cargf-cargl.md)<br/>
[cabs, cabsf, cabsl](../../c-runtime-library/reference/cabs-cabsf-cabsl.md)<br/>
