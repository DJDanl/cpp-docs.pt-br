---
title: _ismbbkprint, _ismbbkprint_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _ismbbkprint
- _ismbbkprint_l
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
- _ismbbkprint_l
- ismbbkprint
- _ismbbkprint
- ismbbkprint_l
dev_langs:
- C++
helpviewer_keywords:
- _ismbbkprint function
- ismbbkprint_l function
- ismbbkprint function
- _ismbbkprint_l function
ms.assetid: 8d1d3258-1e34-4365-81ed-97c95de25475
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a1309b86415d58d4f6c0bc94ae2ec03ab515341c
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="ismbbkprint-ismbbkprintl"></a>_ismbbkprint, _ismbbkprint_l

Determina se um dado caractere multibyte é um símbolo de pontuação.

## <a name="syntax"></a>Sintaxe

```C
int _ismbbkprint(
   unsigned int c
);
int _ismbbkprint_l(
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

**ismbbkprint** retorna um valor diferente de zero se o número inteiro *c* é um texto não-ASCII ou símbolo de pontuação não-ASCII ou 0 se não for. Por exemplo, na página de código 932 somente **ismbbkprint** testes para katakana alfanumérico ou pontuação katakana (intervalo: 0xA1 - 0xDF). **ismbbkprint** usa a localidade atual para configurações de caractere dependente de localidade. **ismbbkprint_l** é idêntico, exceto que ele usa a localidade passada. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_ismbbkprint**|\<mbctype.h>|
|**_ismbbkprint_l**|\<mbctype.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Classificação de byte](../../c-runtime-library/byte-classification.md)<br/>
[Rotinas _ismbb](../../c-runtime-library/ismbb-routines.md)<br/>
