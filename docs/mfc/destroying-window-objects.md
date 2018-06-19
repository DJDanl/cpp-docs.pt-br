---
title: Destruindo objetos de janela | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- frame windows [MFC], destroying
- window objects [MFC], deleting
- window objects [MFC], destroying
- window objects [MFC], removing
ms.assetid: 3241fea0-c614-4a25-957d-20f21bd5fd0c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3aacb01d945429bc36543f78e3635c39ef58223d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33343370"
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

