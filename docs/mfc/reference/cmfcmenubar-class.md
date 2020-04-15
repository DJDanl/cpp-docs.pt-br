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
ms.openlocfilehash: 50dd488d1f59c99b8fee1eb96acf6d0041547df9
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369697"
---
# <a name="cmfcmenubar-class"></a>Classe CMFCMenuBar

Uma barra de menu que implementa o encaixe.
Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

## <a name="syntax"></a>Sintaxe

```
class CMFCMenuBar : public CMFCToolbar
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCMenubar::Ajustar locais](#adjustlocations)|(Substitui `CMFCToolBar::AdjustLocations`.)|
|[CMFCMenuBar::Permitiralteraralterarrótulos de texto](#allowchangetextlabels)|Especifica se os rótulos de texto podem ser mostrados em imagens nos botões da barra de ferramentas. (Substitui [cmfctoolbar::AllowChangeTextLabels](../../mfc/reference/cmfctoolbar-class.md#allowchangetextlabels).)|
|[CMFCMenubar::AllowShowOnPaneMenu](#allowshowonpanemenu)|(Substitui `CPane::AllowShowOnPaneMenu`.)|
|[CMFCMenubar::CalcFixedLayout](#calcfixedlayout)|Calcula o tamanho horizontal da barra de ferramentas. (Substitui [cmfctoolbar::CalcFixedLayout](../../mfc/reference/cmfctoolbar-class.md#calcfixedlayout).)|
|[CMFCMenubar::CalcLayout](#calclayout)|(Substitui `CMFCToolBar::CalcLayout`.)|
|[CMFCMenubar::CalcMaxButtonHeight](#calcmaxbuttonheight)|Calcula a altura máxima dos botões na barra de ferramentas. (Substitui [cmfctoolbar::CalcMaxButtonHeight](../../mfc/reference/cmfctoolbar-class.md#calcmaxbuttonheight).)|
|[CMFCMenubar::CanBeClosed](#canbeclosed)|Especifica se um usuário pode fechar a barra de ferramentas. (Substitui [cmfctoolbar::CanBeClosed](../../mfc/reference/cmfctoolbar-class.md#canbeclosed).)|
|[CMFCMenubar::CanBeRestored](#canberestored)|Determina se o sistema pode restaurar uma barra de ferramentas ao seu estado original após a personalização. (Substitui [cmfctoolbar::CanBeRestored](../../mfc/reference/cmfctoolbar-class.md#canberestored).)|
|[CMFCMenubar::Criar](#create)|Cria um controle de menu `CMFCMenuBar` e o anexa a um objeto.|
|[CMFCMenubar::CreateEx](#createex)|Cria `CMFCMenuBar` um objeto com opções adicionais de estilo.|
|[CMFCMenubar::CreateFromMenu](#createfrommenu)|Inicializa um objeto `CMFCMenuBar`. Aceita um parâmetro HMENU que funciona como um `CMFCMenuBar`modelo para um povoado .|
|[CMFCMenuBar::HabilitarHelpCombobox](#enablehelpcombobox)|Habilita uma caixa de combinação **de ajuda** localizada no lado direito da barra de menu.|
|[CMFCMenubar::AtivarMenuSombras](#enablemenushadows)|Especifica se é exibido sombras para menus pop-up.|
|[CMFCMenubar::getAvailableExpandSize](#getavailableexpandsize)|(Substitui [cpane::GetAvailableExpandSize](../../mfc/reference/cpane-class.md#getavailableexpandsize).)|
|[CMFCMenubar::obterlargura da coluna](#getcolumnwidth)|Retorna a largura dos botões da barra de ferramentas. (Substitui [cmfctoolbar:getColumnWidth](../../mfc/reference/cmfctoolbar-class.md#getcolumnwidth).)|
|[CMFCMenubar::GetDefaultMenu](#getdefaultmenu)|Retorna uma alça para o menu original no arquivo de recursos.|
|[CMFCMenubar::GetDefaultMenuResId](#getdefaultmenuresid)|Retorna o identificador de recursos para o menu original no arquivo de recursos.|
|[CMFCMenubar::GetFloatPopupDirection](#getfloatpopupdirection)||
|[CMFCMenubar::GetForceDownArrows](#getforcedownarrows)||
|[CMFCMenubar::GetHelpCombobox](#gethelpcombobox)|Retorna um ponteiro para a caixa de combinação **Ajuda.**|
|[CMFCMenubar::getHmenu](#gethmenu)|Retorna a alça ao menu anexado `CMFCMenuBar` ao objeto.|
|[CMFCMenubar::getMenufont](#getmenufont)|Retorna a fonte global atual para objetos de menu.|
|[CMFCMenubar::GetMenuItem](#getmenuitem)|Retorna o botão da barra de ferramentas associado ao índice de itens fornecido.|
|[CMFCMenubar::GetrowHeight](#getrowheight)|Retorna a altura dos botões da barra de ferramentas. (Substitui [cmfctoolbar::GetRowHeight](../../mfc/reference/cmfctoolbar-class.md#getrowheight).)|
|[CMFCMenubar::GetSystemButton](#getsystembutton)||
|[CMFCMenubar::GetSystemButtonsCount](#getsystembuttonscount)||
|[CMFCMenubar::GetSystemMenu](#getsystemmenu)||
|[CMFCMenubar::DestaqueItens desativados](#highlightdisableditems)|Indica se os itens do menu desativado saem destacados.|
|[CMFCMenubar::isbuttonExtrasizeAvailable](#isbuttonextrasizeavailable)|Determina se a barra de ferramentas pode exibir botões com bordas estendidas. (Substitui [cmfctoolbar::IsButtonExtraSizeAvailable](../../mfc/reference/cmfctoolbar-class.md#isbuttonextrasizeavailable).)|
|[CMFCMenubar::IsHighlightDisabledItems](#ishighlightdisableditems)|Indica se os itens desativados são destacados.|
|[CMFCMenubar::IsMenuShadows](#ismenushadows)|Indica se as sombras são desenhadas para menus pop-up.|
|[CMFCMenubar::ÉRecentementeUsadoMenus](#isrecentlyusedmenus)|Indica se os comandos de menu usados recentemente são exibidos na barra de menus.|
|[CMFCMenubar::IsShowAllCommands](#isshowallcommands)|Indica se os menus pop-up exibem todos os comandos.|
|[CMFCMenubar::IsShowAllCommandsDelay](#isshowallcommandsdelay)|Indica se os menus exibem todos os comandos após um curto atraso.|
|[CMFCMenubar::LoadState](#loadstate)|Carrega o estado `CMFCMenuBar` do objeto do registro.|
|[CMFCMenubar::OnChangeHot](#onchangehot)|Chamado pela estrutura quando um usuário seleciona um botão na barra de ferramentas. (Substitui [cmfctoolbar::OnChangeHot](../../mfc/reference/cmfctoolbar-class.md#onchangehot).)|
|[CMFCMenubar:OnDefaultMenuLoaded](#ondefaultmenuloaded)|Chamado pela estrutura quando uma janela de quadro carrega o menu padrão do arquivo de recursos.|
|[CMFCMenubar::OnSendCommand](#onsendcommand)|(Substitui `CMFCToolBar::OnSendCommand`.)|
|[CMFCMenubar::Início de inícioTexto de botão de serviço](#onsetdefaultbuttontext)|Chamado pela estrutura quando um menu está no modo de personalização e o usuário altera o texto de um item do menu.|
|[CMFCMenubar::OntoolHitTest](#ontoolhittest)|(Substitui `CMFCToolBar::OnToolHitTest`.)|
|[CMFCMenuBar::PreTraduzirmensagem](#pretranslatemessage)|(Substitui `CMFCToolBar::PreTranslateMessage`.)|
|[CMFCMenuBar::RestaurarEstado original](#restoreoriginalstate)|Chamado pela estrutura quando um menu está no modo de personalização e o usuário seleciona **Redefinir** para uma barra de menu.|
|[CMFCMenubar::SaveState](#savestate)|Salva o estado `CMFCMenuBar` do objeto para o registro.|
|[CMFCMenubar:SetDefaultMenuResId](#setdefaultmenuresid)|Define o menu original no arquivo de recursos.|
|[CMFCMenubar::SetForceDownArrows](#setforcedownarrows)||
|[CMFCMenubar::SetMaximizeMode](#setmaximizemode)|Chamado pela estrutura quando uma janela de criança MDI muda seu modo de exibição. Se a janela de criança MDI for recém-maximizada ou não for mais maximizada, este método atualizará a barra de menu.|
|[CMFCMenubar::setMenuButtonRTC](#setmenubuttonrtc)|Define as informações de classe de tempo de execução geradas quando o usuário cria dinamicamente botões de menu.|
|[CMFCMenubar::setMenufont](#setmenufont)|Define a fonte para todos os menus do aplicativo.|
|[CMFCMenubar::SetRecentlyUsedMenus](#setrecentlyusedmenus)|Especifica se uma barra de menu exibe comandos de menu usados recentemente.|
|[CMFCMenubar::SetShowAllCommands](#setshowallcommands)|Especifica se a barra de menu mostra todos os comandos.|

## <a name="remarks"></a>Comentários

A `CMFCMenuBar` classe é uma barra de menu que implementa a funcionalidade de acoplamento. Ele se assemelha a uma barra de ferramentas, embora não possa ser fechado - é sempre exibido.

`CMFCMenuBar`suporta a opção de exibir objetos de menu usados recentemente. Se essa opção estiver `CMFCMenuBar` ativada, o exibirá apenas um subconjunto dos comandos disponíveis na primeira visualização. Depois disso, os comandos usados recentemente são exibidos juntamente com o subconjunto original de comandos. Além disso, o usuário pode sempre expandir o menu para visualizar todos os comandos disponíveis. Assim, cada comando disponível é configurado para exibir constantemente, ou para exibir somente se tiver sido selecionado recentemente.

Para usar `CMFCMenuBar` um objeto, incorpore-o no objeto da moldura da janela principal. Ao processar `WM_CREATE` a mensagem, ligue `CMFCMenuBar::Create` ou `CMFCMenuBar::CreateEx`. Independentemente de qual função de criação você usa, passe em um ponteiro para a janela do quadro principal. Em seguida, habilite o encaixe chamando [CFrameWndEx::EnableDocking](../../mfc/reference/cframewndex-class.md#enabledocking). Acoplá-lo ao ligar para [CFrameWndEx::DockPane](../../mfc/reference/cframewndex-class.md#dockpane).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCMenuBar` usar vários métodos na classe. O exemplo mostra como definir o estilo do painel, ativar o botão personalizar, ativar uma caixa de ajuda, ativar sombras para menus pop-up e atualizar a barra de menus. Este trecho de código faz parte da [amostra ie demo](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_IEDemo#1](../../mfc/reference/codesnippet/cpp/cmfcmenubar-class_1.h)]
[!code-cpp[NVC_MFC_IEDemo#3](../../mfc/reference/codesnippet/cpp/cmfcmenubar-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cbasepane](../../mfc/reference/cbasepane-class.md)

[Cpane](../../mfc/reference/cpane-class.md)

[CMFCBaseToolBar](../../mfc/reference/cmfcbasetoolbar-class.md)

[Cmfctoolbar](../../mfc/reference/cmfctoolbar-class.md)

`CMFCMenuBar`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmenubar.h

## <a name="cmfcmenubaradjustlocations"></a><a name="adjustlocations"></a>CMFCMenubar::Ajustar locais

Ajusta as posições dos itens do menu na barra de menu.

```
virtual void AdjustLocations();
```

### <a name="remarks"></a>Comentários

## <a name="cmfcmenubarallowchangetextlabels"></a><a name="allowchangetextlabels"></a>CMFCMenuBar::Permitiralteraralterarrótulos de texto

Determina se os rótulos de texto são permitidos em imagens na barra de menu.

```
virtual BOOL AllowChangeTextLabels() const;
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o usuário puder optar por mostrar rótulos de texto em imagens.

### <a name="remarks"></a>Comentários

## <a name="cmfcmenubarallowshowonpanemenu"></a><a name="allowshowonpanemenu"></a>CMFCMenubar::AllowShowOnPaneMenu

```
virtual BOOL AllowShowOnPaneMenu() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcmenubarcalcfixedlayout"></a><a name="calcfixedlayout"></a>CMFCMenubar::CalcFixedLayout

```
virtual CSize CalcFixedLayout(
    BOOL bStretch,
    BOOL bHorz);
```

### <a name="parameters"></a>Parâmetros

[em] *bStretch*<br/>

[em] *bHorz*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcmenubarcalclayout"></a><a name="calclayout"></a>CMFCMenubar::CalcLayout

```
virtual CSize CalcLayout(
    DWORD dwMode,
    int nLength = -1);
```

### <a name="parameters"></a>Parâmetros

[em] *dwMode*<br/>

[em] *nComprimento*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcmenubarcalcmaxbuttonheight"></a><a name="calcmaxbuttonheight"></a>CMFCMenubar::CalcMaxButtonHeight

```
virtual int CalcMaxButtonHeight();
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcmenubarcanbeclosed"></a><a name="canbeclosed"></a>CMFCMenubar::CanBeClosed

```
virtual BOOL CanBeClosed() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcmenubarcanberestored"></a><a name="canberestored"></a>CMFCMenubar::CanBeRestored

```
virtual BOOL CanBeRestored() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcmenubarcreate"></a><a name="create"></a>CMFCMenubar::Criar

Cria um controle de menu e o anexa a um objeto [CMFCMenuBar.](../../mfc/reference/cmfcmenubar-class.md)

```
virtual BOOL Create(
    CWnd* pParentWnd,
    DWORD dwStyle = AFX_DEFAULT_TOOLBAR_STYLE,
    UINT nID = AFX_IDW_MENUBAR);
```

### <a name="parameters"></a>Parâmetros

*Pparentwnd*<br/>
[em] Ponteiro para a janela `CMFCMenuBar` pai para o novo objeto.

*Dwstyle*<br/>
[em] O estilo da nova barra de menu.

*nID*<br/>
[em] A id para a janela infantil da barra de menu.

### <a name="return-value"></a>Valor retornado

VERDADE se bem sucedido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Depois de `CMFCMenuBar` construir um objeto, você deve chamar `Create`. Este método `CMFCMenuBar` cria o controle e `CMFCMenuBar` o anexa ao objeto.

Para obter mais informações sobre os estilos da barra de ferramentas, consulte [CBasePane::SetPaneStyle](../../mfc/reference/cbasepane-class.md#setpanestyle).

## <a name="cmfcmenubarcreateex"></a><a name="createex"></a>CMFCMenubar::CreateEx

Cria um objeto [CMFCMenuBar](../../mfc/reference/cmfcmenubar-class.md) com estilos estendidos especificados.

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

### <a name="parameters"></a>Parâmetros

*Pparentwnd*<br/>
[em] Ponteiro para a janela `CMFCMenuBar` pai do novo objeto.

*dwCtrlStyle*<br/>
[em] Estilos adicionais para a nova barra de menu.

*Dwstyle*<br/>
[em] O estilo principal da nova barra de menu.

*fronteiras rc*<br/>
[em] Um `CRect` parâmetro que especifica os tamanhos para `CMFCMenuBar` as bordas do objeto.

*nID*<br/>
[em] A id para a janela infantil da barra de menu.

### <a name="return-value"></a>Valor retornado

Não zero se o método for bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você deve usar esta função em vez de [CMFCMenuBar::Criar](#create) quando quiser especificar estilos além do estilo da barra de ferramentas. Alguns estilos adicionais frequentemente usados são TBSTYLE_TRANSPARENT e CBRS_TOP.

Para listas de estilos adicionais, consulte [Controle de barra de ferramentas e estilos de botão,](/windows/win32/Controls/toolbar-control-and-button-styles)estilos de controle [comuns](/windows/win32/Controls/common-control-styles)e [estilos de janela comuns](/windows/win32/winmsg/window-styles).

### <a name="example"></a>Exemplo

O exemplo a seguir `CreateEx` demonstra como `CMFCMenuBar` usar o método da classe. Este trecho de código faz parte da [amostra ie demo](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_IEDemo#1](../../mfc/reference/codesnippet/cpp/cmfcmenubar-class_1.h)]
[!code-cpp[NVC_MFC_IEDemo#2](../../mfc/reference/codesnippet/cpp/cmfcmenubar-class_3.cpp)]

## <a name="cmfcmenubarcreatefrommenu"></a><a name="createfrommenu"></a>CMFCMenubar::CreateFromMenu

Inicializa um objeto [CMFCMenuBar.](../../mfc/reference/cmfcmenubar-class.md) Este método `CMFCMenuBar` modela o objeto após um parâmetro HMENU.

```
virtual void CreateFromMenu(
    HMENU hMenu,
    BOOL bDefaultMenu = FALSE,
    BOOL bForceUpdate = FALSE);
```

### <a name="parameters"></a>Parâmetros

*Hmenu*<br/>
[em] Uma alça para um recurso de menu. `CreateFromMenu`usa esse recurso como `CMFCMenuBar`modelo para .

*bDefaultMenu*<br/>
[em] Um booleano que indica se o novo menu é o menu padrão.

*bForceUpdate*<br/>
[em] Um booleano que indica se esse método força uma atualização do menu.

### <a name="remarks"></a>Comentários

Use este método se quiser que um controle de menu tenha os mesmos itens do menu que um recurso de menu. Você chama este método depois de chamar [CMFCMenuBar::Criar](#create) ou [CMFCMenuBar::CreateEx](#createex).

## <a name="cmfcmenubarenablehelpcombobox"></a><a name="enablehelpcombobox"></a>CMFCMenuBar::HabilitarHelpCombobox

Habilita uma caixa de combinação **de ajuda** localizada no lado direito da barra de menu.

```
void EnableHelpCombobox(
    UINT uiID,
    LPCTSTR lpszPrompt = NULL,
    int nComboBoxWidth = 150);
```

### <a name="parameters"></a>Parâmetros

*Uiid*<br/>
[em] O iD de comando para o botão da caixa de combinação **Ajuda.**

*lpszPrompt*<br/>
[em] Uma string que contém o texto que a estrutura exibe na caixa de combinação se estiver vazia e não estiver ativa. Por exemplo, "Digite o texto aqui".

*nComboBoxWidth*<br/>
[em] A largura do botão para a caixa de combinação em pixels.

### <a name="remarks"></a>Comentários

A caixa de combinação **Ajuda** se assemelha à caixa de combinação **Ajuda** na barra de menu do Microsoft Word.

Quando você chama este método com *uiID* definido como 0, este método oculta a caixa de combinação. Caso contrário, este método exibe a caixa de combinação automaticamente no lado direito da barra de menu. Depois de chamar esse método, ligue para [CMFCMenuBar::GetHelpCombobox](#gethelpcombobox) para obter um ponteiro para o objeto [CMFCToolBarComboBoxButton](../../mfc/reference/cmfctoolbarcomboboxbutton-class.md) inserido.

## <a name="cmfcmenubarenablemenushadows"></a><a name="enablemenushadows"></a>CMFCMenubar::AtivarMenuSombras

Habilita sombras para menus pop-up.

```
static void EnableMenuShadows(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
[em] Um parâmetro booleano que indica se as sombras devem ser habilitadas para menus pop-up.

### <a name="remarks"></a>Comentários

O algoritmo que este método usa é complexo e pode diminuir o desempenho da sua aplicação em sistemas mais lentos.

## <a name="cmfcmenubargetavailableexpandsize"></a><a name="getavailableexpandsize"></a>CMFCMenubar::getAvailableExpandSize

```
virtual int GetAvailableExpandSize() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcmenubargetcolumnwidth"></a><a name="getcolumnwidth"></a>CMFCMenubar::obterlargura da coluna

```
virtual int GetColumnWidth() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcmenubargetdefaultmenu"></a><a name="getdefaultmenu"></a>CMFCMenubar::GetDefaultMenu

Recupera uma alça para o menu original. A estrutura carrega o menu original do arquivo de recursos.

```
HMENU GetDefaultMenu() const;
```

### <a name="return-value"></a>Valor retornado

Uma alça para um recurso de menu.

### <a name="remarks"></a>Comentários

Se o aplicativo personalizar um menu, você pode usar este método para recuperar uma alça no menu original.

## <a name="cmfcmenubargetdefaultmenuresid"></a><a name="getdefaultmenuresid"></a>CMFCMenubar::GetDefaultMenuResId

Recupera o identificador de recursos para o menu padrão.

```
UINT GetDefaultMenuResId() const;
```

### <a name="return-value"></a>Valor retornado

Um identificador de recurso de menu.

### <a name="remarks"></a>Comentários

A estrutura carrega o menu `CMFCMenuBar` padrão para o objeto a partir do arquivo de recursos.

## <a name="cmfcmenubargetfloatpopupdirection"></a><a name="getfloatpopupdirection"></a>CMFCMenubar::GetFloatPopupDirection

```
int GetFloatPopupDirection(CMFCToolBarMenuButton* pButton);
```

### <a name="parameters"></a>Parâmetros

[em] *botão p*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcmenubargetforcedownarrows"></a><a name="getforcedownarrows"></a>CMFCMenubar::GetForceDownArrows

```
BOOL GetForceDownArrows();
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcmenubargethelpcombobox"></a><a name="gethelpcombobox"></a>CMFCMenubar::GetHelpCombobox

Retorna um ponteiro para a caixa de combinação **Ajuda.**

```
CMFCToolBarComboBoxButton* GetHelpCombobox();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a caixa de combinação **Ajuda.** NULL se a caixa de combinação **Ajuda** estiver oculta ou não habilitada.

### <a name="remarks"></a>Comentários

A caixa de combinação **Ajuda** está localizada no lado direito da barra de menu. Chame o método [CMFCMenuBar::EnableHelpCombobox](#enablehelpcombobox) para ativar essa caixa de combinação.

## <a name="cmfcmenubargethmenu"></a><a name="gethmenu"></a>CMFCMenubar::getHmenu

Recupera a alça no menu anexado ao objeto [CMFCMenuBar.](../../mfc/reference/cmfcmenubar-class.md)

```
HMENU GetHMenu() const;
```

## <a name="cmfcmenubargetmenufont"></a><a name="getmenufont"></a>CMFCMenubar::getMenufont

Recupera a fonte do menu atual.

```
static const CFont& GetMenuFont(BOOL bHorz = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Bhorz*<br/>
[em] Um parâmetro booleano que especifica se deve retornar a fonte horizontal ou vertical. TRUE indica a fonte horizontal.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um parâmetro [CFont](../../mfc/reference/cfont-class.md) que contém a fonte atual da barra de menu.

### <a name="remarks"></a>Comentários

A fonte retornada é um parâmetro global para a aplicação. Duas fontes globais são `CMFCMenuBar` mantidas para todos os objetos. Essas fontes separadas são usadas para barras de menu horizontais e verticais.

## <a name="cmfcmenubargetmenuitem"></a><a name="getmenuitem"></a>CMFCMenubar::GetMenuItem

Recupera um objeto [CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md) em uma barra de menu com base no índice do item.

```
CMFCToolBarButton* GetMenuItem(int iItem) const;
```

### <a name="parameters"></a>Parâmetros

*Iitem*<br/>
[em] O índice do item do menu para retornar.

### <a name="return-value"></a>Valor retornado

Um ponteiro `CMFCToolBarButton` para o objeto que corresponde ao índice especificado pelo *iItem*. NULO se o índice for inválido.

## <a name="cmfcmenubargetrowheight"></a><a name="getrowheight"></a>CMFCMenubar::GetrowHeight

```
virtual int GetRowHeight() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcmenubargetsystembutton"></a><a name="getsystembutton"></a>CMFCMenubar::GetSystemButton

```
CMFCToolBarMenuButtonsButton* GetSystemButton(
    UINT uiBtn,
    BOOL bByCommand = TRUE) const;
```

### <a name="parameters"></a>Parâmetros

[em] *uiBtn*<br/>

[em] *bByCommand*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcmenubargetsystembuttonscount"></a><a name="getsystembuttonscount"></a>CMFCMenubar::GetSystemButtonsCount

```
int GetSystemButtonsCount() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcmenubargetsystemmenu"></a><a name="getsystemmenu"></a>CMFCMenubar::GetSystemMenu

```
CMFCToolBarSystemMenuButton* GetSystemMenu() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcmenubarhighlightdisableditems"></a><a name="highlightdisableditems"></a>CMFCMenubar::DestaqueItens desativados

Controla se a estrutura destaca itens de menu desativados.

```
static void HighlightDisabledItems(BOOL bHighlight = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bDestaque*<br/>
[em] Um parâmetro booleano que indica se a estrutura destaca itens de menu indisponíveis.

### <a name="remarks"></a>Comentários

Por padrão, a estrutura não destaca itens de menu indisponíveis quando o usuário posiciona o ponteiro do mouse sobre eles.

## <a name="cmfcmenubarisbuttonextrasizeavailable"></a><a name="isbuttonextrasizeavailable"></a>CMFCMenubar::isbuttonExtrasizeAvailable

```
virtual BOOL IsButtonExtraSizeAvailable() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcmenubarishighlightdisableditems"></a><a name="ishighlightdisableditems"></a>CMFCMenubar::IsHighlightDisabledItems

Indica se a estrutura destaca itens de menu indisponíveis.

```
static BOOL IsHighlightDisabledItems();
```

### <a name="return-value"></a>Valor retornado

TRUE se os itens do menu indisponíveis forem destacados; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Por padrão, a estrutura não destaca itens de menu indisponíveis quando o usuário posiciona o ponteiro do mouse sobre eles. Use o método [CMFCMenuBar::HighlightDisabledItems](#highlightdisableditems) para habilitar esse recurso.

## <a name="cmfcmenubarismenushadows"></a><a name="ismenushadows"></a>CMFCMenubar::IsMenuShadows

Indica se a estrutura desenha sombras para menus pop-up.

```
static BOOL IsMenuShadows();
```

### <a name="return-value"></a>Valor retornado

TRUE se a estrutura desenhar sombras de menu; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Use o método [CMFCMenuBar::EnableMenuShadows](#enablemenushadows) para ativar ou desativar esse recurso.

## <a name="cmfcmenubarisrecentlyusedmenus"></a><a name="isrecentlyusedmenus"></a>CMFCMenubar::ÉRecentementeUsadoMenus

Indica se os comandos de menu usados recentemente são exibidos na barra de menus.

```
static BOOL IsRecentlyUsedMenus();
```

### <a name="return-value"></a>Valor retornado

Não zero `CMFCMenuBar` se o objeto mostrar comandos de menu usados recentemente; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use a função [CMFCMenuBar::SetRecentlyUsedMenus](#setrecentlyusedmenus) para controlar se a barra de menumostra comandos de menu usados recentemente.

## <a name="cmfcmenubarisshowallcommands"></a><a name="isshowallcommands"></a>CMFCMenubar::IsShowAllCommands

Indica se os menus exibem todos os comandos.

```
static BOOL IsShowAllCommands();
```

### <a name="return-value"></a>Valor retornado

Não zero `CMFCMenuBar` se os comandos exibirem todos os comandos; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um `CMFCMenuBar` objeto pode ser configurado para mostrar todos os comandos ou mostrar apenas um subconjunto de comandos. Para obter mais informações sobre esse recurso, consulte [CMFCMenuBar Class](../../mfc/reference/cmfcmenubar-class.md).

`IsShowAllCommands`lhe dirá como esse recurso está `CMFCMenuBar` configurado para o objeto. Para controlar quais comandos de menu são mostrados, use os métodos [CMFCMenuBar::SetShowAllCommands](#setshowallcommands) e [CMFCMenuBar::SetRecentlyUsedMenus](#setrecentlyusedmenus).

## <a name="cmfcmenubarisshowallcommandsdelay"></a><a name="isshowallcommandsdelay"></a>CMFCMenubar::IsShowAllCommandsDelay

Indica se o objeto [CMFCMenuBar](../../mfc/reference/cmfcmenubar-class.md) exibe todos os comandos após um curto atraso.

```
static BOOL IsShowAllCommandsDelay();
```

### <a name="return-value"></a>Valor retornado

Não zero se a barra de menu exibir menus completos após um curto atraso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Quando você configura uma barra de menu para exibir itens usados recentemente, a barra de menu exibe o menu completo de duas maneiras:

- Exibir o menu completo após um atraso programado a partir do momento em que o usuário paira sobre o cursor sobre a seta na parte inferior do menu.

- Exibir o menu completo depois que o usuário clicar na seta na parte inferior do menu.

Por padrão, `CMFCMenuBar` todos os objetos usam a opção de exibir o menu completo após um curto atraso. Esta opção não pode ser `CMFCMenuBar` alterada programáticamente na classe. No entanto, um usuário pode alterar o comportamento durante a personalização da barra de ferramentas usando a caixa de diálogo **Personalizar..**

## <a name="cmfcmenubarloadstate"></a><a name="loadstate"></a>CMFCMenubar::LoadState

Carrega o estado da barra de menu saem do registro do Windows.

```
virtual BOOL LoadState(
    LPCTSTR lpszProfileName = NULL,
    int nIndex = -1,
    UINT uiID = (UINT)-1);
```

### <a name="parameters"></a>Parâmetros

*Lpszprofilename*<br/>
[em] Uma seqüência que contém o caminho de uma chave de registro do Windows.

*nIndex*<br/>
[em] O iD de controle da barra de menu.

*Uiid*<br/>
[em] Um valor reservado.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se o método foi bem sucedido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Use o [método CMFCMenuBar::SaveState](#savestate) para salvar o estado da barra de menu no registro. As informações salvas incluem os itens do menu, o estado das docas e a posição da barra de menu.

Na maioria dos casos, `LoadState`sua solicitação não chama . A estrutura chama esse método quando inicia o espaço de trabalho.

## <a name="cmfcmenubaronchangehot"></a><a name="onchangehot"></a>CMFCMenubar::OnChangeHot

```
virtual void OnChangeHot(int iHot);
```

### <a name="parameters"></a>Parâmetros

[em] *iHot*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfcmenubarondefaultmenuloaded"></a><a name="ondefaultmenuloaded"></a>CMFCMenubar:OnDefaultMenuLoaded

O framework chama esse método quando ele carrega o recurso de menu do arquivo de recursos.

```
virtual void OnDefaultMenuLoaded(HMENU hMenu);
```

### <a name="parameters"></a>Parâmetros

*Hmenu*<br/>
[em] A alça do menu anexado ao `CMFCMenuBar` objeto.

### <a name="remarks"></a>Comentários

A implementação padrão desta função não faz nada. Substituir esta função para executar código personalizado depois que a estrutura carrega um recurso de menu do arquivo de recursos.

## <a name="cmfcmenubaronsendcommand"></a><a name="onsendcommand"></a>CMFCMenubar::OnSendCommand

```
virtual BOOL OnSendCommand(const CMFCToolBarButton* pButton);
```

### <a name="parameters"></a>Parâmetros

[em] *botão p*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcmenubaronsetdefaultbuttontext"></a><a name="onsetdefaultbuttontext"></a>CMFCMenubar::Início de inícioTexto de botão de serviço

A estrutura chama esse método quando o usuário altera o texto de um item na barra de menu.

```
virtual BOOL OnSetDefaultButtonText(CMFCToolBarButton* pButton);
```

### <a name="parameters"></a>Parâmetros

*Pbutton*<br/>
[em] Um ponteiro para o objeto [CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md) que o usuário deseja personalizar.

### <a name="return-value"></a>Valor retornado

TRUE se o framework aplicar as alterações do usuário na barra de menus; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

A implementação padrão deste método altera o texto do botão para o texto que o usuário fornece.

## <a name="cmfcmenubarontoolhittest"></a><a name="ontoolhittest"></a>CMFCMenubar::OntoolHitTest

```
virtual INT_PTR OnToolHitTest(
    CPoint point,
    TOOLINFO* pTI) const;
```

### <a name="parameters"></a>Parâmetros

[em] *ponto*<br/>

[em] *pTI*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcmenubarpretranslatemessage"></a><a name="pretranslatemessage"></a>CMFCMenuBar::PreTraduzirmensagem

```
virtual BOOL PreTranslateMessage(MSG* pMsg);
```

### <a name="parameters"></a>Parâmetros

[em] *pMsg*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcmenubarrestoreoriginalstate"></a><a name="restoreoriginalstate"></a>CMFCMenuBar::RestaurarEstado original

Chamado pela estrutura quando o usuário seleciona **Redefinir** na caixa de diálogo **Personalizar.**

```
virtual BOOL RestoreOriginalstate();
```

### <a name="return-value"></a>Valor retornado

Não zero se o método for bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método é chamado quando o usuário seleciona **Redefinir** no menu de personalização. Você também pode chamar manualmente este método para redefinir programáticamente o estado da barra de menu. Este método carrega o estado original do arquivo de recursos.

Anular este método se você quiser fazer qualquer processamento quando o usuário selecionar a opção **Redefinir.**

## <a name="cmfcmenubarsavestate"></a><a name="savestate"></a>CMFCMenubar::SaveState

Salva o estado do objeto [CMFCMenuBar](../../mfc/reference/cmfcmenubar-class.md) no registro do Windows.

```
virtual BOOL SaveState (
    LPCTSTR lpszProfileName = NULL,
    int nIndex = -1,
    UINT uiID = (UINT)-1);
```

### <a name="parameters"></a>Parâmetros

*Lpszprofilename*<br/>
[em] Uma seqüência que contém o caminho de uma chave de registro do Windows.

*nIndex*<br/>
[em] O iD de controle da barra de menu.

*Uiid*<br/>
[em] Um valor reservado.

### <a name="return-value"></a>Valor retornado

VERDADE se bem sucedido; caso CONTRÁRIO, FALSO;

### <a name="remarks"></a>Comentários

Normalmente, sua aplicação `SaveState`não chama . A estrutura chama esse método quando o espaço de trabalho é serializado. Para obter mais informações, consulte [CWinAppEx::SaveState](../../mfc/reference/cwinappex-class.md#savestate).

As informações salvas incluem os itens do menu, o estado das docas e a posição da barra de menu.

## <a name="cmfcmenubarsetdefaultmenuresid"></a><a name="setdefaultmenuresid"></a>CMFCMenubar:SetDefaultMenuResId

Define o menu padrão de um objeto [CMFCMenuBar](../../mfc/reference/cmfcmenubar-class.md) com base no ID de recurso.

```
void SetDefaultMenuResId(UINT uiResId);
```

### <a name="parameters"></a>Parâmetros

*uiResId*<br/>
[em] O ID de recurso para o novo menu padrão.

### <a name="remarks"></a>Comentários

A [barra de menus CMFC::RestoreO métodoEstado original](#restoreoriginalstate) restaura o menu padrão do arquivo de recursos.

Use o método [CMFCMenuBar::GetDefaultMenuResId](#getdefaultmenuresid) para recuperar o menu padrão sem restaurá-lo.

## <a name="cmfcmenubarsetforcedownarrows"></a><a name="setforcedownarrows"></a>CMFCMenubar::SetForceDownArrows

```
void SetForceDownArrows(BOOL bValue);
```

### <a name="parameters"></a>Parâmetros

[em] *bValue*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfcmenubarsetmaximizemode"></a><a name="setmaximizemode"></a>CMFCMenubar::SetMaximizeMode

A estrutura chama esse método quando um MDI altera seu modo de exibição e a barra de menu deve ser atualizada.

```
void SetMaximizeMode(
    BOOL bMax,
    CWnd* pWnd = NULL,
    BOOL bRecalcLayout = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bMax*<br/>
[em] Um booleano que especifica o modo. Para obter mais informações, consulte a seção Comentários.

*Pwnd*<br/>
[em] Um ponteiro para a janela de criança MDI que está mudando.

*bRecalcLayout*<br/>
[em] Um booleano que especifica se o layout da barra de menu deve ser recalculado imediatamente.

### <a name="remarks"></a>Comentários

Quando uma janela filho MDI é maximizada, uma barra de menu anexada à janela principal do quadro MDI exibe o menu do sistema e os botões **Minimizar,** **Maximizar** e **Fechar.** Se *bMax* for TRUE e *pWnd* não for NULL, a janela do filho MDI será maximizada e a barra de menu deve incorporar os controles extras. Caso contrário, a barra de menu retorna ao seu estado regular.

## <a name="cmfcmenubarsetmenubuttonrtc"></a><a name="setmenubuttonrtc"></a>CMFCMenubar::setMenuButtonRTC

Define as informações da classe de tempo de execução que a estrutura usa quando o usuário cria botões de menu.

```
void SetMenuButtonRTC(CRuntimeClass* pMenuButtonRTC);
```

### <a name="parameters"></a>Parâmetros

*pMenuButtonRTC*<br/>
[em] As informações [do CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) para uma classe derivada da [classe CMFCMenuButton .](../../mfc/reference/cmfcmenubutton-class.md)

### <a name="remarks"></a>Comentários

Quando um usuário adiciona novos botões à barra de menu, a estrutura cria os botões dinamicamente. Por padrão, `CMFCMenuButton` ele cria objetos. Substituir este método para alterar o tipo de objetos de botão que a estrutura cria.

## <a name="cmfcmenubarsetmenufont"></a><a name="setmenufont"></a>CMFCMenubar::setMenufont

Define a fonte para todas as barras de menu em seu aplicativo.

```
static BOOL SetMenuFont(
    LPLOGFONT lpLogFont,
    BOOL bHorz = TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpLogFont*<br/>
[em] Um ponteiro para uma estrutura [LOGFONT](/windows/win32/api/dimm/ns-dimm-logfonta) que define a fonte a definir.

*Bhorz*<br/>
[em] TRUE se você quiser que o parâmetro *lpLogFont* seja usado para a fonte vertical, FALSE se você quiser que ele seja usado para fonte horizontal.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se o método foi bem sucedido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Duas fontes são usadas `CMFCMenuBar` para todos os objetos. Essas fontes separadas são usadas para barras de menu horizontais e verticais.

As configurações da fonte são `CMFCMenuBar` variáveis globais e afetam todos os objetos.

## <a name="cmfcmenubarsetrecentlyusedmenus"></a><a name="setrecentlyusedmenus"></a>CMFCMenubar::SetRecentlyUsedMenus

Controla se uma barra de menu exibe comandos de menu usados recentemente.

```
static void SetRecentlyUsedMenus (BOOL bOn = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Bon*<br/>
[em] Um booleano que controla se os comandos de menu usados recentemente são exibidos.

## <a name="cmfcmenubarsetshowallcommands"></a><a name="setshowallcommands"></a>CMFCMenubar::SetShowAllCommands

Controla se um menu mostra todos os comandos disponíveis.

```
static void SetShowAllCommands(BOOL bShowAllCommands = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bShowAllCommands*<br/>
[em] Um parâmetro booleano que especifica se o menu pop-up mostra todos os comandos do menu.

### <a name="remarks"></a>Comentários

Se um menu não exibir todos os comandos do menu, ele ocultará os comandos que raramente são usados. Para obter mais informações sobre como exibir comandos de menu, consulte [CMFCMenuBar Class](../../mfc/reference/cmfcmenubar-class.md).

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)
