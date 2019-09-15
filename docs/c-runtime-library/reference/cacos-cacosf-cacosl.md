---
title: cacos, cacosf, cacosl
ms.date: 11/04/2016
api_name:
- cacos
- cacosf
- cacosl
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
- cacos
- cacosf
- cacosl
- complex/cacos
- complex/cacosf
- complex/cacosl
helpviewer_keywords:
- cacos function
- cacosf function
- cacosl function
ms.assetid: 78118c00-0a07-49c1-8a13-4bf19ce3aea8
ms.openlocfilehash: 5b0751703b9b9cdcdb50e265a6b5d3c929d89ae1
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70939393"
---
# <a name="cacos-cacosf-cacosl"></a>cacos, cacosf, cacosl

Recupera o arco cosseno de um número complexo, com recortes de ramificação fora do intervalo [-1, + 1] ao longo do eixo real.

## <a name="syntax"></a>Sintaxe

```C
_Dcomplex cacos( _Dcomplex z );
_Fcomplex cacosf( _Fcomplex z );
_Lcomplex cacosl( _Lcomplex z );
```

```cpp
_Fcomplex cacos( _Fcomplex z );  // C++ only
_Lcomplex cacos( _Lcomplex z );  // C++ only
```

### <a name="parameters"></a>Parâmetros

*z*<br/>
Um número complexo que representa um ângulo, em radianos.

## <a name="return-value"></a>Valor de retorno

O arco cosseno de *z*, em radianos. O resultado é ilimitado ao longo do eixo imaginário e no intervalo [0, π] ao longo do eixo real. Um erro de domínio ocorrerá se *z* estiver fora do intervalo [-1, + 1].

## <a name="remarks"></a>Comentários

Como C++ o permite sobrecarga, você pode chamar sobrecargas de **cacos** que usam e retornam valores **_Fcomplex** e **_Lcomplex** . Em um programa C, **cacos** sempre pega e retorna um valor **_Dcomplex** .

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho C|Cabeçalho C++|
|-------------|--------------|------------------|
|**cacos**,               **cacosf**, **cacosl**|\<complex.h>|\<ccomplex>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[catanh, catanhf, catanhl](catanh-catanhf-catanhl.md)<br/>
[ctanh, ctanhf, ctanhl](ctanh-ctanhf-ctanhl.md)<br/>
[catan, catanf, catanl](catan-catanf-catanl.md)<br/>
[csinh, csinhf, csinhl](csinh-csinhf-csinhl.md)<br/>
[casinh, casinhf, casinhl](casinh-casinhf-casinhl.md)<br/>
[ccosh, ccoshf, ccoshl](ccosh-ccoshf-ccoshl.md)<br/>
[cacosh, cacoshf, cacoshl](cacosh-cacoshf-cacoshl.md)<br/>
[ctan, ctanf, ctanl](ctan-ctanf-ctanl.md)<br/>
[csin, csinf, csinl](csin-csinf-csinl.md)<br/>
[casin, casinf, casinl](casin-casinf-casinl.md)<br/>
[ccos, ccosf, ccosl](ccos-ccosf-ccosl.md)<br/>
[csqrt, csqrtf, csqrtl](csqrt-csqrtf-csqrtl.md)<br/>
