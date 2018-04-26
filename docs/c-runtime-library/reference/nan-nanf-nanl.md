---
title: nan, nanf, nanl | Microsoft Docs
ms.custom: ''
ms.date: 94/05/2018
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- nanf
- nan
- nanl
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
- nan
- nanl
- nanf
dev_langs:
- C++
helpviewer_keywords:
- nan function
- nanf function
- nanl function
ms.assetid: 790e9158-80ab-43e0-8f5a-096198553fd9
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e2fa378cdded71f0f99ad0fbe152d1282c9e6fe4
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="nan-nanf-nanl"></a>nan, nanf, nanl

Retorna um valor NaN silencioso.

## <a name="syntax"></a>Sintaxe

```C
double nan( const char* input );
float nanf( const char* input );
long double nanl( const char* input );
```

### <a name="parameters"></a>Parâmetros

*input*<br/>
Um valor da cadeia de caracteres.

## <a name="return-value"></a>Valor de retorno

O **nan** funções retornam um valor de NaN silencioso.

## <a name="remarks"></a>Comentários

O **nan** funções retornam um valor de ponto flutuante que corresponde a um NaN silencioso (sem sinal). O *entrada* valor é ignorado. Para obter informações sobre como um NaN é representado para saída, consulte [printf, _printf_l, wprintf, _wprintf_l](printf-printf-l-wprintf-wprintf-l.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**NaN**, **nanf**, **nanl**|\<math.h>|\<cmath> ou \<math.h>|

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[_finite, _finitef](finite-finitef.md)<br/>
[_fpclass, _fpclassf](fpclass-fpclassf.md)<br/>
[isnan, _isnan, _isnanf](isnan-isnan-isnanf.md)<br/>
