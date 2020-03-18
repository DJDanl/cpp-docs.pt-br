---
title: Classe CMFCMenuBar
ms.date: 10/18/2018
f1_keywords:
- CMFCMenuBar
- AFXMENUBAR/CMFCMenuBar
- AFXMENUBAR/CMFCMenuBar::AdjustLocations
- AFXMENUBAR/CMFCMenuBar::AllowChangeTextLabels
- AFXMENUBAR/CMFCMenuBar::AllowShowOnPaneMenu
- AFXMENUBAR/CMFCMenuBar::CalcFixedLayout
- AFXMENUBAR/CMFCMenuBar::CalcLayout
- AFXMENUBAR/CMFCMenuBar::CalcMaxButtonHeight
- AFXMENUBAR/CMFCMenuBar::CanBeClosed
- AFXMENUBAR/CMFCMenuBar::CanBeRestored
- AFXMENUBAR/CMFCMenuBar::Create
- AFXMENUBAR/CMFCMenuBar::CreateEx
- AFXMENUBAR/CMFCMenuBar::CreateFromMenu
- AFXMENUBAR/CMFCMenuBar::EnableHelpCombobox
- AFXMENUBAR/CMFCMenuBar::EnableMenuShadows
- AFXMENUBAR/CMFCMenuBar::GetAvailableExpandSize
- AFXMENUBAR/CMFCMenuBar::GetColumnWidth
- AFXMENUBAR/CMFCMenuBar::GetDefaultMenu
- AFXMENUBAR/CMFCMenuBar::GetDefaultMenuResId
- AFXMENUBAR/CMFCMenuBar::GetFloatPopupDirection
- AFXMENUBAR/CMFCMenuBar::GetForceDownArrows
- AFXMENUBAR/CMFCMenuBar::GetHelpCombobox
- AFXMENUBAR/CMFCMenuBar::GetHMenu
- AFXMENUBAR/CMFCMenuBar::GetMenuFont
- AFXMENUBAR/CMFCMenuBar::GetMenuItem
- AFXMENUBAR/CMFCMenuBar::GetRowHeight
- AFXMENUBAR/CMFCMenuBar::GetSystemButton
- AFXMENUBAR/CMFCMenuBar::GetSystemButtonsCount
- AFXMENUBAR/CMFCMenuBar::GetSystemMenu
- AFXMENUBAR/CMFCMenuBar::HighlightDisabledItems
- AFXMENUBAR/CMFCMenuBar::IsButtonExtraSizeAvailable
- AFXMENUBAR/CMFCMenuBar::IsHighlightDisabledItems
- AFXMENUBAR/CMFCMenuBar::IsMenuShadows
- AFXMENUBAR/CMFCMenuBar::IsRecentlyUsedMenus
- AFXMENUBAR/CMFCMenuBar::IsShowAllCommands
- AFXMENUBAR/CMFCMenuBar::IsShowAllCommandsDelay
- AFXMENUBAR/CMFCMenuBar::LoadState
- AFXMENUBAR/CMFCMenuBar::OnChangeHot
- AFXMENUBAR/CMFCMenuBar::OnDefaultMenuLoaded
- AFXMENUBAR/CMFCMenuBar::OnSendCommand
- AFXMENUBAR/CMFCMenuBar::OnSetDefaultButtonText
- AFXMENUBAR/CMFCMenuBar::OnToolHitTest
- AFXMENUBAR/CMFCMenuBar::PreTranslateMessage
- AFXMENUBAR/CMFCMenuBar::RestoreOriginalstate
- AFXMENUBAR/CMFCMenuBar::SaveState
- AFXMENUBAR/CMFCMenuBar::SetDefaultMenuResId
- AFXMENUBAR/CMFCMenuBar::SetForceDownArrows
- AFXMENUBAR/CMFCMenuBar::SetMaximizeMode
- AFXMENUBAR/CMFCMenuBar::SetMenuButtonRTC
- AFXMENUBAR/CMFCMenuBar::SetMenuFont
- AFXMENUBAR/CMFCMenuBar::SetRecentlyUsedMenus
- AFXMENUBAR/CMFCMenuBar::SetShowAllCommands
helpviewer_keywords:
- CMFCMenuBar [MFC], AdjustLocations
- CMFCMenuBar [MFC], AllowChangeTextLabels
- CMFCMenuBar [MFC], AllowShowOnPaneMenu
- CMFCMenuBar [MFC], CalcFixedLayout
- CMFCMenuBar [MFC], CalcLayout
- CMFCMenuBar [MFC], CalcMaxButtonHeight
- CMFCMenuBar [MFC], CanBeClosed
- CMFCMenuBar [MFC], CanBeRestored
- CMFCMenuBar [MFC], Create
- CMFCMenuBar [MFC], CreateEx
- CMFCMenuBar [MFC], CreateFromMenu
- CMFCMenuBar [MFC], EnableHelpCombobox
- CMFCMenuBar [MFC], EnableMenuShadows
- CMFCMenuBar [MFC], GetAvailableExpandSize
- CMFCMenuBar [MFC], GetColumnWidth
- CMFCMenuBar [MFC], GetDefaultMenu
- CMFCMenuBar [MFC], GetDefaultMenuResId
- CMFCMenuBar [MFC], GetFloatPopupDirection
- CMFCMenuBar [MFC], GetForceDownArrows
- CMFCMenuBar [MFC], GetHelpCombobox
- CMFCMenuBar [MFC], GetHMenu
- CMFCMenuBar [MFC], GetMenuFont
- CMFCMenuBar [MFC], GetMenuItem
- CMFCMenuBar [MFC], GetRowHeight
- CMFCMenuBar [MFC], GetSystemButton
- CMFCMenuBar [MFC], GetSystemButtonsCount
- CMFCMenuBar [MFC], GetSystemMenu
- CMFCMenuBar [MFC], HighlightDisabledItems
- CMFCMenuBar [MFC], IsButtonExtraSizeAvailable
- CMFCMenuBar [MFC], IsHighlightDisabledItems
- CMFCMenuBar [MFC], IsMenuShadows
- CMFCMenuBar [MFC], IsRecentlyUsedMenus
- CMFCMenuBar [MFC], IsShowAllCommands
- CMFCMenuBar [MFC], IsShowAllCommandsDelay
- CMFCMenuBar [MFC], LoadState
- CMFCMenuBar [MFC], OnChangeHot
- CMFCMenuBar [MFC], OnDefaultMenuLoaded
- CMFCMenuBar [MFC], OnSendCommand
- CMFCMenuBar [MFC], OnSetDefaultButtonText
- CMFCMenuBar [MFC], OnToolHitTest
- CMFCMenuBar [MFC], PreTranslateMessage
- CMFCMenuBar [MFC], RestoreOriginalstate
- CMFCMenuBar [MFC], SaveState
- CMFCMenuBar [MFC], SetDefaultMenuResId
- CMFCMenuBar [MFC], SetForceDownArrows
- CMFCMenuBar [MFC], SetMaximizeMode
- CMFCMenuBar [MFC], SetMenuButtonRTC
- CMFCMenuBar [MFC], SetMenuFont
- CMFCMenuBar [MFC], SetRecentlyUsedMenus
- CMFCMenuBar [MFC], SetShowAllCommands
ms.assetid: 8a3ce4c7-b012-4dc0-b4f8-53c10b4b86b8
ms.openlocfilehash: 278feca6b64915d0cf789e8f68af3c3fdf9b3129
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79420263"
---
# <a name="cmfcmenubar-class"></a>Classe CMFCMenuBar

Uma barra de menus que implementa encaixe.
Para obter mais detalhes, consulte o código-fonte localizado no **VC\\atlmfc\\src\\pasta MFC** da sua instalação do Visual Studio.

## <a name="syntax"></a>Sintaxe

```
class CMFCMenuBar : public CMFCToolbar
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CMFCMenuBar::AdjustLocations](#adjustlocations)|(Substitui `CMFCToolBar::AdjustLocations`.)|
|[CMFCMenuBar::AllowChangeTextLabels](#allowchangetextlabels)|Especifica se os rótulos de texto podem ser mostrados em imagens nos botões da barra de ferramentas. (Substitui [CMFCToolBar:: AllowChangeTextLabels](../../mfc/reference/cmfctoolbar-class.md#allowchangetextlabels).)|
|[CMFCMenuBar::AllowShowOnPaneMenu](#allowshowonpanemenu)|(Substitui `CPane::AllowShowOnPaneMenu`.)|
|[CMFCMenuBar::CalcFixedLayout](#calcfixedlayout)|Calcula o tamanho horizontal da barra de ferramentas. (Substitui [CMFCToolBar:: CalcFixedLayout](../../mfc/reference/cmfctoolbar-class.md#calcfixedlayout).)|
|[CMFCMenuBar::CalcLayout](#calclayout)|(Substitui `CMFCToolBar::CalcLayout`.)|
|[CMFCMenuBar::CalcMaxButtonHeight](#calcmaxbuttonheight)|Calcula a altura máxima dos botões na barra de ferramentas. (Substitui [CMFCToolBar:: CalcMaxButtonHeight](../../mfc/reference/cmfctoolbar-class.md#calcmaxbuttonheight).)|
|[CMFCMenuBar::CanBeClosed](#canbeclosed)|Especifica se um usuário pode fechar a barra de ferramentas. (Substitui [CMFCToolBar:: CanBeClosed](../../mfc/reference/cmfctoolbar-class.md#canbeclosed).)|
|[CMFCMenuBar::CanBeRestored](#canberestored)|Determina se o sistema pode restaurar uma barra de ferramentas para seu estado original após a personalização. (Substitui [CMFCToolBar:: CanBeRestored](../../mfc/reference/cmfctoolbar-class.md#canberestored).)|
|[CMFCMenuBar:: criar](#create)|Cria um controle de menu e o anexa a um objeto `CMFCMenuBar`.|
|[CMFCMenuBar::CreateEx](#createex)|Cria um objeto `CMFCMenuBar` com opções de estilo adicionais.|
|[CMFCMenuBar::CreateFromMenu](#createfrommenu)|Inicializa um objeto `CMFCMenuBar`. Aceita um parâmetro HMENU que atua como um modelo para um `CMFCMenuBar`populado.|
|[CMFCMenuBar::EnableHelpCombobox](#enablehelpcombobox)|Habilita uma caixa de combinação de **ajuda** que está localizada no lado direito da barra de menus.|
|[CMFCMenuBar::EnableMenuShadows](#enablemenushadows)|Especifica se as sombras dos menus pop-up devem ser exibidas.|
|[CMFCMenuBar::GetAvailableExpandSize](#getavailableexpandsize)|(Substitui [CPane:: GetAvailableExpandSize](../../mfc/reference/cpane-class.md#getavailableexpandsize).)|
|[CMFCMenuBar::GetColumnWidth](#getcolumnwidth)|Retorna a largura dos botões da barra de ferramentas. (Substitui [CMFCToolBar:: GetColumnWidth](../../mfc/reference/cmfctoolbar-class.md#getcolumnwidth).)|
|[CMFCMenuBar::GetDefaultMenu](#getdefaultmenu)|Retorna um identificador para o menu original no arquivo de recurso.|
|[CMFCMenuBar::GetDefaultMenuResId](#getdefaultmenuresid)|Retorna o identificador de recurso do menu original no arquivo de recurso.|
|[CMFCMenuBar::GetFloatPopupDirection](#getfloatpopupdirection)||
|[CMFCMenuBar::GetForceDownArrows](#getforcedownarrows)||
|[CMFCMenuBar::GetHelpCombobox](#gethelpcombobox)|Retorna um ponteiro para a caixa de combinação de **ajuda** .|
|[CMFCMenuBar::GetHMenu](#gethmenu)|Retorna o identificador para o menu que é anexado ao objeto `CMFCMenuBar`.|
|[CMFCMenuBar::GetMenuFont](#getmenufont)|Retorna a fonte global atual para objetos de menu.|
|[CMFCMenuBar:: getmenuitem](#getmenuitem)|Retorna o botão da barra de ferramentas associado ao índice de item fornecido.|
|[CMFCMenuBar:: getalturadalinha](#getrowheight)|Retorna a altura dos botões da barra de ferramentas. (Substitui [CMFCToolBar:: getalturadalinha](../../mfc/reference/cmfctoolbar-class.md#getrowheight).)|
|[CMFCMenuBar::GetSystemButton](#getsystembutton)||
|[CMFCMenuBar::GetSystemButtonsCount](#getsystembuttonscount)||
|[CMFCMenuBar::GetSystemMenu](#getsystemmenu)||
|[CMFCMenuBar::HighlightDisabledItems](#highlightdisableditems)|Indica se os itens de menu desabilitados são realçados.|
|[CMFCMenuBar::IsButtonExtraSizeAvailable](#isbuttonextrasizeavailable)|Determina se a barra de ferramentas pode exibir botões com bordas estendidas. (Substitui [CMFCToolBar:: IsButtonExtraSizeAvailable](../../mfc/reference/cmfctoolbar-class.md#isbuttonextrasizeavailable).)|
|[CMFCMenuBar::IsHighlightDisabledItems](#ishighlightdisableditems)|Indica se os itens desabilitados são realçados.|
|[CMFCMenuBar::IsMenuShadows](#ismenushadows)|Indica se as sombras são desenhadas para menus pop-up.|
|[CMFCMenuBar::IsRecentlyUsedMenus](#isrecentlyusedmenus)|Indica se os comandos de menu usados recentemente são exibidos na barra de menus.|
|[CMFCMenuBar::IsShowAllCommands](#isshowallcommands)|Indica se os menus pop-up exibem todos os comandos.|
|[CMFCMenuBar::IsShowAllCommandsDelay](#isshowallcommandsdelay)|Indica se os menus exibem todos os comandos após um pequeno atraso.|
|[CMFCMenuBar:: LoadState](#loadstate)|Carrega o estado do objeto de `CMFCMenuBar` do registro.|
|[CMFCMenuBar::OnChangeHot](#onchangehot)|Chamado pelo Framework quando um usuário seleciona um botão na barra de ferramentas. (Substitui [CMFCToolBar:: OnChangeHot](../../mfc/reference/cmfctoolbar-class.md#onchangehot).)|
|[CMFCMenuBar::OnDefaultMenuLoaded](#ondefaultmenuloaded)|Chamado pelo Framework quando uma janela do quadro carrega o menu padrão do arquivo de recurso.|
|[CMFCMenuBar::OnSendCommand](#onsendcommand)|(Substitui `CMFCToolBar::OnSendCommand`.)|
|[CMFCMenuBar::OnSetDefaultButtonText](#onsetdefaultbuttontext)|Chamado pelo Framework quando um menu está no modo de personalização e o usuário altera o texto de um item de menu.|
|[CMFCMenuBar::OnToolHitTest](#ontoolhittest)|(Substitui `CMFCToolBar::OnToolHitTest`.)|
|[CMFCMenuBar::P reTranslateMessage](#pretranslatemessage)|(Substitui `CMFCToolBar::PreTranslateMessage`.)|
|[CMFCMenuBar::RestoreOriginalstate](#restoreoriginalstate)|Chamado pelo Framework quando um menu está no modo de personalização e o usuário seleciona **Redefinir** para uma barra de menus.|
|[CMFCMenuBar:: SaveState](#savestate)|Salva o estado do objeto `CMFCMenuBar` no registro.|
|[CMFCMenuBar::SetDefaultMenuResId](#setdefaultmenuresid)|Define o menu original no arquivo de recurso.|
|[CMFCMenuBar::SetForceDownArrows](#setforcedownarrows)||
|[CMFCMenuBar:: setmaximmode](#setmaximizemode)|Chamado pelo Framework quando uma janela filho MDI altera seu modo de exibição. Se a janela filho MDI for recentemente maximizada ou não for mais maximizada, esse método atualizará a barra de menus.|
|[CMFCMenuBar::SetMenuButtonRTC](#setmenubuttonrtc)|Define as informações de classe de tempo de execução que são geradas quando o usuário cria botões de menu dinamicamente.|
|[CMFCMenuBar::SetMenuFont](#setmenufont)|Define a fonte de todos os menus no aplicativo.|
|[CMFCMenuBar::SetRecentlyUsedMenus](#setrecentlyusedmenus)|Especifica se uma barra de menus exibe comandos de menu usados recentemente.|
|[CMFCMenuBar::SetShowAllCommands](#setshowallcommands)|Especifica se a barra de menus mostra todos os comandos.|

## <a name="remarks"></a>Comentários

A classe `CMFCMenuBar` é uma barra de menus que implementa a funcionalidade de encaixe. Ele é semelhante a uma barra de ferramentas, embora não possa ser fechado; ele é sempre exibido.

`CMFCMenuBar` dá suporte à opção de exibir objetos de item de menu usados recentemente. Se essa opção estiver habilitada, a `CMFCMenuBar` exibirá apenas um subconjunto dos comandos disponíveis na primeira exibição. Depois disso, os comandos usados recentemente são exibidos junto com o subconjunto original de comandos. Além disso, o usuário sempre pode expandir o menu para exibir todos os comandos disponíveis. Assim, cada comando disponível é configurado para exibir constantemente, ou para exibir somente se ele tiver sido selecionado recentemente.

Para usar um objeto `CMFCMenuBar`, incorpore-o no objeto quadro da janela principal. Ao processar a mensagem de `WM_CREATE`, chame `CMFCMenuBar::Create` ou `CMFCMenuBar::CreateEx`. Independentemente da função de criação que você usar, passe um ponteiro para a janela do quadro principal. Em seguida, habilite o encaixe chamando [CFrameWndEx:: EnableDocking](../../mfc/reference/cframewndex-class.md#enabledocking). Encaixe esse menu chamando [CFrameWndEx::D ockpane](../../mfc/reference/cframewndex-class.md#dockpane).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar vários métodos na classe `CMFCMenuBar`. O exemplo mostra como definir o estilo do painel, habilitar o botão Personalizar, habilitar uma caixa de ajuda, habilitar sombras para menus pop-up e atualizar a barra de menus. Este trecho de código faz parte do [exemplo de demonstração do IE](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_IEDemo#1](../../mfc/reference/codesnippet/cpp/cmfcmenubar-class_1.h)]
[!code-cpp[NVC_MFC_IEDemo#3](../../mfc/reference/codesnippet/cpp/cmfcmenubar-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CBasePane](../../mfc/reference/cbasepane-class.md)

[CPane](../../mfc/reference/cpane-class.md)

[CMFCBaseToolBar](../../mfc/reference/cmfcbasetoolbar-class.md)

[CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)

`CMFCMenuBar`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmenubar. h

##  <a name="adjustlocations"></a>CMFCMenuBar::AdjustLocations

Ajusta as posições dos itens de menu na barra de menus.

```
virtual void AdjustLocations();
```

### <a name="remarks"></a>Comentários

##  <a name="allowchangetextlabels"></a>CMFCMenuBar::AllowChangeTextLabels

Determina se os rótulos de texto são permitidos em imagens na barra de menus.

```
virtual BOOL AllowChangeTextLabels() const;
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o usuário pode optar por Mostrar rótulos de texto em imagens.

### <a name="remarks"></a>Comentários

##  <a name="allowshowonpanemenu"></a>CMFCMenuBar::AllowShowOnPaneMenu

```
virtual BOOL AllowShowOnPaneMenu() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

##  <a name="calcfixedlayout"></a>CMFCMenuBar::CalcFixedLayout

```
virtual CSize CalcFixedLayout(
    BOOL bStretch,
    BOOL bHorz);
```

### <a name="parameters"></a>parâmetros

no *bStretch*<br/>

no *bHorz*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

##  <a name="calclayout"></a>CMFCMenuBar::CalcLayout

```
virtual CSize CalcLayout(
    DWORD dwMode,
    int nLength = -1);
```

### <a name="parameters"></a>parâmetros

no *dwMode*<br/>

no *nLength*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

##  <a name="calcmaxbuttonheight"></a>CMFCMenuBar::CalcMaxButtonHeight

```
virtual int CalcMaxButtonHeight();
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

##  <a name="canbeclosed"></a>CMFCMenuBar::CanBeClosed

```
virtual BOOL CanBeClosed() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

##  <a name="canberestored"></a>CMFCMenuBar::CanBeRestored

```
virtual BOOL CanBeRestored() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

##  <a name="create"></a>CMFCMenuBar:: criar

Cria um controle de menu e o anexa a um objeto [CMFCMenuBar](../../mfc/reference/cmfcmenubar-class.md) .

```
virtual BOOL Create(
    CWnd* pParentWnd,
    DWORD dwStyle = AFX_DEFAULT_TOOLBAR_STYLE,
    UINT nID = AFX_IDW_MENUBAR);
```

### <a name="parameters"></a>parâmetros

*pParentWnd*<br/>
no Ponteiro para a janela pai do novo objeto `CMFCMenuBar`.

*dwStyle*<br/>
no O estilo da nova barra de menus.

*nID*<br/>
no A ID da janela filho da barra de menus.

### <a name="return-value"></a>Valor retornado

Verdadeiro se for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Depois de construir um objeto de `CMFCMenuBar`, você deve chamar `Create`. Esse método cria o controle de `CMFCMenuBar` e o anexa ao objeto `CMFCMenuBar`.

Para obter mais informações sobre estilos de barra de ferramentas, consulte [CBasePane:: SetPaneStyle](../../mfc/reference/cbasepane-class.md#setpanestyle).

##  <a name="createex"></a>CMFCMenuBar::CreateEx

Cria um objeto [CMFCMenuBar](../../mfc/reference/cmfcmenubar-class.md) com os estilos estendidos especificados.

```
virtual BOOL CreateEx(
    CWnd* pParentWnd,
    DWORD dwCtrlStyle = TBSTYLE_FLAT,
    DWORD dwStyle = AFX_DEFAULT_TOOLBAR_STYLE,
    CRect rcBorders = CRect(1,
    1,
    1,
    1),
    UINT nID =AFX_IDW_MENUBAR);
```

### <a name="parameters"></a>parâmetros

*pParentWnd*<br/>
no Ponteiro para a janela pai do novo objeto de `CMFCMenuBar`.

*dwCtrlStyle*<br/>
no Estilos adicionais para a nova barra de menus.

*dwStyle*<br/>
no O estilo principal da nova barra de menus.

*rcBorders*<br/>
no Um parâmetro `CRect` que especifica os tamanhos das bordas do objeto `CMFCMenuBar`.

*nID*<br/>
no A ID da janela filho da barra de menus.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o método for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você deve usar essa função em vez de [CMFCMenuBar:: Create](#create) quando desejar especificar estilos além do estilo da barra de ferramentas. Alguns estilos adicionais usados com frequência são TBSTYLE_TRANSPARENT e CBRS_TOP.

Para obter listas de estilos adicionais, consulte [controle da barra de ferramentas e estilos de botão](/windows/win32/Controls/toolbar-control-and-button-styles), [estilos comuns de controle](/windows/win32/Controls/common-control-styles)e estilos de [janela comuns](/windows/win32/winmsg/window-styles).

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar o método `CreateEx` da classe `CMFCMenuBar`. Este trecho de código faz parte do [exemplo de demonstração do IE](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_IEDemo#1](../../mfc/reference/codesnippet/cpp/cmfcmenubar-class_1.h)]
[!code-cpp[NVC_MFC_IEDemo#2](../../mfc/reference/codesnippet/cpp/cmfcmenubar-class_3.cpp)]

##  <a name="createfrommenu"></a>CMFCMenuBar::CreateFromMenu

Inicializa um objeto [CMFCMenuBar](../../mfc/reference/cmfcmenubar-class.md) . Esse método modela o objeto `CMFCMenuBar` após um parâmetro HMENU.

```
virtual void CreateFromMenu(
    HMENU hMenu,
    BOOL bDefaultMenu = FALSE,
    BOOL bForceUpdate = FALSE);
```

### <a name="parameters"></a>parâmetros

*hMenu*<br/>
no Um identificador para um recurso de menu. `CreateFromMenu` usa esse recurso como um modelo para o `CMFCMenuBar`.

*bDefaultMenu*<br/>
no Um booliano que indica se o novo menu é o menu padrão.

*bForceUpdate*<br/>
no Um booliano que indica se esse método força uma atualização de menu.

### <a name="remarks"></a>Comentários

Use esse método se desejar que um controle de menu tenha os mesmos itens de menu que um recurso de menu. Você chama esse método depois de chamar [CMFCMenuBar:: Create](#create) ou [CMFCMenuBar:: CreateEx](#createex).

##  <a name="enablehelpcombobox"></a>CMFCMenuBar::EnableHelpCombobox

Habilita uma caixa de combinação de **ajuda** que está localizada no lado direito da barra de menus.

```
void EnableHelpCombobox(
    UINT uiID,
    LPCTSTR lpszPrompt = NULL,
    int nComboBoxWidth = 150);
```

### <a name="parameters"></a>parâmetros

*uiID*<br/>
no A ID de comando para o botão da caixa de combinação de **ajuda** .

*lpszPrompt*<br/>
no Uma cadeia de caracteres que contém o texto que a estrutura exibe na caixa de combinação, se estiver vazia e não ativa. Por exemplo, "Insira o texto aqui".

*nComboBoxWidth*<br/>
no A largura do botão da caixa de combinação em pixels.

### <a name="remarks"></a>Comentários

A caixa de combinação **ajuda** é semelhante à caixa de combinação **ajuda** na barra de menus do Microsoft Word.

Quando você chama esse método com *uiID* definido como 0, esse método oculta a caixa de combinação. Caso contrário, esse método exibirá a caixa de combinação automaticamente no lado direito da barra de menus. Depois de chamar esse método, chame [CMFCMenuBar:: GetHelpCombobox](#gethelpcombobox) para obter um ponteiro para o objeto [CMFCToolBarComboBoxButton](../../mfc/reference/cmfctoolbarcomboboxbutton-class.md) inserido.

##  <a name="enablemenushadows"></a>CMFCMenuBar::EnableMenuShadows

Habilita sombras para menus pop-up.

```
static void EnableMenuShadows(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>parâmetros

*bEnable*<br/>
no Um parâmetro booliano que indica se as sombras devem ser habilitadas para menus pop-up.

### <a name="remarks"></a>Comentários

O algoritmo usado por esse método é complexo e pode diminuir o desempenho do seu aplicativo em sistemas mais lentos.

##  <a name="getavailableexpandsize"></a>CMFCMenuBar::GetAvailableExpandSize

```
virtual int GetAvailableExpandSize() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

##  <a name="getcolumnwidth"></a>CMFCMenuBar::GetColumnWidth

```
virtual int GetColumnWidth() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

##  <a name="getdefaultmenu"></a>CMFCMenuBar::GetDefaultMenu

Recupera um identificador para o menu original. A estrutura carrega o menu original do arquivo de recursos.

```
HMENU GetDefaultMenu() const;
```

### <a name="return-value"></a>Valor retornado

Um identificador para um recurso de menu.

### <a name="remarks"></a>Comentários

Se seu aplicativo personalizar um menu, você poderá usar esse método para recuperar um identificador para o menu original.

##  <a name="getdefaultmenuresid"></a>CMFCMenuBar::GetDefaultMenuResId

Recupera o identificador de recurso para o menu padrão.

```
UINT GetDefaultMenuResId() const;
```

### <a name="return-value"></a>Valor retornado

Um identificador de recurso de menu.

### <a name="remarks"></a>Comentários

A estrutura carrega o menu padrão para o objeto de `CMFCMenuBar` do arquivo de recurso.

##  <a name="getfloatpopupdirection"></a>CMFCMenuBar::GetFloatPopupDirection

```
int GetFloatPopupDirection(CMFCToolBarMenuButton* pButton);
```

### <a name="parameters"></a>parâmetros

no *pButton*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

##  <a name="getforcedownarrows"></a>CMFCMenuBar::GetForceDownArrows

```
BOOL GetForceDownArrows();
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

##  <a name="gethelpcombobox"></a>CMFCMenuBar::GetHelpCombobox

Retorna um ponteiro para a caixa de combinação de **ajuda** .

```
CMFCToolBarComboBoxButton* GetHelpCombobox();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a caixa de combinação de **ajuda** . NULL se a caixa de combinação de **ajuda** estiver oculta ou não estiver habilitada.

### <a name="remarks"></a>Comentários

A caixa de combinação **ajuda** está localizada no lado direito da barra de menus. Chame o método [CMFCMenuBar:: EnableHelpCombobox](#enablehelpcombobox) para habilitar essa caixa de combinação.

##  <a name="gethmenu"></a>CMFCMenuBar::GetHMenu

Recupera o identificador para o menu anexado ao objeto [CMFCMenuBar](../../mfc/reference/cmfcmenubar-class.md) .

```
HMENU GetHMenu() const;
```

##  <a name="getmenufont"></a>CMFCMenuBar::GetMenuFont

Recupera a fonte do menu atual.

```
static const CFont& GetMenuFont(BOOL bHorz = TRUE);
```

### <a name="parameters"></a>parâmetros

*bHorz*<br/>
no Um parâmetro booliano que especifica se a fonte horizontal ou vertical deve ser retornada. VERDADEIRO indica a fonte horizontal.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um parâmetro [CFont](../../mfc/reference/cfont-class.md) que contém a fonte da barra de menus atual.

### <a name="remarks"></a>Comentários

A fonte retornada é um parâmetro global para o aplicativo. Duas fontes globais são mantidas para todos os objetos de `CMFCMenuBar`. Essas fontes separadas são usadas para barras de menu horizontais e verticais.

##  <a name="getmenuitem"></a>CMFCMenuBar:: getmenuitem

Recupera um objeto [CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md) em uma barra de menus com base no índice do item.

```
CMFCToolBarButton* GetMenuItem(int iItem) const;
```

### <a name="parameters"></a>parâmetros

*iItem*<br/>
no O índice do item de menu a ser retornado.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto `CMFCToolBarButton` que corresponde ao índice especificado por *iItem*. NULL se o índice for inválido.

##  <a name="getrowheight"></a>CMFCMenuBar:: getalturadalinha

```
virtual int GetRowHeight() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

##  <a name="getsystembutton"></a>CMFCMenuBar::GetSystemButton

```
CMFCToolBarMenuButtonsButton* GetSystemButton(
    UINT uiBtn,
    BOOL bByCommand = TRUE) const;
```

### <a name="parameters"></a>parâmetros

no *uiBtn*<br/>

no *bByCommand*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

##  <a name="getsystembuttonscount"></a>CMFCMenuBar::GetSystemButtonsCount

```
int GetSystemButtonsCount() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

##  <a name="getsystemmenu"></a>CMFCMenuBar::GetSystemMenu

```
CMFCToolBarSystemMenuButton* GetSystemMenu() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

##  <a name="highlightdisableditems"></a>CMFCMenuBar::HighlightDisabledItems

Controla se a estrutura realça os itens de menu desabilitados.

```
static void HighlightDisabledItems(BOOL bHighlight = TRUE);
```

### <a name="parameters"></a>parâmetros

*bHighlight*<br/>
no Um parâmetro booliano que indica se a estrutura realça itens de menu indisponíveis.

### <a name="remarks"></a>Comentários

Por padrão, a estrutura não realça itens de menu indisponíveis quando o usuário posiciona o ponteiro do mouse sobre eles.

##  <a name="isbuttonextrasizeavailable"></a>CMFCMenuBar::IsButtonExtraSizeAvailable

```
virtual BOOL IsButtonExtraSizeAvailable() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

##  <a name="ishighlightdisableditems"></a>CMFCMenuBar::IsHighlightDisabledItems

Indica se a estrutura realça os itens de menu indisponíveis.

```
static BOOL IsHighlightDisabledItems();
```

### <a name="return-value"></a>Valor retornado

TRUE se os itens de menu não disponíveis forem realçados; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Por padrão, a estrutura não realça itens de menu indisponíveis quando o usuário posiciona o ponteiro do mouse sobre eles. Use o método [CMFCMenuBar:: HighlightDisabledItems](#highlightdisableditems) para habilitar esse recurso.

##  <a name="ismenushadows"></a>CMFCMenuBar::IsMenuShadows

Indica se a estrutura desenha sombras para menus pop-up.

```
static BOOL IsMenuShadows();
```

### <a name="return-value"></a>Valor retornado

TRUE se a estrutura desenhar o menu Shadows; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use o método [CMFCMenuBar:: EnableMenuShadows](#enablemenushadows) para habilitar ou desabilitar esse recurso.

##  <a name="isrecentlyusedmenus"></a>CMFCMenuBar::IsRecentlyUsedMenus

Indica se os comandos de menu usados recentemente são exibidos na barra de menus.

```
static BOOL IsRecentlyUsedMenus();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o objeto de `CMFCMenuBar` mostrar comandos de menu usados recentemente; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use a função [CMFCMenuBar:: SetRecentlyUsedMenus](#setrecentlyusedmenus) para controlar se a barra de menus mostra os comandos de menu usados recentemente.

##  <a name="isshowallcommands"></a>CMFCMenuBar::IsShowAllCommands

Indica se os menus exibem todos os comandos.

```
static BOOL IsShowAllCommands();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o `CMFCMenuBar` exibir todos os comandos; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um objeto `CMFCMenuBar` pode ser configurado para mostrar todos os comandos ou mostrar apenas um subconjunto de comandos. Para obter mais informações sobre esse recurso, consulte [Classe CMFCMenuBar](../../mfc/reference/cmfcmenubar-class.md).

`IsShowAllCommands` lhe dirá como esse recurso está configurado para o objeto `CMFCMenuBar`. Para controlar quais comandos de menu são mostrados, use os métodos [CMFCMenuBar:: SetShowAllCommands](#setshowallcommands) e [CMFCMenuBar:: SetRecentlyUsedMenus](#setrecentlyusedmenus).

##  <a name="isshowallcommandsdelay"></a>CMFCMenuBar::IsShowAllCommandsDelay

Indica se o objeto [CMFCMenuBar](../../mfc/reference/cmfcmenubar-class.md) exibe todos os comandos após um pequeno atraso.

```
static BOOL IsShowAllCommandsDelay();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se a barra de menus exibir menus completos após um pequeno atraso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Quando você configura uma barra de menus para exibir itens usados recentemente, a barra de menus exibe o menu completo de uma das duas maneiras:

- Exibe o menu completo após um atraso programado de quando o usuário passa o cursor sobre a seta na parte inferior do menu.

- Exiba o menu completo depois que o usuário clicar na seta na parte inferior do menu.

Por padrão, todos os objetos de `CMFCMenuBar` usam a opção para exibir o menu completo após um pequeno atraso. Essa opção não pode ser alterada programaticamente na classe `CMFCMenuBar`. No entanto, um usuário pode alterar o comportamento durante a personalização da barra de ferramentas usando a caixa de diálogo **Personalizar** .

##  <a name="loadstate"></a>CMFCMenuBar:: LoadState

Carrega o estado da barra de menus do registro do Windows.

```
virtual BOOL LoadState(
    LPCTSTR lpszProfileName = NULL,
    int nIndex = -1,
    UINT uiID = (UINT)-1);
```

### <a name="parameters"></a>parâmetros

*lpszProfileName*<br/>
no Uma cadeia de caracteres que contém o caminho de uma chave do registro do Windows.

*nIndex*<br/>
no A ID de controle da barra de menus.

*uiID*<br/>
no Um valor reservado.

### <a name="return-value"></a>Valor retornado

TRUE se o método foi bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use o método [CMFCMenuBar:: SaveState](#savestate) para salvar o estado da barra de menus no registro. As informações salvas incluem os itens de menu, o estado de encaixe e a posição da barra de menus.

Na maioria dos casos, seu aplicativo não chama `LoadState`. A estrutura chama esse método quando Inicializa o espaço de trabalho.

##  <a name="onchangehot"></a>CMFCMenuBar::OnChangeHot

```
virtual void OnChangeHot(int iHot);
```

### <a name="parameters"></a>parâmetros

no *iHot*<br/>

### <a name="remarks"></a>Comentários

##  <a name="ondefaultmenuloaded"></a>CMFCMenuBar::OnDefaultMenuLoaded

A estrutura chama esse método quando ele carrega o recurso de menu do arquivo de recurso.

```
virtual void OnDefaultMenuLoaded(HMENU hMenu);
```

### <a name="parameters"></a>parâmetros

*hMenu*<br/>
no O identificador do menu anexado ao objeto `CMFCMenuBar`.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função não faz nada. Substitua essa função para executar o código personalizado depois que o Framework carregar um recurso de menu do arquivo de recurso.

##  <a name="onsendcommand"></a>CMFCMenuBar::OnSendCommand

```
virtual BOOL OnSendCommand(const CMFCToolBarButton* pButton);
```

### <a name="parameters"></a>parâmetros

no *pButton*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

##  <a name="onsetdefaultbuttontext"></a>CMFCMenuBar::OnSetDefaultButtonText

A estrutura chama esse método quando o usuário altera o texto de um item na barra de menus.

```
virtual BOOL OnSetDefaultButtonText(CMFCToolBarButton* pButton);
```

### <a name="parameters"></a>parâmetros

*pButton*<br/>
no Um ponteiro para o objeto [CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md) que o usuário deseja personalizar.

### <a name="return-value"></a>Valor retornado

TRUE se a estrutura aplicar as alterações de usuário à barra de menus; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A implementação padrão desse método altera o texto do botão para o texto que o usuário fornece.

##  <a name="ontoolhittest"></a>CMFCMenuBar::OnToolHitTest

```
virtual INT_PTR OnToolHitTest(
    CPoint point,
    TOOLINFO* pTI) const;
```

### <a name="parameters"></a>parâmetros

no *ponto*<br/>

no *PTI*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

##  <a name="pretranslatemessage"></a>CMFCMenuBar::P reTranslateMessage

```
virtual BOOL PreTranslateMessage(MSG* pMsg);
```

### <a name="parameters"></a>parâmetros

no *pMsg*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

##  <a name="restoreoriginalstate"></a>CMFCMenuBar::RestoreOriginalstate

Chamado pelo Framework quando o usuário seleciona **Redefinir** na caixa de diálogo **Personalizar** .

```
virtual BOOL RestoreOriginalstate();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o método for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método é chamado quando o usuário seleciona **Redefinir** no menu de personalização. Você também pode chamar manualmente esse método para redefinir programaticamente o estado da barra de menus. Esse método carrega o estado original do arquivo de recurso.

Substitua esse método se você quiser fazer qualquer processamento quando o usuário selecionar a opção de **redefinição** .

##  <a name="savestate"></a>CMFCMenuBar:: SaveState

Salva o estado do objeto [CMFCMenuBar](../../mfc/reference/cmfcmenubar-class.md) no registro do Windows.

```
virtual BOOL SaveState (
    LPCTSTR lpszProfileName = NULL,
    int nIndex = -1,
    UINT uiID = (UINT)-1);
```

### <a name="parameters"></a>parâmetros

*lpszProfileName*<br/>
no Uma cadeia de caracteres que contém o caminho de uma chave do registro do Windows.

*nIndex*<br/>
no A ID de controle da barra de menus.

*uiID*<br/>
no Um valor reservado.

### <a name="return-value"></a>Valor retornado

Verdadeiro se for bem-sucedido; caso contrário, FALSE;

### <a name="remarks"></a>Comentários

Normalmente, seu aplicativo não chama `SaveState`. A estrutura chama esse método quando o espaço de trabalho é serializado. Para obter mais informações, consulte [CWinAppEx:: SaveState](../../mfc/reference/cwinappex-class.md#savestate).

As informações salvas incluem os itens de menu, o estado de encaixe e a posição da barra de menus.

##  <a name="setdefaultmenuresid"></a>CMFCMenuBar::SetDefaultMenuResId

Define o menu padrão para um objeto [CMFCMenuBar](../../mfc/reference/cmfcmenubar-class.md) com base na ID do recurso.

```
void SetDefaultMenuResId(UINT uiResId);
```

### <a name="parameters"></a>parâmetros

*uiResId*<br/>
no A ID do recurso para o novo menu padrão.

### <a name="remarks"></a>Comentários

O método [CMFCMenuBar:: RestoreOriginalstate](#restoreoriginalstate) restaura o menu padrão do arquivo de recursos.

Use o método [CMFCMenuBar:: GetDefaultMenuResId](#getdefaultmenuresid) para recuperar o menu padrão sem restaurá-lo.

##  <a name="setforcedownarrows"></a>CMFCMenuBar::SetForceDownArrows

```
void SetForceDownArrows(BOOL bValue);
```

### <a name="parameters"></a>parâmetros

no *bValue*<br/>

### <a name="remarks"></a>Comentários

##  <a name="setmaximizemode"></a>CMFCMenuBar:: setmaximmode

A estrutura chama esse método quando um MDI altera seu modo de exibição e a barra de menus deve ser atualizada.

```
void SetMaximizeMode(
    BOOL bMax,
    CWnd* pWnd = NULL,
    BOOL bRecalcLayout = TRUE);
```

### <a name="parameters"></a>parâmetros

*bMax*<br/>
no Um booliano que especifica o modo. Para obter mais informações, consulte a seção Comentários.

*pWnd*<br/>
no Um ponteiro para a janela filho MDI que está sendo alterada.

*bRecalcLayout*<br/>
no Um booliano que especifica se o layout da barra de menus deve ser recalculado imediatamente.

### <a name="remarks"></a>Comentários

Quando uma janela filho MDI é maximizada, uma barra de menus anexada à janela do quadro principal MDI exibe o menu do sistema e os botões **minimizar**, **maximizar** e **Fechar** . Se *bMax* for true e *pWnd* não for NULL, a janela filho MDI será maximizada e a barra de menus deverá incorporar os controles adicionais. Caso contrário, a barra de menus retornará ao seu estado regular.

##  <a name="setmenubuttonrtc"></a>CMFCMenuBar::SetMenuButtonRTC

Define as informações de classe de tempo de execução que a estrutura usa quando o usuário cria botões de menu.

```
void SetMenuButtonRTC(CRuntimeClass* pMenuButtonRTC);
```

### <a name="parameters"></a>parâmetros

*pMenuButtonRTC*<br/>
no As informações de [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) para uma classe derivada da [Classe CMFCMenuButton](../../mfc/reference/cmfcmenubutton-class.md).

### <a name="remarks"></a>Comentários

Quando um usuário adiciona novos botões à barra de menus, a estrutura cria os botões dinamicamente. Por padrão, ele cria objetos de `CMFCMenuButton`. Substitua esse método para alterar o tipo de objetos de botão que a estrutura cria.

##  <a name="setmenufont"></a>CMFCMenuBar::SetMenuFont

Define a fonte de todas as barras de menu em seu aplicativo.

```
static BOOL SetMenuFont(
    LPLOGFONT lpLogFont,
    BOOL bHorz = TRUE);
```

### <a name="parameters"></a>parâmetros

*lpLogFont*<br/>
no Um ponteiro para uma estrutura [LOGFONT](/windows/win32/api/dimm/ns-dimm-logfonta) que define a fonte a ser definida.

*bHorz*<br/>
no TRUE se você quiser que o parâmetro *lpLogFont* seja usado para a fonte vertical, false se você quiser que ele seja usado para a fonte horizontal.

### <a name="return-value"></a>Valor retornado

TRUE se o método foi bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Duas fontes são usadas para todos os objetos de `CMFCMenuBar`. Essas fontes separadas são usadas para barras de menu horizontais e verticais.

As configurações de fonte são variáveis globais e afetam todos os objetos de `CMFCMenuBar`.

##  <a name="setrecentlyusedmenus"></a>CMFCMenuBar::SetRecentlyUsedMenus

Controla se uma barra de menus exibe comandos de menu usados recentemente.

```
static void SetRecentlyUsedMenus (BOOL bOn = TRUE);
```

### <a name="parameters"></a>parâmetros

*Bno*<br/>
no Um booliano que controla se os comandos de menu usados recentemente são exibidos.

##  <a name="setshowallcommands"></a>CMFCMenuBar::SetShowAllCommands

Controla se um menu mostra todos os comandos disponíveis.

```
static void SetShowAllCommands(BOOL bShowAllCommands = TRUE);
```

### <a name="parameters"></a>parâmetros

*bShowAllCommands*<br/>
no Um parâmetro booliano que especifica se o menu pop-up mostra todos os comandos de menu.

### <a name="remarks"></a>Comentários

Se um menu não exibir todos os comandos de menu, ele ocultará os comandos que raramente são usados. Para obter mais informações sobre como exibir comandos de menu, consulte [Classe CMFCMenuBar](../../mfc/reference/cmfcmenubar-class.md).

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)
