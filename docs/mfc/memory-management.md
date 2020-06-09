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
ms.openlocfilehash: 464a31491f2c3017453bdd5bbdc8b059d348eb3c
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626256"
---
# <a name="memory-management"></a>Gerenciamento de memória

Este grupo de artigos descreve como aproveitar os serviços de uso geral do biblioteca MFC (MFC) relacionados ao gerenciamento de memória. A alocação de memória pode ser dividida em duas categorias principais: alocações de quadros e alocações de heap.

Uma das principais diferenças entre as duas técnicas de alocação é que, com a alocação de quadros, você normalmente trabalha com o próprio bloco de memória real, ao passo que, com a alocação de heap, sempre é fornecido um ponteiro para o bloco de memória. Outra grande diferença entre os dois esquemas é que os objetos de quadro são excluídos automaticamente, enquanto os objetos de heap devem ser explicitamente excluídos pelo programador.

Para obter informações não MFC sobre o gerenciamento de memória em programas para Windows, consulte [Gerenciamento de memória](/windows/win32/memory/memory-management) no SDK do Windows.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Alocação de quadros](memory-management-frame-allocation.md)

- [Alocação de heap](memory-management-heap-allocation.md)

- [Alocando memória para uma matriz](memory-management-examples.md)

- [Desalocando memória para uma matriz do heap](memory-management-examples.md)

- [Alocando memória para uma estrutura de dados](memory-management-examples.md)

- [Alocando memória para um objeto](memory-management-examples.md)

- [Blocos de memória redimensionáveis](memory-management-resizable-memory-blocks.md)

## <a name="see-also"></a>Consulte também

[Conceitos](mfc-concepts.md)<br/>
[Tópicos MFC gerais](general-mfc-topics.md)
