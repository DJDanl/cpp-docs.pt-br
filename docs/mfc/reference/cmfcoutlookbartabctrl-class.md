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
ms.openlocfilehash: 309b74126f57e76aa6399f57382d88fee4400700
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369672"
---
# <a name="cmfcoutlookbartabctrl-class"></a>Classe CMFCOutlookBarTabCtrl

Um controle de guia que tem a aparência visual do Painel de **Navegação** no Microsoft Outlook.
Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

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
|`CMFCOutlookBarTabCtrl::CalcRectEdit`|Chamado pela estrutura para determinar as dimensões da caixa de edição que aparece `CMFCBaseTabCtrl::CalcRectEdit`quando um usuário renomeia uma guia. (Overrides .)|
|[CMFCOutlookBarTabCtrl::CanShowFewerPageButtons](#canshowfewerpagebuttons)|Chamado pela estrutura durante operações de redimensionamento para determinar se menos botões de página de guia do Outlook podem ser exibidos do que estão visíveis atualmente.|
|[CMFCOutlookBarTabCtrl::CanShowMorePageButtons](#canshowmorepagebuttons)|Chamado pela estrutura durante operações de redimensionamento para determinar se mais botões de página de guia do Outlook podem ser exibidos do que estão visíveis atualmente.|
|[CMFCOutlookBarTabCtrl::Criar](#create)|Cria o controle de guia da barra do Outlook.|
|`CMFCOutlookBarTabCtrl::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|[CMFCOutlookBarTabCtrl:EnableAnimation](#enableanimation)|Especifica se a animação que ocorre durante o switch entre as guias ativas está ativa.|
|[CMFCOutlookBarTabCtrl::EnableInPlaceEdit](#enableinplaceedit)|Especifica se um usuário pode modificar os rótulos de texto nos botões de guia da barra do Outlook. (Substitui [cmfcbasetabctrl::EnableInPlaceEdit](../../mfc/reference/cmfcbasetabctrl-class.md#enableinplaceedit).)|
|[CMFCOutlookBarTabCtrl:HabilitarBotões de pergaminho](#enablescrollbuttons)|Chamado pela estrutura para ativar botões que permitem ao usuário percorrer botões no painel da barra do Outlook.|
|`CMFCOutlookBarTabCtrl::FindTargetWnd`|Identifica o painel que contém um ponto especificado. (Substitui [cmfcbasetabctrl::FindTargetWnd](../../mfc/reference/cmfcbasetabctrl-class.md#findtargetwnd).)|
|[CMFCOutlookBarTabCtrl::GetBorderSize](#getbordersize)|Retorna o tamanho da borda do controle da guia Outlook.|
|`CMFCOutlookBarTabCtrl::GetTabArea`|Recupera o tamanho e a posição da área de guia do controle da guia. (Substitui [cmfcbasetabctrl::GetTabArea](../../mfc/reference/cmfcbasetabctrl-class.md#gettabarea).)|
|`CMFCOutlookBarTabCtrl::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|
|[CMFCOutlookBarTabCtrl::GetVisiblePageButtons](#getvisiblepagebuttons)||
|[CMFCOutlookBarTabCtrl::IsAnimation](#isanimation)|Determina se a animação que ocorre durante o switch entre as guias ativas está ativa.|
|[CMFCOutlookBarTabCtrl::IsMode2003](#ismode2003)|Determina se o controle da guia da barra do Outlook está em um modo que emula o Microsoft Outlook 2003.|
|`CMFCOutlookBarTabCtrl::IsPtInTabArea`|Determina se um ponto está dentro da área da guia. (Substitui [cmfcbasetabctrl::IsPtInTabArea](../../mfc/reference/cmfcbasetabctrl-class.md#isptintabarea).)|
|`CMFCOutlookBarTabCtrl::IsTabDetachable`|Determina se uma guia é destacável. (Substitui [cmfcbasetabctrl::IsTabDetachable](../../mfc/reference/cmfcbasetabctrl-class.md#istabdetachable).)|
|`CMFCOutlookBarTabCtrl::OnChangeTabs`|Chamado pelo framework quando uma guia é inserida ou removida. (Substitui `CMFCBaseTabCtrl::OnChangeTabs`.)|
|[CMFCOutlookBarTabCtrl::OnShowFewerPageButtons](#onshowfewerpagebuttons)|Chamado pelo framework para diminuir o número de botões de página de guia que são visíveis.|
|[CMFCOutlookBarTabCtrl::OnShowMorePageButtons](#onshowmorepagebuttons)|Chamado pelo framework para aumentar o número de botões de página de guia que são visíveis.|
|[CMFCOutlookBarTabCtrl::OnShowOptions](#onshowoptions)|Exibe a **caixa de diálogo Opções de painel de** navegação.|
|`CMFCOutlookBarTabCtrl::RecalcLayout`|Recalcula o layout interno do controle de guias. (Substitui [cmfcbasetabctrl::RecalcLayout](../../mfc/reference/cmfcbasetabctrl-class.md#recalclayout).)|
|[CMFCOutlookBarTabCtrl::SetActiveTab](#setactivetab)|Define a guia ativa. (Substitui [cmfcbasetabctrl::setActiveTab](../../mfc/reference/cmfcbasetabctrl-class.md#setactivetab).)|
|[CMFCOutlookBarTabCtrl::SetBorderSize](#setbordersize)|Define o tamanho da borda do controle da guia Outlook.|
|[CMFCOutlookBarTabCtrl::SetPageButtonTextAlign](#setpagebuttontextalign)|Define o alinhamento das etiquetas de texto nos botões de guia da barra do Outlook.|
|[CMFCOutlookBarTabCtrl::SetToolbarImageList](#settoolbarimagelist)|Define o bitmap que contém os ícones exibidos na parte inferior da barra do Outlook no modo Outlook 2003 (consulte [CMFCOutlookBar Class](../../mfc/reference/cmfcoutlookbar-class.md)).|
|[CMFCOutlookBarTabCtrl::SetVisiblePageButtons](#setvisiblepagebuttons)||

## <a name="remarks"></a>Comentários

Para criar uma barra do Outlook com `CMFCOutlookBar` suporte ao docking, use um objeto para hospedar o controle da guia de barras do Outlook. Para obter mais informações, consulte [CMFCOutlookBar Class](../../mfc/reference/cmfcoutlookbar-class.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra `CMFCOutlookBarTabCtrl` como inicializar um `CMFCOutlookBarTabCtrl` objeto e usar vários métodos na classe. O exemplo mostra como ativar a edição no local do rótulo de texto nos botões da página de guia da barra do Outlook, ativar a animação, ativar alças de rolagem que permitem ao usuário percorrer botões no painel da barra do Outlook, definir o tamanho da borda do controle da guia Outlook e definir o alinhamento das etiquetas de texto nos botões de guia da barra do Outlook. Este trecho de código faz parte da amostra do [Outlook Demo](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_OutlookDemo#1](../../mfc/reference/codesnippet/cpp/cmfcoutlookbartabctrl-class_1.cpp)]
[!code-cpp[NVC_MFC_OutlookDemo#2](../../mfc/reference/codesnippet/cpp/cmfcoutlookbartabctrl-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cmfcbasetabctrl](../../mfc/reference/cmfcbasetabctrl-class.md)

[Cmfcoutlookbartabctrl](../../mfc/reference/cmfcoutlookbartabctrl-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxoutlookbartabctrl.h

## <a name="cmfcoutlookbartabctrladdcontrol"></a><a name="addcontrol"></a>CMFCOutlookBarTabCtrl::AddControl

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
[em] Um ponteiro para um controle para adicionar.

*lpszName*<br/>
[em] Especifica o nome da guia.

*bDetachable*<br/>
[em] Se TRUE, a página será criada como destacável.

*nImageID*<br/>
[em] Índice de imagem na lista de imagens internas para que a imagem seja exibida na nova guia.

*dwControlBarStyle*<br/>
[em] Especifica o estilo AFX_ CBRS_* para painéis de encaixe embrulhados.

### <a name="remarks"></a>Comentários

Use esta função para adicionar um controle como uma nova página de uma barra de outlook.

Esta função chama internamente [o CMFCBaseTabCtrl::AddTab](../../mfc/reference/cmfcbasetabctrl-class.md#addtab).

Se você definir *bDetachable* como TRUE, `AddControl` internamente criará um `CDockablePaneAdapter` objeto e envolverá o controle adicionado. Ele define automaticamente a classe de tempo de execução `CMFCOutlookBar` da janela com guias para `CMultiPaneFrameWnd`a classe de tempo de execução e a classe de tempo de execução do quadro flutuante para .

### <a name="example"></a>Exemplo

O exemplo a seguir `AddControl` demonstra como `CMFCOutlookBarTabCtrl` usar o método na classe. Este trecho de código faz parte da amostra do [Outlook Demo](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_OutlookDemo#3](../../mfc/reference/codesnippet/cpp/cmfcoutlookbartabctrl-class_3.cpp)]

## <a name="cmfcoutlookbartabctrlcanshowfewerpagebuttons"></a><a name="canshowfewerpagebuttons"></a>CMFCOutlookBarTabCtrl::CanShowFewerPageButtons

Chamado pela estrutura durante operações de redimensionamento para determinar se menos botões de página de guia do Outlook podem ser exibidos do que estão visíveis atualmente.

```
virtual BOOL CanShowFewerPageButtons() const;
```

### <a name="return-value"></a>Valor retornado

VERDADE se houver mais de um botão; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

O controle da guia da barra do Outlook adiciona ou remove dinamicamente as guias do display, dependendo da quantidade de espaço disponível. Este método é usado pela estrutura para auxiliar nesse processo.

## <a name="cmfcoutlookbartabctrlcanshowmorepagebuttons"></a><a name="canshowmorepagebuttons"></a>CMFCOutlookBarTabCtrl::CanShowMorePageButtons

Chamado pela estrutura durante operações de redimensionamento para determinar se mais botões de página de guia do Outlook podem ser exibidos do que estão visíveis atualmente.

```
virtual BOOL CanShowMorePageButtons() const;
```

### <a name="return-value"></a>Valor retornado

VERDADE se houver botões que não estejam visíveis no momento; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

O controle da guia da barra do Outlook adiciona ou remove dinamicamente as guias do display, dependendo da quantidade de espaço disponível. Este método é usado pela estrutura para auxiliar nesse processo.

## <a name="cmfcoutlookbartabctrlcreate"></a><a name="create"></a>CMFCOutlookBarTabCtrl::Criar

Cria o controle de guia da barra do Outlook.

```
virtual BOOL Create(
    const CRect& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
[em] Especifica o tamanho e a posição iniciais em pixels.

*Pparentwnd*<br/>
[em] Aponta para a janela dos pais. Não deve ser NULO.

*nID*<br/>
[em] A id de controle.

### <a name="return-value"></a>Valor retornado

Não zero se o controle tiver sido criado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Normalmente, os controles de guia da barra de perspectiva são criados quando [o CMFCOutlookBar Class](../../mfc/reference/cmfcoutlookbar-class.md) controla a mensagem WM_CREATE do processo.

## <a name="cmfcoutlookbartabctrlenableanimation"></a><a name="enableanimation"></a>CMFCOutlookBarTabCtrl:EnableAnimation

Especifica se a animação que ocorre durante o switch entre as guias ativas está ativa.

```
static void EnableAnimation(BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
[em] Especifica se a animação deve ser ativada ou desativada.

### <a name="remarks"></a>Comentários

Chame esta função para ativar e desativar a animação. Quando o usuário abre uma página de guia, a legenda da página desliza para cima ou para baixo se a animação estiver ativada. Se a animação estiver desativada, a página fica ativa imediatamente.

Por padrão, a animação está ativada.

## <a name="cmfcoutlookbartabctrlenableinplaceedit"></a><a name="enableinplaceedit"></a>CMFCOutlookBarTabCtrl::EnableInPlaceEdit

Especifica se um usuário pode modificar os rótulos de texto nos botões da página da guia da barra do Outlook.

```
virtual void EnableInPlaceEdit(BOOL bEnable);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
Se TRUE, habilite a edição no lugar do rótulo de texto. Se FALSO, desative a edição no local.

### <a name="remarks"></a>Comentários

Chame esta função para ativar ou desativar a edição no local de rótulos de texto nos botões da página da guia. Por padrão, a edição no local está desativada.

## <a name="cmfcoutlookbartabctrlenablescrollbuttons"></a><a name="enablescrollbuttons"></a>CMFCOutlookBarTabCtrl:HabilitarBotões de pergaminho

Chamado pela estrutura para ativar alças de rolagem que permitem ao usuário percorrer botões no painel da barra do Outlook.

```
void EnableScrollButtons(
    BOOL bEnable = TRUE,
    BOOL bIsUp = TRUE,
    BOOL bIsDown = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
[em] Determina se os botões de rolagem são exibidos.

*bIsUp*<br/>
[em] Determina se a barra de rolagem superior é exibida.

*bIsDown*<br/>
[em] Determina se a barra de rolagem inferior é exibida.

### <a name="remarks"></a>Comentários

Habilita a exibição dos botões de rolagem. Este método é chamado pela estrutura quando a guia ativa muda para restaurar os botões de rolagem.

## <a name="cmfcoutlookbartabctrlgetbordersize"></a><a name="getbordersize"></a>CMFCOutlookBarTabCtrl::GetBorderSize

Retorna o tamanho da borda do controle da guia Outlook.

```
int GetBorderSize() const;
```

### <a name="return-value"></a>Valor retornado

O tamanho da borda, em pixels.

## <a name="cmfcoutlookbartabctrlgetvisiblepagebuttons"></a><a name="getvisiblepagebuttons"></a>CMFCOutlookBarTabCtrl::GetVisiblePageButtons

```
int GetVisiblePageButtons() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcoutlookbartabctrlisanimation"></a><a name="isanimation"></a>CMFCOutlookBarTabCtrl::IsAnimation

Especifica se a animação que ocorre durante o switch entre as guias ativas está ativa.

```
static BOOL IsAnimation();
```

### <a name="return-value"></a>Valor retornado

Não zero se a animação estiver ativada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Ligue para o [CMFCOutlookBarTabCtrl::EnableAnimation](#enableanimation) function para ativar ou desativar a animação.

## <a name="cmfcoutlookbartabctrlismode2003"></a><a name="ismode2003"></a>CMFCOutlookBarTabCtrl::IsMode2003

Determina se o controle da guia da barra do Outlook está em um modo que emula o Microsoft Outlook 2003.

```
BOOL IsMode2003() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o controle da guia da barra do Outlook estiver no modo Outlook 2003; caso CONTRÁRIO, FALSO;

### <a name="remarks"></a>Comentários

Este valor é definido por [CMFCOutlookBar::SetMode2003](../../mfc/reference/cmfcoutlookbar-class.md#setmode2003).

## <a name="cmfcoutlookbartabctrlonshowfewerpagebuttons"></a><a name="onshowfewerpagebuttons"></a>CMFCOutlookBarTabCtrl::OnShowFewerPageButtons

Chamado pelo framework para diminuir o número de botões de página de guia que são visíveis.

```
virtual void OnShowFewerPageButtons();
```

### <a name="remarks"></a>Comentários

Este método ajusta o número de botões de guia de página visíveis quando o controle é redimensionado.

## <a name="cmfcoutlookbartabctrlonshowmorepagebuttons"></a><a name="onshowmorepagebuttons"></a>CMFCOutlookBarTabCtrl::OnShowMorePageButtons

Chamado pelo framework para aumentar o número de botões de página de guia que são visíveis.

```
virtual void OnShowMorePageButtons();
```

### <a name="remarks"></a>Comentários

Este método ajusta o número de botões de página de guia que são visíveis quando o controle é redimensionado.

## <a name="cmfcoutlookbartabctrlonshowoptions"></a><a name="onshowoptions"></a>CMFCOutlookBarTabCtrl::OnShowOptions

Exibe a caixa de diálogo **Opções de** painel de navegação.

```
virtual void OnShowOptions();
```

### <a name="remarks"></a>Comentários

A caixa de diálogo **Opções de painel** de navegação permite que o usuário selecione quais botões de página de guia devem ser exibidos e a ordem em que eles são exibidos.

Este método é chamado pela framework quando o usuário seleciona o item do menu **Opções de painel** de navegação no menu de personalização do controle.

## <a name="cmfcoutlookbartabctrlsetactivetab"></a><a name="setactivetab"></a>CMFCOutlookBarTabCtrl::SetActiveTab

Define a guia ativa. A guia ativa é a que está aberta, com seu conteúdo visível.

```
virtual BOOL SetActiveTab(int iTab);
```

### <a name="parameters"></a>Parâmetros

*Itab*<br/>
[em] O índice baseado em zero de uma guia a ser aberta.

### <a name="return-value"></a>Valor retornado

Não zero se a guia especificada tiver sido aberta com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

O efeito visual da configuração da guia ativa depende se você habilitou a animação. Para obter mais informações, consulte [CMFCOutlookBarTabCtrl::EnableAnimation](#enableanimation).

## <a name="cmfcoutlookbartabctrlsetbordersize"></a><a name="setbordersize"></a>CMFCOutlookBarTabCtrl::SetBorderSize

Define o tamanho da borda do controle da guia Outlook.

```
void SetBorderSize(int nBorderSize);
```

### <a name="parameters"></a>Parâmetros

*nBorderSize*<br/>
[em] Especifica o novo tamanho da borda em pixels.

### <a name="remarks"></a>Comentários

Define o novo tamanho da borda e recalcula o layout da janela de perspectiva.

## <a name="cmfcoutlookbartabctrlsetpagebuttontextalign"></a><a name="setpagebuttontextalign"></a>CMFCOutlookBarTabCtrl::SetPageButtonTextAlign

Define o alinhamento das etiquetas de texto nos botões de guia da barra do Outlook.

```
void SetPageButtonTextAlign(
    UINT uiAlign,
    BOOL bRedraw=TRUE);
```

### <a name="parameters"></a>Parâmetros

*uiAlign*<br/>
[em] Especifica o alinhamento do texto.

*Bredraw*<br/>
[em] Se TRUE, a janela de perspectiva será redesenhada.

### <a name="remarks"></a>Comentários

Use esta função para alterar o alinhamento de texto para botões de página.

*uiAlign* pode ser um dos seguintes valores:

|Constante|Significado|
|--------------|-------------|
|TA_LEFT|Alinhamento à esquerda|
|TA_CENTER|Alinhamento central|
|TA_RIGHT|Alinhamento certo|

O valor padrão é TA_CENTER.

## <a name="cmfcoutlookbartabctrlsettoolbarimagelist"></a><a name="settoolbarimagelist"></a>CMFCOutlookBarTabCtrl::SetToolbarImageList

Define o bitmap que contém os ícones exibidos na parte inferior da barra do Outlook no modo Outlook 2003.

```
BOOL SetToolbarImageList(
    UINT uiID,
    int cx,
    COLORREF clrTransp=RGB(255, 0, 255));
```

### <a name="parameters"></a>Parâmetros

*Uiid*<br/>
[em] Especifica o ID de recurso da imagem a ser carregado.

*Cx*<br/>
[em] Especifica a largura de uma imagem na lista de imagens, em pixels.

*clrTransp*<br/>
[em] Um valor RGB que especifica a cor transparente.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se for bem sucedido; caso contrário retorna FALSO.

### <a name="remarks"></a>Comentários

Use esta função para anexar uma lista de imagens cujas imagens serão exibidas em botões de barra de ferramentas no modo Microsoft Office 2003. Os índices de imagem devem corresponder aos índices de página.

Este método não deve ser chamado se não estiver no modo Microsoft Office 2003. Para obter mais informações, consulte [CMFCOutlookBar Class](../../mfc/reference/cmfcoutlookbar-class.md).

## <a name="cmfcoutlookbartabctrlsetvisiblepagebuttons"></a><a name="setvisiblepagebuttons"></a>CMFCOutlookBarTabCtrl::SetVisiblePageButtons

```
void SetVisiblePageButtons(int nVisiblePageButtons);
```

### <a name="parameters"></a>Parâmetros

[em] *nVisiblePageButtons*<br/>

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCBaseTabCtrl](../../mfc/reference/cmfcbasetabctrl-class.md)<br/>
[Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)<br/>
[CMFCOutlookBarPane Class](../../mfc/reference/cmfcoutlookbarpane-class.md)
