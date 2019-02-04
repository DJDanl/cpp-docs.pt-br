---
title: c16rtomb, c32rtomb
ms.date: 01/22/2018
apiname:
- c16rtomb
- c32rtomb
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
- api-ms-win-crt-convert-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- c16rtomb
- c32rtomb
- uchar/c16rtomb
- uchar/c32rtomb
helpviewer_keywords:
- c16rtomb function
- c32rtomb function
ms.assetid: 7f5743ca-a90e-4e3f-a310-c73e16f4e14d
ms.openlocfilehash: ad58184c7bab6f95a842bda5f9eb545f09434a3e
ms.sourcegitcommit: e98671a4f741b69d6277da02e6b4c9b1fd3c0ae5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/04/2019
ms.locfileid: "55702772"
---
# <a name="c16rtomb-c32rtomb"></a>c16rtomb, c32rtomb

Converta um caractere largo UTF-16 ou UTF-32 em um caractere multibyte na localidade atual.

## <a name="syntax"></a>Sintaxe

```C
size_t c16rtomb(
    char *mbchar,
    char16_t wchar,
    mbstate_t *state
);
size_t c32rtomb(
    char *mbchar,
    char32_t wchar,
    mbstate_t *state
);
```

### <a name="parameters"></a>Parâmetros

*mbchar*<br/>
Ponteiro para uma matriz para armazenar o caractere multibyte convertido.

*wchar*<br/>
Um caractere largo a ser convertido.

*state*<br/>
Um ponteiro para um **mbstate_t** objeto.

## <a name="return-value"></a>Valor de retorno

O número de bytes armazenados no objeto de matriz *mbchar*, incluindo quaisquer sequências de deslocamento. Se *wchar* não é um caractere largo válido, o valor (**size_t**)(-1) for retornado, **errno** é definido como **EILSEQ**e o valor de *estado* não está especificado.

## <a name="remarks"></a>Comentários

O **c16rtomb** função converte o caractere UTF-16 *wchar* à sequência de caractere estreito multibyte equivalente na localidade atual. Se *mbchar* não é um ponteiro nulo, a função armazena a sequência convertida no objeto de matriz apontada por *mbchar*. Até **MB_CUR_MAX** bytes são armazenados em *mbchar*, e *estado* é definido como o estado de deslocamento multibyte resultante.    Se *wchar* é um caractere largo nulo, uma sequência necessária para restaurar o estado de deslocamento inicial será armazenado, se necessário, seguido pelo caractere null, e *estado* é definido como o estado de conversão inicial. O **c32rtomb** função é idêntica, mas converte um caractere UTF-32.

Se *mbchar* for um ponteiro nulo, o comportamento é equivalente a uma chamada para a função que substitui um buffer interno para *mbchar* e um caractere nulo largo para *wchar*.

O *estado* objeto de estado de conversão permite que você faça chamadas subsequentes para essa função e outras funções reiniciáveis que mantenham o estado de deslocamento dos caracteres multibyte de saída. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis ou se uma chamada para **setlocale** é feita entre chamadas de função reiniciável.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**c16rtomb**, **c32rtomb**|C, C++: \<uchar.h>|

Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[mbrtoc16, mbrtoc32](mbrtoc16-mbrtoc323.md)<br/>
[wcrtomb](wcrtomb.md)<br/>
[wcrtomb_s](wcrtomb-s.md)<br/>
