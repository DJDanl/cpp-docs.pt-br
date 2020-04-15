---
title: _create_locale, _wcreate_locale
ms.date: 4/2/2020
api_name:
- _create_locale
- __create_locale
- _wcreate_locale
- _o__create_locale
- _o__wcreate_locale
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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: 611eaf342776b9a0f57c4f55c52a841c3fd13fb5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81348260"
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

### <a name="parameters"></a>Parâmetros

*Categoria*<br/>
Categoria.

*Localidade*<br/>
Especificador de localidade.

## <a name="return-value"></a>Valor retornado

Se for dado um *local* e *categoria* válidos, retorna as configurações de local especificadas como um **objeto _locale_t.** As configurações de localidade atual do programa não são alteradas.

## <a name="remarks"></a>Comentários

A função **_create_locale** permite criar um objeto que represente determinadas configurações específicas da região, para uso em versões específicas locais de muitas funções CRT (funções com o **sufixo _l).** O comportamento é semelhante ao **setlocale,** exceto que, em vez de aplicar as configurações de localização especificadas no ambiente atual, as configurações são salvas em uma estrutura **_locale_t** que é devolvida. A estrutura **_locale_t** deve ser liberada usando [_free_locale](free-locale.md) quando não for mais necessário.

**_wcreate_locale** é uma versão ampla do **_create_locale;** o argumento *local* para **_wcreate_locale** é uma seqüência de caracteres amplo. **_wcreate_locale** e **_create_locale** se comportam de forma idêntica.

O argumento *da categoria* especifica as partes do comportamento específico do local que são afetadas. As bandeiras utilizadas para *a categoria* e as partes do programa que afetam são como mostrado nesta tabela:

| *bandeira categoria* | Afeta |
|-----------------|---------|
| **Lc_all** |Todas as categorias, conforme listado abaixo. |
| **LC_COLLATE** |O **strcoll**, **_stricoll**, **wcscoll**, **_wcsicoll**, **strxfrm**, **_strncoll**, **_strnicoll**, **_wcsncoll**, **_wcsnicoll**, e **wcsxfrm.** |
| **LC_CTYPE** | As funções de manuseio de caracteres (exceto **isdigit**, **isxdigit,** **mbstowcs**e **mbtowc**, que não são afetadas). |
| **LC_MONETARY** | Informações de formatação monetária retornadas pela função **localeconv.** |
| **LC_NUMERIC** | Caractere de ponto decimal para as rotinas de saída formatadas (como **printf),** para as rotinas de conversão de dados e para as informações de formatação não monetárias retornadas pela **localeconv**. Além do caractere de ponto decimal, **LC_NUMERIC** define o separador de milhares e a seqüência de controle de agrupamento retornada por [localeconv](localeconv.md). |
| **LC_TIME** | As funções **strftime** e **wcsftime.** |

Esta função valida os parâmetros de *categoria* *e local.* Se o parâmetro de categoria não for um dos valores dados na tabela anterior ou se a *localidade* for **NULA,** a função retorna **NULA**.

O *argumento local é* um ponteiro para uma string que especifica o local. Para obter informações sobre o formato do argumento *local,* consulte [Nomes locais, idiomas e strings de país/região](../../c-runtime-library/locale-names-languages-and-country-region-strings.md).

O argumento *local* pode ter um nome local, uma seqüência de idiomas, uma seqüência de idiomas e código de país/região, uma página de código ou uma seqüência de idiomas, código de país/região e página de código. O conjunto de nomes locais disponíveis, idiomas, códigos de país/região e páginas de código inclui tudo o que é suportado pela API do Windows NLS. O conjunto de nomes locais suportados por **_create_locale** são descritos em [Nomes locais, idiomas e strings de país/região](../../c-runtime-library/locale-names-languages-and-country-region-strings.md). O conjunto de strings de idioma e país/região suportados por **_create_locale** estão listados em [Strings de idioma](../../c-runtime-library/language-strings.md) e [strings país/região](../../c-runtime-library/country-region-strings.md).

Para obter mais informações sobre as configurações de localidade, consulte [setlocale, _wsetlocale](setlocale-wsetlocale.md).

O nome anterior desta função, **__create_locale** (com dois sublinhados principais), foi preterido.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_create_locale**|\<locale.h>|
|**_wcreate_locale**|\<locale.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

[Nomes locais, idiomas e strings país/região](../../c-runtime-library/locale-names-languages-and-country-region-strings.md)<br/>
[Cadeias de caracteres de idioma](../../c-runtime-library/language-strings.md)<br/>
[Cadeias de caracteres de país/região](../../c-runtime-library/country-region-strings.md)<br/>
[_free_locale](free-locale.md)<br/>
[_configthreadlocale](configthreadlocale.md)<br/>
[Setlocale](../../preprocessor/setlocale.md)<br/>
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
