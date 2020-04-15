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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: 60ae432fb11c5a29da2c4830c2a85305c6eaa46c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365624"
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

### <a name="parameters"></a>Parâmetros

*Strsource*<br/>
Cadeia de caracteres terminada em nulo a ser convertida.

*endptr*<br/>
Ponteiro para o caractere que interrompe a verificação.

*base*<br/>
O número base a ser usado.

*Localidade*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor retornado

**strtoul** retorna o valor convertido, se houver, ou **ULONG_MAX** no estouro. **strtoul** retorna 0 se nenhuma conversão puder ser realizada. **wcstoul** retorna valores análogamente ao **strtoul**. Para ambas as funções, **errno** é definido como **ERANGE** se ocorrer estouro ou subfluxo.

Veja [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre este, e outros códigos de devolução.

## <a name="remarks"></a>Comentários

Cada uma dessas funções converte o *strSource* da string de entrada em um **longo** **não assinado** .

**strtoul** pára de ler o *strSource* string no primeiro caractere que ele não pode reconhecer como parte de um número. Este pode ser o caráter nulo final, ou pode ser o primeiro caractere numérico maior ou igual à *base*. A **configuração de** LC_NUMERIC categoria do local determina o reconhecimento do caractere radix em *strSource*; para obter mais informações, consulte [setlocale](setlocale-wsetlocale.md). **strtoul** e **wcstoul** usam o local atual; **_strtoul_l** e **_wcstoul_l** são idênticos, exceto que eles usam o local passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Se *endptr* não for **NULL**, um ponteiro para o caractere que parou a varredura é armazenado no local apontado pelo *endptr*. Se nenhuma conversão for realizada (nenhum dígito válido foi encontrado ou uma base inválida foi especificada), o valor do *strSource* será armazenado no local apontado pelo *endptr*.

**wcstoul** é uma versão de amplo caráter de **strtoul;** seu argumento *strSource* é uma seqüência de caracteres amplo. Caso contrário, essas funções se comportam de forma idêntica.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcstoul**|**strtoul**|**strtoul**|**wcstoul**|
|**_tcstoul_l**|**strtoul_l**|**_strtoul_l**|**_wcstoul_l**|

**strtoul** espera *que strSource* aponte para uma seqüência da seguinte forma:

> [*espaço em branco*] [{**+** **-**&#124; }] [**0** [{ **x** &#124; **X** }]] [*dígitos* &#124; *letras*]

Um *espaço em branco* pode consistir em caracteres de espaço e aba, que são ignorados. *dígitos* são um ou mais dígitos decimais. *letras* são uma ou mais das letras 'a' através de 'z' (ou 'A' a 'Z'). O primeiro caractere que não é adequado a esse formato interrompe o exame. Se *a base* estiver entre 2 e 36, então ela é usada como base do número. Se *base* for 0, os caracteres iniciais da seqüência apontada salientado por *strSource* são usados para determinar a base. Se o primeiro caractere é 0 e o segundo caractere não for 'x' ou 'X', a cadeia de caracteres é interpretada como um inteiro octal. Se o primeiro caractere for '0' e o segundo caractere for 'x' ou 'X', a cadeia de caracteres será interpretada como um inteiro hexadecimal. Se o primeiro caractere for de '1' até '9', a cadeia de caracteres será interpretada como um inteiro hexadecimal. As letras 'a' a 'z' (ou 'A' a 'Z') recebem os valores 10 a 35; somente são permitidas letras cujos valores atribuídos são menores que *base*. O primeiro caractere fora do intervalo da base interrompe o exame. Por exemplo, se *base* é 0 e o primeiro caractere digitalizado é '0', um inteiro octal é assumido e um caractere '8' ou '9' impedirá a varredura. **strtoul** permite um**+** prefixo**-** de sinal mais ( ) ou menos ( ; um sinal de menos líder indica que o valor de retorno é negado.

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
[Funções de valor da cadeia de caracteres para numérico](../../c-runtime-library/string-to-numeric-value-functions.md)<br/>
[strtod, _strtod_l, wcstod, _wcstod_l](strtod-strtod-l-wcstod-wcstod-l.md)<br/>
[strtol, wcstol, _strtol_l, _wcstol_l](strtol-wcstol-strtol-l-wcstol-l.md)<br/>
[atof, _atof_l, _wtof, _wtof_l](atof-atof-l-wtof-wtof-l.md)<br/>
