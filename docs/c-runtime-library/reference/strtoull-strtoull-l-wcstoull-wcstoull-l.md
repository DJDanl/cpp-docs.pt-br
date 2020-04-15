---
title: strtoull, _strtoull_l, wcstoull, _wcstoull_l
ms.date: 4/2/2020
api_name:
- _strtoull_l
- _wcstoull_l
- strtoull
- wcstoull
- _o__strtoull_l
- _o__wcstoull_l
- _o_strtoull
- _o_wcstoull
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
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _wcstoull_l
- _tcstoull
- _tcstoull_l
- wcstoull
- _strtoull_l
- strtoull
helpviewer_keywords:
- strtoull function
- _tcstoull_l function
- _tcstoull function
- _wcstoull_l function
- _strtoull_l function
- wcstoull function
ms.assetid: 36dac1cc-e901-40a0-8802-63562d6d01df
ms.openlocfilehash: 5a27218b9d83314f995df30fbe21d97031d371af
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81354061"
---
# <a name="strtoull-_strtoull_l-wcstoull-_wcstoull_l"></a>strtoull, _strtoull_l, wcstoull, _wcstoull_l

Converte uma cadeia de caracteres para um valor inteiro longo sem sinal.

## <a name="syntax"></a>Sintaxe

```C
unsigned long long strtoull(
   const char *strSource,
   char **endptr,
   int base
);
unsigned long long _strtoull_l(
   const char *strSource,
   char **endptr,
   int base,
   _locale_t locale
);
unsigned long long wcstoull(
   const wchar_t *strSource,
   wchar_t **endptr,
   int base
);
unsigned long long _wcstoull_l(
   const wchar_t *strSource,
   wchar_t **endptr,
   int base,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*Strsource*<br/>
Cadeia de caracteres terminada em nulo a ser convertida.

*endptr*<br/>
Ponteiro para o caractere que interrompe o exame.

*base*<br/>
O número base a ser usado.

*Localidade*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor retornado

**strtoull** retorna o valor convertido, se houver, ou **ULLONG_MAX** no estouro. **strtoull** retorna 0 se nenhuma conversão pode ser realizada. **wcstoull** retorna valores análogos ao **strtoull**. Para ambas as funções, **errno** é definido como **ERANGE** se ocorrer estouro ou subfluxo.

Para obter mais informações sobre os códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

Cada uma dessas funções converte o *strSource* da string de entrada em um valor inteiro **longo** **long** **não assinado.**

**strtoull** pára de ler o *strSource* string no primeiro caractere que ele não pode reconhecer como parte de um número. Este pode ser o caráter nulo final, ou pode ser o primeiro caractere numérico que é maior ou igual à *base*. A configuração da categoria **LC_NUMERIC** do local determina o reconhecimento do caractere radix em *strSource*; para obter mais informações, consulte [setlocale, _wsetlocale](setlocale-wsetlocale.md). **strtoull** e **wcstoull** usar o local atual; **_strtoull_l** e **_wcstoull_l** em vez disso usam o local que passou, mas são idênticos de outra forma. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Se *endptr* não for **NULL**, um ponteiro para o caractere que parou a varredura é armazenado no local que é apontado pelo *endptr*. Se nenhuma conversão for realizada (nenhum dígito válido foi encontrado ou uma base inválida foi especificada), o valor do *strSource* será armazenado no local que é apontado pelo *endptr*.

**wcstoull** é uma versão de amplo caráter de **strtoull** e seu argumento *strSource* é uma seqüência de caracteres amplo. Caso contrário, essas funções se comportam de forma idêntica.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcstoull**|**strtoull**|**strtoull**|**wcstoull**|
|**_tcstoull_l**|**strtoull_l**|**_strtoull_l**|**_wcstoull_l**|

**strtoull** espera *que strSource* aponte para uma seqüência da seguinte forma:

> [*espaço em branco*] [{**+** **-**&#124; }] [**0** [{ **x** &#124; **X** }]] [*dígitos* &#124; *letras*]

Um *espaço em branco* pode consistir em caracteres de espaço e aba, que são ignorados. *dígitos* são um ou mais dígitos decimais. *letras* são uma ou mais das letras 'a' através de 'z' (ou 'A' a 'Z'). O primeiro caractere que não é adequado a esse formato interrompe o exame. Se *a base* estiver entre 2 e 36, então ela é usada como base do número. Se *base* é 0, os caracteres iniciais da seqüência que é apontado por *strSource* são usados para determinar a base. Se o primeiro caractere for '0' e o segundo caractere não for 'x' nem 'X', a cadeia de caracteres será interpretada como um inteiro octal. Se o primeiro caractere for '0' e o segundo caractere for 'x' ou 'X', a cadeia de caracteres será interpretada como um inteiro hexadecimal. Se o primeiro caractere for de '1' até '9', a cadeia de caracteres será interpretada como um inteiro hexadecimal. As letras 'a' a 'z' (ou 'A' a 'Z') recebem os valores 10 a 35; somente são permitidas letras cujos valores atribuídos são menores que *base*. O primeiro caractere fora do intervalo da base interrompe o exame. Por exemplo, se *base* é 0 e o primeiro caractere digitalizado é '0', um inteiro octal é assumido e um caractere '8' ou '9' interrompe a varredura. **strtoull** permite um**+** sinal de mais**-**( ) ou menos sinal () prefixo; um sinal de menos líder indica que o valor de retorno é negado.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strtoull**|\<stdlib.h>|
|**wcstoull**|\<stdlib.h> ou \<wchar.h>|
|**_strtoull_l**|\<stdlib.h>|
|**_wcstoull_l**|\<stdlib.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Consulte o exemplo de [strtod](strtod-strtod-l-wcstod-wcstod-l.md).

## <a name="see-also"></a>Confira também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[localeconv](localeconv.md)<br/>
[setlocale, _wsetlocale](setlocale-wsetlocale.md)<br/>
[Funções de valor da cadeia de caracteres para numérico](../../c-runtime-library/string-to-numeric-value-functions.md)<br/>
[strtod, _strtod_l, wcstod, _wcstod_l](strtod-strtod-l-wcstod-wcstod-l.md)<br/>
[strtol, wcstol, _strtol_l, _wcstol_l](strtol-wcstol-strtol-l-wcstol-l.md)<br/>
[strtoul, _strtoul_l, wcstoul, _wcstoul_l](strtoul-strtoul-l-wcstoul-wcstoul-l.md)<br/>
[strtoll, _strtoll_l, wcstoll, _wcstoll_l](strtoll-strtoll-l-wcstoll-wcstoll-l.md)<br/>
[atof, _atof_l, _wtof, _wtof_l](atof-atof-l-wtof-wtof-l.md)<br/>
