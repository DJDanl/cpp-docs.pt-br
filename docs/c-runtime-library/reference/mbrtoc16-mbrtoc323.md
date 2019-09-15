---
title: mbrtoc16, mbrtoc323
ms.date: 11/04/2016
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
ms.openlocfilehash: 52bcec5911fdc2ecbb073ae0042777aa4eb2b963
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70952434"
---
# <a name="mbrtoc16-mbrtoc32"></a>mbrtoc16, mbrtoc32

Converte o primeiro caractere multibyte em uma sequência de caracteres estreita no caractere UTF-16 ou UTF-32 equivalente.

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

*destination*<br/>
Ponteiro para o equivalente de **char16_t** ou **char32_t** do caractere multibyte a ser convertido. Se for null, a função não armazenará um valor.

*source*<br/>
O ponteiro para a cadeia de caracteres multibyte a ser convertida.

*max_bytes*<br/>
O número máximo de bytes na *origem* para examinar um caractere a ser convertido. Deve ser um valor entre um e o número de bytes, incluindo qualquer terminador nulo, restante na *origem*.

*state*<br/>
Ponteiro para um objeto de estado de conversão **mbstate_t** usado para interpretar a cadeia de caracteres multibyte para um ou mais caracteres de saída.

## <a name="return-value"></a>Valor de retorno

Em caso de sucesso, retorna o valor da primeira dessas condições que se aplicam, dado o valor do *estado* atual:

|Valor|Condição|
|-----------|---------------|
|0|Os próximos *max_bytes* ou menos caracteres convertidos da *origem* correspondem ao caractere de largura nula, que é o valor armazenado se o *destino* não for nulo.<br /><br /> o *estado* contém o estado de deslocamento inicial.|
|Entre 1 e *max_bytes*, inclusive|O valor retornado é o número de bytes de *origem* que concluem um caractere multibyte válido. O caractere largo convertido será armazenado se o *destino* não for nulo.|
|-3|O próximo caractere largo resultante de uma chamada anterior para a função foi armazenado no *destino* se o *destino* não for nulo. Nenhum byte da *origem* é consumido por essa chamada para a função.<br /><br /> Quando a *origem* aponta para um caractere multibyte que requer mais de um caractere largo para representar (por exemplo, um par alternativo), o valor de *estado* é atualizado para que a próxima chamada de função escreva o caractere adicional.|
|-2|Os próximos *max_bytes* bytes representam um caractere multibyte incompleto, mas potencialmente válido. Nenhum valor é armazenado no *destino*. Esse resultado pode ocorrer se *max_bytes* for zero.|
|-1|Ocorreu um erro de codificação. Os próximos *max_bytes* ou menos bytes não contribuem para um caractere multibyte completo e válido. Nenhum valor é armazenado no *destino*.<br /><br /> **EILSEQ** é armazenado em **errno** e o *estado* do estado de conversão não é especificado.|

## <a name="remarks"></a>Comentários

A função **mbrtoc16** lê até *max_bytes* bytes da *origem* para localizar o primeiro caractere multibyte completo, válido e, em seguida, armazena o caractere UTF-16 equivalente no *destino*. Os bytes de origem são interpretados de acordo com a localidade de multibyte do thread atual. Se o caractere multibyte exigir mais de um caractere de saída UTF-16, como um par alternativo, o valor de *estado* será definido para armazenar o próximo caractere UTF-16 no *destino* na próxima chamada para **mbrtoc16**. A função **mbrtoc32** é idêntica, mas a saída é armazenada como um caractere UTF-32.

Se *Source* for NULL, essas funções retornarão o equivalente de uma chamada feita usando argumentos de **NULL** para *Destination*, **""** para *Source*e 1 para *max_bytes*. Os valores passados de *Destination* e *max_bytes* são ignorados.

Se *Source* não for NULL, a função começará no início da cadeia de caracteres e inspecionará até *max_bytes* bytes para determinar o número de bytes necessários para concluir o próximo caractere multibyte, incluindo quaisquer sequências de deslocamento. Se os bytes examinados contiverem um caractere multibyte válido e completo, a função converterá o caractere no caractere ou caracteres largos de 16 bits ou 32 bits equivalentes. Se o *destino* não for nulo, a função armazenará o primeiro (e, possivelmente, apenas) o caractere de resultado no destino. Se forem necessários caracteres de saída adicionais, um valor será definido no *estado*, para que as chamadas subsequentes para a função gerem os caracteres adicionais e retornem o valor-3. Se nenhum caractere de saída for necessário, *State* será definido como o estado de deslocamento inicial.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**mbrtoc16**, **mbrtoc32**|\<uchar.h>|\<cuchar>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[c16rtomb, c32rtomb](c16rtomb-c32rtomb1.md)<br/>
[mbrtowc](mbrtowc.md)<br/>
[mbsrtowcs](mbsrtowcs.md)<br/>
[mbsrtowcs_s](mbsrtowcs-s.md)<br/>
