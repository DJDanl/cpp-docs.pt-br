---
title: Quando inicializar objetos CWnd | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- window objects [MFC], when to initialize CWnd
- initializing CWnd objects [MFC]
- initializing objects [MFC], CWnd
- CWnd objects [MFC], when HWND is attached
- HWND, when attached to CWnd object
- CWnd objects [MFC], when to initialize
ms.assetid: 4d31bcb1-73db-4f2f-b71c-89b087569a10
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ee10a4632809a224028bfa482f80ed9e8a9334a5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="when-to-initialize-cwnd-objects"></a>Quando inicializar objetos CWnd
Você não pode criar seu próprio filho windows ou chamar quaisquer funções de API do Windows no construtor de uma `CWnd`-objeto derivado. Isso ocorre porque o `HWND` para o `CWnd` objeto ainda não foi criado. Inicialização mais específicos do Windows, como a adição de janelas filho, deve ser feita em um [OnCreate](../mfc/reference/cwnd-class.md#oncreate) manipulador de mensagens.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Criando janelas com moldura de documento](../mfc/creating-document-frame-windows.md)  
  
-   [Criação de documento/exibição](../mfc/document-view-creation.md)  
  
## <a name="see-also"></a>Consulte também  
 [Usando janelas com moldura](../mfc/using-frame-windows.md)

