---
title: Alocação de memória
ms.date: 11/04/2016
f1_keywords:
- c.memory
helpviewer_keywords:
- memory allocation, routines
- memory, managing
- memory, allocation
ms.assetid: b4470556-a128-4782-9943-2ccf7a7d9979
ms.openlocfilehash: 2adfd0de21a5dc7a1f3aa65041a6b8a9a9cf1d69
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87189500"
---
# <a name="memory-allocation"></a>Alocação de memória

Use estas rotinas para alocar, liberar e realocar memória.

## <a name="memory-allocation-routines"></a>Rotinas de alocação da memória

|Rotina|Uso|
|-------------|---------|
|[_alloca](../c-runtime-library/reference/alloca.md), [_malloca](../c-runtime-library/reference/malloca.md)|Alocar memória da pilha|
|[calloc](../c-runtime-library/reference/calloc.md)|Alocar armazenamento para matriz, inicializando cada byte em bloco alocado como 0|
|[_calloc_dbg](../c-runtime-library/reference/calloc-dbg.md)|Versão de depuração de **calloc**. Disponível apenas em versões de depuração das bibliotecas em tempo de execução|
|[operador Delete](../c-runtime-library/operator-delete-crt.md)|Liberar bloco alocado|
|[operador delete&#91;&#93;](../c-runtime-library/delete-operator-crt.md)|Liberar bloco alocado|
|[_expand](../c-runtime-library/reference/expand.md)|Expandir ou reduzir bloco de memória sem movê-lo|
|[_expand_dbg](../c-runtime-library/reference/expand-dbg.md)|Versão de depuração de **_expand**. Disponível apenas em versões de depuração das bibliotecas em tempo de execução|
|[informações](../c-runtime-library/reference/free.md)|Liberar bloco alocado|
|[_free_dbg](../c-runtime-library/reference/free-dbg.md)|Versão de depuração de **free**. Disponível apenas em versões de depuração das bibliotecas em tempo de execução|
|[_freea](../c-runtime-library/reference/freea.md)|Liberar bloco alocado da pilha|
|[_get_heap_handle](../c-runtime-library/reference/get-heap-handle.md)|Obter Win32 HANDLE do heap CRT.|
|[_heapadd](../c-runtime-library/heapadd.md)|Adicionar memória ao heap|
|[_heapchk](../c-runtime-library/reference/heapchk.md)|Verificar consistência do heap|
|[_heapmin](../c-runtime-library/reference/heapmin.md)|Liberar memória não usada no heap|
|[_heapset](../c-runtime-library/heapset.md)|Preencher entradas do heap com valor especificado|
|[_heapwalk](../c-runtime-library/reference/heapwalk.md)|Retornar informações sobre cada entrada no heap|
|[malloc](../c-runtime-library/reference/malloc.md)|Alocar bloco de memória do heap|
|[_malloc_dbg](../c-runtime-library/reference/malloc-dbg.md)|Versão de depuração de **malloc**. Disponível apenas em versões de depuração das bibliotecas em tempo de execução|
|[_msize](../c-runtime-library/reference/msize.md)|Retornar tamanho do bloco alocado|
|[_msize_dbg](../c-runtime-library/reference/msize-dbg.md)|Versão de depuração de **_msize**. Disponível apenas em versões de depuração das bibliotecas em tempo de execução|
|[Novo](../c-runtime-library/operator-new-crt.md)|Alocar bloco de memória do heap|
|[new&#91;&#93;](../c-runtime-library/new-operator-crt.md)|Alocar bloco de memória do heap|
|[_query_new_handler](../c-runtime-library/reference/query-new-handler.md)|Retornar o endereço da rotina atual do novo manipulador, conforme definido por **_set_new_handler**|
|[_query_new_mode](../c-runtime-library/reference/query-new-mode.md)|Retornar inteiro indicando novo modo do manipulador definido por **_set_new_mode** para **malloc**|
|[realloc](../c-runtime-library/reference/realloc.md)|Realocar bloco para novo tamanho|
|[_realloc_dbg](../c-runtime-library/reference/realloc-dbg.md)|Versão de depuração de **realloc**. Disponível apenas em versões de depuração das bibliotecas em tempo de execução|
|[_set_new_handler](../c-runtime-library/reference/set-new-handler.md)|Habilitar mecanismo de tratamento de erros quando o **`new`** operador falhar (para alocar memória) e habilitar a compilação de bibliotecas padrão C++|
|[_set_new_mode](../c-runtime-library/reference/set-new-mode.md)|Definir novo modo do manipulador para **malloc**|

## <a name="see-also"></a>Confira também

[Rotinas de runtime C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>
