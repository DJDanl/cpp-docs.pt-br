---
title: btowc | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- btowc
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
- api-ms-win-crt-convert-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- btowc
dev_langs:
- C++
helpviewer_keywords:
- btowc function
ms.assetid: 99a46e02-6f86-4569-af79-5feca012add8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4d0e56649218e6249550638af4e198cbd1284bc2
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32393310"
---
# <a name="btowc"></a>btowc

Determine se um inteiro representa um caractere de byte único válido no estado inicial do deslocamento.

## <a name="syntax"></a>Sintaxe

```C
wint_t btowc(
   int character
);
```

### <a name="parameters"></a>Parâmetros

*character*<br/>
Inteiro a ser testado.

## <a name="return-value"></a>Valor de retorno

Retornará a representação de caractere largo do caractere se o inteiro representar um caractere de byte único válido no estado inicial do deslocamento. Retornará WEOF se o inteiro for EOF ou não for um caractere de byte único válido no estado inicial do deslocamento. A saída dessa função é afetada por atual **LC_TYPE** localidade.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**btowc**|\<stdio.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[mbtowc, _mbtowc_l](mbtowc-mbtowc-l.md)<br/>
