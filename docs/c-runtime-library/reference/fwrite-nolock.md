---
title: _fwrite_nolock
ms.date: 11/04/2016
apiname:
- _fwrite_nolock
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
- api-ms-win-crt-stdio-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _fwrite_nolock
- fwrite_nolock
helpviewer_keywords:
- fwrite_nolock function
- streams, writing data to
- _fwrite_nolock function
ms.assetid: 2b4ec6ce-742e-4615-8407-44a0a18ec1d7
ms.openlocfilehash: 1c899e34e19547b30a42135f3f818f220f1bc5b7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50626041"
---
# <a name="fwritenolock"></a>_fwrite_nolock

Grava dados em um fluxo sem bloquear o thread.

## <a name="syntax"></a>Sintaxe

```C
size_t _fwrite_nolock(
   const void *buffer,
   size_t size,
   size_t count,
   FILE *stream
);
```

### <a name="parameters"></a>Parâmetros

*buffer*<br/>
Ponteiro para os dados a serem gravados.

*size*<br/>
Tamanho do item em bytes.

*count*<br/>
Máximo de itens a serem gravados.

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor de retorno

O mesmo que [fwrite](fwrite.md).

## <a name="remarks"></a>Comentários

Essa função é uma versão sem bloqueio do **fwrite**. Ela é idêntica à **fwrite** , exceto que não está protegida contra interferência de outros threads. Ela pode ser mais rápida, porque não incorre na sobrecarga de bloquear outros threads. Use esta função apenas em contextos thread-safe, como aplicativos de thread único ou em que o escopo de chamada já trata do isolamento de threads.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**_fwrite_nolock**|\<stdio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [thread](fread.md).

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fread](fread.md)<br/>
[_write](write.md)<br/>
