---
title: strtoul, _strtoul_l, wcstoul, _wcstoul_l
ms.date: 4/2/2020
api_name:
- _wcstoul_l
- _strtoul_l
- strtoul
- wcstoul
- _o__strtoul_l
- _o__wcstoul_l
- _o_strtoul
- _o_wcstoul
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
- ntoskrnl.exe
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- strtoul
- _tcstoul
- wcstoul
helpviewer_keywords:
- _wcstoul_l function
- _tcstoul function
- _strtoul_l function
- string conversion, to integers
- wcstoul function
- strtoul function
- wcstoul_l function
- strtoul_l function
- tcstoul function
ms.assetid: 38f2afe8-8178-4e0b-8bbe-d5c6ad66e3ab
ms.openlocfilehash: ceeb541a44d969db471cb2ba798bdc13079b5759
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87189253"
---
# <a name="strtoul-_strtoul_l-wcstoul-_wcstoul_l"></a>strtoul, _strtoul_l, wcstoul, _wcstoul_l

Converte uma cadeia de caracteres para um valor inteiro longo não assinado.

## <a name="syntax"></a>Sintaxe

```C
unsigned long strtoul(
   const char *strSource,
   char **endptr,
   int base
);
unsigned long _strtoul_l(
   const char *strSource,
   char **endptr,
   int base,
   _locale_t locale
);
unsigned long wcstoul(
   const wchar_t *strSource,
   wchar_t **endptr,
   int base
);
unsigned long _wcstoul_l(
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
Localidade a usar.

## <a name="return-value"></a>Valor retornado

**strtoul** retorna o valor convertido, se houver, ou **ULONG_MAX** excedente. **strtoul** retornará 0 se nenhuma conversão puder ser executada. **wcstoul** retorna valores de forma análoga ao **strtoul**. Para ambas as funções, **errno** é definido como **ERANGE** se ocorrer estouro ou Subfluxo.

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esse e outros códigos de retorno.

## <a name="remarks"></a>Comentários

Cada uma dessas funções converte a cadeia de caracteres de entrada *strSource* em um **`unsigned long`** .

**strtoul** interrompe a leitura da cadeia de caracteres *strSource* no primeiro caractere que ela não pode reconhecer como parte de um número. Esse pode ser o caractere nulo de terminação ou pode ser o primeiro caractere numérico maior ou igual à *base*. A configuração de categoria de **LC_NUMERIC** da localidade determina o reconhecimento do caractere fracionário em *strSource*; para obter mais informações, consulte [setlocale](setlocale-wsetlocale.md). **strtoul** e **wcstoul** usam a localidade atual; **_strtoul_l** e **_wcstoul_l** são idênticas, exceto pelo fato de que usam a localidade passada em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Se *endptr* não for **NULL**, um ponteiro para o caractere que parou a verificação será armazenado no local apontado por *endptr*. Se nenhuma conversão puder ser executada (nenhum dígito válido foi encontrado ou uma base inválida foi especificada), o valor de *strSource* será armazenado no local apontado por *endptr*.

**wcstoul** é uma versão de caractere largo do **strtoul**; seu argumento *strSource* é uma cadeia de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcstoul**|**strtoul**|**strtoul**|**wcstoul**|
|**_tcstoul_l**|**strtoul_l**|**_strtoul_l**|**_wcstoul_l**|

**strtoul** espera que *strSource* aponte para uma cadeia de caracteres do seguinte formato:

> [*espaço em branco*] [{ **+** &#124; **-** }] [**0** [{ **x** &#124; **x** }]] [*dígitos* &#124; *letras*]

Um *espaço em branco* pode consistir em caracteres de espaço e tabulação, ignorados. os *dígitos* são um ou mais dígitos decimais. as *letras* são uma ou mais das letras ' a ' por meio de ' z ' (ou ' a ' por meio de ' z '). O primeiro caractere que não é adequado a esse formato interrompe o exame. Se *base* estiver entre 2 e 36, ela será usada como a base do número. Se *base* for 0, os caracteres iniciais da cadeia de caracteres apontada por *strSource* serão usados para determinar a base. Se o primeiro caractere é 0 e o segundo caractere não for 'x' ou 'X', a cadeia de caracteres é interpretada como um inteiro octal. Se o primeiro caractere for '0' e o segundo caractere for 'x' ou 'X', a cadeia de caracteres será interpretada como um inteiro hexadecimal. Se o primeiro caractere for de '1' até '9', a cadeia de caracteres será interpretada como um inteiro hexadecimal. As letras 'a' a 'z' (ou 'A' a 'Z') recebem os valores 10 a 35; somente são permitidas letras cujos valores atribuídos são menores que *base*. O primeiro caractere fora do intervalo da base interrompe o exame. Por exemplo, se *base* for 0 e o primeiro caractere verificado for ' 0 ', um inteiro octal será assumido e um caractere ' 8 ' ou ' 9 ' interromperá a verificação. **strtoul** permite um prefixo de sinal de adição ( **+** ) ou de subtração ( **-** ); um sinal de subtração à esquerda indica que o valor de retorno é negado.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strtoul**|\<stdlib.h>|
|**wcstoul**|\<stdlib.h> ou \<wchar.h>|
|**_strtoul_l**|\<stdlib.h>|
|**_wcstoul_l**|\<stdlib.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Consulte o exemplo de [strtod](strtod-strtod-l-wcstod-wcstod-l.md).

## <a name="see-also"></a>Confira também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[localeconv](localeconv.md)<br/>
[setlocale, _wsetlocale](setlocale-wsetlocale.md)<br/>
[Cadeia de caracteres para funções de valor numérico](../../c-runtime-library/string-to-numeric-value-functions.md)<br/>
[strtod, _strtod_l, wcstod, _wcstod_l](strtod-strtod-l-wcstod-wcstod-l.md)<br/>
[strtol, wcstol, _strtol_l, _wcstol_l](strtol-wcstol-strtol-l-wcstol-l.md)<br/>
[atof, _atof_l, _wtof, _wtof_l](atof-atof-l-wtof-wtof-l.md)<br/>
