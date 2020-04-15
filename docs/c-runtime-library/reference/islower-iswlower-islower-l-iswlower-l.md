---
title: islower, iswlower, _islower_l, _iswlower_l
ms.date: 4/2/2020
api_name:
- iswlower
- _islower_l
- islower
- _iswlower_l
- _o_islower
- _o_iswlower
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
- _istlower
- islower
- _ismbclower_l
- _liswlower_l
- _istlower_l
- _iswlower_l
- _islower _l
- _islower_l
- iswlower
helpviewer_keywords:
- _islower _l function
- _ismbclower_l function
- islower function
- _iswlower_l function
- _liswlower_l function
- _istlower_l function
- istlower function
- _istlower function
- iswlower function
- _islower_l function
ms.assetid: fcc3b70a-2b47-45fd-944d-e5c1942e6457
ms.openlocfilehash: 64fbde1db738dda694a911557748f2b46b6d8af8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81343792"
---
# <a name="islower-iswlower-_islower_l-_iswlower_l"></a>islower, iswlower, _islower_l, _iswlower_l

Determina se um inteiro representa um caractere minúsculo.

## <a name="syntax"></a>Sintaxe

```C
int islower(
   int c
);
int iswlower(
   wint_t c
);
int islower_l(
   int c,
   _locale_t locale
);
int _iswlower_l(
   wint_t c,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*C*<br/>
Inteiro a ser testado.

*Localidade*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor retornado

Cada uma dessas rotinas retorna não zero se *c* é uma representação particular de um caractere minúsculo. **islower** retorna um valor não zero se *c* é um caractere minúsculo (a - z). **iswlower** retorna um valor não zero se *c* é um caractere amplo que corresponde a uma letra minúscula, ou se *c* é um de um conjunto definido de implementação de caracteres largos para os quais nenhum de **iswcntrl**, **iswdigit**, **iswpunct,** ou **iswspace** não é zero. Cada uma dessas rotinas retorna 0 se *c* não satisfaz a condição de teste.

As versões dessas funções que têm o **sufixo _l** usam o local que é passado em vez do local atual para seu comportamento dependente da localidade. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

O comportamento de **islower** e **_islower_l** é indefinido se *c* não é EOF ou na faixa 0 a 0xFF, inclusive. Quando uma biblioteca CRT depurada é usada e *c* não é um desses valores, as funções levantam uma afirmação.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_istlower**|**islower**|[_ismbclower](ismbclower-ismbclower-l-ismbcupper-ismbcupper-l.md)|**Iswlower**|
|**_istlower_l**|`_islower _l`|[_ismbclower_l](ismbclower-ismbclower-l-ismbcupper-ismbcupper-l.md)|**_liswlower_l**|

## <a name="remarks"></a>Comentários

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**islower**|\<ctype.h>|
|**Iswlower**|\<ctype.h> ou \<wchar.h>|
|**_islower_l**|\<ctype.h>|
|**_swlower_l**|\<ctype.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Classificação de caracteres](../../c-runtime-library/character-classification.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)<br/>
