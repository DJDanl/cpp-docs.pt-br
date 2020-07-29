---
title: ':::no-loc(strtol):::, :::no-loc(wcstol):::, :::no-loc(_strtol_l):::, :::no-loc(_wcstol_l):::'
ms.date: 4/2/2020
api_name:
- ':::no-loc(strtol):::'
- ':::no-loc(wcstol):::'
- ':::no-loc(_strtol_l):::'
- ':::no-loc(_wcstol_l):::'
- '_o_:::no-loc(_strtol_l):::'
- '_o_:::no-loc(_wcstol_l):::'
- '_o_:::no-loc(strtol):::'
- '_o_:::no-loc(wcstol):::'
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
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- ':::no-loc(_wcstol_l):::'
- ':::no-loc(strtol):::'
- ':::no-loc(_tcstol):::'
- ':::no-loc(wcstol):::'
- ':::no-loc(_strtol_l):::'
- ':::no-loc(_tcstol_l):::'
helpviewer_keywords:
- ':::no-loc(wcstol)::: function'
- :::no-loc(wcstol):::_l function
- ':::no-loc(_tcstol)::: function'
- string conversion, to integers
- tcstol function
- :::no-loc(strtol):::_l function
- ':::no-loc(_wcstol_l)::: function'
- ':::no-loc(_strtol_l)::: function'
- ':::no-loc(strtol)::: function'
ms.assetid: 1787c96a-f283-4a83-9325-33cfc1c7e240
no-loc:
- ':::no-loc(strtol):::'
- ':::no-loc(wcstol):::'
- ':::no-loc(_strtol_l):::'
- ':::no-loc(_wcstol_l):::'
- ':::no-loc(LONG_MAX):::'
- ':::no-loc(LONG_MIN):::'
- ':::no-loc(errno):::'
- ':::no-loc(ERANGE):::'
- ':::no-loc(EINVAL):::'
- ':::no-loc(LC_NUMERIC):::'
- ':::no-loc(_tcstol):::'
- ':::no-loc(_tcstol_l):::'
- ':::no-loc(localeconv):::'
- ':::no-loc(setlocale):::'
- ':::no-loc(_wsetlocale):::'
- ':::no-loc(strtod):::'
- ':::no-loc(_strtod_l):::'
- ':::no-loc(wcstod):::'
- ':::no-loc(_wcstod_l):::'
- ':::no-loc(strtoll):::'
- ':::no-loc(_strtoll_l):::'
- ':::no-loc(wcstoll):::'
- ':::no-loc(_wcstoll_l):::'
- ':::no-loc(strtoul):::'
- ':::no-loc(_strtoul_l):::'
- ':::no-loc(wcstoul):::'
- ':::no-loc(_wcstoul_l):::'
- ':::no-loc(atof):::'
- ':::no-loc(_atof_l):::'
- ':::no-loc(_wtof):::'
- ':::no-loc(_wtof_l):::'
ms.openlocfilehash: a5265b434f14f299532d6f5ebb65c83d75ea63ca
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87232398"
---
# <a name="no-locstrtol-no-locwcstol-no-loc_strtol_l-no-loc_wcstol_l"></a>:::no-loc(strtol):::, :::no-loc(wcstol):::, :::no-loc(_strtol_l):::, :::no-loc(_wcstol_l):::

Converta cadeias de caracteres em um **`long`** valor inteiro.

## <a name="syntax"></a>Sintaxe

```C
long :::no-loc(strtol):::(
   const char *string,
   char **end_ptr,
   int base
);
long :::no-loc(wcstol):::(
   const wchar_t *string,
   wchar_t **end_ptr,
   int base
);
long :::no-loc(_strtol_l):::(
   const char *string,
   char **end_ptr,
   int base,
   _locale_t locale
);
long :::no-loc(_wcstol_l):::(
   const wchar_t *string,
   wchar_t **end_ptr,
   int base,
   _locale_t locale
);
```

### <a name="parameters"></a>parâmetros

*Strings*\
Cadeia de caracteres terminada em nulo a ser convertida.

*end_ptr*\
Um parâmetro de saída, definido para apontar para o caractere após o último caractere interpretado. Ignorado, se for **nulo**.

*polybase*\
O número base a ser usado.

*localidade*\
Localidade a usar.

## <a name="return-value"></a>Valor retornado

**:::no-loc(strtol):::**, **:::no-loc(wcstol):::** , **:::no-loc(_strtol_l):::** e **:::no-loc(_wcstol_l):::** retornam o valor representado na *cadeia de caracteres*. Eles retornam 0 se nenhuma conversão é possível. Quando a representação causar um estouro, elas retornam **:::no-loc(LONG_MAX):::** ou **:::no-loc(LONG_MIN):::** .

**:::no-loc(errno):::** é definido como **:::no-loc(ERANGE):::** se ocorrer estouro ou Subfluxo. Ele é definido como **:::no-loc(EINVAL):::** se a *cadeia de caracteres* for **nula**. Ou, se *base* for diferente de zero e menor que 2 ou maior que 36. Para obter mais informações sobre o **:::no-loc(ERANGE):::** , o **:::no-loc(EINVAL):::** e outros códigos de retorno, consulte [_dos :::no-loc(errno)::: , :::no-loc(errno)::: , _sys_errlist e _sys_nerr](../../c-runtime-library/:::no-loc(errno):::-dos:::no-loc(errno):::-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

As **:::no-loc(strtol):::** **:::no-loc(wcstol):::** funções,, e **:::no-loc(_strtol_l):::** **:::no-loc(_wcstol_l):::** convertem a *cadeia de caracteres* em um **`long`** . Eles param de ler a *cadeia de caracteres* no primeiro caractere não reconhecido como parte de um número. Pode ser o caractere de terminação-nulo ou o primeiro caractere alfanumérico maior ou igual a *base*.

**:::no-loc(wcstol):::** e **:::no-loc(_wcstol_l):::** são versões de caractere largo do **:::no-loc(strtol):::** e do **:::no-loc(_strtol_l):::** . O argumento de *cadeia* de caracteres é uma cadeia de caracteres largo. Essas funções se comportam de **:::no-loc(strtol):::** forma idêntica e não **:::no-loc(_strtol_l):::** . A configuração de **:::no-loc(LC_NUMERIC):::** categoria da localidade determina o reconhecimento do caractere fracionário (o marcador fracionário ou o ponto decimal) na *cadeia de caracteres*. As funções **:::no-loc(strtol):::** e **:::no-loc(wcstol):::** usam a localidade atual. **:::no-loc(_strtol_l):::** e **:::no-loc(_wcstol_l):::** use a localidade passada em seu lugar. Para obter mais informações, consulte [ :::no-loc(setlocale)::: ] e [localidade](../../c-runtime-library/locale.md).

Quando *end_ptr* é **nulo**, ele é ignorado. Caso contrário, um ponteiro para o caractere que parou a verificação é armazenado no local apontado por *end_ptr*. Nenhuma conversão será possível se nenhum dígito válido for encontrado ou se uma base inválida for especificada. O valor da *cadeia de caracteres* é armazenado no local apontado por *end_ptr*.

**:::no-loc(strtol):::** Espera que a *cadeia de caracteres* aponte para uma cadeia de caracteres do seguinte formato:

> [*espaço em branco*] [{ **+** &#124; **-** }] [**0** [{ **x** &#124; **x** }]] [*alfanuméricos*]

Colchetes ( `[ ]` ) envolvem elementos opcionais. Chaves e uma barra vertical ( `{ | }` ) envolvem alternativas para um único elemento. o *espaço em branco* pode consistir em caracteres de espaço e tabulação, ignorados. os *alfanuméricos* são dígitos decimais ou as letras ' a ' a ' z ' (ou ' a ' por meio de ' z '). O primeiro caractere que não se ajusta a esse formulário interrompe a verificação. Se *base* estiver entre 2 e 36, ela será usada como a base do número. Se *base* for 0, os caracteres iniciais da cadeia de caracteres apontados por *cadeia de caracteres* serão usados para determinar a base. Se o primeiro caractere for 0 e o segundo caractere não for ' x ' ou ' X ', a cadeia de caracteres será interpretada como um inteiro octal. Se o primeiro caractere for '0' e o segundo caractere for 'x' ou 'X', a cadeia de caracteres será interpretada como um inteiro hexadecimal. Se o primeiro caractere for de '1' até '9', a cadeia de caracteres será interpretada como um inteiro hexadecimal. As letras ' a ' a ' z ' (ou ' A ' até ' Z ') recebem os valores de 10 a 35. A verificação só permite letras cujos valores sejam menores que *base*. O primeiro caractere fora do intervalo da base interrompe o exame. Por exemplo, suponha que a *cadeia de caracteres* comece com "01". Se *base* for 0, o verificador assumirá que é um inteiro octal. Um caractere ' 8 ' ou ' 9 ' interrompe a verificação.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**:::no-loc(_tcstol):::**|**:::no-loc(strtol):::**|**:::no-loc(strtol):::**|**:::no-loc(wcstol):::**|
|**:::no-loc(_tcstol_l):::**|**:::no-loc(_strtol_l):::**|**:::no-loc(_strtol_l):::**|**:::no-loc(_wcstol_l):::**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**:::no-loc(strtol):::**|\<stdlib.h>|
|**:::no-loc(wcstol):::**|\<stdlib.h> ou \<wchar.h>|
|**:::no-loc(_strtol_l):::**|\<stdlib.h>|
|**:::no-loc(_wcstol_l):::**|\<stdlib.h> ou \<wchar.h>|

As **:::no-loc(_strtol_l):::** **:::no-loc(_wcstol_l):::** funções e são específicas da Microsoft, e não fazem parte da biblioteca C padrão. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../compatibility.md).

## <a name="example"></a>Exemplo

Consulte o exemplo para [:::no-loc(strtod):::](:::no-loc(strtod):::-:::no-loc(strtod):::-l-:::no-loc(wcstod):::-:::no-loc(wcstod):::-l.md) .

## <a name="see-also"></a>Confira também

[Conversão de dados](../data-conversion.md)\
[Localidade](../locale.md)\
[:::no-loc(localeconv):::](:::no-loc(localeconv):::.md)\
[:::no-loc(setlocale):::, :::no-loc(_wsetlocale):::](:::no-loc(setlocale):::-w:::no-loc(setlocale):::.md)\
[Cadeia de caracteres para funções de valor numérico](../string-to-numeric-value-functions.md)\
[:::no-loc(strtod):::, :::no-loc(_strtod_l):::, :::no-loc(wcstod):::, :::no-loc(_wcstod_l):::](:::no-loc(strtod):::-:::no-loc(strtod):::-l-:::no-loc(wcstod):::-:::no-loc(wcstod):::-l.md)\
[:::no-loc(strtoll):::, :::no-loc(_strtoll_l):::, :::no-loc(wcstoll):::, :::no-loc(_wcstoll_l):::](:::no-loc(strtoll):::-:::no-loc(strtoll):::-l-:::no-loc(wcstoll):::-:::no-loc(wcstoll):::-l.md)\
[:::no-loc(strtoul):::, :::no-loc(_strtoul_l):::, :::no-loc(wcstoul):::, :::no-loc(_wcstoul_l):::](:::no-loc(strtoul):::-:::no-loc(strtoul):::-l-:::no-loc(wcstoul):::-:::no-loc(wcstoul):::-l.md)\
[:::no-loc(atof):::, :::no-loc(_atof_l):::, :::no-loc(_wtof):::, :::no-loc(_wtof_l):::](:::no-loc(atof):::-:::no-loc(atof):::-l-wtof-wtof-l.md)
