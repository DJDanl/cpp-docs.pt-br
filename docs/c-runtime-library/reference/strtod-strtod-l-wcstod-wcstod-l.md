---
title: strtod, _strtod_l, wcstod, _wcstod_l
ms.date: 10/20/2017
apiname:
- wcstod
- _wcstod_l
- _strtod_l
- strtod
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
- _tcstod
- strtod
- wcstod
- _strtod_l
- _wcstod_l
- stdlib/strtod
- corecrt_wstdlib/wcstod
- stdlib/_strtod_l
- corecrt_wstdlib/_wcstod_l
helpviewer_keywords:
- wcstod_l function
- tcstod_l function
- _tcstod_l function
- strtod function
- _wcstod_l function
- wcstod function
- strtod_l function
- tcstod function
- _tcstod function
- _strtod_l function
- string conversion, to floating point values
ms.assetid: 0444f74a-ba2a-4973-b7f0-1d77ba88c6ed
ms.openlocfilehash: c8c2b3b491e2e7265829fa88580529dc757ace8c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50469323"
---
# <a name="strtod-strtodl-wcstod-wcstodl"></a>strtod, _strtod_l, wcstod, _wcstod_l

Converte cadeias de caracteres em um valor de precisão dupla.

## <a name="syntax"></a>Sintaxe

```C
double strtod(
   const char *strSource,
   char **endptr
);
double _strtod_l(
   const char *strSource,
   char **endptr,
   _locale_t locale
);
double wcstod(
   const wchar_t *strSource,
   wchar_t **endptr
);
double wcstod_l(
   const wchar_t *strSource,
   wchar_t **endptr,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*strSource*<br/>
Cadeia de caracteres terminada em nulo a ser convertida.

*endptr*<br/>
Ponteiro para o caractere que interrompe a verificação.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor de retorno

**strtod** retorna o valor do número de ponto flutuante, exceto quando a representação causaria um estouro, nesse caso, a função retorna + /-**HUGE_VAL**. O sinal de **HUGE_VAL** coincide com o sinal do valor que não pode ser representado. **strtod** retorna 0 se nenhuma conversão pode ser realizada ou ocorrerá um estouro negativo.

**wcstod** retorna valores de maneira semelhante a **strtod**. Para ambas as funções **errno** é definido como **ERANGE** se ocorre estouro ou estouro negativo e o manipulador de parâmetro inválido será invocado, conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de retorno.

## <a name="remarks"></a>Comentários

Cada função converte a cadeia de caracteres de entrada *strSource* para um **duplo**. O **strtod** função converte *strSource* para um valor de precisão dupla. **strtod** deixa de ler a cadeia de caracteres *strSource* no primeiro caractere que não reconhece como parte de um número. Este pode ser o caractere nulo de terminação. **wcstod** é uma versão de caractere largo de **strtod**; sua *strSource* argumento é uma cadeia de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tcstod**|**strtod**|**strtod**|**wcstod**|
|**tcstod_l**|**_strtod_l**|**_strtod_l**|**_wcstod_l**|

O **LC_NUMERIC** configuração da categoria da localidade atual determina o reconhecimento do caractere de ponto fracionário *strSource*. Para obter mais informações sobre, consulte [setlocale](setlocale-wsetlocale.md). As funções sem o **l** sufixo usam a localidade atual; **strtod_l** é idêntico ao **strtod_l** , exceto que eles usam o *localidade* passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Se *endptr* não está **nulo**, um ponteiro para o caractere que parou a verificação é armazenado no local apontado pela *endptr*. Se nenhuma conversão puder ser executada (Nenhum dígito válido foi encontrado ou uma base inválida foi especificada), o valor de *strSource* é armazenado no local apontado por *endptr*.

**strtod** espera *strSource* para apontar para uma cadeia de caracteres de uma das seguintes formas:

[*espaço em branco*] [*sinal*] {*dígitos* [*fracionário* *dígitos*] &#124;  *fracionário* *dígitos*} [{**eletrônico** &#124; **eletrônico**} [*entrada*] *dígitos*] [*espaço em branco*] [*entrada*] {**0x** &#124; **0x**} {*hexdigits* [ *fracionário* *hexdigits*] &#124; *fracionário* *hexdigits*} [{**p** &#124; **P**} [*sinal*] *hexdigits*] [*espaço em branco*] [*entrada*] { **INF** &#124; **infinito**} [*espaço em branco*] [*entrada*]  **NAN** [*sequência*]

O entrelinhamento opcional *espaço em branco* pode consistir em caracteres de espaço ou tabulação, que são ignorados; *sinal* é um sinal de mais (+) ou menos (-); *dígitos* são um ou mais dígitos decimais; *hexdigits* são um ou mais dígitos hexadecimais; *fracionário* é o caractere de ponto fracionário, ou um ponto (.) na localidade "C" padrão, ou a específica de localidade de valor se a localidade atual for diferente ou quando *localidade* for especificado, um *sequência* é uma sequência de alfanumérico ou caracteres de sublinhado. Em formulários de número decimais e hexadecimais, se nenhum dígito aparecer antes do caractere de ponto fracionário, pelo menos um deverá aparecer após o caractere de ponto fracionário. No formato decimal, os dígitos decimais podem ser seguidos por um expoente, que consiste em uma letra de apresentação (**eletrônico** ou **eletrônico**) e um inteiro com sinal opcionalmente. Os dígitos hexadecimais no formulário hexadecimal, podem ser seguidos por um expoente, que consiste em uma letra de apresentação (**p** ou **P**) e um inteiro hexadecimal opcionalmente com sinal que representa o expoente como uma potência de 2. Em qualquer forma, se nem um expoente nem um caractere de ponto fracionário aparecer, um caractere de ponto fracionário é considerado siga o último dígito na cadeia de caracteres. O caso é ignorado em ambos os **INF** e **NAN** formulários. O primeiro caractere que não se ajusta a uma dessas formas interrompe o exame.

As versões UCRT dessas funções não têm suporte para conversão do estilo Fortran (**1!d** ou **1!d**) letras de expoente. Essa extensão não padrão tinha suporte em versões anteriores do CRT e pode ser uma alteração significativa para seu código. As versões UCRT dão suporte a cadeias de caracteres hexadecimais e o ciclo completo de valores de INF e NAN, que não tinham suporte em versões anteriores. Isso também pode causar alterações significativas em seu código. Por exemplo, a cadeia de caracteres "0x1a" será interpretada pelo **strtod** como 0,0 nas versões anteriores, mas como 26.0 na versão do UCRT.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strtod**, **strtod_l**|C: &lt;stdlib.h> C++: &lt;cstdlib> ou &lt;stdlib.h> |
|**wcstod**, **wcstod_l**|C: &lt;stdlib.h> ou &lt;wchar.h> C++: &lt;cstdlib>, &lt;stdlib.h> ou &lt;wchar.h> |

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_strtod.c
// This program uses strtod to convert a
// string to a double-precision value; strtol to
// convert a string to long integer values; and strtoul
// to convert a string to unsigned long-integer values.
//

#include <stdlib.h>
#include <stdio.h>

int main( void )
{
   char   *string, *stopstring;
   double x;
   long   l;
   int    base;
   unsigned long ul;

   string = "3.1415926This stopped it";
   x = strtod( string, &stopstring );
   printf( "string = %s\n", string );
   printf("   strtod = %f\n", x );
   printf("   Stopped scan at: %s\n\n", stopstring );

   string = "-10110134932This stopped it";
   l = strtol( string, &stopstring, 10 );
   printf( "string = %s\n", string );
   printf("   strtol = %ld\n", l );
   printf("   Stopped scan at: %s\n\n", stopstring );

   string = "10110134932";
   printf( "string = %s\n", string );

   // Convert string using base 2, 4, and 8:
   for( base = 2; base <= 8; base *= 2 )
   {
      // Convert the string:
      ul = strtoul( string, &stopstring, base );
      printf( "   strtol = %ld (base %d)\n", ul, base );
      printf( "   Stopped scan at: %s\n", stopstring );
   }
}
```

```Output
string = 3.1415926This stopped it
   strtod = 3.141593
   Stopped scan at: This stopped it

string = -10110134932This stopped it
   strtol = -2147483648
   Stopped scan at: This stopped it

string = 10110134932
   strtol = 45 (base 2)
   Stopped scan at: 34932
   strtol = 4423 (base 4)
   Stopped scan at: 4932
   strtol = 2134108 (base 8)
   Stopped scan at: 932
```

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Funções de valor de cadeia de caracteres para numérico](../../c-runtime-library/string-to-numeric-value-functions.md)<br/>
[strtol, wcstol, _strtol_l, _wcstol_l](strtol-wcstol-strtol-l-wcstol-l.md)<br/>
[strtoul, _strtoul_l, wcstoul, _wcstoul_l](strtoul-strtoul-l-wcstoul-wcstoul-l.md)<br/>
[atof, _atof_l, _wtof, _wtof_l](atof-atof-l-wtof-wtof-l.md)<br/>
[localeconv](localeconv.md)<br/>
[_create_locale, _wcreate_locale](create-locale-wcreate-locale.md)<br/>
[_free_locale](free-locale.md)<br/>
