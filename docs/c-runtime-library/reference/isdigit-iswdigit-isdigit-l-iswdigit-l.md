---
title: isdigit, iswdigit, _isdigit_l, _iswdigit_l
ms.date: 4/2/2020
api_name:
- _isdigit_l
- iswdigit
- _iswdigit_l
- isdigit
- _o_isdigit
- _o_iswdigit
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
- api-ms-win-crt-string-l1-1-0.dll
- ntoskrnl.exe
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _iswdigit_l
- _isdigit_l
- iswdigit
- isdigit
- _istdigit
- _istdigit_l
helpviewer_keywords:
- iswdigit function
- iswdigit_l function
- _iswdigit_l function
- _istdigit_l function
- _istdigit function
- istdigit function
- isdigit function
- isdigit_l function
- _ismbcdigit_l function
- _isdigit_l function
ms.assetid: 350b0093-843a-47b0-954e-c1776e8a3853
ms.openlocfilehash: 139453b5f03af2b5ec02db715630adf1f6715716
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81343860"
---
# <a name="isdigit-iswdigit-_isdigit_l-_iswdigit_l"></a>isdigit, iswdigit, _isdigit_l, _iswdigit_l

Determina se um inteiro representa um caractere de dígito decimal.

## <a name="syntax"></a>Sintaxe

```C
int isdigit(
   int c
);
int iswdigit(
   wint_t c
);
int _isdigit_l(
   int c,
   _locale_t locale
);
int _iswdigit_l(
   wint_t c,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*C*<br/>
Inteiro a ser testado.

*Localidade*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor retornado

Cada uma dessas rotinas retorna não zero se *c* é uma representação particular de um caractere decimal-dígito. **isdigit** retorna um valor não zero se *c* for um dígito decimal (0 - 9). **iswdigit** retorna um valor não zero se *c* é um caractere amplo que corresponde a um caractere decimal dígito. Cada uma dessas rotinas retorna 0 se *c* não satisfaz a condição de teste.

As versões dessas funções que têm o **sufixo _l** usam o local que é passado em vez do local atual para seu comportamento dependente da localidade. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

O comportamento de **isdigit** e **_isdigit_l** é indefinido se *c* não é EOF ou na faixa 0 a 0xFF, inclusive. Quando uma biblioteca CRT depurada é usada e *c* não é um desses valores, as funções levantam uma afirmação.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_istdigit**|**isdigit**|[_ismbcdigit](ismbcalnum-functions.md)|**Iswdigit**|
|**_istdigit_l**|**_isdigit_l**|[_ismbcdigit_l](ismbcalnum-functions.md)|**_iswdigit_l**|

## <a name="remarks"></a>Comentários

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**isdigit**|\<ctype.h>|
|**Iswdigit**|\<ctype.h> ou \<wchar.h>|
|**_isdigit_l**|\<ctype.h>|
|**_iswdigit_l**|\<ctype.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Classificação de caracteres](../../c-runtime-library/character-classification.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)<br/>
