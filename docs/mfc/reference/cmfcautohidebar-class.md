---
title: Classe CMFCAutoHideBar
ms.date: 10/18/2018
f1_keywords:
- CMFCAutoHideBar
- AFXAUTOHIDEBAR/CMFCAutoHideBar
- AFXAUTOHIDEBAR/CMFCAutoHideBar::CMFCAutoHideBar
- AFXAUTOHIDEBAR/CMFCAutoHideBar::AddAutoHideWindow
- AFXAUTOHIDEBAR/CMFCAutoHideBar::AllowShowOnPaneMenu
- AFXAUTOHIDEBAR/CMFCAutoHideBar::CalcFixedLayout
- AFXAUTOHIDEBAR/CMFCAutoHideBar::Create
- AFXAUTOHIDEBAR/CMFCAutoHideBar::GetFirstAHWindow
- AFXAUTOHIDEBAR/CMFCAutoHideBar::GetVisibleCount
- AFXAUTOHIDEBAR/CMFCAutoHideBar::OnShowControlBarMenu
- AFXAUTOHIDEBAR/CMFCAutoHideBar::RemoveAutoHideWindow
- AFXAUTOHIDEBAR/CMFCAutoHideBar::SetActiveInGroup
- AFXAUTOHIDEBAR/CMFCAutoHideBar::SetRecentVisibleState
- AFXAUTOHIDEBAR/CMFCAutoHideBar::ShowAutoHideWindow
- AFXAUTOHIDEBAR/CMFCAutoHideBar::StretchPane
- AFXAUTOHIDEBAR/CMFCAutoHideBar::UnSetAutoHideMode
- AFXAUTOHIDEBAR/CMFCAutoHideBar::UpdateVisibleState
- AFXAUTOHIDEBAR/CMFCAutoHideBar::m_nShowAHWndDelay
helpviewer_keywords:
- CMFCAutoHideBar [MFC], CMFCAutoHideBar
- CMFCAutoHideBar [MFC], AddAutoHideWindow
- CMFCAutoHideBar [MFC], AllowShowOnPaneMenu
- CMFCAutoHideBar [MFC], CalcFixedLayout
- CMFCAutoHideBar [MFC], Create
- CMFCAutoHideBar [MFC], GetFirstAHWindow
- CMFCAutoHideBar [MFC], GetVisibleCount
- CMFCAutoHideBar [MFC], OnShowControlBarMenu
- CMFCAutoHideBar [MFC], RemoveAutoHideWindow
- CMFCAutoHideBar [MFC], SetActiveInGroup
- CMFCAutoHideBar [MFC], SetRecentVisibleState
- CMFCAutoHideBar [MFC], ShowAutoHideWindow
- CMFCAutoHideBar [MFC], StretchPane
- CMFCAutoHideBar [MFC], UnSetAutoHideMode
- CMFCAutoHideBar [MFC], UpdateVisibleState
- CMFCAutoHideBar [MFC], m_nShowAHWndDelay
ms.assetid: 54c8d84f-de64-4efd-8a47-3ea0ade40a70
ms.openlocfilehash: 05f77dfba442f1ce4a375c8f225908799ece1788
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81751766"
---
# <a name="cmfcautohidebar-class"></a>Classe CMFCAutoHideBar

A `CMFCAutoHideBar` classe é uma classe especial de barra de ferramentas que implementa o recurso de ocultação automática.

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

## <a name="syntax"></a>Sintaxe

```
class CMFCAutoHideBar : public CPane
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCAutoHidebar::CMFCAutoHidebar](#cmfcautohidebar)||

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCAutoHidebar::AddAutoHidewindow](#addautohidewindow)||
|[CMFCAutoHideBar::PermitirMostrarOnPaneMenu](#allowshowonpanemenu)|(Substitui `CPane::AllowShowOnPaneMenu`.)|
|[CMFCAutoHideBar::CalcFixedLayout](#calcfixedlayout)|(Substitui [cbasepane::CalcFixedLayout](../../mfc/reference/cbasepane-class.md#calcfixedlayout).)|
|[CMFCAutoHidebar::Criar](#create)|Cria uma barra de controle e a prende ao objeto [CPane.](../../mfc/reference/cpane-class.md) (Substitui [cpane::criar](../../mfc/reference/cpane-class.md#create).)|
|[CMFCAutoHidebar::GetFirstAHwindow](#getfirstahwindow)||
|[CMFCAutoHidebar::GetVisibleCount](#getvisiblecount)||
|[CMFCAutoHidebar::OnShowControlBarmenu](#onshowcontrolbarmenu)|Chamado pela estrutura quando um menu de painel especial está prestes a ser exibido. (Substitui [cpane::OnShowControlBarMenu](../../mfc/reference/cpane-class.md#onshowcontrolbarmenu).)|
|[CMFCAutoHidebar::RemoveAutoHideWindow](#removeautohidewindow)||
|[CMFCAutoHidebar::setActiveInGroup](#setactiveingroup)|(Substitui [cpane::SetActiveInGroup](../../mfc/reference/cpane-class.md#setactiveingroup).)|
|[CMFCAutoHidebar::setRecentVisiblestate](#setrecentvisiblestate)||
|[CMFCAutoHidebar::ShowAutoHidewindow](#showautohidewindow)||
|[CMFCAutoHideBar::StretchPane](#stretchpane)|Estica um painel vertical ou horizontalmente. (Substitui [cbasepane::StretchPane](../../mfc/reference/cbasepane-class.md#stretchpane).)|
|[CMFCAutoHidebar::'''''''Modo de ocultação de automaticamente'.](#unsetautohidemode)||
|[CMFCAutoHidebar::AtualizaçãoVisibleState](#updatevisiblestate)||

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|----------|-----------------|
|[CMFCAutoHideBar::m_nShowAHWndDelay](#m_nshowahwnddelay)|O atraso de tempo entre o momento em que o usuário coloca o cursor do mouse sobre uma [classe CMFCAutoHideButton e](../../mfc/reference/cmfcautohidebutton-class.md) o momento em que a estrutura mostra a janela associada.|

## <a name="remarks"></a>Comentários

Quando o usuário alterna um painel de doca para o `CMFCAutoHideBar` modo de ocultação automática, a estrutura cria automaticamente um objeto. Ele também cria os objetos [CAutoHideDockSite](../../mfc/reference/cautohidedocksite-class.md) e [CMFCAutoHideButton](../../mfc/reference/cmfcautohidebutton-class.md) necessários. Cada `CAutoHideDockSite` objeto está associado `CMFCAutoHideButton`a um indivíduo.

A `CMFCAutoHideBar` classe implementa a `CAutoHideDockSite` exibição de um quando o `CMFCAutoHideButton`mouse de um usuário paira sobre um . Quando a barra de ferramentas `CMFCAutoHideBar` recebe uma mensagem WM_MOUSEMOVE, inicia um temporizador. Quando o temporizador termina, ele envia à barra de ferramentas uma notificação de evento WM_TIMER. A barra de ferramentas lida com este evento verificando se o ponteiro do mouse está posicionado sobre o mesmo botão de ocultação automática que foi posicionado quando o temporizador começou. Se for, o `CAutoHideDockSite` anexo é exibido.

Você pode controlar o tempo de atraso `m_nShowAHWndDelay`do temporizador configurando . O valor padrão é de 400 ms.

## <a name="example"></a>Exemplo

O exemplo a seguir `CMFCAutoHideBar` demonstra como `GetDockSiteRow` construir um objeto e usar seu método.

[!code-cpp[NVC_MFC_RibbonApp#26](../../mfc/reference/codesnippet/cpp/cmfcautohidebar-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cbasepane](../../mfc/reference/cbasepane-class.md)

[Cpane](../../mfc/reference/cpane-class.md)

[CMFCAutoHideBar](../../mfc/reference/cmfcautohidebar-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxautohidebar.h

## <a name="cmfcautohidebaraddautohidewindow"></a><a name="addautohidewindow"></a>CMFCAutoHidebar::AddAutoHidewindow

Adiciona funcionalidade a `CDockablePane` uma janela que permite que ele se esconda automaticamente.

```
CMFCAutoHideButton* AddAutoHideWindow(
    CDockablePane* pAutoHideWnd,
    DWORD dwAlignment);
```

### <a name="parameters"></a>Parâmetros

*pAutoHideWnd*<br/>
[em] A janela que você quer esconder.

*Dwalignment*<br/>
[em] Um valor que especifica o alinhamento do botão de ocultação automática com a janela do aplicativo.

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

O parâmetro *dwAlignment* indica onde o botão de ocultação automática reside no aplicativo. O parâmetro pode ser qualquer um dos seguintes valores:

- Cbrs_align_left

- Cbrs_align_right

- Cbrs_align_top

- Cbrs_align_bottom

## <a name="cmfcautohidebarallowshowonpanemenu"></a><a name="allowshowonpanemenu"></a>CMFCAutoHideBar::PermitirMostrarOnPaneMenu

```
virtual BOOL AllowShowOnPaneMenu() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcautohidebarcalcfixedlayout"></a><a name="calcfixedlayout"></a>CMFCAutoHideBar::CalcFixedLayout

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

## <a name="cmfcautohidebarcmfcautohidebar"></a><a name="cmfcautohidebar"></a>CMFCAutoHidebar::CMFCAutoHidebar

Constrói um objeto CMFCAutoHideBar.

```
CMFCAutoHideBar();
```

### <a name="remarks"></a>Comentários

## <a name="cmfcautohidebarcreate"></a><a name="create"></a>CMFCAutoHidebar::Criar

```
virtual BOOL Create(
    LPCTSTR lpszClassName,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID,
    DWORD dwControlBarStyle = AFX_DEFAULT_PANE_STYLE,
    CCreateContext* pContext = NULL);
```

### <a name="parameters"></a>Parâmetros

*Lpszclassname*<br/>

*Dwstyle*<br/>

*Rect*<br/>

*Pparentwnd*<br/>

*nID*<br/>

*dwControlBarStyle*<br/>

*pContext*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcautohidebargetfirstahwindow"></a><a name="getfirstahwindow"></a>CMFCAutoHidebar::GetFirstAHwindow

Retorna um ponteiro para a primeira janela de ocultação automática no aplicativo.

```
CDockablePane* GetFirstAHWindow();
```

### <a name="return-value"></a>Valor retornado

A primeira janela de ocultação automática no aplicativo, ou NULL se não houver.

### <a name="remarks"></a>Comentários

## <a name="cmfcautohidebargetvisiblecount"></a><a name="getvisiblecount"></a>CMFCAutoHidebar::GetVisibleCount

Obtém o número de botões de ocultação automática visíveis.

```
int GetVisibleCount();
```

### <a name="return-value"></a>Valor retornado

Retorna o número de botões de ocultação automática visíveis.

### <a name="remarks"></a>Comentários

## <a name="cmfcautohidebarm_nshowahwnddelay"></a><a name="m_nshowahwnddelay"></a>CMFCAutoHideBar::m_nShowAHWndDelay

O atraso de tempo entre o momento em que o usuário coloca o cursor do mouse sobre uma [classe CMFCAutoHideButton e](../../mfc/reference/cmfcautohidebutton-class.md) o momento em que a estrutura mostra a janela associada.

```
int CMFCAutoHideBar::m_nShowAHWndDelay = 400;
```

### <a name="remarks"></a>Comentários

Quando o usuário coloca o cursor do mouse sobre um, `CMFCAutoHideButton`há um pequeno atraso antes que a estrutura exiba a janela associada. Este parâmetro determina o comprimento desse atraso em milissegundos.

## <a name="cmfcautohidebaronshowcontrolbarmenu"></a><a name="onshowcontrolbarmenu"></a>CMFCAutoHidebar::OnShowControlBarmenu

```
virtual BOOL OnShowControlBarMenu(CPoint);
```

### <a name="parameters"></a>Parâmetros

[em] *CPoint*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcautohidebarremoveautohidewindow"></a><a name="removeautohidewindow"></a>CMFCAutoHidebar::RemoveAutoHideWindow

Remove e destrói a janela de ocultação automática.

```
    BOOL RemoveAutoHideWindow(CDockablePane* pAutoHideWnd);
```

### <a name="parameters"></a>Parâmetros

CDockablePane* *pAutoHideWnd* A janela de ocultação automática para remover.

### <a name="return-value"></a>Valor retornado

VERDADE se bem sucedido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

## <a name="cmfcautohidebarsetactiveingroup"></a><a name="setactiveingroup"></a>CMFCAutoHidebar::setActiveInGroup

Sinaliza uma barra de ocultação automática como ativa.

```
virtual void SetActiveInGroup(BOOL bActive);
```

### <a name="parameters"></a>Parâmetros

[em] BOOL *bActive* TRUE para definir como ativo; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Veja [CPane::SetActiveInGroup](../../mfc/reference/cpane-class.md#setactiveingroup).

## <a name="cmfcautohidebarsetrecentvisiblestate"></a><a name="setrecentvisiblestate"></a>CMFCAutoHidebar::setRecentVisiblestate

```cpp
void SetRecentVisibleState(BOOL bState);
```

### <a name="parameters"></a>Parâmetros

*bState*<br/>
[em] Estado para definir.

### <a name="remarks"></a>Comentários

## <a name="cmfcautohidebarshowautohidewindow"></a><a name="showautohidewindow"></a>CMFCAutoHidebar::ShowAutoHidewindow

Mostra a janela de ocultação automática.

```
BOOL ShowAutoHideWindow(
    CDockablePane* pAutoHideWnd,
    BOOL bShow,
    BOOL bDelay);
```

### <a name="parameters"></a>Parâmetros

*pAutoHideWnd*<br/>
[em] Janela para mostrar.

*Bshow*<br/>
[em] VERDADE para mostrar a janela.

*bAtraso*<br/>
[em] Este parâmetro é ignorado.

### <a name="return-value"></a>Valor retornado

VERDADE se bem sucedido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

## <a name="cmfcautohidebarstretchpane"></a><a name="stretchpane"></a>CMFCAutoHideBar::StretchPane

Redimensiona a barra de ocultação automática `CMFCAutoHideButton` em seu estado colapsado para caber no objeto.

```
virtual CSize StretchPane(
    int nLength,
    BOOL bVert);
```

### <a name="parameters"></a>Parâmetros

*Nlength*<br/>
[em] O valor não é utilizado na implementação da base. Em implementações derivadas, use este valor para indicar o comprimento do painel redimensionado.

*bVert*<br/>
[em] O valor não é utilizado na implementação da base. Nas implementações derivadas, use TRUE para lidar com o caso em que a barra de ocultação automática é colapsada verticalmente, e FALSE para o caso em que a barra de ocultação automática é colapsada horizontalmente.

### <a name="return-value"></a>Valor retornado

O tamanho resultante do painel redimensionado.

### <a name="remarks"></a>Comentários

Classes derivadas podem substituir esse método para personalizar o comportamento.

## <a name="cmfcautohidebarunsetautohidemode"></a><a name="unsetautohidemode"></a>CMFCAutoHidebar::'''''''Modo de ocultação de automaticamente'.

Desabilita o modo de ocultação automática para um grupo de barras de ocultação automática.

```cpp
void UnSetAutoHideMode(CDockablePane* pFirstBarInGroup)
```

### <a name="parameters"></a>Parâmetros

[in] pFirstBarInGroup Um ponteiro para a primeira barra de ocultação automática do grupo.

### <a name="remarks"></a>Comentários

## <a name="cmfcautohidebarupdatevisiblestate"></a><a name="updatevisiblestate"></a>CMFCAutoHidebar::AtualizaçãoVisibleState

Chamada pela estrutura quando a barra de ocultação automática precisa ser redesenhada.

```cpp
void UpdateVisibleState();
```

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CPane](../../mfc/reference/cpane-class.md)<br/>
[Classe CAutoHideDockSite](../../mfc/reference/cautohidedocksite-class.md)<br/>
[Classe CMFCAutoHideButton](../../mfc/reference/cmfcautohidebutton-class.md)
