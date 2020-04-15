---
title: strcmp, wcscmp, _mbscmp, _mbscmp_l
ms.date: 4/2/2020
api_name:
- wcscmp
- _mbscmp
- _mbscmp_l
- strcmp
- _o__mbscmp
- _o__mbscmp_l
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
- ntdll.dll
- ucrtbase.dll
- api-ms-win-crt-multibyte-l1-1-0.dll
- api-ms-win-crt-string-l1-1-0.dll
- ntoskrnl.exe
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _mbscmp
- _mbscmp_l
- wcscmp
- strcmp
- _tcscmp
- _ftcscmp
helpviewer_keywords:
- tcscmp function
- strcmp function
- strings [C++], comparing
- mbscmp function
- string comparison [C++]
- _mbscmp function
- _mbscmp_l function
- wcscmp function
- _tcscmp function
- _ftcscmp function
- ftcscmp function
ms.assetid: 5d216b57-7a5c-4cb3-abf0-0f4facf4396d
ms.openlocfilehash: 16bb294f7bbdc0b95b59b845d7b714f823f9d962
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81357279"
---
# <a name="strcmp-wcscmp-_mbscmp-_mbscmp_l"></a>strcmp, wcscmp, _mbscmp, _mbscmp_l

Compare cadeias de caracteres.

> [!IMPORTANT]
> **_mbscmp** e **_mbscmp_l** não podem ser usados em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int strcmp(
   const char *string1,
   const char *string2
);
int wcscmp(
   const wchar_t *string1,
   const wchar_t *string2
);
int _mbscmp(
   const unsigned char *string1,
   const unsigned char *string2
);
int _mbscmp_l(
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

O valor de retorno para cada uma dessas funções indica a relação ordinal de *string1* para *string2*.

|Valor|Relação da string1 com a string2|
|-----------|----------------------------------------|
|< 0|*string1* é menor que *string2*|
|0|*string1* é idêntico a *string2*|
|> 0|*string1* é maior que *string2*|

Em um erro de validação de parâmetros, **_mbscmp** e **_mbscmp_l** \<retorno **_NLSCMPERROR**, que é definido em \<string.h> e mbstring.h>.

## <a name="remarks"></a>Comentários

A função **strcmp** realiza uma comparação ordinal de *string1* e *string2* e retorna um valor que indica sua relação. **wcscmp** e **_mbscmp** são, respectivamente, versões de amplo caráter e multibyte-caracteres de **strcmp**. **_mbscmp** reconhece sequências de caracteres multibytes de acordo com a página de código multibyte atual e retorna **_NLSCMPERROR** em um erro. **_mbscmp_l** tem o mesmo comportamento, mas usa o parâmetro local que é passado em vez do local atual. Para obter mais informações, consulte [Páginas de Código](../../c-runtime-library/code-pages.md). Além disso, se *string1* ou *string2* for um ponteiro nulo, **_mbscmp** invoca o manipulador de parâmetros inválido, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **_mbscmp** e **_mbscmp_l** retornar **_NLSCMPERROR** e definir **errno** ao **EINVAL**. **strcmp** e **wcscmp** não validam seus parâmetros. Caso contrário, essas funções se comportam de forma idêntica.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcscmp**|**Strcmp**|**_mbscmp**|**wcscmp**|

As funções **de strcmp** diferem das funções **de strcoll** em que as comparações **de strcmp** são ordinárias, e não são afetadas pela localidade. **strcoll** compara as cordas lexicograficamente usando a categoria **LC_COLLATE** da localidade atual. Para obter mais informações sobre a categoria **LC_COLLATE,** consulte [setlocale, _wsetlocale](setlocale-wsetlocale.md).

Na localidade "C", a ordem de caracteres no conjunto de caracteres (conjunto de caracteres ASCII) é a mesma que a ordem lexicográfica de caracteres. No entanto, em outras localidades, a ordem de caracteres no conjunto de caracteres pode ser diferente da ordem lexicográfica. Por exemplo, em algumas localidades europeias, o caractere 'a' (valor 0x61) precede o caractere 'ä' (valor 0xE4) no conjunto de caracteres, mas o caractere 'ä' precede a caractere 'a' lexicograficamente.

Em locais para os quais o conjunto de caracteres e a ordem de caracteres lexicográficos diferem, você pode usar **strcoll** em vez de **strcmp** para comparação lexicográfica de strings. Alternativamente, você pode usar **strxfrm** nas strings originais e, em seguida, usar **strcmp** nas strings resultantes.

As **funções de strcmp** são sensíveis a maiúsculas e minúsculas. stricmp , ** \_wcsicmp**e ** \_mbsicmp** comparam as cordas convertendo-as primeiro em suas formas minúsculas. ** \_** Duas cordas que contêm caracteres que estão localizados entre 'Z' e 'a'\\na tabela ASCII ('[', ''', ''', '^', '_', '_', e '\`'' ' ' comparar de forma diferente, dependendo do seu caso. Por exemplo, as duas cordas "ABCDE" e "ABCD^" comparam-se de uma maneira se a comparação for minúscula ("abcde" > "abcd^") e a outra ("ABCDE" < "ABCD^") se a comparação for maiúscula.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**Strcmp**|\<string.h>|
|**wcscmp**|\<string.h> ou \<wchar.h>|
|**_mbscmp**|\<mbstring.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Bibliotecas

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

```C
// crt_strcmp.c

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
      strcpy_s( tmp, _countof (tmp), "less than" );
   else
      strcpy_s( tmp, _countof (tmp), "equal to" );
   printf( "   strcmp:   String 1 is %s string 2\n", tmp );

   // Case insensitive (could use equivalent _stricmp)
   result = _stricmp( string1, string2 );
   if( result > 0 )
      strcpy_s( tmp, _countof (tmp), "greater than" );
   else if( result < 0 )
      strcpy_s( tmp, _countof (tmp), "less than" );
   else
      strcpy_s( tmp, _countof (tmp), "equal to" );
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
[Funções strcoll](../../c-runtime-library/strcoll-functions.md)<br/>
[_stricmp, _wcsicmp, _mbsicmp, _stricmp_l, _wcsicmp_l, _mbsicmp_l](stricmp-wcsicmp-mbsicmp-stricmp-l-wcsicmp-l-mbsicmp-l.md)<br/>
[strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)<br/>
[_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l](strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)<br/>
[strrchr, wcsrchr, _mbsrchr, _mbsrchr_l](strrchr-wcsrchr-mbsrchr-mbsrchr-l.md)<br/>
[strspn, wcsspn, _mbsspn, _mbsspn_l](strspn-wcsspn-mbsspn-mbsspn-l.md)<br/>
[strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l](strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)<br/>
