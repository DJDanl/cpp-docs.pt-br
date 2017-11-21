---
title: Classes de janela derivadas | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- window class hierarchy
- hierarchies, window classes
- classes [MFC], derived
- CWnd class [MFC], classes derived from
- derived classes [MFC], window classes
- window classes [MFC], derived
ms.assetid: 6f7e437e-fbde-4a06-bfab-72d9dbf05292
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: d75a6692eadaa3a080803b9aa69d30e4b384307a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="derived-window-classes"></a>Classes de janela derivadas
Você pode criar janelas diretamente do [CWnd](../mfc/reference/cwnd-class.md), ou derivar novas classes de janela de `CWnd`. Isso é como você normalmente cria seu próprio personalizada do windows. No entanto, a maioria dos windows usados em um programa do framework são criadas de uma da `CWnd`-classes de janela com moldura fornecidos pelo MFC derivadas.  
  
## <a name="frame-window-classes"></a>Classes de janela com moldura  
 [CFrameWnd](../mfc/reference/cframewnd-class.md)  
 Usado para janelas de quadro SDI que um único documento e a exibição do quadro. A janela do quadro é a janela do quadro principal para o aplicativo e a janela do quadro do documento atual.  
  
 [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md)  
 Usado como a janela do quadro principal para aplicativos MDI. A janela do quadro principal é um contêiner para todas as janelas de documentos MDI e compartilha sua barra de menu com eles. Uma janela de quadro MDI é uma janela de nível superior que aparece na área de trabalho.  
  
 [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md)  
 Usado para documentos individuais abertos em uma janela do quadro principal MDI. Cada documento e sua exibição são enquadradas por uma janela de quadro MDI filho contida pela janela do quadro principal MDI. Uma janela de filho MDI é muito parecida com uma janela do quadro típico, mas está contida dentro de uma janela de quadro MDI em vez de na área de trabalho. No entanto, a janela filho MDI não tem uma barra de menus do seu próprio e deve compartilhar a barra de menus da janela de quadro MDI que o contém.  
  
 Para obter mais informações, consulte [janelas com moldura](../mfc/frame-windows.md).  
  
## <a name="other-window-classes-derived-from-cwnd"></a>Outras Classes de janela derivadas de CWnd  
 Janelas com moldura, além de várias outras categorias principais do windows são derivadas de `CWnd`:  
  
 *Exibições*  
 Exibições são criadas usando o `CWnd`-classe derivada [CView](../mfc/reference/cview-class.md) (ou uma de suas classes derivadas). Um modo de exibição é anexado a um documento e atua como um intermediário entre o documento e o usuário. Uma exibição é uma janela filho (não é um filho MDI) que normalmente preenche a área de cliente de uma janela do quadro SDI ou uma janela do quadro filho MDI (ou parte da área do cliente não coberta por uma barra de ferramentas e/ou uma barra de status).  
  
 *Caixas de diálogo*  
 Caixas de diálogo são criadas usando o `CWnd`-classe derivada [CDialog](../mfc/reference/cdialog-class.md).  
  
 *Formulários*  
 Modos de exibição de formulário com base nos recursos de modelo de caixa de diálogo, como caixas de diálogo, são criados usando classes [CFormView](../mfc/reference/cformview-class.md), [CRecordView](../mfc/reference/crecordview-class.md), ou [CDaoRecordView](../mfc/reference/cdaorecordview-class.md).  
  
 *Controles*  
 Controles como botões, caixas de listagem e caixas de combinação são criados usando outras classes derivadas de `CWnd`. Consulte [controlar tópicos](../mfc/controls-mfc.md).  
  
 *Barras de controle*  
 Janelas filho que contêm controles. Exemplos incluem as barras de ferramentas e barras de status. Consulte [barras de controle](../mfc/control-bars.md).  
  
## <a name="window-class-hierarchy"></a>Hierarquia de classes de janela  
 Consulte o [gráfico de hierarquia MFC](../mfc/hierarchy-chart.md) no *referência MFC*. Modos de exibição são explicados em [arquitetura de documento/exibição](../mfc/document-view-architecture.md). Caixas de diálogo são explicadas em [caixas de diálogo](../mfc/dialog-boxes.md).  
  
## <a name="creating-your-own-special-purpose-window-classes"></a>Criando suas próprias Classes de janela com finalidade especial  
 Além das classes de janela fornecidas pela biblioteca de classe, talvez seja necessário janelas filho de finalidade especial. Para criar uma janela, crie seu próprio [CWnd](../mfc/reference/cwnd-class.md)-classe derivada e torná-lo em uma janela filho de um quadro ou exibição. Tenha em mente que a estrutura gerencia a extensão da área cliente de uma janela de quadro do documento. A maioria da área do cliente é gerenciado por uma exibição, mas outras janelas, como controle de barras ou seu próprio personalizada do windows, pode compartilhar o espaço com o modo de exibição. Talvez seja necessário interagir com os mecanismos em classes [CView](../mfc/reference/cview-class.md) e [CControlBar](../mfc/reference/ccontrolbar-class.md) para posicionamento janelas filho na área de cliente de uma janela quadro.  
  
 [Criando janelas](../mfc/creating-windows.md) discute a criação de objetos de janela e do windows que eles gerenciam.  
  
## <a name="see-also"></a>Consulte também  
 [Objetos de janela](../mfc/window-objects.md)

