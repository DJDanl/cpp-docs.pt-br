---
title: "Localidade | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "c.international"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "informações de país"
  - "rotinas de informação de idioma"
  - "rotinas de localidade"
  - "localização, localidade"
  - "setlocale - função"
ms.assetid: 442f8112-9288-44d7-be3c-15d22652093a
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Localidade
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

*A localidade* refere\-se às configurações de país\/região e de idioma que você pode usar para personalizar seu programa.  Algumas categorias de localidade dependentes incluem os formatos de exibição para datas e valores monetários.  Para obter mais informações, consulte [Categorias de localidade](../c-runtime-library/locale-categories.md).  
  
 Use a função de [setlocale](../Topic/setlocale,%20_wsetlocale.md) para alterar ou consultar qualquer ou qualquer programa atual ou para threading informações de localidade quando usar funcionar sem o sufixo de `_l` .  As funções com o sufixo de `_l` usarão o parâmetro de localidade transmitido para suas informações de localidade durante a execução dessa função específica somente.  Para criar uma localidade para uso com uma função com um sufixo de `_l` , use [\_create\_locale](../c-runtime-library/reference/create-locale-wcreate-locale.md).  Para liberar essa localidade, use [\_free\_locale](../c-runtime-library/reference/free-locale.md).  Para obter a localidade atual, use [\_get\_current\_locale](../Topic/_get_current_locale.md).  
  
 Use [\_configthreadlocale](../c-runtime-library/reference/configthreadlocale.md) para controlar se cada thread tem sua própria localidade, ou todos os threads em um programa compartilham a mesma localidade.  Para obter mais informações, consulte [Localidades e páginas de código](../text/locales-and-code-pages.md).  
  
 Versões mais seguras de funções na tabela a seguir estão disponíveis, indicado pelo sufixo de `_s` proteger \(“”\).  Para obter mais informações, consulte [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
### Rotinas de localidade dependente  
  
|Rotina|Uso|dependência de configuração da categoria de`setlocale`|  
|------------|---------|------------------------------------------------------------|  
|[atof, \_atof\_l, \_wtof, \_wtof\_l](../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)|Caractere de conversão ao valor de ponto flutuante|`LC_NUMERIC`|  
|[atoi, \_atoi\_l, \_wtoi, \_wtoi\_l](../c-runtime-library/reference/atoi-atoi-l-wtoi-wtoi-l.md)|Caractere de conversão para o valor inteiro|`LC_NUMERIC`|  
|[\_atoi64, \_atoi64\_l, \_wtoi64, \_wtoi64\_l](../c-runtime-library/reference/atoi64-atoi64-l-wtoi64-wtoi64-l.md)|Caractere de conversão para o valor inteiro de 64 bits|`LC_NUMERIC`|  
|[atol, \_atol\_l, \_wtol, \_wtol\_l](../c-runtime-library/reference/atol-atol-l-wtol-wtol-l.md)|Caractere de conversão a ser avaliada por muito tempo|`LC_NUMERIC`|  
|[atodbl, atodbl\_l, atoldbl, atoldbl\_l, atoflt, atoflt\_l](../c-runtime-library/reference/atodbl-atodbl-l-atoldbl-atoldbl-l-atoflt-atoflt-l.md)|Valor duplo longo de caracteres de conversão|`LC_NUMERIC`|  
|[são rotinas](../c-runtime-library/is-isw-routines.md)|Inteiro pode testar a condição específica.|`LC_CTYPE`|  
|[isleadbyte, \_isleadbyte\_l](../c-runtime-library/reference/isleadbyte-isleadbyte-l.md)|Teste do byte inicial|`LC_CTYPE`|  
|[localeconv](../c-runtime-library/reference/localeconv.md)|Valores apropriados de leitura para formatar quantidades numéricas|`LC_MONETARY, LC_NUMERIC`|  
|[MB\_CUR\_MAX](../c-runtime-library/mb-cur-max.md)|Comprimento máximo em bytes de alguns caracteres multibyte na localidade atual \(macro definido em STDLIB.H\)|`LC_CTYPE`|  
|[\_mbccpy, \_mbccpy\_l](../Topic/_mbccpy,%20_mbccpy_l.md),[\_mbccpy\_s, \_mbccpy\_s\_l](../c-runtime-library/reference/mbccpy-s-mbccpy-s-l.md)|Caracteres multibyte de uma cópia|`LC_CTYPE`|  
|[\_mbclen, mblen, \_mblen\_l](../c-runtime-library/reference/mbclen-mblen-mblen-l.md)|Validar e retornar o número de bytes em caracteres multibyte|`LC_CTYPE`|  
|[strlen, wcslen, \_mbslen, \_mbslen\_l, \_mbstrlen, \_mbstrlen\_l](../Topic/strlen,%20wcslen,%20_mbslen,%20_mbslen_l,%20_mbstrlen,%20_mbstrlen_l.md)|Para cadeias de caracteres de multibyte\- caractere: validar cada caractere na cadeia de caracteres; retorna o comprimento da cadeia de caracteres|`LC_CTYPE`|  
|[mbstowcs, \_mbstowcs\_l](../c-runtime-library/reference/mbstowcs-mbstowcs-l.md),[mbstowcs\_s, \_mbstowcs\_s\_l](../c-runtime-library/reference/mbstowcs-s-mbstowcs-s-l.md)|Converter a sequência de caracteres multibyte correspondente à sequência de caracteres amplos|`LC_CTYPE`|  
|[mbtowc, \_mbtowc\_l](../Topic/mbtowc,%20_mbtowc_l.md)|O converter caracteres multibyte ao caractere largo correspondente|`LC_CTYPE`|  
|funções de[printf](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)|A saída formatada de gravação|`LC_NUMERIC` \(determina saída de caracteres raiz\)|  
|funções de[scanf](../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md)|Entrada formatado de leitura|`LC_NUMERIC` \(determina o reconhecimento de caracteres raiz\)|  
|[setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md)|Localidade de seleção para o programa|Não aplicável|  
|[strcoll, wcscoll, \_mbscoll, \_strcoll\_l, \_wcscoll\_l, \_mbscoll\_l](../c-runtime-library/reference/strcoll-wcscoll-mbscoll-strcoll-l-wcscoll-l-mbscoll-l.md)|Compare caracteres de duas cadeias de caracteres|`LC_COLLATE`|  
|[\_stricmp, \_wcsicmp, \_mbsicmp, \_stricmp\_l, \_wcsicmp\_l, \_mbsicmp\_l](../c-runtime-library/reference/stricmp-wcsicmp-mbsicmp-stricmp-l-wcsicmp-l-mbsicmp-l.md)|Compara duas cadeias de caracteres sem considerar o caso|`LC_CTYPE`|  
|[\_stricoll, \_wcsicoll, \_mbsicoll, \_stricoll\_l, \_wcsicoll\_l, \_mbsicoll\_l](../Topic/_stricoll,%20_wcsicoll,%20_mbsicoll,%20_stricoll_l,%20_wcsicoll_l,%20_mbsicoll_l.md)|Compare caracteres de duas cadeias de caracteres \(sem diferenciação de maiúsculas e minúsculas\)|`LC_COLLATE`|  
|[\_strncoll, \_wcsncoll, \_mbsncoll, \_strncoll\_l, \_wcsncoll\_l, \_mbsncoll\_l](../c-runtime-library/reference/strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md)|Compare primeiros caracteres de `n` de duas cadeias de caracteres|`LC_COLLATE`|  
|[\_strnicmp, \_wcsnicmp, \_mbsnicmp, \_strnicmp\_l, \_wcsnicmp\_l, \_mbsnicmp\_l](../c-runtime-library/reference/strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)|Compare caracteres de duas cadeias de caracteres sem considerar o caso.|`LC_CTYPE`|  
|[\_strnicoll, \_wcsnicoll, \_mbsnicoll, \_strnicoll\_l, \_wcsnicoll\_l, \_mbsnicoll\_l](../c-runtime-library/reference/strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|Compare primeiros caracteres de `n` de duas cadeias de caracteres \(sem diferenciação de maiúsculas e minúsculas\)|`LC_COLLATE`|  
|[strftime, wcsftime, \_strftime\_l, \_wcsftime\_l](../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md)|Formatar a data e o valor do tempo de acordo com o argumento fornecido de `format`|`LC_TIME`|  
|[\_strlwr, \_wcslwr, \_mbslwr, \_strlwr\_l, \_wcslwr\_l, \_mbslwr\_l](../Topic/_strlwr,%20_wcslwr,%20_mbslwr,%20_strlwr_l,%20_wcslwr_l,%20_mbslwr_l.md),[\_strlwr\_s, \_strlwr\_s\_l, \_mbslwr\_s, \_mbslwr\_s\_l, \_wcslwr\_s, \_wcslwr\_s\_l](../c-runtime-library/reference/strlwr-s-strlwr-s-l-mbslwr-s-mbslwr-s-l-wcslwr-s-wcslwr-s-l.md)|Converter, em vez, cada letra maiúscula na cadeia de caracteres fornecida a minúsculas|`LC_CTYPE`|  
|[strtod, \_strtod\_l, wcstod, \_wcstod\_l](../c-runtime-library/reference/strtod-strtod-l-wcstod-wcstod-l.md)|Converter a cadeia de caracteres ao valor de `double`|`LC_NUMERIC` \(determina o reconhecimento de caracteres raiz\)|  
|[strtol, wcstol, \_strtol\_l, \_wcstol\_l](../c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l.md)|Converter a cadeia de caracteres ao valorde `long`|`LC_NUMERIC` \(determina o reconhecimento de caracteres raiz\)|  
|[strtoul, \_strtoul\_l, wcstoul, \_wcstoul\_l](../c-runtime-library/reference/strtoul-strtoul-l-wcstoul-wcstoul-l.md)|Converter a cadeia de caracteres ao valor longo não assinados|`LC_NUMERIC` \(determina o reconhecimento de caracteres raiz\)|  
|[\_strupr, \_strupr\_l, \_mbsupr, \_mbsupr\_l, \_wcsupr\_l, \_wcsupr](../c-runtime-library/reference/strupr-strupr-l-mbsupr-mbsupr-l-wcsupr-l-wcsupr.md),[\_strupr\_s, \_strupr\_s\_l, \_mbsupr\_s, \_mbsupr\_s\_l, \_wcsupr\_s, \_wcsupr\_s\_l](../c-runtime-library/reference/strupr-s-strupr-s-l-mbsupr-s-mbsupr-s-l-wcsupr-s-wcsupr-s-l.md)|Converter, em vez, cada letra minúscula na cadeia de caracteres para letras maiúsculas|`LC_CTYPE`|  
|[strxfrm, wcsxfrm, \_strxfrm\_l, \_wcsxfrm\_l](../c-runtime-library/reference/strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)|Transformar a cadeia de caracteres no formato ordenado de acordo com a localidade|`LC_COLLATE`|  
|[tolower, \_tolower, towlower, \_tolower\_l, \_towlower\_l](../Topic/tolower,%20_tolower,%20towlower,%20_tolower_l,%20_towlower_l.md),[\_mbctolower, \_mbctolower\_l, \_mbctoupper, \_mbctoupper\_l](../c-runtime-library/reference/mbctolower-mbctolower-l-mbctoupper-mbctoupper-l.md)|Converter o caractere dado ao caractere minúsculo correspondente|`LC_CTYPE`|  
|[toupper, \_toupper, towupper, \_toupper\_l, \_towupper\_l](../Topic/toupper,%20_toupper,%20towupper,%20_toupper_l,%20_towupper_l.md),[\_mbctolower, \_mbctolower\_l, \_mbctoupper, \_mbctoupper\_l](../c-runtime-library/reference/mbctolower-mbctolower-l-mbctoupper-mbctoupper-l.md)|Converter o caractere dado à letra maiúscula correspondente|`LC_CTYPE`|  
|[wcstombs, \_wcstombs\_l](../Topic/wcstombs,%20_wcstombs_l.md),[wcstombs\_s, \_wcstombs\_s\_l](../Topic/wcstombs_s,%20_wcstombs_s_l.md)|Converter a sequência de caracteres amplos correspondente à sequência de caracteres multibyte|`LC_CTYPE`|  
|[wctomb, \_wctomb\_l](../c-runtime-library/reference/wctomb-wctomb-l.md),[wctomb\_s, \_wctomb\_s\_l](../c-runtime-library/reference/wctomb-s-wctomb-s-l.md)|Converter o caractere largo correspondente em caracteres multibyte|`LC_CTYPE`|  
  
> [!NOTE]
>  Para rotinas de multibyte, a página de código de multibyte deve equivaler à localidade definida com [setlocale](../Topic/setlocale,%20_wsetlocale.md).  [\_setmbcp](../c-runtime-library/reference/setmbcp.md), com um argumento de `_MB_CP_LOCALE` faz a página de código multibyte da mesma forma que a página de código de `setlocale` .  
  
## Consulte também  
 [Internacionalização](../c-runtime-library/internationalization.md)   
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)