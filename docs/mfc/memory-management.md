---
title: "Gerenciamento de mem&#243;ria | Microsoft Docs"
ms.custom: ""
ms.date: "12/13/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "memória"
  - "alocação de memória"
  - "alocação de memória, MFC"
  - "memória, gerenciando"
  - "MFC, gerenciamento de memória"
ms.assetid: 934ac81b-d630-4232-88e5-ea74f7187987
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Gerenciamento de mem&#243;ria
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este grupo de artigos descreve como tirar proveito dos serviços de uso geral da biblioteca de classes do Microsoft \(MFC\) relacionada ao gerenciamento de memória.  A alocação de memória pode ser dividida em duas categorias principais: alocações do quadro e alocações do heap.  
  
 A principal diferença entre as duas técnicas de alocação é a alocação do quadro com que você normalmente trabalha com o bloco de memória real em si, quando a alocação de heap seja determinado sempre um ponteiro para o bloco de memória.  Outra principal diferença entre os dois esquemas é que os objetos do quadro são excluídos automaticamente, quando objetos de heap devem ser explicitamente excluídos pelo programador.  
  
 Para obter informações não MFC sobre o gerenciamento de memória em programas do windows, consulte [Gerenciamento de memória](http://msdn.microsoft.com/library/windows/desktop/aa366779) em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
## Que você deseja saber mais?  
  
-   [Peça para alocação](../mfc/memory-management-frame-allocation.md)  
  
-   [Empilhe a alocação](../mfc/memory-management-heap-allocation.md)  
  
-   [Atribuindo a memória para uma matriz](../mfc/memory-management-examples.md)  
  
-   [Desalocando a memória para uma matriz de heap](../mfc/memory-management-examples.md)  
  
-   [Alocar memória para uma estrutura de dados](../mfc/memory-management-examples.md)  
  
-   [Atribuindo a memória para um objeto](../mfc/memory-management-examples.md)  
  
-   [Blocos de memória redimensionável](../mfc/memory-management-resizable-memory-blocks.md)  
  
## Consulte também  
 [Conceitos](../mfc/mfc-concepts.md)   
 [Tópicos MFC gerais](../mfc/general-mfc-topics.md)