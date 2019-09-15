---
title: norm, normf, norml
ms.date: 04/05/2018
api_name:
- norm
- normf
- norml
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
- norm
- normf
- norml
- complex/norm
- complex/normf
- complex/norml
helpviewer_keywords:
- norm function
- normf function
- norml function
ms.assetid: 9786ecfe-0019-4553-b378-0af6c691e15c
ms.openlocfilehash: 8deaa07d984a3840c73e594535ffffc9078d4716
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70951313"
---
# <a name="norm-normf-norml"></a>norm, normf, norml

Recupera a magnitude quadrada de um número complexo.

## <a name="syntax"></a>Sintaxe

```C
double norm( _Dcomplex z );
float normf( _Fcomplex z );
long double norml( _Lcomplex z );
```

```cpp
float norm( _Fcomplex z );  // C++ only
long double norm( _Lcomplex z );  // C++ only
```

### <a name="parameters"></a>Parâmetros

*z*<br/>
Um número complexo.

## <a name="return-value"></a>Valor de retorno

A magnitude quadrada de *z*.

## <a name="remarks"></a>Comentários

Como C++ o permite sobrecarga, você pode chamar sobrecargas de **norma** que usam valores **_Fcomplex** ou **_Lcomplex** e retornar valores **duplos** **float** ou Long. Em um programa C, a **norma** sempre usa um valor **_Dcomplex** e retorna um valor **duplo** .

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho C|Cabeçalho C++|
|-------------|--------------|------------------|
|**norm**, **normf**, **norml**|\<complex.h>|\<complex.h>|

Os tipos **_Fcomplex**, **_Dcomplex**e **_Lcomplex** são equivalentes específicos da Microsoft dos tipos de C99 nativos não implementados **float _Complex**, **Double _Complex**e **Long duplo _Complex**, respectivamente.  Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[creal, crealf, creall](creal-crealf-creall.md)<br/>
[cproj, cprojf, cprojl](cproj-cprojf-cprojl.md)<br/>
[conj, conjf, conjl](conj-conjf-conjl.md)<br/>
[cimag, cimagf, cimagl](cimag-cimagf-cimagl.md)<br/>
[carg, cargf, cargl](carg-cargf-cargl.md)<br/>
[cabs, cabsf, cabsl](cabs-cabsf-cabsl.md)<br/>
