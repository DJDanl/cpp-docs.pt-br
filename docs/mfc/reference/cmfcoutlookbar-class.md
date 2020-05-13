---
title: Classe CMFCOutlookBar
ms.date: 06/25/2018
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
ms.openlocfilehash: fe328cb0d857ff9154624d218b1b56362890ce81
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369648"
---
# <a name="cmfcoutlookbar-class"></a>Classe CMFCOutlookBar

Um painel com a aparência visual do Painel de **Navegação** no Microsoft Outlook 2000 ou outlook 2003. O `CMFCOutlookBar` objeto contém um objeto [CMFCOutlookBarTabCtrl Class](../../mfc/reference/cmfcoutlookbartabctrl-class.md) e uma série de guias. As guias podem ser objetos [cmfcoutlookbarpane class](../../mfc/reference/cmfcoutlookbarpane-class.md) ou `CWnd`objetos derivados. Para o usuário, a barra do Outlook aparece como uma série de botões e uma área de exibição. Quando o usuário clica em um botão, o controle correspondente ou o painel de botão é exibido.

## <a name="syntax"></a>Sintaxe

```cpp
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
|[CMFCOutlookBar::PermitirDestroyEmptyTabbedPane](#allowdestroyemptytabbedpane)|Especifica se um painel vazio pode ser destruído. (Substitui [cbasetabbedPane::PermitirDestroyDestroyEmptyTabbedPane](../../mfc/reference/cbasetabbedpane-class.md#allowdestroyemptytabbedpane).)|
|[CMFCOutlookBar::CanAcceptPane](#canacceptpane)|Determina se outro painel pode ser ancorado no painel da barra do Outlook. (Substitui cdockablepane::CanAcceptPane.)|
|[CMFCOutlookBar::CanSet'SText'S'T'M](#cansetcaptiontexttotabname)|Determina se a legenda do painel com guias exibe o mesmo texto que a guia ativa. (Substitui [cBaseTabbedPane:CanSetCaptionTextToTabName](../../mfc/reference/cbasetabbedpane-class.md#cansetcaptiontexttotabname).)|
|[CMFCOutlookBar::Criar](#create)|Cria o controle de barra do Outlook.|
|[CMFCOutlookBar::CriarcustomPage](#createcustompage)|Cria uma guia de barra do Outlook personalizada.|
|`CMFCOutlookBar::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|[CMFCOutlookBar::DoesAllowDynInsertBefore](#doesallowdyninsertbefore)|Determina se um usuário pode encaixar uma barra de controle na borda externa da barra do Outlook.|
|[CMFCOutlookBar::Floattab](#floattab)|Flutua um painel, mas apenas se o painel atualmente residir em uma guia destacável. (Overrides [CBaseTabbedPane::FloatTab](../../mfc/reference/cbasetabbedpane-class.md#floattab).)|
|[CMFCOutlookBar::GetButtonsFont](#getbuttonsfont)|Retorna a fonte do texto nos botões da barra do Outlook.|
|[CMFCOutlookBar::GetTabArea](#gettabarea)|Retorna o tamanho e a posição das áreas de guia na barra do Outlook. (Substitui [cbasetabbedpane::GetTabArea](../../mfc/reference/cbasetabbedpane-class.md#gettabarea).)|
|`CMFCOutlookBar::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|
|[CMFCOutlookBar::IsMode2003](#ismode2003)|Determina se o comportamento da barra do Outlook imita o do Microsoft Office Outlook 2003 (ver Observações).|
|[CMFCOutlookBar::OnAfterAnimation](#onafteranimation)|Chamado por [CMFCOutlookBarTabCtrl::SetActiveTab](../../mfc/reference/cmfcoutlookbartabctrl-class.md#setactivetab) depois que a guia ativa foi definida usando animação.|
|[CMFCOutlookBar::OnbeforeAnimation](#onbeforeanimation)|Chamado por [CMFCOutlookBarTabCtrl::SetActiveTab](../../mfc/reference/cmfcoutlookbartabctrl-class.md#setactivetab) antes que uma página de guia seja definida como a guia ativa usando animação.|
|[CMFCOutlookBar::OnScroll](#onscroll)|Chamada pela estrutura se a barra do Outlook estiver rolando para cima ou para baixo.|
|[CMFCOutlookBar::RemoveCustomPage](#removecustompage)|Remove uma guia de barra personalizada do Outlook.|
|[CMFCOutlookBar::SetButtonsFont](#setbuttonsfont)|Define a fonte do texto nos botões da barra do Outlook.|
|[CMFCOutlookBar::SetMode2003](#setmode2003)|Especifica se o comportamento da barra do Outlook imita o do Outlook 2003 (ver Observações).|

## <a name="remarks"></a>Comentários

Para um exemplo de barra do Outlook, consulte a amostra do [OutlookDemo: MFC OutlookDemo Application](../../overview/visual-cpp-samples.md).

## <a name="implementing-the-outlook-bar"></a>Implementando a barra do Outlook

Para usar `CMFCOutlookBar` o controle em sua aplicação, siga estas etapas:

1. Incorpore `CMFCOutlookBar` um objeto na classe da janela do quadro principal.

    ```cpp
    class CMainFrame : public CMDIFrameWnd
    {
        // ...
        CMFCOutlookBar m_wndOutlookBar;
        CMFCOutlookBarPane m_wndOutlookPane;
        // ...
    };
    ```

1. Ao processar a mensagem WM_CREATE no quadro principal, chame o método [CMFCOutlookBar::Criar](#create) para criar o controle da guia da barra do Outlook.

    ```cpp
    m_wndOutlookBar.Create (_T("Shortcuts"),
        this,
        CRect (0, 0, 100, 100),
        ID_VIEW_OUTLOOKBAR,
        WS_CHILD | WS_VISIBLE | CBRS_LEFT);
    ```

1. Obtenha um ponteiro para `CMFCOutlookBarTabCtrl` o subjacente usando [CBaseTabbedPane::GetUnderlyingWindow](../../mfc/reference/cbasetabbedpane-class.md#getunderlyingwindow).

    ```cpp
    CMFCOutlookBarTabCtrl* pOutlookBar = (CMFCOutlookBarTabCtrl*) m_wndOutlookBar.GetUnderlyingWindow ();
    ```

1. Crie um objeto [CMFCOutlookBarPane Class](../../mfc/reference/cmfcoutlookbarpane-class.md) para cada guia que contenha botões.

    ```cpp
    m_wndOutlookPane.Create(&m_wndOutlookBar,
        AFX_DEFAULT_TOOLBAR_STYLE,
        ID_OUTLOOK_PANE_GENERAL,
        AFX_CBRS_FLOAT | AFX_CBRS_RESIZE);

    // make the Outlook pane detachable (enable docking)
    m_wndOutlookPane.EnableDocking(CBRS_ALIGN_ANY);

    // add buttons
    m_wndOutlookPane.AddButton(theApp.LoadIcon (IDR_MAINFRAME),
        "About",
        ID_APP_ABOUT);

    m_wndOutlookPane.AddButton (theApp.LoadIcon (IDR_CUSTOM_OPEN_ICON),
        "Open",
        ID_FILE_OPEN);
    ```

1. Ligue para [o CMFCOutlookBarTabCtrl::AddTab](../../mfc/reference/cmfcbasetabctrl-class.md#addtab) para adicionar cada nova guia. Defina o parâmetro *bDecável* como FALSO para tornar uma página não destacável. Ou, use [CMFCOutlookBarTabCtrl::AddControl](../../mfc/reference/cmfcoutlookbartabctrl-class.md#addcontrol) para adicionar páginas destacáveis.

    ```cpp
    pOutlookBar->AddTab (&m_wndOutlookPane, "General", (UINT) -1, TRUE);
    ```

1. Para adicionar `CWnd`um controle derivado (por exemplo, [CMFCShellTreeCtrl Class)](../../mfc/reference/cmfcshelltreectrl-class.md)como uma guia, crie o controle e chame [CMFCOutlookBarTabCtrl::AddTab](../../mfc/reference/cmfcbasetabctrl-class.md#addtab) para adicioná-lo à barra do Outlook.

> [!NOTE]
> Você deve usar IDs de controle exclusivos para cada `CWnd`objeto [CMFCOutlookBarPane Class](../../mfc/reference/cmfcoutlookbarpane-class.md) e para cada objeto derivado.

Para adicionar ou excluir dinamicamente novas páginas em tempo de execução, use [CMFCOutlookBar::CreateCustomPage](#createcustompage) e [CMFCOutlookBar::RemoveCustomPage](#removecustompage).

## <a name="outlook-2003-mode"></a>Modo Outlook 2003

No modo Outlook 2003, os botões de guia são posicionados na parte inferior do painel da barra do Outlook. Quando não há espaço suficiente para exibir os botões, eles são exibidos como ícones em uma área semelhante a uma barra de ferramentas ao longo da parte inferior do painel.

Use [CMFCOutlookBar::SetMode2003](#setmode2003) para ativar o modo Outlook 2003. Use [CMFCOutlookBarTabCtrl::SetToolbarImageList](../../mfc/reference/cmfcoutlookbartabctrl-class.md#settoolbarimagelist) para definir o bitmap que contém os ícones exibidos na parte inferior da barra do Outlook. Os ícones no bitmap devem ser ordenados por índice de guia.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cbasepane](../../mfc/reference/cbasepane-class.md)

[Cpane](../../mfc/reference/cpane-class.md)

[Cdockablepane](../../mfc/reference/cdockablepane-class.md)

[Cbasetabbedpane](../../mfc/reference/cbasetabbedpane-class.md)

[Cmfcoutlookbar](../../mfc/reference/cmfcoutlookbar-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxoutlookbar.h

## <a name="cmfcoutlookbarallowdestroyemptytabbedpane"></a><a name="allowdestroyemptytabbedpane"></a>CMFCOutlookBar::PermitirDestroyEmptyTabbedPane

Especifica se um painel vazio pode ser destruído.

```cpp
virtual BOOL AllowDestroyEmptyTabbedPane() const;
```

### <a name="return-value"></a>Valor retornado

VERDADE se um painel de abas vazio pode ser destruído; caso contrário, FALSE. A implementação padrão sempre retorna TRUE.

### <a name="remarks"></a>Comentários

Se um painel vazio não puder ser destruído, a estrutura o esconde.

## <a name="cmfcoutlookbarcanacceptpane"></a><a name="canacceptpane"></a>CMFCOutlookBar::CanAcceptPane

Determina se outro painel pode ser ancorado no painel da barra do Outlook.

```cpp
virtual BOOL CanAcceptPane(const CBasePane* pBar) const;
```

### <a name="parameters"></a>Parâmetros

*Pbar*<br/>
[em] Um ponteiro para outro painel que está sendo ancorado neste painel.

### <a name="return-value"></a>Valor retornado

VERDADE se outro painel pode ser ancorado no painel da barra outlook; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Se a barra do Outlook estiver no modo Outlook 2003, o docking não será suportado, então o valor de retorno é FALSO.

Se o parâmetro *pBar* for NULO, este método reame..

Caso contrário, esse método se comporta como o método base [CBasePane::CanAcceptPane](../../mfc/reference/cbasepane-class.md#canacceptpane), exceto que, mesmo que o docking não esteja ativado, uma barra do Outlook ainda pode permitir que outra barra do Outlook seja encaixada sobre ela.

## <a name="cmfcoutlookbarcansetcaptiontexttotabname"></a><a name="cansetcaptiontexttotabname"></a>CMFCOutlookBar::CanSet'SText'S'T'M

Determina se a legenda do painel com guias exibe o mesmo texto que a guia ativa.

```cpp
virtual BOOL CanSetCaptionTextToTabName() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se a legenda da janela da barra do Outlook for definida automaticamente para o texto da guia ativa; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Use [CBaseTabbedPane::EnableSetCaptionTextToTabName](../../mfc/reference/cbasetabbedpane-class.md#enablesetcaptiontexttotabname) para ativar ou desativar essa funcionalidade.

No modo Outlook 2003, essa configuração está sempre ativada.

## <a name="cmfcoutlookbarcreate"></a><a name="create"></a>CMFCOutlookBar::Criar

Cria o controle de barra do Outlook.

```cpp
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

*lpszCaption*<br/>
[em] Especifica a legenda da janela.

*Pparentwnd*<br/>
[em] Especifica um ponteiro para uma janela pai. Não deve ser NULO.

*Rect*<br/>
[em] Especifica o tamanho e a posição da barra de perspectiva em pixels.

*nID*<br/>
[em] Especifica o ID de controle. Deve ser diferente de outros IDs de controle usados na aplicação.

*Dwstyle*<br/>
[em] Especifica o estilo da barra de controle desejada. Para obter valores possíveis, consulte [Estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles).

*dwControlBarStyle*<br/>
[em] Especifica os estilos especiais definidos pela biblioteca.

*pContext*<br/>
[em] Criar contexto.

### <a name="return-value"></a>Valor retornado

Não zero se o método for bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói `CMFCOutlookBar` um objeto em dois passos. Primeiro ligue para o construtor `Create`e, em seguida, chame, o `CMFCOutlookBar` que cria o controle da barra de visão e o anexa ao objeto.

Consulte [CBasePane::CreateEx](../../mfc/reference/cbasepane-class.md#createex) para obter a lista dos estilos definidos pela biblioteca disponíveis a serem especificados pelo *dwControlBarStyle*.

### <a name="example"></a>Exemplo

O exemplo a seguir `Create` demonstra como `CMFCOutlookBar` usar o método da classe. Este trecho de código faz parte da [amostra Outlook Multi Views](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_OutlookMultiViews#1](../../mfc/reference/codesnippet/cpp/cmfcoutlookbar-class_1.h)]
[!code-cpp[NVC_MFC_OutlookMultiViews#2](../../mfc/reference/codesnippet/cpp/cmfcoutlookbar-class_2.cpp)]

## <a name="cmfcoutlookbarcreatecustompage"></a><a name="createcustompage"></a>CMFCOutlookBar::CriarcustomPage

Cria uma guia de barra do Outlook personalizada.

```cpp
CMFCOutlookBarPane* CreateCustomPage(
    LPCTSTR lpszPageName,
    BOOL bActivatePage=TRUE,
    DWORD dwEnabledDocking=CBRS_ALIGN_ANY,
    BOOL bEnableTextLabels=TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszPageName*<br/>
[em] O rótulo da página.

*bActivatePage*<br/>
[em] Se TRUE, a página se torna ativa após a criação.

*dwEnabledDocking*<br/>
[em] Uma combinação de CBRS_ALIGN_ bandeiras que especifica os lados de acoplamento habilitados quando a página é separada.

*bEnableTextLabels*<br/>
[em] Se TRUE, os rótulos de texto estão habilitados para os botões que residem na página.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a página recém-criada ou NULL se a criação falhar.

### <a name="remarks"></a>Comentários

Use este método para permitir que os usuários criem páginas de barra personalizadas do Outlook. Você pode criar até 100 páginas por aplicativo. Os IDs de controle de página começam a partir de 0xF000. A criação falha se o número total de páginas de barra personalizadas do Outlook exceder 100.

Use [CMFCOutlookBar::RemoveCustomPage](#removecustompage) para excluir páginas personalizadas.

## <a name="cmfcoutlookbardoesallowdyninsertbefore"></a><a name="doesallowdyninsertbefore"></a>CMFCOutlookBar::DoesAllowDynInsertBefore

Especifica se um usuário pode ancorar um painel na borda externa da barra do Outlook.

```
DECLARE_MESSAGE_MAP virtual BOOL DoesAllowDynInsertBefore() const;
```

### <a name="return-value"></a>Valor retornado

A implementação padrão retorna FALSE.

### <a name="remarks"></a>Comentários

A estrutura `DoesAllowDynInsertBefore` chama o método quando procura um local para ancorar um painel dinâmico. Se a função retornar FALSE, a estrutura não permite o encaixe de qualquer painel dinâmico nas bordas externas do painel.

Normalmente, você cria uma barra do Outlook como um controle estático não flutuante. Você pode substituir essa função em uma classe derivada e retornar TRUE para alterar esse comportamento.

> [!NOTE]
> Como os painéis dinâmicos verificam o status dos painéis estáticos ancorados ao acoplar, você deve acoplar painéis dinâmicos após painéis estáticos sempre que possível.

## <a name="cmfcoutlookbarfloattab"></a><a name="floattab"></a>CMFCOutlookBar::Floattab

Flutua um painel.

```cpp
virtual BOOL FloatTab(
    CWnd* pBar,
    int nTabID,
    AFX_DOCK_METHOD dockMethod,
    BOOL bHide);
```

### <a name="parameters"></a>Parâmetros

*Pbar*<br/>
[em] Um ponteiro para o painel para flutuar.

*nTabID*<br/>
[em] O índice baseado em zero da guia para flutuar.

*Dockmethod*<br/>
[em] Especifica o método a ser usado para fazer o painel flutuar.  Para obter mais informações, consulte [CBaseTabbedPane::FloatTab](../../mfc/reference/cbasetabbedpane-class.md#floattab).

*bOcultar*<br/>
[em] VERDADE para esconder o painel antes de flutuar; caso contrário, FALSE. Ao contrário da versão de classe base deste método, este parâmetro não tem um valor padrão.

### <a name="return-value"></a>Valor retornado

VERDADE se o painel flutuou; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método é como [CBaseTabbedPane::FloatTab](../../mfc/reference/cbasetabbedpane-class.md#floattab) exceto que ele não habilita a última guia restante em um controle de barra do Outlook para flutuar.

## <a name="cmfcoutlookbargetbuttonsfont"></a><a name="getbuttonsfont"></a>CMFCOutlookBar::GetButtonsFont

Retorna a fonte do texto nas guias do botão de página da barra do Outlook.

```cpp
CFont* GetButtonsFont() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto de fonte usado para exibir texto nas guias do botão da barra do Outlook.

### <a name="remarks"></a>Comentários

Use esta função para recuperar a fonte usada para exibir o texto nas guias do botão da página do Outlook. Você pode definir a fonte chamando [cmfcoutlookbar::SetButtonsFont](#setbuttonsfont).

## <a name="cmfcoutlookbargettabarea"></a><a name="gettabarea"></a>CMFCOutlookBar::GetTabArea

Determina o tamanho e a posição das áreas da guia na barra do Outlook.

```cpp
virtual void GetTabArea(
    CRect& rectTabAreaTop,
    CRect& rectTabAreaBottom) const;
```

### <a name="parameters"></a>Parâmetros

*rectTabAreaTop*<br/>
[fora] Contém o tamanho e a posição (nas coordenadas do cliente) da área superior da guia quando a função retorna.

*rectTabAreaBottom*<br/>
[fora] Contém o tamanho e a posição (nas coordenadas do cliente) da área da guia inferior quando a função retorna.

### <a name="remarks"></a>Comentários

A estrutura chama este método para determinar o tipo de acoplamento ao painel de destino. Quando a estrutura determina que o usuário arrasta o painel a ser ancorado sobre a área da guia do painel de destino, ele tenta adicionar o primeiro painel como uma nova guia do painel de destino. Caso contrário, ele tenta encaixar o primeiro painel em um lado apropriado do painel alvo. A estrutura cria um novo recipiente com um controle deslizante para acomodar o painel ancorado adicional.

A implementação `GetTabArea` padrão de retorna toda a área do cliente da barra do Outlook se a barra do Outlook estiver estática; isto é, se a barra do Outlook não puder flutuar. Caso contrário, ele retorna a área que os botões de página tomam na parte superior e inferior do controle da barra do Outlook.

Anular esse método em classe `CMFCOutlookBar` derivada para mudar esse comportamento.

## <a name="cmfcoutlookbarismode2003"></a><a name="ismode2003"></a>CMFCOutlookBar::IsMode2003

Especifica se o comportamento da barra do Outlook imita o do Microsoft Office Outlook 2003.

```cpp
BOOL IsMode2003() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se a barra do Outlook estiver sendo veiumnada no modo Microsoft Office 2003; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você pode habilitar este modo usando [CMFCOutlookBar::SetMode2003](#setmode2003).

## <a name="cmfcoutlookbaronafteranimation"></a><a name="onafteranimation"></a>CMFCOutlookBar::OnAfterAnimation

Chamado por [CMFCOutlookBarTabCtrl::SetActiveTab](../../mfc/reference/cmfcoutlookbartabctrl-class.md#setactivetab) depois que a guia ativa foi definida usando animação.

```cpp
virtual void OnAfterAnimation(int nPage);
```

### <a name="parameters"></a>Parâmetros

*Npage*<br/>
[em] O índice baseado em zero da página de guia que foi ativada.

### <a name="remarks"></a>Comentários

O efeito visual da configuração da guia ativa depende se você habilitou a animação. Para obter mais informações, consulte [CMFCOutlookBarTabCtrl::EnableAnimation](../../mfc/reference/cmfcoutlookbartabctrl-class.md#enableanimation).

## <a name="cmfcoutlookbaronbeforeanimation"></a><a name="onbeforeanimation"></a>CMFCOutlookBar::OnbeforeAnimation

Chamado por [CMFCOutlookBarTabCtrl::SetActiveTab](../../mfc/reference/cmfcoutlookbartabctrl-class.md#setactivetab) antes que uma página de guia seja definida como a guia ativa usando animação.

```cpp
virtual BOOL OnBeforeAnimation(int nPage);
```

### <a name="parameters"></a>Parâmetros

*Npage*<br/>
[em] O índice baseado em zero da página de guia que está prestes a ser definido ativo.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se a animação deve ser usada na definição da nova guia ativa ou FALSA se a animação deve ser desativada.

### <a name="remarks"></a>Comentários

## <a name="cmfcoutlookbaronscroll"></a><a name="onscroll"></a>CMFCOutlookBar::OnScroll

Chamada pela estrutura se a barra do Outlook estiver rolando para cima ou para baixo.

```cpp
virtual void OnScroll(BOOL bDown);
```

### <a name="parameters"></a>Parâmetros

*bDown*<br/>
[em] TRUE se a barra do Outlook estiver rolando para baixo ou FALSA se estiver rolando para cima.

### <a name="remarks"></a>Comentários

## <a name="cmfcoutlookbarremovecustompage"></a><a name="removecustompage"></a>CMFCOutlookBar::RemoveCustomPage

Remove uma página de guia de barra personalizada do Outlook.

```cpp
BOOL RemoveCustomPage(
    UINT uiPage,
    CMFCOutlookBarTabCtrl* pTargetWnd);
```

### <a name="parameters"></a>Parâmetros

*uiPage*<br/>
[em] Índice baseado em zero da página na janela pai do Outlook.

*pTargetWnd*<br/>
[em] Ponteiro para a janela do Outlook pai.

### <a name="return-value"></a>Valor retornado

Não zero se a página personalizada tiver sido removida com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Chame esta função para excluir páginas personalizadas. Quando a página é removida, seu ID de controle é devolvido ao pool de IDs disponíveis.

Você deve fornecer um ponteiro para o objeto [CMFCOutlookBarTabCtrl Class](../../mfc/reference/cmfcoutlookbartabctrl-class.md) no qual a página a ser removida reside atualmente. Observe que um usuário pode mover páginas destacáveis entre diferentes barras do Outlook, mas as informações sobre uma página personalizada residem no objeto de barra do Outlook para o qual você chamou [cmfcoutlookbar::CreateCustomPage](#createcustompage).

Use [CBaseTabbedPane::GetUnderlyingWindow](../../mfc/reference/cbasetabbedpane-class.md#getunderlyingwindow) para obter um ponteiro na janela do Outlook.

## <a name="cmfcoutlookbarsetbuttonsfont"></a><a name="setbuttonsfont"></a>CMFCOutlookBar::SetButtonsFont

Define a fonte do texto nos botões da barra do Outlook.

```cpp
void SetButtonsFont(
    CFont* pFont,
    BOOL bRedraw=TRUE);
```

### <a name="parameters"></a>Parâmetros

*fonte p*<br/>
[em] Especifica a nova fonte.

*Bredraw*<br/>
[em] Se TRUE, a barra do Outlook será redesenhada.

### <a name="remarks"></a>Comentários

Use este método para definir uma fonte para o texto exibido nos botões da página da guia de perspectiva.

## <a name="cmfcoutlookbarsetmode2003"></a><a name="setmode2003"></a>CMFCOutlookBar::SetMode2003

Especifica se o comportamento da barra do Outlook imita o do Outlook 2003.

```cpp
void SetMode2003(BOOL bMode2003=TRUE);
```

### <a name="parameters"></a>Parâmetros

*bMode2003*<br/>
[em] Se TRUE, o modo Office 2003 estiver habilitado.

### <a name="remarks"></a>Comentários

Use esta função para ativar ou desativar o modo Office 2003. Neste modo, a barra do Outlook tem uma barra de ferramentas adicional com um botão de personalização. O comportamento da barra do Outlook está em conformidade com o comportamento da barra do Outlook no Microsoft Office 2003.

Por padrão, este modo está desativado.

> [!NOTE]
> Essa função deve ser chamada antes [do CMFCOutlookBar::Criar](#create).

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CBaseTabbedPane](../../mfc/reference/cbasetabbedpane-class.md)<br/>
[Classe CMFCOutlookBarTabCtrl](../../mfc/reference/cmfcoutlookbartabctrl-class.md)<br/>
[CMFCOutlookBarPane Class](../../mfc/reference/cmfcoutlookbarpane-class.md)
