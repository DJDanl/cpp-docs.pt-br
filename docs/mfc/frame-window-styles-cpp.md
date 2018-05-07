---
title: Estilos de janela com moldura (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- window styles [MFC]
- PreCreateWindow method, setting window styles
- windows [MFC], MFC
- frame windows [MFC], styles
- MFC, frame windows
- styles [MFC], windows
ms.assetid: fc5058c1-eec8-48d8-9f76-3fc01cfa53f7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 102b3a4c8372a53aada23ad448ce5dc1cf323a97
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="frame-window-styles-c"></a>Estilos de janela com moldura (C++)
As janelas de quadro obter com o framework são adequadas para a maioria dos programas, mas você pode obter flexibilidade adicional, usando as funções avançadas [PreCreateWindow](../mfc/reference/cwnd-class.md#precreatewindow) e a função global MFC [AfxRegisterWndClass ](../mfc/reference/application-information-and-management.md#afxregisterwndclass). `PreCreateWindow` é uma função de membro de `CWnd`.  
  
 Se você aplicar o **WS_HSCROLL** e **WS_VSCROLL** estilos para a janela do quadro principal, em vez disso, são aplicados ao **MDICLIENT** janela para que os usuários podem rolar a **MDICLIENT** área.  
  
 Se a janela **FWS_ADDTOTITLE** bit de estilo é definido (que é o padrão), a exibição informa a janela do quadro que título a ser exibido na barra de título da janela com base no nome do documento do modo de exibição.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Gerenciando janelas de filhos MDI (MDICLIENT)](../mfc/managing-mdi-child-windows.md), a janela em um quadro MDI que contém as janelas filho MDI  
  
-   [Alternando os estilos de uma janela criada por MFC](../mfc/changing-the-styles-of-a-window-created-by-mfc.md)  
  
-   [Estilos de janela](../mfc/reference/styles-used-by-mfc.md#window-styles)  
  
## <a name="see-also"></a>Consulte também  
 [Janelas com moldura](../mfc/frame-windows.md)

