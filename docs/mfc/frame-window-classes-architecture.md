---
title: Classes de janela (arquitetura) do quadro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.classes.frame
dev_langs:
- C++
helpviewer_keywords:
- frame window classes [MFC], document/view architecture
ms.assetid: 5da01fb4-f531-46cc-914f-e422e4f07f5d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b7de72b77be9be90ca876cfef943500a0312d183
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="frame-window-classes-architecture"></a>Classes de janela com moldura (arquitetura)
Na arquitetura de documento/exibição janelas com moldura são janelas que contêm uma janela de exibição. Eles também possuem suporte para ter controle barras anexadas a elas.  
  
 Em vários aplicativos de interface (MDI) do documento, a janela principal é derivada de `CMDIFrameWnd`. Ele contém indiretamente quadros os documentos, que são `CMDIChildWnd` objetos. O `CMDIChildWnd` objetos, por sua vez, contêm exibições os documentos.  
  
 Em aplicativos de interface (SDI) único documento, a janela principal, derivado de `CFrameWnd`, contém a exibição do documento atual.  
  
 [CFrameWnd](../mfc/reference/cframewnd-class.md)  
 A classe base para a janela do quadro principal do aplicativo SDI. Também é a classe base para todas as outras classes de janela do quadro.  
  
 [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md)  
 A classe base para a janela do quadro principal do aplicativo MDI.  
  
 [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md)  
 A classe base para janelas de quadro de documento do aplicativo MDI.  
  
 [COleIPFrameWnd](../mfc/reference/coleipframewnd-class.md)  
 Fornece a janela do quadro para um modo de exibição quando um documento do servidor está sendo editado no local.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

