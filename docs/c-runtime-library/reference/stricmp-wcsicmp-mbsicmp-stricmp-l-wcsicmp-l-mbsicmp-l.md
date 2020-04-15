---
title: _stricmp, _wcsicmp, _mbsicmp, _stricmp_l, _wcsicmp_l, _mbsicmp_l
ms.date: 4/2/2020
api_name:
- _stricmp_l
- _mbsicmp
- _wcsicmp
- _mbsicmp_l
- _stricmp
- _wcsicmp_l
- _o__mbsicmp
- _o__mbsicmp_l
- _o__stricmp
- _o__stricmp_l
- _o__wcsicmp
- _o__wcsicmp_l
api_location:
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
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
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
ms.openlocfilehash: 315a86c5cf7e58219bad25f2b6633dd91275c09f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81320466"
---
# <a name="_stricmp-_wcsicmp-_mbsicmp-_stricmp_l-_wcsicmp_l-_mbsicmp_l"></a>_stricmp, _wcsicmp, _mbsicmp, _stricmp_l, _wcsicmp_l, _mbsicmp_l

Executa uma comparação que não diferencia maiúsculas de minúsculas na cadeia de caracteres.

> [!IMPORTANT]
> **_mbsicmp** e **_mbsicmp_l** não podem ser usados em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
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

### <a name="parameters"></a>Parâmetros

*string1,* *string2*<br/>
Cadeias de caracteres com terminação nula.

*Localidade*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor retornado

O valor de retorno indica a relação de *string1* com *string2* da seguinte forma.

|Valor retornado|Descrição|
|------------------|-----------------|
|< 0|*string1* menos que *string2*|
|0|*string1* idêntico à *string2*|
|> 0|*string1* maior que *string2*|

Em um erro, **_mbsicmp** retorna **_NLSCMPERROR**, que é definido em \<string.h> e \<mbstring.h>.

## <a name="remarks"></a>Comentários

A função **_stricmp** compara ordinally *string1* e *string2* depois de converter cada caractere em minúsculas, e retorna um valor indicando sua relação. **_stricmp** difere da **_stricoll,** na qual a comparação **_stricmp** só é afetada por **LC_CTYPE**, que determina quais caracteres são maiúsculas e minúsculas. A função **_stricoll** compara as cordas de acordo com as categorias **LC_CTYPE** e **LC_COLLATE** do local, o que inclui tanto o caso quanto a ordem de colagem. Para obter mais informações sobre a categoria **LC_COLLATE,** consulte [setlocale](setlocale-wsetlocale.md) e [Categorias Locais](../../c-runtime-library/locale-categories.md). As versões dessas funções sem o **sufixo _l** usam a localidade atual para comportamento dependente da localidade. As versões com o sufixo são idênticas, com exceção de que usam a localidade passada, em vez da localidade atual. Se a localidade não tiver sido definida, a localidade C será usada. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

> [!NOTE]
> **_stricmp** equivale a **_strcmpi.** Eles podem ser usados de forma intercambiável, mas **_stricmp** é o padrão preferido.

A função **_strcmpi** é equivalente a **_stricmp** e é fornecida apenas para compatibilidade retrógrada.

Como **_stricmp** faz comparações minúsculas, pode resultar em comportamento inesperado.

Para ilustrar quando a conversão de casos por **_stricmp** afeta o resultado de uma comparação, suponha que você tem as duas cordas JOHNSTON e JOHN_HENRY. A cadeia de caracteres JOHN_HENRY será considerada inferior a JOHNSTON porque "_" tem um valor de ASCII menor que um S minúsculo. Na verdade, qualquer caractere que tenha um valor de ASCII entre 91 e 96 será considerado menor do que qualquer letra.

Se a função [strcmp](strcmp-wcscmp-mbscmp.md) for usada em vez de **_stricmp,** JOHN_HENRY será maior que johnston.

**_wcsicmp** e **_mbsicmp** são versões de amplo caráter e multibytes de **_stricmp**. Os argumentos e o valor de retorno de **_wcsicmp** são strings de caracteres amplos; os de **_mbsicmp** são cordas de caracteres multibytes. **_mbsicmp** reconhece sequências de caracteres multibytes de acordo com a página de código multibyte atual e retorna **_NLSCMPERROR** em um erro. Para obter mais informações, consulte [Páginas de Código](../../c-runtime-library/code-pages.md). Caso contrário, essas três funções se comportam de forma idêntica.

**_wcsicmp** e **wcscmp** se comportam de forma idêntica, exceto que **o wcscmp** não converte seus argumentos em minúsculas antes de compará-los. **_mbsicmp** e **_mbscmp** se comportam de forma idêntica, exceto que **_mbscmp** não converte seus argumentos em minúsculas antes de compará-los.

Você precisará chamar [setlocale](setlocale-wsetlocale.md) para **_wcsicmp** trabalhar com caracteres latinos 1. A localidade C está em vigor por padrão, portanto, por exemplo, ä não será comparado como igual a Ä. Chamada **setlocale** com qualquer local que não seja o local C antes da chamada para **_wcsicmp**. A amostra a seguir demonstra como **_wcsicmp** é sensível ao local:

```C
// crt_stricmp_locale.c
By default, this function's global state is scoped to the application. To change this, see [Global state in the CRT](../global-state.md).

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

Uma alternativa é chamar [_create_locale, _wcreate_locale](create-locale-wcreate-locale.md) e passar o objeto local devolvido como parâmetro para **_wcsicmp_l**.

Todas essas funções validam seus parâmetros. Se as *string1* ou *string2* forem ponteiros nulos, o manipulador de parâmetros inválidos será invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md) . Se a execução continuar, essas funções retornam **_NLSCMPERROR** e definem **errno** para **EINVAL**.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcsicmp**|**_stricmp**|**_mbsicmp**|**_wcsicmp**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_stricmp** **_stricmp_l**|\<string.h>|
|**_wcsicmp,** **_wcsicmp_l.**|\<string.h> ou \<wchar.h>|
|**_mbsicmp,** **_mbsicmp_l.**|\<mbstring.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
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

## <a name="see-also"></a>Confira também

[Manipulação de cordas](../../c-runtime-library/string-manipulation-crt.md)<br/>
[memcmp, wmemcmp](memcmp-wmemcmp.md)<br/>
[_memicmp, _memicmp_l](memicmp-memicmp-l.md)<br/>
[strcmp, wcscmp, _mbscmp](strcmp-wcscmp-mbscmp.md)<br/>
[Funções strcoll](../../c-runtime-library/strcoll-functions.md)<br/>
[strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)<br/>
[_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l](strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)<br/>
[strrchr, wcsrchr, _mbsrchr, _mbsrchr_l](strrchr-wcsrchr-mbsrchr-mbsrchr-l.md)<br/>
[_strset, _strset_l, _wcsset, _wcsset_l, _mbsset, _mbsset_l](strset-strset-l-wcsset-wcsset-l-mbsset-mbsset-l.md)<br/>
[strspn, wcsspn, _mbsspn, _mbsspn_l](strspn-wcsspn-mbsspn-mbsspn-l.md)<br/>
