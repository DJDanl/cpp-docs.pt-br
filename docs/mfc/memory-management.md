---
title: Gerenciamento de memória
ms.date: 11/04/2016
helpviewer_keywords:
- memory [MFC]
- MFC, memory management
- memory allocation [MFC]
- memory [MFC], managing
- memory allocation [MFC], MFC
ms.assetid: 934ac81b-d630-4232-88e5-ea74f7187987
ms.openlocfilehash: 5d81bd0a8bdd24059951cba5c8b69751b3d1db86
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69508268"
---
# <a name="memory-management"></a>Gerenciamento de memória

Este grupo de artigos descreve como aproveitar os serviços de uso geral do biblioteca MFC (MFC) relacionados ao gerenciamento de memória. A alocação de memória pode ser dividida em duas categorias principais: alocações de quadros e alocações de heap.

Uma das principais diferenças entre as duas técnicas de alocação é que, com a alocação de quadros, você normalmente trabalha com o próprio bloco de memória real, ao passo que, com a alocação de heap, sempre é fornecido um ponteiro para o bloco de memória. Outra grande diferença entre os dois esquemas é que os objetos de quadro são excluídos automaticamente, enquanto os objetos de heap devem ser explicitamente excluídos pelo programador.

Para obter informações não MFC sobre o gerenciamento de memória em programas para Windows, consulte [Gerenciamento de memória](/windows/win32/memory/memory-management) no SDK do Windows.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Alocação de quadros](../mfc/memory-management-frame-allocation.md)

- [Alocação de heap](../mfc/memory-management-heap-allocation.md)

- [Alocando memória para uma matriz](../mfc/memory-management-examples.md)

- [Desalocando memória para uma matriz do heap](../mfc/memory-management-examples.md)

- [Alocando memória para uma estrutura de dados](../mfc/memory-management-examples.md)

- [Alocando memória para um objeto](../mfc/memory-management-examples.md)

- [Blocos de memória redimensionáveis](../mfc/memory-management-resizable-memory-blocks.md)

## <a name="see-also"></a>Consulte também

[Conceitos](../mfc/mfc-concepts.md)<br/>
[Tópicos gerais do MFC](../mfc/general-mfc-topics.md)
