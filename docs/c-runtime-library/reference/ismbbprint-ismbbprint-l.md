---
title: _ismbbprint, _ismbbprint_l
ms.date: 4/2/2020
api_name:
- _ismbbprint_l
- _ismbbprint
- _o__ismbbprint
- _o__ismbbprint_l
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
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _ismbbprint_l
- _ismbbprint
- ismbbprint
- ismbbprint_l
helpviewer_keywords:
- ismbbprint_l function
- ismbbprint function
- _ismbbprint function
- _ismbbprint_l function
ms.assetid: d08a061c-18a8-48f2-a75d-bff4870aec9d
ms.openlocfilehash: 8da69247d090c2067b0efda3c47f92bbeb729e49
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81343529"
---
# <a name="_ismbbprint-_ismbbprint_l"></a>_ismbbprint, _ismbbprint_l

Determina se um caractere multibyte especificado é um caractere de impressão.

## <a name="syntax"></a>Sintaxe

```C
int _ismbbprint(
   unsigned int c
);
int _ismbbprint_l(
   unsigned int c,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*C*<br/>
Inteiro a ser testado.

*Localidade*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor retornado

**_ismbbprint** retorna um valor não zero se a expressão:

`isprint(c) || _ismbbkprint(c)`

não é zero para *c*, ou 0 se não for. **_ismbbprint** usa o local atual para qualquer comportamento dependente do local. **_ismbbprint_l** é idêntica, exceto que usa o local passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

## <a name="remarks"></a>Comentários

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_ismbbprint**|\<mbctype.h>|
|**_ismbbprint_l**|\<mbctype.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Classificação de byte](../../c-runtime-library/byte-classification.md)<br/>
[rotinas _ismbb](../../c-runtime-library/ismbb-routines.md)<br/>
