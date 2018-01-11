---
title: _strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _wcsnicmp
- _strnicmp_l
- _wcsnicmp_l
- _strnicmp
- _mbsnicmp
- _mbsnicmp_l
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
- wcsnicmp_l
- _strnicmp
- _ftcsnicmp
- mbsnicmp_l
- _ftcsncicmp
- mbsnicmp
- _tcsncicmp
- _mbsnicmp
- _tcsnicmp
- strnicmp_l
- _wcsnicmp
- _wcsnicmp_l
- CORECRT_WSTRING/_wcsnicmp
- CORECRT_WSTRING/_wcsnicmp_l
- string/_strnicmp
- string/_strnicmp_l
dev_langs: C++
helpviewer_keywords:
- tcsnicmp function
- _tcsncicmp function
- _mbsnicmp_l function
- mbsnicmp_l function
- wcsnicmp_l function
- wcsnicmp function
- string comparison [C++], lowercase
- ftcsnicmp function
- strnicmp_l function
- strncmp function
- _strnicmp function
- strings [C++], comparing characters of
- _wcsnicmp_l function
- tcsncicmp function
- string comparison [C++], strncmp function
- _mbsnicmp function
- ftcsncicmp function
- _tcsnicmp function
- _ftcsncicmp function
- _strnicmp_l function
- _ftcsnicmp function
- characters [C++], comparing
- mbsnicmp function
- _wcsnicmp function
ms.assetid: df6e5037-4039-4c85-a0a6-21d4ef513966
caps.latest.revision: "24"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c926c23553545a76bc8e1d0a0427c20ea65f3156
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="strnicmp-wcsnicmp-mbsnicmp-strnicmpl-wcsnicmpl-mbsnicmpl"></a>_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l
Compara o número especificado de caracteres de duas cadeias de caracteres sem considerar o caso.  
  
> [!IMPORTANT]
>  `_mbsnicmp` e `_mbsnicmp_l` não podem ser usados em aplicativos executados no Windows Runtime. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _strnicmp(  
   const char *string1,  
   const char *string2,  
   size_t count   
);  
int _wcsnicmp(  
   const wchar_t *string1,  
   const wchar_t *string2,  
   size_t count   
);  
int _mbsnicmp(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count   
);  
int _strnicmp_l(  
   const char *string1,  
   const char *string2,  
   size_t count,  
   _locale_t locale  
);  
int _wcsnicmp_l(  
   const wchar_t *string1,  
   const wchar_t *string2,  
   size_t count,  
   _locale_t locale  
);  
int _mbsnicmp_l(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count,  
   _locale_t locale  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `string1, string2`  
 Cadeias de caracteres com terminação nula.  
  
 `count`  
 O número de caracteres a serem comparados.  
  
 `locale`  
 Localidade a usar.  
  
## <a name="return-value"></a>Valor de retorno  
 Indica a relação entre as subcadeias de caracteres, da seguinte maneira.  
  
|Valor retornado|Descrição|  
|------------------|-----------------|  
|< 0|A subcadeia de caracteres `string1` é menor do que a subcadeia de caracteres `string2`.|  
|0|A subcadeia de caracteres `string1` é idêntica à subcadeia de caracteres `string2`.|  
|> 0|A subcadeia de caracteres `string1` é maior que a subcadeia de caracteres `string2`.|  
  
 Em um erro de validação de parâmetro, essas funções retornam `_NLSCMPERROR`, que é definido em \<string.h> e \<mbstring.h>.  
  
## <a name="remarks"></a>Comentários  
 A função `_strnicmp` compara ordinariamente, no máximo, os primeiros `count` caracteres de `string1` e `string2`. A comparação é executada independentemente do caso, convertendo cada caractere em minúsculas. `_strnicmp` é uma versão que não diferencia maiúsculas e minúsculas de `strncmp`. A comparação termina se um caractere nulo de terminação é atingido em qualquer cadeia de caracteres antes dos `count` caracteres serem comparados. Se as cadeias de caracteres forem iguais quando um caractere nulo de terminação for atingido em qualquer cadeia de caracteres antes dos `count` caracteres serem comparados, a cadeia de caracteres mais curta será menor.  
  
 Os caracteres de 91 a 96 na tabela ASCII ('[','\\', ']', ' ^', '_' e '\`') avaliam como menor do que qualquer caractere alfabético. Essa classificação é idêntica ao do `stricmp`.  
  
 `_wcsnicmp` e `_mbsnicmp` são versões de caracteres largos e de caracteres multibyte de `_strnicmp`. Os argumentos de `_wcsnicmp` são cadeias de caracteres largos; aqueles de `_mbsnicmp` são cadeias de caracteres multibyte. `_mbsnicmp` reconhece sequências de caracteres multibyte de acordo com a página de código multibyte atual e retorna `_NLSCMPERROR` em um erro. Para obter mais informações, consulte [Páginas de Código](../../c-runtime-library/code-pages.md). Caso contrário, essas três funções se comportam de forma idêntica. Essas funções são afetadas pela configuração de localidade – as versões que não têm o sufixo `_l` usam a localidade atual para esse comportamento dependente de localidade; e as versões que têm o sufixo `_l`, ao invés disso, usam o `locale` informado. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Todas essas funções validam seus parâmetros. Se `string1` ou `string2` for um ponteiro nulo, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão `_NLSCMPERROR` e definirão `errno` para `EINVAL`.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tcsncicmp`|`_strnicmp`|`_mbsnicmp`|`_wcsnicmp`|  
|`_tcsnicmp`|`_strnicmp`|`_mbsnbicmp`|`_wcsnicmp`|  
|`_tcsncicmp_l`|`_strnicmp_l`|`_mbsnicmp_l`|`_wcsnicmp_l`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_strnicmp`, `_strnicmp_l`|<string.h>|  
|`_wcsnicmp`, `_wcsnicmp_l`|<string.h> ou <wchar.h>|  
|`_mbsnicmp`, `_mbsnicmp_l`|\<mbstring.h>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo para [strncmp](../../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md).  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [strcat, wcscat, _mbscat](../../c-runtime-library/reference/strcat-wcscat-mbscat.md)   
 [strcmp, wcscmp, _mbscmp](../../c-runtime-library/reference/strcmp-wcscmp-mbscmp.md)   
 [strcpy, wcscpy, _mbscpy](../../c-runtime-library/reference/strcpy-wcscpy-mbscpy.md)   
 [strncat, _strncat_l, wcsncat, _wcsncat_l, _mbsncat, _mbsncat_l](../../c-runtime-library/reference/strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md)   
 [strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](../../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)   
 [strncpy, _strncpy_l, wcsncpy, _wcsncpy_l, _mbsncpy, _mbsncpy_l](../../c-runtime-library/reference/strncpy-strncpy-l-wcsncpy-wcsncpy-l-mbsncpy-mbsncpy-l.md)   
 [strrchr, wcsrchr, _mbsrchr, _mbsrchr_l](../../c-runtime-library/reference/strrchr-wcsrchr-mbsrchr-mbsrchr-l.md)   
 [_strset, _strset_l, _wcsset, _wcsset_l, _mbsset, _mbsset_l](../../c-runtime-library/reference/strset-strset-l-wcsset-wcsset-l-mbsset-mbsset-l.md)   
 [strspn, wcsspn, _mbsspn, _mbsspn_l](../../c-runtime-library/reference/strspn-wcsspn-mbsspn-mbsspn-l.md)