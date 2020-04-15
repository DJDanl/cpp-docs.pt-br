---
title: strtod, _strtod_l, wcstod, _wcstod_l
ms.date: 4/2/2020
api_name:
- wcstod
- _wcstod_l
- _strtod_l
- strtod
- _o__strtod_l
- _o__wcstod_l
- _o_strtod
- _o_wcstod
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
ms.openlocfilehash: a688846d5db4d508327745728f8933c91bfd54e0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81337662"
---
# <a name="strtod-_strtod_l-wcstod-_wcstod_l"></a>strtod, _strtod_l, wcstod, _wcstod_l

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

*Strsource*<br/>
Cadeia de caracteres terminada em nulo a ser convertida.

*endptr*<br/>
Ponteiro para o caractere que interrompe a verificação.

*Localidade*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor retornado

**strtod** retorna o valor do número de ponto flutuante, exceto quando a representação causaria um estouro, nesse caso a função retorna +/-**HUGE_VAL**. O sinal de **HUGE_VAL** corresponde ao sinal do valor que não pode ser representado. **strtod** retorna 0 se nenhuma conversão puder ser realizada ou ocorrer um subfluxo.

**wcstod** retorna valores análogos ao **strtod**. Para ambas as funções, **errno** é definido como **ERANGE** se ocorrer estouro ou subfluxo e o manipulador de parâmetros inválidos for invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de retorno.

## <a name="remarks"></a>Comentários

Cada função converte o *strSource* da seqüência de entrada em um **duplo**. A função **strtod converte** *strSource* em um valor de dupla precisão. **strtod** pára de ler o *strSource* string no primeiro caractere que não pode reconhecer como parte de um número. Este pode ser o caractere nulo de terminação. **wcstod** é uma versão de amplo caráter de **strtod;** seu argumento *strSource* é uma seqüência de caracteres amplo. Caso contrário, essas funções se comportam de forma idêntica.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcstod**|**strtod**|**strtod**|**wcstod**|
|**_tcstod_l**|**_strtod_l**|**_strtod_l**|**_wcstod_l**|

A **configuração de** LC_NUMERIC categoria da localidade atual determina o reconhecimento do caractere de ponto radix em *strSource*. Para obter mais informações sobre, consulte [setlocale](setlocale-wsetlocale.md). As funções sem o **sufixo _l** utilizam o local atual; **_strtod_l** é idêntica ao **_strtod_l** exceto que eles usam o *local* passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Se *endptr* não for **NULL**, um ponteiro para o caractere que parou a varredura é armazenado no local apontado pelo *endptr*. Se nenhuma conversão for realizada (nenhum dígito válido foi encontrado ou uma base inválida foi especificada), o valor do *strSource* será armazenado no local apontado pelo *endptr*.

**strtod** espera *que strSource* aponte para uma seqüência de uma das seguintes formas:

[*espaço em branco*] [*sinal]* {*dígitos* *[dígitos**de radix* ] &#124; *dígitos* *de radix* } [{**e** &#124; **E**} [*sign*] *dígitos*] [*whitespace*] [*sinal*] {**0x** &#124; **0X**} {*hexdigits* [*radix* *hexdigits*] &#124; *radix* *hexdigits*} [{ p **&#124;** **P**} [*sign*] *hexdigits*] [*whitespace*] [*sign*] { sign ] {**INF** &#124; **INFINITY**} [*whitespace*] [*sinal*] **NAN** *sequence*

O *espaço branco* líder opcional pode consistir em caracteres de espaço e guia, que são ignorados; *sinal* é mais (+) ou menos (-); *dígitos* são um ou mais dígitos decimais; *os hexadígitos* são um ou mais dígitos hexadecimais; *radix* é o caractere de ponto radix, seja um período (.) na localidade padrão "C" ou o valor específico da localidade se a localidade atual for diferente ou quando *a localidade* for especificada; uma *seqüência* é uma seqüência de caracteres alfanuméricos ou sublinhados. Em ambos os formulários de número decimal e hexadecimal, se nenhum dígito aparecer antes do caractere de ponto radix, pelo menos um deve aparecer após o caractere de ponto radix. Na forma decimal, os dígitos decimais podem ser seguidos por um expoente, que consiste em uma letra introdutória (**e** ou **E**) e um inteiro assinado opcionalmente. Na forma hexadecimal, os dígitos hexadecimais podem ser seguidos por um expoente, que consiste em uma letra introdutória (**p** ou **P**) e um inteiro hexadecimal assinado opcionalmente que representa o expoente como um poder de 2. Em qualquer forma, se nem uma parte expoente nem um caractere de ponto radix aparecer, um caractere de ponto radix é assumido para seguir o último dígito na seqüência. O caso é ignorado tanto nos formulários **INF** quanto **no NAN.** O primeiro caractere que não se encaixa em uma dessas formas interrompe a varredura.

As versões UCRT dessas funções não suportam a conversão de letras expoentes no estilo Fortran **(d** ou **D).** Essa extensão não padrão tinha suporte em versões anteriores do CRT e pode ser uma alteração significativa para seu código. As versões ucrt suportam cordas hexadecimais e tropeços redondos de valores INF e NAN, que não foram suportados em versões anteriores. Isso também pode causar alterações no seu código. Por exemplo, a string "0x1a" seria interpretada por **strtod** como 0.0 nas versões anteriores, mas como 26.0 na versão UCRT.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strtod**, **_strtod_l**|C: &lt;stdlib.h> C++: &lt;cstdlib> ou &lt;stdlib.h> |
|**wcstod,** **_wcstod_l**|C: &lt;stdlib.h> ou &lt;wchar.h> C++: &lt;cstdlib>, &lt;stdlib.h> ou &lt;wchar.h> |

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Confira também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Funções de valor da cadeia de caracteres para numérico](../../c-runtime-library/string-to-numeric-value-functions.md)<br/>
[strtol, wcstol, _strtol_l, _wcstol_l](strtol-wcstol-strtol-l-wcstol-l.md)<br/>
[strtoul, _strtoul_l, wcstoul, _wcstoul_l](strtoul-strtoul-l-wcstoul-wcstoul-l.md)<br/>
[atof, _atof_l, _wtof, _wtof_l](atof-atof-l-wtof-wtof-l.md)<br/>
[localeconv](localeconv.md)<br/>
[_create_locale, _wcreate_locale](create-locale-wcreate-locale.md)<br/>
[_free_locale](free-locale.md)<br/>
