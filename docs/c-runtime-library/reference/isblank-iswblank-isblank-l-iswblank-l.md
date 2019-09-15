---
title: isblank, iswblank, _isblank_l, _iswblank_l
ms.date: 11/04/2016
api_name:
- isblank
- _isblank_l
- iswblank
- _iswblank_l
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _iswblank_l
- isblank
- _istblank_l
- _istblank
- _isblank_l
- iswblank
ms.assetid: 33ce96c0-f387-411a-8283-c3d2a69e56bd
ms.openlocfilehash: 022eba0335facc597f0608d63cfb58e0146e0f23
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70954514"
---
# <a name="isblank-iswblank-_isblank_l-_iswblank_l"></a>isblank, iswblank, _isblank_l, _iswblank_l

Determina se um inteiro representa um caractere em branco.

## <a name="syntax"></a>Sintaxe

```C
int isblank(
   int c
);
int iswblank(
   wint_t c
);
int _isblank_l(
   int c,
   _locale_t locale
);
int _iswblank_l(
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

Cada uma dessas rotinas retornará zero se *c* for uma representação específica de um espaço ou um caractere de tabulação horizontal, ou um dos conjuntos de caracteres específicos da localidade que são usados para separar palavras dentro de uma linha de texto. **IsBlank** retornará um valor diferente de zero se *c* for um caractere de espaço (0x20) ou um caractere de tabulação horizontal (0x09). O resultado da condição de teste para as funções **isblanks** depende da configuração de categoria **LC_CTYPE** da localidade; para obter mais informações, consulte [setlocale, _wsetlocale](setlocale-wsetlocale.md). As versões dessas funções que não têm o sufixo **_L** usam a localidade atual para qualquer comportamento dependente de localidade; as versões que têm o sufixo **_L** são idênticas, exceto que usam a localidade que é passada em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

**iswblank** retornará um valor diferente de zero se *c* for um caractere largo que corresponde a um caractere de tabulação horizontal ou espaço padrão.

O comportamento de **IsBlank** e **_isblank_l** será indefinido se *c* não for EOF ou estiver no intervalo de 0 a 0xFF, inclusive. Quando uma biblioteca CRT de depuração é usada e *c* não é um desses valores, as funções geram uma asserção.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_istblank**|**isblank**|[_ismbcblank](ismbcgraph-functions.md)|**iswblank**|
|**_istblank_l**|**_isblank_l**|[_ismbcblank_l](ismbcgraph-functions.md)|**_iswblank_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**isblank**|\<ctype.h>|
|**iswblank**|\<ctype.h> ou \<wchar.h>|
|**_isblank_l**|\<ctype.h>|
|**_iswblank_l**|\<ctype.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Classificação de caracteres](../../c-runtime-library/character-classification.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)<br/>
