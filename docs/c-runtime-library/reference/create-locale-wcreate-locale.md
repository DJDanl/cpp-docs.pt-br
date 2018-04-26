---
title: _create_locale, _wcreate_locale | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _create_locale
- __create_locale
- _wcreate_locale
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
- api-ms-win-crt-locale-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- create_locale
- _create_locale
- __create_locale
dev_langs:
- C++
helpviewer_keywords:
- locales, creating
- _create_locale function
- create_locale function
- __create_locale function
ms.assetid: ca362464-9f4a-4ec6-ab03-316c55c5be81
caps.latest.revision: 23
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 420f18b3bac3daf538ee5eee48b8e57bedbdf9c1
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="createlocale-wcreatelocale"></a>_create_locale, _wcreate_locale

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

*category*<br/>
Categoria.

*locale*<br/>
Especificador de localidade.

## <a name="return-value"></a>Valor de retorno

Se uma opção válida *localidade* e *categoria* recebem, retorna as configurações de localidade especificada como um **locale_t** objeto. As configurações de localidade atual do programa não são alteradas.

## <a name="remarks"></a>Comentários

O **create_locale** função permite que você crie um objeto que representa certas configurações específicas da região, para uso em versões específicas de localidade de muitas funções CRT (funções com o **_l** sufixo ). O comportamento é semelhante ao **setlocale**, exceto que, em vez de aplicar as configurações de localidade especificada no ambiente atual, as configurações são salvas em um **locale_t** estrutura que é retornada. O **locale_t** estrutura deve ser liberada usando [free_locale](free-locale.md) quando ele não for mais necessário.

**_wcreate_locale** é uma versão de caractere largo de **create_locale**; o *localidade* argumento **_wcreate_locale** é uma cadeia de caracteres largos. **_wcreate_locale** e **create_locale** se comportam de forma idêntica caso contrário.

O *categoria* argumento especifica as partes do comportamento específico de localidade que são afetadas. Os sinalizadores usados para *categoria* e as partes do programa que afetem são conforme mostrado na tabela a seguir.

|*categoria* sinalizador|Afeta|
|-|-|
**LC_ALL**|Todas as categorias, conforme listado abaixo.
**LC_COLLATE**|O **strcoll**, **stricoll**, **wcscoll**, **wcsicoll**, **strxfrm**, **_ strncoll**, **strnicoll**, **wcsncoll**, **wcsnicoll**, e **wcsxfrm** funções.
**LC_CTYPE**|As funções de manipulação de caracteres (exceto **isdigit**, **isxdigit**, **mbstowcs**, e **mbtowc**, que não são afetado).
**LC_MONETARY**|Formatação monetário informações retornadas pelo **localeconv** função.
**LC_NUMERIC**|Caractere para as rotinas de saída formatada de ponto de decimal (como **printf**), para as rotinas de conversão de dados e para as informações de formatação não monetárias retornado por **localeconv**. Além do caractere de ponto decimal, **LC_NUMERIC** separador de milhares de conjuntos e o agrupamento de controle de cadeia de caracteres retornada por [localeconv](localeconv.md).
**LC_TIME**|O **strftime** e **wcsftime** funções.

Esta função valida o *categoria* e *localidade* parâmetros. Se o parâmetro de categoria não é um dos valores fornecidos na tabela anterior ou se *localidade* é **nulo**, a função retorna **nulo**.

O *localidade* argumento é um ponteiro para uma cadeia de caracteres que especifica a localidade. Para obter informações sobre o formato da *localidade* argumento, consulte [nomes de localidades, idiomas e cadeias de caracteres de país/região](../../c-runtime-library/locale-names-languages-and-country-region-strings.md).

O *localidade* argumento pode assumir um nome de localidade, uma cadeia de caracteres de idioma, uma cadeia de caracteres do idioma e o código de país/região, uma página de código, ou uma cadeia de caracteres de idioma, código de país/região e página de código. O conjunto de nomes de localidade, idiomas, códigos de país/região e páginas de código disponíveis inclui tudo o que tem suporte na API NLS do Windows, com exceção das páginas de código que exigem mais de dois bytes por caractere – por exemplo, UTF-7 e UTF-8. Se você fornecer uma página de código como UTF-7 ou UTF-8, **create_locale** falhará e retornará NULL. O conjunto de nomes de localidades com suporte **create_locale** são descritos na [nomes de localidades, idiomas e cadeias de caracteres de país/região](../../c-runtime-library/locale-names-languages-and-country-region-strings.md). O conjunto de cadeias de caracteres de idioma e país/região com suporte **create_locale** são listadas na [cadeias de caracteres do idioma](../../c-runtime-library/language-strings.md) e [cadeias de caracteres de país/região](../../c-runtime-library/country-region-strings.md).

Para obter mais informações sobre as configurações de localidade, consulte [setlocale, _wsetlocale](setlocale-wsetlocale.md).

O nome anterior desta função **create_locale** (com dois sublinhados), foi preterido.

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

## <a name="see-also"></a>Consulte também

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
