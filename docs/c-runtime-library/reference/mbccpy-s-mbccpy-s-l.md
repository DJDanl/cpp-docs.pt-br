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
- api-ms-win-crt-private-l1-1-0.dll
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
ms.openlocfilehash: 85db4e478b070823bb14028018d918e0f3cabbd7
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82920317"
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
Preenchido com o número de bytes copiados (1 ou 2 se for bem-sucedido). Passe **NULL** se você não se preocupa com o número.

*src*<br/>
Caracteres multibyte para copiar.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido; um código de erro em caso de falha. Se *src* ou *dest* for **NULL**ou se mais de **buffSizeInBytes** bytes forem copiados para *dest*, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, as funções retornam **EINVAL** e **errno** é definida como **EINVAL**.

## <a name="remarks"></a>Comentários

A função **_mbccpy_s** copia um caractere multibyte de *src* para *dest*. Se *src* não apontar para o byte de Lead de um caractere multibyte como determinado por uma chamada implícita para [_ismbblead](ismbblead-ismbblead-l.md), então, o único byte para o qual *src* aponta será copiado. Se *src* apontar para um byte de Lead, mas o byte a seguir for 0 e, portanto, for inválido, 0 será copiado para *dest*, **errno** será definido como **EILSEQ**e a função retornará **EILSEQ**.

**_mbccpy_s** não acrescenta um terminador nulo; no entanto, se *src* apontar para um caractere nulo, esse NULL será copiado para *dest* (essa é apenas uma cópia regular de byte único).

O valor em *pCopied* é preenchido com o número de bytes copiados. Os valores possíveis são 1 e 2 se a operação for bem-sucedida. Se **NULL** for passado, esse parâmetro será ignorado.

|*src*|copiado para o *dest*|*pCopied*|Valor retornado|
|-----------|----------------------|---------------|------------------|
|byte não inicial|byte não inicial|1|0|
|0|0|1|0|
|byte inicial seguido por um valor diferente de 0|byte inicial seguido por um valor diferente de 0|2|0|
|byte inicial seguido por 0|0|1|**EILSEQ**|

Observe que a segunda linha é apenas um caso especial do primeiro. Observe também que a tabela pressupõe *buffSizeInBytes* >= *pCopied*.

**_mbccpy_s** usa a localidade atual para qualquer comportamento dependente de localidade. **_mbccpy_s_l** é idêntica a **_mbccpy_s** , exceto que **_mbccpy_s_l** usa a localidade passada para qualquer comportamento dependente de localidade.

No C++, o uso dessas funções é simplificado por sobrecargas de modelo. As sobrecargas podem inferir automaticamente o tamanho do buffer, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

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

## <a name="see-also"></a>Consulte também

[Locale](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[_mbclen, mblen, _mblen_l](mbclen-mblen-mblen-l.md)<br/>
