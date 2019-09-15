---
title: isxdigit, iswxdigit, _isxdigit_l, _iswxdigit_l
ms.date: 11/04/2016
api_name:
- _iswxdigit_l
- iswxdigit
- isxdigit
- _isxdigit_l
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
- iswxdigit
- isxdigit
- _istxdigit
helpviewer_keywords:
- isxdigit function
- istxdigit function
- _iswxdigit_l function
- _istxdigit function
- _isxdigit_l function
- iswxdigit_l function
- isxdigit_l function
- hexadecimal characters
- iswxdigit function
ms.assetid: c8bc5146-0b58-4e3f-bee3-f2318dd0f829
ms.openlocfilehash: 18f360e66583dfbf5033f813deed0b56abc71260
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70953586"
---
# <a name="isxdigit-iswxdigit-_isxdigit_l-_iswxdigit_l"></a>isxdigit, iswxdigit, _isxdigit_l, _iswxdigit_l

Determina se um inteiro representa um caractere que é um dígito hexadecimal.

## <a name="syntax"></a>Sintaxe

```C
int isxdigit(
   int c
);
int iswxdigit(
   wint_t c
);
int _isxdigit_l(
   int c,
   _locale_t locale
);
int _iswxdigit_l(
   wint_t c,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*c*<br/>
Inteiro a ser testado.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas rotinas retornará zero se *c* for uma representação específica de um dígito hexadecimal. **isxdigit** retornará um valor diferente de zero se *c* for um dígito hexadecimal (a-f, a-f ou 0-9). **iswxdigit** retornará um valor diferente de zero se *c* for um caractere largo que corresponde a um caractere de dígito hexadecimal. Cada uma dessas rotinas retornará 0 se *c* não atender à condição de teste.

Para a localidade "C", a função **iswxdigit** não oferece suporte a caracteres hexadecimais de largura inteira Unicode.

As versões dessas funções que têm o sufixo **_L** usam a localidade que é passada em vez da localidade atual para seu comportamento dependente de localidade. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

O comportamento de **isxdigit** e **_isxdigit_l** será indefinido se *c* não for EOF ou no intervalo de 0 a 0xFF, inclusive. Quando uma biblioteca CRT de depuração é usada e *c* não é um desses valores, as funções geram uma asserção.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_istxdigit**|**isxdigit**|**isxdigit**|**iswxdigit**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**isxdigit**|\<ctype.h>|
|**iswxdigit**|\<ctype.h> ou \<wchar.h>|
|**_isxdigit_l**|\<ctype.h>|
|**_iswxdigit_l**|\<ctype.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Classificação de caracteres](../../c-runtime-library/character-classification.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)<br/>
