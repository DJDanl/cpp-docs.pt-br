---
title: _Cbuild, _FCbuild, _LCbuild | Microsoft Docs
ms.custom: ''
ms.date: 03/30/2018
ms.technology:
- cpp
- devlang-cpp
ms.topic: reference
apiname:
- _Cbuild
- _FCbuild
- _LCbuild
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
- _Cbuild
- _FCbuild
- _LCbuild
- complex/_Cbuild
- complex/_FCbuild
- complex/_LCbuild
dev_langs:
- C++
helpviewer_keywords:
- _Cbuild function
- _FCbuild function
- _LCbuild function
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 555cd1d9d8f22801b1d3f3341be9041b1dde548c
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="cbuild-fcbuild-lcbuild"></a>_Cbuild, _FCbuild, _LCbuild

Constrói um número complexo de partes reais e imaginários.

## <a name="syntax"></a>Sintaxe

```C
_Dcomplex _Cbuild( double real, double imaginary );
_Fcomplex _FCbuild( float real, float imaginary );
_Lcomplex _LCbuild( long double real, long double imaginary );
```

### <a name="parameters"></a>Parâmetros

*real*<br/>
A parte real do número complexo para construir.

*imaginary*<br/>
A parte imaginária do número complexo para construir.

## <a name="return-value"></a>Valor de retorno

Um **_Dcomplex**, **_Fcomplex**, ou **_Lcomplex** estrutura que representa o número complexo (*real*, *imaginário*  \* i) para valores do tipo de ponto flutuante especificado.

## <a name="remarks"></a>Comentários

O **_Cbuild**, **_FCbuild**, e **_LCbuild** funções simplificam a criação de tipos complexos. Use o [creal, crealf, creall](creal-crealf-creall.md) e [cimag, cimagf, cimagl](cimag-cimagf-cimagl.md) funções para recuperar as partes reais e imaginários dos números complexos representados.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho C|Cabeçalho C++|
|-------------|--------------|------------------|
|**_Cbuild**, **_FCbuild**, **_LCbuild**|\<complex.h>|\<ccomplex>|

Essas funções são específicas da Microsoft. Os tipos de **_Dcomplex**, **_Fcomplex**, e **_Lcomplex** são equivalentes específicas da Microsoft para os tipos nativos de C99 não implementados **Complex duplo** , **float Complex**, e **Complex long double**, respectivamente. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[_Cmulcc, _FCmulcc, _LCmulcc](cmulcc-fcmulcc-lcmulcc.md)<br/>
[_Cmulcr, _FCmulcr, _LCmulcr](cmulcr-fcmulcr-lcmulcr.md)<br/>
[norm, normf, norml](norm-normf-norml1.md)<br/>
[cproj, cprojf, cprojl](cproj-cprojf-cprojl.md)<br/>
[conj, conjf, conjl](conj-conjf-conjl.md)<br/>
[creal, crealf, creall](creal-crealf-creall.md)<br/>
[cimag, cimagf, cimagl](cimag-cimagf-cimagl.md)<br/>
[carg, cargf, cargl](carg-cargf-cargl.md)<br/>
[cabs, cabsf, cabsl](cabs-cabsf-cabsl.md)<br/>
