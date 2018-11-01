---
title: _free_locale
ms.date: 11/04/2016
apiname:
- _free_locale
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
- api-ms-win-crt-locale-l1-1-0.dll
apitype: DLLExport
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
ms.openlocfilehash: 92dc8cd711087e8e797b484d6c7e3c6c3b031b5c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50537378"
---
# <a name="freelocale"></a>_free_locale

Libera um objeto de localidade.

## <a name="syntax"></a>Sintaxe

```C
void _free_locale(
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*locale*<br/>
Objeto de localidade a ser liberado.

## <a name="remarks"></a>Comentários

O **free_locale** função é usada para liberar o objeto de localidade obtido de uma chamada para **get_current_locale** ou **create_locale**.

O nome anterior dessa função, **free_locale** (com dois sublinhados à esquerda) foi preterido.

## <a name="requirements"></a>Requisitos

|**Rotina**|Cabeçalho necessário|
|---------------|---------------------|
|**_free_locale**|\<locale.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[_get_current_locale](get-current-locale.md)<br/>
[_create_locale, _wcreate_locale](create-locale-wcreate-locale.md)<br/>
