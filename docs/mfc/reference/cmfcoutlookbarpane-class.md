---
title: Classe CMFCOutlookBarPane
ms.date: 11/04/2016
f1_keywords:
- CMFCOutlookBarPane
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::AddButton
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::CanBeAttached
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::ClearAll
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::Create
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::EnablePageScrollMode
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::GetRegularColor
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::IsBackgroundTexture
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::IsDrawShadedHighlight
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::RemoveButton
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::SetBackColor
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::SetBackImage
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::SetDefaultState
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::SetExtraSpace
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::SetTextColor
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::SetTransparentColor
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::EnableContextMenuItems
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::RemoveAllButtons
helpviewer_keywords:
- CMFCOutlookBarPane [MFC], AddButton
- CMFCOutlookBarPane [MFC], CanBeAttached
- CMFCOutlookBarPane [MFC], ClearAll
- CMFCOutlookBarPane [MFC], Create
- CMFCOutlookBarPane [MFC], EnablePageScrollMode
- CMFCOutlookBarPane [MFC], GetRegularColor
- CMFCOutlookBarPane [MFC], IsBackgroundTexture
- CMFCOutlookBarPane [MFC], IsDrawShadedHighlight
- CMFCOutlookBarPane [MFC], RemoveButton
- CMFCOutlookBarPane [MFC], SetBackColor
- CMFCOutlookBarPane [MFC], SetBackImage
- CMFCOutlookBarPane [MFC], SetDefaultState
- CMFCOutlookBarPane [MFC], SetExtraSpace
- CMFCOutlookBarPane [MFC], SetTextColor
- CMFCOutlookBarPane [MFC], SetTransparentColor
- CMFCOutlookBarPane [MFC], EnableContextMenuItems
- CMFCOutlookBarPane [MFC], RemoveAllButtons
ms.assetid: 094e2ef3-a118-487e-a4cc-27626108fe08
ms.openlocfilehash: 9ef6a06a4889119e39e72a9e495e5d4f9e17cf56
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69505158"
---
# <a name="cmfcoutlookbarpane-class"></a>Classe CMFCOutlookBarPane

Para obter mais detalhes, consulte o código-fonte localizado na pasta **vc\\atlmfc\\src\\MFC** da instalação do Visual Studio.

Um controle derivado da [Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md) que pode ser inserido em uma barra do Outlook ( [Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)). O painel da barra do Outlook contém uma coluna de botões grandes. O usuário pode rolar para cima e para baixo na lista de botões se ele for maior do que o painel. Quando o usuário desanexa um painel da barra do Outlook da barra do Outlook, ele pode flutuar ou encaixar na janela do quadro principal.

## <a name="syntax"></a>Sintaxe

```
class CMFCOutlookBarPane : public CMFCToolBar
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCOutlookBarPane::CMFCOutlookBarPane`|Construtor padrão.|
|`CMFCOutlookBarPane::~CMFCOutlookBarPane`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCOutlookBarPane:: AddButton](#addbutton)|Adiciona um botão ao painel da barra do Outlook.|
|[CMFCOutlookBarPane::CanBeAttached](#canbeattached)|Determina se o painel pode ser encaixado em outra janela de painel ou quadro. (Substitui [CBasePane:: CanBeAttached](../../mfc/reference/cbasepane-class.md#canbeattached).)|
|`CMFCOutlookBarPane::CanBeRestored`|Determina se o sistema pode restaurar uma barra de ferramentas para seu estado original após a personalização. (Substitui [CMFCToolBar:: CanBeRestored](../../mfc/reference/cmfctoolbar-class.md#canberestored).)|
|[CMFCOutlookBarPane::ClearAll](#clearall)|Libera os recursos usados pelas imagens no painel da barra do Outlook.|
|[CMFCOutlookBarPane:: criar](#create)|Cria o painel da barra do Outlook.|
|`CMFCOutlookBarPane::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|`CMFCOutlookBarPane::Dock`|Chamado pelo Framework para encaixar o painel da barra do Outlook. (Substitui `CPane::Dock`.)|
|[CMFCOutlookBarPane::EnablePageScrollMode](#enablepagescrollmode)|Especifica se as setas de rolagem no painel da barra do Outlook avançam a lista de botões por página ou por botão.|
|[CMFCOutlookBarPane::GetRegularColor](#getregularcolor)|Retorna a cor de texto normal (não selecionada) do painel da barra do Outlook.|
|`CMFCOutlookBarPane::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a esse tipo de classe.|
|[CMFCOutlookBarPane::IsBackgroundTexture](#isbackgroundtexture)|Determina se há uma imagem de plano de fundo carregada para o painel da barra do Outlook.|
|`CMFCOutlookBarPane::IsChangeState`|Determina se um painel flutuante pode ser encaixado. (Substitui `CPane::IsChangeState`.)|
|[CMFCOutlookBarPane::IsDrawShadedHighlight](#isdrawshadedhighlight)|Determina se a borda do botão está sombreada quando um botão é realçado e uma imagem de plano de fundo é exibida.|
|`CMFCOutlookBarPane::OnBeforeFloat`|Chamado pelo Framework quando um painel está prestes a flutuar. (Substitui [CPane:: OnBeforeFloat](../../mfc/reference/cpane-class.md#onbeforefloat).)|
|[CMFCOutlookBarPane::RemoveButton](#removebutton)|Remove o botão que tem uma ID de comando especificada.|
|`CMFCOutlookBarPane::RestoreOriginalstate`|Restaura o estado original de uma barra de ferramentas. (Substitui [CMFCToolBar:: RestoreOriginalState](../../mfc/reference/cmfctoolbar-class.md#restoreoriginalstate).)|
|[CMFCOutlookBarPane::SetBackColor](#setbackcolor)|Define a cor do plano de fundo.|
|[CMFCOutlookBarPane::SetBackImage](#setbackimage)|Define a imagem de plano de fundo.|
|[CMFCOutlookBarPane::SetDefaultState](#setdefaultstate)|Redefine o painel da barra do Outlook para o conjunto de botões original.|
|[CMFCOutlookBarPane::SetExtraSpace](#setextraspace)|Define o número de pixels de preenchimento usado em volta de botões no painel da barra do Outlook.|
|[CMFCOutlookBarPane::SetTextColor](#settextcolor)|Define as cores de texto regular e realçado no painel da barra do Outlook.|
|[CMFCOutlookBarPane::SetTransparentColor](#settransparentcolor)|Define a cor transparente para o painel da barra do Outlook.|
|`CMFCOutlookBarPane::SmartUpdate`|Usado internamente para atualizar a barra do Outlook. (Substitui `CMFCToolBar::SmartUpdate`.)|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCOutlookBarPane::EnableContextMenuItems](#enablecontextmenuitems)|Especifica quais itens de menu de atalho são exibidos no modo de personalização.|
|[CMFCOutlookBarPane::RemoveAllButtons](#removeallbuttons)|Remove todos os botões do painel da barra do Outlook. (Substitui [CMFCToolBar:: RemoveAllButtons](../../mfc/reference/cmfctoolbar-class.md#removeallbuttons).)|

## <a name="remarks"></a>Comentários

Para obter informações sobre como implementar uma barra do Outlook, consulte [Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md).

Para obter um exemplo de uma barra do Outlook, consulte o projeto de exemplo OutlookDemo.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar vários métodos da `CMFCOutlookBarPane` classe. O exemplo mostra como criar um painel de barra do Outlook, habilitar o modo de rolagem de página, habilitar o encaixe e definir a cor da tela de fundo da barra do Outlook. Este trecho de código faz parte do [exemplo de vários modos de exibição do Outlook](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_OutlookMultiViews#3](../../mfc/reference/codesnippet/cpp/cmfcoutlookbarpane-class_1.h)]
[!code-cpp[NVC_MFC_OutlookMultiViews#4](../../mfc/reference/codesnippet/cpp/cmfcoutlookbarpane-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CBasePane](../../mfc/reference/cbasepane-class.md)

[CPane](../../mfc/reference/cpane-class.md)

[CMFCBaseToolBar](../../mfc/reference/cmfcbasetoolbar-class.md)

[CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)

[CMFCOutlookBarPane](../../mfc/reference/cmfcoutlookbarpane-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxoutlookbarpane. h

##  <a name="addbutton"></a>CMFCOutlookBarPane:: AddButton

Adiciona um botão ao painel da barra do Outlook.

```
BOOL AddButton(
    UINT uiImage,
    LPCTSTR lpszLabel,
    UINT iIdCommand,
    int iInsertAt=-1);

BOOL AddButton(
    UINT uiImage,
    UINT uiLabel,
    UINT iIdCommand,
    int iInsertAt=-1);

BOOL AddButton(
    LPCTSTR szBmpFileName,
    LPCTSTR szLabel,
    UINT iIdCommand,
    int iInsertAt=-1);

BOOL AddButton(
    HBITMAP hBmp,
    LPCTSTR lpszLabel,
    UINT iIdCommand,
    int iInsertAt=-1);

BOOL AddButton(
    HICON hIcon,
    LPCTSTR lpszLabel,
    UINT iIdCommand,
    int iInsertAt=-1,
    BOOL bAlphaBlend=FALSE);
```

### <a name="parameters"></a>Parâmetros

*uiImage*<br/>
no Especifica o identificador de recurso de um bitmap.

*lpszLabel*<br/>
no Especifica o texto do botão.

*iIdCommand*<br/>
no Especifica a ID do controle de botão.

*iInsertAt*<br/>
no Especifica o índice de base zero na página da barra do Outlook na qual inserir o botão.

*uiLabel*<br/>
no Uma ID de recurso de cadeia de caracteres.

*szBmpFileName*<br/>
no Especifica o nome do arquivo de imagem de disco a ser carregado.

*szLabel*<br/>
no Especifica o texto do botão.

*hBmp*<br/>
no Um identificador para o bitmap de um botão.

*hIcon*<br/>
no Um identificador para um ícone de botões.

### <a name="return-value"></a>Valor de retorno

TRUE se um botão tiver sido adicionado com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use este método para inserir um novo botão em uma página da barra do Outlook. A imagem do botão pode ser carregada a partir dos recursos do aplicativo ou de um arquivo de disco.

Se a ID de página especificada por *uiPageID* for-1, o botão será inserido na primeira página.

Se o índice especificado por *iInsertAt* for-1, o botão será adicionado ao final da página.

##  <a name="canbeattached"></a>CMFCOutlookBarPane::CanBeAttached

Para obter mais detalhes, consulte o código-fonte localizado na pasta **vc\\atlmfc\\src\\MFC** da instalação do Visual Studio.

```
virtual BOOL CanBeAttached() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="clearall"></a>  CMFCOutlookBarPane::ClearAll

Libera os recursos usados pelas imagens no painel da barra do Outlook.

```
void ClearAll();
```

### <a name="remarks"></a>Comentários

Esse método chama diretamente [CMFCToolBarImages:: Clear](../../mfc/reference/cmfctoolbarimages-class.md#clear), que é chamado nas imagens usadas pelo painel da barra do Outlook.

##  <a name="create"></a>CMFCOutlookBarPane:: criar

Cria o painel da barra do Outlook.

```
virtual BOOL Create(
    CWnd* pParentWnd,
    DWORD dwStyle=AFX_DEFAULT_TOOLBAR_STYLE,
    UINT uiID=(UINT)-1,
    DWORD dwControlBarStyle=0);
```

### <a name="parameters"></a>Parâmetros

*pParentWnd*<br/>
no Especifica a janela pai do controle do painel da barra do Outlook. Não deve ser nulo.

*dwStyle*<br/>
no O estilo da janela.  Para obter uma lista de estilos de janela, consulte [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles).

*uiID*<br/>
no A ID de controle. Deve ser exclusivo para habilitar o salvamento do estado do controle.

*dwControlBarStyle*<br/>
no Especifica estilos especiais que definem o comportamento do controle do painel da barra do Outlook quando ele é desanexado da barra do Outlook.

### <a name="return-value"></a>Valor de retorno

TRUE se o método foi bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Para construir um `CMFCOutlookBarPane` objeto, primeiro chame o construtor e, em seguida `Create`, chame, que cria o controle do painel da barra do Outlook e `CMFCOutlookBarPane` o anexa ao objeto.

Para obter mais informações `dwControlBarStyle` sobre o, consulte [CBasePane:: CreateEx](../../mfc/reference/cbasepane-class.md#createex).

##  <a name="enablecontextmenuitems"></a>CMFCOutlookBarPane::EnableContextMenuItems

Especifica quais itens de menu de atalho são exibidos no modo de personalização.

```
virtual BOOL EnableContextMenuItems(
    CMFCToolBarButton* pButton,
    CMenu* pPopup);
```

### <a name="parameters"></a>Parâmetros

*pButton*<br/>
no Um ponteiro para um botão da barra de ferramentas em que um usuário clicou.

*pPopup*<br/>
no Um ponteiro para o menu de atalho.

### <a name="return-value"></a>Valor de retorno

Retorna TRUE se o menu de atalho deve ser exibido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Substitua esse método para modificar o menu de atalho do Framework standard que o Framework exibe no modo de personalização.

A implementação padrão verifica o modo de personalização ( [CMFCToolBar::](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode)iscustommode) e, se estiver definida como true, desabilita todos os itens de menu de atalho, exceto **delete**. Em seguida, ele apenas passa os parâmetros de `CMFCToolBar::EnableContextMenuItems`entrada para.

> [!NOTE]
> O *menu de contexto* é um sinônimo para menu de atalho.

##  <a name="enablepagescrollmode"></a>  CMFCOutlookBarPane::EnablePageScrollMode

Especifica se as setas de rolagem no painel da barra do Outlook avançam a lista de botões página por página ou botão por botão.

```
void EnablePageScrollMode(BOOL bPageScroll=TRUE);
```

### <a name="parameters"></a>Parâmetros

*bPageScroll*<br/>
no Se for TRUE, habilite o modo de rolagem de página. Se for FALSE, desabilite o modo de rolagem de página.

##  <a name="getregularcolor"></a>  CMFCOutlookBarPane::GetRegularColor

Retorna a cor de texto regular (ou seja, não selecionado) do painel da barra do Outlook.

```
DECLARE_MESSAGE_MAPCOLORREF GetRegularColor() const;
```

### <a name="return-value"></a>Valor de retorno

A cor do texto atual como um valor de cor RGB.

### <a name="remarks"></a>Comentários

Use [CMFCOutlookBarPane:: SetTextColor](#settextcolor) para definir a cor de texto atual (regular e selecionada) da barra do Outlook. Você pode obter a cor do texto padrão chamando a função [GetSysColor](/windows/win32/api/winuser/nf-winuser-getsyscolor) com o índice COLOR_WINDOW.

##  <a name="isbackgroundtexture"></a>  CMFCOutlookBarPane::IsBackgroundTexture

Determina se há uma imagem de plano de fundo carregada para o painel da barra do Outlook.

```
BOOL IsBackgroundTexture() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se houver imagem de tela de fundo a ser exibida; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Você pode adicionar uma imagem de plano de fundo chamando a função [CMFCOutlookBarPane:: SetBackImage](#setbackimage) .

Se não houver nenhuma imagem de plano de fundo, o plano de fundo será pintado com uma cor especificada usando [CMFCOutlookBarPane:: SetBackColor](#setbackcolor).

##  <a name="isdrawshadedhighlight"></a>  CMFCOutlookBarPane::IsDrawShadedHighlight

Determina se a borda do botão está sombreada quando um botão é realçado e uma imagem de plano de fundo é exibida.

```
BOOL IsDrawShadedHighlight() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se as bordas do botão estiverem sombreadas; caso contrário, FALSE.

##  <a name="removeallbuttons"></a>  CMFCOutlookBarPane::RemoveAllButtons

Remove todos os botões do painel da barra do Outlook.

```
virtual void RemoveAllButtons();
```

##  <a name="removebutton"></a>CMFCOutlookBarPane::RemoveButton

Remove o botão que tem uma ID de comando especificada.

```
BOOL RemoveButton(UINT iIdCommand);
```

### <a name="parameters"></a>Parâmetros

*iIdCommand*<br/>
no Especifica a ID de comando de um botão a ser removido.

### <a name="return-value"></a>Valor de retorno

TRUE se o botão tiver sido removido com êxito; FALSE se a ID de comando especificada não for válida.

##  <a name="setbackcolor"></a>CMFCOutlookBarPane:: SetBackColor

Define a cor do plano de fundo da barra do Outlook.

```
void SetBackColor(COLORREF color);
```

### <a name="parameters"></a>Parâmetros

*color*<br/>
no Especifica a nova cor do plano de fundo.

### <a name="remarks"></a>Comentários

Chame essa função para definir a cor de plano de fundo atual para a barra do Outlook. A cor do plano de fundo só será usada se não houver nenhuma imagem de plano de fundo.

##  <a name="setbackimage"></a>CMFCOutlookBarPane::SetBackImage

Define a imagem de plano de fundo.

```
void SetBackImage(UINT uiImageID);
```

### <a name="parameters"></a>Parâmetros

*uiImageID*<br/>
no Especifica a ID do recurso de imagem.

### <a name="remarks"></a>Comentários

Chame esse método para definir a imagem de plano de fundo da barra do Outlook. A lista de imagens de plano de fundo é gerenciada pelo objeto de [Classe CMFCToolBarImages](../../mfc/reference/cmfctoolbarimages-class.md) inserido.

##  <a name="setdefaultstate"></a>  CMFCOutlookBarPane::SetDefaultState

Redefine o painel da barra do Outlook para o conjunto de botões original.

```
void SetDefaultState();
```

### <a name="remarks"></a>Comentários

Esse método restaura os botões da barra do Outlook para o conjunto original. Esse método é como `CMFCOutlookBarPane::RestoreOriginalstate`, exceto que ele não dispara um redesenho do painel da barra do Outlook.

##  <a name="setextraspace"></a>CMFCOutlookBarPane::SetExtraSpace

Define o número de pixels de preenchimento usado em volta de botões no painel da barra do Outlook.

```
void SetExtraSpace()
```

##  <a name="settextcolor"></a>CMFCOutlookBarPane::SetTextColor

Define as cores de texto regular e realçado no painel da barra do Outlook.

```
void SetTextColor(
    COLORREF clrRegText,
    COLORREF clrSelText=0);
```

### <a name="parameters"></a>Parâmetros

*clrRegText*<br/>
no Especifica a nova cor para o texto não selecionado.

*clrSelText*<br/>
no Especifica a nova cor do texto selecionado.

##  <a name="settransparentcolor"></a>  CMFCOutlookBarPane::SetTransparentColor

Define a cor transparente para o painel da barra do Outlook.

```
void SetTransparentColor(COLORREF color);
```

### <a name="parameters"></a>Parâmetros

*color*<br/>
Especifica a nova cor transparente.

### <a name="remarks"></a>Comentários

A cor transparente é necessária para exibir imagens transparentes. Qualquer ocorrência dessa cor em uma imagem é pintada com a cor do plano de fundo em vez disso.  Não há mistura de imagens em segundo plano e em primeiro plano.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)<br/>
[Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)<br/>
[Classe CMFCOutlookBarTabCtrl](../../mfc/reference/cmfcoutlookbartabctrl-class.md)
