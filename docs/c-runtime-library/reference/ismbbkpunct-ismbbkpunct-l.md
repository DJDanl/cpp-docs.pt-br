---
title: _ismbbkpunct, _ismbbkpunct_l
ms.date: 4/2/2020
api_name:
- _ismbbkpunct_l
- _ismbbkpunct
- _o__ismbbkpunct
- _o__ismbbkpunct_l
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
- api-ms-win-crt-multibyte-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- ismbbkpunct_l
- _ismbbkpunct_l
- ismbbkpunct
- _ismbbkpunct
helpviewer_keywords:
- _ismbbkpunct_l function
- ismbbkpunct_l function
- ismbbkpunct function
- _ismbbkpunct function
ms.assetid: a04c59cd-5ca7-4296-bec0-2b0d7f04edd0
ms.openlocfilehash: 8cf2d0d38466c370d0110b71a302471679e64657
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82915699"
---
# <a name="_ismbbkpunct-_ismbbkpunct_l"></a>_ismbbkpunct, _ismbbkpunct_l

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

*&*<br/>
Inteiro a ser testado.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor retornado

**_ismbbkpunct** retornará um valor diferente de zero se o inteiro *c* for um símbolo de pontuação não-ASCII ou 0 se não for. Por exemplo, somente na página de código 932, **_ismbbkpunct** testa se há pontuação katakana. **_ismbbkpunct** usa a localidade atual para qualquer configuração de caractere dependente de localidade. **_ismbbkpunct_l** é idêntico, exceto pelo fato de que ele usa a localidade passada. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

## <a name="remarks"></a>Comentários

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_ismbbkpunct**|\<mbctype.h>|
|**_ismbbkpunct_l**|\<mbctype.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Classificação de byte](../../c-runtime-library/byte-classification.md)<br/>
[Rotinas de _ismbb](../../c-runtime-library/ismbb-routines.md)<br/>
