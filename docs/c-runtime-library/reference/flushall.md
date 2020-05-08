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
- api-ms-win-crt-private-l1-1-0.dll
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
ms.openlocfilehash: 1a53eeedd5dfa0f9c01fa5883a9db33e26e3ea17
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82911619"
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

Por padrão, a função **_flushall** grava em arquivos apropriados o conteúdo de todos os buffers associados a fluxos de saída abertos. Todos os buffers associados a fluxos de entrada abertos são limpos do seu conteúdo atual. (Normalmente, esses buffers são mantidos pelo sistema operacional, que determina o momento ideal para gravar os dados automaticamente no disco: quando um buffer estiver cheio, quando um fluxo for fechado ou quando um programa for encerrado normalmente sem fechar fluxos.)

Se uma leitura seguir uma chamada para **_flushall**, novos dados serão lidos dos arquivos de entrada para os buffers. Todos os fluxos permanecem abertos após a chamada para **_flushall**.

O recurso de confirmar no disco da biblioteca em tempo de execução permite assegurar que dados críticos sejam gravados diretamente no disco em vez de em buffers do sistema operacional. Sem reescrever um programa existente, você pode habilitar esse recurso vinculando os arquivos de objeto do programa com Commode. obj. No arquivo executável resultante, as chamadas para **_flushall** gravam o conteúdo de todos os buffers em disco. Somente **_flushall** e [fflush](fflush.md) são afetados por COMMODE. obj.

Para obter informações sobre como controlar o recurso de confirmação em disco, consulte [E/S de fluxo](../../c-runtime-library/stream-i-o.md), [fopen](fopen-wfopen.md) e [_fdopen](fdopen-wfdopen.md).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

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
