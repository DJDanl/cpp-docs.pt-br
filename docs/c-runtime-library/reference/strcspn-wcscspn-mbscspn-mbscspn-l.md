---
title: strcspn, wcscspn, _mbscspn, _mbscspn_l
ms.date: 4/2/2020
api_name:
- _mbscspn_l
- wcscspn
- _mbscspn
- strcspn
- _o__mbscspn
- _o__mbscspn_l
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
- ucrtbase.dll
- api-ms-win-crt-multibyte-l1-1-0.dll
- api-ms-win-crt-string-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- strcspn
- _mbscspn
- wcscspn
- _ftcscspn
- _tcscspn
helpviewer_keywords:
- strings [C++], searching
- ftcscspn function
- strcspn function
- _mbscspn function
- mbscspn_l function
- wcscspn function
- tcscspn function
- _ftcscspn function
- _mbscspn_l function
- mbscspn function
- _tcscspn function
ms.assetid: f73f51dd-b533-4e46-ba29-d05c553708a6
ms.openlocfilehash: 2ba3c2941736d185ad93c7c6e44cb83c82ebb478
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81358871"
---
# <a name="strcspn-wcscspn-_mbscspn-_mbscspn_l"></a>strcspn, wcscspn, _mbscspn, _mbscspn_l

Retorna o índice da primeira ocorrência, em uma cadeia de caracteres, de um caractere que pertence a um conjunto de caracteres.

> [!IMPORTANT]
> **_mbschr** e **_mbschr_l** não podem ser usados em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
size_t strcspn(
   const char *str,
   const char *strCharSet
);
size_t wcscspn(
   const wchar_t *str,
   const wchar_t *strCharSet
);
size_t _mbscspn(
   const unsigned char *str,
   const unsigned char *strCharSet
);
size_t _mbscspn_l(
   const unsigned char *str,
   const unsigned char *strCharSet,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*Str*<br/>
Cadeia de caracteres pesquisadas e terminadas em nulo.

*Strcharset*<br/>
Conjunto de caracteres terminado em nulo.

*Localidade*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor retornado

Essas funções retornam o índice do primeiro caractere em *str* que está em *strCharSet*. Se nenhum dos caracteres em *str* estiver em *strCharSet,* então o valor de retorno é o comprimento do *str*.

Nenhum valor retornado é reservado para indicar um erro.

## <a name="remarks"></a>Comentários

**wcscspn** e **_mbscspn** são versões de amplo caráter e multibytes do **strcspn**. Os argumentos do **wcscspn** são cordas de caráter amplo; os de **_mbscspn** são cordas de caracteres multibytes.

**_mbscspn** valida seus parâmetros. Se *str* ou *strCharSet* for um ponteiro nulo, o manipulador de parâmetros inválidos será invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, a função retorna 0 e define **errno** para **EINVAL**. **strcspn** e **wcscspn** não validam seus parâmetros. Caso contrário, essas três funções se comportam de forma idêntica.

O valor de saída é afetado pela configuração da categoria **LC_CTYPE** da localidade. Consulte [setlocale](setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções sem o sufixo **_l** usam a localidade atual desse comportamento dependente da localidade. As versões com o sufixo **_l** são idênticas, exceto por usarem o parâmetro de localidade passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcscspn**|**strcspn**|**_mbscspn**|**wcscspn**|
|n/d|n/d|**_mbscspn_l**|n/d|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strcspn**|\<string.h>|
|**wcscspn**|\<string.h> ou \<wchar.h>|
|**_mbscspn** **, _mbscspn_l**|\<mbstring.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_strcspn.c

#include <string.h>
#include <stdio.h>

void test( const char * str, const char * strCharSet )
{
   int pos = strcspn( str, strCharSet );
   printf( "strcspn( \"%s\", \"%s\" ) = %d\n", str, strCharSet, pos );
}

int main( void )
{
   test( "xyzbxz", "abc" );
   test( "xyzbxz", "xyz" );
   test( "xyzbxz", "no match" );
   test( "xyzbxz", "" );
   test( "", "abc" );
   test( "", "" );
}
```

```Output
strcspn( "xyzbxz", "abc" ) = 3
strcspn( "xyzbxz", "xyz" ) = 0
strcspn( "xyzbxz", "no match" ) = 6
strcspn( "xyzbxz", "" ) = 6
strcspn( "", "abc" ) = 0
strcspn( "", "" ) = 0
```

## <a name="see-also"></a>Confira também

[Manipulação de cordas](../../c-runtime-library/string-manipulation-crt.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[strncat, _strncat_l, wcsncat, _wcsncat_l, _mbsncat, _mbsncat_l](strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md)<br/>
[strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)<br/>
[strncpy, _strncpy_l, wcsncpy, _wcsncpy_l, _mbsncpy, _mbsncpy_l](strncpy-strncpy-l-wcsncpy-wcsncpy-l-mbsncpy-mbsncpy-l.md)<br/>
[_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l](strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)<br/>
[strrchr, wcsrchr, _mbsrchr, _mbsrchr_l](strrchr-wcsrchr-mbsrchr-mbsrchr-l.md)<br/>
[strspn, wcsspn, _mbsspn, _mbsspn_l](strspn-wcsspn-mbsspn-mbsspn-l.md)<br/>
