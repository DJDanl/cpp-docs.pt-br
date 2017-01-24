---
title: "Classe de CMFCOutlookBarTabCtrl | Microsoft Docs"
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
  - "CMFCOutlookBarTabCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCOutlookBarTabCtrl"
ms.assetid: b1f2b3f7-cc59-49a3-99d8-7ff9b37c044b
caps.latest.revision: 26
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCOutlookBarTabCtrl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um controle de guias que possui a aparência visual de **Painel de navegação** no Microsoft Outlook.  
  
## Sintaxe  
  
```  
class CMFCOutlookBarTabCtrl : public CMFCBaseTabCtrl  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCOutlookBarTabCtrl::CMFCOutlookBarTabCtrl`|Construtor padrão.|  
|`CMFCOutlookBarTabCtrl::~CMFCOutlookBarTabCtrl`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCOutlookBarTabCtrl::AddControl](../Topic/CMFCOutlookBarTabCtrl::AddControl.md)|Adiciona um controle do windows como uma nova aba na barra do Outlook.|  
|`CMFCOutlookBarTabCtrl::CalcRectEdit`|Chamado pela estrutura para determinar as dimensões da caixa de edição que aparece quando um usuário renomeia um guia.  Overrides \( `CMFCBaseTabCtrl::CalcRectEdit`.\)|  
|[CMFCOutlookBarTabCtrl::CanShowFewerPageButtons](../Topic/CMFCOutlookBarTabCtrl::CanShowFewerPageButtons.md)|Chamado pela estrutura durante operações de redimensionamento para determinar se menos botões da guia da barra do Outlook podem ser exibidos do que é visível no momento.|  
|[CMFCOutlookBarTabCtrl::CanShowMorePageButtons](../Topic/CMFCOutlookBarTabCtrl::CanShowMorePageButtons.md)|Chamado pela estrutura durante operações de redimensionamento para determinar se mais botões da guia da barra do Outlook podem ser exibidos do que é visível no momento.|  
|[CMFCOutlookBarTabCtrl::Create](../Topic/CMFCOutlookBarTabCtrl::Create.md)|Cria o controle da guia da barra do Outlook.|  
|`CMFCOutlookBarTabCtrl::CreateObject`|Usado pela estrutura dinâmica para criar uma instância de esse tipo da classe.|  
|[CMFCOutlookBarTabCtrl::EnableAnimation](../Topic/CMFCOutlookBarTabCtrl::EnableAnimation.md)|Especifica se a animação que ocorre durante alterne entre ativos guias está habilitada.|  
|[CMFCOutlookBarTabCtrl::EnableInPlaceEdit](../Topic/CMFCOutlookBarTabCtrl::EnableInPlaceEdit.md)|Especifica se um usuário pode alterar os rótulos de texto nos botões da barra do Outlook.  Overrides \( [CMFCBaseTabCtrl::EnableInPlaceEdit](../Topic/CMFCBaseTabCtrl::EnableInPlaceEdit.md).\)|  
|[CMFCOutlookBarTabCtrl::EnableScrollButtons](../Topic/CMFCOutlookBarTabCtrl::EnableScrollButtons.md)|Chamado pela estrutura para ativar botões que permitem ao usuário percorra os botões no painel da barra do Outlook.|  
|`CMFCOutlookBarTabCtrl::FindTargetWnd`|Identifica o painel que contém um ponto específico.  Overrides \( [CMFCBaseTabCtrl::FindTargetWnd](../Topic/CMFCBaseTabCtrl::FindTargetWnd.md).\)|  
|[CMFCOutlookBarTabCtrl::GetBorderSize](../Topic/CMFCOutlookBarTabCtrl::GetBorderSize.md)|Retorna o tamanho da borda do controle da guia do Outlook.|  
|`CMFCOutlookBarTabCtrl::GetTabArea`|Retorna o tamanho e a posição da área da guia do controle de guia.  Overrides \( [CMFCBaseTabCtrl::GetTabArea](../Topic/CMFCBaseTabCtrl::GetTabArea.md).\)|  
|`CMFCOutlookBarTabCtrl::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto de [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) que está associado com esse tipo da classe.|  
|[CMFCOutlookBarTabCtrl::GetVisiblePageButtons](../Topic/CMFCOutlookBarTabCtrl::GetVisiblePageButtons.md)||  
|[CMFCOutlookBarTabCtrl::IsAnimation](../Topic/CMFCOutlookBarTabCtrl::IsAnimation.md)|Determina se a animação que ocorre durante alterne entre ativos guias está habilitada.|  
|[CMFCOutlookBarTabCtrl::IsMode2003](../Topic/CMFCOutlookBarTabCtrl::IsMode2003.md)|Determina se o controle da guia da barra do Outlook estiver de forma que emule Microsoft Outlook 2003.|  
|`CMFCOutlookBarTabCtrl::IsPtInTabArea`|Determina se um ponto está dentro da área de tabulação.  Overrides \( [CMFCBaseTabCtrl::IsPtInTabArea](../Topic/CMFCBaseTabCtrl::IsPtInTabArea.md).\)|  
|`CMFCOutlookBarTabCtrl::IsTabDetachable`|Determina se uma guia ser destacável.  Overrides \( [CMFCBaseTabCtrl::IsTabDetachable](../Topic/CMFCBaseTabCtrl::IsTabDetachable.md).\)|  
|`CMFCOutlookBarTabCtrl::OnChangeTabs`|Chamado pela estrutura quando uma guia é inserido ou removido.  Overrides \( `CMFCBaseTabCtrl::OnChangeTabs`.\)|  
|[CMFCOutlookBarTabCtrl::OnShowFewerPageButtons](../Topic/CMFCOutlookBarTabCtrl::OnShowFewerPageButtons.md)|Chamado pela estrutura para reduzir o número de botões de guia que são visíveis.|  
|[CMFCOutlookBarTabCtrl::OnShowMorePageButtons](../Topic/CMFCOutlookBarTabCtrl::OnShowMorePageButtons.md)|Chamado pela estrutura para aumentar o número de botões de guia que são visíveis.|  
|[CMFCOutlookBarTabCtrl::OnShowOptions](../Topic/CMFCOutlookBarTabCtrl::OnShowOptions.md)|Exibe a caixa de diálogo de **Opções do Painel de Navegação** .|  
|`CMFCOutlookBarTabCtrl::RecalcLayout`|Recalcula o layout interno do controle de guia.  Overrides \( [CMFCBaseTabCtrl::RecalcLayout](../Topic/CMFCBaseTabCtrl::RecalcLayout.md).\)|  
|[CMFCOutlookBarTabCtrl::SetActiveTab](../Topic/CMFCOutlookBarTabCtrl::SetActiveTab.md)|Define a guia.  Overrides \( [CMFCBaseTabCtrl::SetActiveTab](../Topic/CMFCBaseTabCtrl::SetActiveTab.md).\)|  
|[CMFCOutlookBarTabCtrl::SetBorderSize](../Topic/CMFCOutlookBarTabCtrl::SetBorderSize.md)|Defina o tamanho da borda do controle da guia do Outlook.|  
|[CMFCOutlookBarTabCtrl::SetPageButtonTextAlign](../Topic/CMFCOutlookBarTabCtrl::SetPageButtonTextAlign.md)|Define o alinhamento de rótulos de texto nos botões da barra do Outlook.|  
|[CMFCOutlookBarTabCtrl::SetToolbarImageList](../Topic/CMFCOutlookBarTabCtrl::SetToolbarImageList.md)|Define o bitmap que contém os ícones que são exibidos na parte inferior da barra do Outlook no modo de [Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)Outlook 2003 \(consulte\).|  
|[CMFCOutlookBarTabCtrl::SetVisiblePageButtons](../Topic/CMFCOutlookBarTabCtrl::SetVisiblePageButtons.md)||  
  
## Comentários  
 Para criar o Outlook barre que possui suporte de encaixe, use um objeto de `CMFCOutlookBar` para hospedar o controle da guia da barra do Outlook.  Para mais informações, consulte [Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md).  
  
## Exemplo  
 O exemplo a seguir demonstra como inicializar um objeto de `CMFCOutlookBarTabCtrl` e para usar vários métodos em `CMFCOutlookBarTabCtrl` classe.  O exemplo a seguir mostra como habilitar a edição in\-loco de rótulo de texto nos botões de guia da barra do Outlook, permite a animação, permite que as alças de rolagem que permitem ao usuário para percorrer os botões no painel da barra do Outlook, defina o tamanho da borda do controle da guia do Outlook, e definem o alinhamento de rótulos de texto nos botões da barra do Outlook.  Este trecho de código é parte de [Exemplo de demonstração do Outlook](../../top/visual-cpp-samples.md).  
  
 [!CODE [NVC_MFC_OutlookDemo#1](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_OutlookDemo#1)]  
[!CODE [NVC_MFC_OutlookDemo#2](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_OutlookDemo#2)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CMFCBaseTabCtrl](../../mfc/reference/cmfcbasetabctrl-class.md)  
  
 [CMFCOutlookBarTabCtrl](../../mfc/reference/cmfcoutlookbartabctrl-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxoutlookbartabctrl.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCBaseTabCtrl](../../mfc/reference/cmfcbasetabctrl-class.md)   
 [Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)   
 [Classe de CMFCOutlookBarPane](../../mfc/reference/cmfcoutlookbarpane-class.md)