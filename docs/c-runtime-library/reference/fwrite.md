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
- api-ms-win-crt-private-l1-1-0.dll
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
ms.openlocfilehash: b604819391629d057850c17466807e7c329c472d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87198587"
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

### <a name="parameters"></a>parâmetros

*completo*<br/>
Ponteiro para os dados a serem gravados.

*size*<br/>
Tamanho do item, em bytes.

*contagem*<br/>
Máximo de itens a serem gravados.

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor retornado

**fwrite** retorna o número de itens completos gravados, o que pode ser menor que a *contagem* se ocorrer um erro. Além disso, em caso de erro, não será possível determinar o indicador de posição do arquivo. Se o *fluxo* ou o *buffer* for um ponteiro nulo ou se um número ímpar de bytes a serem gravados for especificado no modo Unicode, a função invocará o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essa função definirá **errno** como **EINVAL** e retornará 0.

## <a name="remarks"></a>Comentários

A função **fwrite** grava até a *contagem* de itens, com *tamanho* de comprimento cada, do *buffer* para o *fluxo*de saída. O ponteiro de arquivo associado ao *fluxo* (se houver) é incrementado pelo número de bytes realmente gravados. Se o *fluxo* for aberto no modo de texto, cada alimentação de linha será substituído por um par de retorno de carro-alimentação de linha. A substituição não interfere no valor retornado.

Quando *o fluxo* é aberto no modo de conversão Unicode — por exemplo, se o *fluxo* for aberto chamando **fopen** e usando um parâmetro de modo que inclui **CCS = Unicode**, **CCS = UTF-16LE**ou **CCS = UTF-8**, ou se o modo for alterado para um modo de conversão Unicode usando **_setmode** e um parâmetro de modo que inclui **_O_WTEXT**, **_O_U16TEXT**ou **_O_U8TEXT**— o*buffer* será interpretado como um ponteiro para uma matriz de **`wchar_t`** que contenha dados UTF-16. Tentar gravar uma quantidade ímpar de bytes nesse modo gera um erro de validação de parâmetro.

Como essa função bloqueia o thread da chamada, ela é thread-safe. Para uma versão sem bloqueio, consulte **_fwrite_nolock**.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

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
