---
title: "Classe CMFCOutlookBar | Microsoft Docs"
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
  - "CMFCOutlookBar"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CMFCOutlookBar"
ms.assetid: 2b335f71-ce99-4efd-b103-e65ba43ffc36
caps.latest.revision: 34
caps.handback.revision: 23
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CMFCOutlookBar
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um painel com guias com a aparência visual de **Painel de Navegação** no Microsoft Outlook 2000 ou no Outlook 2003.  O objeto de `CMFCOutlookBar` contém um objeto de [Classe de CMFCOutlookBarTabCtrl](../../mfc/reference/cmfcoutlookbartabctrl-class.md) e uma série de guias.  As guias podem ser objetos de [Classe de CMFCOutlookBarPane](../../mfc/reference/cmfcoutlookbarpane-class.md) ou `CWnd`de objetos derivados.  Para o usuário, a barra do Outlook aparece como uma série de botões e uma área de exibição.  Quando o usuário clica em um botão, o painel de controle correspondente ou do botão é exibido.  
  
## Sintaxe  
  
```  
class CMFCOutlookBar : public CBaseTabbedPane  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCOutlookBar::CMFCOutlookBar`|Construtor padrão.|  
|`CMFCOutlookBar::~CMFCOutlookBar`|Destruidor.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCOutlookBar::AllowDestroyEmptyTabbedPane](../Topic/CMFCOutlookBar::AllowDestroyEmptyTabbedPane.md)|Especifica se um painel com guias vazio pode ser destruído.  Overrides \( [CBaseTabbedPane::AllowDestroyEmptyTabbedPane](../Topic/CBaseTabbedPane::AllowDestroyEmptyTabbedPane.md).\)|  
|[CMFCOutlookBar::CanAcceptPane](../Topic/CMFCOutlookBar::CanAcceptPane.md)|Determina se outro painel puder ser encaixado no painel da barra do Outlook.  Overrides \(CDockablePane::CanAcceptPane.\)|  
|[CMFCOutlookBar::CanSetCaptionTextToTabName](../Topic/CMFCOutlookBar::CanSetCaptionTextToTabName.md)|Determina se a legenda para o painel com guias exibe o mesmo texto que a ativo.  Overrides \( [CBaseTabbedPane::CanSetCaptionTextToTabName](../Topic/CBaseTabbedPane::CanSetCaptionTextToTabName.md).\)|  
|[CMFCOutlookBar::Create](../Topic/CMFCOutlookBar::Create.md)|Cria o controle de barra do Outlook.|  
|[CMFCOutlookBar::CreateCustomPage](../Topic/CMFCOutlookBar::CreateCustomPage.md)|Cria um guia da barra do Outlook personalizado.|  
|`CMFCOutlookBar::CreateObject`|Usado pela estrutura dinâmica para criar uma instância desse tipo da classe.|  
|[CMFCOutlookBar::DoesAllowDynInsertBefore](../Topic/CMFCOutlookBar::DoesAllowDynInsertBefore.md)|Determina se um usuário pode inserir uma barra de controle na borda externa da barra do Outlook.|  
|[CMFCOutlookBar::FloatTab](../Topic/CMFCOutlookBar::FloatTab.md)|Flutua um painel, mas somente se o painel está atualmente em uma guia destacável.  Overrides \( [CBaseTabbedPane::FloatTab](../Topic/CBaseTabbedPane::FloatTab.md).\)|  
|[CMFCOutlookBar::GetButtonsFont](../Topic/CMFCOutlookBar::GetButtonsFont.md)|Retorna a fonte do texto nos botões da barra do Outlook.|  
|[CMFCOutlookBar::GetTabArea](../Topic/CMFCOutlookBar::GetTabArea.md)|Retorna o tamanho e a posição das áreas da guia na barra do Outlook.  Overrides \( [CBaseTabbedPane::GetTabArea](../Topic/CBaseTabbedPane::GetTabArea.md).\)|  
|`CMFCOutlookBar::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto de [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) que está associado com esse tipo da classe.|  
|[CMFCOutlookBar::IsMode2003](../Topic/CMFCOutlookBar::IsMode2003.md)|Determina se o comportamento de mostrado na barra do Outlook do Microsoft Office Outlook 2003 \(consulte comentários.\)|  
|[CMFCOutlookBar::OnAfterAnimation](../Topic/CMFCOutlookBar::OnAfterAnimation.md)|Chamado por [CMFCOutlookBarTabCtrl::SetActiveTab](../Topic/CMFCOutlookBarTabCtrl::SetActiveTab.md) após a guia ativa foi definido usando a animação.|  
|[CMFCOutlookBar::OnBeforeAnimation](../Topic/CMFCOutlookBar::OnBeforeAnimation.md)|Chamado por [CMFCOutlookBarTabCtrl::SetActiveTab](../Topic/CMFCOutlookBarTabCtrl::SetActiveTab.md) antes de uma guia é definida como a guia ativa que usa a animação.|  
|[CMFCOutlookBar::OnScroll](../Topic/CMFCOutlookBar::OnScroll.md)|Chamado pela estrutura se a barra do Outlook estiver enrolando para cima ou para baixo.|  
|[CMFCOutlookBar::RemoveCustomPage](../Topic/CMFCOutlookBar::RemoveCustomPage.md)|Remove um guia da barra do Outlook personalizado.|  
|[CMFCOutlookBar::SetButtonsFont](../Topic/CMFCOutlookBar::SetButtonsFont.md)|Define a fonte do texto nos botões da barra do Outlook.|  
|[CMFCOutlookBar::SetMode2003](../Topic/CMFCOutlookBar::SetMode2003.md)|Especifica se o comportamento de mostrado na barra do Outlook do Outlook 2003 \(consulte comentários.\)|  
  
## Comentários  
 Para um exemplo de uma barra do Outlook, consulte [Exemplo de OutlookDemo: Aplicativo MFC OutlookDemo](../../top/visual-cpp-samples.md).  
  
## Implementando a barra do Outlook  
 Para usar `CMFCOutlookBar` controle em seu aplicativo, siga estas etapas:  
  
1.  Inserir um objeto de `CMFCOutlookBar` na classe de janela do quadro chave.  
  
    ```  
    class CMainFrame : public CMDIFrameWnd  
     { ...  
         CMFCOutlookBar         m_wndOutlookBar;  
         CMFCOutlookBarPane     m_wndOutlookPane;  
    ... };  
    ```  
  
2.  Ao processar a mensagem de `WM_CREATE` no quadro chave, chame o método de [CMFCOutlookBar::Create](../Topic/CMFCOutlookBar::Create.md) para criar o controle da guia da barra do Outlook.  
  
    ```  
    m_wndOutlookBar.Create (_T("Shortcuts"), this, CRect (0, 0, 100, 100), ID_VIEW_OUTLOOKBAR, WS_CHILD | WS_VISIBLE | CBRS_LEFT);  
    ```  
  
3.  Obtenha um ponteiro para `CMFCOutlookBarTabCtrl` subjacente usando [CBaseTabbedPane::GetUnderlyingWindow](../Topic/CBaseTabbedPane::GetUnderlyingWindow.md).  
  
    ```  
    CMFCOutlookBarTabCtrl* pOutlookBar = (CMFCOutlookBarTabCtrl*) m_wndOutlookBar.GetUnderlyingWindow ();  
    ```  
  
4.  Crie um objeto de [Classe de CMFCOutlookBarPane](../../mfc/reference/cmfcoutlookbarpane-class.md) para cada guia que contém botões.  
  
    ```  
    m_wndOutlookPane.Create (&m_wndOutlookBar, AFX_DEFAULT_TOOLBAR_STYLE, ID_OUTLOOK_PANE_GENERAL, AFX_CBRS_FLOAT | AFX_CBRS_RESIZE);  
    // make the Outlook pane detachable (enable docking)  
    m_wndOutlookPane.EnableDocking (CBRS_ALIGN_ANY);  
    // add buttons  
    m_wndOutlookPane.AddButton (theApp.LoadIcon (IDR_MAINFRAME), "About", ID_APP_ABOUT);  
    m_wndOutlookPane.AddButton (theApp.LoadIcon (IDR_CUSTOM_OPEN_ICON), "Open", ID_FILE_OPEN);  
    ```  
  
5.  Chame [CMFCBaseTabCtrl::AddTab](../Topic/CMFCBaseTabCtrl::AddTab.md) para adicionar cada nova guia.  Defina o parâmetro de `bDetachable` a `FALSE` para fazer uma página não destacável.  Ou, use [CMFCOutlookBarTabCtrl::AddControl](../Topic/CMFCOutlookBarTabCtrl::AddControl.md) adicionar páginas destacáveis.  
  
    ```  
    pOutlookBar->AddTab (&m_wndOutlookPane, "General", (UINT) -1, TRUE);   
    ```  
  
6.  Para adicionar `CWnd`\- o controle derivado \(por exemplo, [Classe de CMFCShellTreeCtrl](../../mfc/reference/cmfcshelltreectrl-class.md)\) como um guia, cria o controle e a chamada [CMFCBaseTabCtrl::AddTab](../Topic/CMFCBaseTabCtrl::AddTab.md) para adicioná\-lo à barra do Outlook.  
  
> [!NOTE]
>  Você deve usar identificações exclusivas de controle para cada objeto de [Classe de CMFCOutlookBarPane](../../mfc/reference/cmfcoutlookbarpane-class.md) e para cada `CWnd`objeto derivado de.  
  
 Para adicionar ou excluir dinamicamente novas páginas em tempo de execução, em uso [CMFCOutlookBar::CreateCustomPage](../Topic/CMFCOutlookBar::CreateCustomPage.md) e em [CMFCOutlookBar::RemoveCustomPage](../Topic/CMFCOutlookBar::RemoveCustomPage.md).  
  
## Modo do Outlook 2003  
 No modo do Outlook 2003, os botões são posicionados na guia na parte inferior do painel da barra do Outlook.  Quando não há espaço suficiente uma exibir botões, são exibidos como ícones na barra de ferramentas\- como a área na parte inferior do painel.  
  
 Use [CMFCOutlookBar::SetMode2003](../Topic/CMFCOutlookBar::SetMode2003.md) para ativar o modo do Outlook 2003.  Use [CMFCOutlookBarTabCtrl::SetToolbarImageList](../Topic/CMFCOutlookBarTabCtrl::SetToolbarImageList.md) para definir o bitmap que contém os ícones que são exibidos na parte inferior da barra do Outlook.  Ícones no bitmap devem ser ordenados pelo índice de tabulação.  
  
## Hierarquia de Herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CDockablePane](../Topic/CDockablePane%20Class.md)  
  
 [CBaseTabbedPane](../../mfc/reference/cbasetabbedpane-class.md)  
  
 [CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxoutlookbar.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe CBaseTabbedPane](../../mfc/reference/cbasetabbedpane-class.md)   
 [Classe de CMFCOutlookBarTabCtrl](../../mfc/reference/cmfcoutlookbartabctrl-class.md)   
 [Classe de CMFCOutlookBarPane](../../mfc/reference/cmfcoutlookbarpane-class.md)