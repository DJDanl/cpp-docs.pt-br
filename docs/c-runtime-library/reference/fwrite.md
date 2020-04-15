---
title: fwrite
ms.date: 4/2/2020
api_name:
- fwrite
- _o_fwrite
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
- api-ms-win-crt-stdio-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- fwrite
helpviewer_keywords:
- streams, writing data to
- fwrite function
ms.assetid: 7afacf3a-72d7-4a50-ba2e-bea1ab9f4124
ms.openlocfilehash: a5bd6da3c8d16189f7ff0db744901e03513acc21
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81345400"
---
# <a name="fwrite"></a>fwrite

Grava dados em um fluxo.

## <a name="syntax"></a>Sintaxe

```C
size_t fwrite(
   const void *buffer,
   size_t size,
   size_t count,
   FILE *stream
);
```

### <a name="parameters"></a>Parâmetros

*Buffer*<br/>
Ponteiro para os dados a serem gravados.

*Tamanho*<br/>
Tamanho do item, em bytes.

*contagem*<br/>
Máximo de itens a serem gravados.

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor retornado

**fwrite** retorna o número de itens completos realmente escritos, o que pode ser menor do que *a contagem* se ocorrer um erro. Além disso, em caso de erro, não será possível determinar o indicador de posição do arquivo. Se o *fluxo* ou *buffer* for um ponteiro nulo ou se um número ímpar de bytes a serem gravados for especificado no modo Unicode, a função invoca o manipulador de parâmetros inválidos, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, esta função define **errno** para **EINVAL** e retorna 0.

## <a name="remarks"></a>Comentários

A função **fwrite** grava até *para contar* itens, de *tamanho* cada, do *buffer* ao *fluxo*de saída . O ponteiro de arquivo associado ao *fluxo* (se houver um) é incrementado pelo número de bytes realmente escritos. Se *o fluxo* for aberto no modo texto, cada alimentação da linha será substituída por um par de feed de linha de retorno do transporte. A substituição não interfere no valor retornado.

Quando *o fluxo* é aberto no modo de tradução Unicode — por exemplo, se o *fluxo* for aberto chamando **fopen** e usando um parâmetro de modo que inclui **ccs=UNICODE**, **ccs=UTF-16LE**, ou **ccs=UTF-8**, ou se o modo for alterado para um modo de tradução Unicode usando **_setmode** e um parâmetro de modo que inclua **_O_WTEXT**, **_O_U16TEXT**ou **_O_U8TEXT**—*buffer* é interpretado como um ponteiro para um conjunto de **wchar_t** que contém Tentar gravar uma quantidade ímpar de bytes nesse modo gera um erro de validação de parâmetro.

Como essa função bloqueia o thread da chamada, ela é thread-safe. Para obter uma versão sem bloqueio, consulte **_fwrite_nolock**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fwrite**|\<stdio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [thread](fread.md).

## <a name="see-also"></a>Confira também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[_setmode](setmode.md)<br/>
[fread](fread.md)<br/>
[_fwrite_nolock](fwrite-nolock.md)<br/>
[_write](write.md)<br/>
