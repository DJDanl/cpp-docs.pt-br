---
title: Classe CDockSite
ms.date: 10/18/2018
f1_keywords:
- CDockSite
- AFXDOCKSITE/CDockSite
- AFXDOCKSITE/CDockSite::AddRow
- AFXDOCKSITE/CDockSite::AdjustDockingLayout
- AFXDOCKSITE/CDockSite::AdjustLayout
- AFXDOCKSITE/CDockSite::AlignDockSite
- AFXDOCKSITE/CDockSite::CalcFixedLayout
- AFXDOCKSITE/CDockSite::CanAcceptPane
- AFXDOCKSITE/CDockSite::CreateEx
- AFXDOCKSITE/CDockSite::CreateRow
- AFXDOCKSITE/CDockSite::DockPane
- AFXDOCKSITE/CDockSite::DoesAllowDynInsertBefore
- AFXDOCKSITE/CDockSite::FindRowIndex
- AFXDOCKSITE/CDockSite::FixupVirtualRects
- AFXDOCKSITE/CDockSite::GetDockSiteID
- AFXDOCKSITE/CDockSite::GetDockSiteRowsList
- AFXDOCKSITE/CDockSite::IsAccessibilityCompatible
- AFXDOCKSITE/CDockSite::IsDragMode
- AFXDOCKSITE/CDockSite::IsLastRow
- AFXDOCKSITE/CDockSite::IsRectWithinDockSite
- AFXDOCKSITE/CDockSite::IsResizable
- AFXDOCKSITE/CDockSite::MovePane
- AFXDOCKSITE/CDockSite::OnInsertRow
- AFXDOCKSITE/CDockSite::OnRemoveRow
- AFXDOCKSITE/CDockSite::OnResizeRow
- AFXDOCKSITE/CDockSite::OnSetWindowPos
- AFXDOCKSITE/CDockSite::OnShowRow
- AFXDOCKSITE/CDockSite::OnSizeParent
- AFXDOCKSITE/CDockSite::PaneFromPoint
- AFXDOCKSITE/CDockSite::DockPaneLeftOf
- AFXDOCKSITE/CDockSite::FindPaneByID
- AFXDOCKSITE/CDockSite::GetPaneList
- AFXDOCKSITE/CDockSite::RectSideFromPoint
- AFXDOCKSITE/CDockSite::RemovePane
- AFXDOCKSITE/CDockSite::RemoveRow
- AFXDOCKSITE/CDockSite::ReplacePane
- AFXDOCKSITE/CDockSite::RepositionPanes
- AFXDOCKSITE/CDockSite::ResizeDockSite
- AFXDOCKSITE/CDockSite::ResizeRow
- AFXDOCKSITE/CDockSite::ShowPane
- AFXDOCKSITE/CDockSite::ShowRow
- AFXDOCKSITE/CDockSite::SwapRows
helpviewer_keywords:
- CDockSite [MFC], AddRow
- CDockSite [MFC], AdjustDockingLayout
- CDockSite [MFC], AdjustLayout
- CDockSite [MFC], AlignDockSite
- CDockSite [MFC], CalcFixedLayout
- CDockSite [MFC], CanAcceptPane
- CDockSite [MFC], CreateEx
- CDockSite [MFC], CreateRow
- CDockSite [MFC], DockPane
- CDockSite [MFC], DoesAllowDynInsertBefore
- CDockSite [MFC], FindRowIndex
- CDockSite [MFC], FixupVirtualRects
- CDockSite [MFC], GetDockSiteID
- CDockSite [MFC], GetDockSiteRowsList
- CDockSite [MFC], IsAccessibilityCompatible
- CDockSite [MFC], IsDragMode
- CDockSite [MFC], IsLastRow
- CDockSite [MFC], IsRectWithinDockSite
- CDockSite [MFC], IsResizable
- CDockSite [MFC], MovePane
- CDockSite [MFC], OnInsertRow
- CDockSite [MFC], OnRemoveRow
- CDockSite [MFC], OnResizeRow
- CDockSite [MFC], OnSetWindowPos
- CDockSite [MFC], OnShowRow
- CDockSite [MFC], OnSizeParent
- CDockSite [MFC], PaneFromPoint
- CDockSite [MFC], DockPaneLeftOf
- CDockSite [MFC], FindPaneByID
- CDockSite [MFC], GetPaneList
- CDockSite [MFC], RectSideFromPoint
- CDockSite [MFC], RemovePane
- CDockSite [MFC], RemoveRow
- CDockSite [MFC], ReplacePane
- CDockSite [MFC], RepositionPanes
- CDockSite [MFC], ResizeDockSite
- CDockSite [MFC], ResizeRow
- CDockSite [MFC], ShowPane
- CDockSite [MFC], ShowRow
- CDockSite [MFC], SwapRows
ms.assetid: 0fcfff79-5f50-4281-b2de-a55653bbea40
ms.openlocfilehash: a95ee024d9df835102eeffc8443ae6225775aff7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375545"
---
# <a name="cdocksite-class"></a>Classe CDockSite

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

Fornece funcionalidade para organizar painéis derivados da [Classe CPane](../../mfc/reference/cpane-class.md) em conjuntos de linhas.

## <a name="syntax"></a>Sintaxe

```
class CDockSite: public CBasePane
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[cdockSite::Addrow](#addrow)||
|[CDockSite::AdjustDockingLayout](#adjustdockinglayout)|(Substitui [cbasepane::AdjustDockingLayout](../../mfc/reference/cbasepane-class.md#adjustdockinglayout).)|
|[CDockSite::AdjustLayout](#adjustlayout)|(Substitui [cbasepane::AdjustLayout](../../mfc/reference/cbasepane-class.md#adjustlayout).)|
|[CdockSite::AlignDockSite](#aligndocksite)||
|[CDockSite::CalcFixedLayout](#calcfixedlayout)|(Substitui [cbasepane::CalcFixedLayout](../../mfc/reference/cbasepane-class.md#calcfixedlayout).)|
|[CDockSite::CanAcceptPane](#canacceptpane)|(Substitui [cbasepane::CanAcceptPane](../../mfc/reference/cbasepane-class.md#canacceptpane).)|
|[cdockSite::CreateEx](#createex)|(Substitui [cbasepane::CreateEx](../../mfc/reference/cbasepane-class.md#createex).)|
|[cdockSite::Createrow](#createrow)||
|[CDockSite::DockPane](#dockpane)|(Substitui [CBasePane::DockPane](../../mfc/reference/cbasepane-class.md#dockpane).)|
|[CDockSite::DoesAllowDynInsertBefore](#doesallowdyninsertbefore)|(Substitui [CBasePane::DoesAllowDynInsertBefore](../../mfc/reference/cbasepane-class.md#doesallowdyninsertbefore).)|
|[cdocksite::FindrowIndex](#findrowindex)||
|[CDockSite::FixupVirtualRects](#fixupvirtualrects)||
|[cdocksite::getdocksiteid](#getdocksiteid)||
|[CDockSite::GetDockSiteRowsList](#getdocksiterowslist)||
|[CDockSite::IsAccessibilityCompatible](#isaccessibilitycompatible)|(Substitui `CBasePane::IsAccessibilityCompatible`.)|
|[cdockSite::IsDragMode](#isdragmode)||
|[cdockSite::Islastrow](#islastrow)||
|[CDockSite::IsRectWithinDockSite](#isrectwithindocksite)||
|[CDockSite::IsResizable](#isresizable)|(Substitui [cbasepane::IsResizable](../../mfc/reference/cbasepane-class.md#isresizable).)|
|[CDockSite::MovePane](#movepane)||
|[cdocksite::OnInsertrow](#oninsertrow)||
|[cdocksite::OnRemoverow](#onremoverow)||
|[CDockSite::OnResizeRow](#onresizerow)||
|[CDockSite::OnSetWindowPos](#onsetwindowpos)||
|[cdocksite::OnShowrow](#onshowrow)||
|[cdocksite::OnSizeParent](#onsizeparent)||
|[CDockSite::PaneFromPoint](#panefrompoint)|Retorna um painel que está ancorado no local das docas no ponto especificado pelo parâmetro dado.|
|[CDockSite::DockPaneLeftOf](#dockpaneleftof)|Acopla um painel à esquerda de outro painel.|
|[CDockSite::FindPaneByID](#findpanebyid)|Devolve o painel que é identificado pelo id dado.|
|[CDockSite::GetPaneList](#getpanelist)|Retorna uma lista de painéis que estão ancorados no local das docas.|
|[CDockSite::RectSideFromPoint](#rectsidefrompoint)||
|[CDockSite::RemovePane](#removepane)||
|[cdockSite::removerow](#removerow)||
|[CDockSite::ReplacePane](#replacepane)||
|[CDockSite::ReposicionarPanes](#repositionpanes)||
|[CDockSite::Redimensionaroosite de doca](#resizedocksite)||
|[CDockSite::ResizeRow](#resizerow)||
|[CDockSite::ShowPane](#showpane)|Mostra o painel.|
|[CDockSite::Showrow](#showrow)||
|[CDockSite::SwapRows](#swaprows)||

## <a name="remarks"></a>Comentários

A estrutura `CDockSite` cria objetos automaticamente quando você chama [CFrameWndEx::EnableDocking](../../mfc/reference/cframewndex-class.md#enabledocking). As janelas do local de doca estão posicionadas na borda da área do cliente na janela principal da moldura.

Você geralmente não precisa ligar para os serviços fornecidos pelo site de doca porque o [CFrameWndEx Class](../../mfc/reference/cframewndex-class.md) lida com esses serviços.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CDockSite` criar um objeto da classe.

[!code-cpp[NVC_MFC_RibbonApp#27](../../mfc/reference/codesnippet/cpp/cdocksite-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)\
-&nbsp;[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[CWnd](../../mfc/reference/cwnd-class.md)\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[CBasePane](../../mfc/reference/cbasepane-class.md)\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-&nbsp;[CdockSite](../../mfc/reference/cdocksite-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxDockSite.h

## <a name="cdocksiteaddrow"></a><a name="addrow"></a>cdockSite::Addrow

```
CDockingPanesRow* AddRow(
    POSITION pos,
    int nHeight);
```

### <a name="parameters"></a>Parâmetros

[em] *pos*<br/>

[em] *nAltura*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cdocksiteadjustdockinglayout"></a><a name="adjustdockinglayout"></a>CDockSite::AdjustDockingLayout

```
virtual void AdjustDockingLayout();
```

### <a name="remarks"></a>Comentários

## <a name="cdocksiteadjustlayout"></a><a name="adjustlayout"></a>CDockSite::AdjustLayout

```
virtual void AdjustLayout();
```

### <a name="remarks"></a>Comentários

## <a name="cdocksitealigndocksite"></a><a name="aligndocksite"></a>CdockSite::AlignDockSite

```
void AlignDockSite(
    const CRect& rectToAlignBy,
    CRect& rectResult,
    BOOL bMoveImmediately);
```

### <a name="parameters"></a>Parâmetros

[em] *rectToAlignBy*<br/>

[em] *rectResult*<br/>

[em] *bMoveImediatamente*<br/>

### <a name="remarks"></a>Comentários

## <a name="cdocksitecalcfixedlayout"></a><a name="calcfixedlayout"></a>CDockSite::CalcFixedLayout

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

## <a name="cdocksitecanacceptpane"></a><a name="canacceptpane"></a>CDockSite::CanAcceptPane

```
virtual BOOL CanAcceptPane(const CBasePane* pBar) const;
```

### <a name="parameters"></a>Parâmetros

[em] *pBar*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cdocksitecreateex"></a><a name="createex"></a>cdockSite::CreateEx

```
virtual BOOL CreateEx(
    DWORD dwStyleEx,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    DWORD dwControlBarStyle,
    CCreateContext* pContext = NULL);
```

### <a name="parameters"></a>Parâmetros

[em] *dwStyleEx*<br/>

[em] *dwStyle*<br/>

[em] *rect*<br/>

[em] *pParentWnd*<br/>

[em] *dwControlBarStyle*<br/>

[em] *pContext*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cdocksitecreaterow"></a><a name="createrow"></a>cdockSite::Createrow

```
virtual CDockingPanesRow* CreateRow(
    CDockSite* pParentDockBar,
    int nOffset,
    int nRowHeight);
```

### <a name="parameters"></a>Parâmetros

[em] *pParentDockBar*<br/>

[em] *nOffset*<br/>

[em] *nRowHeight*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cdocksitedockpane"></a><a name="dockpane"></a>CDockSite::DockPane

```
virtual void DockPane(
    CPane* pWnd,
    AFX_DOCK_METHOD dockMethod,
    LPCRECT lpRect = NULL);
```

### <a name="parameters"></a>Parâmetros

[em] *pWnd*<br/>

[em] *dockMethod*<br/>

[em] *lpRect*<br/>

### <a name="remarks"></a>Comentários

## <a name="cdocksitedockpaneleftof"></a><a name="dockpaneleftof"></a>CDockSite::DockPaneLeftOf

Acopla um painel à esquerda de outro painel.

```
virtual BOOL DockPaneLeftOf(
    CPane* pBarToDock,
    CPane* pTargetBar);
```

### <a name="parameters"></a>Parâmetros

*pBarToDock*<br/>
[dentro, fora] Um ponteiro para o painel a ser ancorado à esquerda de *pTargetBar*.

*pTargetBar*<br/>
[dentro, fora] Um ponteiro para o painel alvo.

### <a name="return-value"></a>Valor retornado

VERDADE se o painel estiver ancorado com sucesso; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

## <a name="cdocksitedoesallowdyninsertbefore"></a><a name="doesallowdyninsertbefore"></a>CDockSite::DoesAllowDynInsertBefore

```
virtual BOOL DoesAllowDynInsertBefore() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cdocksitefindpanebyid"></a><a name="findpanebyid"></a>CDockSite::FindPaneByID

Devolve o painel com a id dada.

```
CPane* FindPaneByID(UINT nID);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
[em] O comando id do painel a ser encontrado.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o painel com o ID de comando especificado ou NULL se o painel não for encontrado.

### <a name="remarks"></a>Comentários

## <a name="cdocksitefindrowindex"></a><a name="findrowindex"></a>cdocksite::FindrowIndex

```
int FindRowIndex(CDockingPanesRow* pRow);
```

### <a name="parameters"></a>Parâmetros

[em] *pRow*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cdocksitefixupvirtualrects"></a><a name="fixupvirtualrects"></a>CDockSite::FixupVirtualRects

```
virtual void FixupVirtualRects();
```

### <a name="remarks"></a>Comentários

## <a name="cdocksitegetdocksiteid"></a><a name="getdocksiteid"></a>cdocksite::getdocksiteid

```
virtual UINT GetDockSiteID() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cdocksitegetdocksiterowslist"></a><a name="getdocksiterowslist"></a>CDockSite::GetDockSiteRowsList

```
const CObList& GetDockSiteRowsList() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cdocksitegetpanelist"></a><a name="getpanelist"></a>CDockSite::GetPaneList

Retorna uma lista de painéis que estão ancorados no local das docas.

```
const CObList& GetPaneList() const;
```

### <a name="return-value"></a>Valor retornado

Uma referência somente à lista de painéis atualmente ancorados na barra de ancoragem.

## <a name="cdocksiteisaccessibilitycompatible"></a><a name="isaccessibilitycompatible"></a>CDockSite::IsAccessibilityCompatible

```
virtual BOOL IsAccessibilityCompatible();
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cdocksiteisdragmode"></a><a name="isdragmode"></a>cdockSite::IsDragMode

```
virtual BOOL IsDragMode() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cdocksiteislastrow"></a><a name="islastrow"></a>cdockSite::Islastrow

```
bool IsLastRow(CDockingPanesRow* pRow) const;
```

### <a name="parameters"></a>Parâmetros

[em] *pRow*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cdocksiteisrectwithindocksite"></a><a name="isrectwithindocksite"></a>CDockSite::IsRectWithinDockSite

```
BOOL IsRectWithinDockSite(
    CRect rect,
    CPoint& ptDelta);
```

### <a name="parameters"></a>Parâmetros

[em] *rect*<br/>

[em] *ptDelta*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cdocksiteisresizable"></a><a name="isresizable"></a>CDockSite::IsResizable

```
virtual BOOL IsResizable() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cdocksitemovepane"></a><a name="movepane"></a>CDockSite::MovePane

```
virtual BOOL MovePane(
    CPane* pWnd,
    UINT nFlags,
    CPoint ptOffset);
```

### <a name="parameters"></a>Parâmetros

[em] *pWnd*<br/>

[em] *nBandeiras*<br/>

[em] *ptOffset*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cdocksiteoninsertrow"></a><a name="oninsertrow"></a>cdocksite::OnInsertrow

```
virtual void OnInsertRow(POSITION pos);
```

### <a name="parameters"></a>Parâmetros

[em] *pos*<br/>

### <a name="remarks"></a>Comentários

## <a name="cdocksiteonremoverow"></a><a name="onremoverow"></a>cdocksite::OnRemoverow

```
virtual void OnRemoveRow(
    POSITION pos,
    BOOL bByShow = FALSE);
```

### <a name="parameters"></a>Parâmetros

[em] *pos*<br/>

[em] *bByShow*<br/>

### <a name="remarks"></a>Comentários

## <a name="cdocksiteonresizerow"></a><a name="onresizerow"></a>CDockSite::OnResizeRow

```
virtual int OnResizeRow(
    CDockingPanesRow* pRowToResize,
    int nOffset);
```

### <a name="parameters"></a>Parâmetros

[em] *pRowToResize*<br/>

[em] *nOffset*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cdocksiteonsizeparent"></a><a name="onsizeparent"></a>cdocksite::OnSizeParent

```
virtual void OnSizeParent(
    CRect& rectAvailable,
    UINT nSide,
    BOOL bExpand,
    int nOffset);
```

### <a name="parameters"></a>Parâmetros

[em] *rectAvailable*<br/>

[em] *nSide*<br/>

[em] *bExpandir*<br/>

[em] *nOffset*<br/>

### <a name="remarks"></a>Comentários

## <a name="cdocksiteonsetwindowpos"></a><a name="onsetwindowpos"></a>CDockSite::OnSetWindowPos

```
virtual BOOL OnSetWindowPos(
    const CWnd* pWndInsertAfter,
    const CRect& rectWnd,
    UINT nFlags);
```

### <a name="parameters"></a>Parâmetros

[em] *pWndInsertAfter*<br/>

[em] *rectWnd*<br/>

[em] *nBandeiras*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cdocksiteonshowrow"></a><a name="onshowrow"></a>cdocksite::OnShowrow

```
virtual void OnShowRow(
    POSITION pos,
    BOOL bShow);
```

### <a name="parameters"></a>Parâmetros

[em] *pos*<br/>

[em] *bMostrar*<br/>

### <a name="remarks"></a>Comentários

## <a name="cdocksitepanefrompoint"></a><a name="panefrompoint"></a>CDockSite::PaneFromPoint

Retorna um painel que está ancorado no local das docas no ponto especificado pelo parâmetro dado.

```
virtual CPane* PaneFromPoint(CPoint pt);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
[em] Um ponto, nas coordenadas da tela, para o painel recuperar.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o painel localizado no ponto especificado ou NULL se não houver painel no ponto especificado.

### <a name="remarks"></a>Comentários

## <a name="cdocksiterectsidefrompoint"></a><a name="rectsidefrompoint"></a>CDockSite::RectSideFromPoint

```
static int __stdcall RectSideFromPoint(
    const CRect& rect,
    const CPoint& point);
```

### <a name="parameters"></a>Parâmetros

[em] *rect*<br/>

[em] *ponto*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cdocksiteremovepane"></a><a name="removepane"></a>CDockSite::RemovePane

```
virtual void RemovePane(
    CPane* pWnd,
    AFX_DOCK_METHOD dockMethod);
```

### <a name="parameters"></a>Parâmetros

[em] *pWnd*<br/>

[em] *dockMethod*<br/>

### <a name="remarks"></a>Comentários

## <a name="cdocksiteremoverow"></a><a name="removerow"></a>cdockSite::removerow

```
void RemoveRow(CDockingPanesRow* pRow);
```

### <a name="parameters"></a>Parâmetros

[em] *pRow*<br/>

### <a name="remarks"></a>Comentários

## <a name="cdocksitereplacepane"></a><a name="replacepane"></a>CDockSite::ReplacePane

```
BOOL ReplacePane(
    CPane* pOldBar,
    CPane* pNewBar);
```

### <a name="parameters"></a>Parâmetros

[em] *pOldBar*<br/>

[em] *pNewBar*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cdocksiterepositionpanes"></a><a name="repositionpanes"></a>CDockSite::ReposicionarPanes

```
virtual void RepositionPanes(CRect& rectNewClientArea);
```

### <a name="parameters"></a>Parâmetros

[em] *rectNewClientArea*<br/>

### <a name="remarks"></a>Comentários

## <a name="cdocksiteresizedocksite"></a><a name="resizedocksite"></a>CDockSite::Redimensionaroosite de doca

```
void ResizeDockSite(
    int nNewWidth,
    int nNewHeight);
```

### <a name="parameters"></a>Parâmetros

[em] *nNewWidth*<br/>

[em] *nNewHeight*<br/>

### <a name="remarks"></a>Comentários

## <a name="cdocksiteresizerow"></a><a name="resizerow"></a>CDockSite::ResizeRow

```
int ResizeRow(
    CDockingPanesRow* pRow,
    int nNewSize,
    BOOL bAdjustLayout = TRUE);
```

### <a name="parameters"></a>Parâmetros

[em] *pRow*<br/>

[em] *nNewSize*<br/>

[em] *bAdjustLayout*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cdocksiteshowpane"></a><a name="showpane"></a>CDockSite::ShowPane

Mostra o painel.

```
virtual BOOL ShowPane(
    CBasePane* pBar,
    BOOL bShow,
    BOOL bDelay,
    BOOL bActivate);
```

### <a name="parameters"></a>Parâmetros

*Pbar*<br/>
[dentro, fora] Um ponteiro para o painel a ser mostrado ou escondido.

*Bshow*<br/>
[em] TRUE para especificar que o painel deve ser mostrado; FALSO para especificar que o painel deve ser escondido.

*bAtraso*<br/>
[em] TRUE para especificar que o layout do painel deve ser adiado até que o painel seja mostrado; caso contrário, FALSE.

*bAtivar*<br/>
[em] Este parâmetro não é usado.

### <a name="return-value"></a>Valor retornado

VERDADE se o painel foi mostrado ou escondido com sucesso. FALSO se o painel especificado não pertencer a este local de doca.

### <a name="remarks"></a>Comentários

Chame este método para mostrar ou esconder painéis ancorados. Normalmente, você não `CDockSite::ShowPane` precisa ligar diretamente, porque é chamado pela janela do quadro dos pais ou pelo painel base.

## <a name="cdocksiteshowrow"></a><a name="showrow"></a>CDockSite::Showrow

```
void ShowRow(
    CDockingPanesRow* pRow,
    BOOL bShow,
    BOOL bAdjustLayout);
```

### <a name="parameters"></a>Parâmetros

[em] *pRow*<br/>

[em] *bMostrar*<br/>

[em] *bAdjustLayout*<br/>

### <a name="remarks"></a>Comentários

## <a name="cdocksiteswaprows"></a><a name="swaprows"></a>CDockSite::SwapRows

```
void SwapRows(
    CDockingPanesRow* pFirstRow,
    CDockingPanesRow* pSecondRow);
```

### <a name="parameters"></a>Parâmetros

[em] *pFirstRow*<br/>

[em] *pSecondRow*<br/>

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CBasePane](../../mfc/reference/cbasepane-class.md)
