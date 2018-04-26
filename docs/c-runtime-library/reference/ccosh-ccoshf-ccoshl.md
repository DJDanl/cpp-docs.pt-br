---
title: ccosh, ccoshf, ccoshl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- ccosh
- ccoshf
- ccoshl
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
- ccosh
- ccoshf
- ccoshl
- complex/ccosh
- complex/ccoshf
- complex/ccoshl
dev_langs:
- C++
helpviewer_keywords:
- ccosh function
- ccoshf function
- ccoshl function
ms.assetid: 79667449-4edf-4948-bf6b-720adf2b3f3b
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b78287c719e7da2e0e5a314a2e5bca77f3bdc9ff
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="ccosh-ccoshf-ccoshl"></a>ccosh, ccoshf, ccoshl

Recupera o cosseno hiperbólico de um número complexo.

## <a name="syntax"></a>Sintaxe

```C
_Dcomplex ccosh(
   _Dcomplex z
);
_Fcomplex ccosh(
   _Fcomplex z
);  // C++ only
_Lcomplex ccosh(
   _Lcomplex z
);  // C++ only
_Fcomplex ccoshf(
   _Fcomplex z
);
_Lcomplex ccoshl(
   _Lcomplex z
);
```

### <a name="parameters"></a>Parâmetros

*z*<br/>
Um número complexo que representa o ângulo, em radianos.

## <a name="return-value"></a>Valor de retorno

O cosseno hiperbólico de *z*, em radianos.

## <a name="remarks"></a>Comentários

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **ccosh** que levar e retornar **_Fcomplex** e **_Lcomplex** valores. Em um programa C, **ccosh** sempre usa e retorna um **_Dcomplex** valor.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho C|Cabeçalho C++|
|-------------|--------------|------------------|
|**ccosh**, **ccoshf**, **ccoshl**|\<complex.h>|\<ccomplex>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[catanh, catanhf, catanhl](catanh-catanhf-catanhl.md)<br/>
[ctanh, ctanhf, ctanhl](ctanh-ctanhf-ctanhl.md)<br/>
[catan, catanf, catanl](catan-catanf-catanl.md)<br/>
[csinh, csinhf, csinhl](csinh-csinhf-csinhl.md)<br/>
[casinh, casinhf, casinhl](casinh-casinhf-casinhl.md)<br/>
[cacosh, cacoshf, cacoshl](cacosh-cacoshf-cacoshl.md)<br/>
[cacos, cacosf, cacosl](cacos-cacosf-cacosl.md)<br/>
[ctan, ctanf, ctanl](ctan-ctanf-ctanl.md)<br/>
[csin, csinf, csinl](csin-csinf-csinl.md)<br/>
[casin, casinf, casinl](casin-casinf-casinl.md)<br/>
[ccos, ccosf, ccosl](ccos-ccosf-ccosl.md)<br/>
[csqrt, csqrtf, csqrtl](csqrt-csqrtf-csqrtl.md)<br/>
