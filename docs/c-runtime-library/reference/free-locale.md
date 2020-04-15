---
title: _free_locale
ms.date: 4/2/2020
api_name:
- _free_locale
- _o__free_locale
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
- api-ms-win-crt-locale-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- __free_locale
- free_locale
- _free_locale
helpviewer_keywords:
- __free_locale function
- free_locale function
- locales, freeing
- _free_locale function
ms.assetid: 1f08d348-ab32-4028-a145-6cbd51b49af9
ms.openlocfilehash: 568e44d731f384a0503420339d716fdfdc81e13a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81346050"
---
# <a name="_free_locale"></a>_free_locale

Libera um objeto de localidade.

## <a name="syntax"></a>Sintaxe

```C
void _free_locale(
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*Localidade*<br/>
Objeto de localidade a ser liberado.

## <a name="remarks"></a>Comentários

A função **_free_locale** é usada para libertar o objeto local obtido de uma chamada para **_get_current_locale** ou **_create_locale**.

O nome anterior desta função, **__free_locale** (com dois sublinhados principais) foi preterido.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|**Rotina**|Cabeçalho necessário|
|---------------|---------------------|
|**_free_locale**|\<locale.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[_get_current_locale](get-current-locale.md)<br/>
[_create_locale, _wcreate_locale](create-locale-wcreate-locale.md)<br/>
