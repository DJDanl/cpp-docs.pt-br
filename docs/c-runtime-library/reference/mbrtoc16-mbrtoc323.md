---
title: mbrtoc16, mbrtoc323
ms.date: 10/22/2019
api_name:
- mbrtoc16
- mbrtoc32
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
- mbrtoc16
- mbrtoc32
- uchar/mbrtoc16
- uchar/mbrtoc32
helpviewer_keywords:
- mbrtoc16 function
- mbrtoc32 function
ms.assetid: 099ade4d-56f7-4e61-8b45-493f1d7a64bd
ms.openlocfilehash: 793eadf433f3117d89b4f0dc7c8397762405406b
ms.sourcegitcommit: 0a5518fdb9d87fcc326a8507ac755936285fcb94
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/23/2019
ms.locfileid: "72811129"
---
# <a name="mbrtoc16-mbrtoc32"></a>mbrtoc16, mbrtoc32

Traduz o primeiro caractere multibyte UTF-8 em uma cadeia de caracteres no caractere UTF-16 ou UTF-32 equivalente.

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

\ de *destino*
Ponteiro para o equivalente de **char16_t** ou **char32_t** do caractere multibyte UTF-8 a ser convertido. Se for NULL, a função não armazenará um valor.

\ de *origem*
Ponteiro para a cadeia de caracteres multibyte UTF-8 para converter.

\ *max_bytes*
O número máximo de bytes na *origem* para examinar um caractere a ser convertido. Esse argumento deve ser um valor entre um e o número de bytes, incluindo qualquer terminador nulo, restante na *origem*.

*estado* \
Ponteiro para um objeto de estado de conversão **mbstate_t** usado para interpretar a cadeia de caracteres multibyte UTF-8 para um ou mais caracteres de saída.

## <a name="return-value"></a>Valor retornado

Em caso de sucesso, retorna o valor da primeira dessas condições que se aplicam, dado o valor do *estado* atual:

|Valor|Condição|
|-----------|---------------|
|0|Os próximos *max_bytes* ou menos caracteres convertidos da *origem* correspondem ao caractere de largura nula, que é o valor armazenado se o *destino* não for nulo.<br /><br /> o *estado* contém o estado de deslocamento inicial.|
|Entre 1 e *max_bytes*, inclusive|O valor retornado é o número de bytes de *origem* que concluem um caractere multibyte válido. O caractere largo convertido será armazenado se o *destino* não for nulo.|
|-3|O próximo caractere largo resultante de uma chamada anterior para a função foi armazenado no *destino* se o *destino* não for nulo. Nenhum byte da *origem* é consumido por essa chamada para a função.<br /><br /> Quando a *origem* aponta para um caractere multibyte UTF-8 que requer mais de um caractere largo para representar (por exemplo, um par substituto), o valor de *estado* é atualizado para que a próxima chamada de função escreva o caractere adicional.|
|-2|Os próximos *max_bytes* bytes representam um caractere de multibyte UTF-8 incompleto, mas potencialmente válido. Nenhum valor é armazenado no *destino*. Esse resultado pode ocorrer se *max_bytes* for zero.|
|-1|Ocorreu um erro de codificação. Os próximos *max_bytes* ou menos bytes não contribuem para um caractere de multibyte UTF-8 válido e completo. Nenhum valor é armazenado no *destino*.<br /><br /> **EILSEQ** é armazenado em **errno** e o *estado* do valor do estado de conversão não é especificado.|

## <a name="remarks"></a>Comentários

A função **mbrtoc16** lê até *max_bytes* bytes da *origem* para localizar o primeiro caractere multibyte completo, válido UTF-8 e, em seguida, armazena o caractere UTF-16 equivalente no *destino*. Se o caractere exigir mais de um caractere de saída UTF-16, como um par alternativo, o valor de *estado* será definido para armazenar o próximo caractere UTF-16 no *destino* na próxima chamada para **mbrtoc16**. A função **mbrtoc32** é idêntica, mas a saída é armazenada como um caractere UTF-32.

Se a *origem* for nula, essas funções retornarão o equivalente de uma chamada feita usando argumentos de **NULL** para o *destino*, `""` (uma cadeia de caracteres vazia, terminada em nulo) para a *origem*e 1 para *max_bytes*. Os valores passados de *Destination* e *max_bytes* são ignorados.

Se a *origem* não for nula, a função começará no início da cadeia de caracteres e inspecionará até *max_bytes* bytes para determinar o número de bytes necessários para concluir o próximo caractere multibyte UTF-8, incluindo quaisquer sequências de deslocamento. Se os bytes examinados contiverem um caractere de multibyte UTF-8 válido e completo, a função converterá o caractere no caractere ou caracteres equivalentes de 16 bits ou 32 bits largos. Se o *destino* não for nulo, a função armazenará o primeiro caractere de resultado (e, possivelmente, somente) no destino. Se forem necessários caracteres de saída adicionais, um valor será definido no *estado*, para que as chamadas subsequentes para a função gerem os caracteres adicionais e retornem o valor-3. Se nenhum caractere de saída for necessário, *State* será definido como o estado de deslocamento inicial.

Para converter caracteres de multibyte não UTF-8 em caracteres UTF-16 LE, use as funções [mbrtowc](mbrtowc.md), [mbtowc ou _mbtowc_l](mbtowc-mbtowc-l.md) .

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**mbrtoc16**, **mbrtoc32**|\<uchar.h>|\<cuchar>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../compatibility.md).

## <a name="see-also"></a>Consulte também

\ de [conversão de dados](../data-conversion.md)
[Localidade](../locale.md)\
[Interpretação de sequências de caracteres multibyte](../interpretation-of-multibyte-character-sequences.md)\
[c16rtomb, c32rtomb](c16rtomb-c32rtomb1.md)\
[mbrtowc](mbrtowc.md)\
[mbsrtowcs](mbsrtowcs.md)\
[mbsrtowcs_s](mbsrtowcs-s.md)
