---
title: _ismbbtrail, _ismbbtrail_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _ismbbtrail
- _ismbbtrail_l
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
- _ismbbtrail
- ismbbtrail
- _ismbbtrail_l
- ismbbtrail_l
dev_langs:
- C++
helpviewer_keywords:
- ismbbtrail_l function
- _ismbbtrail function
- _ismbbtrail_l function
- ismbbtrail function
ms.assetid: dfdd0292-960b-4c1d-bf11-146e0fc80247
caps.latest.revision: 22
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5b062dff3ef38743af21e2dcf75ea1cfb4a8c921
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="ismbbtrail-ismbbtraill"></a>_ismbbtrail, _ismbbtrail_l

Determina se um byte é um byte à direita de um caractere multibyte.

## <a name="syntax"></a>Sintaxe

```C
int _ismbbtrail(
   unsigned int c
);
int _ismbbtrail_l(
   unsigned int c,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*c*<br/>
O inteiro a ser testado.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor de retorno

**ismbbtrail** retorna um valor diferente de zero se o número inteiro *c* é o segundo byte de um caractere multibyte. Por exemplo, somente na página de código 932, os intervalos válidos são 0x40 a 0x7E e 0x80 a 0xFC.

## <a name="remarks"></a>Comentários

**ismbbtrail** usa a localidade atual para o comportamento dependente de localidade. **ismbbtrail_l** é idêntico, exceto que ele usa a localidade que é transmitida em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_ismbbtrail**|\<mbctype.h> ou \<mbstring.h>|\<ctype.h>,* \<limits.h>, \<stdlib.h>|
|**_ismbbtrail_l**|\<mbctype.h> ou \<mbstring.h>|\<ctype.h>,* \<limits.h>, \<stdlib.h>|

\* Para constantes de manifesto para as condições de teste.

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Classificação de byte](../../c-runtime-library/byte-classification.md)<br/>
[Rotinas _ismbb](../../c-runtime-library/ismbb-routines.md)<br/>
