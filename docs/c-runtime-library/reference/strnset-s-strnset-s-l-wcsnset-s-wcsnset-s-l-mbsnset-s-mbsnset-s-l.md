---
title: "_strnset_s, _strnset_s_l, _wcsnset_s, _wcsnset_s_l, _mbsnset_s, _mbsnset_s_l | Microsoft Docs"
ms.custom: ""
ms.date: "11/04/2016"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_mbsnset_s_l"
  - "_strnset_s"
  - "_mbsnset_s"
  - "_strnset_s_l"
  - "_wcsnset_s_l"
  - "_wcsnset_s"
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
  - "api-ms-win-crt-multibyte-l1-1-0.dll"
  - "api-ms-win-crt-string-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_mbsnset_s_l"
  - "wcsnset_s"
  - "_tcsnset_s_l"
  - "_wcsnset_s"
  - "_mbsnset_s"
  - "_wcsnset_s_l"
  - "_strnset_s_l"
  - "strnset_s_l"
  - "_tcsnset_s"
  - "_strnset_s"
  - "strnset_s"
  - "mbsnset_s_l"
  - "mbsnset_s"
  - "wcsnset_s_l"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "tcsnset_s function"
  - "mbsnset_s_l function"
  - "initializing characters"
  - "wcsnset_s function"
  - "mbsnset_s function"
  - "_tcsnset_s_l function"
  - "_strnset_s_l function"
  - "_mbsnset_s function"
  - "strnset_s_l function"
  - "_tcsnset_s function"
  - "_strnset_s function"
  - "tcsnset_s_l function"
  - "_mbsnset_s_l function"
  - "strnset_s function"
  - "_wcsnset_s function"
ms.assetid: 9cf1b321-b5cb-4469-b285-4c07cfbd8813
caps.latest.revision: 27
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
# <a name="strnsets-strnsetsl-wcsnsets-wcsnsetsl-mbsnsets-mbsnsetsl"></a>_strnset_s, _strnset_s_l, _wcsnset_s, _wcsnset_s_l, _mbsnset_s, _mbsnset_s_l
Inicializa os caracteres de uma cadeia de caracteres para um determinado caractere. Essas versões de [_strnset, _strnset_l, _wcsnset, _wcsnset_l, _mbsnset, _mbsnset_l](../../c-runtime-library/reference/strnset-strnset-l-wcsnset-wcsnset-l-mbsnset-mbsnset-l.md) tem aprimoramentos de segurança, conforme descrito em [Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
> [!IMPORTANT]
>  `_mbsnset_s` e `_mbsnset_s_l` não podem ser usados em aplicativos executados no Windows Runtime. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
errno_t _strnset_s(  
   char *str,  
   size_t numberOfElements,  
   int c,  
   size_t count   
);  
errno_t _strnset_s_l(  
   char *str,  
   size_t numberOfElements,  
   int c,  
   size_t count,  
   locale_t locale  
);  
errno_t _wcsnset_s(  
   wchar_t *str,  
   size_t numberOfElements,  
   wchar_t c,  
   size_t count   
);  
errno_t _wcsnset_s_l(  
   wchar_t *str,  
   size_t numberOfElements,  
   wchar_t c,  
   size_t count,  
   _locale_t locale  
);  
errno_t _mbsnset_s(  
   unsigned char *str,  
   size_t numberOfElements,  
   unsigned int c,  
   size_t count   
);  
errno_t _mbsnset_s_l(  
   unsigned char *str,  
   size_t numberOfElements,  
   unsigned int c,  
   size_t count,  
   _locale_t locale  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `str`  
 Cadeia de caracteres a ser alterada.  
  
 `numberOfElements`  
 O tamanho do buffer `str`.  
  
 `c`  
 Configuração de caractere.  
  
 `count`  
 O número de caracteres a ser definido.  
  
 `locale`  
 Localidade a usar.  
  
## <a name="return-value"></a>Valor de retorno  
 Zero se for bem-sucedido; caso contrário, um código de erro.  
  
 Essas funções validam seus argumentos. Se `str` não é uma cadeia de caracteres terminado em nulo ou argumento de tamanho for menor que ou igual a 0, em seguida o manipulador de parâmetro inválido é invocado, conforme a descrição em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções retornarão um código de erro e `errno` será definido para esse código de erro. O código de erro padrão será `EINVAL` se um valor mais específico não se aplicar.  
  
## <a name="remarks"></a>Comentários  
 Essas funções definem, no máximo, os primeiros `count` caracteres de `str` para `c`. Se `count` é maior que o tamanho do `str`, o tamanho de `str` é usado em vez de `count`. Ocorrerá um erro se `count` for maior do que `numberOfElements` e esses dois parâmetros são maiores que o tamanho de `str`.  
  
 `_wcsnset_s` e `_mbsnset_s` são versões de caracteres largos e de caracteres multibyte de `_strnset_s`. O argumento de cadeia de caracteres de `_wcsnset_s` é uma cadeia de caractere largo; do `_mbsnset_s` é a cadeia de caracteres multibyte. Caso contrário, essas três funções se comportam de forma idêntica.  
  
 O valor de saída é afetado pela configuração da categoria `LC_CTYPE` da localidade; consulte [setlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções sem o sufixo `_l` usam a localidade atual desse comportamento dependente da localidade. As versões com o sufixo `_l` são idênticas, exceto por usarem o parâmetro de localidade passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 As versões de depuração dessas funções preenchem primeiro o buffer com 0xFD. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](../../c-runtime-library/reference/crtsetdebugfillthreshold.md).  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tcsnset_s`|`_strnset_s`|`_mbsnbset_s`|`_wcsnset_s`|  
|`_tcsnset_s_l`|`_strnset_s_l`|`_mbsnbset_s_l`|`_wcsnset_s_l`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_strnset_s`|\<string.h>|  
|`_strnset_s_l`|\<tchar.h>|  
|`_wcsnset_s`|\<string.h> ou \<wchar.h>|  
|`_wcsnset_s_l`|\<tchar.h>|  
|`_mbsnset_s`, `_mbsnset_s_l`|\<mbstring.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_strnset_s.c  
#include <string.h>  
#include <stdio.h>  
  
int main( void )  
{  
   char string[15] = "This is a test";  
   /* Set not more than 4 characters of string to be *'s */  
   printf( "Before: %s\n", string );  
   _strnset_s( string, sizeof(string), '*', 4 );  
   printf( "After:  %s\n", string );  
}  
```  
  
```Output  
Before: This is a test  
After:  **** is a test  
```  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 [System::String::Replace](https://msdn.microsoft.com/en-us/library/system.string.replace.aspx)  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [strcat, wcscat, _mbscat](../../c-runtime-library/reference/strcat-wcscat-mbscat.md)   
 [strcmp, wcscmp, _mbscmp](../../c-runtime-library/reference/strcmp-wcscmp-mbscmp.md)   
 [strcpy, wcscpy, _mbscpy](../../c-runtime-library/reference/strcpy-wcscpy-mbscpy.md)   
 [_strset, _strset_l, _wcsset, _wcsset_l, _mbsset, _mbsset_l](../../c-runtime-library/reference/strset-strset-l-wcsset-wcsset-l-mbsset-mbsset-l.md)