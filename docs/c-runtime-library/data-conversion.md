---
title: Conversão de Dados
ms.date: 03/21/2018
f1_keywords:
- c.conversions
helpviewer_keywords:
- data conversion routines [C++]
- converting data
ms.assetid: b15b5268-7467-49f1-bf95-5299b598f94c
ms.openlocfilehash: 94e6a8182e12ecd74f9d2cd5dddaa84a1e3eb847
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218761"
---
# <a name="data-conversion"></a>Conversão de Dados

Essas rotinas convertem dados de um formulário para outro. Geralmente, essas rotinas são executadas mais rapidamente do que as conversões que podem ser escritas. Cada rotina que começa com um prefixo *to* é implementada como função e como macro. Consulte [Escolher entre funções e macros](../c-runtime-library/recommendations-for-choosing-between-functions-and-macros.md) para obter informações sobre como escolher uma implementação.

## <a name="data-conversion-routines"></a>Rotinas de conversão de dados

|Rotina|Uso|
|-------------|---------|
|[ABS](../c-runtime-library/reference/abs-labs-llabs-abs64.md)|Localizar o valor absoluto de um inteiro|
|[atof, _atof_l](../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)|Converter cadeia de caracteres em**`float`**|
|[atoi, _atoi_l](../c-runtime-library/reference/atoi-atoi-l-wtoi-wtoi-l.md)|Converter cadeia de caracteres em**`int`**|
|[_atoi64, _atoi64_l](../c-runtime-library/reference/atoi64-atoi64-l-wtoi64-wtoi64-l.md)|Converter cadeia de caracteres em **`__int64`** ou**`long long`**|
|[atol, _atol_l](../c-runtime-library/reference/atol-atol-l-wtol-wtol-l.md)|Converter cadeia de caracteres em**`long`**|
|[c16rtomb, c32rtomb](../c-runtime-library/reference/c16rtomb-c32rtomb1.md)|Converter caracteres UTF-16 ou UTF-32 em um equivalente multibyte|
|[_ecvt](../c-runtime-library/reference/ecvt.md), [_ecvt_s](../c-runtime-library/reference/ecvt-s.md)|Converter **`double`** em cadeia de caracteres de comprimento especificado|
|[_fcvt](../c-runtime-library/reference/fcvt.md), [_fcvt_s](../c-runtime-library/reference/fcvt-s.md)|Converter **`double`** em cadeia de caracteres com o número especificado de dígitos após o ponto decimal|
|[_gcvt](../c-runtime-library/reference/gcvt.md), [_gcvt_s](../c-runtime-library/reference/gcvt-s.md)|Converter **`double`** número em cadeia de caracteres; armazenar cadeia de caracteres no buffer|
|[_itoa, _ltoa, _ultoa, _i64toa, _ui64toa, _itow, _ltow, ultow, _i64tow, _ui64tow](../c-runtime-library/reference/itoa-itow.md), [_itoa_s, _ltoa_s, _ultoa_s, _i64toa_s, _ui64toa_s, _itow_s, _ltow_s, _ultow_s, _i64tow_s, _ui64tow_s](../c-runtime-library/reference/itoa-s-itow-s.md)|Converter os tipos de inteiro em cadeia de caracteres|
|[labs](../c-runtime-library/reference/abs-labs-llabs-abs64.md)|Localizar o valor absoluto do **`long`** inteiro|
|[llabs](../c-runtime-library/reference/abs-labs-llabs-abs64.md)|Localizar o valor absoluto do **`long long`** inteiro|
|[_mbbtombc, _mbbtombc_l](../c-runtime-library/reference/mbbtombc-mbbtombc-l.md)|Converter caractere multibyte de 1 byte no caractere multibyte de 2 bytes correspondente|
|[_mbcjistojms, _mbcjistojms_l, _mbcjmstojis, _mbcjmstojis_l](../c-runtime-library/reference/mbcjistojms-mbcjistojms-l-mbcjmstojis-mbcjmstojis-l.md)|Converter caractere JIS (Japan Industry Standard) em caractere JMS (Japan Microsoft)|
|[_mbcjistojms, _mbcjistojms_l, _mbcjmstojis, _mbcjmstojis_l](../c-runtime-library/reference/mbcjistojms-mbcjistojms-l-mbcjmstojis-mbcjmstojis-l.md)|Converter caractere JMS em caractere JIS|
|[_mbctohira, _mbctohira_l, _mbctokata, _mbctokata_l](../c-runtime-library/reference/mbctohira-mbctohira-l-mbctokata-mbctokata-l.md)|Converter caractere multibyte em código hiragana de 1 byte|
|[_mbctohira, _mbctohira_l, _mbctokata, _mbctokata_l](../c-runtime-library/reference/mbctohira-mbctohira-l-mbctokata-mbctokata-l.md)|Converter caractere multibyte em código katakana de 1 byte|
|[_mbctombb, _mbctombb_l](../c-runtime-library/reference/mbctombb-mbctombb-l.md)|Converter caractere multibyte de 2 bytes no caractere multibyte de 1 byte correspondente|
|[mbrtoc16, mbrtoc32](../c-runtime-library/reference/mbrtoc16-mbrtoc323.md)|Converter caracteres multibyte em caracteres UTF-16 ou UTF-32 equivalentes|
|[mbstowcs, _mbstowcs_l](../c-runtime-library/reference/mbstowcs-mbstowcs-l.md), [mbstowcs_s, _mbstowcs_s_l](../c-runtime-library/reference/mbstowcs-s-mbstowcs-s-l.md)|Converter uma sequência de caracteres multibyte em uma sequência de caracteres largos correspondente|
|[mbtowc, _mbtowc_l](../c-runtime-library/reference/mbtowc-mbtowc-l.md)|Converter um caractere multibyte em um caractere largo correspondente|
|[strtod, _strtod_l, wcstod, _wcstod_l](../c-runtime-library/reference/strtod-strtod-l-wcstod-wcstod-l.md)|Converter cadeia de caracteres em**`double`**|
|[strtol, wcstol, _strtol_l, _wcstol_l](../c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l.md)|Converter cadeia de caracteres em **`long`** inteiro|
|[strtoul, _strtoul_l, wcstoul, _wcstoul_l](../c-runtime-library/reference/strtoul-strtoul-l-wcstoul-wcstoul-l.md)|Converter cadeia de caracteres em **`unsigned long`** inteiro|
|[strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l](../c-runtime-library/reference/strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)|Transformar cadeia de caracteres em forma agrupada com base em informações específicas da localidade|
|[toascii, __toascii](../c-runtime-library/reference/toascii-toascii.md)|Converter caractere em código ASCII|
|[tolower, _tolower, towlower, _tolower_l, _towlower_l](../c-runtime-library/reference/tolower-tolower-towlower-tolower-l-towlower-l.md), [_mbctolower, _mbctolower_l, _mbctoupper, _mbctoupper_l](../c-runtime-library/reference/mbctolower-mbctolower-l-mbctoupper-mbctoupper-l.md)|Testar caractere e converter em minúsculas se estiver em maiúsculas|
|[tolower, _tolower, towlower, _tolower_l, _towlower_l](../c-runtime-library/reference/tolower-tolower-towlower-tolower-l-towlower-l.md)|Converter caractere em minúsculas incondicionalmente|
|[toupper, _toupper, towupper, _toupper_l, _towupper_l](../c-runtime-library/reference/toupper-toupper-towupper-toupper-l-towupper-l.md), [_mbctolower, _mbctolower_l, _mbctoupper, _mbctoupper_l](../c-runtime-library/reference/mbctolower-mbctolower-l-mbctoupper-mbctoupper-l.md)|Testar caractere e converter em maiúsculas se estiver em minúsculas|
|[toupper, _toupper, towupper, _toupper_l, _towupper_l](../c-runtime-library/reference/toupper-toupper-towupper-toupper-l-towupper-l.md)|Converter caractere em maiúsculas incondicionalmente|
|[wcstombs, _wcstombs_l](../c-runtime-library/reference/wcstombs-wcstombs-l.md), [wcstombs_s, _wcstombs_s_l](../c-runtime-library/reference/wcstombs-s-wcstombs-s-l.md)|Converter cadeia de caracteres largos na cadeia de caracteres multibyte correspondente|
|[wctomb, _wctomb_l](../c-runtime-library/reference/wctomb-wctomb-l.md), [wctomb_s, _wctomb_s_l](../c-runtime-library/reference/wctomb-s-wctomb-s-l.md)|Converter um caractere largo em um caractere multibyte correspondente|
|[_wtof, _wtof_l](../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)|Converter cadeia de caracteres largos em um**`double`**|
|[_wtoi, _wtoi_l](../c-runtime-library/reference/atoi-atoi-l-wtoi-wtoi-l.md)|Converter cadeia de caracteres largos em**`int`**|
|[_wtoi64, _wtoi64_l](../c-runtime-library/reference/atoi64-atoi64-l-wtoi64-wtoi64-l.md)|Converter cadeia de caracteres largos em **`__int64`** ou**`long long`**|
|[_wtol, _wtol_l](../c-runtime-library/reference/atol-atol-l-wtol-wtol-l.md)|Converter cadeia de caracteres largos em**`long`**|

## <a name="see-also"></a>Confira também

[Rotinas de runtime C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>
