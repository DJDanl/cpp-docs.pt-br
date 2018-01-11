---
title: Elementos da interface | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- architecture [MFC], MFC Feature Pack
- MFC Feature Pack, architecture
ms.assetid: eead6827-9602-40a3-8038-8986e8207385
caps.latest.revision: "28"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ab3da476a4e8b18d5ac864f0cf690a6a113db11e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="interface-elements"></a>Elementos da interface
Este documento descreve os elementos de interface que foram introduzidos no [!INCLUDE[vs_orcas_long](../atl/reference/includes/vs_orcas_long_md.md)] SP1 e também descreve as diferenças com a versão anterior da biblioteca.  
  
 A ilustração a seguir mostra um aplicativo que foi criado usando os novos elementos de interface.  
  
 ![O aplicativo de exemplo do MFC Feature Pack](../mfc/media/mfc_featurepack.png "mfc_featurepack")  
  
## <a name="window-docking"></a>Janela de encaixe  
 Janela de encaixe funcionalidade é semelhante a janela de encaixe que o [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] usa interface gráfica do usuário.  
  
## <a name="control-bars-are-now-panes"></a>Barras de controle são agora painéis  
 Barras de controle agora são conhecidas como painéis e são derivadas de [CBasePane classe](../mfc/reference/cbasepane-class.md). Em versões anteriores do MFC, a classe base das barras de controle foi `CControlBar`.  
  
 Janela do quadro principal do aplicativo normalmente é representada pelo [classe CWinAppEx é](../mfc/reference/cframewndex-class.md) ou [CMDIFrameWndEx classe](../mfc/reference/cmdiframewndex-class.md). O quadro principal é chamado de *encaixar site*. Painéis podem ter um dos três tipos de pais: um site de encaixe, uma barra de encaixe ou uma janela do quadro simplificado.  
  
 Há dois tipos de painéis: redimensionáveis e não redimensionável. Painéis redimensionáveis, como barras de status e barras de ferramentas, podem ser redimensionadas usando divisores ou controles deslizantes. Painéis redimensionáveis podem formar contêineres (um painel pode ser encaixado para outro painel, criando um separador entre eles). No entanto, não não possível anexar painéis redimensionáveis (encaixado) para encaixar barras.  
  
 Se seu aplicativo usa painéis não redimensionável, derivar de [CPane classe](../mfc/reference/cpane-class.md).  Se seu aplicativo usa painéis redimensionáveis, derive de [CDockablePane classe](../mfc/reference/cdockablepane-class.md)  
  
## <a name="dock-site"></a>Site de encaixe  
 O site de encaixe (ou a janela do quadro principal) possui todos os painéis e janelas com moldura simplificado em um aplicativo. O local de encaixe contém um [CDockingManager](../mfc/reference/cdockingmanager-class.md) membro. Este membro mantém uma lista de todos os painéis que pertencem ao site de encaixe. A lista é ordenada de forma que os painéis criados nas bordas externas do site encaixe são posicionados no início da lista. Quando a estrutura redesenha o site de encaixe, ele faz um loop sobre essa lista e ajusta o layout de cada painel para incluir o retângulo delimitador atual do site de encaixe. Você pode chamar `AdjustDockingLayout` ou `RecalcLayout` quando você precisa ajustar o layout de encaixe, e o framework redireciona essa chamada para o Gerenciador de encaixe.  
  
## <a name="dock-bars"></a>Barras de encaixe  
 Cada janela do quadro principal pode posicionar *encaixar barras* ao longo de suas bordas. Uma barra de encaixe é um painel que pertence a um [CDockSite classe](../mfc/reference/cdocksite-class.md). Barras de encaixe podem aceitar objetos derivados de [CPane](../mfc/reference/cpane-class.md), como barras de ferramentas. Para criar barras de encaixe quando a janela do quadro principal é inicializada, chame `EnableDocking`. Para habilitar as barras de ocultar automaticamente, chame `EnableAutoHideBars`. `EnableAutoHideBars`cria [CAutoHideDockSite](../mfc/reference/cautohidedocksite-class.md) objetos e posiciona-os ao lado de cada barra de encaixe.  
  
 Cada barra de encaixe é dividida em linhas de encaixe. Linhas de encaixe são representadas pelo [CDockingPanesRow classe](../mfc/reference/cdockingpanesrow-class.md). Cada linha de encaixe contém uma lista das barras de ferramentas. Se um usuário encaixa uma barra de ferramentas ou move a barra de ferramentas de uma linha para outro dentro da mesma barra de encaixe, o framework cria uma nova linha e redimensiona a barra de encaixe adequadamente, ou ele posiciona a barra de ferramentas em uma linha existente.  
  
## <a name="mini-frame-windows"></a>Janelas com moldura simplificado  
 Um painel flutuante reside em uma janela do quadro simplificado. Janelas com moldura mini são representadas por duas classes: [classe CMDITabInfo](../mfc/reference/cmditabinfo-class.md) (que pode conter somente um painel) e [CMultiPaneFrameWnd classe](../mfc/reference/cmultipaneframewnd-class.md) (que pode conter vários painéis). Para desencaixar um painel em seu código, chame [CBasePane::FloatPane](../mfc/reference/cbasepane-class.md#floatpane). Depois que um painel flutua, o framework cria automaticamente uma janela do minie quadro essa janela do minise quadro torna o pai do painel flutuante. Quando o painel flutuante encaixa, a estrutura redefine seu pai e o painel flutuante se tornará uma barra de encaixe (para barras de ferramentas) ou um local de encaixe (para painéis redimensionáveis).  
  
## <a name="pane-dividers"></a>Painel divisores  
 Divisores de painel (também chamados de controles deslizantes ou divisores) são representados pelo [CPaneDivider classe](../mfc/reference/cpanedivider-class.md). Quando um usuário encaixa um painel, o framework cria divisores do painel, independentemente se o painel está encaixado no local de encaixe ou no outro painel. Quando um painel se encaixa no site de encaixe, o divisor do painel é chamado de *padrão divisor do painel*. O divisor de painel padrão é responsável pelo layout de todos os painéis de encaixe no site de encaixe. O Gerenciador de encaixe mantém uma lista de divisores de painel padrão e uma lista de painéis. Gerenciadores de encaixe são responsáveis pelo layout de todos os painéis de encaixe.  
  
## <a name="containers"></a>Contêineres  
 Todos os painéis redimensionáveis, quando estiver encaixada, são mantidos em contêineres. Contêineres são representados pelo [CPaneContainer classe](../mfc/reference/cpanecontainer-class.md). Cada contêiner tem ponteiros para seu painel esquerdo, painel direito, subcontêiner à esquerda, direita subcontêiner e o separador entre as partes esquerdas e direita. (*Esquerda* e *direita* não fazem referência a lados físicos, mas em vez disso, identifique as ramificações de uma estrutura de árvore.) Dessa maneira, podemos criar uma árvore de painéis e separadores e, portanto, atingir layouts complexos de painéis que podem ser redimensionadas juntas. O `CPaneContainer` classe mantém a árvore de contêineres; também mantém duas listas de painéis e os controles deslizantes que residem nessa árvore. Gerenciadores de contêiner de painel geralmente são inseridos em controles deslizantes do padrão e janelas com moldura simplificado que contêm vários painéis.  
  
## <a name="auto-hide-control-bars"></a>Barras de controle de ocultar automaticamente  
 Por padrão, cada `CDockablePane` suporta o recurso de ocultar automaticamente. Quando um usuário clica no botão de pin na legenda do `CDockablePane`, a estrutura alterna o painel para o modo de ocultar automaticamente. Para lidar com o clique, o framework cria um [CMFCAutoHideBar classe](../mfc/reference/cmfcautohidebar-class.md) e um [CMFCAutoHideButton classe](../mfc/reference/cmfcautohidebutton-class.md) associados a `CMFCAutoHideBar` objeto. A estrutura coloca o novo `CMFCAutoHideBar` no [CAutoHideDockSite](../mfc/reference/cautohidedocksite-class.md). A estrutura também anexa o `CMFCAutoHideButton` na barra de ferramentas. O [CDockingManager classe](../mfc/reference/cdockingmanager-class.md) mantém o `CDockablePane`.  
  
## <a name="tabbed-control-bars-and-outlook-bars"></a>Barras de controle com guias e barras do Outlook  
 O [CMFCBaseTabCtrl classe](../mfc/reference/cmfcbasetabctrl-class.md) implementa a funcionalidade básica de uma janela com guias com guias destacáveis. Para usar um `CMFCBaseTabCtrl` de objeto, inicializar um [CBaseTabbedPane classe](../mfc/reference/cbasetabbedpane-class.md) em seu aplicativo. `CBaseTabbedPane`é derivado de `CDockablePane` e mantém um ponteiro para um `CMFCBaseTabCtrl` objeto. O `CBaseTabbedPane` permite que os usuários Encaixar e redimensionar as barras de controle com guias. Use [CDockablePane::AttachToTabWnd](../mfc/reference/cdockablepane-class.md#attachtotabwnd) criar dinamicamente as barras de controle que estão encaixadas e com guias.  
  
 O controle de barra do Outlook também se baseia nas barras com guias. O [CMFCOutlookBar classe](../mfc/reference/cmfcoutlookbar-class.md) é derivado de `CBaseTabbedPane`. Para obter mais informações sobre como usar a barra do Outlook, consulte [CMFCOutlookBar classe](../mfc/reference/cmfcoutlookbar-class.md).  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../mfc/mfc-concepts.md)

