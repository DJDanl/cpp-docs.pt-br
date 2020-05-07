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
- api-ms-win-crt-private-l1-1-0.dll
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
ms.openlocfilehash: 786c2bd2738bb82b3edac5c811ccfd3f9f8bc854
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82920003"
---
# <a name="_stricmp-_wcsicmp-_mbsicmp-_stricmp_l-_wcsicmp_l-_mbsicmp_l"></a>_stricmp, _wcsicmp, _mbsicmp, _stricmp_l, _wcsicmp_l, _mbsicmp_l

Executa uma comparação que não diferencia maiúsculas de minúsculas na cadeia de caracteres.

> [!IMPORTANT]
> **_mbsicmp** e **_mbsicmp_l** não podem ser usados em aplicativos que são executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

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

*seqüência1*, *seqüência2*<br/>
Cadeias de caracteres com terminação nula.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor retornado

O valor de retorno indica a relação de *seqüência1* para *string2* da seguinte maneira.

|Valor retornado|Descrição|
|------------------|-----------------|
|< 0|*seqüência1* menor que *seqüência2*|
|0|*seqüência1* idêntico a *seqüência2*|
|> 0|*seqüência1* maior que *seqüência2*|

Em um erro, **_mbsicmp** retorna **_NLSCMPERROR**, que é definido em \<String. h> e \<mbstring. h>.

## <a name="remarks"></a>Comentários

A função **_stricmp** , em seguida, compara *seqüência1* e *seqüência2* depois de converter cada caractere em minúsculas e retorna um valor que indica sua relação. **_stricmp** difere de **_stricoll** no que a comparação de **_stricmp** só é afetada pelo **LC_CTYPE**, que determina quais caracteres são letras maiúsculas e minúsculas. A função **_stricoll** compara Cadeias de caracteres de acordo com as categorias **LC_CTYPE** e **LC_COLLATE** da localidade, que inclui o caso e a ordem de agrupamento. Para obter mais informações sobre **LC_COLLATE** a categoria de LC_COLLATE [, consulte categorias de local e](setlocale-wsetlocale.md) de [localidade](../../c-runtime-library/locale-categories.md). As versões dessas funções sem o sufixo **_L** usam a localidade atual para o comportamento dependente de localidade. As versões com o sufixo são idênticas, com exceção de que usam a localidade passada, em vez da localidade atual. Se a localidade não tiver sido definida, a localidade C será usada. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

> [!NOTE]
> **_stricmp** é equivalente a **_strcmpi**. Eles podem ser usados de forma intercambiável, mas **_stricmp** é o padrão preferencial.

A função **_strcmpi** é equivalente a **_stricmp** e é fornecida somente para fins de compatibilidade com versões anteriores.

Como **_stricmp** faz comparações em minúsculas, isso pode resultar em um comportamento inesperado.

Para ilustrar quando a conversão de maiúsculas e minúsculas por **_stricmp** afeta o resultado de uma comparação, suponha que você tenha as duas cadeias de caracteres JOHNSTON e JOHN_HENRY. A cadeia de caracteres JOHN_HENRY será considerada inferior a JOHNSTON porque "_" tem um valor de ASCII menor que um S minúsculo. Na verdade, qualquer caractere que tenha um valor de ASCII entre 91 e 96 será considerado menor do que qualquer letra.

Se a função [strcmp](strcmp-wcscmp-mbscmp.md) for usada em vez de **_stricmp**, JOHN_HENRY será maior que Johnston.

**_wcsicmp** e **_mbsicmp** são versões de caractere largo e de vários caracteres de **_stricmp**. Os argumentos e o valor de retorno de **_wcsicmp** são cadeias de caracteres largos; os de **_mbsicmp** são cadeias de caracteres multibyte. **_mbsicmp** reconhece seqüências de caracteres multibyte de acordo com a página de código multibyte atual e retorna **_NLSCMPERROR** em um erro. Para obter mais informações, consulte [Páginas de Código](../../c-runtime-library/code-pages.md). Caso contrário, essas três funções se comportam de forma idêntica.

**_wcsicmp** e **wcscmp** se comportam de forma idêntica, exceto que **wcscmp** não converte seus argumentos em minúsculas antes de compará-los. **_mbsicmp** e **_mbscmp** se comportam de forma idêntica, exceto que **_mbscmp** não converte seus argumentos em minúsculas antes de compará-los.

Você precisará chamar [setlocaling](setlocale-wsetlocale.md) para que **_wcsicmp** funcionem com Latin 1 caracteres. A localidade C está em vigor por padrão, portanto, por exemplo, ä não será comparado como igual a Ä. Chame **setlocale** com qualquer localidade diferente da localidade C antes da chamada para **_wcsicmp**. O exemplo a seguir demonstra como **_wcsicmp** é sensível à localidade:

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

Uma alternativa é chamar [_create_locale, _wcreate_locale](create-locale-wcreate-locale.md) e passar o objeto de localidade retornado como um parâmetro para **_wcsicmp_l**.

Todas essas funções validam seus parâmetros. Se *seqüência1* ou *seqüência2* forem ponteiros nulos, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md) . Se a execução puder continuar, essas funções retornarão **_NLSCMPERROR** e definirá **errno** como **EINVAL**.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcsicmp**|**_stricmp**|**_mbsicmp**|**_wcsicmp**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_stricmp**, **_stricmp_l**|\<string.h>|
|**_wcsicmp**, **_wcsicmp_l**|\<string.h> ou \<wchar.h>|
|**_mbsicmp**, **_mbsicmp_l**|\<mbstring.h>|

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

[Manipulação de cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[memcmp, wmemcmp](memcmp-wmemcmp.md)<br/>
[_memicmp, _memicmp_l](memicmp-memicmp-l.md)<br/>
[strcmp, wcscmp, _mbscmp](strcmp-wcscmp-mbscmp.md)<br/>
[Funções strcoll](../../c-runtime-library/strcoll-functions.md)<br/>
[strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)<br/>
[_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l](strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)<br/>
[strrchr, wcsrchr, _mbsrchr, _mbsrchr_l](strrchr-wcsrchr-mbsrchr-mbsrchr-l.md)<br/>
[_strset, _strset_l, _wcsset, _wcsset_l, _mbsset, _mbsset_l](strset-strset-l-wcsset-wcsset-l-mbsset-mbsset-l.md)<br/>
[strspn, wcsspn, _mbsspn, _mbsspn_l](strspn-wcsspn-mbsspn-mbsspn-l.md)<br/>
