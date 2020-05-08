---
title: _mbsnbset_s, _mbsnbset_s_l
ms.date: 4/2/2020
api_name:
- _mbsnbset_s_l
- _mbsnbset_s
- _o__mbsnbset_s
- _o__mbsnbset_s_l
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
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- mbsnbset_s
- _mbsnbset_s_l
- _mbsnbset_s
- mbsnbset_s_l
helpviewer_keywords:
- tcsnset_s function
- mbsnbset_s function
- mbsnbset_s_l function
- _mbsnbset_s_l function
- _tcsnset_s_l function
- _mbsnbset_s function
- _tcsnset_s function
- tcsnset_s_l function
ms.assetid: 811f92c9-cc31-4bbd-8017-2d1bfc6fb96f
ms.openlocfilehash: b4880e774d6ad1b07052529461910ceff6897351
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82915530"
---
# <a name="_mbsnbset_s-_mbsnbset_s_l"></a>_mbsnbset_s, _mbsnbset_s_l

Define os primeiros **n** bytes de uma cadeia de caracteres multibyte para um caractere especificado. Essas versões de [_mbsnbset, _mbsnbset_l](mbsnbset-mbsnbset-l.md) têm melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t _mbsnbset_s(
   unsigned char *str,
   size_t size,
   unsigned int c,
   size_t count
);
errno_t _mbsnbset_s_l(
   unsigned char *str,
   size_t size,
   unsigned int c,
   size_t count,
   _locale_t locale
);
template <size_t size>
errno_t _mbsnbset_s(
   unsigned char (&str)[size],
   unsigned int c,
   size_t count
); // C++ only
template <size_t size>
errno_t _mbsnbset_s_l(
   unsigned char (&str)[size],
   unsigned int c,
   size_t count,
   _locale_t locale
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*Str*<br/>
Cadeia de caracteres a ser alterada.

*size*<br/>
O tamanho do buffer da cadeia de caracteres.

*&*<br/>
Configuração de caractere multibyte ou de byte único.

*contagem*<br/>
Número de bytes a serem definidos.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido, caso contrário, um código de erro.

## <a name="remarks"></a>Comentários

As funções **_mbsnbset_s** e **_mbsnbset_s_l** definidas, no máximo, a primeira *contagem* de bytes de *Str* para *c*. Se *Count* for maior que o comprimento de *Str*, o comprimento de *Str* será usado em vez de *Count*. Se *c* for um caractere multibyte e não puder ser definido inteiramente no último byte especificado por *Count*, o último byte será preenchido com um caractere em branco. **_mbsnbset_s** e **_mbsnbset_s_l** não coloque um nulo de terminação no final de *Str*.

**_mbsnbset_s** e **_mbsnbset_s_l** se assemelham **_mbsnset**, exceto que eles definem bytes de *contagem* em vez de *contar* caracteres de *c*.

Se *Str* for **NULL** ou *Count* for zero, essa função gerará uma exceção de parâmetro inválida, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** será definido como **EINVAL** e a função retornará **NULL**. Além disso, se *c* não for um caractere multibyte válido, **errno** será definido como **EINVAL** e um espaço será usado em vez disso.

O valor de saída é afetado pela configuração da configuração de categoria de **LC_CTYPE** da localidade; consulte [setlocale, _wsetlocale](setlocale-wsetlocale.md) para obter mais informações. A versão **_mbsnbset_s** dessa função usa a localidade atual para esse comportamento dependente de localidade; a versão **_mbsnbset_s_l** é idêntica, exceto pelo fato de que ela usa o parâmetro de localidade que é passado. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

No C++, o uso dessas funções é simplificado por sobrecargas de modelo. As sobrecargas podem inferir o tamanho do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

As versões de biblioteca de depuração dessas funções primeiro preenchem o buffer com 0xFE. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](crtsetdebugfillthreshold.md).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tcsnset_s**|**_strnset_s**|**_mbsnbset_s**|**_wcsnset_s**|
|**_tcsnset_s_l**|`_strnset_s _l`|**_mbsnbset_s_l**|**_wcsnset_s_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_mbsnbset_s**|\<mbstring.h>|
|**_mbsnbset_s_l**|\<mbstring.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_mbsnbset_s.c
#include <mbstring.h>
#include <stdio.h>

int main( void )
{
   char string[15] = "This is a test";
   /* Set not more than 4 bytes of string to be *'s */
   printf( "Before: %s\n", string );
   _mbsnbset_s( string, sizeof(string), '*', 4 );
   printf( "After:  %s\n", string );
}
```

## <a name="output"></a>Saída

```Output
Before: This is a test
After:  **** is a test
```

## <a name="see-also"></a>Consulte também

[Manipulação de cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[_mbsnbcat, _mbsnbcat_l](mbsnbcat-mbsnbcat-l.md)<br/>
[_strnset, _strnset_l, _wcsnset, _wcsnset_l, _mbsnset, _mbsnset_l](strnset-strnset-l-wcsnset-wcsnset-l-mbsnset-mbsnset-l.md)<br/>
[_strset, _strset_l, _wcsset, _wcsset_l, _mbsset, _mbsset_l](strset-strset-l-wcsset-wcsset-l-mbsset-mbsset-l.md)<br/>
