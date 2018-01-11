---
title: "Sequência de destruição da janela | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- destruction, windows
- destroying windows
- sequence [MFC], window destruction
- CWnd objects [MFC], destruction sequence
- sequence [MFC]
- windows [MFC], destroying
ms.assetid: 2d819196-6240-415f-a308-db43745e616c
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8b873d51f585336425537756064582eb709988f6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="window-destruction-sequence"></a>Sequência de destruição da janela
Na estrutura MFC, quando o usuário fecha a janela do quadro, padrão da janela [OnClose](../mfc/reference/cwnd-class.md#onclose) chamadas de manipulador [DestroyWindow](../mfc/reference/cwnd-class.md#destroywindow). É a última função membro chamada quando a janela do Windows é destruída [OnNcDestroy](../mfc/reference/cwnd-class.md#onncdestroy), que faz alguma limpeza, chama o [padrão](../mfc/reference/cwnd-class.md#default) membro de função para executar a limpeza do Windows e finalmente chama a função membro virtual [PostNcDestroy](../mfc/reference/cwnd-class.md#postncdestroy). O [CFrameWnd](../mfc/reference/cframewnd-class.md) implementação de `PostNcDestroy` exclui o objeto de janela C++.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Alocando e desalocando a memória da janela](../mfc/allocating-and-deallocating-window-memory.md)  
  
-   [Desanexando um CWnd de HWND](../mfc/detaching-a-cwnd-from-its-hwnd.md)  
  
## <a name="see-also"></a>Consulte também  
 [Destruindo objetos de janela](../mfc/destroying-window-objects.md)

