---
title: mbrtoc16, mbrtoc323
ms.date: 11/04/2016
apiname:
- mbrtoc16
- mbrtoc32
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
- mbrtoc16
- mbrtoc32
- uchar/mbrtoc16
- uchar/mbrtoc32
helpviewer_keywords:
- mbrtoc16 function
- mbrtoc32 function
ms.assetid: 099ade4d-56f7-4e61-8b45-493f1d7a64bd
ms.openlocfilehash: f8573ac321772d19141be0228891b290ba48b217
ms.sourcegitcommit: afd6fac7c519dbc47a4befaece14a919d4e0a8a2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2018
ms.locfileid: "51520136"
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

*Destino*<br/>
Ponteiro para o **char16_t** ou **char32_t** equivalente do caractere multibyte a ser convertido. Se for null, a função não armazenará um valor.

*source*<br/>
O ponteiro para a cadeia de caracteres multibyte a ser convertida.

*max_bytes*<br/>
O número máximo de bytes em *origem* para examinar um caractere a ser convertido. Isso deve ser um valor entre 1 e o número de bytes, incluindo qualquer terminador nulo, restantes no *fonte*.

*state*<br/>
Ponteiro para um **mbstate_t** objeto de estado de conversão usado para interpretar a cadeia de caracteres multibyte para um ou mais caracteres de saída.

## <a name="return-value"></a>Valor de retorno

Em caso de sucesso, retorna o valor da primeira dessas condições que se aplica, dado o atual *estado* valor:

|Valor|Condição|
|-----------|---------------|
|0|A próxima *max_bytes* ou menos caracteres convertidos de *fonte* correspondem ao caractere largo nulo, que é o valor armazenado se *destino* não é nulo.<br /><br /> *estado* contém o estado inicial do deslocamento.|
|Entre 1 e *max_bytes*, inclusive|O valor retornado é o número de bytes de *origem* que concluir um caractere multibyte válido. O caractere largo convertido será armazenado se *destino* não é nulo.|
|-3|O próximo caractere largo resultante de uma chamada anterior para a função foi armazenado no *destino* se *destino* não é nulo. Nenhum byte de *origem* são consumidos por essa chamada à função.<br /><br /> Quando *fonte* aponta para um caractere multibyte que requer mais de um caractere largo para representar (por exemplo, um par substituto), em seguida, a *estado* valor é atualizado para que a próxima chamada de função grave  o caractere adicional.|
|-2|A próxima *max_bytes* bytes representam um incompleto, mas potencialmente válido de caractere multibyte. Nenhum valor é armazenado no *destino*. Esse resultado pode ocorrer se *max_bytes* é zero.|
|-1|Ocorreu um erro de codificação. A próxima *max_bytes* ou menos bytes não contribuem para um caractere multibyte válido e completo. Nenhum valor é armazenado no *destino*.<br /><br /> **EILSEQ** é armazenado no **errno** e o estado de conversão *estado* não está especificado.|

## <a name="remarks"></a>Comentários

O **mbrtoc16** função lê até *max_bytes* bytes do *origem* para localizar o primeiro caractere multibyte válido, completo e, em seguida, armazena o UTF-16 equivalente caractere em *destino*. Os bytes de origem são interpretados de acordo com a localidade de multibyte do thread atual. Se os caracteres multibyte exigirem mais de um caractere de saída UTF-16 como um par substituto, o *estado* valor é definido para armazenar o próximo caractere UTF-16 no *destino* na próxima chamada para **mbrtoc16**. O **mbrtoc32** função é idêntica, mas a saída é armazenada como um caractere UTF-32.

Se *fonte* for null, essas funções retornam o equivalente de uma chamada feita usando argumentos de **nulo** para *destino*, **""** para *fonte*e 1 para *max_bytes*. Os valores passados de *destino* e *max_bytes* são ignorados.

Se *fonte* for não nulo, a função começa no início da cadeia de caracteres e inspecionará até *max_bytes* bytes para determinar o número de bytes necessários para completar o próximo caractere multibyte, incluindo quaisquer sequências de deslocamento. Se os bytes examinados contiverem um caractere multibyte válido e completo, a função converterá o caractere no caractere ou caracteres largos de 16 bits ou 32 bits equivalentes. Se *destino* não for nulo, a função armazena o resultado do primeiro (e possivelmente único) caractere no destino. Se caracteres de saída adicionais forem necessários, um valor é definido *estado*, de modo que as chamadas subsequentes para a função os caracteres adicionais e retornam o valor -3. Se não houver mais caracteres de saída forem necessárias, em seguida *estado* é definido como estado inicial do deslocamento.

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
