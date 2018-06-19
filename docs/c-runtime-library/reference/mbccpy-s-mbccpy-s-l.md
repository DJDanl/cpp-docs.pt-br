---
title: _mbccpy_s, _mbccpy_s_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _mbccpy_s
- _mbccpy_s_l
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
- _mbccpy_s_l
- mbccpy_s_l
- mbccpy_s
- _mbccpy_s
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0a3a52314209b62c818623e315757dcd358ec491
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32404022"
---
# <a name="mbccpys-mbccpysl"></a>_mbccpy_s, _mbccpy_s_l

Copia um caractere multibyte de uma cadeia de caracteres para outra. Essas versões de [_mbccpy, _mbccpy_l](mbccpy-mbccpy-l.md) têm melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

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
Preenchido com o número de bytes copiados (1 ou 2 se for bem-sucedido). Passar **nulo** se você não se importa com o número.

*src*<br/>
Caracteres multibyte para copiar.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido; um código de erro em caso de falha. Se *src* ou *dest* é **nulo**, ou se mais de **buffSizeinBytes** bytes serão copiados *dest*, em seguida, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, as funções retornam **EINVAL** e **errno** é definido como **EINVAL**.

## <a name="remarks"></a>Comentários

O **mbccpy_s** função copia caracteres multibyte um de *src* para *dest*. Se *src* não aponta para o byte de um caractere multibyte conforme determinado por uma chamada implícita para [ismbblead](ismbblead-ismbblead-l.md), em seguida, o byte único que *src* pontos é copiado. Se *src* aponta para um byte inicial, mas o byte seguinte é 0 e, portanto, inválida, 0 é copiado para *dest*, **errno** é definido como **EILSEQ**e o função retorna **EILSEQ**.

**mbccpy_s** não anexa um terminador nulo; no entanto, se *src* aponta para um caractere null, e que null é copiado para *dest* (Esta é apenas uma cópia regular de byte único).

O valor em *pCopied* é preenchido com o número de bytes copiados. Os valores possíveis são 1 e 2 se a operação for bem-sucedida. Se **nulo** for passado, esse parâmetro é ignorado.

|*src*|copiados *dest*|*pCopied*|Valor retornado|
|-----------|----------------------|---------------|------------------|
|byte não inicial|byte não inicial|1|0|
|0|0|1|0|
|byte inicial seguido por um valor diferente de 0|byte inicial seguido por um valor diferente de 0|2|0|
|byte inicial seguido por 0|0|1|**EILSEQ**|

Observe que a segunda linha é apenas um caso especial do primeiro. Observe também que a tabela considera *buffSizeInBytes* >= *pCopied*.

**mbccpy_s** usa a localidade atual para qualquer comportamento dependente de localidade. **mbccpy_s_l** é idêntico ao **mbccpy_s** exceto que **mbccpy_s_l** usa a localidade passada para qualquer comportamento dependente de localidade.

No C++, o uso dessas funções é simplificado por sobrecargas de modelo. As sobrecargas podem inferir automaticamente o tamanho do buffer, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**tccpy_s**|É mapeado para um macro ou uma função embutida.|**_mbccpy_s**|É mapeado para um macro ou uma função embutida.|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_mbccpy_s**|\<mbstring.h>|
|**_mbccpy_s_l**|\<mbstring.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[_mbclen, mblen, _mblen_l](mbclen-mblen-mblen-l.md)<br/>
