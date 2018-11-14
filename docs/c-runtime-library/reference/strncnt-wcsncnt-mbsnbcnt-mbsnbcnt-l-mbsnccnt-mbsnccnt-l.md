---
title: _strncnt, _wcsncnt, _mbsnbcnt, _mbsnbcnt_l, _mbsnccnt, _mbsnccnt_l
ms.date: 11/04/2016
apiname:
- _mbsnbcnt_l
- _mbsnccnt
- _wcsncnt
- _strncnt
- _mbsnccnt_l
- _mbsnbcnt
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
- _mbsnbcnt
- wcsncnt
- _tcsnbcnt
- _mbsnccnt
- _ftcsnbcnt
- mbsnbcnt
- strncnt
- mbsnbcnt_l
- mbsnccnt_l
- mbsnccnt
- _strncnt
- _wcsncnt
helpviewer_keywords:
- _strncnt function
- _mbsnbcnt function
- _mbsnbcnt_l function
- _mbsnccnt_l function
- mbsnbcnt_l function
- mbsnbcnt function
- tcsnbcnt function
- mbsnccnt_l function
- strncnt function
- _tcsnbcnt function
- mbsnccnt function
- wcsncnt function
- _mbsnccnt function
- _wcsncnt function
ms.assetid: 2a022e9e-a307-4acb-a66b-e56e5357f848
ms.openlocfilehash: 456a11ae98fe8fb40c2ef1d6f4e6d86583f4b7b3
ms.sourcegitcommit: afd6fac7c519dbc47a4befaece14a919d4e0a8a2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2018
ms.locfileid: "51520201"
---
# <a name="strncnt-wcsncnt-mbsnbcnt-mbsnbcntl-mbsnccnt-mbsnccntl"></a>_strncnt, _wcsncnt, _mbsnbcnt, _mbsnbcnt_l, _mbsnccnt, _mbsnccnt_l

Retorna o número de caracteres ou bytes dentro de uma contagem especificada.

> [!IMPORTANT]
> **_mbsnbcnt**, **_mbsnbcnt_l**, **_mbsnccnt**, e **_mbsnccnt_l** não pode ser usado em aplicativos executados no tempo de execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
size_t _strncnt(
   const char *str,
   size_t count
);
size_t _wcsncnt(
   const wchar_t *str,
   size_t count
);
size_t _mbsnbcnt(
   const unsigned char *str,
   size_t count
);
size_t _mbsnbcnt_l(
   const unsigned char *str,
   size_t count,
   _locale_t locale
);
size_t _mbsnccnt(
   const unsigned char *str,
   size_t count
);
size_t _mbsnccnt_l(
   const unsigned char *str,
   size_t count,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*str*<br/>
Cadeia de caracteres a ser examinada.

*count*<br/>
Número de caracteres ou bytes a ser examinado no *str*.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

**_mbsnbcnt** e **_mbsnbcnt_l** retornar o número de bytes encontrado no primeiro *contagem* de caracteres multibyte de *str*. **_mbsnccnt** e **_mbsnccnt_l** retornar o número de caracteres encontrados no primeiro *contagem* de bytes de *str*. Se um caractere nulo é encontrado antes do exame de *str* tiver concluído, eles retornam o número de bytes ou caracteres encontrados antes do caractere nulo. Se *str* consiste em menos de *contagem* caracteres ou bytes, elas retornam o número de caracteres ou bytes na cadeia de caracteres. Se *contagem* é menor que zero, eles retornam 0. Nas versões anteriores, essas funções tinham um valor de retorno do tipo **int** vez **size_t**.

**_strncnt** retorna o número de caracteres nos primeiros *contagem* bytes da cadeia de caracteres de byte único *str*. **_wcsncnt** retorna o número de caracteres nos primeiros *contagem* caracteres largos da cadeia de caracteres largos *str*.

## <a name="remarks"></a>Comentários

**_mbsnbcnt** e **_mbsnbcnt_l** contar o número de bytes encontrado no primeiro *contagem* de caracteres multibyte de *str*. **_mbsnbcnt** e **_mbsnbcnt_l** substituir **mtob** e deve ser usado no lugar de **mtob**.

**_mbsnccnt** e **_mbsnccnt_l** contar o número de caracteres encontrados no primeiro *contagem* de bytes de *str*. Se **_mbsnccnt** e **_mbsnccnt_l** encontrar um caractere nulo no segundo byte de um caractere de byte duplo, o primeiro byte também é considerado como nulo e não está incluído no valor de contagem retornado. **_mbsnccnt** e **_mbsnccnt_l** substituir **btom** e deve ser usado no lugar de **btom**.

Se *str* é um **nulo** ponteiro ou é *contagem* for 0, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md), **errno** é definido como **EINVAL**, e a função retornará 0.

O valor de saída é afetado pela configuração da categoria **LC_CTYPE** da localidade. Consulte [setlocale](setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções sem o sufixo **_l** usam a localidade atual desse comportamento dependente da localidade. As versões com o sufixo **_l** são idênticas, exceto por usarem o parâmetro de localidade passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|-------------|--------------------------------------|--------------------|-----------------------|
|**_tcsnbcnt**|**_strncnt**|**_mbsnbcnt**|**_wcsncnt**|
|**_tcsnccnt**|**_strncnt**|**_mbsnbcnt**|N/D|
|**_wcsncnt**|N/D|N/D|**_mbsnbcnt**|
|**_wcsncnt**|N/D|N/D|**_mbsnccnt**|
|N/D|N/D|**_mbsnbcnt_l**|**_mbsnccnt_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_mbsnbcnt**|\<mbstring.h>|
|**_mbsnbcnt_l**|\<mbstring.h>|
|**_mbsnccnt**|\<mbstring.h>|
|**_mbsnccnt_l**|\<mbstring.h>|
|**_strncnt**|\<tchar.h>|
|**_wcsncnt**|\<tchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_mbsnbcnt.c

#include  <mbstring.h>
#include  <stdio.h>

int main( void )
{
   unsigned char str[] = "This is a multibyte-character string.";
   unsigned int char_count, byte_count;
   char_count = _mbsnccnt( str, 10 );
   byte_count = _mbsnbcnt( str, 10 );
   if ( byte_count - char_count )
      printf( "The first 10 characters contain %d multibyte characters\n", char_count );
   else
      printf( "The first 10 characters are single-byte.\n");
}
```

### <a name="output"></a>Saída

```Output
The first 10 characters are single-byte.
```

## <a name="see-also"></a>Consulte também

[Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[_mbsnbcat, _mbsnbcat_l](mbsnbcat-mbsnbcat-l.md)<br/>
