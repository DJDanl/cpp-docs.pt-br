---
title: _strncnt, _wcsncnt, _mbsnbcnt, _mbsnbcnt_l, _mbsnccnt, _mbsnccnt_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _mbsnbcnt_l
- _mbsnccnt
- _wcsncnt
- _strncnt
- _mbsnccnt_l
- _mbsnbcnt
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
- _mbsnbcnt
- wcsncnt
- _tcsnbcnt
- _mbsnccnt
- _ftcsnbcnt
- mbsnbcnt
- strncnt
- mbsnbcnt_l
- mbsnccnt_l
- mbsnccnt
- _strncnt
- _wcsncnt
dev_langs: C++
helpviewer_keywords:
- _strncnt function
- _mbsnbcnt function
- _mbsnbcnt_l function
- _mbsnccnt_l function
- mbsnbcnt_l function
- mbsnbcnt function
- tcsnbcnt function
- mbsnccnt_l function
- strncnt function
- _tcsnbcnt function
- mbsnccnt function
- wcsncnt function
- _mbsnccnt function
- _wcsncnt function
ms.assetid: 2a022e9e-a307-4acb-a66b-e56e5357f848
caps.latest.revision: "22"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 27c2d107da6c937705cacac770a50d912cadda84
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="strncnt-wcsncnt-mbsnbcnt-mbsnbcntl-mbsnccnt-mbsnccntl"></a>_strncnt, _wcsncnt, _mbsnbcnt, _mbsnbcnt_l, _mbsnccnt, _mbsnccnt_l
Retorna o número de caracteres ou bytes dentro de uma contagem especificada.  
  
> [!IMPORTANT]
>  `_mbsnbcnt`, `_mbsnbcnt_l`, `_mbsnccnt` e `_mbsnccnt_l` não podem ser usados em aplicativos que são executados no Windows Runtime. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
size_t _strncnt(  
   const char *str,  
   size_t count  
);  
size_t _wcsncnt(  
   const wchar_t *str,  
   size_t count  
);  
size_t _mbsnbcnt(  
   const unsigned char *str,  
   size_t count   
);  
size_t _mbsnbcnt_l(  
   const unsigned char *str,  
   size_t count,  
   _locale_t locale  
);  
size_t _mbsnccnt(  
   const unsigned char *str,  
   size_t count  
);  
size_t _mbsnccnt_l(  
   const unsigned char *str,  
   size_t count,  
   _locale_t locale  
);  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `str`  
 Cadeia de caracteres a ser examinada.  
  
 `count`  
 Número de caracteres ou bytes a ser examinado em `str`.  
  
 `locale`  
 Localidade a usar.  
  
## <a name="return-value"></a>Valor de retorno  
 `_mbsnbcnt` e `_mbsnbcnt_l` retornam o número de bytes encontrado no primeiro de `count` caracteres multibyte de `str`. `_mbsnccnt` e `_mbsnccnt_l` retornam o número de bytes encontrado no primeiro `count` de bytes de `str`. Se um caractere NULO é encontrado antes do exame de `str` estar concluído, eles retornam o número de bytes ou caracteres encontrados antes do caractere nulo. Se `str` consiste em menos de `count` caracteres ou bytes, retornam o número de caracteres ou bytes na cadeia de caracteres. Se `count` for menor que zero, eles retornam 0. Nas versões anteriores, essas funções tinham um valor retornado do tipo `int` ao invés de `size_t`.  
  
 `_strncnt` retorna o número de caracteres nos primeiros `count` bytes da cadeia de caracteres de byte único `str`. `_wcsncnt` retorna o número de caracteres nos primeiros `count` caracteres largos da cadeia de caracteres largos `str`.  
  
## <a name="remarks"></a>Comentários  
 `_mbsnbcnt` e `_mbsnbcnt_l` contam o número de bytes encontrados no primeiro `count` de caracteres multibyte de `str`. `_mbsnbcnt` e `_mbsnbcnt_l` substituem `mtob` e devem ser usados no lugar de `mtob`.  
  
 `_mbsnccnt` e `_mbsnccnt_l` contam o número de caracteres encontrado no primeiro `count` de bytes de `str`. Se `_mbsnccnt` e `_mbsnccnt_l` encontrar um valor NULO no segundo byte de um caractere de byte duplo, o primeiro byte também é considerado como NULO e não está incluído no valor de contagem retornado. `_mbsnccnt` e `_mbsnccnt_l` substituem `btom` e devem ser usados no lugar de `btom`.  
  
 Se `str` for um ponteiro nulo ou é `count` for 0, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md), `errno` é definido como `EINVAL` e a função retorna 0.  
  
 O valor de saída é afetado pela configuração da categoria `LC_CTYPE` da localidade; consulte [setlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções sem o sufixo `_l` usam a localidade atual desse comportamento dependente da localidade. As versões com o sufixo `_l` são idênticas, exceto por usarem o parâmetro de localidade passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|-------------|--------------------------------------|--------------------|-----------------------|  
|`_tcsnbcnt`|`_strncnt`|`_mbsnbcnt`|`_wcsncnt`|  
|`_tcsnccnt`|`_strncnt`|`_mbsnbcnt`|`n/a`|  
|`_wcsncnt`|`n/a`|`n/a`|`_mbsnbcnt`|  
|`_wcsncnt`|`n/a`|`n/a`|`_mbsnccnt`|  
|`n/a`|`n/a`|`_mbsnbcnt_l`|`_mbsnccnt_l`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_mbsnbcnt`|\<mbstring.h>|  
|`_mbsnbcnt_l`|\<mbstring.h>|  
|`_mbsnccnt`|\<mbstring.h>|  
|`_mbsnccnt_l`|\<mbstring.h>|  
|`_strncnt`|\<tchar.h>|  
|`_wcsncnt`|\<tchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_mbsnbcnt.c  
  
#include  <mbstring.h>  
#include  <stdio.h>  
  
int main( void )  
{  
   unsigned char str[] = "This is a multibyte-character string.";  
   unsigned int char_count, byte_count;  
   char_count = _mbsnccnt( str, 10 );  
   byte_count = _mbsnbcnt( str, 10 );  
   if ( byte_count - char_count )  
      printf( "The first 10 characters contain %d multibyte characters\n", char_count );  
   else  
      printf( "The first 10 characters are single-byte.\n");  
}  
```  
  
## <a name="output"></a>Saída  
  
```  
The first 10 characters are single-byte.  
```  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [_mbsnbcat, _mbsnbcat_l](../../c-runtime-library/reference/mbsnbcat-mbsnbcat-l.md)