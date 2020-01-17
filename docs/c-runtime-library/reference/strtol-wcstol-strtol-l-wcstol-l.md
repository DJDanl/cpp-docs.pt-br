---
title: strtol, wcstol, _strtol_l, _wcstol_l
ms.date: 01/14/2020
api_name:
- strtol
- wcstol
- _strtol_l
- _wcstol_l
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _wcstol_l
- strtol
- _tcstol
- wcstol
- _strtol_l
- _tcstol_l
helpviewer_keywords:
- wcstol function
- wcstol_l function
- _tcstol function
- string conversion, to integers
- tcstol function
- strtol_l function
- _wcstol_l function
- _strtol_l function
- strtol function
ms.assetid: 1787c96a-f283-4a83-9325-33cfc1c7e240
no-loc:
- strtol
- wcstol
- _strtol_l
- _wcstol_l
- LONG_MAX
- LONG_MIN
- errno
- ERANGE
- EINVAL
- LC_NUMERIC
- _tcstol
- _tcstol_l
- localeconv
- setlocale
- _wsetlocale
- strtod
- _strtod_l
- wcstod
- _wcstod_l
- strtoll
- _strtoll_l
- wcstoll
- _wcstoll_l
- strtoul
- _strtoul_l
- wcstoul
- _wcstoul_l
- atof
- _atof_l
- _wtof
- _wtof_l
ms.openlocfilehash: 83054e1b31b56fda96bdea198ab34d65d633f335
ms.sourcegitcommit: e93f3e6a110fe38bc642055bdf4785e620d4220f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2020
ms.locfileid: "76123923"
---
# <a name="opno-locstrtol-opno-locwcstol-opno-loc_strtol_l-opno-loc_wcstol_l"></a>strtol, wcstol, _strtol_l, _wcstol_l

Converta cadeias de caracteres em um valor inteiro **longo** .

## <a name="syntax"></a>Sintaxe

```C
long strtol(
   const char *string,
   char **end_ptr,
   int base
);
long wcstol(
   const wchar_t *string,
   wchar_t **end_ptr,
   int base
);
long _strtol_l(
   const char *string,
   char **end_ptr,
   int base,
   _locale_t locale
);
long _wcstol_l(
   const wchar_t *string,
   wchar_t **end_ptr,
   int base,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*string*\
Cadeia de caracteres terminada em nulo a ser convertida.

*end_ptr*\
Um parâmetro de saída, definido para apontar para o caractere após o último caractere interpretado. Ignorado, se for **nulo**.

*base*\
O número base a ser usado.

\ de *localidade*
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

**strtol** , **wcstol** , **_strtol_l** e **_wcstol_l** retornam o valor representado na *cadeia de caracteres*. Eles retornam 0 se nenhuma conversão é possível. Quando a representação causar um estouro, elas retornarão **LONG_MAX** ou **LONG_MIN** .

**errno** é definido como **ERANGE** se ocorrer estouro ou Subfluxo. Ele é definido como **EINVAL** se a *cadeia de caracteres* é **nula**. Ou, se *base* for diferente de zero e menor que 2 ou maior que 36. Para obter mais informações sobre **ERANGE** , **EINVAL** e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

As funções **strtol** , **wcstol** , **_strtol_l** e **_wcstol_l** convertem a *cadeia de caracteres* em um **longo**. Eles param de ler a *cadeia de caracteres* no primeiro caractere não reconhecido como parte de um número. Pode ser o caractere de terminação-nulo ou o primeiro caractere alfanumérico maior ou igual a *base*.

**wcstol** e **_wcstol_l** são versões de caractere largo de **strtol** e **_strtol_l** . O argumento de *cadeia* de caracteres é uma cadeia de caracteres largo. Essas funções se comportam de forma idêntica para **strtol** e **_strtol_l** caso contrário. A configuração de categoria de **LC_NUMERIC** da localidade determina o reconhecimento do caractere fracionário (o marcador fracionário ou o ponto decimal) na *cadeia de caracteres*. As funções **strtol** e **wcstol** usam a localidade atual. **_strtol_l** e **_wcstol_l** usar a localidade passada em vez disso. Para obter mais informações, consulte [setlocale] e [localidade](../../c-runtime-library/locale.md).

Quando *end_ptr* é **nulo**, ele é ignorado. Caso contrário, um ponteiro para o caractere que parou a verificação é armazenado no local apontado por *end_ptr*. Nenhuma conversão será possível se nenhum dígito válido for encontrado ou se uma base inválida for especificada. O valor da *cadeia de caracteres* é armazenado no local apontado por *end_ptr*.

**strtol** espera que a *cadeia de caracteres* aponte para uma cadeia de caracteres do seguinte formato:

> [*espaço em branco*] [{ **+** &#124; **-** }] [**0** [{ **x** &#124; **x** }]] [*alfanuméricos*]

Colchetes (`[ ]`) circundar elementos opcionais. Chaves e uma barra vertical (`{ | }`) alternativas de surround para um único elemento. o *espaço em branco* pode consistir em caracteres de espaço e tabulação, ignorados. os *alfanuméricos* são dígitos decimais ou as letras ' a ' a ' z ' (ou ' a ' por meio de ' z '). O primeiro caractere que não se ajusta a esse formulário interrompe a verificação. Se *base* estiver entre 2 e 36, ela será usada como a base do número. Se *base* for 0, os caracteres iniciais da cadeia de caracteres apontados por *cadeia de caracteres* serão usados para determinar a base. Se o primeiro caractere for 0 e o segundo caractere não for ' x ' ou ' X ', a cadeia de caracteres será interpretada como um inteiro octal. Se o primeiro caractere for '0' e o segundo caractere for 'x' ou 'X', a cadeia de caracteres será interpretada como um inteiro hexadecimal. Se o primeiro caractere for de '1' até '9', a cadeia de caracteres será interpretada como um inteiro hexadecimal. As letras ' a ' a ' z ' (ou ' A ' até ' Z ') recebem os valores de 10 a 35. A verificação só permite letras cujos valores sejam menores que *base*. O primeiro caractere fora do intervalo da base interrompe o exame. Por exemplo, suponha que a *cadeia de caracteres* comece com "01". Se *base* for 0, o verificador assumirá que é um inteiro octal. Um caractere ' 8 ' ou ' 9 ' interrompe a verificação.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcstol**|**strtol**|**strtol**|**wcstol**|
|**_tcstol_l**|**_strtol_l**|**_strtol_l**|**_wcstol_l**|

## <a name="requirements"></a>Requisitos do

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strtol**|\<stdlib.h>|
|**wcstol**|\<stdlib.h> ou \<wchar.h>|
|**_strtol_l**|\<stdlib.h>|
|**_wcstol_l**|\<stdlib.h> ou \<wchar.h>|

As funções **_strtol_l** e **_wcstol_l** são específicas da Microsoft, não fazem parte da biblioteca C padrão. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../compatibility.md).

## <a name="example"></a>Exemplo

Consulte o exemplo para [strtod](strtod-strtod-l-wcstod-wcstod-l.md).

## <a name="see-also"></a>Veja também

\ de [conversão de dados](../data-conversion.md)
[Localidade](../locale.md)\
[localeconv](localeconv.md)\
[setlocale, _wsetlocale](setlocale-wsetlocale.md)\
[Cadeia de caracteres para funções de valor numérico](../string-to-numeric-value-functions.md)\
[strtod, _strtod_l, wcstod_wcstod_l](strtod-strtod-l-wcstod-wcstod-l.md)\
[strtoll, _strtoll_l, wcstoll_wcstoll_l](strtoll-strtoll-l-wcstoll-wcstoll-l.md)\
[strtoul, _strtoul_l, wcstoul_wcstoul_l](strtoul-strtoul-l-wcstoul-wcstoul-l.md)\
[atof, _atof_l, _wtof_wtof_l](atof-atof-l-wtof-wtof-l.md)
