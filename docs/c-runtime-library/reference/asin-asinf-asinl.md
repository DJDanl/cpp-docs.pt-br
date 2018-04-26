---
title: asin, asinf, asinl | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- asinf
- asinl
- asin
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
- asin
- asinl
- asinf
dev_langs:
- C++
helpviewer_keywords:
- asin function
- asinl function
- asinf function
- trigonometric functions
- arcsine function
ms.assetid: ca05f9ea-b711-49f6-9f32-2f4019abfd69
caps.latest.revision: 14
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6dd1399042e1055d124cd3c53363a6979d4256d3
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="asin-asinf-asinl"></a>asin, asinf, asinl

Calcula o arco seno.

## <a name="syntax"></a>Sintaxe

```C
double asin( double x );
float asinf ( float x );
long double asinl( long double x );
```

```cpp
float asin( float x );  // C++ only
long double asin( long double x );  // C++ only
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Valor cujo arco seno é calculado.

## <a name="return-value"></a>Valor de retorno

O **asin** função retorna o arco seno (a função de seno inverso) de *x* no intervalo - π/2 a π/2 radianos.

Por padrão, se *x* é menor que -1 ou maior que 1, **asin** retorna um indefinido.

|Entrada|Exceção SEH|Exceção Matherr|
|-----------|-------------------|-----------------------|
|± ∞|**INVÁLIDO**|**DOMAIN**|
|± **QNAN**, **IND**|nenhum|**DOMAIN**|
|&#124;x&#124;>1|**INVÁLIDO**|**DOMAIN**|

## <a name="remarks"></a>Comentários

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **asin** com **float** e **longo** **duplo** valores. Em um programa C, **asin** sempre usa e retorna um **duplo**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|-------------|---------------------|-|
|**ASIN**, **asinf**, **asinl**|\<math.h>|\<cmath> ou \<math.h>|

## <a name="example"></a>Exemplo

Para obter mais informações, consulte [acos, acosf, acosl](acos-acosf-acosl.md).

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[acos, acosf, acosl](acos-acosf-acosl.md)<br/>
[atan, atanf, atanl, atan2, atan2f, atan2l](atan-atanf-atanl-atan2-atan2f-atan2l.md)<br/>
[cos, cosf, cosl](cos-cosf-cosl.md)<br/>
[_matherr](matherr.md)<br/>
[sin, sinf, sinl](sin-sinf-sinl.md)<br/>
[tan, tanf, tanl](tan-tanf-tanl.md)<br/>
