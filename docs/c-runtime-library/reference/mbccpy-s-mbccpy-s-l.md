---
title: _mbccpy_s, _mbccpy_s_l
ms.date: 4/2/2020
api_name:
- _mbccpy_s
- _mbccpy_s_l
- _o__mbccpy_s
- _o__mbccpy_s_l
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
- _mbccpy_s_l
- mbccpy_s_l
- mbccpy_s
- _mbccpy_s
helpviewer_keywords:
- tccpy_s_l function
- _tccpy_s function
- _mbccpy_s function
- mbccpy_s function
- tccpy_s function
- mbccpy_s_l function
- _tccpy_s_l function
- _mbccpy_s_l function
ms.assetid: b6e965fa-53c1-4ec3-85ef-a1c4b4f2b2da
ms.openlocfilehash: 08df395c6978c84b3f53ed0b07ce988afd0249f6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81341242"
---
# <a name="_mbccpy_s-_mbccpy_s_l"></a>_mbccpy_s, _mbccpy_s_l

Copia um caractere multibyte de uma cadeia de caracteres para outra. Essas versões de [_mbccpy, _mbccpy_l](mbccpy-mbccpy-l.md) têm melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t _mbccpy_s(
   unsigned char *dest,
   size_t buffSizeInBytes,
   int * pCopied,
   const unsigned char *src
);
errno_t _mbccpy_s_l(
   unsigned char *dest,
   size_t buffSizeInBytes,
   int * pCopied,
   const unsigned char *src,
   locale_t locale
);
template <size_t size>
errno_t _mbccpy_s(
   unsigned char (&dest)[size],
   int * pCopied,
   const unsigned char *src
); // C++ only
template <size_t size>
errno_t _mbccpy_s_l(
   unsigned char (&dest)[size],
   int * pCopied,
   const unsigned char *src,
   locale_t locale
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*dest*<br/>
Destino da cópia.

*buffSizeInBytes*<br/>
Tamanho do buffer de destino.

*pCopied*<br/>
Preenchido com o número de bytes copiados (1 ou 2 se for bem-sucedido). Passe **NULO** se você não se importa com o número.

*src*<br/>
Caracteres multibyte para copiar.

*Localidade*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido; um código de erro em caso de falha. Se *src* ou *dest* for **NULL**, ou se mais do que **buffSizeinBytes** bytes será copiado para *dest*, então o manipulador de parâmetros inválidos é invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, as funções retornam **EINVAL** e **errno** é definida **como EINVAL**.

## <a name="remarks"></a>Comentários

A função **_mbccpy_s** copia um caractere multibyte *de src* para *dest*. Se *o src* não apontar para o byte principal de um caractere multibyte determinado por uma chamada implícita para [_ismbblead,](ismbblead-ismbblead-l.md)então o único byte que *o src* aponta é copiado. Se *o src* aponta para um byte de chumbo, mas o byte seguinte é 0 e, portanto, inválido, então 0 é copiado para *dest*, **errno** é definido como **EILSEQ**, e a função retorna **EILSEQ**.

**_mbccpy_s** não anexa um exterminador nulo; no entanto, se *src* aponta para um caractere nulo, então esse nulo é copiado para *dest* (esta é apenas uma cópia regular de single-byte).

O valor em *pCopied* é preenchido com o número de bytes copiados. Os valores possíveis são 1 e 2 se a operação for bem-sucedida. Se **NULL** for aprovado, este parâmetro será ignorado.

|*src*|copiado para *dest*|*pCopied*|Valor retornado|
|-----------|----------------------|---------------|------------------|
|byte não inicial|byte não inicial|1|0|
|0|0|1|0|
|byte inicial seguido por um valor diferente de 0|byte inicial seguido por um valor diferente de 0|2|0|
|byte inicial seguido por 0|0|1|**EILSEQ**|

Observe que a segunda linha é apenas um caso especial do primeiro. Observe também que a tabela assume *buffSizeInBytes* >= *pCopied*.

**_mbccpy_s** usa o local atual para qualquer comportamento dependente do local. **_mbccpy_s_l** é idêntico ao **_mbccpy_s** exceto que **_mbccpy_s_l** usa o local passado para qualquer comportamento dependente da localidade.

No C++, o uso dessas funções é simplificado por sobrecargas de modelo. As sobrecargas podem inferir automaticamente o tamanho do buffer, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tccpy_s**|É mapeado para um macro ou uma função embutida.|**_mbccpy_s**|É mapeado para um macro ou uma função embutida.|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_mbccpy_s**|\<mbstring.h>|
|**_mbccpy_s_l**|\<mbstring.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[_mbclen, mblen, _mblen_l](mbclen-mblen-mblen-l.md)<br/>
