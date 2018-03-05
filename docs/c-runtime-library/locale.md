---
title: Localidade | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- c.international
dev_langs:
- C++
helpviewer_keywords:
- localization, locale
- country information
- language information routines
- setlocale function
- locale routines
ms.assetid: 442f8112-9288-44d7-be3c-15d22652093a
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 835c396c36a23d05a1e3512fa7ad5e4c4e81c795
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="locale"></a>Localidade
*Localidade* refere-se às configurações de país/região e idioma que você pode usar para personalizar o seu programa. Algumas categorias dependentes da localidade incluem os formatos de exibição para datas e valores monetários. Para saber mais, veja [Localidade](../c-runtime-library/locale-categories.md).  
  
 Use o [setlocale](../c-runtime-library/reference/setlocale-wsetlocale.md) função para alterar ou consultar algumas ou todas as informações atuais de localidade de thread ou de programa durante o uso de funções sem o `_l` sufixo. As funções com o `_l` sufixo usará o parâmetro de localidade passado para suas informações de localidade durante a execução dessa função específica apenas. Para criar uma localidade para uso com uma função com um sufixo `_l`, use [create_locale](../c-runtime-library/reference/create-locale-wcreate-locale.md). Para liberar essa localidade, use [free_locale](../c-runtime-library/reference/free-locale.md). Para obter a localidade atual, use [_get_current_locale](../c-runtime-library/reference/get-current-locale.md).  
  
 Use [_configthreadlocale](../c-runtime-library/reference/configthreadlocale.md) para controlar se cada thread tem sua própria localidade ou se todos os threads em um programa compartilham a mesma localidade. Para saber mais, veja [Localidade e páginas de código](../text/locales-and-code-pages.md).  
  
 As versões mais seguras das funções na tabela a seguir estão disponíveis, indicadas pelo sufixo `_s` ("secure"). Para obter mais informações, consulte [Recursos de segurança no CRT](../c-runtime-library/security-features-in-the-crt.md).  
  
### <a name="locale-dependent-routines"></a>Rotinas dependentes de localidade  
  
|Rotina|Use|`setlocale` dependência de configuração de categoria|  
|-------------|---------|---------------------------------------------|  
|[atof, _atof_l, _wtof, _wtof_l](../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)|Converter caractere em valor de ponto flutuante|`LC_NUMERIC`|  
|[atoi, _atoi_l, _wtoi, _wtoi_l](../c-runtime-library/reference/atoi-atoi-l-wtoi-wtoi-l.md)|Converter caractere em valor inteiro|`LC_NUMERIC`|  
|[_atoi64, _atoi64_l, _wtoi64, _wtoi64_l](../c-runtime-library/reference/atoi64-atoi64-l-wtoi64-wtoi64-l.md)|Converter caractere em valor inteiro de 64 bits|`LC_NUMERIC`|  
|[atol, _atol_l, _wtol, _wtol_l](../c-runtime-library/reference/atol-atol-l-wtol-wtol-l.md)|Converter caractere em valor longo|`LC_NUMERIC`|  
|[_atodbl, _atodbl_l, _atoldbl, _atoldbl_l, _atoflt, _atoflt_l](../c-runtime-library/reference/atodbl-atodbl-l-atoldbl-atoldbl-l-atoflt-atoflt-l.md)|Converter caractere em valor longo duplo|`LC_NUMERIC`|  
|[is Routines](../c-runtime-library/is-isw-routines.md)|Testar determinado inteiro para uma condição em particular.|`LC_CTYPE`|  
|[isleadbyte, _isleadbyte_l](../c-runtime-library/reference/isleadbyte-isleadbyte-l.md)|Teste de byte inicial|`LC_CTYPE`|  
|[localeconv](../c-runtime-library/reference/localeconv.md)|Ler os valores apropriados para a formatação de quantidades numéricas|`LC_MONETARY, LC_NUMERIC`|  
|[MB_CUR_MAX](../c-runtime-library/mb-cur-max.md)|Comprimento máximo em bytes de qualquer caractere multibyte na localidade atual (macro definida em STDLIB.H)|`LC_CTYPE`|  
|[_mbccpy, _mbccpy_l](../c-runtime-library/reference/mbccpy-mbccpy-l.md),[_mbccpy_s, _mbccpy_s_l](../c-runtime-library/reference/mbccpy-s-mbccpy-s-l.md)|Copiar um caractere multibyte|`LC_CTYPE`|  
|[_mbclen, mblen, _mblen_l](../c-runtime-library/reference/mbclen-mblen-mblen-l.md)|Validar e retornar número de bytes em caractere multibyte|`LC_CTYPE`|  
|[strlen, wcslen, _mbslen, _mbslen_l, _mbstrlen, _mbstrlen_l](../c-runtime-library/reference/strlen-wcslen-mbslen-mbslen-l-mbstrlen-mbstrlen-l.md)|Para cadeias de caracteres multibyte: validar cada caractere na cadeia de caracteres; Retornar o comprimento da cadeia de caracteres|`LC_CTYPE`|  
|[mbstowcs, _mbstowcs_l](../c-runtime-library/reference/mbstowcs-mbstowcs-l.md),[mbstowcs_s, _mbstowcs_s_l](../c-runtime-library/reference/mbstowcs-s-mbstowcs-s-l.md)|Converter uma sequência de caracteres multibyte em uma sequência de caracteres largos correspondente|`LC_CTYPE`|  
|[mbtowc, _mbtowc_l](../c-runtime-library/reference/mbtowc-mbtowc-l.md)|Converter um caractere multibyte em um caractere largo correspondente|`LC_CTYPE`|  
|Funções [printf](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)|Gravar saída formatada|`LC_NUMERIC` (determina a saída de caracteres de base)|  
|Funções [scanf](../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md)|Ler entrada formatada|`LC_NUMERIC` (determina o reconhecimento de caracteres de base)|  
|[setlocale, _wsetlocale](../c-runtime-library/reference/setlocale-wsetlocale.md)|Selecionar localidade para o programa|Não aplicável|  
|[strcoll, wcscoll, _mbscoll, _strcoll_l, _wcscoll_l, _mbscoll_l](../c-runtime-library/reference/strcoll-wcscoll-mbscoll-strcoll-l-wcscoll-l-mbscoll-l.md)|Comparar caracteres de duas cadeias de caracteres|`LC_COLLATE`|  
|[_stricmp, _wcsicmp, _mbsicmp, _stricmp_l, _wcsicmp_l, _mbsicmp_l](../c-runtime-library/reference/stricmp-wcsicmp-mbsicmp-stricmp-l-wcsicmp-l-mbsicmp-l.md)|Comparar duas cadeias de caracteres sem considerar as maiúsculas e minúsculas|`LC_CTYPE`|  
|[_stricoll, _wcsicoll, _mbsicoll, _stricoll_l, _wcsicoll_l, _mbsicoll_l](../c-runtime-library/reference/stricoll-wcsicoll-mbsicoll-stricoll-l-wcsicoll-l-mbsicoll-l.md)|Comparar caracteres de duas cadeias de caracteres (não diferencia maiúsculas de minúsculas)|`LC_COLLATE`|  
|[_strncoll, _wcsncoll, _mbsncoll, _strncoll_l, _wcsncoll_l, _mbsncoll_l](../c-runtime-library/reference/strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md)|Comparar `n` primeiros caracteres de duas cadeias de caracteres|`LC_COLLATE`|  
|[_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l](../c-runtime-library/reference/strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)|Comprar caracteres de duas cadeias de caracteres sem considerar as maiúsculas e minúsculas.|`LC_CTYPE`|  
|[_strnicoll, _wcsnicoll, _mbsnicoll, _strnicoll_l, _wcsnicoll_l, _mbsnicoll_l](../c-runtime-library/reference/strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|Comparar `n` primeiros caracteres de duas cadeias de caracteres (diferencia maiúsculas de minúsculas)|`LC_COLLATE`|  
|[strftime, wcsftime, _strftime_l, _wcsftime_l](../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md)|Formatar valor de data e hora de acordo com o argumento `format` fornecido|`LC_TIME`|  
|[_strlwr, _wcslwr, _mbslwr, _strlwr_l, _wcslwr_l, _mbslwr_l](../c-runtime-library/reference/strlwr-wcslwr-mbslwr-strlwr-l-wcslwr-l-mbslwr-l.md),[_strlwr_s, _strlwr_s_l, _mbslwr_s, _mbslwr_s_l, _wcslwr_s, _wcslwr_s_l](../c-runtime-library/reference/strlwr-s-strlwr-s-l-mbslwr-s-mbslwr-s-l-wcslwr-s-wcslwr-s-l.md)|Converter, no local, cada letra maiúscula em determinada cadeia de caracteres em minúsculas|`LC_CTYPE`|  
|[strtod, _strtod_l, wcstod, _wcstod_l](../c-runtime-library/reference/strtod-strtod-l-wcstod-wcstod-l.md)|Converter cadeia de caracteres no valor `double`|`LC_NUMERIC` (determina o reconhecimento de caracteres de base)|  
|[strtol, wcstol, _strtol_l, _wcstol_l](../c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l.md)|Converter cadeia de caracteres no valor `long`|`LC_NUMERIC` (determina o reconhecimento de caracteres de base)|  
|[strtoul, _strtoul_l, wcstoul, _wcstoul_l](../c-runtime-library/reference/strtoul-strtoul-l-wcstoul-wcstoul-l.md)|Converter cadeia de caracteres do caractere em valor longo unsigned|`LC_NUMERIC` (determina o reconhecimento de caracteres de base)|  
|[_strupr, _strupr_l, _mbsupr, _mbsupr_l, _wcsupr_l, _wcsupr](../c-runtime-library/reference/strupr-strupr-l-mbsupr-mbsupr-l-wcsupr-l-wcsupr.md),[_strupr_s, _strupr_s_l, _mbsupr_s, _mbsupr_s_l, _wcsupr_s, _wcsupr_s_l](../c-runtime-library/reference/strupr-s-strupr-s-l-mbsupr-s-mbsupr-s-l-wcsupr-s-wcsupr-s-l.md)|Converter, no local, cada letra minúscula em cadeia de caracteres em maiúsculas|`LC_CTYPE`|  
|[strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l](../c-runtime-library/reference/strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)|Transformar cadeia de caracteres em formato agrupado de acordo com a localidade|`LC_COLLATE`|  
|[tolower, _tolower, towlower, _tolower_l, _towlower_l](../c-runtime-library/reference/tolower-tolower-towlower-tolower-l-towlower-l.md),[_mbctolower, _mbctolower_l, _mbctoupper, _mbctoupper_l](../c-runtime-library/reference/mbctolower-mbctolower-l-mbctoupper-mbctoupper-l.md)|Converter determinado caractere no caractere minúsculo correspondente|`LC_CTYPE`|  
|[toupper, _toupper, towupper, _toupper_l, _towupper_l](../c-runtime-library/reference/toupper-toupper-towupper-toupper-l-towupper-l.md),[_mbctolower, _mbctolower_l, _mbctoupper, _mbctoupper_l](../c-runtime-library/reference/mbctolower-mbctolower-l-mbctoupper-mbctoupper-l.md)|Converter determinado caractere na letra minúscula correspondente|`LC_CTYPE`|  
|[wcstombs, _wcstombs_l](../c-runtime-library/reference/wcstombs-wcstombs-l.md),[wcstombs_s, _wcstombs_s_l](../c-runtime-library/reference/wcstombs-s-wcstombs-s-l.md)|Converter sequência de caracteres largos na sequência de caracteres multibyte correspondente|`LC_CTYPE`|  
|[wctomb, _wctomb_l](../c-runtime-library/reference/wctomb-wctomb-l.md),[wctomb_s, _wctomb_s_l](../c-runtime-library/reference/wctomb-s-wctomb-s-l.md)|Converter um caractere largo em um caractere multibyte correspondente|`LC_CTYPE`|  
  
> [!NOTE]
>  Para rotinas multibyte, a página de código multibyte deve ser equivalente à localidade definida com [setlocale](../c-runtime-library/reference/setlocale-wsetlocale.md). [_setmbcp](../c-runtime-library/reference/setmbcp.md), com um argumento `_MB_CP_LOCALE` faz com que a página de código multibyte fique igual à página de código `setlocale`.  
  
## <a name="see-also"></a>Consulte também  
 [Internacionalização](../c-runtime-library/internationalization.md)   
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)