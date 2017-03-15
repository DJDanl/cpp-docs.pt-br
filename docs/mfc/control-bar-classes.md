---
title: "Classes da barra de controle | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.classes.control"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "barras de controle, Classes "
ms.assetid: 11009103-cad8-4309-85ce-3d2e858e1818
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes da barra de controle
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As barras de controle são anexadas a uma janela do quadro.  Contêm botões, os painéis de status, ou um modelo da caixa de diálogo.  As barras de controle flutuante, também chamadas paletas da ferramenta, são implementadas anexando a um objeto de [CMiniFrameWnd](../mfc/reference/cminiframewnd-class.md) .  
  
## Barras de controle da estrutura  
 Essas barras de controle são parte integrante da estrutura de MFC.  São mais fáceis de usar e eficientes do que as barras de controle do windows porque são integrados com a estrutura.  A maioria dos aplicativos MFC usam essas barras de controle em vez das barras de controle do windows.  
  
 [CControlBar](../mfc/reference/ccontrolbar-class.md)  
 A classe base para barras de controle de MFC listados nesta seção.  Uma barra de controle é uma janela alinhada à borda de uma janela do quadro.  A barra de controle contém os controles filho baseado em `HWND`ou dos controles não baseadas em `HWND`, como os botões da barra de ferramentas.  
  
 [CDialogBar](../mfc/reference/cdialogbar-class.md)  
 Uma barra de controle que é baseado em um modelo da caixa de diálogo.  
  
 [CReBar](../mfc/reference/crebar-class.md)  
 Oferece suporte a uma barra de ferramentas que pode conter janelas filho adicionais na forma dos controles.  
  
 [CToolBar](../mfc/reference/ctoolbar-class.md)  
 Janelas de controle da barra de ferramentas que contêm botões de comando de bitmap não baseadas em `HWND`.  A maioria dos aplicativos MFC usam essa classe em vez de `CToolBarCtrl`.  
  
 [CStatusBar](../mfc/reference/cstatusbar-class.md)  
 A classe base para janelas de controle da barra de status.  A maioria dos aplicativos MFC usam essa classe em vez de `CStatusBarCtrl`.  
  
## Barras de controle do windows  
 Essas barras de controle são wrappers refinados para os controles correspondentes do windows.  Porque não são integrados com a estrutura, é mais difícil usar do que as barras de controle listadas anteriormente.  A maioria dos aplicativos MFC usam as barras de controle listadas anteriormente.  
  
 [CRebarCtrl](../mfc/reference/crebarctrl-class.md)  
 Implementa controle interno do objeto de `CRebar` .  
  
 [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md)  
 Uma janela horizontal, dividido geralmente painéis, em que um aplicativo pode exibir informações de status.  
  
 [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md)  
 Fornece a funcionalidade do controle comum de barra de ferramentas comum do Windows.  
  
## Classes relacionadas  
 [CToolTipCtrl](../Topic/CToolTipCtrl%20Class.md)  
 Um pequeno janela pop\-up que exibe uma única linha de texto que descreve a finalidade de uma ferramenta em um aplicativo.  
  
 [CDockState](../mfc/reference/cdockstate-class.md)  
 Trata o armazenamento de dados persistente do estado de encaixe de barras de controle.  
  
## Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)