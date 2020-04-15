---
title: mbrtoc16, mbrtoc323
ms.date: 4/2/2020
api_name:
- mbrtoc16
- mbrtoc32
- _o_mbrtoc16
- _o_mbrtoc32
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
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- mbrtoc16
- mbrtoc32
- uchar/mbrtoc16
- uchar/mbrtoc32
helpviewer_keywords:
- mbrtoc16 function
- mbrtoc32 function
ms.assetid: 099ade4d-56f7-4e61-8b45-493f1d7a64bd
ms.openlocfilehash: 91755d19eacf73f19700eed7fffbffc529d4e235
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81340973"
---
# <a name="mbrtoc16-mbrtoc32"></a>mbrtoc16, mbrtoc32

Traduz o primeiro caractere multibyte UTF-8 em uma seqüência para o caractere UTF-16 ou UTF-32 equivalente.

## <a name="syntax"></a>Sintaxe

```C
size_t mbrtoc16(
   char16_t* destination,
   const char* source,
   size_t max_bytes,
   mbstate_t* state
);

size_t mbrtoc32(
   char32_t* destination,
   const char* source,
   size_t max_bytes,
   mbstate_t* state
);
```

### <a name="parameters"></a>Parâmetros

*Destino*\
Ponteiro para o **char16_t** ou **char32_t** equivalente do caractere multibyte UTF-8 a converter. Se nula, a função não armazena um valor.

*Fonte*\
Ponteiro para a seqüência de caracteres multibyte UTF-8 para converter.

*max_bytes*\
O número máximo de bytes na *fonte* para examinar um caractere a ser convertido. Este argumento deve ser um valor entre um e o número de bytes, incluindo qualquer exterminador nulo, permanecendo na *fonte*.

*Estado*\
Ponteiro para um objeto de estado de conversão **mbstate_t** usado para interpretar a seqüência de vários bytes UTF-8 para um ou mais caracteres de saída.

## <a name="return-value"></a>Valor retornado

No sucesso, devolve o valor da primeira dessas condições que se aplica, dado o valor atual do *estado:*

|Valor|Condição|
|-----------|---------------|
|0|Os próximos *max_bytes* ou menos caracteres convertidos da *origem* correspondem ao caractere de largura nulo, que é o valor armazenado se o *destino* não for nulo.<br /><br /> *estado* contém o estado de mudança inicial.|
|Entre 1 e *max_bytes,* inclusive|O valor devolvido é o número de bytes de *fonte* que completam um caractere multibyte válido. O caractere largo convertido é armazenado se o *destino* não for nulo.|
|-3|O próximo caractere amplo resultante de uma chamada anterior para a função foi armazenado no *destino* se o *destino* não for nulo. Nenhum bytes da *fonte* são consumidos por esta chamada para a função.<br /><br /> Quando *a fonte* aponta para um caractere multibyte UTF-8 que requer mais de um caractere amplo para representar (por exemplo, um par de substitutos), então o valor do *estado* é atualizado para que a próxima chamada de função escreva o caractere adicional.|
|-2|Os próximos *bytes de max_bytes* representam um caractere multibyte UTF-8 incompleto, mas potencialmente válido. Nenhum valor é armazenado no *destino*. Esse resultado pode ocorrer se *max_bytes* for zero.|
|-1|Ocorreu um erro de codificação. Os próximos *max_bytes* ou menos bytes não contribuem para um caractere multibyte UTF-8 completo e válido. Nenhum valor é armazenado no *destino*.<br /><br /> **O EILSEQ** é armazenado em **errno** e o *estado* de valor do estado de conversão não é especificado.|

## <a name="remarks"></a>Comentários

A função **mbrtoc16** lê até *max_bytes* bytes da *fonte* para encontrar o primeiro caractere multibyte UTF-8 completo e válido e, em seguida, armazena o caractere UTF-16 equivalente no *destino*. Se o caractere exigir mais de um caractere de saída UTF-16, como um par de substitutos, então o valor *do estado* será definido para armazenar o próximo caractere UTF-16 no *destino* na próxima chamada para **mbrtoc16**. A função **mbrtoc32** é idêntica, mas a saída é armazenada como um caractere UTF-32.

Se *a fonte* for nula, essas funções retornam o equivalente a uma chamada feita usando argumentos de **NULL** para *destino*, `""` (uma seqüência vazia e nula) para *fonte*e 1 para *max_bytes*. Os valores passados de *destino* e *max_bytes* são ignorados.

Se a *fonte* não for nula, a função começa no início da seqüência e inspeciona até *max_bytes* bytes para determinar o número de bytes necessários para completar o próximo caractere multibyte UTF-8, incluindo quaisquer seqüências de turno. Se os bytes examinados contiverem um caractere multibyte UTF-8 válido e completo, a função converterá o caractere em caracteres ou caracteres de 16 bits ou 32 bits de largura equivalentes. Se *o destino* não for nulo, a função armazena o primeiro (e possivelmente único) personagem de resultado no destino. Se forem necessários caracteres de saída adicionais, um valor será definido no *estado,* de modo que as chamadas subseqüentes para a função desaem os caracteres adicionais e retornem o valor -3. Se não forem necessários mais caracteres de saída, *o estado* será definido para o estado inicial de deslocamento.

Para converter caracteres multibytes não-UTF-8 em caracteres LE UTF-16, use as funções [mbrtowc](mbrtowc.md), [mbtowc ou _mbtowc_l.](mbtowc-mbtowc-l.md)

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**mbrtoc16**, **mbrtoc32**|\<uchar.h>|\<cuchar>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../compatibility.md).

## <a name="see-also"></a>Confira também

[Conversão de dados](../data-conversion.md)\
[Localidade](../locale.md)\
[Interpretação de sequências de caracteres multibytes](../interpretation-of-multibyte-character-sequences.md)\
[c16rtomb, c32rtomb](c16rtomb-c32rtomb1.md)\
[mbrtowc](mbrtowc.md)\
[Mbsrtowcs](mbsrtowcs.md)\
[mbsrtowcs_s](mbsrtowcs-s.md)
