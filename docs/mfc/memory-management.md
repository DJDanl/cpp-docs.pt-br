---
title: "Gerenciamento de memória | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- memory [MFC]
- MFC, memory management
- memory allocation [MFC]
- memory [MFC], managing
- memory allocation [MFC], MFC
ms.assetid: 934ac81b-d630-4232-88e5-ea74f7187987
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1a9e31fc1136249f843aa5dc96a4caffcccc7a85
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="memory-management"></a>Gerenciamento de memória
Este grupo de artigos descreve como tirar proveito dos serviços de uso gerais da Microsoft Foundation Class Library (MFC) relacionadas ao gerenciamento de memória. Alocação de memória pode ser dividida em duas categorias principais: alocações e as alocações de heap do quadro.  
  
 Uma diferença principal entre as técnicas de duas alocação é que com alocação de quadro, que você normalmente trabalha com a memória real bloquear em si, embora com alocação de heap você sempre terá um ponteiro para o bloco de memória. Uma outra grande diferença entre os dois esquemas é que objetos de quadro são automaticamente excluídos, enquanto os objetos do heap devem ser excluídos explicitamente pelo programador.  
  
 Para obter informações sobre o gerenciamento de memória em programas para Windows não MFC, consulte [gerenciamento de memória](http://msdn.microsoft.com/library/windows/desktop/aa366779) no SDK do Windows.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Alocação de quadro](../mfc/memory-management-frame-allocation.md)  
  
-   [Alocação de heap](../mfc/memory-management-heap-allocation.md)  
  
-   [Ao alocar memória para uma matriz](../mfc/memory-management-examples.md)  
  
-   [Desalocando memória para uma matriz de heap](../mfc/memory-management-examples.md)  
  
-   [Ao alocar memória para uma estrutura de dados](../mfc/memory-management-examples.md)  
  
-   [Ao alocar memória para um objeto](../mfc/memory-management-examples.md)  
  
-   [Blocos de memória redimensionáveis](../mfc/memory-management-resizable-memory-blocks.md)  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../mfc/mfc-concepts.md)   
 [Tópicos gerais do MFC](../mfc/general-mfc-topics.md)

