---
title: "Classe de CMFCOutlookBarPane | Microsoft Docs"
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
  - "CMFCOutlookBarPane"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método de CanBeRestored"
  - "Classe de CMFCOutlookBarPane"
  - "Método dock"
  - "Método de IsChangeState"
  - "Método de OnBeforeFloat"
  - "Método de RestoreOriginalstate"
  - "Método de SmartUpdate"
ms.assetid: 094e2ef3-a118-487e-a4cc-27626108fe08
caps.latest.revision: 30
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCOutlookBarPane
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

[!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
 Um controle derivado de [Classe de CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md) que pode ser inserido em uma barra do Outlook \([Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)\).  O painel da barra do Outlook contém uma coluna de botões grandes.  O usuário pode rolar para cima e para baixo da lista de botões se é maior que o painel.  Quando o usuário dispara um painel da barra do Outlook de barra do Outlook, pode posicioná\-la tanto ou entrar na janela do quadro chave.  
  
## Sintaxe  
  
```  
class CMFCOutlookBarPane : public CMFCToolBar  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCOutlookBarPane::CMFCOutlookBarPane`|Construtor padrão.|  
|`CMFCOutlookBarPane::~CMFCOutlookBarPane`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCOutlookBarPane::AddButton](../Topic/CMFCOutlookBarPane::AddButton.md)|Adicionar um botão ao painel da barra do Outlook.|  
|[CMFCOutlookBarPane::CanBeAttached](../Topic/CMFCOutlookBarPane::CanBeAttached.md)|Determina se o painel puder ser encaixado a outra janela do painel ou quadro.  Overrides \( [CBasePane::CanBeAttached](../Topic/CBasePane::CanBeAttached.md).\)|  
|`CMFCOutlookBarPane::CanBeRestored`|Determina se o sistema pode restaurar uma barra de ferramentas para seu estado original após a personalização.  Overrides \( [CMFCToolBar::CanBeRestored](../Topic/CMFCToolBar::CanBeRestored.md).\)|  
|[CMFCOutlookBarPane::ClearAll](../Topic/CMFCOutlookBarPane::ClearAll.md)|Libera os recursos usados pelas imagens no painel da barra do Outlook.|  
|[CMFCOutlookBarPane::Create](../Topic/CMFCOutlookBarPane::Create.md)|Cria o painel da barra do Outlook.|  
|`CMFCOutlookBarPane::CreateObject`|Usado pela estrutura dinâmica para criar uma instância de esse tipo da classe.|  
|`CMFCOutlookBarPane::Dock`|Chamado pela estrutura para encaixar o painel da barra do Outlook. Overrides \( `CPane::Dock`.\)|  
|[CMFCOutlookBarPane::EnablePageScrollMode](../Topic/CMFCOutlookBarPane::EnablePageScrollMode.md)|Especifica se as setas de rolagem no painel da barra do Outlook avançam a lista de botões por página, ou pelo botão.|  
|[CMFCOutlookBarPane::GetRegularColor](../Topic/CMFCOutlookBarPane::GetRegularColor.md)|Retorna o texto da cor selecionada normal \(não\) do painel de barra do Outlook.|  
|`CMFCOutlookBarPane::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto de [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) que está associado com esse tipo da classe.|  
|[CMFCOutlookBarPane::IsBackgroundTexture](../Topic/CMFCOutlookBarPane::IsBackgroundTexture.md)|Determina se houver uma imagem de plano de fundo carregada para o painel de barra do Outlook.|  
|`CMFCOutlookBarPane::IsChangeState`|Determina se um painel flutuante pode ser conectado.  Overrides \( `CPane::IsChangeState`.\)|  
|[CMFCOutlookBarPane::IsDrawShadedHighlight](../Topic/CMFCOutlookBarPane::IsDrawShadedHighlight.md)|Determina se a borda do botão é protegida quando um botão é realçado e uma imagem de plano de fundo é exibida.|  
|`CMFCOutlookBarPane::OnBeforeFloat`|Chamado pela estrutura quando um painel é a de ponto flutuante.  Overrides \( [CPane::OnBeforeFloat](../Topic/CPane::OnBeforeFloat.md).\)|  
|[CMFCOutlookBarPane::RemoveButton](../Topic/CMFCOutlookBarPane::RemoveButton.md)|Remove o botão que tem um certo ID de comando|  
|`CMFCOutlookBarPane::RestoreOriginalstate`|Restaura o estado original de uma barra de ferramentas.  Overrides \( [CMFCToolBar::RestoreOriginalState](../Topic/CMFCToolBar::RestoreOriginalState.md).\)|  
|[CMFCOutlookBarPane::SetBackColor](../Topic/CMFCOutlookBarPane::SetBackColor.md)|Define a cor do plano de fundo.|  
|[CMFCOutlookBarPane::SetBackImage](../Topic/CMFCOutlookBarPane::SetBackImage.md)|Define a imagem de plano de fundo.|  
|[CMFCOutlookBarPane::SetDefaultState](../Topic/CMFCOutlookBarPane::SetDefaultState.md)|Redefine o painel da barra do Outlook para o original conjunto de botões.|  
|[CMFCOutlookBarPane::SetExtraSpace](../Topic/CMFCOutlookBarPane::SetExtraSpace.md)|Define o número de pixels de preenchimento usados em torno os botões no painel da barra do Outlook.|  
|[CMFCOutlookBarPane::SetTextColor](../Topic/CMFCOutlookBarPane::SetTextColor.md)|Defina as cores de texto normal e realçado no painel da barra do Outlook.|  
|[CMFCOutlookBarPane::SetTransparentColor](../Topic/CMFCOutlookBarPane::SetTransparentColor.md)|Define a cor transparente para o painel de barra do Outlook.|  
|`CMFCOutlookBarPane::SmartUpdate`|Usado internamente para atualizar a barra do Outlook.  Overrides \( `CMFCToolBar::SmartUpdate`.\)|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCOutlookBarPane::EnableContextMenuItems](../Topic/CMFCOutlookBarPane::EnableContextMenuItems.md)|Especifica que os itens de menu de atalho são exibidos no modo de personalização.|  
|[CMFCOutlookBarPane::RemoveAllButtons](../Topic/CMFCOutlookBarPane::RemoveAllButtons.md)|Remove todos os botões da barra do painel do Outlook.  Overrides \( [CMFCToolBar::RemoveAllButtons](../Topic/CMFCToolBar::RemoveAllButtons.md).\)|  
  
## Comentários  
 Para obter informações sobre como implementar uma barra do Outlook, consulte [Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md).  
  
 Para um exemplo de uma barra do Outlook, consulte o exemplo de OutlookDemo projeto.  
  
## Exemplo  
 O exemplo seguinte demonstra como usar vários métodos da classe de `CMFCOutlookBarPane` .  O exemplo a seguir mostra como criar um painel da barra do Outlook, ativar o modo de rolagem da página, permite encaixe, e define a cor do plano de fundo da barra do Outlook.  Este trecho de código é parte de [Exemplo das exibições de multi Outlook](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_OutlookMultiViews#3](../../mfc/reference/codesnippet/CPP/cmfcoutlookbarpane-class_1.h)]  
[!code-cpp[NVC_MFC_OutlookMultiViews#4](../../mfc/reference/codesnippet/CPP/cmfcoutlookbarpane-class_2.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CMFCBaseToolBar](../../mfc/reference/cmfcbasetoolbar-class.md)  
  
 [CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)  
  
 [CMFCOutlookBarPane](../../mfc/reference/cmfcoutlookbarpane-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxoutlookbarpane.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)   
 [Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)   
 [Classe de CMFCOutlookBarTabCtrl](../../mfc/reference/cmfcoutlookbartabctrl-class.md)