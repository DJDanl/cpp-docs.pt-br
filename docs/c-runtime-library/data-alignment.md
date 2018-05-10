---
title: Alinhamento de dados | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- data.alignment
dev_langs:
- C++
helpviewer_keywords:
- data alignment [C++]
ms.assetid: 35ac3d2d-a4b3-421b-954f-b7372b1f18e1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: aa83c067e8a2f6794adde13ed8f163ac7ee52680
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="data-alignment"></a>Alinhamento de dados

As seguintes funções de tempo de execução C dão suporte ao alinhamento de dados.

## <a name="data-alignment-routines"></a>Rotinas de alinhamento de dados

|Rotina|Use|
|-------------|---------|
|[_aligned_free](../c-runtime-library/reference/aligned-free.md)|Libera um bloco de memória que foi alocado com [_aligned_malloc](../c-runtime-library/reference/aligned-malloc.md)ou [_aligned_offset_malloc](../c-runtime-library/reference/aligned-offset-malloc.md).|
|[_aligned_free_dbg](../c-runtime-library/reference/aligned-free-dbg.md)|Libera um bloco de memória que foi alocado com [aligned_malloc](../c-runtime-library/reference/aligned-malloc.md) ou [aligned_offset_malloc](../c-runtime-library/reference/aligned-offset-malloc.md) (somente depuração).|
|[_aligned_malloc](../c-runtime-library/reference/aligned-malloc.md)|Aloca memória em um limite de alinhamento especificado.|
|[_aligned_malloc_dbg](../c-runtime-library/reference/aligned-malloc-dbg.md)|Aloca memória em um limite de alinhamento especificado com espaço adicional para um cabeçalho de depuração e buffers de substituição (apenas versão de depuração).|
|[_aligned_msize](../c-runtime-library/reference/aligned-msize.md)|Retorna o tamanho de um bloco de memória alocado no heap.|
|[_aligned_msize_dbg](../c-runtime-library/reference/aligned-msize-dbg.md)|Retorna o tamanho de um bloco de memória alocado no heap (somente versão de depuração).|
|[_aligned_offset_malloc](../c-runtime-library/reference/aligned-offset-malloc.md)|Aloca memória em um limite de alinhamento especificado.|
|[_aligned_offset_malloc_dbg](../c-runtime-library/reference/aligned-offset-malloc-dbg.md)|Aloca memória em um limite de alinhamento especificado (somente versão de depuração).|
|[_aligned_offset_realloc](../c-runtime-library/reference/aligned-offset-realloc.md)|Altera o tamanho de um bloco de memória que foi alocado com [_aligned_malloc](../c-runtime-library/reference/aligned-malloc.md) ou [_aligned_offset_malloc](../c-runtime-library/reference/aligned-offset-malloc.md).|
|[_aligned_offset_realloc_dbg](../c-runtime-library/reference/aligned-offset-realloc-dbg.md)|Altera o tamanho de um bloco de memória alocado com [_aligned_malloc](../c-runtime-library/reference/aligned-malloc.md) ou [_aligned_offset_malloc](../c-runtime-library/reference/aligned-offset-malloc.md) (somente versão de depuração).|
|[_aligned_offset_recalloc](../c-runtime-library/reference/aligned-offset-recalloc.md)|Altera o tamanho de um bloco de memória que foi alocado com [_aligned_malloc](../c-runtime-library/reference/aligned-malloc.md) ou [_aligned_offset_malloc](../c-runtime-library/reference/aligned-offset-malloc.md) e inicializa a memória como 0.|
|[_aligned_offset_recalloc_dbg](../c-runtime-library/reference/aligned-offset-recalloc-dbg.md)|Altera o tamanho de um bloco de memória que foi alocado com [_aligned_malloc](../c-runtime-library/reference/aligned-malloc.md) ou [_aligned_offset_malloc](../c-runtime-library/reference/aligned-offset-malloc.md) e inicializa a memória como 0 (somente versão de depuração).|
|[_aligned_realloc](../c-runtime-library/reference/aligned-realloc.md)|Altera o tamanho de um bloco de memória que foi alocado com [_aligned_malloc](../c-runtime-library/reference/aligned-malloc.md) ou [_aligned_offset_malloc](../c-runtime-library/reference/aligned-offset-malloc.md).|
|[_aligned_realloc_dbg](../c-runtime-library/reference/aligned-realloc-dbg.md)|Altera o tamanho de um bloco de memória alocado com [_aligned_malloc](../c-runtime-library/reference/aligned-malloc.md) ou [_aligned_offset_malloc](../c-runtime-library/reference/aligned-offset-malloc.md) (somente versão de depuração).|
|[_aligned_recalloc](../c-runtime-library/reference/aligned-recalloc.md)|Altera o tamanho de um bloco de memória que foi alocado com [_aligned_malloc](../c-runtime-library/reference/aligned-malloc.md) ou [_aligned_offset_malloc](../c-runtime-library/reference/aligned-offset-malloc.md) e inicializa a memória como 0.|
|[_aligned_recalloc_dbg](../c-runtime-library/reference/aligned-recalloc-dbg.md)|Altera o tamanho de um bloco de memória que foi alocado com [_aligned_malloc](../c-runtime-library/reference/aligned-malloc.md) ou [_aligned_offset_malloc](../c-runtime-library/reference/aligned-offset-malloc.md) e inicializa a memória como 0 (somente versão de depuração).|

## <a name="see-also"></a>Consulte também

[Rotinas de tempo de execução C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>