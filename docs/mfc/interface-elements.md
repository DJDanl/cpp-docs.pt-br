---
title: "Elementos da interface | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "arquitetura [C++], MFC Feature Pack"
  - "MFC Feature Pack, arquitetura"
ms.assetid: eead6827-9602-40a3-8038-8986e8207385
caps.latest.revision: 28
caps.handback.revision: 24
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Elementos da interface
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este documento descreve os elementos da interface que foram introduzidos em [!INCLUDE[vs_orcas_long](../atl/reference/includes/vs_orcas_long_md.md)] SP1, e também descreve diferenças com a versão anterior de biblioteca.  
  
 A ilustração a seguir mostra um aplicativo que é construído usando novos elementos da interface.  
  
 ![Aplicativo de exemplo do MFC Feature Pack](../mfc/media/mfc_featurepack.png "MFC\_FeaturePack")  
  
## Encaixe da janela  
 A funcionalidade de encaixe da janela semelhante ao encaixe da janela que a interface gráfica do usuário de [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] usa.  
  
## As barras de controle agora são painéis  
 As barras de controle agora são conhecidas como os painéis e derivadas de [Classe de CBasePane](../mfc/reference/cbasepane-class.md).  Em versões anteriores de MFC, a classe base de barras de controle era `CControlBar`.  
  
 A janela principal do quadro do aplicativo normalmente é representada por [Classe de CFrameWndEx](../mfc/reference/cframewndex-class.md) ou por [Classe CMDIFrameWndEx](../Topic/CMDIFrameWndEx%20Class.md).  O quadro principal é chamado *de site de plug\-in*.  Os painéis podem ter um dos três tipos de pais: um site de plug\-in, uma barra de plug\-in, ou uma janela de mini\- quadro.  
  
 Há dois tipos de painéis: não redimensionável e redimensionável.  Os painéis redimensionável, como barras de status e barras de ferramentas, podem ser redimensionados usando separadores ou controles deslizantes.  Os painéis redimensionável poderão formar um contêiner \(o painel pode ser inserida para outro painel, criando um separador entre eles\).  Porém, os painéis redimensionável não podem ser anexados \(logon\) para inserir barras.  
  
 Se seu aplicativo usa os painéis não redimensionável, derive\-os de [Classe de CPane](../mfc/reference/cpane-class.md).  Se seu aplicativo usa os painéis redimensionável, derive\-os de [Classe de CDockablePane](../Topic/CDockablePane%20Class.md)  
  
## Entre o site  
 O local de encaixe \(ou a janela do quadro principal\) possuem todos os painéis e janelas de mini\- quadro em um aplicativo.  O local de encaixe contém um membro de [CDockingManager](../mfc/reference/cdockingmanager-class.md) .  Esse membro mantém uma lista de todos os painéis que pertencem ao site de plug\-in.  A lista estiver ordenada de forma que os painéis criados nas bordas externos do site de plug\-in são posicionados no início da lista.  Quando a estrutura redesenha ao site de plug\-in, dará um loop nessa lista e ajustar o layout de cada painel para incluir o retângulo delimitador de site atual de plug\-in.  Você pode chamar `AdjustDockingLayout` ou `RecalcLayout` quando você precisa ajustar o layout de encaixe, e a estrutura redireciona essa chamada ao gerenciador de encaixe.  
  
## Barras de plug\-in  
 Cada janela principal do quadro pode posicionar *barras de encaixe* ao longo das bordas.  Uma barra de plug\-in é um painel que pertence a [Classe de CDockSite](../mfc/reference/cdocksite-class.md).  As barras de plug\-in podem aceitar os objetos derivados de [CPane](../mfc/reference/cpane-class.md), como barras de ferramentas.  Para criar barras de plug\-in quando a janela principal do quadro é inicializada, chame `EnableDocking`.  Para habilitar barras ocultar automaticamente, chame `EnableAutoHideBars`.  `EnableAutoHideBars` cria objetos de [CAutoHideDockSite](../mfc/reference/cautohidedocksite-class.md) , posicionando\-os ao lado de cada barra de plug\-in.  
  
 Cada barra de plug\-in é dividida em linhas de plug\-in.  As linhas de plug\-in são representadas por [Classe de CDockingPanesRow](../mfc/reference/cdockingpanesrow-class.md).  Cada linha de plug\-in contém uma lista das barras de ferramentas.  Se um usuário insira uma barra de ferramentas ou mova a barra de ferramentas de uma linha para outra na mesma barra de plug\-in, a estrutura ou cria uma linha nova e redimensionar a barra de plug\-in consequentemente, ou posicionar a barra de ferramentas em uma linha existente.  
  
## Janelas de Mini\- quadro  
 Um painel de flutuação reside em uma janela de mini\- quadro.  As janelas de Mini\- quadro são representadas por duas classes: [Classe de CMDITabInfo](../Topic/CMDITabInfo%20Class.md) \(que podem conter apenas um painel\) e [Classe de CMultiPaneFrameWnd](../mfc/reference/cmultipaneframewnd-class.md) \(que podem conter vários painéis.\)  Para serem flutuantes um painel em seu código, chame [CBasePane::FloatPane](../Topic/CBasePane::FloatPane.md).  Depois que um painel flutua, a estrutura cria automaticamente uma janela de mini\- quadro e essa janela de mini\- quadro se torna o pai do painel de flutuação.  Quando o painel de flutuação enter, a estrutura redefine seu pai, e o painel flutuante se torna uma barra de plug\-in \(para barras de ferramentas\) ou um site de plug\-in \(para os painéis redimensionável.\)  
  
## Divisores do painel  
 Os divisores do painel \(também denominados controles deslizantes ou separadores\) são representados por [Classe de CPaneDivider](../mfc/reference/cpanedivider-class.md).  Quando um usuário faz logon em um painel, a estrutura cria divisores do painel, independentemente de se o painel está conectado no site de plug\-in ou em outro painel.  Quando um painel no site de plug\-in, o divisor do painel é chamado *o divisor padrão do painel*.  O divisor padrão do painel é responsável para o layout de todos os painéis de encaixe no site de plug\-in.  O gerenciador de plug\-in mantém uma lista de divisores padrão do painel, e uma lista de painéis.  Os gerenciadores de plug\-in são responsáveis pelo layout de todos os painéis de encaixe.  
  
## Containers  
 Todos os painéis redimensionável, quando conectados entre si, são mantidos em contêineres.  Os contêineres são representados por [Classe de CPaneContainer](../mfc/reference/cpanecontainer-class.md).  Cada contêiner tem ponteiros ao seu painel esquerdo, o painel direito, um contêiner esquerdo, um contêiner direito, e o separador entre as partes esquerda e direita. \(*Esquerda* e *direita* não se refere a físicos lado mas identifica um pouco ramificações de uma estrutura de árvore.\) Assim podemos criar uma árvore dos painéis e dos separadores e como consequência para obter layouts complexos os painéis que podem ser redimensionados juntos.  A classe de `CPaneContainer` mantém a árvore dos contêineres; também mantêm duas listas de painéis e os controles deslizantes que residem nessa árvore.  Os gerenciadores do contêiner do painel geralmente inseridos nos controles deslizantes padrão e nas janelas de mini\- tableau que levam vários painéis.  
  
## Barras de controle de ocultar automaticamente  
 Por padrão, cada `CDockablePane` da suporte ao recurso de ocultar automaticamente.  Quando um usuário clica no botão do pin na legenda de `CDockablePane`, a estrutura alterna o painel para o modo de ocultar automaticamente.  Para tratar o clicar em, a estrutura [Classe de CMFCAutoHideBar](../Topic/CMFCAutoHideBar%20Class.md) cria e [Classe de CMFCAutoHideButton](../mfc/reference/cmfcautohidebutton-class.md) associados ao objeto de `CMFCAutoHideBar` .  A estrutura coloca nova `CMFCAutoHideBar` em [CAutoHideDockSite](../mfc/reference/cautohidedocksite-class.md).  A estrutura também anexar `CMFCAutoHideButton` à barra de ferramentas.  [Classe de CDockingManager](../mfc/reference/cdockingmanager-class.md) mantém `CDockablePane`.  
  
## Barras de controle com guias e barras do Outlook  
 [Classe de CMFCBaseTabCtrl](../mfc/reference/cmfcbasetabctrl-class.md) implementa a funcionalidade de base de uma janela com guias com guias destacáveis.  Para usar um objeto de `CMFCBaseTabCtrl` , inicializando [Classe CBaseTabbedPane](../mfc/reference/cbasetabbedpane-class.md) em seu aplicativo.  `CBaseTabbedPane` é derivado de `CDockablePane` e mantém um ponteiro para um objeto de `CMFCBaseTabCtrl` .  `CBaseTabbedPane` permite que os usuários insiram e redimensionar as barras de controle com guias.  Uso [CDockablePane::AttachToTabWnd](../Topic/CDockablePane::AttachToTabWnd.md) criar dinamicamente as barras de controle que é inserida e listado.  
  
 O controle da barra do Outlook também é baseado em barras com guias.  [Classe CMFCOutlookBar](../mfc/reference/cmfcoutlookbar-class.md) é derivado de `CBaseTabbedPane`.  Para obter mais informações sobre como usar a barra do Outlook, consulte [Classe CMFCOutlookBar](../mfc/reference/cmfcoutlookbar-class.md).  
  
## Consulte também  
 [Conceitos](../mfc/mfc-concepts.md)