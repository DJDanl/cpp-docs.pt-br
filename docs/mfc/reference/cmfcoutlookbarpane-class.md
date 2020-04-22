---
title: CMFCOutlookBarPane Class
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
ms.openlocfilehash: 97c7edde26bdf13e899d823dcf88d143068d86a4
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81749613"
---
# <a name="cmfcoutlookbarpane-class"></a>CMFCOutlookBarPane Class

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

Um controle derivado do [CMFCToolBar Class](../../mfc/reference/cmfctoolbar-class.md) que pode ser inserido em uma barra do Outlook [(CMFCOutlookBar Class).](../../mfc/reference/cmfcoutlookbar-class.md) O painel da barra do Outlook contém uma coluna de botões grandes. O usuário pode rolar para cima e para baixo a lista de botões se for maior que o painel. Quando o usuário destaca um painel de barra do Outlook da barra do Outlook, ele pode flutuar ou acoplar na janela principal do quadro.

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
|[CMFCOutlookBarPane::AddButton](#addbutton)|Adiciona um botão ao painel da barra do Outlook.|
|[CMFCOutlookBarPane::CanBeAttached](#canbeattached)|Determina se o painel pode ser encaixado em outro painel ou janela de quadro. (Substitui [cbasepane::CanBeAttached](../../mfc/reference/cbasepane-class.md#canbeattached).)|
|`CMFCOutlookBarPane::CanBeRestored`|Determina se o sistema pode restaurar uma barra de ferramentas ao seu estado original após a personalização. (Substitui [cmfctoolbar::CanBeRestored](../../mfc/reference/cmfctoolbar-class.md#canberestored).)|
|[CMFCOutlookBarPane::ClearAll](#clearall)|Libera os recursos usados pelas imagens no painel da barra do Outlook.|
|[CMFCOutlookBarPane::Criar](#create)|Cria o painel de barras do Outlook.|
|`CMFCOutlookBarPane::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|`CMFCOutlookBarPane::Dock`|Chamado pela estrutura para acoplar o painel de barras do Outlook. (Substitui `CPane::Dock`.)|
|[CMFCOutlookBarPane:EnablePageScrollMode](#enablepagescrollmode)|Especifica se as setas de rolagem no painel da barra do Outlook avançam a lista de botões por página ou por botão.|
|[CMFCOutlookBarPane::GetRegularColor](#getregularcolor)|Retorna a cor de texto regular (não selecionada) do painel da barra do Outlook.|
|`CMFCOutlookBarPane::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|
|[CMFCOutlookBarPane::IsBackgroundTexture](#isbackgroundtexture)|Determina se há uma imagem de fundo carregada para o painel da barra do Outlook.|
|`CMFCOutlookBarPane::IsChangeState`|Determina se um painel flutuante pode ser ancorado. (Substitui `CPane::IsChangeState`.)|
|[CMFCOutlookBarPane::IsDrawShadedHighlight](#isdrawshadedhighlight)|Determina se a borda do botão é sombreada quando um botão é destacado e uma imagem de fundo é exibida.|
|`CMFCOutlookBarPane::OnBeforeFloat`|Chamado pela estrutura quando um painel está prestes a flutuar. (Substitui [cpane::OnBeforeFloat](../../mfc/reference/cpane-class.md#onbeforefloat).)|
|[CMFCOutlookBarPane::RemoveButton](#removebutton)|Remove o botão que tem um ID de comando especificado.|
|`CMFCOutlookBarPane::RestoreOriginalstate`|Restaura o estado original de uma barra de ferramentas. (Substitui [cmfctoolbar::RestoreOriginalState](../../mfc/reference/cmfctoolbar-class.md#restoreoriginalstate).)|
|[CMFCOutlookBarPane::SetBackColor](#setbackcolor)|Define a cor de fundo.|
|[CMFCOutlookBarPane::SetBackImage](#setbackimage)|Define a imagem de fundo.|
|[CMFCOutlookBarPane::SetDefaultState](#setdefaultstate)|Redefine o painel da barra do Outlook para o conjunto original de botões.|
|[CMFCOutlookBarPane::SetExtraSpace](#setextraspace)|Define o número de pixels de preenchimento usados em torno de botões no painel da barra do Outlook.|
|[CMFCOutlookBarPane::SetTextColor](#settextcolor)|Define as cores do texto regular e destacado no painel da barra do Outlook.|
|[CMFCOutlookBarPane::SetTransparentColor](#settransparentcolor)|Define a cor transparente para o painel da barra do Outlook.|
|`CMFCOutlookBarPane::SmartUpdate`|Usado internamente para atualizar a barra do Outlook. (Substitui `CMFCToolBar::SmartUpdate`.)|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCOutlookBarPane:EnableContextMenuItems](#enablecontextmenuitems)|Especifica quais itens do menu de atalho são exibidos no modo de personalização.|
|[CMFCOutlookBarPane::RemoveAllButtons](#removeallbuttons)|Remove todos os botões do painel da barra do Outlook. (Substitui [cmfctoolbar::RemoveAllButtons](../../mfc/reference/cmfctoolbar-class.md#removeallbuttons).)|

## <a name="remarks"></a>Comentários

Para obter informações sobre como implementar uma barra do Outlook, consulte [CMFCOutlookBar Class](../../mfc/reference/cmfcoutlookbar-class.md).

Para um exemplo de barra do Outlook, consulte o projeto de amostra outlookDemo.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCOutlookBarPane` usar vários métodos da classe. O exemplo mostra como criar um painel de barras do Outlook, ativar o modo de rolagem de página, ativar o docking e definir a cor de fundo da barra do Outlook. Este trecho de código faz parte da [amostra Outlook Multi Views](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_OutlookMultiViews#3](../../mfc/reference/codesnippet/cpp/cmfcoutlookbarpane-class_1.h)]
[!code-cpp[NVC_MFC_OutlookMultiViews#4](../../mfc/reference/codesnippet/cpp/cmfcoutlookbarpane-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cbasepane](../../mfc/reference/cbasepane-class.md)

[Cpane](../../mfc/reference/cpane-class.md)

[CMFCBaseToolBar](../../mfc/reference/cmfcbasetoolbar-class.md)

[Cmfctoolbar](../../mfc/reference/cmfctoolbar-class.md)

[Cmfcoutlookbarpane](../../mfc/reference/cmfcoutlookbarpane-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxoutlookbarpane.h

## <a name="cmfcoutlookbarpaneaddbutton"></a><a name="addbutton"></a>CMFCOutlookBarPane::AddButton

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

*Uiimage*<br/>
[em] Especifica o identificador de recursos de um bitmap.

*lpszLabel*<br/>
[em] Especifica o texto do botão.

*iIdCommand*<br/>
[em] Especifica o ID do controle do botão.

*Iinsertat*<br/>
[em] Especifica o índice baseado em zero na página da barra de perspectiva na qual inserir o botão.

*Uilabel*<br/>
[em] Um ID de recurso de string.

*szBmpFileName*<br/>
[em] Especifica o nome do arquivo de imagem de disco para carregar.

*szLabel*<br/>
[em] Especifica o texto do botão.

*hBmp*<br/>
[em] Uma alça para o bitmap de um botão.

*Hicon*<br/>
[em] Uma alça para o ícone de um botão.

### <a name="return-value"></a>Valor retornado

TRUE se um botão foi adicionado com sucesso; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Use este método para inserir um novo botão na página de uma barra do Outlook. A imagem do botão pode ser carregada a partir dos recursos do aplicativo ou de um arquivo de disco.

Se o ID da página especificado pelo *uiPageID* for -1, o botão será inserido na primeira página.

Se o índice especificado por *iInsertAt* for -1, o botão será adicionado no final da página.

## <a name="cmfcoutlookbarpanecanbeattached"></a><a name="canbeattached"></a>CMFCOutlookBarPane::CanBeAttached

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

```
virtual BOOL CanBeAttached() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcoutlookbarpaneclearall"></a><a name="clearall"></a>CMFCOutlookBarPane::ClearAll

Libera os recursos usados pelas imagens no painel da barra do Outlook.

```cpp
void ClearAll();
```

### <a name="remarks"></a>Comentários

Este método chama diretamente [cmfcToolBarImages::Clear](../../mfc/reference/cmfctoolbarimages-class.md#clear), que é chamado nas imagens que são usadas pelo painel da barra do Outlook.

## <a name="cmfcoutlookbarpanecreate"></a><a name="create"></a>CMFCOutlookBarPane::Criar

Cria o painel de barras do Outlook.

```
virtual BOOL Create(
    CWnd* pParentWnd,
    DWORD dwStyle=AFX_DEFAULT_TOOLBAR_STYLE,
    UINT uiID=(UINT)-1,
    DWORD dwControlBarStyle=0);
```

### <a name="parameters"></a>Parâmetros

*Pparentwnd*<br/>
[em] Especifica a janela pai do controle do painel de barras do Outlook. Não deve ser NULO.

*Dwstyle*<br/>
[em] O estilo da janela.  Para obter uma lista de estilos de janela, consulte Estilos de [janela](../../mfc/reference/styles-used-by-mfc.md#window-styles).

*Uiid*<br/>
[em] A id de controle. Deve ser único para permitir a salvação do estado do controle.

*dwControlBarStyle*<br/>
[em] Especifica estilos especiais que definem o comportamento do controle do painel de barras do Outlook quando ele é separado da barra do Outlook.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se o método foi bem sucedido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Para construir `CMFCOutlookBarPane` um objeto, primeiro chame o `Create`construtor e, em seguida, chame , `CMFCOutlookBarPane` que cria o controle do painel da barra do Outlook e o anexa ao objeto.

Para obter `dwControlBarStyle` mais informações sobre [cBasePane::CreateEx](../../mfc/reference/cbasepane-class.md#createex).

## <a name="cmfcoutlookbarpaneenablecontextmenuitems"></a><a name="enablecontextmenuitems"></a>CMFCOutlookBarPane:EnableContextMenuItems

Especifica quais itens do menu de atalho são exibidos no modo de personalização.

```
virtual BOOL EnableContextMenuItems(
    CMFCToolBarButton* pButton,
    CMenu* pPopup);
```

### <a name="parameters"></a>Parâmetros

*Pbutton*<br/>
[em] Um ponteiro para um botão de barra de ferramentas que um usuário clicou.

*pPopup*<br/>
[em] Um ponteiro para o menu de atalho.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o menu de atalho for exibido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Substituir este método para modificar o menu de atalho padrão de estrutura que a estrutura exibe no modo de personalização.

A implementação padrão verifica o modo de personalização [(CMFCToolBar::IsCustomizeMode)](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode)e se estiver configurada como TRUE, desativará todos os itens do menu de atalho, exceto **Excluir**. Em seguida, ele apenas `CMFCToolBar::EnableContextMenuItems`passa os parâmetros de entrada para .

> [!NOTE]
> *Menu de contexto* é um sinônimo para menu de atalho.

## <a name="cmfcoutlookbarpaneenablepagescrollmode"></a><a name="enablepagescrollmode"></a>CMFCOutlookBarPane:EnablePageScrollMode

Especifica se as setas de rolagem no painel da barra do Outlook avançam a lista de botões página por página ou botão por botão.

```cpp
void EnablePageScrollMode(BOOL bPageScroll=TRUE);
```

### <a name="parameters"></a>Parâmetros

*bPageScroll*<br/>
[em] Se TRUE, habilite o modo de rolagem de página. Se FALSO, desative o modo de rolagem da página.

## <a name="cmfcoutlookbarpanegetregularcolor"></a><a name="getregularcolor"></a>CMFCOutlookBarPane::GetRegularColor

Retorna a cor de texto regular (ou seja, não selecionada) do painel da barra do Outlook.

```
DECLARE_MESSAGE_MAPCOLORREF GetRegularColor() const;
```

### <a name="return-value"></a>Valor retornado

A cor de texto atual como um valor de cor RGB.

### <a name="remarks"></a>Comentários

Use [CMFCOutlookBarPane::SetTextColor](#settextcolor) para definir a cor de texto atual (regular e selecionada) da barra do Outlook. Você pode obter a cor de texto padrão chamando a função [GetSysColor](/windows/win32/api/winuser/nf-winuser-getsyscolor) com o índice COLOR_WINDOW.

## <a name="cmfcoutlookbarpaneisbackgroundtexture"></a><a name="isbackgroundtexture"></a>CMFCOutlookBarPane::IsBackgroundTexture

Determina se há uma imagem de fundo carregada para o painel da barra do Outlook.

```
BOOL IsBackgroundTexture() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se houver imagem de fundo para exibir; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Você pode adicionar uma imagem em segundo plano chamando [CMFCOutlookBarPane::SetBackImage.](#setbackimage)

Se não houver imagem de fundo, o plano de fundo será pintado com uma cor especificada usando [CMFCOutlookBarPane::SetBackColor](#setbackcolor).

## <a name="cmfcoutlookbarpaneisdrawshadedhighlight"></a><a name="isdrawshadedhighlight"></a>CMFCOutlookBarPane::IsDrawShadedHighlight

Determina se a borda do botão é sombreada quando um botão é destacado e uma imagem de fundo é exibida.

```
BOOL IsDrawShadedHighlight() const;
```

### <a name="return-value"></a>Valor retornado

VERDADE se as bordas do botão forem sombreadas; caso contrário, FALSO.

## <a name="cmfcoutlookbarpaneremoveallbuttons"></a><a name="removeallbuttons"></a>CMFCOutlookBarPane::RemoveAllButtons

Remove todos os botões do painel da barra do Outlook.

```
virtual void RemoveAllButtons();
```

## <a name="cmfcoutlookbarpaneremovebutton"></a><a name="removebutton"></a>CMFCOutlookBarPane::RemoveButton

Remove o botão que tem um ID de comando especificado.

```
BOOL RemoveButton(UINT iIdCommand);
```

### <a name="parameters"></a>Parâmetros

*iIdCommand*<br/>
[em] Especifica o ID de comando de um botão a ser removido.

### <a name="return-value"></a>Valor retornado

TRUE se o botão foi removido com sucesso; FALSO se o ID de comando especificado não for válido.

## <a name="cmfcoutlookbarpanesetbackcolor"></a><a name="setbackcolor"></a>CMFCOutlookBarPane::SetBackColor

Define a cor de fundo da barra do Outlook.

```cpp
void SetBackColor(COLORREF color);
```

### <a name="parameters"></a>Parâmetros

*cor*<br/>
[em] Especifica a nova cor de fundo.

### <a name="remarks"></a>Comentários

Chame esta função para definir a cor de fundo atual para a barra do Outlook. A cor de fundo é usada apenas se não houver imagem de fundo.

## <a name="cmfcoutlookbarpanesetbackimage"></a><a name="setbackimage"></a>CMFCOutlookBarPane::SetBackImage

Define a imagem de fundo.

```cpp
void SetBackImage(UINT uiImageID);
```

### <a name="parameters"></a>Parâmetros

*uiImageID*<br/>
[em] Especifica o ID de recurso de imagem.

### <a name="remarks"></a>Comentários

Chame este método para definir a imagem de fundo da barra do Outlook. A lista de imagens em segundo plano é gerenciada pelo objeto [CMFCToolBarImages Class](../../mfc/reference/cmfctoolbarimages-class.md) incorporado.

## <a name="cmfcoutlookbarpanesetdefaultstate"></a><a name="setdefaultstate"></a>CMFCOutlookBarPane::SetDefaultState

Redefine o painel da barra do Outlook para o conjunto original de botões.

```cpp
void SetDefaultState();
```

### <a name="remarks"></a>Comentários

Este método restaura os botões da barra do Outlook ao conjunto original. Este método `CMFCOutlookBarPane::RestoreOriginalstate`é como , exceto que ele não desencadeia um redesenho do painel de barra do Outlook.

## <a name="cmfcoutlookbarpanesetextraspace"></a><a name="setextraspace"></a>CMFCOutlookBarPane::SetExtraSpace

Define o número de pixels de preenchimento usados em torno de botões no painel da barra do Outlook.

```cpp
void SetExtraSpace()
```

## <a name="cmfcoutlookbarpanesettextcolor"></a><a name="settextcolor"></a>CMFCOutlookBarPane::SetTextColor

Define as cores do texto regular e destacado no painel da barra do Outlook.

```cpp
void SetTextColor(
    COLORREF clrRegText,
    COLORREF clrSelText=0);
```

### <a name="parameters"></a>Parâmetros

*clrRegText*<br/>
[em] Especifica a nova cor para texto não selecionado.

*clrSelText*<br/>
[em] Especifica a nova cor para texto selecionado.

## <a name="cmfcoutlookbarpanesettransparentcolor"></a><a name="settransparentcolor"></a>CMFCOutlookBarPane::SetTransparentColor

Define a cor transparente para o painel da barra do Outlook.

```cpp
void SetTransparentColor(COLORREF color);
```

### <a name="parameters"></a>Parâmetros

*cor*<br/>
Especifica a nova cor transparente.

### <a name="remarks"></a>Comentários

A cor transparente é necessária para exibir imagens transparentes. Qualquer ocorrência dessa cor em uma imagem é pintada com a cor de fundo em vez disso.  Não há mistura de imagens de fundo e primeiro plano.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)<br/>
[Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)<br/>
[Classe CMFCOutlookBarTabCtrl](../../mfc/reference/cmfcoutlookbartabctrl-class.md)
