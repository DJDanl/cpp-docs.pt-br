---
title: isalpha, iswalpha, _isalpha_l, _iswalpha_l
ms.date: 4/2/2020
api_name:
- iswalpha
- _iswalpha_l
- isalpha
- _isalpha_l
- _o_isalpha
- _o_iswalpha
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
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _istalpha
- _ismbcalpha_l
- isalpha
- _isalpha_l
- iswalpha
- _istalpha_l
- _iswalpha_l
helpviewer_keywords:
- _iswalpha_l function
- _isalpha_l function
- _ismbcalpha_l function
- _istalpha_l function
- _ismbcalpha function
- isalpha function
- iswalpha function
- istalpha function
- _istalpha function
ms.assetid: ed6cc2be-c4b0-4475-87ac-bc06d8c23064
ms.openlocfilehash: abce570aecc307efd4986fab78d45954d7a79588
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82919795"
---
# <a name="isalpha-iswalpha-_isalpha_l-_iswalpha_l"></a>isalpha, iswalpha, _isalpha_l, _iswalpha_l

Determina se um inteiro representa um caractere alfabético.

## <a name="syntax"></a>Sintaxe

```C
int isalpha(
   int c
);
int iswalpha(
   wint_t c
);
int _isalpha_l(
   int c,
   _locale_t locale
);
int _iswalpha_l(
   wint_t c,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*&*<br/>
Inteiro a ser testado.

*locale*<br/>
A localidade a ser usada em vez da localidade atual.

## <a name="return-value"></a>Valor retornado

Cada uma dessas rotinas retornará zero se *c* for uma representação específica de um caractere alfabético. **isalpha** retornará um valor diferente de zero se *c* estiver dentro dos intervalos de a-z ou a-z. **iswalpha** retorna um valor diferente de zero somente para caracteres largos para os quais [iswupper](isupper-isupper-l-iswupper-iswupper-l.md) ou **iswlower** é diferente de zero; ou seja, para qualquer caractere largo que seja um de um conjunto definido pela implementação para o qual nenhum de **iswcntrl**, **iswdigit**, **iswpunct**ou **iswspace** seja diferente de zero. Cada uma dessas rotinas retornará 0 se *c* não atender à condição de teste.

As versões dessas funções que têm o sufixo **_L** usam o parâmetro Locale que é passado em vez da localidade atual. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

O comportamento de **isalpha** e **_isalpha_l** será indefinido se *c* não for EOF ou estiver no intervalo de 0 a 0xFF, inclusive. Quando uma biblioteca CRT de depuração é usada e *c* não é um desses valores, as funções geram uma asserção.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_istalpha**|**isalpha**|**_ismbcalpha**|**iswalpha**|
|**_istalpha_l**|**_isalpha_l**|**_ismbcalpha_l**|**_iswalpha_l**|

## <a name="remarks"></a>Comentários

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**isalpha**|\<ctype.h>|
|**iswalpha**|\<ctype.h> ou \<wchar.h>|
|**_isalpha_l**|\<ctype.h>|
|**_iswalpha_l**|\<ctype.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Classificação de caracteres](../../c-runtime-library/character-classification.md)<br/>
[Locale](../../c-runtime-library/locale.md)<br/>
[Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)<br/>
