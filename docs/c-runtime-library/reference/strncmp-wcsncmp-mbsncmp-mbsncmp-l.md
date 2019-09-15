---
title: strncmp, wcsncmp, _mbsncmp, _mbsncmp_l
ms.date: 11/04/2016
api_name:
- strncmp
- _mbsncmp
- wcsncmp
- _mbsncmp_l
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
- _ftcsnccmp
- _ftcsncmp
- _tcsncmp
- _tcsnccmp
- strncmp
- _mbsncmp
- wcsncmp
helpviewer_keywords:
- _tcsnccmp function
- ftcsncmp function
- wcsncmp function
- _ftcsncmp function
- _mbsncmp function
- tcsncmp function
- mbsncmp function
- _mbsncmp_l function
- mbsncmp_l function
- strncmp function
- strings [C++], comparing characters of
- string comparison [C++], strncmp function
- _tcsncmp function
- tcsnccmp function
- ftcsnccmp function
- characters [C++], comparing
- _ftcsnccmp function
ms.assetid: 2fdbf4e6-77da-4b59-9086-488f6066b8af
ms.openlocfilehash: 597db3825d1d6165fb6bd4b98b8d469ea8947b59
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70947339"
---
# <a name="strncmp-wcsncmp-_mbsncmp-_mbsncmp_l"></a>strncmp, wcsncmp, _mbsncmp, _mbsncmp_l

Compara até a contagem especificada de caracteres de duas cadeias de caracteres.

> [!IMPORTANT]
> **_mbsncmp** e **_mbsncmp_l** não podem ser usados em aplicativos que são executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int strncmp(
   const char *string1,
   const char *string2,
   size_t count
);
int wcsncmp(
   const wchar_t *string1,
   const wchar_t *string2,
   size_t count
);
int _mbsncmp(
   const unsigned char *string1,
   const unsigned char *string2,
   size_t count
);
int _mbsncmp_l(
   const unsigned char *string1,
   const unsigned char *string2,
   size_t count,
   _locale_t locale
);int _mbsnbcmp(
   const unsigned char *string1,
   const unsigned char *string2,
   size_t count
);
```

### <a name="parameters"></a>Parâmetros

*string1*, *string2*<br/>
Cadeias de caracteres a serem comparadas.

*count*<br/>
O número de caracteres a serem comparados.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

O valor de retorno indica a relação das subcadeias de caracteres de *seqüência1* e *seqüência2* da seguinte maneira.

|Valor retornado|Descrição|
|------------------|-----------------|
|< 0|Subcadeia de caracteres *seqüência1* menor que a subcadeia de *seqüência2*|
|0|Subcadeia de caracteres *seqüência1* idêntica à Subcadeia *seqüência2*|
|> 0|Subcadeia de caracteres de *seqüência1* maior que a subcadeia de *seqüência2*|

Em um erro de validação de parâmetro, **_mbsncmp** e **_mbsncmp_l** retornam **_NLSCMPERROR**, que \<é definido em String. \<h > e Mbstring. h >.

## <a name="remarks"></a>Comentários

A função **strncmp** executa uma comparação ordinal de, no máximo, os primeiros caracteres de *contagem* em *seqüência1* e *seqüência2* e retorna um valor que indica a relação entre as subcadeias de caracteres. **strncmp** é uma versão com diferenciação de maiúsculas e minúsculas do **_strnicmp**. **wcsncmp** e **_mbsncmp** são versões com diferenciação de maiúsculas e minúsculas do **_wcsnicmp** e do **_mbsnicmp**.

**wcsncmp** e **_mbsncmp** são versões de caractere largo e de multibyte de **strncmp**. Os argumentos de **wcsncmp** são cadeias de caracteres largos; os de **_mbsncmp** são cadeias de caracteres multibyte. o **_mbsncmp** reconhece sequências de caracteres multibyte de acordo com uma página de código multibyte e retorna **_NLSCMPERROR** em um erro.

Além disso, **_mbsncmp** e **_mbsncmp_l** validam parâmetros. Se *string1* ou *seqüência2* for um ponteiro NULL, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, **_mbsncmp** e **_mbsncmp_l** retornará **_NLSCMPERROR** e definir **errno** como **EINVAL**. **strncmp** e **wcsncmp** não validam seus parâmetros. Caso contrário, essas funções se comportam de forma idêntica.

O comportamento de comparação de **_mbsncmp** e **_mbsncmp_l** é afetado pela definição da configuração de categoria **LC_CTYPE** da localidade. Isso controla a detecção de bytes à esquerda e à direita de caracteres multibyte. Para obter mais informações sobre, consulte [setlocale](setlocale-wsetlocale.md). A função **_mbsncmp** usa a localidade atual para esse comportamento dependente de localidade. A função **_mbsncmp_l** é idêntica, exceto pelo fato de usar o parâmetro *locale* em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md). Se a localidade for uma localidade de byte único, o comportamento dessas funções será idêntico a **strncmp**.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcsnccmp**|**strncmp**|**_mbsncmp**|**wcsncmp**|
|**_tcsncmp**|**strncmp**|**_mbsnbcmp**|**wcsncmp**|
|**_tccmp**|É mapeado para um macro ou uma função embutida|**_mbsncmp**|É mapeado para um macro ou uma função embutida|
|**não aplicável**|**não aplicável**|**_mbsncmp_l**|**não aplicável**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strncmp**|\<string.h>|
|**wcsncmp**|\<string.h> ou \<wchar.h>|
|**_mbsncmp**, **_mbsncmp_l**|\<mbstring.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_strncmp.c
#include <string.h>
#include <stdio.h>

char string1[] = "The quick brown dog jumps over the lazy fox";
char string2[] = "The QUICK brown fox jumps over the lazy dog";

int main( void )
{
   char tmp[20];
   int result;
   printf( "Compare strings:\n      %s\n      %s\n\n",
           string1, string2 );
   printf( "Function:   strncmp (first 10 characters only)\n" );
   result = strncmp( string1, string2 , 10 );
   if( result > 0 )
      strcpy_s( tmp, sizeof(tmp), "greater than" );
   else if( result < 0 )
      strcpy_s( tmp, sizeof(tmp), "less than" );
   else
      strcpy_s( tmp, sizeof(tmp), "equal to" );
   printf( "Result:      String 1 is %s string 2\n\n", tmp );
   printf( "Function:   strnicmp _strnicmp (first 10 characters only)\n" );
   result = _strnicmp( string1, string2, 10 );
   if( result > 0 )
      strcpy_s( tmp, sizeof(tmp), "greater than" );
   else if( result < 0 )
      strcpy_s( tmp, sizeof(tmp), "less than" );
   else
      strcpy_s( tmp, sizeof(tmp), "equal to" );
   printf( "Result:      String 1 is %s string 2\n", tmp );
}
```

```Output
Compare strings:
      The quick brown dog jumps over the lazy fox
      The QUICK brown fox jumps over the lazy dog

Function:   strncmp (first 10 characters only)
Result:      String 1 is greater than string 2

Function:   strnicmp _strnicmp (first 10 characters only)
Result:      String 1 is equal to string 2
```

## <a name="see-also"></a>Consulte também

[Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[_mbsnbcmp, _mbsnbcmp_l](mbsnbcmp-mbsnbcmp-l.md)<br/>
[_mbsnbicmp, _mbsnbicmp_l](mbsnbicmp-mbsnbicmp-l.md)<br/>
[strcmp, wcscmp, _mbscmp](strcmp-wcscmp-mbscmp.md)<br/>
[Funções strcoll](../../c-runtime-library/strcoll-functions.md)<br/>
[_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l](strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)<br/>
[strrchr, wcsrchr, _mbsrchr, _mbsrchr_l](strrchr-wcsrchr-mbsrchr-mbsrchr-l.md)<br/>
[_strset, _strset_l, _wcsset, _wcsset_l, _mbsset, _mbsset_l](strset-strset-l-wcsset-wcsset-l-mbsset-mbsset-l.md)<br/>
[strspn, wcsspn, _mbsspn, _mbsspn_l](strspn-wcsspn-mbsspn-mbsspn-l.md)<br/>
