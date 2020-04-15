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
ms.openlocfilehash: b048b60a5512ecc54750cb980ca67e2373e2c837
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364783"
---
# <a name="memory-management-resizable-memory-blocks"></a>Gerenciamento de memória: blocos de memória redimensionáveis

Os **novos** e **exclusões** operadoras, descritas no artigo [Gerenciamento de Memória: Exemplos](../mfc/memory-management-examples.md), são bons para alocar e negociar blocos de memória de tamanho fixo e objetos. Ocasionalmente, sua aplicação pode precisar de blocos de memória resizáveis. Você deve usar as funções padrão de biblioteca de tempo de [execução C malloc](../c-runtime-library/reference/malloc.md), [realloc](../c-runtime-library/reference/realloc.md), e [livre](../c-runtime-library/reference/free.md) para gerenciar blocos de memória resizáveis no heap.

> [!IMPORTANT]
> A mistura dos **novos** e **exclusões** dos operadores com as funções de alocação de memória resizáveis no mesmo bloco de memória resultará em memória corrompida na versão Debug do MFC. Você não deve usar **realloc** em um bloco de memória alocado com **novo**. Da mesma forma, você não deve alocar um bloco de memória com o **novo** operador e excluí-lo **gratuitamente,** ou usar o operador **de exclusão** em um bloco de memória alocado com **malloc**.

## <a name="see-also"></a>Confira também

[Gerenciamento de memória: alocação do heap](../mfc/memory-management-heap-allocation.md)
