---
title: strtol, wcstol, _strtol_l, _wcstol_l
ms.date: 4/2/2020
api_name:
- strtol
- wcstol
- _strtol_l
- _wcstol_l
- _o__strtol_l
- _o__wcstol_l
- _o_strtol
- _o_wcstol
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
ms.openlocfilehash: dbeaf04d34aa20e15de48e99082ed07edb6129ab
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81320483"
---
# <a name="strtol-wcstol-_strtol_l-_wcstol_l"></a>strtol, wcstol, _strtol_l, _wcstol_l

Converta as strings em um **longo** valor inteiro.

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

*String*\
Cadeia de caracteres terminada em nulo a ser convertida.

*end_ptr*\
Um parâmetro de saída, definido para apontar para o personagem após o último caractere interpretado. Ignorado, se **NULO.**

*Base*\
O número base a ser usado.

*Localidade*\
Localidade a usar.

## <a name="return-value"></a>Valor retornado

**strtol,** **wcstol,** **_strtol_l**e **_wcstol_l** devolver o valor representado na *cadeia.* Eles retornam 0 se nenhuma conversão for possível. Quando a representação causaria um estouro, eles retornam **LONG_MAX** ou **LONG_MIN**.

**errno** é definido como **ERANGE** se ocorrer estouro ou subfluxo. Está definido como **EINVAL** se *a seqüência* for **NULA**. Ou, se *a base* não for zero e menor que 2, ou maior que 36. Para obter mais informações sobre **ERANGE,** **EINVAL**e outros códigos de devolução, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

As funções **strtol,** **wcstol,** **_strtol_l**e **_wcstol_l** convertem *a seqüência* em um **longo**. Eles param de ler *string* no primeiro caractere não reconhecido como parte de um número. Pode ser o caractere final-nulo, ou o primeiro caractere alfanumérico maior ou igual à *base*.

**wcstol** e **_wcstol_l** são versões de grande caráter de **strtol** e **_strtol_l**. Seu argumento *de seqüência* é uma seqüência de caracteres amplo. Essas funções se comportam de forma idêntica ao **strtol** e **_strtol_l** de outra forma. A configuração **da** LC_NUMERIC do local determina o reconhecimento do caractere radix (o marcador fracionado ou ponto decimal) na *seqüência*. As funções **strtol** e **wcstol** usam a localização atual. **_strtol_l** e **_wcstol_l** usar o local passou em seu lugar. Para obter mais informações, consulte [setlocale] e [Locale](../../c-runtime-library/locale.md).

Quando *end_ptr* é **NULA,** é ignorada. Caso contrário, um ponteiro para o caractere que parou a varredura é armazenado no local apontado por *end_ptr*. Nenhuma conversão é possível se nenhum dígito válido for encontrado ou uma base inválida for especificada. O valor da *seqüência* é então armazenado no local apontado por *end_ptr*.

**strtol** espera que a *seqüência* aponte para uma seqüência da seguinte forma:

> [*espaço em branco*] [{**+** **-**&#124; }] [**0** [{ **x** &#124; **X** }]] [*alfanuméricas*]

Suportes quadrados`[ ]`() circundam elementos opcionais. Aparelhos encaracolados e`{ | }`uma barra vertical ( ) cercam alternativas para um único elemento. *o espaço branco* pode consistir em caracteres de espaço e guia, que são ignorados. *alfanuméricas* são dígitos decimais ou as letras 'a' através de 'z' (ou 'A' a 'Z'). O primeiro caractere que não se encaixa neste formulário interrompe a varredura. Se *a base* está entre 2 e 36, então é usada como base do número. Se *base* é 0, os caracteres iniciais da seqüência apontada por *string* são usados para determinar a base. Se o primeiro caractere for 0, e o segundo caractere não for 'x' ou 'X', a seqüência é interpretada como um inteiro octal. Se o primeiro caractere for '0' e o segundo caractere for 'x' ou 'X', a cadeia de caracteres será interpretada como um inteiro hexadecimal. Se o primeiro caractere for de '1' até '9', a cadeia de caracteres será interpretada como um inteiro hexadecimal. As letras 'a' a z' (ou 'A' a 'Z') são atribuídas aos valores de 10 a 35. A varredura só permite letras cujos valores são inferiores à *base.* O primeiro caractere fora do intervalo da base interrompe o exame. Por exemplo, suponha que *a seqüência* comece com "01". Se *a base* é 0, o scanner assume que é um inteiro octal. Um caractere '8' ou '9' interrompe a varredura.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcstol**|**strtol**|**strtol**|**wcstol**|
|**_tcstol_l**|**_strtol_l**|**_strtol_l**|**_wcstol_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strtol**|\<stdlib.h>|
|**wcstol**|\<stdlib.h> ou \<wchar.h>|
|**_strtol_l**|\<stdlib.h>|
|**_wcstol_l**|\<stdlib.h> ou \<wchar.h>|

As **_strtol_l** **_wcstol_l** funções são específicas da Microsoft, não fazem parte da biblioteca Padrão C. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../compatibility.md).

## <a name="example"></a>Exemplo

Veja o [strtod](strtod-strtod-l-wcstod-wcstod-l.md)exemplo para .

## <a name="see-also"></a>Confira também

[Conversão de dados](../data-conversion.md)\
[Localidade](../locale.md)\
[localeconv](localeconv.md)\
[setlocale, _wsetlocale](setlocale-wsetlocale.md)\
[Funções de valor de string a numéricas](../string-to-numeric-value-functions.md)\
[strtod, _strtod_l, wcstod, _wcstod_l](strtod-strtod-l-wcstod-wcstod-l.md)\
[strtoll, _strtoll_l, wcstoll, _wcstoll_l](strtoll-strtoll-l-wcstoll-wcstoll-l.md)\
[strtoul, _strtoul_l, wcstoul, _wcstoul_l](strtoul-strtoul-l-wcstoul-wcstoul-l.md)\
[atof, _atof_l, _wtof, _wtof_l](atof-atof-l-wtof-wtof-l.md)
