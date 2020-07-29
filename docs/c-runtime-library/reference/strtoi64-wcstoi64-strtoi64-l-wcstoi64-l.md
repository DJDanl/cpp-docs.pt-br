---
title: _strtoi64, _wcstoi64, _strtoi64_l, _wcstoi64_l
ms.date: 4/2/2020
api_name:
- _strtoi64
- _strtoi64_l
- _wcstoi64_l
- _wcstoi64
- _o__strtoi64
- _o__strtoi64_l
- _o__wcstoi64
- _o__wcstoi64_l
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
- api-ms-win-crt-convert-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _strtoi64
- strtoi64
- _stroi64_l
- _wcstoi64_l
- wcstoi64_l
- _wcstoi64
- wcstoi64
- strtoi64_l
helpviewer_keywords:
- _strtoi64 function
- _wcstoi64 function
- _strtoi64_l function
- string conversion, to integers
- _wcstoi64_l function
- strtoi64_l function
- wcstoi64 function
- strtoi64 function
- wcstoi64_l function
ms.assetid: ea2abc50-7bfe-420e-a46b-703c3153593a
ms.openlocfilehash: ede96e39b596225d13c041468eb6172853959c6a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233945"
---
# <a name="_strtoi64-_wcstoi64-_strtoi64_l-_wcstoi64_l"></a>_strtoi64, _wcstoi64, _strtoi64_l, _wcstoi64_l

Converta uma cadeia de caracteres em um **`__int64`** valor.

## <a name="syntax"></a>Sintaxe

```C
__int64 _strtoi64(
   const char *strSource,
   char **endptr,
   int base
);
__int64 _wcstoi64(
   const wchar_t *strSource,
   wchar_t **endptr,
   int base
);
__int64 _strtoi64_l(
   const char *strSource,
   char **endptr,
   int base,
   _locale_t locale
);
__int64 _wcstoi64_l(
   const wchar_t *strSource,
   wchar_t **endptr,
   int base,
   _locale_t locale
);
```

### <a name="parameters"></a>parâmetros

*strSource*<br/>
Cadeia de caracteres terminada em nulo a ser convertida.

*endptr*<br/>
Ponteiro para o caractere que interrompe a verificação.

*base*<br/>
O número base a ser usado.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor retornado

**_strtoi64** retorna o valor representado na cadeia de caracteres *strSource*, exceto quando a representação causar um estouro, caso em que ele retorna **_I64_MAX** ou **_I64_MIN**. A função retornará 0, se nenhuma conversão puder ser realizada. **_wcstoi64** retorna valores de forma análoga ao **strtoi64**.

**_I64_MAX** e **_I64_MIN** são definidos em limites. T.

Se *strSource* for **nulo** ou a *base* for diferente de zero e for menor que 2 ou maior que 36, **errno** será definido como **EINVAL**.

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de retorno.

## <a name="remarks"></a>Comentários

A função **_strtoi64** converte *strSource* em um **`__int64`** . Ambas as funções param de ler a cadeia de caracteres *strSource* no primeiro caractere que eles não podem reconhecer como parte de um número. Esse pode ser o caractere nulo de terminação ou pode ser o primeiro caractere numérico maior ou igual à *base*. **_wcstoi64** é uma versão de caractere largo do **_strtoi64**; seu argumento *strSource* é uma cadeia de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcstoi64**|**_strtoi64**|**_strtoi64**|**_wcstoi64**|
|**_tcstoi64_l**|**_strtoi64_l**|**_strtoi64_l**|**_wcstoi64_l**|

A configuração de categoria de **LC_NUMERIC** da localidade determina o reconhecimento do caractere fracionário em *strSource*; para obter mais informações, consulte [setlocale](setlocale-wsetlocale.md). As funções sem o sufixo _l usam a localidade atual; **_strtoi64_l** e **_wcstoi64_l** são idênticos à função correspondente sem o sufixo **_L** , exceto pelo fato de que usam a localidade transmitida em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Se *endptr* não for **NULL**, um ponteiro para o caractere que parou a verificação será armazenado no local apontado por *endptr*. Se nenhuma conversão puder ser executada (nenhum dígito válido foi encontrado ou uma base inválida foi especificada), o valor de *strSource* será armazenado no local apontado por *endptr*.

**_strtoi64** espera que *strSource* aponte para uma cadeia de caracteres do seguinte formato:

> [*espaço em branco*] [{ **+** &#124; **-** }] [**0** [{ **x** &#124; **x** }]] [*dígitos* &#124; *letras*]

Um *espaço em branco* pode consistir em caracteres de espaço e tabulação, ignorados; os *dígitos* são um ou mais dígitos decimais; as *letras* são uma ou mais das letras ' a ' por meio de ' z ' (ou ' a ' por meio de ' z ').  O primeiro caractere que não é adequado a esse formato interrompe o exame. Se *base* estiver entre 2 e 36, ela será usada como a base do número. Se *base* for 0, os caracteres iniciais da cadeia de caracteres apontada por *strSource* serão usados para determinar a base. Se o primeiro caractere é 0 e o segundo caractere não for 'x' ou 'X', a cadeia de caracteres é interpretada como um inteiro octal. Se o primeiro caractere for '0' e o segundo caractere for 'x' ou 'X', a cadeia de caracteres será interpretada como um inteiro hexadecimal. Se o primeiro caractere for de '1' até '9', a cadeia de caracteres será interpretada como um inteiro hexadecimal. As letras 'a' a 'z' (ou 'A' a 'Z') recebem os valores 10 a 35; somente são permitidas letras cujos valores atribuídos são menores que *base*. O primeiro caractere fora do intervalo da base interrompe o exame. Por exemplo, se *base* for 0 e o primeiro caractere verificado for ' 0 ', um inteiro octal será assumido e um caractere ' 8 ' ou ' 9 ' interromperá a verificação.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_strtoi64**, **_strtoi64_l**|\<stdlib.h>|
|**_wcstoi64**, **_wcstoi64_l**|\<stdlib.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[localeconv](localeconv.md)<br/>
[setlocale, _wsetlocale](setlocale-wsetlocale.md)<br/>
[Cadeia de caracteres para funções de valor numérico](../../c-runtime-library/string-to-numeric-value-functions.md)<br/>
[strtod, _strtod_l, wcstod, _wcstod_l](strtod-strtod-l-wcstod-wcstod-l.md)<br/>
[strtoul, _strtoul_l, wcstoul, _wcstoul_l](strtoul-strtoul-l-wcstoul-wcstoul-l.md)<br/>
[atof, _atof_l, _wtof, _wtof_l](atof-atof-l-wtof-wtof-l.md)<br/>
