---
title: _strset, _strset_l, _wcsset, _wcsset_l, _mbsset, _mbsset_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _wcsset
- _mbsset
- _strset_l
- _strset
- _wcsset_l
- _mbsset_l
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
- api-ms-win-crt-multibyte-l1-1-0.dll
- api-ms-win-crt-string-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- mbsset
- _strset_l
- _mbsset
- _strset
- mbsset_l
- strset_l
- _wcsset
- _ftcsset
- wcsset_l
- _tcsset_l
- _mbsset_l
- _wcsset_l
- _fstrset
- _tcsset
dev_langs:
- C++
helpviewer_keywords:
- _wcsset_l function
- _tcsset function
- wcsset_l function
- _ftcsset function
- characters [C++], setting
- _strset function
- ftcsset function
- strings [C++], setting characters
- mbsset function
- tcsset_l function
- _fstrset function
- mbsset_l function
- strset_l function
- _wcsset function
- _mbsset function
- _mbsset_l function
- tcsset function
- _strset_l function
- fstrset function
- _tcsset_l function
ms.assetid: c42ded42-2ed9-4f06-a0a9-247ba305473a
caps.latest.revision: 31
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: a82768750e6a7837bb81edd8a51847f83c294c20
ms.openlocfilehash: 9db9c684f27f2cae103cf3071332a5d7fa90e8d9
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="strset-strsetl-wcsset-wcssetl-mbsset-mbssetl"></a>_strset, _strset_l, _wcsset, _wcsset_l, _mbsset, _mbsset_l
Define os caracteres de uma cadeia de caracteres para um determinado caractere. Versões mais seguras dessas funções estão disponíveis; consulte [_strset_s, _strset_s_l, _wcsset_s, _wcsset_s_l, _mbsset_s, _mbsset_s_l](../../c-runtime-library/reference/strset-s-strset-s-l-wcsset-s-wcsset-s-l-mbsset-s-mbsset-s-l.md).  
  
> [!IMPORTANT]
>  `_mbsset` e `_mbsset_l` não podem ser usados em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)]. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
char *_strset(  
   char *str,  
   int c   
);  
char *_strset_l(  
   char *str,  
   int c,  
   locale_t locale  
);  
wchar_t *_wcsset(  
   wchar_t *str,  
   wchar_t c   
);  
wchar_t *_wcsset_l(  
   wchar_t *str,  
   wchar_t c,  
   locale_t locale  
);  
unsigned char *_mbsset(  
   unsigned char *str,  
   unsigned int c   
);  
unsigned char *_mbsset_l(  
   unsigned char *str,  
   unsigned int c,  
   _locale_t locale  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `str`  
 Cadeia de caracteres terminada em nulo a ser definida.  
  
 `c`  
 Configuração de caractere.  
  
 `locale`  
 Localidade a usar.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para a cadeia de caracteres alterada.  
  
## <a name="remarks"></a>Comentários  
 A função `_strset` define todos os caracteres (exceto o caractere nulo de terminação) de `str` para `c`, convertido para `char`. `_wcsset` e `_mbsset_l` são versões de caractere largo e caracteres multibyte de `_strset` e os tipos de dados dos argumentos e valores de retorno variam de acordo. Caso contrário, essas funções se comportam de forma idêntica.  
  
 `_mbsset` valida seus parâmetros. Se `str` for um ponteiro nulo, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, `_mbsset` retornará `NULL` e definirá `errno` como `EINVAL`. `_strset` e `_wcsset` não validam seus parâmetros.  
  
 O valor de saída é afetado pela configuração da categoria `LC_CTYPE` da localidade. Consulte [setlocale, _wsetlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções são idênticas, exceto que aquelas que não têm o sufixo `_l` usam a localidade atual e as com um sufixo `_l` usam o parâmetro de localidade informado. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
> [!IMPORTANT]
>  Essas funções podem ser vulneráveis a ameaças de estouro de buffer. Os estouros de buffer podem ser usados em ataques de sistema porque podem causar uma elevação de privilégio não garantida. Para obter mais informações, consulte [Avoiding Buffer Overruns](http://msdn.microsoft.com/library/windows/desktop/ms717795) (Evitando estouros de buffer).  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tcsset`|`_strset`|`_mbsset`|`_wcsset`|  
|`_tcsset_l`|`_strset_l`|`_mbsset_l`|`_wcsset_l`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_strset`|\<string.h>|  
|`_strset_l`|\<tchar.h>|  
|`_wcsset`|\<string.h> ou \<wchar.h>|  
|`_wcsset_l`|\<tchar.h>|  
|`_mbsset`, `_mbsset_l`|\<mbstring.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_strset.c  
// compile with: /W3  
  
#include <string.h>  
#include <stdio.h>  
  
int main( void )  
{  
   char string[] = "Fill the string with something.";  
   printf( "Before: %s\n", string );  
   _strset( string, '*' ); // C4996  
   // Note: _strset is deprecated; consider using _strset_s instead  
   printf( "After:  %s\n", string );  
}  
```  
  
```Output  
Before: Fill the string with something.  
After:  *******************************  
```  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [_mbsnbset, _mbsnbset_l](../../c-runtime-library/reference/mbsnbset-mbsnbset-l.md)   
 [memset, wmemset](../../c-runtime-library/reference/memset-wmemset.md)   
 [strcat, wcscat, _mbscat](../../c-runtime-library/reference/strcat-wcscat-mbscat.md)   
 [strcmp, wcscmp, _mbscmp](../../c-runtime-library/reference/strcmp-wcscmp-mbscmp.md)   
 [strcpy, wcscpy, _mbscpy](../../c-runtime-library/reference/strcpy-wcscpy-mbscpy.md)   
 [_strnset, _strnset_l, _wcsnset, _wcsnset_l, _mbsnset, _mbsnset_l](../../c-runtime-library/reference/strnset-strnset-l-wcsnset-wcsnset-l-mbsnset-mbsnset-l.md)
