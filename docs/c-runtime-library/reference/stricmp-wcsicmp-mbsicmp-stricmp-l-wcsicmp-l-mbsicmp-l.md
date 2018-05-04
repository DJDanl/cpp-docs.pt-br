---
title: _stricmp, _wcsicmp, _mbsicmp, _stricmp_l, _wcsicmp_l, _mbsicmp_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0014ea3c727db2a368123696c47df1eca6ba3bb4
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="stricmp-wcsicmp-mbsicmp-stricmpl-wcsicmpl-mbsicmpl"></a>_stricmp, _wcsicmp, _mbsicmp, _stricmp_l, _wcsicmp_l, _mbsicmp_l

Executa uma comparação que não diferencia maiúsculas de minúsculas na cadeia de caracteres.

> [!IMPORTANT]
> **mbsicmp** e **mbsicmp_l** não pode ser usado em aplicativos que são executados o tempo de execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

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

*string1*, *string2*<br/>
Cadeias de caracteres com terminação nula.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

O valor de retorno indica a relação de *string1* para *string2* da seguinte maneira.

|Valor retornado|Descrição|
|------------------|-----------------|
|< 0|*string1* menor *string2*|
|0|*string1* idêntico ao *string2*|
|> 0|*string1* maior *string2*|

Em um erro, **mbsicmp** retorna **_NLSCMPERROR**, que é definido em \<string.h > e \<mbstring.h >.

## <a name="remarks"></a>Comentários

O **stricmp** ordinalmente função compara *string1* e *string2* depois de converter cada caractere em minúsculas e retorna um valor que indica sua relação. **stricmp** difere **stricoll** em que o **stricmp** comparação será afetada somente por **LC_CTYPE**, que determina quais caracteres são superiores e letras minúsculas. O **stricoll** função compara cadeias de caracteres de acordo com ambos os **LC_CTYPE** e **LC_COLLATE** categorias de localidade, que inclui o caso e o agrupamento ordem. Para obter mais informações sobre o **LC_COLLATE** categoria, consulte [setlocale](setlocale-wsetlocale.md) e [categorias de localidade](../../c-runtime-library/locale-categories.md). As versões dessas funções sem o **_l** sufixo usam a localidade atual para o comportamento dependente de localidade. As versões com o sufixo são idênticas, com exceção de que usam a localidade passada, em vez da localidade atual. Se a localidade não tiver sido definida, a localidade C será usada. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

> [!NOTE]
> **stricmp** é equivalente a **strcmpi**. Eles podem ser usados alternadamente mas **stricmp** é o padrão preferencial.

O **strcmpi** função é equivalente a **stricmp** e é fornecida para compatibilidade com versões anteriores apenas.

Porque **stricmp** minúsculas comparações, isso pode resultar em comportamento inesperado.

Para ilustrar quando caso a conversão por **stricmp** afeta o resultado de uma comparação, suponha que você tenha duas cadeias de caracteres JOHNSTON e JOHN_HENRY. A cadeia de caracteres JOHN_HENRY será considerada inferior a JOHNSTON porque "_" tem um valor de ASCII menor que um S minúsculo. Na verdade, qualquer caractere que tenha um valor de ASCII entre 91 e 96 será considerado menor do que qualquer letra.

Se o [strcmp](strcmp-wcscmp-mbscmp.md) função é usada em vez de **stricmp**, JOHN_HENRY será maior JOHNSTON.

**wcsicmp** e **mbsicmp** são versões de caracteres largos e caracteres multibyte **stricmp**. O valor de retorno e argumentos **wcsicmp** são caracteres largos cadeias de caracteres; desses **mbsicmp** são cadeias de caracteres multibyte. **mbsicmp** reconhece sequências de caracteres multibyte de acordo com a página de código multibyte atual e retorna **_NLSCMPERROR** em um erro. Para obter mais informações, consulte [Páginas de Código](../../c-runtime-library/code-pages.md). Caso contrário, essas três funções se comportam de forma idêntica.

**wcsicmp** e **wcscmp** tenham comportamento idêntico, exceto que **wcscmp** não converte os argumentos em minúsculas antes de compará-los. **mbsicmp** e **mbscmp** tenham comportamento idêntico, exceto que **mbscmp** não converte os argumentos em minúsculas antes de compará-los.

Você precisará chamar [setlocale](setlocale-wsetlocale.md) para **wcsicmp** para funcionar com caracteres Latin 1. A localidade C está em vigor por padrão, portanto, por exemplo, ä não será comparado como igual a Ä. Chamar **setlocale** com qualquer localidade que não seja a localidade C antes da chamada para **wcsicmp**. O exemplo a seguir demonstra como **wcsicmp** é sensível a localidade:

```C
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

Uma alternativa é chamar [create_locale, _wcreate_locale](create-locale-wcreate-locale.md) e passe o objeto de localidade retornado como um parâmetro para **wcsicmp_l**.

Todas essas funções validam seus parâmetros. Se qualquer um dos *string1* ou *string2* são ponteiros nulos, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md) . Se a execução é permitida para continuar, essas funções retornam **_NLSCMPERROR** e defina **errno** para **EINVAL**.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tcsicmp**|**_stricmp**|**_mbsicmp**|**_wcsicmp**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**stricmp**, **stricmp_l**|\<string.h>|
|**wcsicmp**, **wcsicmp_l**|\<string.h> ou \<wchar.h>|
|**mbsicmp**, **mbsicmp_l**|\<mbstring.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Consulte também

[Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[memcmp, wmemcmp](memcmp-wmemcmp.md)<br/>
[_memicmp, _memicmp_l](memicmp-memicmp-l.md)<br/>
[strcmp, wcscmp, _mbscmp](strcmp-wcscmp-mbscmp.md)<br/>
[Funções strcoll](../../c-runtime-library/strcoll-functions.md)<br/>
[strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)<br/>
[_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l](strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)<br/>
[strrchr, wcsrchr, _mbsrchr, _mbsrchr_l](strrchr-wcsrchr-mbsrchr-mbsrchr-l.md)<br/>
[_strset, _strset_l, _wcsset, _wcsset_l, _mbsset, _mbsset_l](strset-strset-l-wcsset-wcsset-l-mbsset-mbsset-l.md)<br/>
[strspn, wcsspn, _mbsspn, _mbsspn_l](strspn-wcsspn-mbsspn-mbsspn-l.md)<br/>
