---
title: _flushall
ms.date: 4/2/2020
api_name:
- _flushall
- _o__flushall
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
- _flushall
helpviewer_keywords:
- flushall function
- flushing streams
- streams, flushing
- _flushall function
ms.assetid: 2cd73562-6d00-4ca2-b13c-80d0ae7870b5
ms.openlocfilehash: 93181c0fe941a1c5e259e706771495666329bcb3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81346614"
---
# <a name="_flushall"></a>_flushall

Libera todos os fluxos, limpa todos os buffers.

## <a name="syntax"></a>Sintaxe

```C
int _flushall( void );
```

## <a name="return-value"></a>Valor retornado

**_flushall** retorna o número de fluxos abertos (entrada e saída). Nenhum erro é retornado.

## <a name="remarks"></a>Comentários

Por padrão, a função **_flushall** grava para arquivos apropriados o conteúdo de todos os buffers associados a fluxos de saída abertas. Todos os buffers associados a fluxos de entrada abertos são limpos do seu conteúdo atual. (Normalmente, esses buffers são mantidos pelo sistema operacional, que determina o momento ideal para gravar os dados automaticamente no disco: quando um buffer estiver cheio, quando um fluxo for fechado ou quando um programa for encerrado normalmente sem fechar fluxos.)

Se uma leitura seguir uma chamada para **_flushall,** novos dados são lidos dos arquivos de entrada nos buffers. Todos os fluxos permanecem abertos após a chamada para **_flushall**.

O recurso de confirmar no disco da biblioteca em tempo de execução permite assegurar que dados críticos sejam gravados diretamente no disco em vez de em buffers do sistema operacional. Sem reescrever um programa existente, você pode habilitar esse recurso vinculando os arquivos de objeto do programa com o Commode.obj. No arquivo executável resultante, chamadas para **_flushall** gravar o conteúdo de todos os buffers em disco. Apenas **_flushall** e [fflush](fflush.md) são afetados por Commode.obj.

Para obter informações sobre como controlar o recurso de confirmação em disco, consulte [E/S de fluxo](../../c-runtime-library/stream-i-o.md), [fopen](fopen-wfopen.md) e [_fdopen](fdopen-wfdopen.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**_flushall**|\<stdio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_flushall.c
// This program uses _flushall
// to flush all open buffers.

#include <stdio.h>

int main( void )
{
   int numflushed;

   numflushed = _flushall();
   printf( "There were %d streams flushed\n", numflushed );
}
```

```Output
There were 3 streams flushed
```

## <a name="see-also"></a>Confira também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[_commit](commit.md)<br/>
[fclose, _fcloseall](fclose-fcloseall.md)<br/>
[fflush](fflush.md)<br/>
[setvbuf](setvbuf.md)<br/>
