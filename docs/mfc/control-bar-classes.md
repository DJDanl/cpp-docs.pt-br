---
title: Classes da barra de controle | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.classes.control
dev_langs: C++
helpviewer_keywords: control bars [MFC], classes
ms.assetid: 11009103-cad8-4309-85ce-3d2e858e1818
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 44fcecbf1d7ddb6c46469f25349d972c8b317809
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="control-bar-classes"></a>Classes da barra de controle
Barras de controle são anexadas a uma janela do quadro. Eles contêm um modelo de caixa de diálogo, painéis de status ou botões. Barras de controle flutuante, também chamadas de paletas de ferramenta, são implementadas por anexá-los para um [CMiniFrameWnd](../mfc/reference/cminiframewnd-class.md) objeto.  
  
## <a name="framework-control-bars"></a>Barras de controle de estrutura  
 Essas barras de controle são parte integrante do framework MFC. Eles são mais fáceis de usar e mais eficiente do que o Windows controlam barras porque eles são integrados com o framework. A maioria dos aplicativos MFC use essas barras de controle, em vez das barras de controle do Windows.  
  
 [CControlBar](../mfc/reference/ccontrolbar-class.md)  
 A classe base das barras de controle MFC listados nesta seção. Uma barra de controle é uma janela alinhada com a borda de uma janela do quadro. A barra de controle contém um `HWND`-com base em controles filho ou não com base em um `HWND`, como botões da barra de ferramentas.  
  
 [CDialogBar](../mfc/reference/cdialogbar-class.md)  
 Uma barra de controle que é baseada em um modelo de caixa de diálogo.  
  
 [CReBar](../mfc/reference/crebar-class.md)  
 Oferece suporte a uma barra de ferramentas que pode conter windows filho adicionais na forma de controles.  
  
 [CToolBar](../mfc/reference/ctoolbar-class.md)  
 Janelas de controle de barra de ferramentas que contém botões de comando de bitmap não com base em um `HWND`. A maioria dos aplicativos MFC usar essa classe em vez de `CToolBarCtrl`.  
  
 [CStatusBar](../mfc/reference/cstatusbar-class.md)  
 A classe base para windows de controle de barra de status. A maioria dos aplicativos MFC usar essa classe em vez de `CStatusBarCtrl`.  
  
## <a name="windows-control-bars"></a>Barras de controle do Windows  
 Essas barras de controle são wrappers dinâmico para os controles do Windows correspondentes. Porque eles não são integrados com o framework, eles são mais difícil de usar do que as barras de controle listadas anteriormente. A maioria dos aplicativos MFC use as barras de controle listadas anteriormente.  
  
 [CRebarCtrl](../mfc/reference/crebarctrl-class.md)  
 Implementa o controle interno do `CRebar` objeto.  
  
 [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md)  
 Uma janela horizontal, geralmente é dividida em painéis, no qual um aplicativo pode exibir informações de status.  
  
 [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md)  
 Fornece a funcionalidade de controle comum da barra de ferramentas do Windows.  
  
## <a name="related-classes"></a>Classes relacionadas  
 [CToolTipCtrl](../mfc/reference/ctooltipctrl-class.md)  
 Uma pequena janela pop-up que exibe uma única linha de texto que descreve a finalidade de uma ferramenta em um aplicativo.  
  
 [CDockState](../mfc/reference/cdockstate-class.md)  
 Lida com armazenamento persistente de dados de estado para barras de controle de encaixe.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

