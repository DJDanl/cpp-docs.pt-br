---
title: _Cbuild, _FCbuild, _LCbuild
ms.date: 03/30/2018
api_name:
- _Cbuild
- _FCbuild
- _LCbuild
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
- _Cbuild
- _FCbuild
- _LCbuild
- complex/_Cbuild
- complex/_FCbuild
- complex/_LCbuild
helpviewer_keywords:
- _Cbuild function
- _FCbuild function
- _LCbuild function
ms.openlocfilehash: d521fdb0d79e1e4ff6e6c1b01ce40941ed5c8c0a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221959"
---
# <a name="_cbuild-_fcbuild-_lcbuild"></a>_Cbuild, _FCbuild, _LCbuild

Constrói um número complexo de partes reais e imaginários.

## <a name="syntax"></a>Sintaxe

```C
_Dcomplex _Cbuild( double real, double imaginary );
_Fcomplex _FCbuild( float real, float imaginary );
_Lcomplex _LCbuild( long double real, long double imaginary );
```

### <a name="parameters"></a>parâmetros

*real*<br/>
A parte real do número complexo a ser construído.

*imaginar*<br/>
A parte imaginário do número complexo a ser construído.

## <a name="return-value"></a>Valor retornado

Uma **_Dcomplex**, **_Fcomplex**ou **_Lcomplex** estrutura que representa o número complexo (*real*, *imaginário* \* ) para valores do tipo de ponto flutuante especificado.

## <a name="remarks"></a>Comentários

As funções **_Cbuild**, **_FCbuild**e **_LCbuild** simplificam a criação de tipos complexos. Use as funções [Creal, crealf, creall](creal-crealf-creall.md) e [Cimag, cimagf, cimagl](cimag-cimagf-cimagl.md) para recuperar as partes reais e imaginários dos números complexos representados.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho C|Cabeçalho C++|
|-------------|--------------|------------------|
|**_Cbuild**, **_FCbuild**, **_LCbuild**|\<complex.h>|\<ccomplex>|

Essas funções são específicas da Microsoft. Os tipos **_Dcomplex**, **_Fcomplex**e **_Lcomplex** são equivalentes específicos da Microsoft aos tipos nativos C99 não implementados **`double _Complex`** , **`float _Complex`** e **`long double _Complex`** , respectivamente. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Referência de função alfabética](crt-alphabetical-function-reference.md)<br/>
[_Cmulcc, _FCmulcc, _LCmulcc](cmulcc-fcmulcc-lcmulcc.md)<br/>
[_Cmulcr, _FCmulcr, _LCmulcr](cmulcr-fcmulcr-lcmulcr.md)<br/>
[norm, normf, norml](norm-normf-norml1.md)<br/>
[cproj, cprojf, cprojl](cproj-cprojf-cprojl.md)<br/>
[conj, conjf, conjl](conj-conjf-conjl.md)<br/>
[creal, crealf, creall](creal-crealf-creall.md)<br/>
[cimag, cimagf, cimagl](cimag-cimagf-cimagl.md)<br/>
[carg, cargf, cargl](carg-cargf-cargl.md)<br/>
[cabs, cabsf, cabsl](cabs-cabsf-cabsl.md)<br/>
