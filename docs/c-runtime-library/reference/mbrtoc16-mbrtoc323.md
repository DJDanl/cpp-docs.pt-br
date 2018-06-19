---
title: mbrtoc16, mbrtoc323 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp
- devlang-cpp
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- mbrtoc16 function
- mbrtoc32 function
ms.assetid: 099ade4d-56f7-4e61-8b45-493f1d7a64bd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a12e90f9a4bc0cc27df421c27d77a1b9b69334b9
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32405296"
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
Ponteiro para o **char16_t** ou **char32_t** equivalente do caractere multibyte para converter. Se for null, a função não armazenará um valor.

*Código-fonte*<br/>
O ponteiro para a cadeia de caracteres multibyte a ser convertida.

*max_bytes*<br/>
O número máximo de bytes em *fonte* para examinar para um caractere para converter. Isso deve ser um valor entre 1 e o número de bytes, incluindo qualquer terminador nulo, restantes na *fonte*.

*state*<br/>
Ponteiro para um **mbstate_t** objeto de estado de conversão usado para interpretar a cadeia de caracteres multibyte para um ou mais caracteres de saída.

## <a name="return-value"></a>Valor de retorno

Em caso de sucesso, retorna o valor da primeira dessas condições que se aplica, considerando atual *estado* valor:

|Valor|Condição|
|-----------|---------------|
|0|O próximo *max_bytes* ou menos caracteres convertidos de *fonte* correspondem ao caractere grande nulo, que é o valor armazenado se *destino* não é nulo.<br /><br /> *estado* contém o estado inicial de turno.|
|Entre 1 e *max_bytes*, inclusive|O valor retornado é o número de bytes de *fonte* que concluir um caractere multibyte válido. O caractere largo convertido será armazenado se *destino* não é nulo.|
|-3|O próximo caractere largo resultante de uma chamada anterior para a função foi armazenado no *destino* se *destino* não é nulo. Nenhum bytes do *fonte* são consumidos por essa chamada à função.<br /><br /> Quando *fonte* aponta para um caractere multibyte que requer mais de um caractere largo para representar (por exemplo, um par substituto), em seguida, o *estado* valor é atualizado para que grava a próxima chamada de função  o caractere adicional.|
|-2|O próximo *max_bytes* bytes representam um incompleta, mas os caracteres multibyte, potencialmente válido. Nenhum valor é armazenado em *destino*. Esse resultado pode ocorrer se *max_bytes* é zero.|
|-1|Ocorreu um erro de codificação. O próximo *max_bytes* ou menos bytes não contribuem para um caractere multibyte completo e válido. Nenhum valor é armazenado em *destino*.<br /><br /> **EILSEQ** é armazenado em **errno** e o estado de conversão *estado* não está especificado.|

## <a name="remarks"></a>Comentários

O **mbrtoc16** função lê até *max_bytes* bytes do *fonte* para localizar o primeiro caractere multibyte completo, válido e armazena o equivalente UTF-16 caractere *destino*. Os bytes de origem são interpretados de acordo com a localidade de multibyte do thread atual. Se o caractere de multibyte exige mais de um caractere de saída UTF-16 como um par substituto, o *estado* valor é definido para armazenar o próximo caractere UTF-16 no *destino* na próxima chamada para **mbrtoc16**. O **mbrtoc32** é idêntica, mas a saída é armazenada como um caractere UTF-32.

Se *fonte* for null, essas funções de retorno o equivalente de uma chamada feita usando argumentos de **nulo** para *destino*, **""** para *fonte*e 1 para *max_bytes*. Os valores passados do *destino* e *max_bytes* são ignorados.

Se *fonte* é não nulo, a função começa no início da cadeia de caracteres e inspeciona até *max_bytes* bytes para determinar o número de bytes necessários para concluir o próximo caractere multibyte, incluindo Nenhuma sequência de turno. Se os bytes examinados contiverem um caractere multibyte válido e completo, a função converterá o caractere no caractere ou caracteres largos de 16 bits ou 32 bits equivalentes. Se *destino* é não nulo, os repositórios de função, o resultado da primeira (e possivelmente somente) de caracteres no destino. Se os caracteres de saída adicionais forem necessários, um valor é definido *estado*, de modo que as chamadas subsequentes para a função os caracteres adicionais de saída e retornam o valor de -3. Se não houver mais caracteres de saída são necessários, em seguida, *estado* está definido para o estado inicial de turno.

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
