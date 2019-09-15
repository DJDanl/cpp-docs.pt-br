---
title: strcmp, wcscmp, _mbscmp, _mbscmp_l
ms.date: 01/22/2019
api_name:
- wcscmp
- _mbscmp
- _mbscmp_l
- strcmp
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
ms.openlocfilehash: 4bef0c61122e93bd45bc0d1238030743f1196d9e
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70957968"
---
# <a name="strcmp-wcscmp-_mbscmp-_mbscmp_l"></a>strcmp, wcscmp, _mbscmp, _mbscmp_l

Compare cadeias de caracteres.

> [!IMPORTANT]
> **_mbscmp** e **_mbscmp_l** não podem ser usados em aplicativos que são executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

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

*string1*, *string2*<br/>
Cadeias de caracteres com terminação nula.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

O valor de retorno para cada uma dessas funções indica a relação ordinal de *seqüência1* para *seqüência2*.

|Valor|Relação da string1 com a string2|
|-----------|----------------------------------------|
|< 0|*seqüência1* é menor que *seqüência2*|
|0|*seqüência1* é idêntico a *seqüência2*|
|> 0|*seqüência1* é maior que *seqüência2*|

Em um erro de validação de parâmetro, **_mbscmp** e **_mbscmp_l** retornam **_NLSCMPERROR**, que \<é definido em String. \<h > e Mbstring. h >.

## <a name="remarks"></a>Comentários

A função **strcmp** executa uma comparação ordinal de *seqüência1* e *seqüência2* e retorna um valor que indica sua relação. **wcscmp** e **_mbscmp** são, respectivamente, as versões de caractere largo e de multibyte de **strcmp**. o **_mbscmp** reconhece sequências de caracteres multibyte de acordo com a página de código multibyte atual e retorna **_NLSCMPERROR** em um erro. **_mbscmp_l** tem o mesmo comportamento, mas usa o parâmetro Locale que é passado em vez da localidade atual. Para obter mais informações, consulte [Páginas de Código](../../c-runtime-library/code-pages.md). Além disso, se *seqüência1* ou *seqüência2* for um ponteiro nulo, **_mbscmp** invocará o manipulador de parâmetro inválido, conforme descrito em validação de [parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, **_mbscmp** e **_mbscmp_l** retornará **_NLSCMPERROR** e definir **errno** como **EINVAL**. **strcmp** e **wcscmp** não validam seus parâmetros. Caso contrário, essas funções se comportam de forma idêntica.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcscmp**|**strcmp**|**_mbscmp**|**wcscmp**|

As funções **strcmp** diferem das funções **strcoll** no que as comparações de **strcmp** são ordinais e não são afetadas pela localidade. **strcoll** compara Cadeias de caracteres modo lexicográfico usando a categoria **LC_COLLATE** da localidade atual. Para obter mais informações sobre a categoria **LC_COLLATE** , consulte [setlocale, _wsetlocale](setlocale-wsetlocale.md).

Na localidade "C", a ordem de caracteres no conjunto de caracteres (conjunto de caracteres ASCII) é a mesma que a ordem lexicográfica de caracteres. No entanto, em outras localidades, a ordem de caracteres no conjunto de caracteres pode ser diferente da ordem lexicográfica. Por exemplo, em algumas localidades europeias, o caractere 'a' (valor 0x61) precede o caractere 'ä' (valor 0xE4) no conjunto de caracteres, mas o caractere 'ä' precede a caractere 'a' lexicograficamente.

Em localidades para as quais o conjunto de caracteres e a ordem de caracteres lexicográfica são diferentes, você pode usar **strcoll** em vez de **strcmp** para comparação lexicográfica de cadeias de caracteres. Como alternativa, você pode usar **strxfrm** nas cadeias de caracteres originais e, em seguida, usar **strcmp** nas cadeias de caracteres resultantes.

As funções **strcmp** diferenciam maiúsculas de minúsculas. stricmp, **wcsicmp e\_** **mbsicmp comparamcadeiasdecaracteresconvertendo-osprimeiro\_** em seus formulários em minúsculas.  **\_** Duas cadeias que contêm caracteres que estão localizados entre ' Z ' e ' a ' na tabela ASCII (' [', '\\', '] ', ' ^ ', ' _ ' e '\`') se comparam de forma diferente, dependendo de seu caso. Por exemplo, as duas cadeias de caracteres "ABCDE" e "ABCD ^" comparam uma maneira se a comparação for minúscula ("ABCDE" > "abcd ^") e a outra maneira ("ABCDE" < "ABCD ^") se a comparação for maiúscula.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strcmp**|\<string.h>|
|**wcscmp**|\<string.h> ou \<wchar.h>|
|**_mbscmp**|\<mbstring.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

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

## <a name="see-also"></a>Consulte também

[Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[memcmp, wmemcmp](memcmp-wmemcmp.md)<br/>
[_memicmp, _memicmp_l](memicmp-memicmp-l.md)<br/>
[Funções strcoll](../../c-runtime-library/strcoll-functions.md)<br/>
[_stricmp, _wcsicmp, _mbsicmp, _stricmp_l, _wcsicmp_l, _mbsicmp_l](stricmp-wcsicmp-mbsicmp-stricmp-l-wcsicmp-l-mbsicmp-l.md)<br/>
[strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)<br/>
[_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l](strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)<br/>
[strrchr, wcsrchr, _mbsrchr, _mbsrchr_l](strrchr-wcsrchr-mbsrchr-mbsrchr-l.md)<br/>
[strspn, wcsspn, _mbsspn, _mbsspn_l](strspn-wcsspn-mbsspn-mbsspn-l.md)<br/>
[strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l](strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)<br/>
