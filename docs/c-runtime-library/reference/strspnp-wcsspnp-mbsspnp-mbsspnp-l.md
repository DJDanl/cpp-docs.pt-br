---
title: _strspnp, _wcsspnp, _mbsspnp, _mbsspnp_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _mbsspnp
- _wcsspnp
- _mbsspnp_l
- _strspnp
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
apitype: DLLExport
f1_keywords:
- _tcsspnp
- _mbsspnp
- strspnp
- _ftcsspnp
- _mbsspnp_l
- wcsspnp
- mbsspnp_l
- _wcsspnp
- _strspnp
- mbsspnp
dev_langs:
- C++
helpviewer_keywords:
- _strspnp function
- _wcsspnp function
- _mbsspnp_l function
- strspnp function
- mbsspnp function
- wcsspnp function
- _mbsspnp function
- mbsspnp_l function
- _tcsspnp function
- tcsspnp function
ms.assetid: 1ce18100-2edd-4c3b-af8b-53f204d80233
caps.latest.revision: 23
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
ms.openlocfilehash: f7bf32d7fa725e1f012b2a793a8091674e1c2e9f
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="strspnp-wcsspnp-mbsspnp-mbsspnpl"></a>_strspnp, _wcsspnp, _mbsspnp, _mbsspnp_l
Retorna um ponteiro para o primeiro caractere em uma determinada sequência de caracteres não em outra cadeia de caracteres.  
  
> [!IMPORTANT]
>  `_mbsspnp` e `_mbsspnp_l` não podem ser usados em aplicativos executados no Windows Runtime. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
char *_strspnp(  
   const char *str,  
   const char *charset  
);  
wchar_t *_wcsspnp(  
   const unsigned wchar_t *str,  
   const unsigned wchar_t *charset  
);  
unsigned char *_mbsspnp(  
   const unsigned char *str,  
   const unsigned char *charset  
);  
unsigned char *_mbsspnp_l(  
   const unsigned char *str,  
   const unsigned char *charset,  
   _locale_t locale  
);  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `str`  
 Cadeia de caracteres terminada em nulo para pesquisa.  
  
 `charset`  
 Conjunto de caracteres terminado em nulo.  
  
 `locale`  
 Localidade a usar.  
  
## <a name="return-value"></a>Valor de retorno  
 `_strspnp`, `_wcsspnp`, e `_mbsspnp` retornar um ponteiro para o primeiro caractere em `str` que não pertence ao conjunto de caracteres em `charset`. Cada uma dessas funções retorna `NULL` se `str` consiste inteiramente em caracteres de `charset`. Para cada uma dessas rotinas, nenhum valor retornado é reservado para indicar um erro.  
  
## <a name="remarks"></a>Comentários  
 A função `_mbsspnp` retorna um ponteiro para o caractere multibyte que é o primeiro caractere em `str` que não pertence a um conjunto de caracteres em `charset`. `_mbsspnp` reconhece sequências de caracteres multibyte de acordo com a [página de código multibyte](../../c-runtime-library/code-pages.md) atualmente em uso. A pesquisa não inclui os caracteres nulo de terminação.  
  
 Se `str` ou `charset` for um ponteiro nulo, a função invocará o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função retornará `NULL` e definirá `errno` como `EINVAL`.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_tcsspnp`|`_strspnp`|`_mbsspnp`|`_wcsspnp`|  
  
 `_strspnp` e `_wcsspnp` são versões de caractere de byte único e de caractere largo de `_mbsspnp`. `_strspnp` e `_wcsspnp` se comportam de forma idêntica ao `_mbsspnp`, caso contrário; eles são fornecidos apenas para esse mapeamento e não devem ser usados por qualquer outro motivo. Para obter mais informações, consulte [Usando mapeamentos de texto genérico](../../c-runtime-library/using-generic-text-mappings.md) e [Mapeamentos de Texto Genérico](../../c-runtime-library/generic-text-mappings.md).  
  
 `_mbsspnp_l` é idêntico, exceto que ele usa o parâmetro de localidade passado. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_mbsspnp`|\<mbstring.h>|  
|`_strspnp`|\<tchar.h>|  
|`_wcsspnp`|\<tchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_mbsspnp.c  
#include <mbstring.h>  
#include <stdio.h>  
  
int main( void ) {  
   const unsigned char string1[] = "cabbage";  
   const unsigned char string2[] = "c";  
   unsigned char *ptr = 0;  
   ptr = _mbsspnp( string1, string2 );  
   printf( "%s\n", ptr);  
}  
```  
  
## <a name="output"></a>Saída  
  
```  
abbage  
```  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [strspn, wcsspn, _mbsspn, _mbsspn_l](../../c-runtime-library/reference/strspn-wcsspn-mbsspn-mbsspn-l.md)   
 [strncat_s, _strncat_s_l, wcsncat_s, _wcsncat_s_l, _mbsncat_s, _mbsncat_s_l](../../c-runtime-library/reference/strncat-s-strncat-s-l-wcsncat-s-wcsncat-s-l-mbsncat-s-mbsncat-s-l.md)   
 [strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](../../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)   
 [strncpy_s, _strncpy_s_l, wcsncpy_s, _wcsncpy_s_l, _mbsncpy_s, _mbsncpy_s_l](../../c-runtime-library/reference/strncpy-s-strncpy-s-l-wcsncpy-s-wcsncpy-s-l-mbsncpy-s-mbsncpy-s-l.md)   
 [_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l](../../c-runtime-library/reference/strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)   
 [strrchr, wcsrchr, _mbsrchr, _mbsrchr_l](../../c-runtime-library/reference/strrchr-wcsrchr-mbsrchr-mbsrchr-l.md)
