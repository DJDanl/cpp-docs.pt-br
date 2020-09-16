---
title: Classe CTabbedPane
ms.date: 11/04/2016
f1_keywords:
- CTabbedPane
- AFXTABBEDPANE/CTabbedPane
- AFXTABBEDPANE/CTabbedPane::DetachPane
- AFXTABBEDPANE/CTabbedPane::EnableTabAutoColor
- AFXTABBEDPANE/CTabbedPane::FloatTab
- AFXTABBEDPANE/CTabbedPane::GetTabArea
- AFXTABBEDPANE/CTabbedPane::GetTabWnd
- AFXTABBEDPANE/CTabbedPane::HasAutoHideMode
- AFXTABBEDPANE/CTabbedPane::IsTabLocationBottom
- AFXTABBEDPANE/CTabbedPane::ResetTabs
- AFXTABBEDPANE/CTabbedPane::SetTabAutoColors
- AFXTABBEDPANE/CTabbedPane::m_bTabsAlwaysTop
- AFXTABBEDPANE/CTabbedPane::m_pTabWndRTC
helpviewer_keywords:
- CTabbedPane [MFC], DetachPane
- CTabbedPane [MFC], EnableTabAutoColor
- CTabbedPane [MFC], FloatTab
- CTabbedPane [MFC], GetTabArea
- CTabbedPane [MFC], GetTabWnd
- CTabbedPane [MFC], HasAutoHideMode
- CTabbedPane [MFC], IsTabLocationBottom
- CTabbedPane [MFC], ResetTabs
- CTabbedPane [MFC], SetTabAutoColors
- CTabbedPane [MFC], m_bTabsAlwaysTop
- CTabbedPane [MFC], m_pTabWndRTC
ms.assetid: f4dc5215-b789-4f2d-8c62-477aceda3578
ms.openlocfilehash: cfc0a3099b1d5ff9bd1093cc911745bd61cde64c
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90686633"
---
# <a name="ctabbedpane-class"></a>Classe CTabbedPane

Implementa a funcionalidade de um painel com guias desconectáveis.

ou mais detalhes, consulte o código-fonte localizado na pasta **vc \\ atlmfc \\ src \\ MFC** da sua instalação do Visual Studio.

## <a name="syntax"></a>Sintaxe

```
class CTabbedPane : public CBaseTabbedPane
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Name|Descrição|
|----------|-----------------|
|`CTabbedPane::CTabbedPane`|Construtor padrão.|

### <a name="public-methods"></a>Métodos públicos

|Name|Descrição|
|----------|-----------------|
|[CTabbedPane::D etachPane](#detachpane)|(Substitui [CBaseTabbedPane::D etachpane](../../mfc/reference/cbasetabbedpane-class.md#detachpane).)|
|[CTabbedPane::EnableTabAutoColor](#enabletabautocolor)|Habilita ou desabilita a cor automática das guias.|
|[CTabbedPane::FloatTab](#floattab)|Flutua um painel, mas somente se o painel residir atualmente em uma guia desanexável. (Substitui [CBaseTabbedPane:: FloatTab](../../mfc/reference/cbasetabbedpane-class.md#floattab).)|
|[CTabbedPane::GetTabArea](#gettabarea)|Retorna o tamanho e a posição da área da guia dentro da janela com guias.|
|[CTabbedPane::GetTabWnd](#gettabwnd)||
|[CTabbedPane::HasAutoHideMode](#hasautohidemode)|Determina se o painel com guias pode ser alternado para o modo de AutoOcultar. (Substitui [CBaseTabbedPane:: HasAutoHideMode](../../mfc/reference/cbasetabbedpane-class.md#hasautohidemode).)|
|[CTabbedPane::IsTabLocationBottom](#istablocationbottom)|Determina se as guias estão localizadas na parte inferior da janela.|
|[CTabbedPane::ResetTabs](#resettabs)|Redefine todos os painéis com guias para o estado padrão.|
|[CTabbedPane::SetTabAutoColors](#settabautocolors)|Define uma lista de cores personalizadas que podem ser usadas quando o recurso de cor automática está habilitado.|

### <a name="data-members"></a>Membros de dados

|Name|Descrição|
|----------|-----------------|
|[CTabbedPane:: m_bTabsAlwaysTop](#m_btabsalwaystop)|O local padrão para guias no aplicativo.|
|[CTabbedPane:: m_pTabWndRTC](#m_ptabwndrtc)|Informações de classe de tempo de execução para um `CMFCTabCtrl` objeto derivado personalizado.|

## <a name="remarks"></a>Comentários

A estrutura cria automaticamente uma instância dessa classe quando um usuário anexa um painel a outro apontando para a legenda do segundo painel. Todos os painéis com guias criados pelo Framework têm uma ID de-1.

Para especificar guias regulares em vez de guias do estilo do Outlook, passe o estilo de AFX_CBRS_REGULAR_TABS para o método [CDockablePane:: CreateEx](../../mfc/reference/cdockablepane-class.md#createex) .

Se você criar um painel com guias com guias desanexáveis, o painel poderá ser destruído automaticamente pela estrutura, portanto, você não deve armazenar o ponteiro. Para obter um ponteiro para o painel com guias, chame o `CBasePane::GetParentTabbedPane` método.

## <a name="examples"></a>Exemplos

Neste exemplo, criamos um `CTabbedPane` objeto. Em seguida, usamos [CBaseTabbedPane:: AddTab](../../mfc/reference/cbasetabbedpane-class.md#addtab) para anexar guias adicionais.

```cpp
CTabbedPane* pTabbededBar = new CTabbedPane (TRUE);

if (!pTabbededBar->Create (_T(""),
    this,
    CRect (0,
    0,
    200,
    200),
    TRUE,
    (UINT) -1,
    WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |
    WS_CLIPCHILDREN | CBRS_LEFT |
    CBRS_FLOAT_MULTI))
{
    TRACE0("Failed to create Solution Explorer bar\n");

    return FALSE;      // fail to create
}

pTabbededBar->AddTab (&m_wndClassView);
pTabbededBar->AddTab (&m_wndResourceView);

pTabbededBar->AddTab (&m_wndFileView);
pTabbededBar->EnableDocking(CBRS_ALIGN_ANY);

DockPane(pTabbededBar);
```

Outra maneira de criar um objeto de barra de controle com guias é usar [CDockablePane:: AttachToTabWnd](../../mfc/reference/cdockablepane-class.md#attachtotabwnd). O `AttachToTabWnd` método cria dinamicamente um objeto de painel com guias usando informações de classe de tempo de execução definidas por [CDockablePane:: SetTabbedPaneRTC](../../mfc/reference/cdockablepane-class.md#settabbedpanertc).

Neste exemplo, criamos um painel com guias dinamicamente, anexamos duas guias e tornamos a segunda guia não desanexável.

```cpp
DockPane(&m_wndClassView);

CTabbedPane* pTabbedBar = NULL;
m_wndResourceView.AttachToTabWnd (&m_wndClassView,
    DM_SHOW,
    TRUE,
    (CDockablePane**) &pTabbedBar);

m_wndFileView.AttachToTabWnd (pTabbedBar,
    DM_SHOW,
    TRUE,
    (CDockablePane**) &pTabbedBar);

pTabbedBar->GetUnderlyingWindow ()->EnableTabDetach (1,
    FALSE);
```

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CBasePane](../../mfc/reference/cbasepane-class.md)

[CPane](../../mfc/reference/cpane-class.md)

[CDockablePane](../../mfc/reference/cdockablepane-class.md)

[CBaseTabbedPane](../../mfc/reference/cbasetabbedpane-class.md)

[CTabbedPane](../../mfc/reference/ctabbedpane-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxTabbedPane. h

## <a name="ctabbedpanedetachpane"></a><a name="detachpane"></a> CTabbedPane::D etachPane

```
virtual BOOL DetachPane(
    CWnd* pBar,
    BOOL bHide = FALSE);
```

### <a name="parameters"></a>Parâmetros

no *pBar*<br/>

no *bHide*<br/>

### <a name="return-value"></a>Valor Retornado

### <a name="remarks"></a>Comentários

## <a name="ctabbedpaneenabletabautocolor"></a><a name="enabletabautocolor"></a> CTabbedPane::EnableTabAutoColor

Habilita ou desabilita a cor automática das guias.

```
static void EnableTabAutoColor(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bEnable*<br/>
no TRUE para habilitar a coloração automática de guias; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use esse método estático para habilitar ou desabilitar a cor automática de guias em todos os painéis com guias no aplicativo. Quando esse recurso é habilitado, cada guia é preenchida por sua própria cor. Você pode encontrar a lista de cores que são usadas para colorir as guias chamando o método [CMFCBaseTabCtrl:: GetAutoColors](../../mfc/reference/cmfcbasetabctrl-class.md#getautocolors) .

Você pode especificar a lista de cores que será usada para guias chamando [CTabbedPane:: SetTabAutoColors](#settabautocolors).

Por padrão, essa opção está desabilitada.

## <a name="ctabbedpanefloattab"></a><a name="floattab"></a> CTabbedPane::FloatTab

```
virtual BOOL FloatTab(
    CWnd* pBar,
    int nTabID,
    AFX_DOCK_METHOD dockMethod,
    BOOL bHide = FALSE);
```

### <a name="parameters"></a>Parâmetros

no *pBar*<br/>
no *nTabID*<br/>
no *dockMethod*<br/>
no *bHide*<br/>

### <a name="return-value"></a>Valor Retornado

### <a name="remarks"></a>Comentários

## <a name="ctabbedpanegettabarea"></a><a name="gettabarea"></a> CTabbedPane::GetTabArea

Retorna o tamanho e a posição da área da guia na janela com guias.

```
virtual void GetTabArea(
    CRect& rectTabAreaTop,
    CRect& rectTabAreaBottom) const;
```

### <a name="parameters"></a>Parâmetros

*rectTabAreaTop*<br/>
fora Contém o tamanho e a posição, nas coordenadas da tela, da área da guia superior.

*rectTabAreaBottom*<br/>
fora Contém o tamanho e a posição, nas coordenadas da tela, da área da guia inferior.

### <a name="remarks"></a>Comentários

A estrutura chama esse método para determinar como encaixar um painel que um usuário está arrastando. Quando o usuário arrasta um painel sobre a área da guia do painel de destino, a estrutura tenta adicioná-lo como uma nova guia do painel de destino. Caso contrário, ele tentará encaixar o painel no lado do painel de destino, que envolve a criação de um novo contêiner de painel com um divisor de painel que separa os dois painéis.

Substitua esse método em uma `CTabbedPane` classe derivada para alterar esse comportamento.

## <a name="ctabbedpanegettabwnd"></a><a name="gettabwnd"></a> CTabbedPane::GetTabWnd

```
CMFCTabCtrl* GetTabWnd() const;
```

### <a name="return-value"></a>Valor Retornado

### <a name="remarks"></a>Comentários

## <a name="ctabbedpanehasautohidemode"></a><a name="hasautohidemode"></a> CTabbedPane::HasAutoHideMode

```
virtual BOOL HasAutoHideMode() const;
```

### <a name="return-value"></a>Valor Retornado

### <a name="remarks"></a>Comentários

## <a name="ctabbedpaneistablocationbottom"></a><a name="istablocationbottom"></a> CTabbedPane::IsTabLocationBottom

Determina se as guias estão localizadas na parte inferior da janela.

```
virtual BOOL IsTabLocationBottom() const;
```

### <a name="return-value"></a>Valor Retornado

TRUE se a área da guia estiver localizada na parte inferior da janela com guias; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

## <a name="ctabbedpanem_btabsalwaystop"></a><a name="m_btabsalwaystop"></a> CTabbedPane:: m_bTabsAlwaysTop

O local padrão para guias no aplicativo.

```
AFX_IMPORT_DATA static BOOL m_bTabsAlwaysTop;
```

### <a name="remarks"></a>Comentários

Defina esse membro estático como TRUE para forçar todas as guias no aplicativo a serem exibidas na parte superior do painel com guias.

Você deve definir esse valor antes que um painel com guias tenha sido criado.

O valor padrão é FALSE.

## <a name="ctabbedpanem_ptabwndrtc"></a><a name="m_ptabwndrtc"></a> CTabbedPane:: m_pTabWndRTC

Informações de classe de tempo de execução para um `CMFCTabCtrl` objeto derivado personalizado.

```
AFX_IMPORT_DATA static CRuntimeClass* m_pTabWndRTC;
```

### <a name="remarks"></a>Comentários

Defina essa variável de membro estático como um ponteiro para as informações de classe de tempo de execução de um `CMFCTabCtrl` objeto derivado se você estiver usando uma janela com guias personalizada dentro de um painel com guias.

## <a name="ctabbedpaneresettabs"></a><a name="resettabs"></a> CTabbedPane::ResetTabs

Redefine todos os painéis com guias para o estado padrão.

```
static void ResetTabs();
```

### <a name="remarks"></a>Comentários

Chame esse método para reverter todos os painéis com guias para seu estado padrão. Quando chamado, esse método redefine os tamanhos de borda e o estado de cor automático de todos os painéis com guias.

## <a name="ctabbedpanesettabautocolors"></a><a name="settabautocolors"></a> CTabbedPane::SetTabAutoColors

Define uma lista de cores personalizadas que são usadas quando o recurso de cor automática está habilitado.

```
static void SetTabAutoColors(const CArray<COLORREF, COLORREF>& arColors);
```

### <a name="parameters"></a>Parâmetros

*arColors*<br/>
no Contém a matriz de cores a ser definida.

### <a name="remarks"></a>Comentários

Use este método para personalizar a lista de cores que são usadas quando o recurso de cor automática está habilitado. Essa é uma função estática e afeta todos os painéis com guias em seu aplicativo.

Use [CTabbedPane:: EnableTabAutoColor](#enabletabautocolor) para habilitar ou desabilitar o recurso de cor automática.

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CDockablePane](../../mfc/reference/cdockablepane-class.md)<br/>
[Classe CBaseTabbedPane](../../mfc/reference/cbasetabbedpane-class.md)<br/>
[Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)
