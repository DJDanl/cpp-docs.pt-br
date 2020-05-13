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
ms.openlocfilehash: 17351eaed585ec34117a2ef825964fd51bd0d86b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365947"
---
# <a name="ctabbedpane-class"></a>Classe CTabbedPane

Implementa a funcionalidade de um painel com abas destacáveis.

ou mais detalhes veja o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da sua instalação do Visual Studio.

## <a name="syntax"></a>Sintaxe

```
class CTabbedPane : public CBaseTabbedPane
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|`CTabbedPane::CTabbedPane`|Construtor padrão.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CTabbedPane::DetachPane](#detachpane)|(Substitui [cbasetabbedpane::DetachPane](../../mfc/reference/cbasetabbedpane-class.md#detachpane).)|
|[CTabbedPane::HabilitaçãoTabAutoColor](#enabletabautocolor)|Ativa ou desativa a coloração automática das guias.|
|[CTabbedPane::FloatTab](#floattab)|Flutua um painel, mas apenas se o painel atualmente residir em uma guia destacável. (Overrides [CBaseTabbedPane::FloatTab](../../mfc/reference/cbasetabbedpane-class.md#floattab).)|
|[CTabbedPane::GetTabArea](#gettabarea)|Retorna o tamanho e a posição da área da guia dentro da janela com guias.|
|[CTabbedPane::GetTabWnd](#gettabwnd)||
|[CTabbedPane::HasAutoHideMode](#hasautohidemode)|Determina se o painel com guias pode ser comutado para o modo de ocultação automática. (Substitui [cbasetabbedpane::HasAutoHideMode](../../mfc/reference/cbasetabbedpane-class.md#hasautohidemode).)|
|[CTabbedPane::IsTabSiteLocalizaçãoBottom](#istablocationbottom)|Determina se as guias estão localizadas na parte inferior da janela.|
|[CTabbedPane::ResetTabs](#resettabs)|Redefine todos os painéis com guias para o estado padrão.|
|[CTabbedPane::SetTabAutoCores](#settabautocolors)|Define uma lista de cores personalizadas que podem ser usadas quando o recurso de cor automática está ativado.|

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|----------|-----------------|
|[CTabbedPane::m_bTabsAlwaysTop](#m_btabsalwaystop)|O local padrão para guias no aplicativo.|
|[CTabbedPane::m_pTabWndRTC](#m_ptabwndrtc)|Informações da classe de `CMFCTabCtrl`execução para um objeto derivado personalizado.|

## <a name="remarks"></a>Comentários

A estrutura cria automaticamente uma instância desta classe quando um usuário anexa um painel a outro apontando para a legenda do segundo painel. Todos os painéis de guia que são criados pela estrutura têm um ID de -1.

Para especificar guias regulares em vez de guias no estilo Outlook, passe o estilo AFX_CBRS_REGULAR_TABS para o método [CDockablePane::CreateEx.](../../mfc/reference/cdockablepane-class.md#createex)

Se você criar um painel com guias destacáveis, o painel pode ser destruído automaticamente pela estrutura, então você não deve armazenar o ponteiro. Para obter um ponteiro para o painel `CBasePane::GetParentTabbedPane` de abas, chame o método.

## <a name="example"></a>Exemplo

Neste exemplo criamos `CTabbedPane` um objeto. Em seguida, usamos [CBaseTabbedPane::AddTab](../../mfc/reference/cbasetabbedpane-class.md#addtab) para anexar guias adicionais.

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

## <a name="example"></a>Exemplo

Outra maneira de criar um objeto de barra de controle com guias é usar [CDockablePane::AttachToTabWnd](../../mfc/reference/cdockablepane-class.md#attachtotabwnd). O `AttachToTabWnd` método cria dinamicamente um objeto de painel com guias usando informações de classe de tempo de execução definidas por [CDockablePane::SetTabbedPaneRTC](../../mfc/reference/cdockablepane-class.md#settabbedpanertc).

Neste exemplo, criamos um painel com abas dinamicamente, anexamos duas guias e tornamos a segunda guia não destacável.

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

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cbasepane](../../mfc/reference/cbasepane-class.md)

[Cpane](../../mfc/reference/cpane-class.md)

[Cdockablepane](../../mfc/reference/cdockablepane-class.md)

[Cbasetabbedpane](../../mfc/reference/cbasetabbedpane-class.md)

[Ctabbedpane](../../mfc/reference/ctabbedpane-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxTabbedPane.h

## <a name="ctabbedpanedetachpane"></a><a name="detachpane"></a>CTabbedPane::DetachPane

```
virtual BOOL DetachPane(
    CWnd* pBar,
    BOOL bHide = FALSE);
```

### <a name="parameters"></a>Parâmetros

[em] *pBar*<br/>

[em] *bOcultar*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="ctabbedpaneenabletabautocolor"></a><a name="enabletabautocolor"></a>CTabbedPane::HabilitaçãoTabAutoColor

Ativa ou desativa a coloração automática das guias.

```
static void EnableTabAutoColor(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
[em] TRUE para habilitar a coloração automática de guias; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use este método estático para ativar ou desativar a coloração automática das guias em todos os painéis com guias no aplicativo. Quando esse recurso é ativado, cada guia é preenchida por sua própria cor. Você pode encontrar a lista de cores usadas para colorir as guias chamando o [método CMFCBaseTabCtrl::GetAutoColors.](../../mfc/reference/cmfcbasetabctrl-class.md#getautocolors)

Você pode especificar a lista de cores que serão usadas para guias chamando [CTabbedPane::SetTabAutoCores](#settabautocolors).

Por padrão, essa opção está desabilitada.

## <a name="ctabbedpanefloattab"></a><a name="floattab"></a>CTabbedPane::FloatTab

```
virtual BOOL FloatTab(
    CWnd* pBar,
    int nTabID,
    AFX_DOCK_METHOD dockMethod,
    BOOL bHide = FALSE);
```

### <a name="parameters"></a>Parâmetros

[em] *pBar*<br/>
[em] *nTabID*<br/>
[em] *dockMethod*<br/>
[em] *bOcultar*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="ctabbedpanegettabarea"></a><a name="gettabarea"></a>CTabbedPane::GetTabArea

Retorna o tamanho e a posição da área da guia na janela com as guias.

```
virtual void GetTabArea(
    CRect& rectTabAreaTop,
    CRect& rectTabAreaBottom) const;
```

### <a name="parameters"></a>Parâmetros

*rectTabAreaTop*<br/>
[fora] Contém o tamanho e a posição, nas coordenadas da tela, da área superior da guia.

*rectTabAreaBottom*<br/>
[fora] Contém o tamanho e a posição, nas coordenadas da tela, da área inferior da guia.

### <a name="remarks"></a>Comentários

A estrutura chama esse método para determinar como encaixar um painel que um usuário está arrastando. Quando o usuário arrasta um painel sobre a área da guia do painel de destino, a estrutura tenta adicioná-lo como uma nova guia do painel de destino. Caso contrário, ele tenta ancorar o painel para o lado do painel alvo, que envolve a criação de um novo recipiente de painel com um divisor de painel que separa os dois painéis.

Anular este método `CTabbedPane`em uma classe derivada para mudar esse comportamento.

## <a name="ctabbedpanegettabwnd"></a><a name="gettabwnd"></a>CTabbedPane::GetTabWnd

```
CMFCTabCtrl* GetTabWnd() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="ctabbedpanehasautohidemode"></a><a name="hasautohidemode"></a>CTabbedPane::HasAutoHideMode

```
virtual BOOL HasAutoHideMode() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="ctabbedpaneistablocationbottom"></a><a name="istablocationbottom"></a>CTabbedPane::IsTabSiteLocalizaçãoBottom

Determina se as guias estão localizadas na parte inferior da janela.

```
virtual BOOL IsTabLocationBottom() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se a área da guia estiver localizada na parte inferior da janela com as guias; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

## <a name="ctabbedpanem_btabsalwaystop"></a><a name="m_btabsalwaystop"></a>CTabbedPane::m_bTabsAlwaysTop

O local padrão para guias no aplicativo.

```
AFX_IMPORT_DATA static BOOL m_bTabsAlwaysTop;
```

### <a name="remarks"></a>Comentários

Defina este membro estático como TRUE para forçar todas as guias do aplicativo a serem exibidas na parte superior do painel de guias.

Você deve definir este valor antes que um painel de guias tenha sido criado.

O valor padrão é FALSE.

## <a name="ctabbedpanem_ptabwndrtc"></a><a name="m_ptabwndrtc"></a>CTabbedPane::m_pTabWndRTC

Informações da classe de `CMFCTabCtrl`execução para um objeto derivado personalizado.

```
AFX_IMPORT_DATA static CRuntimeClass* m_pTabWndRTC;
```

### <a name="remarks"></a>Comentários

Defina esta variável de membro estático em `CMFCTabCtrl`um ponteiro para as informações da classe de tempo de execução de um objeto derivado se você estiver usando uma janela com guias personalizadas dentro de um painel com guias.

## <a name="ctabbedpaneresettabs"></a><a name="resettabs"></a>CTabbedPane::ResetTabs

Redefine todos os painéis com guias para o estado padrão.

```
static void ResetTabs();
```

### <a name="remarks"></a>Comentários

Chame este método para reverter todos os painéis com guias para o seu estado padrão. Quando chamado, este método redefine os tamanhos de borda e o estado de cor automática de todos os painéis com guias.

## <a name="ctabbedpanesettabautocolors"></a><a name="settabautocolors"></a>CTabbedPane::SetTabAutoCores

Define uma lista de cores personalizadas que são usadas quando o recurso de cor automática é ativado.

```
static void SetTabAutoColors(const CArray<COLORREF, COLORREF>& arColors);
```

### <a name="parameters"></a>Parâmetros

*arCores*<br/>
[em] Contém a matriz de cores a definir.

### <a name="remarks"></a>Comentários

Use este método para personalizar a lista de cores usadas quando o recurso de cor automática estiver ativado. Esta é uma função estática e afeta todos os painéis com guias em sua aplicação.

Use [CTabbedPane::EnableTabAutoColor](#enabletabautocolor) para ativar ou desativar o recurso de cor automática.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CDockablePane](../../mfc/reference/cdockablepane-class.md)<br/>
[Classe CBaseTabbedPane](../../mfc/reference/cbasetabbedpane-class.md)<br/>
[Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)
