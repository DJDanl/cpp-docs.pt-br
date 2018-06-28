---
title: Classe CMFCOutlookBar | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCOutlookBar
- AFXOUTLOOKBAR/CMFCOutlookBar
- AFXOUTLOOKBAR/CMFCOutlookBar::AllowDestroyEmptyTabbedPane
- AFXOUTLOOKBAR/CMFCOutlookBar::CanAcceptPane
- AFXOUTLOOKBAR/CMFCOutlookBar::CanSetCaptionTextToTabName
- AFXOUTLOOKBAR/CMFCOutlookBar::Create
- AFXOUTLOOKBAR/CMFCOutlookBar::CreateCustomPage
- AFXOUTLOOKBAR/CMFCOutlookBar::DoesAllowDynInsertBefore
- AFXOUTLOOKBAR/CMFCOutlookBar::FloatTab
- AFXOUTLOOKBAR/CMFCOutlookBar::GetButtonsFont
- AFXOUTLOOKBAR/CMFCOutlookBar::GetTabArea
- AFXOUTLOOKBAR/CMFCOutlookBar::IsMode2003
- AFXOUTLOOKBAR/CMFCOutlookBar::OnAfterAnimation
- AFXOUTLOOKBAR/CMFCOutlookBar::OnBeforeAnimation
- AFXOUTLOOKBAR/CMFCOutlookBar::OnScroll
- AFXOUTLOOKBAR/CMFCOutlookBar::RemoveCustomPage
- AFXOUTLOOKBAR/CMFCOutlookBar::SetButtonsFont
- AFXOUTLOOKBAR/CMFCOutlookBar::SetMode2003
dev_langs:
- C++
helpviewer_keywords:
- CMFCOutlookBar [MFC], AllowDestroyEmptyTabbedPane
- CMFCOutlookBar [MFC], CanAcceptPane
- CMFCOutlookBar [MFC], CanSetCaptionTextToTabName
- CMFCOutlookBar [MFC], Create
- CMFCOutlookBar [MFC], CreateCustomPage
- CMFCOutlookBar [MFC], DoesAllowDynInsertBefore
- CMFCOutlookBar [MFC], FloatTab
- CMFCOutlookBar [MFC], GetButtonsFont
- CMFCOutlookBar [MFC], GetTabArea
- CMFCOutlookBar [MFC], IsMode2003
- CMFCOutlookBar [MFC], OnAfterAnimation
- CMFCOutlookBar [MFC], OnBeforeAnimation
- CMFCOutlookBar [MFC], OnScroll
- CMFCOutlookBar [MFC], RemoveCustomPage
- CMFCOutlookBar [MFC], SetButtonsFont
- CMFCOutlookBar [MFC], SetMode2003
ms.assetid: 2b335f71-ce99-4efd-b103-e65ba43ffc36
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 935728856a00a27afa1f386f493832ddb955538b
ms.sourcegitcommit: f1b051abb1de3fe96350be0563aaf4e960da13c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/27/2018
ms.locfileid: "37040994"
---
# <a name="cmfcoutlookbar-class"></a>Classe CMFCOutlookBar
Um painel com guias com a aparência visual do **painel de navegação** no Microsoft Outlook 2000 ou Outlook 2003. O `CMFCOutlookBar` objeto contém um [CMFCOutlookBarTabCtrl classe](../../mfc/reference/cmfcoutlookbartabctrl-class.md) objeto e uma série de guias. As guias podem ser [CMFCOutlookBarPane classe](../../mfc/reference/cmfcoutlookbarpane-class.md) objetos ou `CWnd`-objetos derivados. Para o usuário, a barra do Outlook aparece como uma série de botões e uma área de exibição. Quando o usuário clica em um botão, o painel de botão ou controle correspondente é exibida.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCOutlookBar : public CBaseTabbedPane  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCOutlookBar::CMFCOutlookBar`|Construtor padrão.|  
|`CMFCOutlookBar::~CMFCOutlookBar`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCOutlookBar::AllowDestroyEmptyTabbedPane](#allowdestroyemptytabbedpane)|Especifica se um painel com guias vazio pode ser destruído. (Substitui [CBaseTabbedPane::AllowDestroyEmptyTabbedPane](../../mfc/reference/cbasetabbedpane-class.md#allowdestroyemptytabbedpane).)|  
|[CMFCOutlookBar::CanAcceptPane](#canacceptpane)|Determina se o outro painel pode ser encaixado para o painel da barra do Outlook. (Substitui CDockablePane::CanAcceptPane).|  
|[CMFCOutlookBar::CanSetCaptionTextToTabName](#cansetcaptiontexttotabname)|Determina se a legenda para o painel com guias exibirá o mesmo texto como a guia ativa. (Substitui [CBaseTabbedPane::CanSetCaptionTextToTabName](../../mfc/reference/cbasetabbedpane-class.md#cansetcaptiontexttotabname).)|  
|[CMFCOutlookBar::Create](#create)|Cria o controle de barra do Outlook.|  
|[CMFCOutlookBar::CreateCustomPage](#createcustompage)|Cria uma guia personalizada de barra do Outlook.|  
|`CMFCOutlookBar::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|  
|[CMFCOutlookBar::DoesAllowDynInsertBefore](#doesallowdyninsertbefore)|Determina se um usuário pode encaixar uma barra de controle na borda externa da barra do Outlook.|  
|[CMFCOutlookBar::FloatTab](#floattab)|Flutua um painel, mas apenas se o painel estiver atualmente em uma guia destacáveis. (Substitui [CBaseTabbedPane::FloatTab](../../mfc/reference/cbasetabbedpane-class.md#floattab).)|  
|[CMFCOutlookBar::GetButtonsFont](#getbuttonsfont)|Retorna a fonte do texto nos botões da barra do Outlook.|  
|[CMFCOutlookBar::GetTabArea](#gettabarea)|Retorna o tamanho e a posição das áreas de guia na barra do Outlook. (Substitui [CBaseTabbedPane::GetTabArea](../../mfc/reference/cbasetabbedpane-class.md#gettabarea).)|  
|`CMFCOutlookBar::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|[CMFCOutlookBar::IsMode2003](#ismode2003)|Determina se o comportamento da barra do Outlook imita do Microsoft Office Outlook 2003 (consulte comentários).|  
|[CMFCOutlookBar::OnAfterAnimation](#onafteranimation)|Chamado pelo [CMFCOutlookBarTabCtrl::SetActiveTab](../../mfc/reference/cmfcoutlookbartabctrl-class.md#setactivetab) depois que a guia ativa foi definida usando a animação.|  
|[CMFCOutlookBar::OnBeforeAnimation](#onbeforeanimation)|Chamado pelo [CMFCOutlookBarTabCtrl::SetActiveTab](../../mfc/reference/cmfcoutlookbartabctrl-class.md#setactivetab) antes de uma guia é definida como a guia ativa usando a animação.|  
|[CMFCOutlookBar::OnScroll](#onscroll)|Chamado pelo framework se a barra do Outlook é rolar para cima ou para baixo.|  
|[CMFCOutlookBar::RemoveCustomPage](#removecustompage)|Remove uma guia personalizada de barra do Outlook.|  
|[CMFCOutlookBar::SetButtonsFont](#setbuttonsfont)|Define a fonte do texto nos botões da barra do Outlook.|  
|[CMFCOutlookBar::SetMode2003](#setmode2003)|Especifica se o comportamento da barra do Outlook imita do Outlook 2003 (consulte comentários).|  
  
## <a name="remarks"></a>Comentários  
 Para obter um exemplo de uma barra do Outlook, consulte o [OutlookDemo exemplo: aplicativo do MFC OutlookDemo](../../visual-cpp-samples.md).  
  
## <a name="implementing-the-outlook-bar"></a>Implementando a barra do Outlook  
 Para usar o `CMFCOutlookBar` controlar em seu aplicativo, siga estas etapas:  
  
1.  Inserir uma `CMFCOutlookBar` o objeto para a classe de janela do quadro principal.  
  
 ```  
    class CMainFrame : public CMDIFrameWnd  
 { ...  
    CMFCOutlookBar m_wndOutlookBar;  
    CMFCOutlookBarPane m_wndOutlookPane;  
 ... };  
 ```  
2.  Ao processar a mensagem WM_CREATE no quadro principal, chame o [CMFCOutlookBar::Create](#create) método para criar o controle de guia da barra do Outlook.  
  
 ```  
    m_wndOutlookBar.Create (_T("Shortcuts"),
    this,
    CRect (0,
    0,
    100,
    100),
    ID_VIEW_OUTLOOKBAR,
    WS_CHILD | WS_VISIBLE | CBRS_LEFT);

 ```  
3.  Obter um ponteiro para subjacente `CMFCOutlookBarTabCtrl` usando [CBaseTabbedPane::GetUnderlyingWindow](../../mfc/reference/cbasetabbedpane-class.md#getunderlyingwindow).  
  
 ```  
    CMFCOutlookBarTabCtrl* pOutlookBar = (CMFCOutlookBarTabCtrl*) m_wndOutlookBar.GetUnderlyingWindow ();

 ```  
4.  Criar um [CMFCOutlookBarPane classe](../../mfc/reference/cmfcoutlookbarpane-class.md) objeto para cada guia que contém botões.  
  
 ```  
    m_wndOutlookPane.Create (&m_wndOutlookBar,
    AFX_DEFAULT_TOOLBAR_STYLE,
    ID_OUTLOOK_PANE_GENERAL,
    AFX_CBRS_FLOAT | AFX_CBRS_RESIZE);
*// make the Outlook pane detachable (enable docking)  
    m_wndOutlookPane.EnableDocking (CBRS_ALIGN_ANY);
*// add buttons  
    m_wndOutlookPane.AddButton (theApp.LoadIcon (IDR_MAINFRAME), "About",
    ID_APP_ABOUT);

    m_wndOutlookPane.AddButton (theApp.LoadIcon (IDR_CUSTOM_OPEN_ICON), "Open",
    ID_FILE_OPEN);

 ```  
5.  Chamar [CMFCOutlookBarTabCtrl::AddTab](../../mfc/reference/cmfcbasetabctrl-class.md#addtab) para adicionar cada nova guia. Definir o *bDetachable* parâmetro `FALSE` para tornar uma página não removível. Ou use [CMFCOutlookBarTabCtrl::AddControl](../../mfc/reference/cmfcoutlookbartabctrl-class.md#addcontrol) adicionar destacáveis páginas.  
  
 ```  
    pOutlookBar->AddTab (&m_wndOutlookPane, "General", (UINT) -1,
    TRUE);

 ```  
6.  Para adicionar um `CWnd`-controle derivado (por exemplo, [CMFCShellTreeCtrl classe](../../mfc/reference/cmfcshelltreectrl-class.md)) como uma guia, criar o controle e a chamada [CMFCOutlookBarTabCtrl::AddTab](../../mfc/reference/cmfcbasetabctrl-class.md#addtab) para adicioná-lo à barra do Outlook.  
  
> [!NOTE]
>  Você deverá usar IDs de controle exclusivo para cada [CMFCOutlookBarPane classe](../../mfc/reference/cmfcoutlookbarpane-class.md) objeto e para cada `CWnd`-objeto derivado.  
  
 Para adicionar ou excluir novas páginas em tempo de execução dinamicamente, use [CMFCOutlookBar::CreateCustomPage](#createcustompage) e [CMFCOutlookBar::RemoveCustomPage](#removecustompage).  
  
## <a name="outlook-2003-mode"></a>Modo do Outlook 2003  
 No modo do Outlook 2003, os botões da guia são posicionados na parte inferior do painel da barra do Outlook. Quando não há espaço suficiente para exibir os botões, eles são exibidos como ícones em uma área como de barra de ferramentas na parte inferior do painel.  
  
 Use [CMFCOutlookBar::SetMode2003](#setmode2003) para habilitar o modo do Outlook 2003. Use [CMFCOutlookBarTabCtrl::SetToolbarImageList](../../mfc/reference/cmfcoutlookbartabctrl-class.md#settoolbarimagelist) para definir o bitmap que contém os ícones que são exibidos na parte inferior da barra do Outlook. Os ícones no bitmap deverão ser ordenados pelo índice de tabulação.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CDockablePane](../../mfc/reference/cdockablepane-class.md)  
  
 [CBaseTabbedPane](../../mfc/reference/cbasetabbedpane-class.md)  
  
 [CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxoutlookbar.h  
  
##  <a name="allowdestroyemptytabbedpane"></a>  CMFCOutlookBar::AllowDestroyEmptyTabbedPane  
 Especifica se um painel com guias vazio pode ser destruído.  
  
```  
virtual BOOL AllowDestroyEmptyTabbedPane() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se um painel com guias vazio pode ser destruído; Caso contrário, `FALSE`. A implementação padrão sempre retorna `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Se um painel com guias vazio não pode ser destruído, a estrutura oculta em vez disso.  
  
##  <a name="canacceptpane"></a>  CMFCOutlookBar::CanAcceptPane  
 Determina se o outro painel pode ser encaixado para o painel da barra do Outlook.  
  
```  
virtual BOOL CanAcceptPane(const CBasePane* pBar) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pBar*  
 Um ponteiro para outro painel que está sendo encaixada para esse painel.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se outro painel pode ser encaixado painel da barra do Outlook; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Se a barra do Outlook está no modo do Outlook 2003, encaixe não tem suporte, portanto, o valor de retorno é `FALSE`.  
  
 Se o *pBar* parâmetro é `NULL`, esse método retornará `FALSE`.  
  
 Caso contrário, esse método se comporta como o método base [CBasePane::CanAcceptPane](../../mfc/reference/cbasepane-class.md#canacceptpane), exceto que, mesmo se encaixe não estiver habilitado, uma barra do Outlook ainda poderá habilitar outra barra do Outlook para ser encaixado sobre ele.  
  
##  <a name="cansetcaptiontexttotabname"></a>  CMFCOutlookBar::CanSetCaptionTextToTabName  
 Determina se a legenda para o painel com guias exibirá o mesmo texto como a guia ativa.  
  
```  
virtual BOOL CanSetCaptionTextToTabName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o Outlook barra de legenda da janela é definida automaticamente como o texto da guia ativa. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Use [CBaseTabbedPane::EnableSetCaptionTextToTabName](../../mfc/reference/cbasetabbedpane-class.md#enablesetcaptiontexttotabname) para habilitar ou desabilitar essa funcionalidade.  
  
 No modo do Outlook 2003, essa configuração está sempre habilitada.  
  
##  <a name="create"></a>  CMFCOutlookBar::Create  
 Cria o controle de barra do Outlook.  
  
```  
virtual BOOL Create(
    LPCTSTR lpszCaption,  
    CWnd* pParentWnd,  
    const RECT& rect,  
    UINT nID,  
    DWORD dwStyle,  
    DWORD dwControlBarStyle=AFX_CBRS_RESIZE,  
    CCreateContext* pContext=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *lpszCaption*  
 Especifica a legenda da janela.  
  
 [in] *pParentWnd*  
 Especifica um ponteiro para uma janela pai. Ele não deve ser NULL.  
  
 [in] *rect*  
 Especifica o tamanho e a posição em pixels da barra do outlook.  
  
 [in] *nID*  
 Especifica a ID do controle. Deve ser diferente de outro controle IDs usadas no aplicativo.  
  
 [in] *dwStyle*  
 Especifica o estilo de barra de controle desejado. Para obter os valores possíveis, consulte [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles).  
  
 [in] *dwControlBarStyle*  
 Especifica os estilos de definida a biblioteca especiais.  
  
 [in] *pContext*  
 Crie o contexto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você pode criar um `CMFCOutlookBar` objeto em duas etapas. Primeiro, chame o construtor e, em seguida, chamar `Create`, que cria o controle de barra do outlook e anexa-o para o `CMFCOutlookBar` objeto.  
  
 Consulte [CBasePane::CreateEx](../../mfc/reference/cbasepane-class.md#createex) para obter a lista dos estilos definidos de biblioteca disponíveis seja especificada por *dwControlBarStyle*.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `Create` método o `CMFCOutlookBar` classe. Este trecho de código é parte do [exemplo Outlook várias exibições](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_OutlookMultiViews#1](../../mfc/reference/codesnippet/cpp/cmfcoutlookbar-class_1.h)]  
[!code-cpp[NVC_MFC_OutlookMultiViews#2](../../mfc/reference/codesnippet/cpp/cmfcoutlookbar-class_2.cpp)]  
  
##  <a name="createcustompage"></a>  CMFCOutlookBar::CreateCustomPage  
 Cria uma guia personalizada de barra do Outlook.  
  
```  
CMFCOutlookBarPane* CreateCustomPage(
    LPCTSTR lpszPageName,  
    BOOL bActivatePage=TRUE,  
    DWORD dwEnabledDocking=CBRS_ALIGN_ANY,  
    BOOL bEnableTextLabels=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *lpszPageName*  
 O rótulo da página.  
  
 [in] *bActivatePage*  
 Se `TRUE`, a página se torna ativa no momento da criação.  
  
 [in] *dwEnabledDocking*  
 Uma combinação de sinalizadores CBRS_ALIGN_ que especifica os lados de encaixe habilitados quando a página é desanexada.  
  
 [in] *bEnableTextLabels*  
 Se `TRUE`, os rótulos de texto são habilitados para os botões que residem na página.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a página recém-criado, ou `NULL` se a falha na criação.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para permitir que os usuários criem páginas personalizadas de barra do Outlook. Você pode criar até 100 páginas por aplicativo. O controle de página IDs de início de 0xF000. A criação falha se o número total de páginas personalizadas de barra Outlook exceder 100.  
  
 Use [CMFCOutlookBar::RemoveCustomPage](#removecustompage) excluir páginas personalizadas.  
  
##  <a name="doesallowdyninsertbefore"></a>  CMFCOutlookBar::DoesAllowDynInsertBefore  
 Especifica se um usuário pode encaixar um painel da borda externa da barra do Outlook.  
  
```  
DECLARE_MESSAGE_MAP virtual BOOL DoesAllowDynInsertBefore() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A implementação padrão retorna `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama o `DoesAllowDynInsertBefore` método ao procurar um local ancorar um painel dinâmico. Se a função retornar `FALSE`, a estrutura não permite o encaixe de qualquer painel dinâmica nas bordas externas do painel.  
  
 Normalmente, você cria uma barra do Outlook como um controle estático não flutuante. Você pode substituir essa função em uma classe derivada e retornar `TRUE` para alterar esse comportamento.  
  
> [!NOTE]
>  Como painéis dinâmicos verifica o status dos painéis estáticos encaixados quando encaixe, você deve encaixar painéis dinâmicos depois estáticos painéis sempre que possível.  
  
##  <a name="floattab"></a>  CMFCOutlookBar::FloatTab  
 Flutua um painel.  
  
```  
virtual BOOL FloatTab(
    CWnd* pBar,  
    int nTabID,  
    AFX_DOCK_METHOD dockMethod,  
    BOOL bHide);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pBar*  
 Um ponteiro para o painel para float.  
  
 [in] *nTabID*  
 O índice baseado em zero da guia em float.  
  
 [in] *dockMethod*  
 Especifica o método a ser usado para fazer a flutuação do painel.  Para obter mais informações, consulte [CBaseTabbedPane::FloatTab](../../mfc/reference/cbasetabbedpane-class.md#floattab).  
  
 [in] *bHide*  
 `TRUE` Para ocultar o painel antes flutuante; Caso contrário, `FALSE`. Ao contrário da versão da classe base desse método, esse parâmetro não tem um valor padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel flutuante; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método é como [CBaseTabbedPane::FloatTab](../../mfc/reference/cbasetabbedpane-class.md#floattab) exceto que ele não permite que a última guia restante em um controle de barra do Outlook para float.  
  
##  <a name="getbuttonsfont"></a>  CMFCOutlookBar::GetButtonsFont  
 Retorna a fonte do texto na página de guias de botão da barra do Outlook.  
  
```  
CFont* GetButtonsFont() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o objeto de fonte que é usado para exibir texto no Outlook barra guias de botão de página.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para recuperar a fonte usada para exibir o texto nas guias de botão de página do Outlook. Você pode definir a fonte chamando em [CMFCOutlookBar::SetButtonsFont](#setbuttonsfont).  
  
##  <a name="gettabarea"></a>  CMFCOutlookBar::GetTabArea  
 Determina o tamanho e a posição das áreas de guia na barra do Outlook.  
  
```  
virtual void GetTabArea(
    CRect& rectTabAreaTop,  
    CRect& rectTabAreaBottom) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] *rectTabAreaTop*  
 Contém o tamanho e posição (em coordenadas do cliente) da área da guia superior quando a função retorna.  
  
 [out] *rectTabAreaBottom*  
 Contém o tamanho e posição (em coordenadas do cliente) da área da guia inferior quando a função retorna.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para determinar o tipo de encaixe para o painel de destino. Quando a estrutura determina que o usuário arrasta painel encaixado na área do guia do painel de destino, ele tenta adicionar o primeiro painel como uma nova guia do painel de destino. Caso contrário, ele tentará encaixar o painel primeiro em um lado apropriado do painel de destino. A estrutura cria um novo contêiner com um controle deslizante para acomodar o painel encaixado adicional.  
  
 A implementação padrão de `GetTabArea` retorna a área cliente inteiro da barra do Outlook se a barra do Outlook é estático; o que é, se a barra do Outlook não pode flutuar. Caso contrário, ele retorna a área que usam página botões na parte superior e inferior do controle de barra do Outlook.  
  
 Substitua este método na classe derivada de `CMFCOutlookBar` para alterar esse comportamento.  
  
##  <a name="ismode2003"></a>  CMFCOutlookBar::IsMode2003  
 Especifica se o comportamento da barra do Outlook imita do Microsoft Office Outlook 2003.  
  
```  
BOOL IsMode2003() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a barra do Outlook está em execução no modo do Microsoft Office 2003. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você pode habilitar esse modo usando [CMFCOutlookBar::SetMode2003](#setmode2003).  
  
##  <a name="onafteranimation"></a>  CMFCOutlookBar::OnAfterAnimation  
 Chamado pelo [CMFCOutlookBarTabCtrl::SetActiveTab](../../mfc/reference/cmfcoutlookbartabctrl-class.md#setactivetab) depois que a guia ativa foi definida usando a animação.  
  
```  
virtual void OnAfterAnimation(int nPage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *nPage*  
 O índice baseado em zero da página da guia que se tornou ativa.  
  
### <a name="remarks"></a>Comentários  
 O efeito visual de definir a guia ativa depende se você tiver habilitado a animação. Para obter mais informações, consulte [CMFCOutlookBarTabCtrl::EnableAnimation](../../mfc/reference/cmfcoutlookbartabctrl-class.md#enableanimation).  
  
##  <a name="onbeforeanimation"></a>  CMFCOutlookBar::OnBeforeAnimation  
 Chamado pelo [CMFCOutlookBarTabCtrl::SetActiveTab](../../mfc/reference/cmfcoutlookbartabctrl-class.md#setactivetab) antes de uma guia é definida como a guia ativa usando a animação.  
  
```  
virtual BOOL OnBeforeAnimation(int nPage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *nPage*  
 O índice baseado em zero da página da guia está prestes a ser ativada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` se a animação deve ser usada ao configurar a nova guia ativa, ou `FALSE` se a animação deve ser desabilitada.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onscroll"></a>  CMFCOutlookBar::OnScroll  
 Chamado pelo framework se a barra do Outlook é rolar para cima ou para baixo.  
  
```  
virtual void OnScroll(BOOL bDown);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bDown*  
 `TRUE` Se a barra do Outlook está rolando para baixo, ou `FALSE` se ele é rolagem para cima.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="removecustompage"></a>  CMFCOutlookBar::RemoveCustomPage  
 Remove uma página de guia de barra personalizada do Outlook.  
  
```  
BOOL RemoveCustomPage(
    UINT uiPage,  
    CMFCOutlookBarTabCtrl* pTargetWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *uiPage*  
 Índice de base zero da página na janela pai do Outlook.  
  
 [in] *pTargetWnd*  
 Pointerto a janela pai do Outlook.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a página personalizada foi removida com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para excluir páginas personalizadas. Quando a página é removida sua ID de controle é retornado para o pool de identificações disponíveis.  
  
 Você deve fornecer um ponteiro para [CMFCOutlookBarTabCtrl classe](../../mfc/reference/cmfcoutlookbartabctrl-class.md) do objeto no qual reside a página a ser removido no momento. Observe que um usuário pode mover as páginas destacáveis entre diferentes barras do Outlook, mas as informações sobre uma página personalizada residem no objeto de barra do Outlook para o qual você chamou [CMFCOutlookBar::CreateCustomPage](#createcustompage).  
  
 Use [CBaseTabbedPane::GetUnderlyingWindow](../../mfc/reference/cbasetabbedpane-class.md#getunderlyingwindow) para obter um ponteiro para a janela do Outlook.  
  
##  <a name="setbuttonsfont"></a>  CMFCOutlookBar::SetButtonsFont  
 Define a fonte do texto nos botões da barra do Outlook.  
  
```  
void SetButtonsFont(
    CFont* pFont,  
    BOOL bRedraw=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pFont*  
 Especifica a nova fonte.  
  
 [in] *bRedraw*  
 Se `TRUE`, a barra do Outlook irá redesenhada.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para definir uma fonte para o texto exibido nos botões de página de guia do outlook.  
  
##  <a name="setmode2003"></a>  CMFCOutlookBar::SetMode2003  
 Especifica se o comportamento da barra do Outlook imita do Outlook 2003.  
  
```  
void SetMode2003(BOOL bMode2003=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bMode2003*  
 Se for TRUE, o modo do Office 2003 está habilitado.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para habilitar ou desabilitar o modo do Office 2003. Nesse modo, a barra do Outlook tem uma barra de ferramentas adicional com um botão de personalização. O comportamento da barra do Outlook está de acordo com o comportamento da barra do Outlook do Microsoft Office 2003.  
  
 Por padrão, esse modo está desativado.  
  
> [!NOTE]
>  Essa função deve ser chamada antes de [CMFCOutlookBar::Create](#create).  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CBaseTabbedPane](../../mfc/reference/cbasetabbedpane-class.md)   
 [Classe CMFCOutlookBarTabCtrl](../../mfc/reference/cmfcoutlookbartabctrl-class.md)   
 [Classe CMFCOutlookBarPane](../../mfc/reference/cmfcoutlookbarpane-class.md)
