---
title: isprint, iswprint, _isprint_l, _iswprint_l
ms.date: 11/04/2016
api_name:
- iswprint
- isprint
- _isprint_l
- _iswprint_l
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- iswprint
- _istprint
- isprint
helpviewer_keywords:
- _istprint function
- iswprint function
- _iswprint_l function
- isprint_l function
- istprint function
- isprint function
- iswprint_l function
- _isprint_l function
ms.assetid: a8bbcdb0-e8d0-4d8c-ae4e-56d3bdee6ca3
ms.openlocfilehash: 282b72fcec84f8096ce0d54cd114e756aeafbc85
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70953753"
---
# <a name="isprint-iswprint-_isprint_l-_iswprint_l"></a>isprint, iswprint, _isprint_l, _iswprint_l

Determina se um inteiro representa um caractere imprimível.

## <a name="syntax"></a>Sintaxe

```C
int isprint(
   int c
);
int iswprint(
   wint_t c
);
int _isprint_l(
   int c,
   _locale_t locale
);
int _iswprint_l(
   wint_t c,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*c*<br/>
Inteiro a ser testado.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas rotinas retornará zero se *c* for uma representação específica de um caractere imprimível. **isprint** retornará um valor diferente de zero se *c* for um caractere imprimível — isso inclui o caractere de espaço (0x20-0x7E). **iswprint** retornará um valor diferente de zero se *c* for um caractere largo imprimível – isso inclui o caractere de largura. Cada uma dessas rotinas retornará 0 se *c* não atender à condição de teste.

O resultado da condição de teste para essas funções depende da configuração de categoria **LC_CTYPE** da localidade; consulte [setlocale, _wsetlocale](setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções que não têm o sufixo **_L** usam a localidade atual para qualquer comportamento dependente de localidade; as versões que têm o sufixo **_L** são idênticas, exceto que usam a localidade que é passada em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

O comportamento de **isprint** e **_isprint_l** é indefinido se *c* não é EOF ou está no intervalo de 0 a 0xFF, inclusive. Quando uma biblioteca CRT de depuração é usada e *c* não é um desses valores, as funções geram uma asserção.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_unicode definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_** **istprint**|**isprint**|[_ismbcprint](ismbcgraph-functions.md)|**iswprint**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**isprint**|\<ctype.h>|
|**iswprint**|\<ctype.h> ou \<wchar.h>|
|**_isprint_l**|\<ctype.h>|
|**_iswprint_l**|\<ctype.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Classificação de caracteres](../../c-runtime-library/character-classification.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)<br/>
