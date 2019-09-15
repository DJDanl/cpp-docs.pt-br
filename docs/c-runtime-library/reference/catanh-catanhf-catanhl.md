---
title: catanh, catanhf, catanhl
ms.date: 11/04/2016
api_name:
- catanh
- catanhf
- catanhl
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
- catanh
- catanhf
- catanhl
- complex/catanh
- complex/catanhf
- complex/catanhl
helpviewer_keywords:
- catanh function
- catanhf function
- catanhl function
ms.assetid: 1b6021cb-647a-41b4-9d7f-919cc8b57b86
ms.openlocfilehash: 9b21427eb4ab1a3ec8eab10d52e636bf253bc947
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70943228"
---
# <a name="catanh-catanhf-catanhl"></a>catanh, catanhf, catanhl

Recupera a tangente hiperbólica inversa de um número complexo, com os cortes de ramificação fora do intervalo [-1; + 1] ao longo do eixo real.

## <a name="syntax"></a>Sintaxe

```C
_Dcomplex catanh(
   _Dcomplex z
);
_Fcomplex catanh(
   _Fcomplex z
);  // C++ only
_Lcomplex catanh(
   _Lcomplex z
);  //  C++ only
_Fcomplex catanhf(
   _Fcomplex z
);
_Lcomplex catanhl(
   _Lcomplex z
);
```

### <a name="parameters"></a>Parâmetros

*z*<br/>
Um número complexo que representa um ângulo, em radianos.

## <a name="return-value"></a>Valor de retorno

A tangente hiperbólica inversa de *z*, em radianos. O resultado é não associado ao longo do eixo real e no intervalo [-iπ/2; + iπ/2] ao longo do eixo imaginário. Um erro de domínio ocorrerá se *z* estiver fora do intervalo [-1, + 1]. Um erro de pólo ocorrerá se *z* for-1 ou + 1.

## <a name="remarks"></a>Comentários

Como C++ o permite sobrecarga, você pode chamar sobrecargas de **catanh** que usam e retornam valores **_Fcomplex** e **_Lcomplex** . Em um programa C, **catanh** sempre pega e retorna um valor **_Dcomplex** .

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho C|Cabeçalho C++|
|-------------|--------------|------------------|
|**catanh**,               **catanhf**, **catanhl**|\<complex.h>|\<ccomplex>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[ctanh, ctanhf, ctanhl](ctanh-ctanhf-ctanhl.md)<br/>
[catan, catanf, catanl](catan-catanf-catanl.md)<br/>
[csinh, csinhf, csinhl](csinh-csinhf-csinhl.md)<br/>
[casinh, casinhf, casinhl](casinh-casinhf-casinhl.md)<br/>
[ccosh, ccoshf, ccoshl](ccosh-ccoshf-ccoshl.md)<br/>
[cacosh, cacoshf, cacoshl](cacosh-cacoshf-cacoshl.md)<br/>
[cacos, cacosf, cacosl](cacos-cacosf-cacosl.md)<br/>
[ctan, ctanf, ctanl](ctan-ctanf-ctanl.md)<br/>
[csin, csinf, csinl](csin-csinf-csinl.md)<br/>
[casin, casinf, casinl](casin-casinf-casinl.md)<br/>
[ccos, ccosf, ccosl](ccos-ccosf-ccosl.md)<br/>
[csqrt, csqrtf, csqrtl](csqrt-csqrtf-csqrtl.md)<br/>
