---
title: Destruindo objetos de janela | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- frame windows [MFC], destroying
- window objects [MFC], deleting
- window objects [MFC], destroying
- window objects [MFC], removing
ms.assetid: 3241fea0-c614-4a25-957d-20f21bd5fd0c
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8e7b8b2cf605e0f53418755b65151fd9eb2cff5d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="destroying-window-objects"></a>Destruindo objetos de janela
Deve ter cuidado com suas próprias janelas filho para destruir o objeto de janela C++ quando o usuário for concluído com a janela. Se esses objetos não são destruídos, seu aplicativo não recuperará a memória. Felizmente, o framework gerencia destruição de janela, bem como a criação de janelas com moldura, exibições e caixas de diálogo. Se você criar janelas adicionais, você é responsável por destruí-las.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Sequência de destruição da janela](../mfc/window-destruction-sequence.md)  
  
-   [Alocando e desalocando a memória da janela](../mfc/allocating-and-deallocating-window-memory.md)  
  
-   [Desanexando um CWnd de HWND](../mfc/detaching-a-cwnd-from-its-hwnd.md)  
  
-   [Sequência de criação da janela geral](../mfc/general-window-creation-sequence.md)  
  
-   [Destruindo janelas com moldura](../mfc/destroying-frame-windows.md)  
  
## <a name="see-also"></a>Consulte também  
 [Objetos de janela](../mfc/window-objects.md)

