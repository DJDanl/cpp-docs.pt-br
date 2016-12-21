---
title: "Classe CBaseTabbedPane | Microsoft Docs"
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
  - "CBaseTabbedPane"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CBaseTabbedPane"
ms.assetid: f22c0080-5b29-4a0a-8f74-8f0a4cd2dbcf
caps.latest.revision: 26
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CBaseTabbedPane
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Estendem a funcionalidade de [Classe de CDockablePane](../Topic/CDockablePane%20Class.md) para oferecer suporte à criação do windows com guias.  
  
## Sintaxe  
  
```  
class CBaseTabbedPane : public CDockablePane  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|`CBaseTabbedPane::CBaseTabbedPane`|Construtor padrão.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CBaseTabbedPane::AddTab](../Topic/CBaseTabbedPane::AddTab.md)|Adiciona um novo a guia um painel com guias.|  
|[CBaseTabbedPane::AllowDestroyEmptyTabbedPane](../Topic/CBaseTabbedPane::AllowDestroyEmptyTabbedPane.md)|Especifica se um painel com guias vazio pode ser destruído.|  
|[CBaseTabbedPane::ApplyRestoredTabInfo](../Topic/CBaseTabbedPane::ApplyRestoredTabInfo.md)|Aplica as configurações de guia, que são carregadas do Registro, um painel com guias.|  
|[CBaseTabbedPane::CanFloat](../Topic/CBaseTabbedPane::CanFloat.md)|Determina se o painel puder flutuante.  Overrides \( [CBasePane::CanFloat](../Topic/CBasePane::CanFloat.md).\)|  
|[CBaseTabbedPane::CanSetCaptionTextToTabName](../Topic/CBaseTabbedPane::CanSetCaptionTextToTabName.md)|Determina se a legenda para o painel com guias deve exibir o mesmo texto que a ativo.|  
|[CBaseTabbedPane::ConvertToTabbedDocument](../Topic/CBaseTabbedPane::ConvertToTabbedDocument.md)|Overrides \( [CDockablePane::ConvertToTabbedDocument](../Topic/CDockablePane::ConvertToTabbedDocument.md).\)|  
|[CBaseTabbedPane::DetachPane](../Topic/CBaseTabbedPane::DetachPane.md)|Converte um ou vários painéis encaixáveis a MDI catalogou documentos.|  
|[CBaseTabbedPane::EnableSetCaptionTextToTabName](../Topic/CBaseTabbedPane::EnableSetCaptionTextToTabName.md)|Habilita ou desabilita a capacidade do painel sincronizar com guias do texto de legenda com o texto do rótulo na guia.|  
|[CBaseTabbedPane::FillDefaultTabsOrderArray](../Topic/CBaseTabbedPane::FillDefaultTabsOrderArray.md)|Restaura a ordem de tabulação interno em um estado padrão.|  
|[CBaseTabbedPane::FindBarByTabNumber](../Topic/CBaseTabbedPane::FindBarByTabNumber.md)|Retorna um painel que reside em um guia quando a guia é identificado por um índice com base zero de tabulação.|  
|||  
|[CBaseTabbedPane::FindPaneByID](../Topic/CBaseTabbedPane::FindPaneByID.md)|Retorna um painel que é identificado pela identificação do painel|  
|[CBaseTabbedPane::FloatTab](../Topic/CBaseTabbedPane::FloatTab.md)|Flutua um painel, mas somente se o painel está atualmente em uma guia destacável.|  
|[CBaseTabbedPane::GetDefaultTabsOrder](../Topic/CBaseTabbedPane::GetDefaultTabsOrder.md)|Retorna a ordem padrão de guias no painel.|  
|[CBaseTabbedPane::GetFirstVisibleTab](../Topic/CBaseTabbedPane::GetFirstVisibleTab.md)|Recupera um ponteiro para a guia primeiro exibido.|  
|[CBaseTabbedPane::GetMinSize](../Topic/CBaseTabbedPane::GetMinSize.md)|Retorna o tamanho mínimo permitido para o painel.  Overrides \( [CPane::GetMinSize](../Topic/CPane::GetMinSize.md).\)|  
|[CBaseTabbedPane::GetPaneIcon](../Topic/CBaseTabbedPane::GetPaneIcon.md)|Retorna um identificador para o ícone do painel.  Overrides \( [CBasePane::GetPaneIcon](../Topic/CBasePane::GetPaneIcon.md).\)|  
|[CBaseTabbedPane::GetPaneList](../Topic/CBaseTabbedPane::GetPaneList.md)|Retorna uma lista de painéis que estão contidos no painel com guias.|  
|[CBaseTabbedPane::GetTabArea](../Topic/CBaseTabbedPane::GetTabArea.md)|Retorna o retângulo delimitador para as áreas da guia superior e inferior.|  
|[CBaseTabbedPane::GetTabsNum](../Topic/CBaseTabbedPane::GetTabsNum.md)|Retorna a contagem de guias em uma janela na guia.|  
|[CBaseTabbedPane::GetUnderlyingWindow](../Topic/CBaseTabbedPane::GetUnderlyingWindow.md)|Obtém a janela \(\) é subjacente ao guia.|  
|[CBaseTabbedPane::GetVisibleTabsNum](../Topic/CBaseTabbedPane::GetVisibleTabsNum.md)|Retorna a contagem de guias exibidos.|  
|[CBaseTabbedPane::HasAutoHideMode](../Topic/CBaseTabbedPane::HasAutoHideMode.md)|Determina se o painel com guias pode ser alternado para modo automático ocultar de.|  
|[CBaseTabbedPane::IsHideSingleTab](../Topic/CBaseTabbedPane::IsHideSingleTab.md)|Determina se o painel com guias está oculto se apenas um guia é exibida.|  
|`CBaseTabbedPane::LoadSiblingPaneIDs`|Usado internamente durante a serialização.|  
|[CBaseTabbedPane::RecalcLayout](../Topic/CBaseTabbedPane::RecalcLayout.md)|Recalcula informações de layout para o painel.  Overrides \( [CPane::RecalcLayout](../Topic/CPane::RecalcLayout.md).\)|  
|[CBaseTabbedPane::RemovePane](../Topic/CBaseTabbedPane::RemovePane.md)|Remove um painel do painel com guias.|  
|`CBaseTabbedPane::SaveSiblingBarIDs`|Usado internamente durante a serialização.|  
|`CBaseTabbedPane::Serialize`|Overrides \( [CDockablePane::Serialize](http://msdn.microsoft.com/pt-br/09787e59-e446-4e76-894b-206d303dcfd6).\)|  
|`CBaseTabbedPane::SerializeTabWindow`|Usado internamente durante a serialização.|  
|[CBaseTabbedPane::SetAutoDestroy](../Topic/CBaseTabbedPane::SetAutoDestroy.md)|Determina se a barra de controle com guias será automaticamente destruída.|  
|[CBaseTabbedPane::SetAutoHideMode](../Topic/CBaseTabbedPane::SetAutoHideMode.md)|Alterna \/desativar o painel de encaixe exibido entre o modo de incrementos ocultar e.  Overrides \( [CDockablePane::SetAutoHideMode](../Topic/CDockablePane::SetAutoHideMode.md).\)|  
|[CBaseTabbedPane::ShowTab](../Topic/CBaseTabbedPane::ShowTab.md)|Mostra ou oculta uma guia.|  
  
## Comentários  
 Essa classe é uma classe abstrata e não pode ser instanciada.  Implementa os serviços que são comuns a todos os tipos dos painéis com guias.  
  
 Atualmente, a biblioteca inclui duas classes derivadas com guias do painel: [Classe de CTabbedPane](../../mfc/reference/ctabbedpane-class.md) e [Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md).  
  
 Um objeto de `CBaseTabbedPane` envolve um ponteiro para um objeto de [Classe de CMFCBaseTabCtrl](../../mfc/reference/cmfcbasetabctrl-class.md) .  [Classe de CMFCBaseTabCtrl](../../mfc/reference/cmfcbasetabctrl-class.md) transformações em uma janela filho do painel com guias.  
  
 Para obter mais informações sobre como criar os painéis com guias, consulte [Classe de CDockablePane](../Topic/CDockablePane%20Class.md), [Classe de CTabbedPane](../../mfc/reference/ctabbedpane-class.md), e [Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md).  
  
## Hierarquia de Herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CDockablePane](../Topic/CDockablePane%20Class.md)  
  
 [CBaseTabbedPane](../../mfc/reference/cbasetabbedpane-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxBaseTabbedPane.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CDockablePane](../Topic/CDockablePane%20Class.md)