---
title: Classe CMFCOutlookBarTabCtrl
ms.date: 10/18/2018
f1_keywords:
- CMFCOutlookBarTabCtrl
- AFXOUTLOOKBARTABCTRL/CMFCOutlookBarTabCtrl
- AFXOUTLOOKBARTABCTRL/CMFCOutlookBarTabCtrl::AddControl
- AFXOUTLOOKBARTABCTRL/CMFCOutlookBarTabCtrl::CanShowFewerPageButtons
- AFXOUTLOOKBARTABCTRL/CMFCOutlookBarTabCtrl::CanShowMorePageButtons
- AFXOUTLOOKBARTABCTRL/CMFCOutlookBarTabCtrl::Create
- AFXOUTLOOKBARTABCTRL/CMFCOutlookBarTabCtrl::EnableAnimation
- AFXOUTLOOKBARTABCTRL/CMFCOutlookBarTabCtrl::EnableInPlaceEdit
- AFXOUTLOOKBARTABCTRL/CMFCOutlookBarTabCtrl::EnableScrollButtons
- AFXOUTLOOKBARTABCTRL/CMFCOutlookBarTabCtrl::GetBorderSize
- AFXOUTLOOKBARTABCTRL/CMFCOutlookBarTabCtrl::GetVisiblePageButtons
- AFXOUTLOOKBARTABCTRL/CMFCOutlookBarTabCtrl::IsAnimation
- AFXOUTLOOKBARTABCTRL/CMFCOutlookBarTabCtrl::IsMode2003
- AFXOUTLOOKBARTABCTRL/CMFCOutlookBarTabCtrl::OnShowFewerPageButtons
- AFXOUTLOOKBARTABCTRL/CMFCOutlookBarTabCtrl::OnShowMorePageButtons
- AFXOUTLOOKBARTABCTRL/CMFCOutlookBarTabCtrl::OnShowOptions
- AFXOUTLOOKBARTABCTRL/CMFCOutlookBarTabCtrl::SetActiveTab
- AFXOUTLOOKBARTABCTRL/CMFCOutlookBarTabCtrl::SetBorderSize
- AFXOUTLOOKBARTABCTRL/CMFCOutlookBarTabCtrl::SetPageButtonTextAlign
- AFXOUTLOOKBARTABCTRL/CMFCOutlookBarTabCtrl::SetToolbarImageList
- AFXOUTLOOKBARTABCTRL/CMFCOutlookBarTabCtrl::SetVisiblePageButtons
helpviewer_keywords:
- CMFCOutlookBarTabCtrl [MFC], AddControl
- CMFCOutlookBarTabCtrl [MFC], CanShowFewerPageButtons
- CMFCOutlookBarTabCtrl [MFC], CanShowMorePageButtons
- CMFCOutlookBarTabCtrl [MFC], Create
- CMFCOutlookBarTabCtrl [MFC], EnableAnimation
- CMFCOutlookBarTabCtrl [MFC], EnableInPlaceEdit
- CMFCOutlookBarTabCtrl [MFC], EnableScrollButtons
- CMFCOutlookBarTabCtrl [MFC], GetBorderSize
- CMFCOutlookBarTabCtrl [MFC], GetVisiblePageButtons
- CMFCOutlookBarTabCtrl [MFC], IsAnimation
- CMFCOutlookBarTabCtrl [MFC], IsMode2003
- CMFCOutlookBarTabCtrl [MFC], OnShowFewerPageButtons
- CMFCOutlookBarTabCtrl [MFC], OnShowMorePageButtons
- CMFCOutlookBarTabCtrl [MFC], OnShowOptions
- CMFCOutlookBarTabCtrl [MFC], SetActiveTab
- CMFCOutlookBarTabCtrl [MFC], SetBorderSize
- CMFCOutlookBarTabCtrl [MFC], SetPageButtonTextAlign
- CMFCOutlookBarTabCtrl [MFC], SetToolbarImageList
- CMFCOutlookBarTabCtrl [MFC], SetVisiblePageButtons
ms.assetid: b1f2b3f7-cc59-49a3-99d8-7ff9b37c044b
ms.openlocfilehash: c791f3988c7257ed7d188917394e74a6dbeca98b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62374032"
---
# <a name="cmfcoutlookbartabctrl-class"></a>Classe CMFCOutlookBarTabCtrl

Um controle guia que tem a aparência visual do **painel de navegação** no Microsoft Outlook.
Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.
## <a name="syntax"></a>Sintaxe

```
class CMFCOutlookBarTabCtrl : public CMFCBaseTabCtrl
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCOutlookBarTabCtrl::CMFCOutlookBarTabCtrl`|Construtor padrão.|
|`CMFCOutlookBarTabCtrl::~CMFCOutlookBarTabCtrl`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCOutlookBarTabCtrl::AddControl](#addcontrol)|Adiciona um controle do Windows como uma nova guia na barra do Outlook.|
|`CMFCOutlookBarTabCtrl::CalcRectEdit`|Chamado pelo framework determinar as dimensões da caixa de edição que aparece quando um usuário renomeia uma guia. (Substitui `CMFCBaseTabCtrl::CalcRectEdit`.)|
|[CMFCOutlookBarTabCtrl::CanShowFewerPageButtons](#canshowfewerpagebuttons)|Chamado pelo framework durante as operações de redimensionamento para determinar se podem ser exibidos menos Outlook guia página botões da barra de que estão visíveis no momento.|
|[CMFCOutlookBarTabCtrl::CanShowMorePageButtons](#canshowmorepagebuttons)|Chamado pelo framework durante as operações de redimensionamento para determinar se podem ser exibidos mais botões da página Outlook barra guia que estão visíveis no momento.|
|[CMFCOutlookBarTabCtrl::Create](#create)|Cria o controle de guia de barra do Outlook.|
|`CMFCOutlookBarTabCtrl::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|
|[CMFCOutlookBarTabCtrl::EnableAnimation](#enableanimation)|Especifica se a animação que ocorre durante a alternância entre as guias de Active Directory está habilitada.|
|[CMFCOutlookBarTabCtrl::EnableInPlaceEdit](#enableinplaceedit)|Especifica se um usuário pode modificar os rótulos de texto em botões da guia da barra do Outlook. (Substitui [CMFCBaseTabCtrl::EnableInPlaceEdit](../../mfc/reference/cmfcbasetabctrl-class.md#enableinplaceedit).)|
|[CMFCOutlookBarTabCtrl::EnableScrollButtons](#enablescrollbuttons)|Chamado pelo framework para habilitar os botões que permitem que o usuário role por meio de botões no painel da barra do Outlook.|
|`CMFCOutlookBarTabCtrl::FindTargetWnd`|Identifica o painel que contém um ponto especificado. (Substitui [CMFCBaseTabCtrl::FindTargetWnd](../../mfc/reference/cmfcbasetabctrl-class.md#findtargetwnd).)|
|[CMFCOutlookBarTabCtrl::GetBorderSize](#getbordersize)|Retorna o tamanho da borda do controle de guia do Outlook.|
|`CMFCOutlookBarTabCtrl::GetTabArea`|Recupera o tamanho e posição da área da guia do controle guia. (Substitui [CMFCBaseTabCtrl::GetTabArea](../../mfc/reference/cmfcbasetabctrl-class.md#gettabarea).)|
|`CMFCOutlookBarTabCtrl::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|
|[CMFCOutlookBarTabCtrl::GetVisiblePageButtons](#getvisiblepagebuttons)||
|[CMFCOutlookBarTabCtrl::IsAnimation](#isanimation)|Determina se a animação que ocorre durante a alternância entre as guias de Active Directory está habilitada.|
|[CMFCOutlookBarTabCtrl::IsMode2003](#ismode2003)|Determina se o controle de guia de barra do Outlook está em um modo que emula o Microsoft Outlook 2003.|
|`CMFCOutlookBarTabCtrl::IsPtInTabArea`|Determina se um ponto está dentro da área de guia. (Substitui [CMFCBaseTabCtrl::IsPtInTabArea](../../mfc/reference/cmfcbasetabctrl-class.md#isptintabarea).)|
|`CMFCOutlookBarTabCtrl::IsTabDetachable`|Determina se uma guia é removível. (Substitui [CMFCBaseTabCtrl::IsTabDetachable](../../mfc/reference/cmfcbasetabctrl-class.md#istabdetachable).)|
|`CMFCOutlookBarTabCtrl::OnChangeTabs`|Chamado pelo framework quando uma guia é inserida ou removida. (Substitui `CMFCBaseTabCtrl::OnChangeTabs`.)|
|[CMFCOutlookBarTabCtrl::OnShowFewerPageButtons](#onshowfewerpagebuttons)|Chamado pelo framework para diminuir o número de botões de página de guia que são visíveis.|
|[CMFCOutlookBarTabCtrl::OnShowMorePageButtons](#onshowmorepagebuttons)|Chamado pelo framework para aumentar o número de botões de página de guia que são visíveis.|
|[CMFCOutlookBarTabCtrl::OnShowOptions](#onshowoptions)|Exibe a **opções do painel de navegação** caixa de diálogo.|
|`CMFCOutlookBarTabCtrl::RecalcLayout`|Recalcula o layout interno do controle guia. (Substitui [CMFCBaseTabCtrl::RecalcLayout](../../mfc/reference/cmfcbasetabctrl-class.md#recalclayout).)|
|[CMFCOutlookBarTabCtrl::SetActiveTab](#setactivetab)|Define a guia ativa. (Substitui [CMFCBaseTabCtrl::SetActiveTab](../../mfc/reference/cmfcbasetabctrl-class.md#setactivetab).)|
|[CMFCOutlookBarTabCtrl::SetBorderSize](#setbordersize)|Define o tamanho da borda do controle de guia do Outlook.|
|[CMFCOutlookBarTabCtrl::SetPageButtonTextAlign](#setpagebuttontextalign)|Define o alinhamento dos rótulos de texto em botões da guia da barra do Outlook.|
|[CMFCOutlookBarTabCtrl::SetToolbarImageList](#settoolbarimagelist)|Define o bitmap que contém os ícones que são exibidos na parte inferior da barra do Outlook no modo do Outlook 2003 (consulte [classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)).|
|[CMFCOutlookBarTabCtrl::SetVisiblePageButtons](#setvisiblepagebuttons)||

## <a name="remarks"></a>Comentários

Para criar uma barra do Outlook que tem suporte de encaixe, use um `CMFCOutlookBar` objeto para hospedar o controle de guia da barra do Outlook. Para obter mais informações, consulte [classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como inicializar uma `CMFCOutlookBarTabCtrl` do objeto e usar vários métodos no `CMFCOutlookBarTabCtrl` classe. O exemplo mostra como habilitar a edição in-loco do rótulo de texto nos botões de página de guia da barra do Outlook, habilitar a animação, habilitar identificadores de rolagem que permitem que o usuário role por meio de botões no painel da barra do Outlook, defina o tamanho da borda da continuação de guia do Outlook função e defina o alinhamento dos rótulos de texto dos botões da guia da barra do Outlook. Este trecho de código faz parte do [amostra de demonstração do Outlook](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_OutlookDemo#1](../../mfc/reference/codesnippet/cpp/cmfcoutlookbartabctrl-class_1.cpp)]
[!code-cpp[NVC_MFC_OutlookDemo#2](../../mfc/reference/codesnippet/cpp/cmfcoutlookbartabctrl-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CMFCBaseTabCtrl](../../mfc/reference/cmfcbasetabctrl-class.md)

[CMFCOutlookBarTabCtrl](../../mfc/reference/cmfcoutlookbartabctrl-class.md)

## <a name="requirements"></a>Requisitos

**Header:** afxoutlookbartabctrl.h

##  <a name="addcontrol"></a>  CMFCOutlookBarTabCtrl::AddControl

Adiciona um controle do Windows como uma nova guia na barra do Outlook.

```
void AddControl(
    CWnd* pWndCtrl,
    LPCTSTR lpszName,
    int nImageID=-1,
    BOOL bDetachable=TRUE,
    DWORD dwControlBarStyle=AFX_CBRS_FLOAT |  AFX_CBRS_CLOSE | AFX_CBRS_RESIZE |  CBRS_AFX_AUTOHIDE);
```

### <a name="parameters"></a>Parâmetros

*pWndCtrl*<br/>
[in] Um ponteiro para um controle a ser adicionado.

*lpszName*<br/>
[in] Especifica o nome da guia.

*bDetachable*<br/>
[in] Se for TRUE, a página será criada como destacável.

*nImageID*<br/>
[in] Índice de imagem na lista de imagem interna para a imagem a ser exibido na nova guia.

*dwControlBarStyle*<br/>
[in] Especifica o estilo AFX_ CBRS_ * para painéis de encaixe encapsulados.

### <a name="remarks"></a>Comentários

Use essa função para adicionar um controle como uma nova página de uma barra do outlook.

Essa função chama internamente na [CMFCBaseTabCtrl::AddTab](../../mfc/reference/cmfcbasetabctrl-class.md#addtab).

Se você definir *bDetachable* como TRUE, o `AddControl` cria internamente uma `CDockablePaneAdapter` de objeto e encapsula o controle adicionado. Ela configura automaticamente a classe de tempo de execução da janela com guias para a classe de tempo de execução de `CMFCOutlookBar` e a classe de tempo de execução do quadro flutuante para `CMultiPaneFrameWnd`.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar o `AddControl` método no `CMFCOutlookBarTabCtrl` classe. Este trecho de código faz parte do [amostra de demonstração do Outlook](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_OutlookDemo#3](../../mfc/reference/codesnippet/cpp/cmfcoutlookbartabctrl-class_3.cpp)]

##  <a name="canshowfewerpagebuttons"></a>  CMFCOutlookBarTabCtrl::CanShowFewerPageButtons

Chamado pelo framework durante o redimensionamento de operações para determinar se menos botões de página Outlook barra guia podem ser exibidos que estão visíveis no momento.

```
virtual BOOL CanShowFewerPageButtons() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se houver mais de um botão; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O controle de guia de barra do Outlook dinamicamente adiciona ou remove as guias da exibição, dependendo de quanto espaço está disponível. Esse método é usado pelo framework para ajudá-lo nesse processo.

##  <a name="canshowmorepagebuttons"></a>  CMFCOutlookBarTabCtrl::CanShowMorePageButtons

Chamado pelo framework durante o redimensionamento de operações para determinar se mais botões da página Outlook barra guia podem ser exibido que estão visíveis no momento.

```
virtual BOOL CanShowMorePageButtons() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se há botões que não são visíveis no momento; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O controle de guia de barra do Outlook dinamicamente adiciona ou remove as guias da exibição, dependendo de quanto espaço está disponível. Esse método é usado pelo framework para ajudá-lo nesse processo.

##  <a name="create"></a>  CMFCOutlookBarTabCtrl::Create

Cria o controle de guia de barra do Outlook.

```
virtual BOOL Create(
    const CRect& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*rect*<br/>
[in] Especifica o tamanho inicial e a posição, em pixels.

*pParentWnd*<br/>
[in] Aponta para a janela pai. Não deve ser NULL.

*nID*<br/>
[in] A ID do controle.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o controle tiver sido criado com êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Geralmente, controles de guia de barra do outlook são criados quando [classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md) controla a mensagem WM_CREATE do processo.

##  <a name="enableanimation"></a>  CMFCOutlookBarTabCtrl::EnableAnimation

Especifica se a animação que ocorre durante a alternância entre as guias de Active Directory está habilitada.

```
static void EnableAnimation(BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*bEnable*<br/>
[in] Especifica se a animação deve ser habilitada ou desabilitada.

### <a name="remarks"></a>Comentários

Chame essa função para habilitar e desabilitar a animação. Quando o usuário abre uma página da guia, legenda da página desliza para cima ou para baixo se a animação está habilitada. Se a animação está desabilitada, a página se torne ativa imediatamente.

Por padrão, a animação está habilitada.

##  <a name="enableinplaceedit"></a>  CMFCOutlookBarTabCtrl::EnableInPlaceEdit

Especifica se um usuário pode modificar os rótulos de texto nos botões de página de guia da barra do Outlook.

```
virtual void EnableInPlaceEdit(BOOL bEnable);
```

### <a name="parameters"></a>Parâmetros

*bEnable*<br/>
Se for TRUE, habilite a edição in-loco do rótulo de texto. Se for FALSE, desabilite a edição in-loco.

### <a name="remarks"></a>Comentários

Chame essa função para habilitar ou desabilitar a edição in-loco dos rótulos de texto nos botões de página de guia. A edição in-loco está desabilitado por padrão.

##  <a name="enablescrollbuttons"></a>  CMFCOutlookBarTabCtrl::EnableScrollButtons

Chamado pelo framework para habilitar os identificadores de rolagem que permitem que o usuário role por meio de botões no painel da barra do Outlook.

```
void EnableScrollButtons(
    BOOL bEnable = TRUE,
    BOOL bIsUp = TRUE,
    BOOL bIsDown = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bEnable*<br/>
[in] Determina se os botões de rolagem são exibidos.

*bIsUp*<br/>
[in] Determina se a barra de rolagem superior é exibida.

*bIsDown*<br/>
[in] Determina se a barra de rolagem inferior é exibida.

### <a name="remarks"></a>Comentários

Permite a exibição dos botões de rolagem. Este método é chamado pelo framework quando a guia ativa é alterado para restaurar os botões de rolagem.

##  <a name="getbordersize"></a>  CMFCOutlookBarTabCtrl::GetBorderSize

Retorna o tamanho da borda do controle de guia do Outlook.

```
int GetBorderSize() const;
```

### <a name="return-value"></a>Valor de retorno

O tamanho de borda, em pixels.

##  <a name="getvisiblepagebuttons"></a>  CMFCOutlookBarTabCtrl::GetVisiblePageButtons

```
int GetVisiblePageButtons() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="isanimation"></a>  CMFCOutlookBarTabCtrl::IsAnimation

Especifica se a animação que ocorre durante a alternância entre as guias de Active Directory está habilitada.

```
static BOOL IsAnimation();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a animação estiver habilitada; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Chame o [CMFCOutlookBarTabCtrl::EnableAnimation](#enableanimation) função para habilitar ou desabilitar a animação.

##  <a name="ismode2003"></a>  CMFCOutlookBarTabCtrl::IsMode2003

Determina se o controle de guia de barra do Outlook está em um modo que emula o Microsoft Outlook 2003.

```
BOOL IsMode2003() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se a barra de controle de guia do Outlook estiver no modo do Outlook 2003; Caso contrário, FALSE;

### <a name="remarks"></a>Comentários

Esse valor é definido [CMFCOutlookBar::SetMode2003](../../mfc/reference/cmfcoutlookbar-class.md#setmode2003).

##  <a name="onshowfewerpagebuttons"></a>  CMFCOutlookBarTabCtrl::OnShowFewerPageButtons

Chamado pelo framework para diminuir o número de botões de página de guia que são visíveis.

```
virtual void OnShowFewerPageButtons();
```

### <a name="remarks"></a>Comentários

Este método ajusta o número de botões da guia de página visível quando o controle é redimensionado.

##  <a name="onshowmorepagebuttons"></a>  CMFCOutlookBarTabCtrl::OnShowMorePageButtons

Chamado pelo framework para aumentar o número de botões de página de guia que são visíveis.

```
virtual void OnShowMorePageButtons();
```

### <a name="remarks"></a>Comentários

Esse método ajustar o número de botões de página de guia que são visíveis quando o controle é redimensionado.

##  <a name="onshowoptions"></a>  CMFCOutlookBarTabCtrl::OnShowOptions

Exibe a **opções do painel de navegação** caixa de diálogo.

```
virtual void OnShowOptions();
```

### <a name="remarks"></a>Comentários

O **opções do painel de navegação** caixa de diálogo permite que o usuário selecione quais botões de página de guia devem ser exibidas e a ordem na qual elas são exibidas.

Esse método é chamado pelo framework quando o usuário seleciona o **opções do painel de navegação** item de menu no menu de personalização do controle.

##  <a name="setactivetab"></a>  CMFCOutlookBarTabCtrl::SetActiveTab

Define a guia ativa. A guia ativa é aquela que está aberta, com seu conteúdo visível.

```
virtual BOOL SetActiveTab(int iTab);
```

### <a name="parameters"></a>Parâmetros

*iTab*<br/>
[in] O índice baseado em zero de uma guia a ser aberto.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a guia especificada tiver sido aberta com êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

O efeito visual de definir a guia ativa depende de você ter habilitado a animação. Para obter mais informações, consulte [CMFCOutlookBarTabCtrl::EnableAnimation](#enableanimation).

##  <a name="setbordersize"></a>  CMFCOutlookBarTabCtrl::SetBorderSize

Define o tamanho da borda do controle de guia do Outlook.

```
void SetBorderSize(int nBorderSize);
```

### <a name="parameters"></a>Parâmetros

*nBorderSize*<br/>
[in] Especifica o novo tamanho da borda em pixels.

### <a name="remarks"></a>Comentários

Define o novo tamanho de borda e recalcula o layout de janela do outlook.

##  <a name="setpagebuttontextalign"></a>  CMFCOutlookBarTabCtrl::SetPageButtonTextAlign

Define o alinhamento dos rótulos de texto em botões da guia da barra do Outlook.

```
void SetPageButtonTextAlign(
    UINT uiAlign,
    BOOL bRedraw=TRUE);
```

### <a name="parameters"></a>Parâmetros

*uiAlign*<br/>
[in] Especifica o alinhamento do texto.

*bRedraw*<br/>
[in] Se for TRUE, a janela do outlook será redesenhada.

### <a name="remarks"></a>Comentários

Use essa função para alterar o alinhamento de texto para botões de página.

*uiAlign* pode ser um dos seguintes valores:

|Constante|Significado|
|--------------|-------------|
|TA_LEFT|Alinhamento à esquerda|
|TA_CENTER|Alinhamento centralizado|
|TA_RIGHT|Alinhamento à direita|

O valor padrão é TA_CENTER.

##  <a name="settoolbarimagelist"></a>  CMFCOutlookBarTabCtrl::SetToolbarImageList

Define o bitmap que contém os ícones que são exibidos na parte inferior da barra do Outlook no modo do Outlook 2003.

```
BOOL SetToolbarImageList(
    UINT uiID,
    int cx,
    COLORREF clrTransp=RGB(255, 0, 255));
```

### <a name="parameters"></a>Parâmetros

*uiID*<br/>
[in] Especifica a ID do recurso da imagem para carregar.

*cx*<br/>
[in] Especifica a largura de uma imagem na lista de imagens, em pixels.

*clrTransp*<br/>
[in] Um valor RGB que especifica a cor transparente.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se bem-sucedido; Caso contrário, retornará FALSE.

### <a name="remarks"></a>Comentários

Use essa função para anexar uma lista de imagens cujas imagens serão exibidas nos botões de barra de ferramentas no modo do Microsoft Office 2003. Índices de imagem devem corresponder a índices de página.

Esse método não deve ser chamado se não estiver no modo do Microsoft Office 2003. Para obter mais informações, consulte [classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md).

##  <a name="setvisiblepagebuttons"></a>  CMFCOutlookBarTabCtrl::SetVisiblePageButtons

```
void SetVisiblePageButtons(int nVisiblePageButtons);
```

### <a name="parameters"></a>Parâmetros

[in] *nVisiblePageButtons*<br/>

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCBaseTabCtrl](../../mfc/reference/cmfcbasetabctrl-class.md)<br/>
[Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)<br/>
[Classe CMFCOutlookBarPane](../../mfc/reference/cmfcoutlookbarpane-class.md)
