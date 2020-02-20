---
title: _create_locale, _wcreate_locale
ms.date: 11/04/2016
api_name:
- _create_locale
- __create_locale
- _wcreate_locale
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
- api-ms-win-crt-locale-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- create_locale
- _create_locale
- __create_locale
helpviewer_keywords:
- locales, creating
- _create_locale function
- create_locale function
- __create_locale function
ms.assetid: ca362464-9f4a-4ec6-ab03-316c55c5be81
ms.openlocfilehash: 58274b63a09847fb8593247bd2777cfa19935510
ms.sourcegitcommit: f38f770bfda1c174d2b81fabda7c893b15bd83a1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/20/2020
ms.locfileid: "77473840"
---
# <a name="_create_locale-_wcreate_locale"></a>_create_locale, _wcreate_locale

Cria um objeto de localidade.

## <a name="syntax"></a>Sintaxe

```C
_locale_t _create_locale(
   int category,
   const char *locale
);
_locale_t _wcreate_locale(
   int category,
   const wchar_t *locale
);
```

### <a name="parameters"></a>parâmetros

*category*<br/>
Categoria.

*locale*<br/>
Especificador de localidade.

## <a name="return-value"></a>Valor retornado

Se uma *localidade* e *categoria* válidas forem fornecidas, o retornará as configurações de localidade especificadas como um objeto **_locale_t** . As configurações de localidade atual do programa não são alteradas.

## <a name="remarks"></a>Comentários

A função **_create_locale** permite que você crie um objeto que representa determinadas configurações específicas de região, para uso em versões específicas de localidade de muitas funções do CRT (funções com o sufixo **_L** ). O comportamento é semelhante ao **setlocale**, exceto que, em vez de aplicar as configurações de localidade especificadas ao ambiente atual, as configurações são salvas em uma estrutura de **_locale_t** retornada. A estrutura de **_locale_t** deve ser liberada usando [_free_locale](free-locale.md) quando não for mais necessária.

**_wcreate_locale** é uma versão de caractere largo do **_create_locale**; o argumento de *localidade* para **_wcreate_locale** é uma cadeia de caracteres largos. **_wcreate_locale** e **_create_locale** se comportar de forma idêntica.

O argumento *Category* especifica as partes do comportamento específico da localidade que são afetadas. Os sinalizadores usados para a *categoria* e as partes do programa que eles afetam são mostrados nesta tabela:

| sinalizador de *categoria* | Afeta |
|-----------------|---------|
| **LC_ALL** |Todas as categorias, conforme listado abaixo. |
| **LC_COLLATE** |As funções **strcoll**, **_stricoll**, **wcscoll**, **_wcsicoll**, **strxfrm**, **_strncoll**, **_strnicoll**, **_wcsncoll**, **_wcsnicoll**e **wcsxfrm** . |
| **LC_CTYPE** | As funções de manipulação de caracteres (exceto **IsDigit**, **isxdigit**, **mbstowcs**e **mbtowc**, que não são afetadas). |
| **LC_MONETARY** | Informações de formatação monetária retornadas pela função **localeconv** . |
| **LC_NUMERIC** | Caractere de ponto decimal para as rotinas de saída formatadas (como **printf**), para as rotinas de conversão de dados e para as informações de formatação não monetária retornadas por **localeconv**. Além do caractere de ponto decimal, **LC_NUMERIC** define o separador de milhar e a cadeia de caracteres de controle de agrupamento retornada por [localeconv](localeconv.md). |
| **LC_TIME** | As funções **strftime** e **wcsftime** . |

Essa função valida os parâmetros de *categoria* e *localidade* . Se o parâmetro Category não for um dos valores fornecidos na tabela anterior ou se *locale* for **NULL**, a função retornará **NULL**.

O argumento de *localidade* é um ponteiro para uma cadeia de caracteres que especifica a localidade. Para obter informações sobre o formato do argumento de *localidade* , consulte [nomes de localidade, idiomas e cadeias de país/região](../../c-runtime-library/locale-names-languages-and-country-region-strings.md).

O argumento de *localidade* pode usar um nome de localidade, uma cadeia de caracteres de idioma, uma cadeia de caracteres de idioma e um código de país/região, uma página de código ou uma cadeia de caracteres de idioma, código de país/região e página de código. O conjunto de nomes de localidade disponíveis, idiomas, códigos de país/região e páginas de código inclui tudo o que é suportado pela API NLS do Windows. O conjunto de nomes de localidade com suporte pelo **_create_locale** é descrito em [nomes de localidade, linguagens e cadeias de país/região](../../c-runtime-library/locale-names-languages-and-country-region-strings.md). O conjunto de cadeias de caracteres de idioma e país/região com suporte do **_create_locale** está listado em cadeias de caracteres de [idioma](../../c-runtime-library/language-strings.md) e cadeias de [país/região](../../c-runtime-library/country-region-strings.md).

Para obter mais informações sobre as configurações de localidade, consulte [setlocale, _wsetlocale](setlocale-wsetlocale.md).

O nome anterior dessa função, **__create_locale** (com dois sublinhados à esquerda), foi preterido.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_create_locale**|\<locale.h>|
|**_wcreate_locale**|\<locale.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_create_locale.c
// Sets the current locale to "de-CH" using the
// setlocale function and demonstrates its effect on the strftime
// function.

#include <stdio.h>
#include <locale.h>
#include <time.h>

int main(void)
{
    time_t ltime;
    struct tm thetime;
    unsigned char str[100];
    _locale_t locale;

    // Create a locale object representing the German (Switzerland) locale
    locale = _create_locale(LC_ALL, "de-CH");
    time (&ltime);
    _gmtime64_s(&thetime, &ltime);

    // %#x is the long date representation, appropriate to
    // the current locale
    if (!_strftime_l((char *)str, 100, "%#x",
                     (const struct tm *)&thetime, locale))
    {
        printf("_strftime_l failed!\n");
    }
    else
    {
        printf("In de-CH locale, _strftime_l returns '%s'\n", str);
    }

    _free_locale(locale);

    // Create a locale object representing the default C locale
    locale = _create_locale(LC_ALL, "C");
    time(&ltime);
    _gmtime64_s(&thetime, &ltime);

    if (!_strftime_l((char *)str, 100, "%#x",
                     (const struct tm *)&thetime, locale))
    {
        printf("_strftime_l failed!\n");
    }
    else
    {
        printf("In 'C' locale, _strftime_l returns '%s'\n", str);
    }

    _free_locale(locale);
}
```

```Output
In de-CH locale, _strftime_l returns 'Samstag, 9. Februar 2002'
In 'C' locale, _strftime_l returns 'Saturday, February 09, 2002'
```

## <a name="see-also"></a>Confira também

[Nomes de localidades, idiomas e cadeias de caracteres de país/região](../../c-runtime-library/locale-names-languages-and-country-region-strings.md)<br/>
[Cadeias de caracteres de idioma](../../c-runtime-library/language-strings.md)<br/>
[Cadeias de caracteres de país/região](../../c-runtime-library/country-region-strings.md)<br/>
[_free_locale](free-locale.md)<br/>
[_configthreadlocale](configthreadlocale.md)<br/>
[setlocale](../../preprocessor/setlocale.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[localeconv](localeconv.md)<br/>
[_mbclen, mblen, _mblen_l](mbclen-mblen-mblen-l.md)<br/>
[strlen, wcslen, _mbslen, _mbslen_l, _mbstrlen, _mbstrlen_l](strlen-wcslen-mbslen-mbslen-l-mbstrlen-mbstrlen-l.md)<br/>
[mbstowcs, _mbstowcs_l](mbstowcs-mbstowcs-l.md)<br/>
[mbtowc, _mbtowc_l](mbtowc-mbtowc-l.md)<br/>
[_setmbcp](setmbcp.md)<br/>
[setlocale, _wsetlocale](setlocale-wsetlocale.md)<br/>
[Funções strcoll](../../c-runtime-library/strcoll-functions.md)<br/>
[strftime, wcsftime, _strftime_l, _wcsftime_l](strftime-wcsftime-strftime-l-wcsftime-l.md)<br/>
[strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l](strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)<br/>
[wcstombs, _wcstombs_l](wcstombs-wcstombs-l.md)<br/>
[wctomb, _wctomb_l](wctomb-wctomb-l.md)<br/>
