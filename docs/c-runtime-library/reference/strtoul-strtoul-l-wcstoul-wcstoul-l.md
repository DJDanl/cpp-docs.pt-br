---
title: strtoul, _strtoul_l, wcstoul, _wcstoul_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _wcstoul_l
- _strtoul_l
- strtoul
- wcstoul
apilocation:
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
apitype: DLLExport
f1_keywords:
- strtoul
- _tcstoul
- wcstoul
dev_langs:
- C++
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
caps.latest.revision: 21
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a75833dedc988e1cd39ed318ca6729f579e90008
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="strtoul-strtoull-wcstoul-wcstoull"></a>strtoul, _strtoul_l, wcstoul, _wcstoul_l

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

*strSource*<br/>
Cadeia de caracteres terminada em nulo a ser convertida.

*endptr*<br/>
Ponteiro para o caractere que interrompe a verificação.

*base*<br/>
O número base a ser usado.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

**strtoul** retorna o valor convertido, se houver, ou **ULONG_MAX** no estouro. **strtoul** retorna 0 se nenhuma conversão pode ser executada. **wcstoul** retorna valores de maneira semelhante para **strtoul**. Para ambas as funções, **errno** é definido como **ERANGE** se ocorrer estouro ou estouro negativo.

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de retorno.

## <a name="remarks"></a>Comentários

Cada uma dessas funções converte a cadeia de caracteres de entrada *strSource* para um **sem sinal** **longo**.

**strtoul** para de ler a cadeia de caracteres *strSource* no primeiro caractere que não reconhece como parte de um número. Isso pode ser o caractere null de terminação ou pode ser o primeiro caractere numérico maior que ou igual a *base*. O **LC_NUMERIC** categoria determina da localidade reconhecimento do caractere base *strSource*; para obter mais informações, consulte [setlocale](setlocale-wsetlocale.md). **strtoul** e **wcstoul** usam a localidade atual; **strtoul_l** e **wcstoul_l** são idênticos, exceto que eles usam a localidade passada em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Se *endptr* não é **nulo**, um ponteiro para o caractere que interrompeu a verificação é armazenado no local apontado pela *endptr*. Se nenhuma conversão pode ser executada (sem dígitos válidos foram encontrados ou uma base inválida foi especificada), o valor de *strSource* é armazenado no local apontado pela *endptr*.

**wcstoul** é uma versão de caractere largo de **strtoul**; seu *strSource* argumento é uma cadeia de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tcstoul**|**strtoul**|**strtoul**|**wcstoul**|
|**_tcstoul_l**|**strtoul_l**|**_strtoul_l**|**_wcstoul_l**|

**strtoul** espera *strSource* para apontar para uma cadeia de caracteres da seguinte forma:

> [*espaço em branco*] [{**+** &#124; **-**}] [**0** [{ **x** &#124; **X** }]] [*dígitos* &#124; *letras*]

Um *espaço em branco* pode consistir em caracteres de espaço e tabulação, que são ignorados. *dígitos* são um ou mais dígitos decimais. *letras* são um ou mais letras 'a' a 'z' ('A' a 'Z'). O primeiro caractere que não é adequado a esse formato interrompe o exame. Se *base* está entre 2 e 36, em seguida, ele é usado como a base do número. Se *base* é 0, os caracteres iniciais da cadeia de caracteres apontada por *strSource* são usados para determinar a base. Se o primeiro caractere é 0 e o segundo caractere não for 'x' ou 'X', a cadeia de caracteres é interpretada como um inteiro octal. Se o primeiro caractere for '0' e o segundo caractere for 'x' ou 'X', a cadeia de caracteres será interpretada como um inteiro hexadecimal. Se o primeiro caractere for de '1' até '9', a cadeia de caracteres será interpretada como um inteiro hexadecimal. As letras 'a' a 'z' (ou 'A' a 'Z') recebem os valores 10 a 35; somente são permitidas letras cujos valores atribuídos são menores que *base*. O primeiro caractere fora do intervalo da base interrompe o exame. Por exemplo, se *base* é 0 e o primeiro caractere examinado é '0', é considerado um inteiro octal e um caractere '8' ou '9' irá parar a verificação. **strtoul** permite que um sinal de mais (**+**) ou sinal de subtração (**-**) prefixo de sinal; um sinal de subtração indica que o valor de retorno será negado.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strtoul**|\<stdlib.h>|
|**wcstoul**|\<stdlib.h> ou \<wchar.h>|
|**_strtoul_l**|\<stdlib.h>|
|**_wcstoul_l**|\<stdlib.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Consulte o exemplo de [strtod](strtod-strtod-l-wcstod-wcstod-l.md).

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[localeconv](localeconv.md)<br/>
[setlocale, _wsetlocale](setlocale-wsetlocale.md)<br/>
[Funções de valor de cadeia de caracteres para numérico](../../c-runtime-library/string-to-numeric-value-functions.md)<br/>
[strtod, _strtod_l, wcstod, _wcstod_l](strtod-strtod-l-wcstod-wcstod-l.md)<br/>
[strtol, wcstol, _strtol_l, _wcstol_l](strtol-wcstol-strtol-l-wcstol-l.md)<br/>
[atof, _atof_l, _wtof, _wtof_l](atof-atof-l-wtof-wtof-l.md)<br/>
