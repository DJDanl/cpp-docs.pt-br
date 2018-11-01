---
title: _mbsnbcmp, _mbsnbcmp_l
ms.date: 11/04/2016
apiname:
- _mbsnbcmp
- _mbsnbcmp_l
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
- mbsnbcmp
- tcsnbmp
- _mbsnbcmp_l
- mbsnbcmp_l
- _mbsnbcmp
helpviewer_keywords:
- mbsnbcmp_l function
- mbsnbcmp function
- tcsncmp function
- _mbsnbcmp_l function
- _tcsncmp function
- _mbsnbcmp function
ms.assetid: dbc99e50-cf85-4e57-a13f-067591f18ac8
ms.openlocfilehash: 4b21fde122f9804633ac037efaf1f343b5cb9440
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50619993"
---
# <a name="mbsnbcmp-mbsnbcmpl"></a>_mbsnbcmp, _mbsnbcmp_l

Compara os primeiros **n** bytes de duas cadeias de caracteres multibyte.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int _mbsnbcmp(
   const unsigned char *string1,
   const unsigned char *string2,
   size_t count
);
int _mbsnbcmp_l(
   const unsigned char *string1,
   const unsigned char *string2,
   size_t count,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*string1*, *string2*<br/>
As cadeias de caracteres a serem comparadas.

*count*<br/>
O número de bytes a serem comparados.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor de retorno

O valor retornado indica a relação ordinal entre as subcadeias de caracteres de *string1* e *string2*.

|Valor retornado|Descrição|
|------------------|-----------------|
|< 0|*string1* subcadeia de caracteres é menor que *string2* subcadeia de caracteres.|
|0|*string1* subcadeia de caracteres é idêntica à *string2* subcadeia de caracteres.|
|> 0|*string1* subcadeia de caracteres é maior que *string2* subcadeia de caracteres.|

Em um erro de validação de parâmetro, **mbsnbcmp** e **mbsnbcmp_l** retornar **_NLSCMPERROR**, que é definido no \<String. h > e \< mbstring >.

## <a name="remarks"></a>Comentários

O **mbsnbcmp** funções comparam no máximo a primeira *contagem* bytes na *string1* e *string2* e retornar um valor que indica o relação entre as subcadeias de caracteres. **mbsnbcmp** é uma versão diferencia maiusculas de minúsculas **mbsnbicmp**. Diferentemente **mbsnbcoll**, **mbsnbcmp** não é afetada pela ordem de agrupamento da localidade. **mbsnbcmp** reconhece sequências de caracteres multibyte de acordo com a atual multibyte [página de código](../../c-runtime-library/code-pages.md).

**mbsnbcmp** lembra **mbsncmp**, exceto pelo fato **mbsncmp** compara cadeias de caracteres por caracteres em vez de bytes.

O valor de saída é afetado pela **LC_CTYPE** categoria de configuração de localidade, que especifica os bytes iniciais e bytes de caracteres multibyte à direita. Para obter mais informações sobre, consulte [setlocale](setlocale-wsetlocale.md). O **mbsnbcmp** função usa a localidade atual desse comportamento dependente da localidade. O **mbsnbcmp_l** função é idêntica, exceto que ele usa o *localidade* parâmetro em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Se qualquer um dos *string1* ou *string2* é um ponteiro nulo, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, as funções retornam **_NLSCMPERROR** e **errno** está definido como **EINVAL**.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|---------------------------------------|--------------------|-----------------------|
|**tcsncmp**|[strncmp](strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)|**_mbsnbcmp**|[wcsncmp](strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)|
|**_tcsncmp_l**|[strncmp](strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)|**_mbsnbcml**|[wcsncmp](strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_mbsnbcmp**|\<mbstring.h>|
|**_mbsnbcmp_l**|\<mbstring.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_mbsnbcmp.c
#include <mbstring.h>
#include <stdio.h>

char string1[] = "The quick brown dog jumps over the lazy fox";
char string2[] = "The QUICK brown fox jumps over the lazy dog";

int main( void )
{
   char tmp[20];
   int result;
   printf( "Compare strings:\n          %s\n", string1 );
   printf( "          %s\n\n", string2 );
   printf( "Function: _mbsnbcmp (first 10 characters only)\n" );
   result = _mbsncmp( string1, string2 , 10 );
   if( result > 0 )
      _mbscpy_s( tmp, sizeof(tmp), "greater than" );
   else if( result < 0 )
      _mbscpy_s( tmp, sizeof(tmp), "less than" );
   else
      _mbscpy_s( tmp, sizeof(tmp), "equal to" );
   printf( "Result:   String 1 is %s string 2\n\n", tmp );
   printf( "Function: _mbsnicmp _mbsnicmp (first 10 characters only)\n" );
   result = _mbsnicmp( string1, string2, 10 );
   if( result > 0 )
      _mbscpy_s( tmp, sizeof(tmp), "greater than" );
   else if( result < 0 )
      _mbscpy_s( tmp, sizeof(tmp), "less than" );
   else
      _mbscpy_s( tmp, sizeof(tmp), "equal to" );
   printf( "Result:   String 1 is %s string 2\n\n", tmp );
}
```

### <a name="output"></a>Saída

```Output
Compare strings:
          The quick brown dog jumps over the lazy fox
          The QUICK brown fox jumps over the lazy dog

Function: _mbsnbcmp (first 10 characters only)
Result:   String 1 is greater than string 2

Function: _mbsnicmp _mbsnicmp (first 10 characters only)
Result:   String 1 is equal to string 2
```

## <a name="see-also"></a>Consulte também

[Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[_mbsnbcat, _mbsnbcat_l](mbsnbcat-mbsnbcat-l.md)<br/>
[_mbsnbicmp, _mbsnbicmp_l](mbsnbicmp-mbsnbicmp-l.md)<br/>
[strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)<br/>
[_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l](strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
