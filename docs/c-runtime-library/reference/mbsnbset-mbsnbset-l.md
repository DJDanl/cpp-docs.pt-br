---
title: _mbsnbset, _mbsnbset_l
ms.date: 4/2/2020
api_name:
- _mbsnbset
- _mbsnbset_l
- _o__mbsnbset
- _o__mbsnbset_l
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
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- mbsnbset
- mbsnbset_l
- _mbsnbset
- _mbsnbset_l
helpviewer_keywords:
- tcsnset function
- _tcsnset_l function
- _mbsnbset function
- _tcsnset function
- _mbsnbset_l function
- mbsnbset_l function
- tcsnset_l function
- mbsnbset function
ms.assetid: 8e46ef75-9a56-42d2-a522-a08450c67c19
ms.openlocfilehash: 57c6d1a81c9aac817b0028e8eccad38d03b0eef7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81340552"
---
# <a name="_mbsnbset-_mbsnbset_l"></a>_mbsnbset, _mbsnbset_l

Define os primeiros **bytes n** de uma seqüência de caracteres multibytes para um caractere especificado. Versões mais seguras dessas funções estão disponíveis, consulte [_mbsnbset_s, _mbsnbset_s_l](mbsnbset-s-mbsnbset-s-l.md).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
unsigned char *_mbsnbset(
   unsigned char *str,
   unsigned int c,
   size_t count
);
unsigned char *_mbsnbset_l(
   unsigned char *str,
   unsigned int c,
   size_t count,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*Str*<br/>
Cadeia de caracteres a ser alterada.

*C*<br/>
Configuração de caractere multibyte ou de byte único.

*contagem*<br/>
Número de bytes a serem definidos.

*Localidade*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor retornado

**_mbsnbset** retorna um ponteiro para a seqüência alterada.

## <a name="remarks"></a>Comentários

As **funções _mbsnbset** e **_mbsnbset_l** definem, no máximo, os primeiros bytes de *contagem* de *str* a *c*. Se *a contagem* for maior do que o comprimento do *str,* o comprimento do *str* é usado em vez de *contar*. Se *c* é um caractere multibyte e não pode ser definido inteiramente no último byte especificado pela *contagem,* o último byte é acolchoado com um caractere em branco. **_mbsnbset** e **_mbsnbset_l** não coloca um nulo final no final do *STR*.

**_mbsnbset** e **_mbsnbset_l** é semelhante ao **_mbsnset,** exceto que ele define bytes *de contagem* em vez de *contar* caracteres de *c*.

Se *str* é **NULO** ou *contagem* é zero, esta função gera uma exceção de parâmetro inválido conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **errno** será definido **como EINVAL** e a função retorna **NULL**. Além disso, se *c* não é um caractere multibyte válido, **errno** é definido como **EINVAL** e um espaço é usado em vez disso.

O valor de saída é afetado pela configuração da categoria **LC_CTYPE** da localidade. Consulte [setlocale](setlocale-wsetlocale.md) para obter mais informações. A **versão _mbsnbset** desta função usa o local atual para este comportamento dependente da localidade; a versão **_mbsnbset_l** é idêntica, exceto que usa o parâmetro local passado em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

**Observação de segurança** Essa API causa uma ameaça em potencial em relação ao problema de estouro de buffer. Os problemas de estouro de buffer são um método frequente de ataque ao sistema, resultando em uma elevação de privilégio sem garantia. Para obter mais informações, consulte [Avoiding Buffer Overruns](/windows/win32/SecBP/avoiding-buffer-overruns) (Evitando estouros de buffer).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tcsnset**|**_strnset**|**_mbsnbset**|**_wcsnset**|
|**_tcsnset_l**|**_strnset_l**|**_mbsnbset_l**|**_wcsnset_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_mbsnbset**|\<mbstring.h>|
|**_mbsnbset_l**|\<mbstring.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_mbsnbset.c
// compile with: /W3
#include <mbstring.h>
#include <stdio.h>

int main( void )
{
   char string[15] = "This is a test";
   /* Set not more than 4 bytes of string to be *'s */
   printf( "Before: %s\n", string );
   _mbsnbset( string, '*', 4 ); // C4996
   // Note; _mbsnbset is deprecated; consider _mbsnbset_s
   printf( "After:  %s\n", string );
}
```

### <a name="output"></a>Saída

```Output
Before: This is a test
After:  **** is a test
```

## <a name="see-also"></a>Confira também

[Manipulação de cordas](../../c-runtime-library/string-manipulation-crt.md)<br/>
[_mbsnbcat, _mbsnbcat_l](mbsnbcat-mbsnbcat-l.md)<br/>
[_strnset, _strnset_l, _wcsnset, _wcsnset_l, _mbsnset, _mbsnset_l](strnset-strnset-l-wcsnset-wcsnset-l-mbsnset-mbsnset-l.md)<br/>
[_strset, _strset_l, _wcsset, _wcsset_l, _mbsset, _mbsset_l](strset-strset-l-wcsset-wcsset-l-mbsset-mbsset-l.md)<br/>
