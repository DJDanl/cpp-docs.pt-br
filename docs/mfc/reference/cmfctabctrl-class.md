---
title: "Classe de CMFCTabCtrl | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CMFCTabCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCTabCtrl"
  - "Construtor de CMFCTabCtrl"
  - "Método de CMFCTabCtrl::GetTabFromPoint"
  - "Método de CMFCTabCtrl::IsPtInTabArea"
  - "Método de CMFCTabCtrl::MoveTab"
  - "Método de CMFCTabCtrl::PreTranslateMessage"
  - "Método de CMFCTabCtrl::RecalcLayout"
  - "Método de CMFCTabCtrl::SwapTabs"
ms.assetid: d441385d-2c72-4203-96fa-deae2273da35
caps.latest.revision: 33
caps.handback.revision: 22
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCTabCtrl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CMFCTabCtrl` fornece funcionalidade para um controle de guia.  O controle de guia exibe uma janela encaixável com as guias lisos ou tridimensionais na parte superior ou inferior.  As guias podem exibir texto e uma imagem e podem modificar a cor quando ativos.  
  
## Sintaxe  
  
```  
class CMFCTabCtrl : public CMFCBaseTabCtrl  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCTabCtrl::CMFCTabCtrl`|Construtor padrão.|  
|`CMFCTabCtrl::~CMFCTabCtrl`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCTabCtrl::ActivateMDITab](../Topic/CMFCTabCtrl::ActivateMDITab.md)|Exibe a guia especificada a guia atual do controle e defina o foco em essa guia.|  
|[CMFCTabCtrl::AllowDestroyEmptyTabbedPane](../Topic/CMFCTabCtrl::AllowDestroyEmptyTabbedPane.md)||  
|[CMFCTabCtrl::AutoSizeWindow](../Topic/CMFCTabCtrl::AutoSizeWindow.md)|Especifica se a estrutura é redimensionar a área cliente de todas as janelas de controle de tabulação quando um elemento de interface de usuário de alterações de controle de guia.|  
|[CMFCTabCtrl::CalcRectEdit](../Topic/CMFCTabCtrl::CalcRectEdit.md)|Desinfla o tamanho da área especificada na guia.  Overrides \( `CMFCBaseTabCtrl::CalcRectEdit`.\)|  
|[CMFCTabCtrl::Create](../Topic/CMFCTabCtrl::Create.md)|Cria o controle da guia e anexá\-la ao objeto de `CMFCTabCtrl` .|  
|`CMFCTabCtrl::CreateObject`|Usado pela estrutura dinâmica para criar uma instância de esse tipo da classe.|  
|[CMFCTabCtrl::EnableActiveTabCloseButton](../Topic/CMFCTabCtrl::EnableActiveTabCloseButton.md)|Mostra ou oculta um botão fechar \(**X**\) na guia.|  
|[CMFCTabCtrl::EnableInPlaceEdit](../Topic/CMFCTabCtrl::EnableInPlaceEdit.md)|Habilita ou desabilita rótulos editáveis de tabulação.  Overrides \( [CMFCBaseTabCtrl::EnableInPlaceEdit](../Topic/CMFCBaseTabCtrl::EnableInPlaceEdit.md).\)|  
|[CMFCTabCtrl::EnableTabDocumentsMenu](../Topic/CMFCTabCtrl::EnableTabDocumentsMenu.md)|Substitui dois botões que rolam os guias de janela com um botão que abre um menu do windows com guias.|  
|[CMFCTabCtrl::EnsureVisible](../Topic/CMFCTabCtrl::EnsureVisible.md)|Garante que um guia é visível.|  
|[CMFCTabCtrl::GetDocumentIcon](../Topic/CMFCTabCtrl::GetDocumentIcon.md)|Recupera o símbolo que está associado com uma guia em um menu pop\-up do windows com guias.|  
|[CMFCTabCtrl::GetFirstVisibleTabNum](../Topic/CMFCTabCtrl::GetFirstVisibleTabNum.md)|Retorna o índice do primeiro guia que é visível no controle atual na guia.|  
|[CMFCTabCtrl::GetResizeMode](../Topic/CMFCTabCtrl::GetResizeMode.md)|Retorna um valor que especifica como o controle atual da guia pode ser redimensionado.|  
|[CMFCTabCtrl::GetScrollBar](../Topic/CMFCTabCtrl::GetScrollBar.md)|Recupera um ponteiro para o objeto de barra de rolagem que está associado com o controle de guias.|  
|[CMFCTabCtrl::GetTabArea](../Topic/CMFCTabCtrl::GetTabArea.md)|Recupera o retângulo delimitador da área de rótulo da guia na parte superior ou inferior do controle de guia.  Overrides \( [CMFCBaseTabCtrl::GetTabArea](../Topic/CMFCBaseTabCtrl::GetTabArea.md).\)|  
|`CMFCTabCtrl::GetTabFromPoint`|Recupera a guia que contém um ponto específico.  Overrides \( [CMFCBaseTabCtrl::GetTabFromPoint](../Topic/CMFCBaseTabCtrl::GetTabFromPoint.md).\)|  
|[CMFCTabCtrl::GetTabMaxWidth](../Topic/CMFCTabCtrl::GetTabMaxWidth.md)|Obtém a largura máximo de um guia.|  
|[CMFCTabCtrl::GetTabsHeight](../Topic/CMFCTabCtrl::GetTabsHeight.md)|Recupera a altura da área da guia do controle atual na guia.|  
|[CMFCTabCtrl::GetTabsRect](../Topic/CMFCTabCtrl::GetTabsRect.md)|Recupera um retângulo que limite a área da guia do controle atual na guia.  Overrides \( [CMFCBaseTabCtrl::GetTabsRect](../Topic/CMFCBaseTabCtrl::GetTabsRect.md).\)|  
|`CMFCTabCtrl::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto de [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) que está associado com esse tipo da classe.|  
|[CMFCTabCtrl::GetWndArea](../Topic/CMFCTabCtrl::GetWndArea.md)|Recupera o limite da área cliente do controle atual na guia.|  
|[CMFCTabCtrl::HideActiveWindowHorzScrollBar](../Topic/CMFCTabCtrl::HideActiveWindowHorzScrollBar.md)|Oculta a barra de rolagem horizontal, se houver, da janela ativa.|  
|[CMFCTabCtrl::HideInactiveWindow](../Topic/CMFCTabCtrl::HideInactiveWindow.md)|Especifica se a estrutura é exibir janelas inativas de controle de guia.|  
|[CMFCTabCtrl::HideNoTabs](../Topic/CMFCTabCtrl::HideNoTabs.md)|Habilita ou desabilita desenhar a área da guia se não houver nenhum guia visível.|  
|[CMFCTabCtrl::HideSingleTab](../Topic/CMFCTabCtrl::HideSingleTab.md)|Habilita ou desabilita desenhar um guia quando há uma única janela com guias.  Overrides \( [CMFCBaseTabCtrl::HideSingleTab](../Topic/CMFCBaseTabCtrl::HideSingleTab.md).\)|  
|[CMFCTabCtrl::IsActiveInMDITabGroup](../Topic/CMFCTabCtrl::IsActiveInMDITabGroup.md)|Indica se a guia atual de um controle de guia é a guia ativa em um grupo de guia de interface de documentos múltiplos.|  
|[CMFCTabCtrl::IsActiveTabBoldFont](../Topic/CMFCTabCtrl::IsActiveTabBoldFont.md)|Indica se o texto da guia ativa é exibido usando uma fonte em negrito.|  
|[CMFCTabCtrl::IsActiveTabCloseButton](../Topic/CMFCTabCtrl::IsActiveTabCloseButton.md)|Indica se o botão close \(**X**\) é exibido em uma guia ativo ou no canto superior direito da área de tabulação.|  
|[CMFCTabCtrl::IsDrawFrame](../Topic/CMFCTabCtrl::IsDrawFrame.md)|Indica se a janela desenhar um retângulo com guias do quadro ao redor de painéis inseridos.|  
|[CMFCTabCtrl::IsFlatFrame](../Topic/CMFCTabCtrl::IsFlatFrame.md)|Indica se o quadro ao redor da área de guia é suave ou 3D.|  
|[CMFCTabCtrl::IsFlatTab](../Topic/CMFCTabCtrl::IsFlatTab.md)|Indica se a aparência dos guias no controle atual da guia é suave ou não.|  
|[CMFCTabCtrl::IsLeftRightRounded](../Topic/CMFCTabCtrl::IsLeftRightRounded.md)|Indica se a aparência da esquerda e do lado direito de uma guia no controle atual da guia é arredondada.|  
|[CMFCTabCtrl::IsMDITabGroup](../Topic/CMFCTabCtrl::IsMDITabGroup.md)|Indica se o controle atual da guia está contido na área cliente de uma janela de interface de documentos múltiplos.|  
|[CMFCTabCtrl::IsOneNoteStyle](../Topic/CMFCTabCtrl::IsOneNoteStyle.md)|Indica se o controle da guia atual é exibido no estilo da Microsoft OneNote.|  
|`CMFCTabCtrl::IsPtInTabArea`|Determina se um ponto está dentro da área de tabulação.  Overrides \( [CMFCBaseTabCtrl::IsPtInTabArea](../Topic/CMFCBaseTabCtrl::IsPtInTabArea.md).\)|  
|[CMFCTabCtrl::IsSharedScroll](../Topic/CMFCTabCtrl::IsSharedScroll.md)|Indica se o controle atual da guia possui uma barra de rolagem que pode rolar suas guias como um grupo.|  
|[CMFCTabCtrl::IsTabDocumentsMenu](../Topic/CMFCTabCtrl::IsTabDocumentsMenu.md)|Indica se o controle de guia exibe botões de rolagem ou um botão que exibe um menu do windows com guias.|  
|[CMFCTabCtrl::IsVS2005Style](../Topic/CMFCTabCtrl::IsVS2005Style.md)|Indica se as guias são exibidos no estilo Visual studio.net 2005.|  
|[CMFCTabCtrl::ModifyTabStyle](../Topic/CMFCTabCtrl::ModifyTabStyle.md)|Especifica a aparência dos guias no controle atual na guia.|  
|`CMFCTabCtrl::MoveTab`|Move um guia para outra posição de guia.  Overrides \( [CMFCBaseTabCtrl::MoveTab](../Topic/CMFCBaseTabCtrl::MoveTab.md).\)|  
|[CMFCTabCtrl::OnDragEnter](../Topic/CMFCTabCtrl::OnDragEnter.md)|Chamado pela estrutura quando o cursor é arrastado primeiro na janela de controle de guia.|  
|[CMFCTabCtrl::OnDragOver](../Topic/CMFCTabCtrl::OnDragOver.md)|Chamado pela estrutura durante uma operação de arrastar quando o mouse é movida sobre a janela de destino alvo.  Overrides \( [CMFCBaseTabCtrl::OnDragOver](../Topic/CMFCBaseTabCtrl::OnDragOver.md).\)|  
|[CMFCTabCtrl::OnShowTabDocumentsMenu](../Topic/CMFCTabCtrl::OnShowTabDocumentsMenu.md)|Exibe um menu pop\-up do windows com guias, aguarda até que o usuário selecione um guia, e torna a guia selecionada a guia.|  
|`CMFCTabCtrl::PreTranslateMessage`|Converte mensagens de janela antes que são distribuídos funções do windows de [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e de [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) .  Overrides \( [CMFCBaseTabCtrl::PreTranslateMessage](../Topic/CMFCBaseTabCtrl::PreTranslateMessage.md).\)|  
|`CMFCTabCtrl::RecalcLayout`|Recalcula o layout interno do controle de guia.  Overrides \( [CMFCBaseTabCtrl::RecalcLayout](../Topic/CMFCBaseTabCtrl::RecalcLayout.md).\)|  
|[CMFCTabCtrl::SetActiveInMDITabGroup](../Topic/CMFCTabCtrl::SetActiveInMDITabGroup.md)|Define a guia atual de um controle de guias como a guia ativa em um grupo de guia de interface de documentos múltiplos.|  
|[CMFCTabCtrl::SetActiveTab](../Topic/CMFCTabCtrl::SetActiveTab.md)|Ativa um guia.  Overrides \( [CMFCBaseTabCtrl::SetActiveTab](../Topic/CMFCBaseTabCtrl::SetActiveTab.md).\)|  
|[CMFCTabCtrl::SetActiveTabBoldFont](../Topic/CMFCTabCtrl::SetActiveTabBoldFont.md)|Habilita ou desativa uso de uma fonte em negrito guias ativos.|  
|[CMFCTabCtrl::SetDrawFrame](../Topic/CMFCTabCtrl::SetDrawFrame.md)|Habilita ou desabilita o retângulo de quadro de drawinga redor uma barra inserido.|  
|[CMFCTabCtrl::SetFlatFrame](../Topic/CMFCTabCtrl::SetFlatFrame.md)|Especifica se desenhar um plano ou um quadro 3D em torno da área de tabulação.|  
|[CMFCTabCtrl::SetImageList](../Topic/CMFCTabCtrl::SetImageList.md)|Especifica uma lista de imagem.  Overrides \( [CMFCBaseTabCtrl::SetImageList](../Topic/CMFCBaseTabCtrl::SetImageList.md).\)|  
|[CMFCTabCtrl::SetResizeMode](../Topic/CMFCTabCtrl::SetResizeMode.md)|Especifica como o controle atual da guia pode ser redimensionado e reexibe o controle.|  
|[CMFCTabCtrl::SetTabMaxWidth](../Topic/CMFCTabCtrl::SetTabMaxWidth.md)|Especifica a largura máximo da guia em uma janela com guias.|  
|[CMFCTabCtrl::StopResize](../Topic/CMFCTabCtrl::StopResize.md)|Finaliza a atual redimensiona a operação no controle de guias.|  
|`CMFCTabCtrl::SwapTabs`|Alterna um par de guias.  Overrides \( [CMFCBaseTabCtrl::SwapTabs](../Topic/CMFCBaseTabCtrl::SwapTabs.md).\)|  
|[CMFCTabCtrl::SynchronizeScrollBar](../Topic/CMFCTabCtrl::SynchronizeScrollBar.md)|Desenha uma barra de rolagem horizontal em um controle de guias que exibe snaplines lisos.|  
  
### Membros de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCTabCtrl::m\_bEnableActivate](../Topic/CMFCTabCtrl::m_bEnableActivate.md)|Impede a exibição ativa de foco perder nova guia quando um é inserido e ativado.|  
  
## Comentários  
 Suporta da classe de `CMFCTabCtrl` :  
  
-   Catalogue os estilos de controle que incluem 3D, simplificam, e simplificam com uma barra de rolagem horizontal compartilhado.  
  
-   Guias localizados na parte superior ou inferior da janela.  
  
-   Guias que exibem o texto, imagens, ou texto e imagens.  
  
-   Guias que alteram a cor quando a guia está ativa.  
  
-   O tamanho da borda muda para ajustáveis guias.  
  
-   O windows com guias destacáveis.  
  
 A classe de `CMFCTabCtrl` pode ser usada com uma caixa de diálogo, mas é destinada para aplicativos que usam o encaixe de barras de controle como [!INCLUDE[ofprexcel](../Token/ofprexcel_md.md)] e [!INCLUDE[vsprvs](../../assembler/masm/includes/vsprvs_md.md)].  Para mais informações, consulte [Classe de CDockablePane](../Topic/CDockablePane%20Class.md).  
  
 Siga estas etapas para adicionar um redimensionável, inserindo o controle de guias em seu aplicativo:  
  
1.  Crie uma instância de [Classe de CTabbedPane](../../mfc/reference/ctabbedpane-class.md).  
  
2.  Chame [CDockablePane::Create](../Topic/CDockablePane::Create.md).  
  
3.  Use [CBaseTabbedPane::AddTab](../Topic/CBaseTabbedPane::AddTab.md) ou [CMFCBaseTabCtrl::InsertTab](../Topic/CMFCBaseTabCtrl::InsertTab.md) para adicionar novas guias.  
  
4.  Chame [CBasePane::EnableDocking](../Topic/CBasePane::EnableDocking.md) de modo que o controle atual da guia de encaixe possa inserir na janela do quadro chave.  
  
5.  Chame [CFrameWndEx::DockPane](../Topic/CFrameWndEx::DockPane.md) para inserir a janela com guias no quadro chave.  
  
 Para um exemplo de como criar uma janela com guias como uma barra de controle de encaixe, consulte [Classe de CTabbedPane](../../mfc/reference/ctabbedpane-class.md).  Para usar `CMFCTabCtrl` como um controle que não são de encaixe, crie um objeto de `CMFCTabCtrl` e então chame [CMFCTabCtrl::Create](../Topic/CMFCTabCtrl::Create.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CMFCBaseTabCtrl](../../mfc/reference/cmfcbasetabctrl-class.md)  
  
 [CMFCTabCtrl](../../mfc/reference/cmfctabctrl-class.md)  
  
## Exemplo  
 O exemplo a seguir demonstra como usar vários métodos na classe de `CMFCTabCtrl` para configurar um objeto de `CMFCTabCtrl` .  O exemplo explica como adicionar um a guia, mostrar o botão fechar na guia ativa, active rótulos editáveis na guia, e exibir um menu pop\-up de rótulos de janela com guias.  Este exemplo é parte de [Exemplo da coleção de estado](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_StateCollection#1](../../mfc/reference/codesnippet/CPP/cmfctabctrl-class_1.h)]  
[!code-cpp[NVC_MFC_StateCollection#3](../../mfc/reference/codesnippet/CPP/cmfctabctrl-class_2.cpp)]  
  
## Requisitos  
 **Cabeçalho:** afxtabctrl.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CDockablePane](../Topic/CDockablePane%20Class.md)   
 [Classe de CDockablePane](../Topic/CDockablePane%20Class.md)   
 [Classe de CMFCBaseTabCtrl](../../mfc/reference/cmfcbasetabctrl-class.md)