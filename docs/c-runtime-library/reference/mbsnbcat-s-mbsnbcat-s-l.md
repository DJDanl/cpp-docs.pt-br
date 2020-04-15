---
title: _mbsnbcat_s, _mbsnbcat_s_l
ms.date: 4/2/2020
api_name:
- _mbsnbcat_s_l
- _mbsnbcat_s
- _o__mbsnbcat_s
- _o__mbsnbcat_s_l
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
- _mbsnbcat_s
- mbsnbcat_s
- _mbsnbcat_s_l
- mbsnbcat_s_l
helpviewer_keywords:
- _tcsncat function
- mbsnbcat_s function
- _mbsnbcat_s function
- _mbsnbcat_s_l function
- _tcsncat_s_l function
- tcsncat_s_l function
- mbsnbcat_s_l function
- tcsncat function
ms.assetid: 2c9e9be7-d979-4a54-8ada-23428b6648a9
ms.openlocfilehash: b4a9540025ad039458203eec1cc950187b6316a4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81340778"
---
# <a name="_mbsnbcat_s-_mbsnbcat_s_l"></a>_mbsnbcat_s, _mbsnbcat_s_l

Anexa-se a uma seqüência de caracteres multibytes, no máximo, os primeiros **bytes n** de outra seqüência de caracteres multibytes. Essas são versões de [_mbsnbcat, _mbsnbcat_l](mbsnbcat-mbsnbcat-l.md), mas têm melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t _mbsnbcat_s(
   unsigned char *dest,
   size_t sizeInBytes,
   const unsigned char *src,
   size_t count
);
errno_t _mbsnbcat_s_l(
   unsigned char *dest,
   size_t sizeInBytes,
   const unsigned char *src,
   size_t count,
   _locale_t locale
);
template <size_t size>
errno_t _mbsnbcat_s(
   unsigned char (&dest)[size],
   const unsigned char *src,
   size_t count
); // C++ only
template <size_t size>
errno_t _mbsnbcat_s_l(
   unsigned char (&dest)[size],
   const unsigned char *src,
   size_t count,
   _locale_t locale
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*dest*<br/>
Cadeia de caracteres de destino de caractere multibyte terminada em nulo.

*Sizeinbytes*<br/>
Tamanho do tampão *dest* em bytes.

*src*<br/>
Cadeia de caracteres de origem de caractere multibyte terminada em nulo.

*contagem*<br/>
Número de bytes de *src* para apêndice para *dest*.

*Localidade*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido, caso contrário, um código de erro.

### <a name="error-conditions"></a>Condições de erro

|**Dest**|*Sizeinbytes*|*src*|Valor retornado|
|------------|-------------------|-----------|------------------|
|**NULO**|any|any|**Einval**|
|Qualquer|<= 0|any|**Einval**|
|Qualquer|any|**NULO**|**Einval**|

Se qualquer uma das condições de erro ocorrer, a função gerará um erro de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se o erro for manipulado, a função retorna **EINVAL** e define **errno** para **EINVAL**.

## <a name="remarks"></a>Comentários

A **função _mbsnbcat_s** anexa para *dest*, no máximo, os primeiros bytes de *contagem* *de src*. Se o byte que imediatamente precede o caractere nulo em *dest* é um byte de chumbo, ele é substituído pelo byte inicial *do src*. Caso contrário, o byte inicial *do src* substitui o caráter nulo final de *dest*. Se um byte nulo aparecer no *src* antes que os bytes *de contagem* sejam anexados, **_mbsnbcat_s** anexa todos os bytes do *src*, até o caractere nulo. Se *a contagem* for maior do que o comprimento do *src,* o comprimento do *src* é usado no lugar da *contagem*. A cadeia de caracteres resultante é terminada por um caractere nulo. Se ocorrer cópia entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.

O valor de saída é afetado pela configuração da configuração da categoria **LC_CTYPE** do local; consulte [setlocale, _wsetlocale](setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções são idênticas, exceto que as que não têm o **sufixo _l** usam a localização atual e as que têm o **sufixo _l** em vez disso usam o parâmetro local que é passado. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

No C++, o uso dessas funções é simplificado por sobrecargas de modelo, as sobrecargas podem inferir o tamanho do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho e podem usar automaticamente suas funções mais novas e mais seguras para substituir funções mais antigas e menos seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

As versões da biblioteca de depuração dessas funções primeiro preenchem o buffer com 0xFE. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](crtsetdebugfillthreshold.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tcsncat**|[strncat](strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md)|**_mbsnbcat_s**|[wcsncat](strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md)|
|**_tcsncat_s_l**|**_strncat_s_l**|**_mbsnbcat_s_l**|**_wcsncat_s_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_mbsnbcat_s**|\<mbstring.h>|
|**_mbsnbcat_s_l**|\<mbstring.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Manipulação de cordas](../../c-runtime-library/string-manipulation-crt.md)<br/>
[_mbsnbcmp, _mbsnbcmp_l](mbsnbcmp-mbsnbcmp-l.md)<br/>
[_strncnt, _wcsncnt, _mbsnbcnt, _mbsnbcnt_l, _mbsnccnt, _mbsnccnt_l](strncnt-wcsncnt-mbsnbcnt-mbsnbcnt-l-mbsnccnt-mbsnccnt-l.md)<br/>
[_mbsnbcpy, _mbsnbcpy_l](mbsnbcpy-mbsnbcpy-l.md)<br/>
[_mbsnbcpy_s, _mbsnbcpy_s_l](mbsnbcpy-s-mbsnbcpy-s-l.md)<br/>
[_mbsnbset, _mbsnbset_l](mbsnbset-mbsnbset-l.md)<br/>
[strncat, _strncat_l, wcsncat, _wcsncat_l, _mbsncat, _mbsncat_l](strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md)<br/>
[strncat_s, _strncat_s_l, wcsncat_s, _wcsncat_s_l, _mbsncat_s, _mbsncat_s_l](strncat-s-strncat-s-l-wcsncat-s-wcsncat-s-l-mbsncat-s-mbsncat-s-l.md)<br/>
