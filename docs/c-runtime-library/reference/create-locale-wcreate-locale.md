---
title: "_create_locale, _wcreate_locale | Microsoft Docs"
ms.custom: ""
ms.date: "11/04/2016"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_create_locale"
  - "__create_locale"
  - "_wcreate_locale"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-locale-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "create_locale"
  - "_create_locale"
  - "__create_locale"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "locales, creating"
  - "_create_locale function"
  - "create_locale function"
  - "__create_locale function"
ms.assetid: ca362464-9f4a-4ec6-ab03-316c55c5be81
caps.latest.revision: 23
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
translation.priority.ht: 
  - "cs-cz"
  - "de-de"
  - "es-es"
  - "fr-fr"
  - "it-it"
  - "ja-jp"
  - "ko-kr"
  - "pl-pl"
  - "pt-br"
  - "ru-ru"
  - "tr-tr"
  - "zh-cn"
  - "zh-tw"
---
# <a name="createlocale-wcreatelocale"></a>_create_locale, _wcreate_locale
Cria um objeto de localidade.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
_locale_t _create_locale(  
   int category,  
   const char *locale   
);  
_locale_t _wcreate_locale(  
   int category,  
   const wchar_t *locale   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `category`  
 Categoria.  
  
 `locale`  
 Especificador de localidade.  
  
## <a name="return-value"></a>Valor de retorno  
 Se um `locale` e `category` válidos forem fornecidos, retornará as configurações de localidade especificadas como um objeto `_locale_t`. As configurações de localidade atual do programa não são alteradas.  
  
## <a name="remarks"></a>Comentários  
 A função `_create_locale` permite criar um objeto que representa algumas configurações específicas à região, para uso em versões específicas à localidade de várias funções CRT (funciona com o sufixo `_l`). O comportamento é semelhante a `setlocale`, com exceção de que, em vez de aplicar as configurações de localidade especificadas ao ambiente atual, as configurações são salvas em uma estrutura `_locale_t` que é retornada. A estrutura `_locale_t` deve ser liberada usando [_free_locale](../../c-runtime-library/reference/free-locale.md) quando não for mais necessária.  
  
 A função `_wcreate_locale` é uma versão de caractere largo da função `_create_locale`; o argumento `locale` para `_wcreate_locale` é uma cadeia de caracteres larga. Caso contrário, `_wcreate_locale` e `_create_locale` se comportam de forma idêntica.  
  
 O argumento `category` especifica as partes do comportamento específico à localidade que são afetadas. Os sinalizadores usados para `category` e as partes do programa que eles afetam são mostrados na tabela a seguir.  
  
 `LC_ALL`  
 Todas as categorias, conforme listado abaixo.  
  
 `LC_COLLATE`  
 As funções `strcoll`, `_stricoll`, `wcscoll`, `_wcsicoll`, `strxfrm`, `_strncoll`, `_strnicoll`, `_wcsncoll`, `_wcsnicoll` e `wcsxfrm`.  
  
 `LC_CTYPE`  
 As funções de manipulação de caracteres (exceto `isdigit`, `isxdigit`, `mbstowcs` e `mbtowc`, que não são afetadas).  
  
 `LC_MONETARY`  
 Informações de formatação monetária retornadas pela função `localeconv`.  
  
 `LC_NUMERIC`  
 Caractere de ponto decimal para rotinas de saída formatadas (como `printf`), para rotinas de conversão de dados, e para informações não monetárias de formatação retornadas por `localeconv`. Além do caractere de ponto decimal, `LC_NUMERIC` define o separador de milhares e a cadeia de caracteres de controle de agrupamento retornada por [localeconv](../../c-runtime-library/reference/localeconv.md).  
  
 `LC_TIME`  
 As funções `strftime` e `wcsftime`.  
  
 Essa função valida os parâmetros `category` e `locale`. Se o parâmetro de categoria não for um dos valores fornecidos na tabela anterior ou se `locale` for `NULL`, a função retornará `NULL`.  
  
 O argumento `locale` é um ponteiro para uma cadeia de caracteres que especifica a localidade. Para obter informações sobre o formato do argumento `locale`, consulte [Nomes de localidades, idiomas e cadeias de caracteres de país/região](../../c-runtime-library/locale-names-languages-and-country-region-strings.md).  
  
 O argumento `locale` pode ter um nome de localidade, uma cadeia de caracteres de idioma, uma cadeia de caracteres de idioma e código de país/região, uma página de código ou uma cadeia de caracteres de idioma, código de país/região e página de código. O conjunto de nomes de localidade, idiomas, códigos de país/região e páginas de código disponíveis inclui tudo o que tem suporte na API NLS do Windows, com exceção das páginas de código que exigem mais de dois bytes por caractere – por exemplo, UTF-7 e UTF-8. Se você fornecer uma página de código como UTF-7 ou UTF-8, `_create_locale` falhará e retornará NULL. O conjunto de nomes de localidades com suporte no `_create_locale` é descrito em [Nomes de localidades, idiomas e cadeias de caracteres de país/região](../../c-runtime-library/locale-names-languages-and-country-region-strings.md). O conjunto de idiomas e cadeias de caracteres de país/região com suporte no `_create_locale` é listado em [Cadeias de caracteres de idiomas](../../c-runtime-library/language-strings.md) e [Cadeias de caracteres de país/região](../../c-runtime-library/country-region-strings.md).  
  
 Para obter mais informações sobre as configurações de localidade, consulte [setlocale, _wsetlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md).  
  
 O nome anterior dessa função, `__create_locale` (com dois sublinhados à esquerda), foi preterido.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_create_locale`|\<locale.h>|  
|`_wcreate_locale`|\<locale.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
  
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
       //  
       if (!_strftime_l((char *)str, 100, "%#x",   
                     (const struct tm *)&thetime, locale))  
               printf("_strftime_l failed!\n");  
       else  
               printf("In de-CH locale, _strftime_l returns '%s'\n",   
                      str);  
  
       _free_locale(locale);  
  
       // Create a locale object representing the default C locale  
       locale = _create_locale(LC_ALL, "C");  
       time (&ltime);  
       _gmtime64_s(&thetime, &ltime);  
  
       if (!_strftime_l((char *)str, 100, "%#x",   
                     (const struct tm *)&thetime, locale))  
               printf("_strftime_l failed!\n");  
       else  
               printf("In 'C' locale, _strftime_l returns '%s'\n",   
                      str);  
  
       _free_locale(locale);  
}  
```  
  
## <a name="sample-output"></a>Saída de Exemplo  
  
```  
In de-CH locale, _strftime_l returns 'Samstag, 9. Februar 2002'  
In 'C' locale, _strftime_l returns 'Saturday, February 09, 2002'  
```  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 [Classe System::Globalization::CultureInfo](https://msdn.microsoft.com/en-us/library/system.globalization.cultureinfo.aspx)  
  
## <a name="see-also"></a>Consulte também  
 [Nomes de localidade, idiomas e cadeias de caracteres de país/região](../../c-runtime-library/locale-names-languages-and-country-region-strings.md)   
 [Cadeias de caracteres de idioma](../../c-runtime-library/language-strings.md)   
 [Cadeias de caracteres de país/região](../../c-runtime-library/country-region-strings.md)   
 [_free_locale](../../c-runtime-library/reference/free-locale.md)   
 [_configthreadlocale](../../c-runtime-library/reference/configthreadlocale.md)   
 [setlocale](../../preprocessor/setlocale.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [localeconv](../../c-runtime-library/reference/localeconv.md)   
 [_mbclen, mblen, _mblen_l](../../c-runtime-library/reference/mbclen-mblen-mblen-l.md)   
 [strlen, wcslen, _mbslen, _mbslen_l, _mbstrlen, _mbstrlen_l](../../c-runtime-library/reference/strlen-wcslen-mbslen-mbslen-l-mbstrlen-mbstrlen-l.md)   
 [mbstowcs, _mbstowcs_l](../../c-runtime-library/reference/mbstowcs-mbstowcs-l.md)   
 [mbtowc, _mbtowc_l](../../c-runtime-library/reference/mbtowc-mbtowc-l.md)   
 [_setmbcp](../../c-runtime-library/reference/setmbcp.md)   
 [setlocale, _wsetlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md)   
 [Funções strcoll](../../c-runtime-library/strcoll-functions.md)   
 [strftime, wcsftime, _strftime_l, _wcsftime_l](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md)   
 [strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l](../../c-runtime-library/reference/strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)   
 [wcstombs, _wcstombs_l](../../c-runtime-library/reference/wcstombs-wcstombs-l.md)   
 [wctomb, _wctomb_l](../../c-runtime-library/reference/wctomb-wctomb-l.md)