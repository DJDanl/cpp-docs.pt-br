---
title: _ismbbkalnum, _ismbbkalnum_l
ms.date: 4/2/2020
api_name:
- _ismbbkalnum
- _ismbbkalnum_l
- _o__ismbbkalnum
- _o__ismbbkalnum_l
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
- _ismbbkalnum
- ismbbkalnum
- ismbbkalnum_l
- _ismbbkalnum_l
helpviewer_keywords:
- _ismbbkalnum_l function
- ismbbkalnum_l function
- _ismbbkalnum function
- ismbbkalnum function
ms.assetid: e1d70e7b-29d0-469c-9d93-442b99de22ac
ms.openlocfilehash: 25ce3420ec3fb92701c4ed7cd596c2103c33ac54
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82909514"
---
# <a name="_ismbbkalnum-_ismbbkalnum_l"></a>_ismbbkalnum, _ismbbkalnum_l

Determina se um dado caractere multibyte é um símbolo de texto não ASCII.

## <a name="syntax"></a>Sintaxe

```C
int _ismbbkalnum(
   unsigned int c
);
int _ismbbkalnum_l(
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

**_ismbbkalnum** retornará um valor diferente de zero se o inteiro *c* for um símbolo de texto não-ASCII diferente de pontuação, ou 0 se não for. **_ismbbkalnum** usa a localidade atual para informações de caracteres dependentes de localidade. **_ismbbkalnum_l** é idêntico ao **_ismbbkalnum** , exceto pelo fato de que ele usa a localidade como um parâmetro. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

## <a name="remarks"></a>Comentários

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_ismbbkalnum**|\<mbctype.h>|
|**_ismbbkalnum_l**|\<mbctype.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Classificação de byte](../../c-runtime-library/byte-classification.md)<br/>
[Rotinas de _ismbb](../../c-runtime-library/ismbb-routines.md)<br/>
