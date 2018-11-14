---
title: strtold, _strtold_l, wcstold, _wcstold_l
ms.date: 04/05/2018
apiname:
- wcstold
- strtold
- _strtold_l
- _wcstold_l
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
- _tcstold_l
- _wcstold_l
- _tcstold
- strtold
- _strtold_l
- wcstold
ms.assetid: 928c0c9a-bc49-445b-8822-100eb5954115
ms.openlocfilehash: dcf1eca5b163c8553b43d747d53537ec424a793c
ms.sourcegitcommit: afd6fac7c519dbc47a4befaece14a919d4e0a8a2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2018
ms.locfileid: "51521330"
---
# <a name="strtold-strtoldl-wcstold-wcstoldl"></a>strtold, _strtold_l, wcstold, _wcstold_l

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

**strtold** retorna o valor do número de ponto flutuante como uma **longo** **double**, exceto quando a representação causaria um estouro — nesse caso, a função retorna + /-**HUGE_VALL**. O sinal de **HUGE_VALL** coincide com o sinal do valor que não pode ser representado. **strtold** retorna 0 se nenhuma conversão pode ser realizada ou ocorrerá um estouro negativo.

**wcstold** retorna valores de maneira semelhante a **strtold**. Para ambas as funções **errno** é definido como **ERANGE** se ocorre estouro ou estouro negativo e o manipulador de parâmetro inválido será invocado, conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md).

Para obter mais informações sobre os códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

Cada função converte a cadeia de caracteres de entrada *strSource* para um **longo** **double**. O **strtold** função para de ler a cadeia de caracteres *strSource* no primeiro caractere que não reconhece como parte de um número. Este pode ser o caractere nulo de terminação. A versão de caractere largo de **strtold** é **wcstold**; sua *strSource* argumento é uma cadeia de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcstold**|**strtold**|**strtold**|**wcstold**|
|**_tcstold_l**|**_strtold_l**|**_strtold_l**|**_wcstold_l**|

O **LC_NUMERIC** configuração da categoria da localidade atual determina o reconhecimento do caractere fracionário em *strSource*. Para obter mais informações, consulte [setlocale, _wsetlocale](setlocale-wsetlocale.md). As funções sem o **l** sufixo usam a localidade atual; **_strtold_l** e **_wcstold_l** são idênticos aos **_strtold** e **_wcstold** , exceto que eles usam a localidade que passado. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Se *endptr* não está **nulo**, um ponteiro para o caractere que parou a verificação é armazenado no local apontado pela *endptr*. Se nenhuma conversão puder ser executada (Nenhum dígito válido foi encontrado ou uma base inválida foi especificada), o valor de *strSource* é armazenado no local apontado por *endptr*.

**strtold** espera *strSource* para apontar para uma cadeia de caracteres da seguinte forma:

[*espaço em branco*] [*sinal*] [*dígitos*] [. *dígitos*] [{**1!d** &#124; **1!d** &#124; **eletrônico** &#124; **eletrônico**} [*entrada* ]*dígitos*]

Um *espaço em branco* pode consistir em caracteres de espaço ou tabulação, que são ignorados; *sinal* seja plus (**+**) ou de menos (**-**); e *dígitos* são um ou mais dígitos decimais. Se nenhum dígito aparecer antes do caractere fracionário, pelo menos um deverá aparecer após o caractere fracionário. Os dígitos decimais podem ser seguidos por um expoente, que consiste em uma letra de apresentação (**d**, **D**, **e** ou **E**) e um inteiro opcionalmente com sinal. Se nem um expoente nem um caractere fracionário aparecer, supõe-se que um caractere fracionário siga o último dígito na cadeia de caracteres. O primeiro caractere que não é adequado a esse formato interrompe o exame.

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
