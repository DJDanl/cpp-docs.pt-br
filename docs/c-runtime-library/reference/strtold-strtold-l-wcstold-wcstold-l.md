---
title: strtold, _strtold_l, wcstold, _wcstold_l
ms.date: 04/05/2018
api_name:
- wcstold
- strtold
- _strtold_l
- _wcstold_l
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
- _tcstold_l
- _wcstold_l
- _tcstold
- strtold
- _strtold_l
- wcstold
ms.assetid: 928c0c9a-bc49-445b-8822-100eb5954115
ms.openlocfilehash: f1a8bc385072f110832788447bfa248bc12b3663
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70957707"
---
# <a name="strtold-_strtold_l-wcstold-_wcstold_l"></a>strtold, _strtold_l, wcstold, _wcstold_l

Converte cadeias de caracteres em um valor de ponto flutuante de precisão dupla longo.

## <a name="syntax"></a>Sintaxe

```C
long double strtold(
   const char *strSource,
   char **endptr
);
long double _strtold_l(
   const char *strSource,
   char **endptr,
   _locale_t locale
);
long double wcstold(
   const wchar_t *strSource,
   wchar_t **endptr
);
long double wcstold_l(
   const wchar_t *strSource,
   wchar_t **endptr,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*strSource*<br/>
Cadeia de caracteres terminada em nulo a ser convertida.

*endptr*<br/>
Ponteiro para o caractere que interrompe o exame.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor de retorno

**strtold** retorna o valor do número de ponto flutuante como um **longo** **duplo**, exceto quando a representação causar um estouro — nesse caso, a função retornará +/-**HUGE_VALL**. O sinal de **HUGE_VALL** corresponde ao sinal do valor que não pode ser representado. **strtold** retornará 0 se nenhuma conversão puder ser executada ou se ocorrer um estouro negativo.

**wcstold** retorna valores de forma análoga ao **strtold**. Para ambas as funções, **errno** é definido como **ERANGE** se o estouro ou Subfluxo ocorre e o manipulador de parâmetro inválido é invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md).

Para obter mais informações sobre os códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

Cada função converte a cadeia de caracteres de entrada *strSource* para um **longo** **duplo**. A função **strtold** para de ler a cadeia de caracteres *strSource* no primeiro caractere que ela não pode reconhecer como parte de um número. Este pode ser o caractere nulo de terminação. A versão de caractere largo de **strtold** é **wcstold**; seu argumento *strSource* é uma cadeia de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcstold**|**strtold**|**strtold**|**wcstold**|
|**_tcstold_l**|**_strtold_l**|**_strtold_l**|**_wcstold_l**|

A configuração de categoria **LC_NUMERIC** da localidade atual determina o reconhecimento do caractere fracionário em *strSource*. Para obter mais informações, consulte [setlocale, _wsetlocale](setlocale-wsetlocale.md). As funções sem o sufixo **_L** usam a localidade atual; **_strtold_l** e **_wcstold_l** são idênticos a **_strtold** e **_wcstold** , exceto que eles usam a localidade que é passada. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Se *endptr* não for **NULL**, um ponteiro para o caractere que parou a verificação será armazenado no local apontado por *endptr*. Se nenhuma conversão puder ser executada (nenhum dígito válido foi encontrado ou uma base inválida foi especificada), o valor de *strSource* será armazenado no local apontado por *endptr*.

**strtold** espera que *strSource* aponte para uma cadeia de caracteres do seguinte formato:

[*espaço em branco*] [*assinar*] [*dígitos*] [. *dígitos*] [{ &#124; &#124; d e e} [assinar] dígitos] &#124;

Um *espaço em branco* pode consistir em caracteres de espaço e tabulação, ignorados; *Sign* é um sinal de **+** mais () ou **-** menos (); e os *dígitos* são um ou mais dígitos decimais. Se nenhum dígito aparecer antes do caractere fracionário, pelo menos um deverá aparecer após o caractere fracionário. Os dígitos decimais podem ser seguidos por um expoente, que consiste em uma letra de apresentação (**d**, **D**, **e** ou **E**) e um inteiro opcionalmente com sinal. Se nem um expoente nem um caractere fracionário aparecer, supõe-se que um caractere fracionário siga o último dígito na cadeia de caracteres. O primeiro caractere que não é adequado a esse formato interrompe o exame.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strtold**, **_strtold_l**|\<stdlib.h>|
|**wcstold**, **_wcstold_l**|\<stdlib.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_strtold.c
// Build with: cl /W4 /Tc crt_strtold.c
// This program uses strtold to convert a
// string to a long double-precision value.

#include <stdlib.h>
#include <stdio.h>

int main( void )
{
   char *string;
   char *stopstring;
   long double x;

   string = "3.1415926535898This stopped it";
   x = strtold(string, &stopstring);
   printf("string = %s\n", string);
   printf("   strtold = %.13Lf\n", x);
   printf("   Stopped scan at: %s\n\n", stopstring);
}
```

```Output
string = 3.1415926535898This stopped it
   strtold = 3.1415926535898
   Stopped scan at: This stopped it
```

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Funções de valor de cadeia de caracteres para numérico](../../c-runtime-library/string-to-numeric-value-functions.md)<br/>
[strtod, _strtod_l, wcstod, _wcstod_l](strtod-strtod-l-wcstod-wcstod-l.md)<br/>
[strtol, wcstol, _strtol_l, _wcstol_l](strtol-wcstol-strtol-l-wcstol-l.md)<br/>
[strtoul, _strtoul_l, wcstoul, _wcstoul_l](strtoul-strtoul-l-wcstoul-wcstoul-l.md)<br/>
[atof, _atof_l, _wtof, _wtof_l](atof-atof-l-wtof-wtof-l.md)<br/>
[localeconv](localeconv.md)<br/>
[_create_locale, _wcreate_locale](create-locale-wcreate-locale.md)<br/>
[_free_locale](free-locale.md)<br/>
