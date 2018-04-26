---
title: _ismbbkpunct, _ismbbkpunct_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _ismbbkpunct_l
- _ismbbkpunct
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
- api-ms-win-crt-multibyte-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- ismbbkpunct_l
- _ismbbkpunct_l
- ismbbkpunct
- _ismbbkpunct
dev_langs:
- C++
helpviewer_keywords:
- _ismbbkpunct_l function
- ismbbkpunct_l function
- ismbbkpunct function
- _ismbbkpunct function
ms.assetid: a04c59cd-5ca7-4296-bec0-2b0d7f04edd0
caps.latest.revision: 19
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 73f9ee94dc405163d09f100422d98c9e823f6c77
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="ismbbkpunct-ismbbkpunctl"></a>_ismbbkpunct, _ismbbkpunct_l

Verifica se um caractere multibyte é um caractere de pontuação.

## <a name="syntax"></a>Sintaxe

```C
int _ismbbkpunct(
   unsigned int c
);
int _ismbbkpunct_l(
   unsigned int c,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*c*<br/>
Inteiro a ser testado.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

**ismbbkpunct** retorna um valor diferente de zero se o número inteiro *c* é um símbolo de pontuação não-ASCII, ou 0 se não for. Por exemplo, na página de código 932 somente **ismbbkpunct** testes para pontuação katakana. **ismbbkpunct** usa a localidade atual para as configurações de caractere dependente de localidade. **ismbbkpunct_l** é idêntico, exceto que ele usa a localidade que é transmitida. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_ismbbkpunct**|\<mbctype.h>|
|**_ismbbkpunct_l**|\<mbctype.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Classificação de byte](../../c-runtime-library/byte-classification.md)<br/>
[Rotinas _ismbb](../../c-runtime-library/ismbb-routines.md)<br/>
