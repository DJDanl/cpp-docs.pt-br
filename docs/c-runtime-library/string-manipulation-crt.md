---
title: "Manipulação de cadeias de caracteres (CRT) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- c.strings
dev_langs:
- C++
helpviewer_keywords:
- strings [C++], manipulating
- string manipulation
- manipulating strings
ms.assetid: 6545861a-59e7-408d-9d29-2ec9134fc91a
caps.latest.revision: 11
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
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: f64ca286194a1a3675210e386a9afea3b149851f
ms.lasthandoff: 02/25/2017

---
# <a name="string-manipulation-crt"></a>Manipulação da cadeia de caracteres (CRT)
Essas rotinas operam em sequências de caracteres de byte único terminadas em nulo, de caracteres largos e de caracteres multibyte. Use as rotinas de manipulação de buffer, descritas em [manipulação de Buffer](../c-runtime-library/buffer-manipulation.md), para trabalhar com matrizes de caracteres que não terminam com um caractere nulo.  
  
### <a name="string-manipulation-routines"></a>Rotinas de Manipulação de Cadeia de Caracteres  
  
|Rotina|Uso|Equivalente ao .NET Framework|  
|-------------|---------|-------------------------------|  
|[strcoll, wcscoll, _mbscoll, _strcoll_l, _wcscoll_l, _mbscoll_l](../c-runtime-library/reference/strcoll-wcscoll-mbscoll-strcoll-l-wcscoll-l-mbscoll-l.md), [_stricoll, _wcsicoll, _mbsicoll, _stricoll_l, _wcsicoll_l, _mbsicoll_l](../c-runtime-library/reference/stricoll-wcsicoll-mbsicoll-stricoll-l-wcsicoll-l-mbsicoll-l.md), [_strncoll, _wcsncoll, _mbsncoll, _strncoll_l, _wcsncoll_l, _mbsncoll_l](../c-runtime-library/reference/strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md), [_strnicoll, _wcsnicoll, _mbsnicoll, _strnicoll_l, _wcsnicoll_l, _mbsnicoll_l](../c-runtime-library/reference/strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|Comparar duas sequências de caracteres usando informações de página de código (`_mbsicoll` e `_mbsnicoll` diferenciam maiúsculas de minúsculas)|[System::String::Compare](https://msdn.microsoft.com/en-us/library/system.string.compare.aspx)|  
|[_strdec, _wcsdec, _mbsdec, _mbsdec_l](../c-runtime-library/reference/strdec-wcsdec-mbsdec-mbsdec-l.md)|Mover um ponteiro de cadeia de caracteres um caractere para trás|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).|  
|[_strinc, _wcsinc, _mbsinc, _mbsinc_l](../c-runtime-library/reference/strinc-wcsinc-mbsinc-mbsinc-l.md)|Avançar um ponteiro de cadeia de caracteres em um caractere|Não aplicável.|  
|[_mbsnbcat, _mbsnbcat_l](../c-runtime-library/reference/mbsnbcat-mbsnbcat-l.md), [_mbsnbcat_s, _mbsnbcat_s_l](../c-runtime-library/reference/mbsnbcat-s-mbsnbcat-s-l.md)|Acrescentar, no máximo, os primeiros `n` bytes de uma sequência de caracteres para outra|Não aplicável.|  
|[_mbsnbcmp, _mbsnbcmp_l](../c-runtime-library/reference/mbsnbcmp-mbsnbcmp-l.md)|Comparar os primeiros `n` bytes de duas sequências de caracteres|Não aplicável.|  
|[_strncnt, _wcsncnt, _mbsnbcnt, _mbsnbcnt_l, _mbsnccnt, _mbsnccnt_l](../c-runtime-library/reference/strncnt-wcsncnt-mbsnbcnt-mbsnbcnt-l-mbsnccnt-mbsnccnt-l.md)|Retornar o número de bytes de caracteres dentro da contagem de caracteres fornecida|Não aplicável.|  
|[_mbsnbcpy, _mbsnbcpy_l](../c-runtime-library/reference/mbsnbcpy-mbsnbcpy-l.md), [_mbsnbcpy_s, _mbsnbcpy_s_l](../c-runtime-library/reference/mbsnbcpy-s-mbsnbcpy-s-l.md)|Copiar `n` bytes da cadeia de caracteres|Não aplicável.|  
|[_mbsnbicmp, _mbsnbicmp_l](../c-runtime-library/reference/mbsnbicmp-mbsnbicmp-l.md)|Comparar `n` bytes de duas sequências de caracteres, ignorando maiúsculas e minúsculas|Não aplicável.|  
|[_mbsnbset, _mbsnbset_l](../c-runtime-library/reference/mbsnbset-mbsnbset-l.md)|Definir os `n` primeiros bytes de cadeia de caracteres como caracteres especificados|Não aplicável.|  
|[_strncnt, _wcsncnt, _mbsnbcnt, _mbsnbcnt_l, _mbsnccnt, _mbsnccnt_l](../c-runtime-library/reference/strncnt-wcsncnt-mbsnbcnt-mbsnbcnt-l-mbsnccnt-mbsnccnt-l.md)|Retornar o número de caracteres dentro de contagem de bytes fornecida|Não aplicável.|  
|[_strnextc, _wcsnextc, _mbsnextc, _mbsnextc_l](../c-runtime-library/reference/strnextc-wcsnextc-mbsnextc-mbsnextc-l.md)|Localizar o próximo caractere na cadeia de caracteres|Não aplicável.|  
|[_strninc, _wcsninc, _mbsninc, _mbsninc_l](../c-runtime-library/reference/strninc-wcsninc-mbsninc-mbsninc-l.md)|Avançar um ponteiro de cadeia de caracteres em `n` caracteres|Não aplicável.|  
|[_strspnp, _wcsspnp, _mbsspnp, _mbsspnp_l](../c-runtime-library/reference/strspnp-wcsspnp-mbsspnp-mbsspnp-l.md)|Retornar ponteiro para o primeiro caractere em uma determinada cadeia de caracteres que não está em outra cadeia de caracteres|Não aplicável.|  
|[_scprintf, _scprintf_l, _scwprintf, _scwprintf_l](../c-runtime-library/reference/scprintf-scprintf-l-scwprintf-scwprintf-l.md)|Retornar o número de caracteres em uma cadeia de caracteres formatada|Não aplicável.|  
|[_snscanf, _snscanf_l, _snwscanf, _snwscanf_l](../c-runtime-library/reference/snscanf-snscanf-l-snwscanf-snwscanf-l.md), [_snscanf_s, _snscanf_s_l, _snwscanf_s, _snwscanf_s_l](../c-runtime-library/reference/snscanf-s-snscanf-s-l-snwscanf-s-snwscanf-s-l.md)|Leia os dados formatados de um comprimento especificado do fluxo de entrada padrão.|Não aplicável.|  
|[sscanf, _sscanf_l, swscanf, _swscanf_l](../c-runtime-library/reference/sscanf-sscanf-l-swscanf-swscanf-l.md), [sscanf_s, _sscanf_s_l, swscanf_s, _swscanf_s_l](../c-runtime-library/reference/sscanf-s-sscanf-s-l-swscanf-s-swscanf-s-l.md)|Leia os dados formatados de um comprimento especificado do fluxo de entrada padrão.|Não aplicável.|  
|[sprintf, _sprintf_l, swprintf, _swprintf_l, \__swprintf_l](../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md), [sprintf_s, _sprintf_s_l, swprintf_s, _swprintf_s_l](../c-runtime-library/reference/sprintf-s-sprintf-s-l-swprintf-s-swprintf-s-l.md), [_sprintf_p, _sprintf_p_l, _swprintf_p, _swprintf_p_l](../c-runtime-library/reference/sprintf-p-sprintf-p-l-swprintf-p-swprintf-p-l.md)|Gravar os dados formatados em uma cadeia de caracteres|[System::String::Format](https://msdn.microsoft.com/en-us/library/system.string.format.aspx)|  
|[strcat, wcscat, _mbscat](../c-runtime-library/reference/strcat-wcscat-mbscat.md), [strcat_s, wcscat_s, _mbscat_s](../c-runtime-library/reference/strcat-s-wcscat-s-mbscat-s.md)|Acrescentar uma cadeia de caracteres a outra|[System::String::Concat](https://msdn.microsoft.com/en-us/library/system.string.concat.aspx)|  
|[strchr, wcschr, _mbschr, _mbschr_l](../c-runtime-library/reference/strchr-wcschr-mbschr-mbschr-l.md)|Localizar a primeira ocorrência do caractere especificado na cadeia de caracteres|[System::String::IndexOf](https://msdn.microsoft.com/en-us/library/system.string.indexof.aspx)|  
|[strcmp, wcscmp, _mbscmp](../c-runtime-library/reference/strcmp-wcscmp-mbscmp.md)|Comparar duas cadeias de caracteres|[System::String::CompareOrdinal](https://msdn.microsoft.com/en-us/library/system.string.compareordinal.aspx)|  
|[strcoll, wcscoll, _mbscoll, _strcoll_l, _wcscoll_l, _mbscoll_l](../c-runtime-library/reference/strcoll-wcscoll-mbscoll-strcoll-l-wcscoll-l-mbscoll-l.md), [_stricoll, _wcsicoll, _mbsicoll, _stricoll_l, _wcsicoll_l, _mbsicoll_l](../c-runtime-library/reference/stricoll-wcsicoll-mbsicoll-stricoll-l-wcsicoll-l-mbsicoll-l.md), [_strncoll, _wcsncoll, _mbsncoll, _strncoll_l, _wcsncoll_l, _mbsncoll_l](../c-runtime-library/reference/strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md), [_strnicoll, _wcsnicoll, _mbsnicoll, _strnicoll_l, _wcsnicoll_l, _mbsnicoll_l](../c-runtime-library/reference/strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|Comparar duas cadeias de caracteres usando informações de página de código de localidade atual (`_stricoll`, `_wcsicoll`, `_strnicoll`, e `_wcsnicoll` diferenciam maiúsculas de minúsculas)|[System::String::Compare](https://msdn.microsoft.com/en-us/library/system.string.compare.aspx)|  
|[strcpy, wcscpy, _mbscpy](../c-runtime-library/reference/strcpy-wcscpy-mbscpy.md), [strcpy_s, wcscpy_s, _mbscpy_s](../c-runtime-library/reference/strcpy-s-wcscpy-s-mbscpy-s.md)|Copiar uma cadeia de caracteres para outra|[System::String::Copy](https://msdn.microsoft.com/en-us/library/system.string.copy.aspx)|  
|[strcspn, wcscspn, _mbscspn, _mbscspn_l](../c-runtime-library/reference/strcspn-wcscspn-mbscspn-mbscspn-l.md)|Localizar a primeira ocorrência do caractere do conjunto de caracteres especificado na cadeia de caracteres|[System::String::IndexOfAny](https://msdn.microsoft.com/en-us/library/system.string.indexofany.aspx)|  
|[_strdup, _wcsdup, _mbsdup](../c-runtime-library/reference/strdup-wcsdup-mbsdup.md), [_strdup_dbg, _wcsdup_dbg](../c-runtime-library/reference/strdup-dbg-wcsdup-dbg.md)|Cadeias de caracteres duplicadas|[System::String::Clone](https://msdn.microsoft.com/en-us/library/system.string.clone.aspx)|  
|[strerror, _strerror, _wcserror, \__wcserror](../c-runtime-library/reference/strerror-strerror-wcserror-wcserror.md), [strerror_s, _strerror_s, _wcserror_s, \__wcserror_s](../c-runtime-library/reference/strerror-s-strerror-s-wcserror-s-wcserror-s.md)|Mapear número de erro para cadeia de caracteres de mensagem|[System::Exception::Message](https://msdn.microsoft.com/en-us/library/system.exception.message.aspx)|  
|[strftime, wcsftime, _strftime_l, _wcsftime_l](../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md)|Formatar cadeia de caracteres de data e hora|[System::Convert::ToString](https://msdn.microsoft.com/en-us/library/system.convert.tostring.aspx)|  
|[_stricmp, _wcsicmp, _mbsicmp, _stricmp_l, _wcsicmp_l, _mbsicmp_l](../c-runtime-library/reference/stricmp-wcsicmp-mbsicmp-stricmp-l-wcsicmp-l-mbsicmp-l.md)|Comparar duas cadeias de caracteres sem considerar as maiúsculas e minúsculas|[System::String::Compare](https://msdn.microsoft.com/en-us/library/system.string.compare.aspx)|  
|[strlen, wcslen, _mbslen, _mbslen_l, _mbstrlen, _mbstrlen_l](../c-runtime-library/reference/strlen-wcslen-mbslen-mbslen-l-mbstrlen-mbstrlen-l.md), [strnlen, strnlen_s, wcsnlen, wcsnlen_s, _mbsnlen, _mbsnlen_l, _mbstrnlen, _mbstrnlen_l](../c-runtime-library/reference/strnlen-strnlen-s.md)|Encontrar comprimento de cadeia de caracteres|[System::String::Length](https://msdn.microsoft.com/en-us/library/system.string.length.aspx)|  
|[_strlwr, _wcslwr, _mbslwr, _strlwr_l, _wcslwr_l, _mbslwr_l](../c-runtime-library/reference/strlwr-wcslwr-mbslwr-strlwr-l-wcslwr-l-mbslwr-l.md), [_strlwr_s, _strlwr_s_l, _mbslwr_s, _mbslwr_s_l, _wcslwr_s, _wcslwr_s_l](../c-runtime-library/reference/strlwr-s-strlwr-s-l-mbslwr-s-mbslwr-s-l-wcslwr-s-wcslwr-s-l.md)|Converter uma cadeia de caracteres em minúsculas|[System::String::ToLower](https://msdn.microsoft.com/en-us/library/system.string.tolower.aspx)|  
|[strncat, _strncat_l, wcsncat, _wcsncat_l, _mbsncat, _mbsncat_l](../c-runtime-library/reference/strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md), [strncat_s, _strncat_s_l, wcsncat_s, _wcsncat_s_l, _mbsncat_s, _mbsncat_s_l](../c-runtime-library/reference/strncat-s-strncat-s-l-wcsncat-s-wcsncat-s-l-mbsncat-s-mbsncat-s-l.md)|Acrescentar caracteres da cadeia de caracteres|[System::String::Concat](https://msdn.microsoft.com/en-us/library/system.string.concat.aspx)|  
|[strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)|Comparar caracteres de duas cadeias de caracteres|[System::String::Compare](https://msdn.microsoft.com/en-us/library/system.string.compare.aspx)|  
|[strncpy, _strncpy_l, wcsncpy, _wcsncpy_l, _mbsncpy, _mbsncpy_l](../c-runtime-library/reference/strncpy-strncpy-l-wcsncpy-wcsncpy-l-mbsncpy-mbsncpy-l.md), [strncpy_s, _strncpy_s_l, wcsncpy_s, _wcsncpy_s_l, _mbsncpy_s, _mbsncpy_s_l](../c-runtime-library/reference/strncpy-s-strncpy-s-l-wcsncpy-s-wcsncpy-s-l-mbsncpy-s-mbsncpy-s-l.md)|Copiar caracteres de uma cadeia de caracteres para outra|[System::String::Copy](https://msdn.microsoft.com/en-us/library/system.string.copy.aspx)|  
|[_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l](../c-runtime-library/reference/strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)|Comparar caracteres de duas cadeias de caracteres sem considerar maiúsculas e minúsculas|[System::String::Compare](https://msdn.microsoft.com/en-us/library/system.string.compare.aspx)|  
|[_strnset, _strnset_l, _wcsnset, _wcsnset_l, _mbsnset, _mbsnset_l](../c-runtime-library/reference/strnset-strnset-l-wcsnset-wcsnset-l-mbsnset-mbsnset-l.md)|Definir os `n` primeiros caracteres da sequência de caracteres especificada|[System::String::Replace](https://msdn.microsoft.com/en-us/library/system.string.replace.aspx)|  
|[strpbrk, wcspbrk, _mbspbrk, _mbspbrk_l](../c-runtime-library/reference/strpbrk-wcspbrk-mbspbrk-mbspbrk-l.md)|Localizar a primeira ocorrência do caractere de uma cadeia de caracteres em outra cadeia de caracteres|[System::String::IndexOfAny](https://msdn.microsoft.com/en-us/library/system.string.indexofany.aspx)|  
|[strrchr, wcsrchr, _mbsrchr, _mbsrchr_l](../c-runtime-library/reference/strrchr-wcsrchr-mbsrchr-mbsrchr-l.md)|Localizar a última ocorrência de um determinado caractere na cadeia de caracteres|[System::String::LastIndexOf](https://msdn.microsoft.com/en-us/library/system.string.lastindexof.aspx)|  
|[_strrev, _wcsrev, _mbsrev, _mbsrev_l](../c-runtime-library/reference/strrev-wcsrev-mbsrev-mbsrev-l.md)|Inverter cadeia de caracteres|Não aplicável.|  
|[_strset, _strset_l, _wcsset, _wcsset_l, _mbsset, _mbsset_l](../c-runtime-library/reference/strset-strset-l-wcsset-wcsset-l-mbsset-mbsset-l.md)|Definir todos os caracteres de cadeia de caracteres como o caractere especificado|Não aplicável.|  
|[strspn, wcsspn, _mbsspn, _mbsspn_l](../c-runtime-library/reference/strspn-wcsspn-mbsspn-mbsspn-l.md)|Localizar a primeira ocorrência em uma cadeia de caracteres de um caractere não encontrado em outra cadeia de caracteres|Não aplicável.|  
|[strstr, wcsstr, _mbsstr, _mbsstr_l](../c-runtime-library/reference/strstr-wcsstr-mbsstr-mbsstr-l.md)|Localizar a primeira ocorrência da cadeia de caracteres especificada em outra cadeia de caracteres|[System::String::IndexOf](https://msdn.microsoft.com/en-us/library/system.string.indexof.aspx)|  
|[strtok, _strtok_l, wcstok, _wcstok_l, _mbstok, _mbstok_l](../c-runtime-library/reference/strtok-strtok-l-wcstok-wcstok-l-mbstok-mbstok-l.md), [strtok_s, _strtok_s_l, wcstok_s, _wcstok_s_l, _mbstok_s, _mbstok_s_l](../c-runtime-library/reference/strtok-s-strtok-s-l-wcstok-s-wcstok-s-l-mbstok-s-mbstok-s-l.md)|Localizar próximo token na cadeia de caracteres|Não aplicável.|  
|[_strupr, _strupr_l, _mbsupr, _mbsupr_l, _wcsupr_l, _wcsupr](../c-runtime-library/reference/strupr-strupr-l-mbsupr-mbsupr-l-wcsupr-l-wcsupr.md), [_strupr_s, _strupr_s_l, _mbsupr_s, _mbsupr_s_l, _wcsupr_s, _wcsupr_s_l](../c-runtime-library/reference/strupr-s-strupr-s-l-mbsupr-s-mbsupr-s-l-wcsupr-s-wcsupr-s-l.md)|Converter cadeia de caracteres em maiúsculas|[System::String::ToUpper](https://msdn.microsoft.com/en-us/library/system.string.toupper.aspx)|  
|[strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l](../c-runtime-library/reference/strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)|Transformar cadeia de caracteres em forma agrupada com base em informações específicas da localidade|Não aplicável.|  
|[vsprintf, _vsprintf_l, vswprintf, _vswprintf_l, \__vswprintf_l](../c-runtime-library/reference/vsprintf-vsprintf-l-vswprintf-vswprintf-l-vswprintf-l.md), [vsprintf_s, _vsprintf_s_l, vswprintf_s, _vswprintf_s_l](../c-runtime-library/reference/vsprintf-s-vsprintf-s-l-vswprintf-s-vswprintf-s-l.md), [_vsprintf_p, _vsprintf_p_l, _vswprintf_p, _vswprintf_p_l](../c-runtime-library/reference/vsprintf-p-vsprintf-p-l-vswprintf-p-vswprintf-p-l.md)|Gravar saída formatada usando um ponteiro para uma lista de argumentos|[System::String::Format](https://msdn.microsoft.com/en-us/library/system.string.format.aspx)|  
|[vsnprintf, _vsnprintf, _vsnprintf_l, _vsnwprintf, _vsnwprintf_l](../c-runtime-library/reference/vsnprintf-vsnprintf-vsnprintf-l-vsnwprintf-vsnwprintf-l.md), [vsnprintf_s, _vsnprintf_s, _vsnprintf_s_l, _vsnwprintf_s, _vsnwprintf_s_l](../c-runtime-library/reference/vsnprintf-s-vsnprintf-s-vsnprintf-s-l-vsnwprintf-s-vsnwprintf-s-l.md)|Gravar saída formatada usando um ponteiro para uma lista de argumentos|[System::String::Format](https://msdn.microsoft.com/en-us/library/system.string.format.aspx)|  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)
