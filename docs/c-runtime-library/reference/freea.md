---
title: _freea | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _freea
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
- freea
- _freea
dev_langs:
- C++
helpviewer_keywords:
- _freea function
- freea function
- memory deallocation
ms.assetid: dcd30584-dd9d-443b-8c4c-13237a1cecac
caps.latest.revision: 18
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2a64de046f904d4652809f35598f2b4db2b3007f
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="freea"></a>_freea

Desaloca ou libera um bloco de memória.

## <a name="syntax"></a>Sintaxe

```C
void _freea(
   void *memblock
);
```

### <a name="parameters"></a>Parâmetros

*memblock*<br/>
Bloqueio de memória anteriormente alocado a ser liberado.

## <a name="return-value"></a>Valor de retorno

Nenhum.

## <a name="remarks"></a>Comentários

O **freea** função desaloca um bloco de memória (*memblock*) que antes era alocado por uma chamada para [malloca](malloca.md). **freea** verifica se a memória foi alocada no heap ou a pilha. Se ela foi alocada na pilha, **freea** não fará nada. Se tiver sido alocada no heap, o número de bytes liberados será equivalente ao número de bytes solicitados quando o bloco foi alocado. Se *memblock* é **nulo**, o ponteiro é ignorado e **freea** retorna imediatamente. Tentativa de liberar um ponteiro inválido (um ponteiro para um bloco de memória que não foi alocado por **malloca**) podem afetar as solicitações subsequentes de alocação e causar erros.

**freea** chamadas **livre** internamente se detectar que a memória é alocada no heap. Um marcador colocado na memória, no endereço imediatamente anterior à memória alocada, determina se a memória está no heap ou na pilha.

Se ocorrer um erro na liberação de memória, **errno** é definida com informações do sistema operacional da natureza da falha. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

Após um bloco de memória ter sido liberado, [_heapmin](heapmin.md) minimiza a quantidade de memória livre no heap juntando as regiões não utilizadas e liberando-as para o sistema operacional. A memória liberada que não for liberada para o sistema operacional será restaurada para o pool livre e ficará disponível para alocação novamente.

Uma chamada para **freea** deve acompanhar todas as chamadas para **malloca**. Também é um erro ao chamar **freea** duas vezes na mesma memória. Quando o aplicativo está vinculado com uma versão de depuração das bibliotecas de tempo de execução do C, particularmente com [malloc_dbg](malloc-dbg.md) recursos habilitados definindo **crtdbg_map_alloc**, é mais fácil localizar ausente ou duplicado chamadas para **freea**. Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [The CRT Debug Heap](/visualstudio/debugger/crt-debug-heap-details) (O heap de depuração do CRT).

**freea** está marcado como `__declspec(noalias)`, que significa que a função é garantia de não modificar variáveis globais. Para obter mais informações, consulte [noalias](../../cpp/noalias.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**_freea**|\<stdlib.h> e \<malloc.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Consulte o exemplo para [_malloca](malloca.md).

## <a name="see-also"></a>Consulte também

[Alocação de Memória](../../c-runtime-library/memory-allocation.md)<br/>
[_malloca](malloca.md)<br/>
[calloc](calloc.md)<br/>
[malloc](malloc.md)<br/>
[_malloc_dbg](malloc-dbg.md)<br/>
[realloc](realloc.md)<br/>
[_free_dbg](free-dbg.md)<br/>
[_heapmin](heapmin.md)<br/>
