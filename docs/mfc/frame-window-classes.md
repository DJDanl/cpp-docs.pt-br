---
title: Classes de janela com moldura | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- frame window classes [MFC], about frame window classes
- frame window classes [MFC]
- windows [MFC], MDI
- document frame windows [MFC], classes
- single document interface (SDI), frame windows
- window classes [MFC], frame
- MFC, frame windows
- MDI [MFC], frame windows
- classes [MFC], window
ms.assetid: c27e43a7-8ad0-4759-b1b7-43f4725f4132
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b5e67ef155c029285d0b306ca2d05179e993de78
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="frame-window-classes"></a>Classes de janela com moldura
Cada aplicativo tem um "janela do quadro principal", uma janela de área de trabalho que geralmente tem o nome do aplicativo na sua legenda. Cada documento geralmente tem um "janela do quadro do documento." Uma janela do quadro de documento contém pelo menos um modo de exibição, que apresenta os dados do documento.  
  
## <a name="frame-windows-in-sdi-and-mdi-applications"></a>Janelas com moldura no SDI e MDI aplicativos  
 Para um aplicativo SDI, há uma janela do quadro derivada da classe [CFrameWnd](../mfc/reference/cframewnd-class.md). Esta janela é a janela do quadro principal e a janela do quadro do documento. Para um aplicativo MDI, a janela do quadro principal é derivada da classe [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md), e as janelas de quadro do documento, que são janelas filho MDI, são derivadas da classe [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md).  
  
## <a name="use-the-frame-window-class-or-derive-from-it"></a>Use a classe de janela com moldura ou derivado dele  
 Essas classes fornecem a maioria da funcionalidade de janela do quadro que é necessário para seus aplicativos. Em circunstâncias normais, o comportamento padrão e a aparência que eles fornecem atenderá às suas necessidades. Se você precisar de funcionalidade adicional, derive dessas classes.  
  
### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Classes de janela com moldura criadas pelo Assistente de aplicativo](../mfc/frame-window-classes-created-by-the-application-wizard.md)  
  
-   [Estilos de janela com moldura](../mfc/frame-window-styles-cpp.md)  
  
-   [Alternando os estilos de uma janela criada por MFC](../mfc/changing-the-styles-of-a-window-created-by-mfc.md)  
  
## <a name="see-also"></a>Consulte também  
 [Janelas com moldura](../mfc/frame-windows.md)

