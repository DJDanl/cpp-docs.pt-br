---
title: strtoumax, _strtoumax_l, wcstoumax, _wcstoumax_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _wcstoumax_l
- _strtoumax_l
- wcstoumax
- strtoumax
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
- wcstoumax
- _tcstoumax
- _strtoumax_l
- _wcstoumax_l
- _tcstoumax_l
- strtoumax
dev_langs:
- C++
helpviewer_keywords:
- _strtoumax_l function
- conversion functions
- wcstoumax function
- _wcstoumax_l function
- strtoumax function
ms.assetid: 566769f9-495b-4508-b9c6-02217a578897
caps.latest.revision: 5
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e57298c9f3c4d2ef20e679abf7d7da3c75f1ec52
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="strtoumax-strtoumaxl-wcstoumax-wcstoumaxl"></a>strtoumax, _strtoumax_l, wcstoumax, _wcstoumax_l

Converte cadeias de caracteres em um valor inteiro do maior tipo inteiro sem sinal com suporte.

## <a name="syntax"></a>Sintaxe

```C
uintmax_t strtoumax(
   const char *strSource,
   char **endptr,
   int base
);
uintmax_t _strtoumax_l(
   const char *strSource,
   char **endptr,
   int base,
   _locale_t locale
);
uintmax_t wcstoumax(
   const wchar_t *strSource,
   wchar_t **endptr,
   int base
);
uintmax_t _wcstoumax_l(
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

**strtoumax** retorna o valor convertido, se houver, ou **UINTMAX_MAX** no estouro. **strtoumax** retorna 0 se nenhuma conversão pode ser executada. **wcstoumax** retorna valores de maneira semelhante para **strtoumax**. Para ambas as funções, **errno** é definido como **ERANGE** se ocorrer estouro ou estouro negativo.

Para obter mais informações sobre os códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

Cada uma dessas funções converte a cadeia de caracteres de entrada *strSource* para um **uintmax_t** valor inteiro.

**strtoumax** para de ler a cadeia de caracteres *strSource* no primeiro caractere que não reconhece como parte de um número. Isso pode ser o caractere null de terminação ou pode ser o primeiro caractere numérico que é maior que ou igual a *base*. O **LC_NUMERIC** configuração de categoria da localidade determina o reconhecimento do caractere base *strSource*. Para obter mais informações, consulte [setlocale, _wsetlocale](setlocale-wsetlocale.md). **strtoumax** e **wcstoumax** usam a localidade atual; **strtoumax_l** e **wcstoumax_l** são idênticos, exceto que eles em vez disso, usarem a localidade que é transmitida. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Se *endptr* não é **nulo**, um ponteiro para o caractere que interrompeu a verificação é armazenado no local que é apontado pelo *endptr*. Se nenhuma conversão pode ser executada (sem dígitos válidos foram encontrados ou uma base inválida foi especificada), o valor de *strSource* é armazenado no local que é apontado pelo *endptr*.

A versão de caractere largo de **strtoumax** é **wcstoumax**; seu *strSource* argumento é uma cadeia de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcstoumax**|**strtoumax**|**strtoumax**|**wcstoumax**|
|**_tcstoumax_l**|**strtoumax_l**|**_strtoumax_l**|**_wcstoumax_l**|

**strtoumax** espera *strSource* para apontar para uma cadeia de caracteres da seguinte forma:

> [*espaço em branco*] [{**+** &#124; **-**}] [**0** [{ **x** &#124; **X** }]] [*dígitos* &#124; *letras*]  

Um *espaço em branco* pode consistir em caracteres de espaço e tabulação, que são ignorados. *dígitos* são um ou mais dígitos decimais. *letras* são um ou mais letras 'a' a 'z' ('A' a 'Z'). O primeiro caractere que não é adequado a esse formato interrompe o exame. Se *base* está entre 2 e 36, em seguida, ele é usado como a base do número. Se *base* é 0, os caracteres iniciais da cadeia de caracteres que é apontada pelo *strSource* são usados para determinar a base. Se o primeiro caractere for '0' e o segundo caractere não for 'x' nem 'X', a cadeia de caracteres será interpretada como um inteiro octal. Se o primeiro caractere for '0' e o segundo caractere for 'x' ou 'X', a cadeia de caracteres será interpretada como um inteiro hexadecimal. Se o primeiro caractere for de '1' até '9', a cadeia de caracteres será interpretada como um inteiro hexadecimal. As letras 'a' a 'z' (ou 'A' a 'Z') recebem os valores 10 a 35; somente são permitidas letras cujos valores atribuídos são menores que *base*. O primeiro caractere fora do intervalo da base interrompe o exame. Por exemplo, se *base* é 0 e o primeiro caractere examinado é '0', é considerado um inteiro octal e um caractere '8' ou '9' seria interrompê-la. **strtoumax** permite que um sinal de adição (**+**) ou sinal de subtração (**-**) prefixo; um prefixo de sinal de menos indica que o valor de retorno é de dois complemento do valor absoluto de cadeia de caracteres convertida.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strtoumax**|\<stdlib.h>|
|**wcstoumax**|\<stdlib.h> ou \<wchar.h>|
|**_strtoumax_l**|\<stdlib.h>|
|**_wcstoumax_l**|\<stdlib.h> ou \<wchar.h>|

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
[strtoimax, _strtoimax_l, wcstoimax, _wcstoimax_l](strtoimax-strtoimax-l-wcstoimax-wcstoimax-l.md)<br/>
[strtol, wcstol, _strtol_l, _wcstol_l](strtol-wcstol-strtol-l-wcstol-l.md)<br/>
[strtoul, _strtoul_l, wcstoul, _wcstoul_l](strtoul-strtoul-l-wcstoul-wcstoul-l.md)<br/>
[strtoll, _strtoll_l, wcstoll, _wcstoll_l](strtoll-strtoll-l-wcstoll-wcstoll-l.md)<br/>
[atof, _atof_l, _wtof, _wtof_l](atof-atof-l-wtof-wtof-l.md)<br/>
