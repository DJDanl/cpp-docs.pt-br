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
ms.openlocfilehash: 74ae94146b1ec711b586ea1fecbbc89a47b40b5e
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626276"
---
# <a name="memory-management-resizable-memory-blocks"></a>Gerenciamento de memória: blocos de memória redimensionáveis

Os operadores **novo** e **excluir** , descritos no artigo [Gerenciamento de memória: exemplos](memory-management-examples.md), são bons para alocar e desalocar blocos de memória de tamanho fixo e objetos. Ocasionalmente, seu aplicativo pode precisar de blocos de memória redimensionáveis. Você deve usar as funções de biblioteca de tempo de execução do C padrão [malloc](../c-runtime-library/reference/malloc.md), [realloc](../c-runtime-library/reference/realloc.md)e [Free](../c-runtime-library/reference/free.md) para gerenciar blocos de memória redimensionáveis no heap.

> [!IMPORTANT]
> A combinação dos operadores **New** e **delete** com as funções de alocação de memória redimensionável no mesmo bloco de memória resultará na memória corrompida na versão de depuração do MFC. Você não deve usar a **realocação** em um bloco de memória alocado com o **novo**. Da mesma forma, você não deve alocar um bloco de memória com o operador **New** e excluí-lo com **Free**ou usar o operador **delete** em um bloco de memória alocada com **malloc**.

## <a name="see-also"></a>Consulte também

[Gerenciamento de memória: alocação do heap](memory-management-heap-allocation.md)
