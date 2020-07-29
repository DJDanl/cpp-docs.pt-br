---
title: 'Gerenciamento de memória: blocos de memória redimensionáveis'
ms.date: 11/04/2016
helpviewer_keywords:
- memory blocks [MFC], resizable
- memory [MFC], corruption
- memory allocation [MFC], memory block size
- memory blocks [MFC], allocating
- blocks [MFC], memory allocation
- resizable memory blocks [MFC]
ms.assetid: f0efe6f4-a3ed-4541-9195-51ec1291967a
ms.openlocfilehash: 308b5aa00aeb1f0e7887ad90bad79a28b361d7c7
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217916"
---
# <a name="memory-management-resizable-memory-blocks"></a>Gerenciamento de memória: blocos de memória redimensionáveis

Os **`new`** **`delete`** operadores e, descritos no artigo [Gerenciamento de memória: exemplos](memory-management-examples.md), são bons para alocar e desalocar blocos de memória de tamanho fixo e objetos. Ocasionalmente, seu aplicativo pode precisar de blocos de memória redimensionáveis. Você deve usar as funções de biblioteca de tempo de execução do C padrão [malloc](../c-runtime-library/reference/malloc.md), [realloc](../c-runtime-library/reference/realloc.md)e [Free](../c-runtime-library/reference/free.md) para gerenciar blocos de memória redimensionáveis no heap.

> [!IMPORTANT]
> A combinação **`new`** dos **`delete`** operadores e com as funções de alocação de memória redimensionável no mesmo bloco de memória resultará na memória corrompida na versão de depuração do MFC. Você não deve usar **realloc** em um bloco de memória alocado com **`new`** . Da mesma forma, você não deve alocar um bloco de memória com o **`new`** operador e excluí-lo com **Free**ou usar o **`delete`** operador em um bloco de memória alocado com **malloc**.

## <a name="see-also"></a>Confira também

[Gerenciamento de memória: alocação de heap](memory-management-heap-allocation.md)
