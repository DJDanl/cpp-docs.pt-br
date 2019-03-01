---
title: strncmp, wcsncmp, _mbsncmp, _mbsncmp_l
ms.date: 11/04/2016
apiname:
- strncmp
- _mbsncmp
- wcsncmp
- _mbsncmp_l
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
- ntdll.dll
- ucrtbase.dll
- api-ms-win-crt-multibyte-l1-1-0.dll
- api-ms-win-crt-string-l1-1-0.dll
- ntoskrnl.exe
apitype: DLLExport
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
ms.openlocfilehash: 8f022dec6c161814ade5c6be5aaccfcd239a4af4
ms.sourcegitcommit: e06648107065f3dea35f40c1ae5999391087b80b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/01/2019
ms.locfileid: "57210907"
---
# <a name="strncmp-wcsncmp-mbsncmp-mbsncmpl"></a>strncmp, wcsncmp, _mbsncmp, _mbsncmp_l

Compara até a contagem especificada de caracteres de duas cadeias de caracteres.

> [!IMPORTANT]
> **mbsncmp** e **mbsncmp_l** não pode ser usado em aplicativos executados no tempo de execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

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

O valor retornado indica a relação das subcadeias de caracteres de *string1* e *string2* da seguinte maneira.

|Valor retornado|Descrição|
|------------------|-----------------|
|< 0|*string1* subcadeia de caracteres menor que *string2* subcadeia de caracteres|
|0|*string1* subcadeia de caracteres idêntica à *string2* subcadeia de caracteres|
|> 0|*string1* subcadeia de caracteres maior que *string2* subcadeia de caracteres|

Em um erro de validação de parâmetro, **mbsncmp** e **mbsncmp_l** retornar **_NLSCMPERROR**, que é definido no \<String. h > e \< mbstring >.

## <a name="remarks"></a>Comentários

O **strncmp** função executa uma comparação ordinal de no máximo os primeiros *contagem* caracteres *string1* e *string2* e Retorna um valor que indica a relação entre as subcadeias de caracteres. **strncmp** é uma versão diferencia maiusculas de minúsculas **strnicmp**. **wcsncmp** e **mbsncmp** são versões diferencia maiusculas de minúsculas de **wcsnicmp** e **mbsnicmp**.

**wcsncmp** e **mbsncmp** são versões de caractere largo e caracteres multibyte **strncmp**. Os argumentos de **wcsncmp** são largos cadeias de caracteres; aqueles de **mbsncmp** são cadeias de caracteres multibyte. **mbsncmp** reconhece sequências de caracteres multibyte de acordo com uma página de código multibyte e retorna **_NLSCMPERROR** em um erro.

Além disso, **mbsncmp** e **mbsncmp_l** validar parâmetros. Se *string1* ou *string2* é um ponteiro nulo, o manipulador de parâmetro inválido será invocado, conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **mbsncmp** e **mbsncmp_l** retornar **_NLSCMPERROR** e defina **errno** para  **EINVAL**. **strncmp** e **wcsncmp** não validam seus parâmetros. Caso contrário, essas funções se comportam de forma idêntica.

O comportamento da comparação de **mbsncmp** e **mbsncmp_l** é afetada pela configuração da **LC_CTYPE** configuração de categoria da localidade. Isso controla a detecção de bytes à esquerda e à direita de caracteres multibyte. Para obter mais informações sobre, consulte [setlocale](setlocale-wsetlocale.md). O **mbsncmp** função usa a localidade atual desse comportamento dependente da localidade. O **mbsncmp_l** função é idêntica, exceto que ele usa o *localidade* parâmetro em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md). Se a localidade é um byte único, o comportamento dessas funções é idêntico ao **strncmp**.

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
