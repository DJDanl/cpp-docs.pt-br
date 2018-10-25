---
title: Classe CMFCOutlookBarPane | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d2d468ded9db1d21fd19bc553ed2a0c3227725a0
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50075548"
---
# <a name="cmfcoutlookbarpane-class"></a>Classe CMFCOutlookBarPane

Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.

Um controle derivado de [classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md) que podem ser inseridos em uma barra do Outlook ( [classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)). Painel da barra do Outlook contém uma coluna de botões grandes. O usuário pode rolar para cima e para a lista de botões se for maior do que o painel. Quando o usuário desanexa um painel de barra da barra do Outlook, ele pode flutuar ou encaixar na janela do quadro principal.

## <a name="syntax"></a>Sintaxe

```
class CMFCOutlookBarPane : public CMFCToolBar
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCOutlookBarPane::CMFCOutlookBarPane`|Construtor padrão.|
|`CMFCOutlookBarPane::~CMFCOutlookBarPane`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCOutlookBarPane::AddButton](#addbutton)|Adiciona um botão ao painel da barra do Outlook.|
|[CMFCOutlookBarPane::CanBeAttached](#canbeattached)|Determina se o painel pode ser encaixado para outra janela do painel ou quadro. (Substitui [CBasePane::CanBeAttached](../../mfc/reference/cbasepane-class.md#canbeattached).)|
|`CMFCOutlookBarPane::CanBeRestored`|Determina se o sistema pode restaurar uma barra de ferramentas para seu estado original após a personalização. (Substitui [CMFCToolBar::CanBeRestored](../../mfc/reference/cmfctoolbar-class.md#canberestored).)|
|[CMFCOutlookBarPane::ClearAll](#clearall)|Libera os recursos usados pelas imagens no painel da barra do Outlook.|
|[CMFCOutlookBarPane::Create](#create)|Cria um painel da barra do Outlook.|
|`CMFCOutlookBarPane::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|
|`CMFCOutlookBarPane::Dock`|Chamado pelo framework para encaixar o painel da barra do Outlook. (Substitui `CPane::Dock`.)|
|[CMFCOutlookBarPane::EnablePageScrollMode](#enablepagescrollmode)|Especifica se as setas de rolagem no painel da barra do Outlook Avançar a lista de botões por página ou pelo botão.|
|[CMFCOutlookBarPane::GetRegularColor](#getregularcolor)|Retorna a cor do texto normal (não selecionado) do painel da barra do Outlook.|
|`CMFCOutlookBarPane::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|
|[CMFCOutlookBarPane::IsBackgroundTexture](#isbackgroundtexture)|Determina se há uma imagem de plano de fundo carregada para o painel da barra do Outlook.|
|`CMFCOutlookBarPane::IsChangeState`|Determina se um painel flutuante pode ser encaixado. (Substitui `CPane::IsChangeState`.)|
|[CMFCOutlookBarPane::IsDrawShadedHighlight](#isdrawshadedhighlight)|Determina se a borda do botão é sombreada quando um botão está realçado e uma imagem de plano de fundo é exibida.|
|`CMFCOutlookBarPane::OnBeforeFloat`|Chamado pelo framework quando um painel é sobre em float. (Substitui [CPane::OnBeforeFloat](../../mfc/reference/cpane-class.md#onbeforefloat).)|
|[CMFCOutlookBarPane::RemoveButton](#removebutton)|Remove o botão que tem uma ID de comando especificado.|
|`CMFCOutlookBarPane::RestoreOriginalstate`|Restaura o estado original de uma barra de ferramentas. (Substitui [CMFCToolBar::RestoreOriginalState](../../mfc/reference/cmfctoolbar-class.md#restoreoriginalstate).)|
|[CMFCOutlookBarPane::SetBackColor](#setbackcolor)|Define a cor do plano de fundo.|
|[CMFCOutlookBarPane::SetBackImage](#setbackimage)|Define a imagem de plano de fundo.|
|[CMFCOutlookBarPane::SetDefaultState](#setdefaultstate)|Redefine o painel da barra do Outlook para o conjunto original de botões.|
|[CMFCOutlookBarPane::SetExtraSpace](#setextraspace)|Define o número de pixels de preenchimento usada em torno de botões no painel da barra do Outlook.|
|[CMFCOutlookBarPane::SetTextColor](#settextcolor)|Define as cores de texto normal e realçado no painel da barra do Outlook.|
|[CMFCOutlookBarPane::SetTransparentColor](#settransparentcolor)|Define a cor transparente para o painel da barra do Outlook.|
|`CMFCOutlookBarPane::SmartUpdate`|Usada internamente para atualizar a barra do Outlook. (Substitui `CMFCToolBar::SmartUpdate`.)|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCOutlookBarPane::EnableContextMenuItems](#enablecontextmenuitems)|Especifica quais itens de menu de atalho são exibidos no modo de personalização.|
|[CMFCOutlookBarPane::RemoveAllButtons](#removeallbuttons)|Remove todos os botões do painel da barra do Outlook. (Substitui [CMFCToolBar::RemoveAllButtons](../../mfc/reference/cmfctoolbar-class.md#removeallbuttons).)|

## <a name="remarks"></a>Comentários

Para obter informações sobre como implementar uma barra do Outlook, consulte [classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md).

Para obter um exemplo de uma barra do Outlook, consulte o projeto de exemplo OutlookDemo.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar vários métodos para o `CMFCOutlookBarPane` classe. O exemplo mostra como criar um painel de barra, habilitar o modo de rolagem de página, encaixe e definir a cor do plano de fundo da barra do Outlook. Este trecho de código faz parte do [Outlook com várias exibições de exemplo](../../visual-cpp-samples.md).

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

**Cabeçalho:** afxoutlookbarpane.h

##  <a name="addbutton"></a>  CMFCOutlookBarPane::AddButton

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
[in] Especifica o identificador do recurso de um bitmap.

*lpszLabel*<br/>
[in] Especifica o texto do botão.

*iIdCommand*<br/>
[in] Especifica a ID. do controle button

*iInsertAt*<br/>
[in] Especifica o índice baseado em zero na página da barra do outlook no qual inserir o botão.

*uiLabel*<br/>
[in] Uma ID de recurso de cadeia de caracteres.

*szBmpFileName*<br/>
[in] Especifica o nome do arquivo de imagem de disco para carregar.

*szLabel*<br/>
[in] Especifica o texto do botão.

*hBmp*<br/>
[in] Um identificador para o bitmap de um botão.

*hIcon*<br/>
[in] Um identificador para o ícone dos botões.

### <a name="return-value"></a>Valor de retorno

TRUE se um botão foi adicionado com êxito; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use esse método para inserir um novo botão na página de uma barra Outlook. A imagem do botão pode ser carregada de recursos do aplicativo ou de um arquivo de disco.

Se a ID de página especificado pelo *uiPageID* é -1, o botão é inserido na primeira página.

Se o índice especificado por *iInsertAt* é -1, o botão é adicionado ao final da página.

##  <a name="canbeattached"></a>  CMFCOutlookBarPane::CanBeAttached

Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.

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

Esse método chama diretamente [CMFCToolBarImages::Clear](../../mfc/reference/cmfctoolbarimages-class.md#clear), que é chamada nas imagens que são usadas pelo painel da barra do Outlook.

##  <a name="create"></a>  CMFCOutlookBarPane::Create

Cria um painel da barra do Outlook.

```
virtual BOOL Create(
    CWnd* pParentWnd,
    DWORD dwStyle=AFX_DEFAULT_TOOLBAR_STYLE,
    UINT uiID=(UINT)-1,
    DWORD dwControlBarStyle=0);
```

### <a name="parameters"></a>Parâmetros

*pParentWnd*<br/>
[in] Especifica a janela pai do controle de painel de barra do Outlook. Não deve ser NULL.

*dwStyle*<br/>
[in] O estilo da janela.  Para obter uma lista de estilos de janela, consulte [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles).

*uiID*<br/>
[in] A ID do controle. Deve ser exclusivo para habilitar o salvamento de estado do controle.

*dwControlBarStyle*<br/>
[in] Especifica os estilos especiais que definem o comportamento do controle de painel de barra do Outlook quando ele é desanexado da barra do Outlook.

### <a name="return-value"></a>Valor de retorno

TRUE se o método foi bem-sucedida; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Para construir um `CMFCOutlookBarPane` do objeto, primeiro chame o construtor e, em seguida, chamar `Create`, que cria o controle do painel da barra do Outlook e anexa-o para o `CMFCOutlookBarPane` objeto.

Para obter mais informações sobre `dwControlBarStyle` ver [CBasePane::CreateEx](../../mfc/reference/cbasepane-class.md#createex).

##  <a name="enablecontextmenuitems"></a>  CMFCOutlookBarPane::EnableContextMenuItems

Especifica quais itens de menu de atalho são exibidos no modo de personalização.

```
virtual BOOL EnableContextMenuItems(
    CMFCToolBarButton* pButton,
    CMenu* pPopup);
```

### <a name="parameters"></a>Parâmetros

*pButton*<br/>
[in] Um ponteiro para um botão de barra de ferramentas que um usuário clicou.

*pPopup*<br/>
[in] Um ponteiro para o menu de atalho.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o menu de atalho deverá ser exibido; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Substitua este método para modificar o menu de atalho padrão do framework exibida pela estrutura no modo de personalização.

A implementação padrão verifica o modo de personalização ( [CMFCToolBar::IsCustomizeMode](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode)) e se ele é definido como TRUE, desabilita o atalho todos os itens de menu exceto **excluir**. Em seguida, ele simplesmente passa os parâmetros de entrada para `CMFCToolBar::EnableContextMenuItems`.

> [!NOTE]
> *Menu de contexto* é um sinônimo para o menu de atalho.

##  <a name="enablepagescrollmode"></a>  CMFCOutlookBarPane::EnablePageScrollMode

Especifica se as setas de rolagem no painel da barra do Outlook Avançar a lista de botões de página por página ou botão pelo botão.

```
void EnablePageScrollMode(BOOL bPageScroll=TRUE);
```

### <a name="parameters"></a>Parâmetros

*bPageScroll*<br/>
[in] Se for TRUE, habilite o modo de rolagem de página. Se for FALSE, desabilite o modo de rolagem de página.

##  <a name="getregularcolor"></a>  CMFCOutlookBarPane::GetRegularColor

Retorna regulares (ou seja, não selecionado) cor do texto do painel da barra do Outlook.

```
DECLARE_MESSAGE_MAPCOLORREF GetRegularColor() const;
```

### <a name="return-value"></a>Valor de retorno

A cor do texto como um valor de cor RGB.

### <a name="remarks"></a>Comentários

Use [CMFCOutlookBarPane::SetTextColor](#settextcolor) para definir a cor do texto (regulares e selecionado) da barra do Outlook. Você pode obter a cor do texto padrão chamando o [GetSysColor](/windows/desktop/api/winuser/nf-winuser-getsyscolor) função com o índice COLOR_WINDOW.

##  <a name="isbackgroundtexture"></a>  CMFCOutlookBarPane::IsBackgroundTexture

Determina se há uma imagem de plano de fundo carregada para o painel da barra do Outlook.

```
BOOL IsBackgroundTexture() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se não houver imagem de plano de fundo a ser exibida; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Você pode adicionar uma imagem de plano de fundo, chamando [CMFCOutlookBarPane::SetBackImage](#setbackimage) função.

Se não houver nenhuma imagem de plano de fundo, tela de fundo é pintada com uma cor especificada usando [CMFCOutlookBarPane::SetBackColor](#setbackcolor).

##  <a name="isdrawshadedhighlight"></a>  CMFCOutlookBarPane::IsDrawShadedHighlight

Determina se a borda do botão é sombreada quando um botão está realçado e uma imagem de plano de fundo é exibida.

```
BOOL IsDrawShadedHighlight() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se as bordas do botão estão sombreadas; Caso contrário, FALSE.

##  <a name="removeallbuttons"></a>  CMFCOutlookBarPane::RemoveAllButtons

Remove todos os botões do painel da barra do Outlook.

```
virtual void RemoveAllButtons();
```

##  <a name="removebutton"></a>  CMFCOutlookBarPane::RemoveButton

Remove o botão que tem uma ID de comando especificado.

```
BOOL RemoveButton(UINT iIdCommand);
```

### <a name="parameters"></a>Parâmetros

*iIdCommand*<br/>
[in] Especifica a ID de um botão de comando para remover.

### <a name="return-value"></a>Valor de retorno

TRUE se o botão foi removido com êxito; FALSE se a ID de comando especificado não é válida.

##  <a name="setbackcolor"></a>  CMFCOutlookBarPane::SetBackColor

Define a cor do plano de fundo da barra do Outlook.

```
void SetBackColor(COLORREF color);
```

### <a name="parameters"></a>Parâmetros

*Cor*<br/>
[in] Especifica a nova cor de plano de fundo.

### <a name="remarks"></a>Comentários

Chame essa função para definir a cor de plano de fundo atual para a barra do Outlook. A cor do plano de fundo é usada somente se não houver nenhuma imagem de plano de fundo.

##  <a name="setbackimage"></a>  CMFCOutlookBarPane::SetBackImage

Define a imagem de plano de fundo.

```
void SetBackImage(UINT uiImageID);
```

### <a name="parameters"></a>Parâmetros

*uiImageID*<br/>
[in] Especifica a ID do recurso de imagem.

### <a name="remarks"></a>Comentários

Chame esse método para definir o Outlook imagem de plano de fundo da barra. A lista de imagens de plano de fundo é gerenciada pelo inserido [classe CMFCToolBarImages](../../mfc/reference/cmfctoolbarimages-class.md) objeto.

##  <a name="setdefaultstate"></a>  CMFCOutlookBarPane::SetDefaultState

Redefine o painel da barra do Outlook para o conjunto original de botões.

```
void SetDefaultState();
```

### <a name="remarks"></a>Comentários

Este método restaura os botões de barra do Outlook para o conjunto original. Esse método é como `CMFCOutlookBarPane::RestoreOriginalstate`, exceto que ela não dispare um redesenho do painel da barra do Outlook.

##  <a name="setextraspace"></a>  CMFCOutlookBarPane::SetExtraSpace

Define o número de pixels de preenchimento usada em torno de botões no painel da barra do Outlook.

```
void SetExtraSpace()
```

##  <a name="settextcolor"></a>  CMFCOutlookBarPane::SetTextColor

Define as cores de texto normal e realçado no painel da barra do Outlook.

```
void SetTextColor(
    COLORREF clrRegText,
    COLORREF clrSelText=0);
```

### <a name="parameters"></a>Parâmetros

*clrRegText*<br/>
[in] Especifica a nova cor do texto não selecionado.

*clrSelText*<br/>
[in] Especifica a nova cor do texto selecionado.

##  <a name="settransparentcolor"></a>  CMFCOutlookBarPane::SetTransparentColor

Define a cor transparente para o painel da barra do Outlook.

```
void SetTransparentColor(COLORREF color);
```

### <a name="parameters"></a>Parâmetros

*Cor*<br/>
Especifica a nova cor transparente.

### <a name="remarks"></a>Comentários

A cor transparente é necessária para exibir imagens transparentes. Qualquer ocorrência dessa cor em uma imagem é pintada com a cor do plano de fundo em vez disso.  Não há nenhuma combinação de imagens de plano de fundo e primeiro plano.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)<br/>
[Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)<br/>
[Classe CMFCOutlookBarTabCtrl](../../mfc/reference/cmfcoutlookbartabctrl-class.md)
