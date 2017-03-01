---
title: _stricmp, _wcsicmp, _mbsicmp, _stricmp_l, _wcsicmp_l, _mbsicmp_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _stricmp_l
- _mbsicmp
- _wcsicmp
- _mbsicmp_l
- _stricmp
- _wcsicmp_l
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
- ntoskrnl.exe
- ucrtbase.dll
- api-ms-win-crt-multibyte-l1-1-0.dll
- api-ms-win-crt-string-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _ftcsicmp
- _stricmp
- wcsicmp_l
- _wcsicmp
- _tcsicmp
- _strcmpi
- stricmp_l
- _mbsicmp
- _fstricmp
- mbsicmp_l
- mbsicmp
dev_langs:
- C++
helpviewer_keywords:
- _wcsicmp function
- _stricmp_l function
- fstricmp function
- _tcsicmp function
- ftcsicmp function
- string comparison [C++], lowercase
- _wcsicmp_l function
- _fstricmp function
- strings [C++], comparing
- mbsicmp function
- _ftcsicmp function
- _mbsicmp_l function
- wcsicmp_l function
- _stricmp function
- _mbsicmp function
- tcsicmp function
- stricmp_l function
- mbsicmp_l function
- _strcmpi function
ms.assetid: 0e1ee515-0d75-435a-a445-8875d4669b50
caps.latest.revision: 28
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
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: be0f9a48113a00d915ce9fe4474d4a910b1679f1
ms.lasthandoff: 02/25/2017

---
# <a name="stricmp-wcsicmp-mbsicmp-stricmpl-wcsicmpl-mbsicmpl"></a>_stricmp, _wcsicmp, _mbsicmp, _stricmp_l, _wcsicmp_l, _mbsicmp_l
Executa uma comparação que não diferencia maiúsculas de minúsculas na cadeia de caracteres.  
  
> [!IMPORTANT]
>  `_mbsicmp` e `_mbsicmp_l` não podem ser usados em aplicativos executados no Windows Runtime. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _stricmp(  
   const char *string1,  
   const char *string2   
);  
int _wcsicmp(  
   const wchar_t *string1,  
   const wchar_t *string2   
);  
int _mbsicmp(  
   const unsigned char *string1,  
   const unsigned char *string2   
);  
int _stricmp_l(  
   const char *string1,  
   const char *string2,  
   _locale_t locale  
);  
int _wcsicmp_l(  
   const wchar_t *string1,  
   const wchar_t *string2,  
   _locale_t locale  
);  
int _mbsicmp_l(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   _locale_t locale  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `string1, string2`  
 Cadeias de caracteres com terminação nula.  
  
 `locale`  
 Localidade a usar.  
  
## <a name="return-value"></a>Valor de retorno  
 O valor retornado indica a relação de `string1` para `string2` da seguinte maneira.  
  
|Valor retornado|Descrição|  
|------------------|-----------------|  
|< 0|`string1` é menor que `string2`|  
|0|`string1` é idêntica a `string2`|  
|> 0|`string1` é maior que `string2`|  
  
 Em um erro, `_mbsicmp` retorna `_NLSCMPERROR`, que é definido em \<string.h> e \<mbstring.h>.  
  
## <a name="remarks"></a>Comentários  
 A função `_stricmp` ordinalmente compara `string1` e `string2` após converter cada caractere em minúscula e retorna um valor indicando seu relacionamento. `_stricmp` é diferente de `_stricoll` que a comparação com `_stricmp` será afetada somente por `LC_CTYPE`, que determina quais caracteres são letras maiúsculas e minúsculas. A função `_stricoll` compara cadeias de caracteres de acordo com ambas as categorias `LC_CTYPE` e `LC_COLLATE` de localidade, que inclui o caso e a ordem de agrupamento. Para obter mais informações sobre a categoria `LC_COLLATE`, consulte [setlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md) e [categorias de localidade](../../c-runtime-library/locale-categories.md). As versões dessas funções sem o sufixo `_l` usam a localidade atual para o comportamento que depende da localidade. As versões com o sufixo são idênticas, com exceção de que usam a localidade passada, em vez da localidade atual. Se a localidade não tiver sido definida, a localidade C será usada. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
> [!NOTE]
>  `_stricmp` equivale a `_strcmpi`. Podem ser usadas alternadamente, mas `_stricmp` é o padrão preferencial.  
  
 A função `_strcmpi` é equivalente a `_stricmp` e é fornecido para fins de compatibilidade com versões anteriores.  
  
 Como `_stricmp` realiza comparações de minúsculas, pode resultar em comportamento inesperado.  
  
 Para ilustrar quando a conversão de caso por `_stricmp` afeta o resultado de uma comparação, suponha que você tenha duas cadeias de caracteres JOHNSTON e JOHN_HENRY. A cadeia de caracteres JOHN_HENRY será considerada inferior a JOHNSTON porque "_" tem um valor de ASCII menor que um S minúsculo. Na verdade, qualquer caractere que tenha um valor de ASCII entre 91 e 96 será considerado menor do que qualquer letra.  
  
 Se a função [strcmp](../../c-runtime-library/reference/strcmp-wcscmp-mbscmp.md) é usada em vez de `_stricmp`, JOHN_HENRY será maior que JOHNSTON.  
  
 `_wcsicmp` e `_mbsicmp` são versões de caracteres largos e de caracteres multibyte de `_stricmp`. Os argumentos e o valor retornado de `_wcsicmp` são cadeias de caracteres largos; aqueles de `_mbsicmp` são cadeias de caracteres multibyte. `_mbsicmp` reconhece sequências de caracteres multibyte de acordo com a página de código multibyte atual e retorna `_NLSCMPERROR` em um erro. Para obter mais informações, consulte [Páginas de Código](../../c-runtime-library/code-pages.md). Caso contrário, essas três funções se comportam de forma idêntica.  
  
 `_wcsicmp` e `wcscmp` se comportam de maneira idêntica, exceto que `wcscmp` não converte seus argumentos para minúsculas antes de compará-los. `_mbsicmp` e `_mbscmp` se comportam de maneira idêntica, exceto que `_mbscmp` não converte seus argumentos para minúsculas antes de compará-los.  
  
 Você precisará chamar [setlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md) para `_wcsicmp` funcionar com caracteres Latino 1. A localidade C está em vigor por padrão, portanto, por exemplo, ä não será comparado como igual a Ä. Chamar `setlocale` com qualquer localidade que não seja a localidade C antes da chamada para `_wcsicmp`. A amostra a seguir demonstra como `_wcsicmp` é sensível à localidade:  
  
```  
// crt_stricmp_locale.c  
#include <string.h>  
#include <stdio.h>  
#include <locale.h>  
  
int main() {  
   setlocale(LC_ALL,"C");   // in effect by default  
   printf("\n%d",_wcsicmp(L"ä", L"Ä"));   // compare fails  
   setlocale(LC_ALL,"");  
   printf("\n%d",_wcsicmp(L"ä", L"Ä"));   // compare succeeds  
}  
```  
  
 Uma alternativa é chamar [create_locale, _wcreate_locale](../../c-runtime-library/reference/create-locale-wcreate-locale.md) e passar o objeto de localidade retornado como um parâmetro para `_wcsicmp_l`.  
  
 Todas essas funções validam seus parâmetros. Se `string1` ou `string2` são ponteiros nulos, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão `_NLSCMPERROR` e definirão `errno` para `EINVAL`.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tcsicmp`|`_stricmp`|`_mbsicmp`|`_wcsicmp`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_stricmp`, `_stricmp_l`|\<string.h>|  
|`_wcsicmp`, `_wcsicmp_l`|\<string.h> ou \<wchar.h>|  
|`_mbsicmp`, `_mbsicmp_l`|\<mbstring.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_stricmp.c  
  
#include <string.h>  
#include <stdio.h>  
#include <stdlib.h>  
  
char string1[] = "The quick brown dog jumps over the lazy fox";  
char string2[] = "The QUICK brown dog jumps over the lazy fox";  
  
int main( void )  
{  
   char tmp[20];  
   int result;  
  
   // Case sensitive  
   printf( "Compare strings:\n   %s\n   %s\n\n", string1, string2 );  
   result = strcmp( string1, string2 );  
   if( result > 0 )  
      strcpy_s( tmp, _countof(tmp), "greater than" );  
   else if( result < 0 )  
      strcpy_s( tmp, _countof(tmp), "less than" );  
   else  
      strcpy_s( tmp, _countof(tmp), "equal to" );  
   printf( "   strcmp:   String 1 is %s string 2\n", tmp );  
  
   // Case insensitive (could use equivalent _stricmp)  
   result = _stricmp( string1, string2 );  
   if( result > 0 )  
      strcpy_s( tmp, _countof(tmp), "greater than" );  
   else if( result < 0 )  
      strcpy_s( tmp, _countof(tmp), "less than" );  
   else  
      strcpy_s( tmp, _countof(tmp), "equal to" );  
   printf( "   _stricmp:  String 1 is %s string 2\n", tmp );  
}  
```  
  
```Output  
Compare strings:  
   The quick brown dog jumps over the lazy fox  
   The QUICK brown dog jumps over the lazy fox  
  
   strcmp:   String 1 is greater than string 2  
   _stricmp:  String 1 is equal to string 2  
```  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 [System::String::Compare](https://msdn.microsoft.com/en-us/library/system.string.compare.aspx)  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [memcmp, wmemcmp](../../c-runtime-library/reference/memcmp-wmemcmp.md)   
 [_memicmp, _memicmp_l](../../c-runtime-library/reference/memicmp-memicmp-l.md)   
 [strcmp, wcscmp, _mbscmp](../../c-runtime-library/reference/strcmp-wcscmp-mbscmp.md)   
 [Funções strcoll](../../c-runtime-library/strcoll-functions.md)   
 [strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](../../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)   
 [_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l](../../c-runtime-library/reference/strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)   
 [strrchr, wcsrchr, _mbsrchr, _mbsrchr_l](../../c-runtime-library/reference/strrchr-wcsrchr-mbsrchr-mbsrchr-l.md)   
 [_strset, _strset_l, _wcsset, _wcsset_l, _mbsset, _mbsset_l](../../c-runtime-library/reference/strset-strset-l-wcsset-wcsset-l-mbsset-mbsset-l.md)   
 [strspn, wcsspn, _mbsspn, _mbsspn_l](../../c-runtime-library/reference/strspn-wcsspn-mbsspn-mbsspn-l.md)
