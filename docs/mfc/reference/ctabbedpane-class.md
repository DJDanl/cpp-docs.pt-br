---
title: "Classe de CTabbedPane | Microsoft Docs"
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
  - "CTabbedPane"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CTabbedPane"
ms.assetid: f4dc5215-b789-4f2d-8c62-477aceda3578
caps.latest.revision: 27
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CTabbedPane
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa a funcionalidade de um painel com guias destacável.  
  
## Sintaxe  
  
```  
class CTabbedPane : public CBaseTabbedPane  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|`CTabbedPane::CTabbedPane`|Construtor padrão.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CTabbedPane::DetachPane](../Topic/CTabbedPane::DetachPane.md)|\(Substitui [CBaseTabbedPane::DetachPane](../Topic/CBaseTabbedPane::DetachPane.md).\)|  
|[CTabbedPane::EnableTabAutoColor](../Topic/CTabbedPane::EnableTabAutoColor.md)|Habilita ou desabilita a coloração automática das guias.|  
|[CTabbedPane::FloatTab](../Topic/CTabbedPane::FloatTab.md)|Flutua um painel, mas somente se o painel estiver atualmente em uma guia destacável.  \(Substitui [CBaseTabbedPane::FloatTab](../Topic/CBaseTabbedPane::FloatTab.md).\)|  
|[CTabbedPane::GetTabArea](../Topic/CTabbedPane::GetTabArea.md)|Retorna o tamanho e a posição da área de guia dentro da janela com guias.|  
|[CTabbedPane::GetTabWnd](../Topic/CTabbedPane::GetTabWnd.md)||  
|[CTabbedPane::HasAutoHideMode](../Topic/CTabbedPane::HasAutoHideMode.md)|Determina se o painel com guias pode ser alternado para o modo de ocultar automaticamente.  \(Substitui [CBaseTabbedPane::HasAutoHideMode](../Topic/CBaseTabbedPane::HasAutoHideMode.md).\)|  
|[CTabbedPane::IsTabLocationBottom](../Topic/CTabbedPane::IsTabLocationBottom.md)|Determina se as guias estão localizadas na parte inferior da janela.|  
|[CTabbedPane::ResetTabs](../Topic/CTabbedPane::ResetTabs.md)|Redefine todos os painéis com guias para o estado padrão.|  
|[CTabbedPane::SetTabAutoColors](../Topic/CTabbedPane::SetTabAutoColors.md)|Define uma lista de cores personalizadas que podem ser usados quando o recurso de cor automática está habilitado.|  
  
### Membros de Dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CTabbedPane::m\_bTabsAlwaysTop](../Topic/CTabbedPane::m_bTabsAlwaysTop.md)|O local padrão para as guias no aplicativo.|  
|[CTabbedPane::m\_pTabWndRTC](../Topic/CTabbedPane::m_pTabWndRTC.md)|Informações de classe de tempo de execução para um personalizado `CMFCTabCtrl`\-objeto derivado.|  
  
## Comentários  
 O framework cria automaticamente uma instância dessa classe quando um usuário anexar um painel para outro, apontando para a legenda do segundo painel.  Todos os painéis com guias que são criados pelo framework têm uma ID de \-1.  
  
 Para especificar guias normais, em vez de guias de estilo do Outlook, passe o `AFX_CBRS_REGULAR_TABS` de estilo para o [CDockablePane::CreateEx](../Topic/CDockablePane::CreateEx.md) método.  
  
 Se você criar um painel com guias com guias removíveis, o painel pode ser destruído automaticamente pela estrutura, para que você não deve armazenar o ponteiro.  Para obter um ponteiro para o painel com guias, chamar o `CBasePane::GetParentTabbedPane` método.  
  
## Exemplo  
 Neste exemplo, podemos criar um `CTabbedPane` objeto.  Em seguida, usamos [CBaseTabbedPane::AddTab](../Topic/CBaseTabbedPane::AddTab.md) anexar guias adicionais.  
  
```  
CTabbedPane* pTabbededBar = new CTabbedPane (TRUE);  
if (!pTabbededBar->Create (_T(""), this, CRect (0, 0, 200, 200),  
                           TRUE,   
                           (UINT) -1,  
                           WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |  
                           WS_CLIPCHILDREN | CBRS_LEFT |    
                           CBRS_FLOAT_MULTI))  
{  
    TRACE0("Failed to create Solution Explorer bar\n");  
    return FALSE;      // fail to create  
}  
  
pTabbededBar->AddTab (&m_wndClassView);  
pTabbededBar->AddTab (&m_wndResourceView);  
pTabbededBar->AddTab (&m_wndFileView);  
pTabbededBar->EnableDocking(CBRS_ALIGN_ANY);  
DockPane(pTabbededBar);  
```  
  
## Exemplo  
 Outra maneira de criar um objeto de barra de controle com guias é usar [CDockablePane::AttachToTabWnd](../Topic/CDockablePane::AttachToTabWnd.md).  O `AttachToTabWnd` método cria dinamicamente um objeto de painel com guias usando informações de classe de tempo de execução definidas por [CDockablePane::SetTabbedPaneRTC](../Topic/CDockablePane::SetTabbedPaneRTC.md).  
  
 Neste exemplo, podemos criar um painel com guias dinamicamente, anexar duas guias e tornar a segunda guia não removível.  
  
```  
DockPane(&m_wndClassView);  
CTabbedPane* pTabbedBar = NULL;  
m_wndResourceView.AttachToTabWnd (&m_wndClassView, DM_SHOW, TRUE,  
                                  (CDockablePane**) &pTabbedBar);  
m_wndFileView.AttachToTabWnd (pTabbedBar, DM_SHOW, TRUE,  
                              (CDockablePane**) &pTabbedBar);  
pTabbedBar->GetUnderlyingWindow ()->EnableTabDetach (1, FALSE);  
```  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CDockablePane](../Topic/CDockablePane%20Class.md)  
  
 [CBaseTabbedPane](../../mfc/reference/cbasetabbedpane-class.md)  
  
 [CTabbedPane](../../mfc/reference/ctabbedpane-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxTabbedPane.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CDockablePane](../Topic/CDockablePane%20Class.md)   
 [Classe CBaseTabbedPane](../../mfc/reference/cbasetabbedpane-class.md)   
 [Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)