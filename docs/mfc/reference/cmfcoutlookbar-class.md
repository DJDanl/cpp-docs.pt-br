---
title: Classe CMFCOutlookBar | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCOutlookBar
dev_langs:
- C++
helpviewer_keywords:
- CMFCOutlookBar class
ms.assetid: 2b335f71-ce99-4efd-b103-e65ba43ffc36
caps.latest.revision: 34
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: ff58cf786e4979d64aa2b5d7ad4d1a32b96bec3d
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcoutlookbar-class"></a>Classe CMFCOutlookBar
Um painel com guias com a aparência visual do **painel de navegação** no Microsoft Outlook 2000 ou Outlook 2003. O `CMFCOutlookBar` objeto contém um [CMFCOutlookBarTabCtrl classe](../../mfc/reference/cmfcoutlookbartabctrl-class.md) objeto e uma série de guias. As guias podem ser [CMFCOutlookBarPane classe](../../mfc/reference/cmfcoutlookbarpane-class.md) objetos ou `CWnd`-objetos derivados. Para o usuário, a barra do Outlook aparece como uma série de botões e uma área de exibição. Quando o usuário clica em um botão, o painel de botão ou controle correspondente é exibida.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCOutlookBar : public CBaseTabbedPane  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCOutlookBar::CMFCOutlookBar`|Construtor padrão.|  
|`CMFCOutlookBar::~CMFCOutlookBar`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCOutlookBar::AllowDestroyEmptyTabbedPane](#allowdestroyemptytabbedpane)|Especifica se um painel com guias vazia pode ser destruído. (Substitui [CBaseTabbedPane::AllowDestroyEmptyTabbedPane](../../mfc/reference/cbasetabbedpane-class.md#allowdestroyemptytabbedpane).)|  
|[CMFCOutlookBar::CanAcceptPane](#canacceptpane)|Determina se outro painel pode ser encaixado ao painel da barra do Outlook. (Substitui o CDockablePane::CanAcceptPane).|  
|[CMFCOutlookBar::CanSetCaptionTextToTabName](#cansetcaptiontexttotabname)|Determina se a legenda para o painel com guias exibirá o mesmo texto como a guia ativa. (Substitui [CBaseTabbedPane::CanSetCaptionTextToTabName](../../mfc/reference/cbasetabbedpane-class.md#cansetcaptiontexttotabname).)|  
|[CMFCOutlookBar::Create](#create)|Cria o controle de barra do Outlook.|  
|[CMFCOutlookBar::CreateCustomPage](#createcustompage)|Cria uma guia personalizada de barra do Outlook.|  
|`CMFCOutlookBar::CreateObject`|Usado pelo framework para criar uma instância desse tipo de classe dinâmica.|  
|[CMFCOutlookBar::DoesAllowDynInsertBefore](#doesallowdyninsertbefore)|Determina se um usuário pode encaixar uma barra de controle na borda externa da barra do Outlook.|  
|[CMFCOutlookBar::FloatTab](#floattab)|Flutua um painel, mas apenas se o painel estiver atualmente em uma guia destacáveis. (Substitui [CBaseTabbedPane::FloatTab](../../mfc/reference/cbasetabbedpane-class.md#floattab).)|  
|[CMFCOutlookBar::GetButtonsFont](#getbuttonsfont)|Retorna a fonte do texto nos botões da barra de tarefas do Outlook.|  
|[CMFCOutlookBar::GetTabArea](#gettabarea)|Retorna o tamanho e a posição das áreas de guia na barra do Outlook. (Substitui [CBaseTabbedPane::GetTabArea](../../mfc/reference/cbasetabbedpane-class.md#gettabarea).)|  
|`CMFCOutlookBar::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|[CMFCOutlookBar::IsMode2003](#ismode2003)|Determina se o comportamento da barra do Outlook imita do Microsoft Office Outlook 2003 (consulte comentários).|  
|[CMFCOutlookBar::OnAfterAnimation](#onafteranimation)|Chamado por [CMFCOutlookBarTabCtrl::SetActiveTab](../../mfc/reference/cmfcoutlookbartabctrl-class.md#setactivetab) depois que a guia ativa foi definida através de animação.|  
|[CMFCOutlookBar::OnBeforeAnimation](#onbeforeanimation)|Chamado por [CMFCOutlookBarTabCtrl::SetActiveTab](../../mfc/reference/cmfcoutlookbartabctrl-class.md#setactivetab) antes de uma guia é definida como a guia ativa usando a animação.|  
|[CMFCOutlookBar::OnScroll](#onscroll)|Chamado pela estrutura se a barra do Outlook é rolar para cima ou para baixo.|  
|[CMFCOutlookBar::RemoveCustomPage](#removecustompage)|Remove uma guia personalizada de barra do Outlook.|  
|[CMFCOutlookBar::SetButtonsFont](#setbuttonsfont)|Define a fonte do texto nos botões da barra de tarefas do Outlook.|  
|[CMFCOutlookBar::SetMode2003](#setmode2003)|Especifica se o comportamento da barra do Outlook imita do Outlook 2003 (consulte comentários).|  
  
## <a name="remarks"></a>Comentários  
 Para obter um exemplo de uma barra do Outlook, consulte o [OutlookDemo exemplo: aplicativo do MFC OutlookDemo](../../visual-cpp-samples.md).  
  
## <a name="implementing-the-outlook-bar"></a>Implementando a barra do Outlook  
 Para usar o `CMFCOutlookBar` de controle em seu aplicativo, siga estas etapas:  
  
1.  Inserir uma `CMFCOutlookBar` o objeto para a classe de janela do quadro principal.  
  
 ```  
    class CMainFrame : public CMDIFrameWnd  
 { ...  
    CMFCOutlookBar m_wndOutlookBar;  
    CMFCOutlookBarPane m_wndOutlookPane;  
 ... };  
 ```  
2.  Ao processar o `WM_CREATE` mensagem no quadro principal, chamada de [CMFCOutlookBar::Create](#create) método para criar o controle de guia da barra do Outlook.  
  
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
5.  Chamar [CMFCOutlookBarTabCtrl::AddTab](../../mfc/reference/cmfcbasetabctrl-class.md#addtab) para adicionar cada nova guia. Definir o `bDetachable` parâmetro `FALSE` para fazer com que uma página não removível. Ou use [CMFCOutlookBarTabCtrl::AddControl](../../mfc/reference/cmfcoutlookbartabctrl-class.md#addcontrol) para adicionar páginas destacáveis.  
  
 ```  
    pOutlookBar->AddTab (&m_wndOutlookPane, "General", (UINT) -1,
    TRUE);

 ```  
6.  Para adicionar um `CWnd`-controle derivado (por exemplo, [CMFCShellTreeCtrl classe](../../mfc/reference/cmfcshelltreectrl-class.md)) como uma guia, criar o controle e a chamada [CMFCOutlookBarTabCtrl::AddTab](../../mfc/reference/cmfcbasetabctrl-class.md#addtab) para adicioná-lo à barra do Outlook.  
  
> [!NOTE]
>  Você deve usar IDs de controle exclusivo para cada [CMFCOutlookBarPane classe](../../mfc/reference/cmfcoutlookbarpane-class.md) objeto e para cada `CWnd`-objeto derivado.  
  
 Para adicionar ou excluir novas páginas em tempo de execução dinamicamente, use [CMFCOutlookBar::CreateCustomPage](#createcustompage) e [CMFCOutlookBar::RemoveCustomPage](#removecustompage).  
  
## <a name="outlook-2003-mode"></a>Modo do Outlook 2003  
 No modo do Outlook 2003, os botões da guia são posicionados na parte inferior do painel da barra do Outlook. Quando não há espaço suficiente para exibir os botões, eles são exibidos como ícones em uma área como de barra de ferramentas na parte inferior do painel.  
  
 Use [CMFCOutlookBar::SetMode2003](#setmode2003) para habilitar o modo do Outlook 2003. Use [CMFCOutlookBarTabCtrl::SetToolbarImageList](../../mfc/reference/cmfcoutlookbartabctrl-class.md#settoolbarimagelist) para definir o bitmap que contém os ícones são exibidos na parte inferior da barra do Outlook. Os ícones no bitmap devem ser ordenados por índice de tabulação.  
  
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
  
##  <a name="a-nameallowdestroyemptytabbedpanea--cmfcoutlookbarallowdestroyemptytabbedpane"></a><a name="allowdestroyemptytabbedpane"></a>CMFCOutlookBar::AllowDestroyEmptyTabbedPane  
 Especifica se um painel com guias vazia pode ser destruído.  
  
```  
virtual BOOL AllowDestroyEmptyTabbedPane() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se um painel com guias vazia pode ser destruído; Caso contrário, `FALSE`. A implementação padrão sempre retorna `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Se um painel com guias vazio não pode ser destruído, a estrutura oculta em vez disso.  
  
##  <a name="a-namecanacceptpanea--cmfcoutlookbarcanacceptpane"></a><a name="canacceptpane"></a>CMFCOutlookBar::CanAcceptPane  
 Determina se outro painel pode ser encaixado ao painel da barra do Outlook.  
  
```  
virtual BOOL CanAcceptPane(const CBasePane* pBar) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
 Um ponteiro para outro painel que está sendo encaixado para esse painel.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se outro painel pode ser encaixado ao painel da barra do Outlook; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Se a barra do Outlook está no modo do Outlook 2003, encaixe não é suportado, portanto, o valor de retorno é `FALSE`.  
  
 Se o `pBar` parâmetro é `NULL`, esse método retornará `FALSE`.  
  
 Caso contrário, esse método se comporta como o método base [CBasePane::CanAcceptPane](../../mfc/reference/cbasepane-class.md#canacceptpane), exceto que, mesmo se encaixe não estiver habilitado, uma barra do Outlook pode habilitar ainda outra barra do Outlook para ser encaixado sobre ele.  
  
##  <a name="a-namecansetcaptiontexttotabnamea--cmfcoutlookbarcansetcaptiontexttotabname"></a><a name="cansetcaptiontexttotabname"></a>CMFCOutlookBar::CanSetCaptionTextToTabName  
 Determina se a legenda para o painel com guias exibirá o mesmo texto como a guia ativa.  
  
```  
virtual BOOL CanSetCaptionTextToTabName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a barra de legenda da janela do Outlook é definido automaticamente como o texto da guia ativa; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Use [CBaseTabbedPane::EnableSetCaptionTextToTabName](../../mfc/reference/cbasetabbedpane-class.md#enablesetcaptiontexttotabname) para habilitar ou desabilitar essa funcionalidade.  
  
 No modo do Outlook 2003, essa configuração está sempre habilitada.  
  
##  <a name="a-namecreatea--cmfcoutlookbarcreate"></a><a name="create"></a>CMFCOutlookBar::Create  
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
 [in] `lpszCaption`  
 Especifica a legenda da janela.  
  
 [in] `pParentWnd`  
 Especifica um ponteiro para uma janela pai. Ele não deve ser NULL.  
  
 [in] `rect`  
 Especifica o tamanho e a posição em pixels da barra do outlook.  
  
 [in] `nID`  
 Especifica a ID do controle. Deve ser diferente de outro controle IDs usadas no aplicativo.  
  
 [in] `dwStyle`  
 Especifica o estilo de barra de controle desejado. Para obter valores possíveis, consulte [estilos de janela](../../mfc/reference/window-styles.md).  
  
 [in] `dwControlBarStyle`  
 Especifica os estilos especial definida pela biblioteca.  
  
 [in] `pContext`  
 Crie o contexto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método for bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você construir um `CMFCOutlookBar` objeto em duas etapas. Primeiro chama o construtor e, em seguida, chame `Create`, que cria o controle de barra do outlook e anexa-o para o `CMFCOutlookBar` objeto.  
  
 Consulte [CBasePane::CreateEx](../../mfc/reference/cbasepane-class.md#createex) para obter a lista os estilos disponíveis definida pela biblioteca seja especificada por `dwControlBarStyle`.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `Create` método o `CMFCOutlookBar` classe. Este trecho de código é parte do [exemplo de modos de exibição do Outlook múltiplas](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_OutlookMultiViews n º&1;](../../mfc/reference/codesnippet/cpp/cmfcoutlookbar-class_1.h)]  
[!code-cpp[NVC_MFC_OutlookMultiViews n º&2;](../../mfc/reference/codesnippet/cpp/cmfcoutlookbar-class_2.cpp)]  
  
##  <a name="a-namecreatecustompagea--cmfcoutlookbarcreatecustompage"></a><a name="createcustompage"></a>CMFCOutlookBar::CreateCustomPage  
 Cria uma guia personalizada de barra do Outlook.  
  
```  
CMFCOutlookBarPane* CreateCustomPage(
    LPCTSTR lpszPageName,  
    BOOL bActivatePage=TRUE,  
    DWORD dwEnabledDocking=CBRS_ALIGN_ANY,  
    BOOL bEnableTextLabels=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszPageName`  
 O rótulo da página.  
  
 [in] `bActivatePage`  
 Se `TRUE`, a página se torna ativa no momento da criação.  
  
 [in] `dwEnabledDocking`  
 Uma combinação de sinalizadores CBRS_ALIGN_ que especifica os lados de encaixe habilitados quando a página é desanexada.  
  
 [in] `bEnableTextLabels`  
 Se `TRUE`, as legendas são habilitadas para os botões que residem na página.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a página recém-criada, ou `NULL` se a falha na criação.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para permitir que os usuários criem páginas personalizadas de barra do Outlook. Você pode criar até 100 páginas por aplicativo. O controle de página Iniciar IDs de 0xF000. A criação falhará se o número total de páginas personalizadas de barra Outlook exceder 100.  
  
 Use [CMFCOutlookBar::RemoveCustomPage](#removecustompage) excluir páginas personalizadas.  
  
##  <a name="a-namedoesallowdyninsertbeforea--cmfcoutlookbardoesallowdyninsertbefore"></a><a name="doesallowdyninsertbefore"></a>CMFCOutlookBar::DoesAllowDynInsertBefore  
 Especifica se um usuário pode encaixar um painel da borda externa da barra do Outlook.  
  
```  
DECLARE_MESSAGE_MAP virtual BOOL DoesAllowDynInsertBefore() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a implementação padrão `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama o `DoesAllowDynInsertBefore` método ao procurar um local encaixar um painel dinâmico. Se a função retornar `FALSE`, a estrutura não permite o encaixe de qualquer painel dinâmico nas bordas externas do painel.  
  
 Normalmente, você cria uma barra do Outlook como um controle estático não flutuante. Você pode substituir essa função em uma classe derivada e retornar `TRUE` para alterar esse comportamento.  
  
> [!NOTE]
>  Como painéis dinâmicos verifica o status dos painéis estáticos ancoradas ao encaixe, você deve encaixar painéis dinâmicos depois painéis estáticos sempre que possível.  
  
##  <a name="a-namefloattaba--cmfcoutlookbarfloattab"></a><a name="floattab"></a>CMFCOutlookBar::FloatTab  
 Flutua um painel.  
  
```  
virtual BOOL FloatTab(
    CWnd* pBar,  
    int nTabID,  
    AFX_DOCK_METHOD dockMethod,  
    BOOL bHide);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
 Um ponteiro para o painel para float.  
  
 [in] `nTabID`  
 O índice baseado em zero da guia para float.  
  
 [in] `dockMethod`  
 Especifica o método a ser usado para tornar o float de painel.  Para obter mais informações, consulte [CBaseTabbedPane::FloatTab](../../mfc/reference/cbasetabbedpane-class.md#floattab).  
  
 [in] `bHide`  
 `TRUE`Para ocultar o painel antes de flutuante; Caso contrário, `FALSE`. Diferentemente da versão da classe base desse método, esse parâmetro não tem um valor padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o painel flutuante; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método é como [CBaseTabbedPane::FloatTab](../../mfc/reference/cbasetabbedpane-class.md#floattab) exceto que ele não permite que a última guia restante em um controle de barra do Outlook para float.  
  
##  <a name="a-namegetbuttonsfonta--cmfcoutlookbargetbuttonsfont"></a><a name="getbuttonsfont"></a>CMFCOutlookBar::GetButtonsFont  
 Retorna a fonte do texto na página de guias de botão da barra de tarefas do Outlook.  
  
```  
CFont* GetButtonsFont() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o objeto de fonte que é usado para exibir texto no Outlook barra guias de botão de página.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para recuperar a fonte usada para exibir o texto nas guias de botão de página do Outlook. Você pode definir a fonte chamando em [CMFCOutlookBar::SetButtonsFont](#setbuttonsfont).  
  
##  <a name="a-namegettabareaa--cmfcoutlookbargettabarea"></a><a name="gettabarea"></a>CMFCOutlookBar::GetTabArea  
 Determina o tamanho e a posição das áreas de guia na barra do Outlook.  
  
```  
virtual void GetTabArea(
    CRect& rectTabAreaTop,  
    CRect& rectTabAreaBottom) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `rectTabAreaTop`  
 Contém o tamanho e posição (nas coordenadas do cliente) da área da guia superior quando a função retorna.  
  
 [out] `rectTabAreaBottom`  
 Contém o tamanho e posição (nas coordenadas do cliente) da área da guia inferior quando a função retorna.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para determinar o tipo de encaixe para o painel de destino. Quando a estrutura determina que o usuário arrasta painel encaixado na área do guia do painel de destino, ele tenta adicionar o primeiro painel como uma nova guia do painel de destino. Caso contrário, ele tenta encaixar o painel primeiro em um lado do painel de destino apropriado. O framework cria um novo contêiner com um controle deslizante para acomodar o painel encaixado adicional.  
  
 A implementação padrão de `GetTabArea` retorna a área do cliente inteira da barra do Outlook se a barra do Outlook é estática; que é, se a barra do Outlook não pode flutuar. Caso contrário, ele retorna a área que usam página de botões na parte superior e inferior do controle de barra do Outlook.  
  
 Substituir esse método na classe derivada de `CMFCOutlookBar` para alterar esse comportamento.  
  
##  <a name="a-nameismode2003a--cmfcoutlookbarismode2003"></a><a name="ismode2003"></a>CMFCOutlookBar::IsMode2003  
 Especifica se o comportamento da barra do Outlook imita do Microsoft Office Outlook 2003.  
  
```  
BOOL IsMode2003() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a barra do Outlook está em execução no modo do Microsoft Office 2003. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você pode habilitar esse modo usando [CMFCOutlookBar::SetMode2003](#setmode2003).  
  
##  <a name="a-nameonafteranimationa--cmfcoutlookbaronafteranimation"></a><a name="onafteranimation"></a>CMFCOutlookBar::OnAfterAnimation  
 Chamado por [CMFCOutlookBarTabCtrl::SetActiveTab](../../mfc/reference/cmfcoutlookbartabctrl-class.md#setactivetab) depois que a guia ativa foi definida através de animação.  
  
```  
virtual void OnAfterAnimation(int nPage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nPage`  
 O índice baseado em zero da página da guia se tornou ativa.  
  
### <a name="remarks"></a>Comentários  
 O efeito visual da configuração na guia active depende de você ter habilitado a animação. Para obter mais informações, consulte [CMFCOutlookBarTabCtrl::EnableAnimation](../../mfc/reference/cmfcoutlookbartabctrl-class.md#enableanimation).  
  
##  <a name="a-nameonbeforeanimationa--cmfcoutlookbaronbeforeanimation"></a><a name="onbeforeanimation"></a>CMFCOutlookBar::OnBeforeAnimation  
 Chamado por [CMFCOutlookBarTabCtrl::SetActiveTab](../../mfc/reference/cmfcoutlookbartabctrl-class.md#setactivetab) antes de uma guia é definida como a guia ativa usando a animação.  
  
```  
virtual BOOL OnBeforeAnimation(int nPage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nPage`  
 O índice baseado em zero da página da guia que está prestes a ser ativada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` se a animação deve ser usada na definição de nova guia ativa, ou `FALSE` se a animação deve ser desabilitada.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameonscrolla--cmfcoutlookbaronscroll"></a><a name="onscroll"></a>CMFCOutlookBar::OnScroll  
 Chamado pela estrutura se a barra do Outlook é rolar para cima ou para baixo.  
  
```  
virtual void OnScroll(BOOL bDown);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bDown`  
 `TRUE`Se a barra do Outlook está rolando para baixo, ou `FALSE` se ele está rolando para cima.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameremovecustompagea--cmfcoutlookbarremovecustompage"></a><a name="removecustompage"></a>CMFCOutlookBar::RemoveCustomPage  
 Remove uma página de guia de barra personalizada do Outlook.  
  
```  
BOOL RemoveCustomPage(
    UINT uiPage,  
    CMFCOutlookBarTabCtrl* pTargetWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiPage`  
 Índice baseado em zero da página na janela pai do Outlook.  
  
 [in] `pTargetWnd`  
 Pointerto a janela pai do Outlook.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a página personalizada foi removida com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para excluir páginas personalizadas. Quando a página é removida sua ID do controle é retornado ao pool de identificações disponíveis.  
  
 Você deve fornecer um ponteiro para [CMFCOutlookBarTabCtrl classe](../../mfc/reference/cmfcoutlookbartabctrl-class.md) do objeto no qual reside a página a ser removido no momento. Observe que um usuário pode mover páginas destacáveis entre diferentes barras do Outlook, mas as informações sobre uma página personalizada residem no objeto de barra de Outlook para o qual você chamou [CMFCOutlookBar::CreateCustomPage](#createcustompage).  
  
 Use [CBaseTabbedPane::GetUnderlyingWindow](../../mfc/reference/cbasetabbedpane-class.md#getunderlyingwindow) para obter um ponteiro para a janela do Outlook.  
  
##  <a name="a-namesetbuttonsfonta--cmfcoutlookbarsetbuttonsfont"></a><a name="setbuttonsfont"></a>CMFCOutlookBar::SetButtonsFont  
 Define a fonte do texto nos botões da barra de tarefas do Outlook.  
  
```  
void SetButtonsFont(
    CFont* pFont,  
    BOOL bRedraw=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pFont`  
 Especifica a nova fonte.  
  
 [in] `bRedraw`  
 Se `TRUE`, a barra do Outlook será redesenhada.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para definir uma fonte para o texto exibido nos botões de página de guia do outlook.  
  
##  <a name="a-namesetmode2003a--cmfcoutlookbarsetmode2003"></a><a name="setmode2003"></a>CMFCOutlookBar::SetMode2003  
 Especifica se o comportamento da barra do Outlook imita do Outlook 2003.  
  
```  
void SetMode2003(BOOL bMode2003=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bMode2003`  
 Se for TRUE, o modo do Office 2003 está habilitado.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para habilitar ou desabilitar o modo do Office 2003. Nesse modo, a barra do Outlook tem uma barra de ferramentas adicional com um botão de personalização. O comportamento da barra do Outlook está de acordo com o comportamento da barra do Outlook no Microsoft Office 2003.  
  
 Por padrão, esse modo está desativado.  
  
> [!NOTE]
>  Essa função deve ser chamada antes de [CMFCOutlookBar::Create](#create).  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CBaseTabbedPane](../../mfc/reference/cbasetabbedpane-class.md)   
 [Classe CMFCOutlookBarTabCtrl](../../mfc/reference/cmfcoutlookbartabctrl-class.md)   
 [Classe CMFCOutlookBarPane](../../mfc/reference/cmfcoutlookbarpane-class.md)

