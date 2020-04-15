---
title: _mbsnbcat, _mbsnbcat_l
ms.date: 4/2/2020
api_name:
- _mbsnbcat_l
- _mbsnbcat
- _o__mbsnbcat
- _o__mbsnbcat_l
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
- mbsnbcat
- mbsnbcat_l
- _mbsnbcat
- _mbsnbcat_l
helpviewer_keywords:
- tcsncat_l function
- _tcsncat function
- mbsnbcat_l function
- mbsnbcat function
- _mbsnbcat_l function
- _tcsncat_l function
- _mbsnbcat function
- tcsncat function
ms.assetid: aa0f1d30-0ddd-48d1-88eb-c6884b20fd91
ms.openlocfilehash: 7598b20db4698ff8f95fbcefa00864be1b958447
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81340814"
---
# <a name="_mbsnbcat-_mbsnbcat_l"></a>_mbsnbcat, _mbsnbcat_l

Anexa, no máximo, os primeiros **bytes n** de uma seqüência de caracteres multibytes para outra. Estão disponíveis versões mais seguras dessas funções, consulte [_mbsnbcat_s, _mbsnbcat_s_l](mbsnbcat-s-mbsnbcat-s-l.md).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
unsigned char *_mbsnbcat(
   unsigned char *dest,
   const unsigned char *src,
   size_t count
);
unsigned char *_mbsnbcat_l(
   unsigned char *dest,
   const unsigned char *src,
   size_t count,
   _locale_t locale
);
template <size_t size>
unsigned char *_mbsnbcat(
   unsigned char (&dest)[size],
   const unsigned char *src,
   size_t count
); // C++ only
template <size_t size>
unsigned char *_mbsnbcat_l(
   unsigned char (&dest)[size],
   const unsigned char *src,
   size_t count,
   _locale_t locale
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*dest*<br/>
Cadeia de caracteres de destino de caractere multibyte terminada em nulo.

*src*<br/>
Cadeia de caracteres de origem de caractere multibyte terminada em nulo.

*contagem*<br/>
Número de bytes de *src* para apêndice para *dest*.

*Localidade*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor retornado

**_mbsnbcat** retorna um ponteiro para a seqüência de destino. Nenhum valor retornado é reservado para indicar um erro.

## <a name="remarks"></a>Comentários

A **função _mbsnbcat** anexa, no máximo, os primeiros bytes de *contagem* *de src* a *dest*. Se o byte imediatamente precedendo o caractere nulo em *dest* é um byte de chumbo, o byte inicial do *src* substitui este byte de chumbo. Caso contrário, o byte inicial *do src* substitui o caráter nulo final de *dest*. Se um byte nulo aparecer no *src* antes que os bytes *de contagem* sejam anexados, **_mbsnbcat** anexa todos os bytes do *src*, até o caractere nulo. Se *a contagem* for maior do que o comprimento do *src,* o comprimento do *src* é usado no lugar da *contagem*. A cadeia de caracteres resultante é terminada com um caractere nulo. Se ocorrer cópia entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.

O valor de saída é afetado pela configuração da categoria **LC_CTYPE** da localidade. Consulte [setlocale](setlocale-wsetlocale.md) para obter mais informações. A **versão _mbsnbcat** da função usa o local atual para este comportamento dependente da localidade; a versão **_mbsnbcat_l** é idêntica, exceto que eles usam o parâmetro local passado em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

**Observação de Segurança** Use uma cadeia de caracteres terminada em nulo. A cadeia de caracteres terminada em nulo não deve exceder o tamanho do buffer de destino. Para obter mais informações, consulte [Avoiding Buffer Overruns](/windows/win32/SecBP/avoiding-buffer-overruns) (Evitando estouros de buffer).

Se *dest* ou *src* for **NULL,** a função gerará um erro de parâmetro inválido, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se o erro for manipulado, a função retorna **EINVAL** e define **errno** para **EINVAL**.

No C++, essas funções têm sobrecargas de modelo que invocam os equivalentes mais novos e seguros dessas funções. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tcsncat**|[strncat](strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md)|**_mbsnbcat**|[wcsncat](strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md)|
|**_tcsncat_l**|**_strncat_l**|**_mbsnbcat_l**|**_wcsncat_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_mbsnbcat**|\<mbstring.h>|
|**_mbsnbcat_l**|\<mbstring.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Manipulação de cordas](../../c-runtime-library/string-manipulation-crt.md)<br/>
[_mbsnbcmp, _mbsnbcmp_l](mbsnbcmp-mbsnbcmp-l.md)<br/>
[_strncnt, _wcsncnt, _mbsnbcnt, _mbsnbcnt_l, _mbsnccnt, _mbsnccnt_l](strncnt-wcsncnt-mbsnbcnt-mbsnbcnt-l-mbsnccnt-mbsnccnt-l.md)<br/>
[_mbsnbcpy, _mbsnbcpy_l](mbsnbcpy-mbsnbcpy-l.md)<br/>
[_mbsnbicmp, _mbsnbicmp_l](mbsnbicmp-mbsnbicmp-l.md)<br/>
[_mbsnbset, _mbsnbset_l](mbsnbset-mbsnbset-l.md)<br/>
[strncat, _strncat_l, wcsncat, _wcsncat_l, _mbsncat, _mbsncat_l](strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md)<br/>
[_mbsnbcat_s, _mbsnbcat_s_l](mbsnbcat-s-mbsnbcat-s-l.md)<br/>
