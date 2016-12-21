---
title: "Classe de CPane | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CPane"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CPane"
ms.assetid: 5c651a64-3c79-4d94-9676-45f6402a6bc5
caps.latest.revision: 30
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CPane
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CPane` é um aperfeiçoamento de [Classe de CControlBar](../../mfc/reference/ccontrolbar-class.md).  Se você estiver atualizando um projeto existente MFC, substitua todas as ocorrências de `CControlBar` com `CPane`.  
  
## Sintaxe  
  
```  
class CPane : public CBasePane  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|`CPane::~CPane`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPane::AdjustSizeImmediate](../Topic/CPane::AdjustSizeImmediate.md)|Recalcula imediatamente o layout de um painel.|  
|[CPane::AllocElements](../Topic/CPane::AllocElements.md)|Atribui o armazenamento para uso interno.|  
|[CPane::AllowShowOnPaneMenu](../Topic/CPane::AllowShowOnPaneMenu.md)|Especifica se o painel é listado na lista tempo de execução gerado de painéis para o aplicativo.|  
|[CPane::CalcAvailableSize](../Topic/CPane::CalcAvailableSize.md)|Calcula a diferença em tamanho entre um retângulo especificado e o retângulo a janela atual.|  
|[CPane::CalcInsideRect](../Topic/CPane::CalcInsideRect.md)|Calcula o retângulo interno de um painel, levando em conta as bordas e os prendedores.|  
|[CPane::CalcRecentDockedRect](../Topic/CPane::CalcRecentDockedRect.md)|Calcula o retângulo recém\-conectado.|  
|[CPane::CalcSize](../Topic/CPane::CalcSize.md)|Calcula o tamanho do painel.|  
|[CPane::CanBeDocked](../Topic/CPane::CanBeDocked.md)|Determina se o painel puder ser encaixado no painel de base especificado.|  
|[CPane::CanBeTabbedDocument](../Topic/CPane::CanBeTabbedDocument.md)|Determina se o painel puder ser convertido em um documento com guias.|  
|[CPane::ConvertToTabbedDocument](../Topic/CPane::ConvertToTabbedDocument.md)|Converte um painel encaixável a um documento com guias.|  
|[CPane::CopyState](../Topic/CPane::CopyState.md)|Copia o estado de um painel.  Overrides \( [CBasePane::CopyState](../Topic/CBasePane::CopyState.md).\)|  
|[CPane::Create](../Topic/CPane::Create.md)|Cria uma barra de controle e anexá\-la ao objeto de `CPane` .|  
|[CPane::CreateDefaultMiniframe](../Topic/CPane::CreateDefaultMiniframe.md)|Cria uma janela de mini\-linguagem quadro para um painel flutuante.|  
|[CPane::CreateEx](../Topic/CPane::CreateEx.md)|Cria uma barra de controle e anexá\-la ao objeto de `CPane` .|  
|`CPane::CreateObject`|Usado pela estrutura dinâmica para criar uma instância de esse tipo da classe.|  
|[CPane::DockByMouse](../Topic/CPane::DockByMouse.md)|Insere um painel usando o método de encaixe do mouse.|  
|[CPane::DockPane](../Topic/CPane::DockPane.md)|Insere o painel flutuante a um painel base.|  
|[CPane::DockPaneStandard](../Topic/CPane::DockPaneStandard.md)|Insere um painel usando o encaixe de estrutura \(padrão\).|  
|[CPane::DockToFrameWindow](../Topic/CPane::DockToFrameWindow.md)|Insere um painel encaixável a um quadro.  Overrides \( `CBasePane::DockToFrameWindow`.\)|  
|[CPane::DoesAllowSiblingBars](../Topic/CPane::DoesAllowSiblingBars.md)|Indica se você pode inserir outro painel na mesma linha onde o painel atual está conectado.|  
|[CPane::FloatPane](../Topic/CPane::FloatPane.md)|Flutua o painel.|  
|[CPane::GetAvailableExpandSize](../Topic/CPane::GetAvailableExpandSize.md)|Retorna a quantidade, em pixels, que pode expandir o painel.|  
|[CPane::GetAvailableStretchSize](../Topic/CPane::GetAvailableStretchSize.md)|Retorna a quantidade, em pixels, que pode reduzir o painel.|  
|[CPane::GetBorders](../Topic/CPane::GetBorders.md)|Retorna a largura das bordas do painel.|  
|[CPane::GetClientHotSpot](../Topic/CPane::GetClientHotSpot.md)|Retorna *o ponto de acesso* para o painel.|  
|[CPane::GetDockSiteRow](../Topic/CPane::GetDockSiteRow.md)|Retorna a linha de encaixe em que o painel é conectado.|  
|[CPane::GetExclusiveRowMode](../Topic/CPane::GetExclusiveRowMode.md)|Determina se o painel está no modo exclusivo da linha.|  
|[CPane::GetHotSpot](../Topic/CPane::GetHotSpot.md)|Retorna o ponto de acesso que é armazenado em um objeto subjacente de `CMFCDragFrameImpl` .|  
|[CPane::GetMinSize](../Topic/CPane::GetMinSize.md)|Retorna o tamanho mínimo permitido para o painel.|  
|[CPane::GetPaneName](../Topic/CPane::GetPaneName.md)|Recupera o título para o painel.|  
|`CPane::GetResizeStep`|Usado internamente.|  
|`CPane::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto de [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) que está associado com esse tipo da classe.|  
|[CPane::GetVirtualRect](../Topic/CPane::GetVirtualRect.md)|Recupera *o retângulo virtual* do painel.|  
|[CPane::IsChangeState](../Topic/CPane::IsChangeState.md)|Como o painel está sendo movido, esse método analisa a posição do painel em relação a outros painéis, inserir linhas, e janelas de mini\-linguagem quadro, e retorna o valor apropriado de `AFX_CS_STATUS` .|  
|[CPane::IsDragMode](../Topic/CPane::IsDragMode.md)|Especifica se o painel está sendo arrastado.|  
|[CPane::IsInFloatingMultiPaneFrameWnd](../Topic/CPane::IsInFloatingMultiPaneFrameWnd.md)|Especifica se o painel em uma janela de quadro chave com multipainéis.  Overrides \( `CBasePane::IsInFloatingMultiPaneFrameWnd`.\)|  
|[CPane::IsLeftOf](../Topic/CPane::IsLeftOf.md)|Determina se o painel é deixado \(ou\) acima do retângulo especificado.|  
|[CPane::IsResizable](../Topic/CPane::IsResizable.md)|Determina se o painel pode ser redimensionado.  Overrides \( [CBasePane::IsResizable](../Topic/CBasePane::IsResizable.md).\)|  
|[CPane::IsTabbed](../Topic/CPane::IsTabbed.md)|Determina se o painel foi inserido no controle de guias de uma janela com guias.  Overrides \( [CBasePane::IsTabbed](../Topic/CBasePane::IsTabbed.md).\)|  
|[CPane::LoadState](../Topic/CPane::LoadState.md)|Carrega o estado do painel do Registro.  Overrides \( [CBasePane::LoadState](../Topic/CBasePane::LoadState.md).\)|  
|[CPane::MoveByAlignment](../Topic/CPane::MoveByAlignment.md)|Move o painel e o retângulo virtual pela quantidade especificada.|  
|[CPane::MovePane](../Topic/CPane::MovePane.md)|Move o painel para o retângulo especificado.|  
|[CPane::OnAfterChangeParent](../Topic/CPane::OnAfterChangeParent.md)|Chamado pela estrutura quando o pai de um painel alterar.|  
|[CPane::OnBeforeChangeParent](../Topic/CPane::OnBeforeChangeParent.md)|Chamado pela estrutura quando o pai do painel é a ponto de alterar.|  
|[CPane::OnPressCloseButton](../Topic/CPane::OnPressCloseButton.md)|Chamado pela estrutura quando o usuário escolha o botão fechar a legenda para o painel.|  
|`CPane::OnProcessDblClk`|Usado internamente.|  
|[CPane::OnShowControlBarMenu](../Topic/CPane::OnShowControlBarMenu.md)|Chamado pela estrutura quando um menu especial do painel está prestes a ser exibido.|  
|[CPane::OnShowControlBarMenu](../Topic/CPane::OnShowControlBarMenu.md)|Chamado pela estrutura quando um menu especial do painel está prestes a ser exibido.|  
|`CPane::PrepareToDock`|Usado internamente.|  
|[CPane::RecalcLayout](../Topic/CPane::RecalcLayout.md)|Recalcula informações de layout para o painel.  Overrides \( [CBasePane::RecalcLayout](../Topic/CBasePane::RecalcLayout.md).\)|  
|[CPane::SaveState](../Topic/CPane::SaveState.md)|Salvar o estado do painel no Registro.  Overrides \( [CBasePane::SaveState](../Topic/CBasePane::SaveState.md).\)|  
|[CPane::SetActiveInGroup](../Topic/CPane::SetActiveInGroup.md)|Sinaliza um painel como ativo.|  
|[CPane::SetBorders](../Topic/CPane::SetBorders.md)|Defina os valores da borda do painel.|  
|[CPane::SetClientHotSpot](../Topic/CPane::SetClientHotSpot.md)|Define o ponto de acesso para o painel.|  
|[CPane::SetDockState](../Topic/CPane::SetDockState.md)|O restaurará que passa informações de estado para o painel.|  
|[CPane::SetExclusiveRowMode](../Topic/CPane::SetExclusiveRowMode.md)|Habilita ou desabilita o modo exclusivo da linha.|  
|[CPane::SetMiniFrameRTC](../Topic/CPane::SetMiniFrameRTC.md)|Define informações da classe em tempo de execução para a janela padrão de mini\-linguagem quadro.|  
|[CPane::SetMinSize](../Topic/CPane::SetMinSize.md)|Defina o tamanho mínimo permitido para o painel.|  
|[CPane::SetVirtualRect](../Topic/CPane::SetVirtualRect.md)|Define *o retângulo virtual* do painel.|  
|[CPane::StretchPaneDeferWndPos](../Topic/CPane::StretchPaneDeferWndPos.md)|O painel expande horizontalmente ou verticalmente com base no estilo de encaixe.|  
|[CPane::ToggleAutoHide](../Topic/CPane::ToggleAutoHide.md)|Modo automático ocultar de encaixar.|  
|[CPane::UndockPane](../Topic/CPane::UndockPane.md)|Remove o painel do site da plataforma, padrão de controle deslizante, ou da janela de mini\-linguagem quadro onde está conectado no momento.  Overrides \( [CBasePane::UndockPane](../Topic/CBasePane::UndockPane.md).\)|  
|[CPane::UpdateVirtualRect](../Topic/CPane::UpdateVirtualRect.md)|Atualiza o retângulo virtual.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPane::OnAfterDock](../Topic/CPane::OnAfterDock.md)|Chamado pela estrutura quando um painel estiver conectado.|  
|[CPane::OnAfterFloat](../Topic/CPane::OnAfterFloat.md)|Chamado pela estrutura quando um painel é flutuado.|  
|[CPane::OnBeforeDock](../Topic/CPane::OnBeforeDock.md)|Chamado pela estrutura quando o painel está prestes a ser conectado.|  
|[CPane::OnBeforeFloat](../Topic/CPane::OnBeforeFloat.md)|Chamado pela estrutura quando um painel está prestes a ser flutuada.|  
  
### Membros de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPane::m\_bHandleMinSize](../Topic/CPane::m_bHandleMinSize.md)|Permite que a manipulação consistente de tamanho mínimo para os painéis.|  
|[CPane::m\_recentDockInfo](../Topic/CPane::m_recentDockInfo.md)|Contém informações de encaixe recente.|  
  
## Comentários  
 Normalmente, os objetos de `CPane` não são instanciados diretamente.  Se você requer um painel que tenha funcionalidade de encaixe, derive o objeto de [CDockablePane](../Topic/CDockablePane%20Class.md).  Se você precisar da funcionalidade da barra de ferramentas, derive o objeto de [CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md).  
  
 Quando você deriva de uma classe `CPane`, pode ser inserido em [CDockSite](../../mfc/reference/cdocksite-class.md) e pode ser flutuado em [CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxPane.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CBasePane](../../mfc/reference/cbasepane-class.md)