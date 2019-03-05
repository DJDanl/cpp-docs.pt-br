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
ms.openlocfilehash: 1c7f901009d5e1e7f0af20d493bb748b46b18480
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57281285"
---
# <a name="memory-management"></a>Gerenciamento de memória

Esse grupo de artigos descreve como tirar proveito dos serviços de uso geral da Microsoft Foundation Class Library (MFC) relacionados ao gerenciamento de memória. Alocação de memória pode ser dividida em duas categorias principais: alocações e alocações de heap de quadro.

Uma diferença principal entre as técnicas de duas alocação é que com a alocação de quadro, que você normalmente trabalha com a memória real bloquear em si, embora com alocação de heap você sempre terá um ponteiro para o bloco de memória. Uma outra grande diferença entre os dois esquemas é que objetos de quadro são automaticamente excluídos, enquanto os objetos de heap devem ser excluídos explicitamente pelo programador.

Para obter informações sobre o gerenciamento de memória em programas para Windows não MFC, consulte [gerenciamento de memória](/windows/desktop/memory/memory-management) no SDK do Windows.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Alocação de quadro](../mfc/memory-management-frame-allocation.md)

- [Alocação de heap](../mfc/memory-management-heap-allocation.md)

- [Ao alocar memória para uma matriz](../mfc/memory-management-examples.md)

- [Desalocando memória para uma matriz do heap](../mfc/memory-management-examples.md)

- [Ao alocar memória para uma estrutura de dados](../mfc/memory-management-examples.md)

- [Ao alocar memória para um objeto](../mfc/memory-management-examples.md)

- [Blocos de memória redimensionáveis](../mfc/memory-management-resizable-memory-blocks.md)

## <a name="see-also"></a>Consulte também

[Conceitos](../mfc/mfc-concepts.md)<br/>
[Tópicos gerais do MFC](../mfc/general-mfc-topics.md)
