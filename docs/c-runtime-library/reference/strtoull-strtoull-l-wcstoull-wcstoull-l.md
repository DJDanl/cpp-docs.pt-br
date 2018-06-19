---
title: strtoull, _strtoull_l, wcstoull, _wcstoull_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _strtoull_l
- _wcstoull_l
- strtoull
- wcstoull
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
- _wcstoull_l
- _tcstoull
- _tcstoull_l
- wcstoull
- _strtoull_l
- strtoull
dev_langs:
- C++
helpviewer_keywords:
- strtoull function
- _tcstoull_l function
- _tcstoull function
- _wcstoull_l function
- _strtoull_l function
- wcstoull function
ms.assetid: 36dac1cc-e901-40a0-8802-63562d6d01df
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5080946188858e4a0dcd9eb6b2aa0029f1c343e7
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32417191"
---
# <a name="strtoull-strtoulll-wcstoull-wcstoulll"></a>strtoull, _strtoull_l, wcstoull, _wcstoull_l

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

*strSource*<br/>
Cadeia de caracteres terminada em nulo a ser convertida.

*endptr*<br/>
Ponteiro para o caractere que interrompe o exame.

*base*<br/>
O número base a ser usado.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

**strtoull** retorna o valor convertido, se houver, ou **ULLONG_MAX** no estouro. **strtoull** retorna 0 se nenhuma conversão pode ser executada. **wcstoull** retorna valores de maneira semelhante para **strtoull**. Para ambas as funções, **errno** é definido como **ERANGE** se ocorrer estouro ou estouro negativo.

Para obter mais informações sobre os códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

Cada uma dessas funções converte a cadeia de caracteres de entrada *strSource* para um **sem sinal** **longo** **longo** valor inteiro.

**strtoull** para de ler a cadeia de caracteres *strSource* no primeiro caractere que não reconhece como parte de um número. Isso pode ser o caractere null de terminação ou pode ser o primeiro caractere numérico que é maior que ou igual a *base*. A configuração de **LC_NUMERIC** categoria da localidade determina o reconhecimento do caractere base *strSource*; para obter mais informações, consulte [setlocale, wsetlocale](setlocale-wsetlocale.md). **strtoull** e **wcstoull** usam a localidade atual; **strtoull_l** e **wcstoull_l** em vez disso, use a localidade que é transmitida, mas são idênticos caso contrário. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Se *endptr* não é **nulo**, um ponteiro para o caractere que interrompeu a verificação é armazenado no local que é apontado pelo *endptr*. Se nenhuma conversão pode ser executada (sem dígitos válidos foram encontrados ou uma base inválida foi especificada), o valor de *strSource* é armazenado no local que é apontado pelo *endptr*.

**wcstoull** é uma versão de caractere largo de **strtoull** e sua *strSource* argumento é uma cadeia de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tcstoull**|**strtoull**|**strtoull**|**wcstoull**|
|**tcstoull_l**|**strtoull_l**|**_strtoull_l**|**_wcstoull_l**|

**strtoull** espera *strSource* para apontar para uma cadeia de caracteres da seguinte forma:

> [*espaço em branco*] [{**+** &#124; **-**}] [**0** [{ **x** &#124; **X** }]] [*dígitos* &#124; *letras*]  

Um *espaço em branco* pode consistir em caracteres de espaço e tabulação, que são ignorados. *dígitos* são um ou mais dígitos decimais. *letras* são um ou mais letras 'a' a 'z' ('A' a 'Z'). O primeiro caractere que não é adequado a esse formato interrompe o exame. Se *base* está entre 2 e 36, em seguida, ele é usado como a base do número. Se *base* é 0, os caracteres iniciais da cadeia de caracteres que é apontada pelo *strSource* são usados para determinar a base. Se o primeiro caractere for '0' e o segundo caractere não for 'x' nem 'X', a cadeia de caracteres será interpretada como um inteiro octal. Se o primeiro caractere for '0' e o segundo caractere for 'x' ou 'X', a cadeia de caracteres será interpretada como um inteiro hexadecimal. Se o primeiro caractere for de '1' até '9', a cadeia de caracteres será interpretada como um inteiro hexadecimal. As letras 'a' a 'z' (ou 'A' a 'Z') recebem os valores 10 a 35; somente são permitidas letras cujos valores atribuídos são menores que *base*. O primeiro caractere fora do intervalo da base interrompe o exame. Por exemplo, se *base* é 0 e o primeiro caractere examinado é '0', é considerado um inteiro octal e um caractere '8' ou '9' interrompe a verificação. **strtoull** permite que um sinal de adição (**+**) ou sinal de subtração (**-**) prefixo; um sinal de subtração à esquerda entrada indica que o valor de retorno será negado.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strtoull**|\<stdlib.h>|
|**wcstoull**|\<stdlib.h> ou \<wchar.h>|
|**_strtoull_l**|\<stdlib.h>|
|**_wcstoull_l**|\<stdlib.h> ou \<wchar.h>|

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
[strtoul, _strtoul_l, wcstoul, _wcstoul_l](strtoul-strtoul-l-wcstoul-wcstoul-l.md)<br/>
[strtoll, _strtoll_l, wcstoll, _wcstoll_l](strtoll-strtoll-l-wcstoll-wcstoll-l.md)<br/>
[atof, _atof_l, _wtof, _wtof_l](atof-atof-l-wtof-wtof-l.md)<br/>
