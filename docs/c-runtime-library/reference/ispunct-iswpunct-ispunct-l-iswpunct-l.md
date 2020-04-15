---
title: ispunct, iswpunct, _ispunct_l, _iswpunct_l
ms.date: 4/2/2020
api_name:
- ispunct
- _iswpunct_l
- iswpunct
- _ispunct_l
- _o_ispunct
- _o_iswpunct
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
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- iswpunct
- _istpunct
- ispunct
helpviewer_keywords:
- _istpunct function
- _ispunct_l function
- iswpunct function
- ispunct function
- istpunct function
- ispunct_l function
- _iswpunct_l function
- iswpunct_l function
ms.assetid: 94403240-85c8-40a4-9c2b-e3e95c729c76
ms.openlocfilehash: 3072f147d2adff2c50304d2d2052947ca32cb060
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81342805"
---
# <a name="ispunct-iswpunct-_ispunct_l-_iswpunct_l"></a>ispunct, iswpunct, _ispunct_l, _iswpunct_l

Determina se um inteiro representa um caractere de pontuação.

## <a name="syntax"></a>Sintaxe

```C
int ispunct(
   int c
);
int iswpunct(
   wint_t c
);
int _ispunct_l(
   int c,
   _locale_t locale
);
int _iswpunct_l(
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

Cada uma dessas rotinas retorna não zero se *c* é uma representação particular de um caractere de pontuação. **ispunct** retorna um valor não zero para qualquer caractere imprimível que não seja um caractere espacial ou um caractere para o qual **isalnum** não é zero. **iswpunct** retorna um valor não zero para qualquer personagem de largura imprimível que não é nem o caractere amplo do espaço nem um personagem amplo para o qual **iswalnum** não é zero. Cada uma dessas rotinas retorna 0 se *c* não satisfaz a condição de teste.

O resultado da condição de teste para a função **ispunct** depende da **configuração da** LC_CTYPE categoria do local; consulte [setlocale, _wsetlocale](setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções que não possuem o **sufixo _l** utilizam a localidade atual para qualquer comportamento dependente da localidade; as versões que têm o **sufixo _l** são idênticas, exceto que eles usam o local que é passado em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

O comportamento de **ispunct** e **_ispunct_l** é indefinido se *c* não é EOF ou na faixa 0 a 0xFF, inclusive. Quando uma biblioteca CRT depurada é usada e *c* não é um desses valores, as funções levantam uma afirmação.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_** **istpunct**|**ispunct**|[_ismbcpunct](ismbcgraph-functions.md)|**iswpunct**|

## <a name="remarks"></a>Comentários

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**ispunct**|\<ctype.h>|
|**iswpunct**|\<ctype.h> ou \<wchar.h>|
|**_ispunct_l**|\<ctype.h>|
|**_iswpunct_l**|\<ctype.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Classificação de caracteres](../../c-runtime-library/character-classification.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)<br/>
