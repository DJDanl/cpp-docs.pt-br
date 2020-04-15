---
title: Classe CMFCRibbonMiniToolBar
ms.date: 11/04/2016
f1_keywords:
- CMFCRibbonMiniToolBar
- AFXRIBBONMINITOOLBAR/CMFCRibbonMiniToolBar
- AFXRIBBONMINITOOLBAR/CMFCRibbonMiniToolBar::IsContextMenuMode
- AFXRIBBONMINITOOLBAR/CMFCRibbonMiniToolBar::IsRibbonMiniToolBar
- AFXRIBBONMINITOOLBAR/CMFCRibbonMiniToolBar::SetCommands
- AFXRIBBONMINITOOLBAR/CMFCRibbonMiniToolBar::Show
- AFXRIBBONMINITOOLBAR/CMFCRibbonMiniToolBar::ShowWithContextMenu
helpviewer_keywords:
- CMFCRibbonMiniToolBar [MFC], IsContextMenuMode
- CMFCRibbonMiniToolBar [MFC], IsRibbonMiniToolBar
- CMFCRibbonMiniToolBar [MFC], SetCommands
- CMFCRibbonMiniToolBar [MFC], Show
- CMFCRibbonMiniToolBar [MFC], ShowWithContextMenu
ms.assetid: 7017e963-aeaf-4fe9-b540-e15a7ed41e94
ms.openlocfilehash: 10b1d35c331df6563d09be0bea3c97c73e89acaa
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375083"
---
# <a name="cmfcribbonminitoolbar-class"></a>Classe CMFCRibbonMiniToolBar

Implementa uma barra de ferramentas pop-up contextual.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonMiniToolBar : public CMFCRibbonPanelMenu
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCRibbonMiniToolBar::CMFCRibbonMiniToolBar`|Construtor padrão.|
|`CMFCRibbonMiniToolBar::~CMFCRibbonMiniToolBar`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCRibbonMiniToolBar::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|`CMFCRibbonMiniToolBar::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|
|[CMFCRibbonMiniToolbar::IscontextMenuMode](#iscontextmenumode)||
|[CMFCRibbonMinitoolbar::Isribbonminitoolbar](#isribbonminitoolbar)|(Substitui `CMFCPopupMenu::IsRibbonMiniToolBar`.)|
|[CMFCRibbonMiniToolBar::SetCommands](#setcommands)|Define a lista de comandos a serem exibidos na barra de ferramentas.|
|[CMFCRibbonMinitoolbar::Show](#show)|Exibe a mini barra de ferramentas nas coordenadas de tela especificadas.|
|[CMFCRibbonminitoolbar::ShowWithContextMenu](#showwithcontextmenu)|Exibe a mini barra de ferramentas juntamente com um menu de contexto.|

## <a name="remarks"></a>Comentários

A mini barra de ferramentas é normalmente exibida depois que o usuário seleciona um objeto em um documento. Por exemplo, depois que o usuário seleciona um bloco de texto em um programa de processamento de texto, o aplicativo exibe uma mini barra de ferramentas que contém comandos de formatação de texto.

A mini barra de ferramentas torna-se transparente quando o ponteiro do mouse está fora dos limites da barra de ferramentas mini.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CFrameWnd](../../mfc/reference/cframewnd-class.md)

[Cminiframewnd](../../mfc/reference/cminiframewnd-class.md)

[Cmfcpopupmenu](../../mfc/reference/cmfcpopupmenu-class.md)

`CMFCRibbonPanelMenu`

[CmFCRibbonMinitoolbar](../../mfc/reference/cmfcribbonminitoolbar-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxRibbonMiniToolBar.h

## <a name="cmfcribbonminitoolbarsetcommands"></a><a name="setcommands"></a>CMFCRibbonMiniToolBar::SetCommands

Define a lista de comandos a serem exibidos na barra de ferramentas.

```
void SetCommands(
    CMFCRibbonBar* pRibbonBar,
    const CList<UINT,UINT>& lstCommands);
```

### <a name="parameters"></a>Parâmetros

*pRibbonBar*<br/>
[em] A barra de fita que a mini barra de ferramentas procura pelos botões a serem exibidos.

*lstCommands*<br/>
[em] A lista de comandos a serem exibidos na barra de ferramentas mini. Todas as categorias de fita são pesquisadas para encontrar os botões associados.

### <a name="remarks"></a>Comentários

Use esta função para definir a lista de comandos a serem exibidos na mini barra de ferramentas.

### <a name="example"></a>Exemplo

O exemplo a seguir `SetCommands` demonstra como `CMFCRibbonMiniToolBar` usar o método da classe. Este trecho de código faz parte da amostra de [demonstração do MS Office 2007](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_MSOffice2007Demo#9](../../mfc/reference/codesnippet/cpp/cmfcribbonminitoolbar-class_1.cpp)]

## <a name="cmfcribbonminitoolbarshow"></a><a name="show"></a>CMFCRibbonMinitoolbar::Show

Exibe a mini barra de ferramentas nas coordenadas de tela especificadas.

```
BOOL Show(
    int x,
    int y);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
[em] Especifica a posição horizontal da barra de ferramentas da mini-ferramenta nas coordenadas da tela.

*Y*<br/>
[em] Especifica a posição vertical da mini barra de ferramentas nas coordenadas da tela.

### <a name="return-value"></a>Valor retornado

TRUE se a mini barra de ferramentas foi exibida com sucesso; caso contrário, FALSE.

## <a name="cmfcribbonminitoolbarshowwithcontextmenu"></a><a name="showwithcontextmenu"></a>CMFCRibbonminitoolbar::ShowWithContextMenu

Exibe a mini barra de ferramentas juntamente com um menu de contexto.

```
BOOL ShowWithContextMenu(
    int x,
    int y,
    UINT uiMenuResID,
    CWnd* pWndOwner);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
[em] Especifica a posição horizontal do menu de contexto nas coordenadas da tela.

*Y*<br/>
[em] Especifica a posição vertical do menu de contexto nas coordenadas da tela.

*uiMenuResID*<br/>
[em] Especifica o ID de recurso do menu de contexto a ser exibido.

*pWndOwner*<br/>
[em] Identifica a janela que recebe mensagens do menu de contexto.

### <a name="return-value"></a>Valor retornado

TRUE se o menu de contexto foi exibido com sucesso; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use esta função para exibir uma mini barra de ferramentas que tenha um menu de contexto. O menu de contexto está posicionado 15 pixels abaixo da mini barra de ferramentas.

## <a name="cmfcribbonminitoolbariscontextmenumode"></a><a name="iscontextmenumode"></a>CMFCRibbonMiniToolbar::IscontextMenuMode

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

```
BOOL IsContextMenuMode() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonminitoolbarisribbonminitoolbar"></a><a name="isribbonminitoolbar"></a>CMFCRibbonMinitoolbar::Isribbonminitoolbar

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

```
virtual BOOL IsRibbonMiniToolBar() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
