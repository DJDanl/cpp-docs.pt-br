---
title: _CrtCheckMemory
ms.date: 11/04/2016
apiname:
- _CrtCheckMemory
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
apitype: DLLExport
f1_keywords:
- CrtCheckMemory
- _CrtCheckMemory
helpviewer_keywords:
- _CrtCheckMemory function
- CrtCheckMemory function
ms.assetid: 457cc72e-60fd-4177-ab5c-6ae26a420765
ms.openlocfilehash: cb39a76c140934dabdd1269c02aba6018691f917
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50537144"
---
# <a name="crtcheckmemory"></a>_CrtCheckMemory

Confirma a integridade dos blocos de memória alocados no heap de depuração (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C

int _CrtCheckMemory( void );
```

## <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, **crtcheckmemory** retorna TRUE; caso contrário, a função retornará FALSE.

## <a name="remarks"></a>Comentários

O **crtcheckmemory** função valida a memória alocada pelo Gerenciador de heap de depuração verificando o heap base subjacente e inspecionando cada bloco de memória. Se uma inconsistência de memória ou de erro for encontrada no heap base subjacente, as informações de cabeçalho de depuração ou buffers de substituição, **crtcheckmemory** gera um relatório de depuração com informações que descrevem a condição de erro. Quando [Debug](../../c-runtime-library/debug.md) não está definido, as chamadas a **crtcheckmemory** são removidas durante o pré-processamento.

O comportamento de **crtcheckmemory** pode ser controlado definindo os campos de bit a [crtdbgflag](../../c-runtime-library/crtdbgflag.md) sinalizador usando o [crtsetdbgflag](crtsetdbgflag.md) função. Ativar o **crtdbg_check_always_df** resultados Diante do campo de bit **crtcheckmemory** que está sendo chamado sempre que uma operação de alocação de memória é solicitada. Embora esse método reduza a velocidade de execução, ele é útil para capturar erros rapidamente. Ativar o **crtdbg_alloc_mem_df** faz com que campo de bits **crtcheckmemory** para não verificar a pilha e retornar imediatamente **verdadeiro**.

Como essa função retorna **TRUE** ou **FALSE**, ela pode ser passada para uma das macros [_ASSERT](assert-asserte-assert-expr-macros.md) para criar um mecanismo simples de tratamento de erro de depuração. O seguinte exemplo causa uma falha de asserção se o dano é detectado no heap:

```C
_ASSERTE( _CrtCheckMemory( ) );
```

Para obter mais informações sobre como **crtcheckmemory** pode ser usado com outras funções de depuração, consulte [funções de relatório de estado de Heap](/visualstudio/debugger/crt-debug-heap-details). Para obter uma visão geral do gerenciamento de memória e do heap de depuração, consulte [Detalhes do heap de depuração do CRT](/visualstudio/debugger/crt-debug-heap-details).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_CrtCheckMemory**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

Para obter um exemplo de como usar **crtcheckmemory**, consulte [crt_dbg1](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/crt/crt_dbg1).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
[_crtDbgFlag](../../c-runtime-library/crtdbgflag.md)<br/>
[_CrtSetDbgFlag](crtsetdbgflag.md)<br/>
