---
title: "Conversão de dados | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- c.conversions
dev_langs:
- C++
helpviewer_keywords:
- data conversion routines [C++]
- converting data
ms.assetid: b15b5268-7467-49f1-bf95-5299b598f94c
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Human Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 11971f357250d56f8b474595a9608dc1ea0b478d
ms.lasthandoff: 03/30/2017

---
# <a name="data-conversion"></a>Conversão de dados
Essas rotinas convertem dados de um formulário para outro. Geralmente, essas rotinas são executadas mais rapidamente do que as conversões que podem ser escritas. Cada rotina que começa com um prefixo `to` é implementada como função e como macro. Consulte [Escolher entre funções e macros](../c-runtime-library/recommendations-for-choosing-between-functions-and-macros.md) para obter informações sobre como escolher uma implementação.  
  
### <a name="data-conversion-routines"></a>Rotinas de conversão de dados  
  
|Rotina|Uso|  
|-------------|---------|  
|[abs](../c-runtime-library/reference/abs-labs-llabs-abs64.md)|Localizar o valor absoluto de um inteiro|  
|[atof, _atof_l, _wtof, _wtof_l](../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)|Converter cadeia de caracteres em `float`|  
|[atoi, _atoi_l, _wtoi, _wtoi_l](../c-runtime-library/reference/atoi-atoi-l-wtoi-wtoi-l.md)|Converter cadeia de caracteres em `int`|  
|[_atoi64, _atoi64_l, _wtoi64, _wtoi64_l](../c-runtime-library/reference/atoi64-atoi64-l-wtoi64-wtoi64-l.md)|Converter cadeia de caracteres em `__int64`|  
|[atol, _atol_l, _wtol, _wtol_l](../c-runtime-library/reference/atol-atol-l-wtol-wtol-l.md)|Converter cadeia de caracteres em `long`|  
|[_ecvt](../c-runtime-library/reference/ecvt.md), [_ecvt_s](../c-runtime-library/reference/ecvt-s.md)|Converter `double` em cadeia de caracteres de comprimento especificado|  
|[_fcvt](../c-runtime-library/reference/fcvt.md), [_fcvt_s](../c-runtime-library/reference/fcvt-s.md)|Converter `double` em cadeia de caracteres com número especificado de dígitos após o separador decimal|  
|[_gcvt](../c-runtime-library/reference/gcvt.md), [_gcvt_s](../c-runtime-library/reference/gcvt-s.md)|Converter número `double` em cadeia de caracteres; armazenar cadeia de caracteres no buffer|  
|[_itoa, _i64toa, _ui64toa, _itow, _i64tow, _ui64tow](../c-runtime-library/reference/itoa-i64toa-ui64toa-itow-i64tow-ui64tow.md), [_itoa_s, _i64toa_s, _ui64toa_s, _itow_s, _i64tow_s, _ui64tow_s](../c-runtime-library/reference/itoa-s-i64toa-s-ui64toa-s-itow-s-i64tow-s-ui64tow-s.md)|Converter `int` ou `__int64` em cadeia de caracteres|  
|[labs](../c-runtime-library/reference/abs-labs-llabs-abs64.md)|Localizar o valor absoluto do inteiro `long`|  
|[llabs](../c-runtime-library/reference/abs-labs-llabs-abs64.md)|Localizar o valor absoluto do inteiro `long long`|  
|[_ltoa, _ltow](../c-runtime-library/reference/ltoa-ltow.md), [_ltoa_s, _ltow_s](../c-runtime-library/reference/ltoa-s-ltow-s.md)|Converter `long` em cadeia de caracteres|  
|[_mbbtombc, _mbbtombc_l](../c-runtime-library/reference/mbbtombc-mbbtombc-l.md)|Converter caractere multibyte de 1 byte no caractere multibyte de 2 bytes correspondente|  
|[_mbcjistojms, _mbcjistojms_l, _mbcjmstojis, _mbcjmstojis_l](../c-runtime-library/reference/mbcjistojms-mbcjistojms-l-mbcjmstojis-mbcjmstojis-l.md)|Converter caractere JIS (Japan Industry Standard) em caractere JMS (Japan Microsoft)|  
|[_mbcjistojms, _mbcjistojms_l, _mbcjmstojis, _mbcjmstojis_l](../c-runtime-library/reference/mbcjistojms-mbcjistojms-l-mbcjmstojis-mbcjmstojis-l.md)|Converter caractere JMS em caractere JIS|  
|[_mbctohira, _mbctohira_l, _mbctokata, _mbctokata_l](../c-runtime-library/reference/mbctohira-mbctohira-l-mbctokata-mbctokata-l.md)|Converter caractere multibyte em código hiragana de 1 byte|  
|[_mbctohira, _mbctohira_l, _mbctokata, _mbctokata_l](../c-runtime-library/reference/mbctohira-mbctohira-l-mbctokata-mbctokata-l.md)|Converter caractere multibyte em código katakana de 1 byte|  
|[_mbctombb, _mbctombb_l](../c-runtime-library/reference/mbctombb-mbctombb-l.md)|Converter caractere multibyte de 2 bytes no caractere multibyte de 1 byte correspondente|  
|[mbstowcs, _mbstowcs_l](../c-runtime-library/reference/mbstowcs-mbstowcs-l.md), [mbstowcs_s, _mbstowcs_s_l](../c-runtime-library/reference/mbstowcs-s-mbstowcs-s-l.md)|Converter sequência de caracteres multibyte na sequência de caracteres largos correspondente|  
|[mbtowc, _mbtowc_l](../c-runtime-library/reference/mbtowc-mbtowc-l.md)|Converter um caractere multibyte em um caractere largo correspondente|  
|[strtod, _strtod_l, wcstod, _wcstod_l](../c-runtime-library/reference/strtod-strtod-l-wcstod-wcstod-l.md)|Converter cadeia de caracteres em `double`|  
|[strtol, wcstol, _strtol_l, _wcstol_l](../c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l.md)|Converter cadeia de caracteres no inteiro `long`|  
|[strtoul, _strtoul_l, wcstoul, _wcstoul_l](../c-runtime-library/reference/strtoul-strtoul-l-wcstoul-wcstoul-l.md)|Converter cadeia de caracteres no inteiro `unsigned long`|  
|[strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l](../c-runtime-library/reference/strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)|Transformar cadeia de caracteres em forma agrupada com base em informações específicas da localidade|  
|[toascii, __toascii](../c-runtime-library/reference/toascii-toascii.md)|Converter caractere em código ASCII||  
|[tolower, _tolower, towlower, _tolower_l, _towlower_l](../c-runtime-library/reference/tolower-tolower-towlower-tolower-l-towlower-l.md), [_mbctolower, _mbctolower_l, _mbctoupper, _mbctoupper_l](../c-runtime-library/reference/mbctolower-mbctolower-l-mbctoupper-mbctoupper-l.md)|Testar caractere e converter em minúsculas se estiver em maiúsculas|  
|[tolower, _tolower, towlower, _tolower_l, _towlower_l](../c-runtime-library/reference/tolower-tolower-towlower-tolower-l-towlower-l.md)|Converter caractere em minúsculas incondicionalmente|[System::String::ToLower](https://msdn.microsoft.com/en-us/library/system.string.tolower.aspx)|  
|[toupper, _toupper, towupper, _toupper_l, _towupper_l](../c-runtime-library/reference/toupper-toupper-towupper-toupper-l-towupper-l.md), [_mbctolower, _mbctolower_l, _mbctoupper, _mbctoupper_l](../c-runtime-library/reference/mbctolower-mbctolower-l-mbctoupper-mbctoupper-l.md)|Testar caractere e converter em maiúsculas se estiver em minúsculas|  
|[toupper, _toupper, towupper, _toupper_l, _towupper_l](../c-runtime-library/reference/toupper-toupper-towupper-toupper-l-towupper-l.md)|Converter caractere em maiúsculas incondicionalmente|  
|[_ultoa, _ultow](../c-runtime-library/reference/ultoa-ultow.md), [_ultoa_s, _ultow_s](../c-runtime-library/reference/ultoa-s-ultow-s.md)|Converter `unsigned long` em cadeia de caracteres|  
|[wcstombs, _wcstombs_l](../c-runtime-library/reference/wcstombs-wcstombs-l.md), [wcstombs_s, _wcstombs_s_l](../c-runtime-library/reference/wcstombs-s-wcstombs-s-l.md)|Converter sequência de caracteres largos na sequência de caracteres multibyte correspondente|  
|[wctomb, _wctomb_l](../c-runtime-library/reference/wctomb-wctomb-l.md), [wctomb_s, _wctomb_s_l](../c-runtime-library/reference/wctomb-s-wctomb-s-l.md)|Converter um caractere largo em um caractere multibyte correspondente|  
|[atof, _atof_l, _wtof, _wtof_l](../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)|Converter cadeia de caracteres largos em um `double`|   
|[atoi, _atoi_l, _wtoi, _wtoi_l](../c-runtime-library/reference/atoi-atoi-l-wtoi-wtoi-l.md)|Converter cadeia de caracteres largos em `int`|  
|[_atoi64, _atoi64_l, _wtoi64, _wtoi64_l](../c-runtime-library/reference/atoi64-atoi64-l-wtoi64-wtoi64-l.md)|Converter cadeia de caracteres largos em `__int64`|  
|[atol, _atol_l, _wtol, _wtol_l](../c-runtime-library/reference/atol-atol-l-wtol-wtol-l.md)|Converter cadeia de caracteres largos em `long`|  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)
