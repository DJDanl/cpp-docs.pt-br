---
title: 'Gerenciamento de memória: Blocos de memória redimensionáveis | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- memory blocks [MFC], resizable
- memory [MFC], corruption
- memory allocation [MFC], memory block size
- memory blocks [MFC], allocating
- blocks [MFC], memory allocation
- resizable memory blocks [MFC]
ms.assetid: f0efe6f4-a3ed-4541-9195-51ec1291967a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3bbd97899261f85454824fcab261d330b04e25fd
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="memory-management-resizable-memory-blocks"></a>Gerenciamento de memória: blocos de memória redimensionáveis
O **novo** e **excluir** operadores, descritas no artigo [gerenciamento de memória: exemplos](../mfc/memory-management-examples.md), são bons para alocando e desalocando blocos de memória de tamanho fixo e objetos. Ocasionalmente, seu aplicativo pode ser necessário blocos de memória redimensionáveis. Você deve usar as funções de biblioteca de tempo de execução C padrão [malloc](../c-runtime-library/reference/malloc.md), [realloc](../c-runtime-library/reference/realloc.md), e [livre](../c-runtime-library/reference/free.md) para gerenciar os blocos de memória redimensionáveis no heap.  
  
> [!IMPORTANT]
>  Combinação de **novo** e **excluir** operadores com as funções de alocação de memória redimensionáveis no mesmo bloco de memória resultará em memória corrompida na versão de depuração do MFC. Você não deve usar `realloc` em um bloco de memória alocada com **novo**. Da mesma forma, você deve alocar um bloco de memória com o **novo** operador e excluí-lo com **livre**, ou use o **excluir** operador em um bloco de memória alocada com `malloc`.  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciamento de memória: alocação do heap](../mfc/memory-management-heap-allocation.md)

