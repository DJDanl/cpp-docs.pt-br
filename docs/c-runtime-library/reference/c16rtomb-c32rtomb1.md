---
title: c16rtomb, c32rtomb
ms.date: 01/22/2018
api_name:
- c16rtomb
- c32rtomb
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
- api-ms-win-crt-convert-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- c16rtomb
- c32rtomb
- uchar/c16rtomb
- uchar/c32rtomb
helpviewer_keywords:
- c16rtomb function
- c32rtomb function
ms.assetid: 7f5743ca-a90e-4e3f-a310-c73e16f4e14d
ms.openlocfilehash: a16effe48442ccbb5144b57ead2fb15c908fe898
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70943424"
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
Um ponteiro para um objeto **mbstate_t** .

## <a name="return-value"></a>Valor de retorno

O número de bytes armazenados no objeto de matriz *mbchar*, incluindo quaisquer sequências de deslocamento. Se *WCHAR* não for um caractere largo válido, o valor (**size_t**) (-1) será retornado, **errno** será definido como **EILSEQ**e o valor de *State* não será especificado.

## <a name="remarks"></a>Comentários

A função **c16rtomb** converte o caractere UTF-16 *WCHAR* na sequência de caracteres de vários bytes equivalentes na localidade atual. Se *mbchar* não for um ponteiro NULL, a função armazenará a sequência convertida no objeto de matriz apontado por *mbchar*. Até **MB_CUR_MAX** bytes são armazenados em *mbchar*e *State* é definido como o estado de mudança multibyte resultante.    Se *WCHAR* for um caractere largo nulo, uma sequência necessária para restaurar o estado de deslocamento inicial será armazenada, se necessário, seguida do caractere nulo e o *estado* será definido como o estado de conversão inicial. A função **c32rtomb** é idêntica, mas converte um caractere UTF-32.

Se *mbchar* for um ponteiro NULL, o comportamento será equivalente a uma chamada para a função que substitui um buffer interno para *mbchar* e um caractere nulo largo para *WCHAR*.

O objeto estado de conversão de *estado* permite que você faça chamadas subsequentes para essa função e outras funções reiniciáveis que mantêm o estado de deslocamento dos caracteres de saída multibyte. Os resultados são indefinidos quando você combina o uso de funções reiniciáveis e não reiniciáveis, ou se uma chamada para **setlocaling** é feita entre chamadas de função reiniciáveis.

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
