---
title: 'Gerenciamento de memória: Blocos de memória redimensionáveis'
ms.date: 11/04/2016
helpviewer_keywords:
- memory blocks [MFC], resizable
- memory [MFC], corruption
- memory allocation [MFC], memory block size
- memory blocks [MFC], allocating
- blocks [MFC], memory allocation
- resizable memory blocks [MFC]
ms.assetid: f0efe6f4-a3ed-4541-9195-51ec1291967a
ms.openlocfilehash: 124a2599e1523d5393fcf6255c88de0fd8cd72cd
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62219129"
---
# <a name="memory-management-resizable-memory-blocks"></a>Gerenciamento de memória: Blocos de memória redimensionáveis

O **novos** e **excluir** operadores, descritas no artigo [gerenciamento de memória: Exemplos](../mfc/memory-management-examples.md), são bons para alocando e desalocando objetos e blocos de memória de tamanho fixo. Ocasionalmente, seu aplicativo pode precisar de blocos de memória redimensionáveis. Você deve usar as funções de biblioteca de tempo de execução do C padrão [malloc](../c-runtime-library/reference/malloc.md), [realloc](../c-runtime-library/reference/realloc.md), e [livre](../c-runtime-library/reference/free.md) para gerenciar os blocos no heap de memória redimensionáveis.

> [!IMPORTANT]
>  Misturar as **novos** e **excluir** operadores com as funções de alocação de memória redimensionáveis no mesmo bloco de memória resulta em memória corrompida na versão de depuração do MFC. Você não deve usar **realloc** em um bloco de memória alocado com **novos**. Da mesma forma, você deve alocar um bloco de memória com o **novos** operador e excluí-lo com **livre**, ou usar o **excluir** operador em um bloco de memória alocado com **malloc**.

## <a name="see-also"></a>Consulte também

[Gerenciamento de memória: alocação de heap](../mfc/memory-management-heap-allocation.md)
