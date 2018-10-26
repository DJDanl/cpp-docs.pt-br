---
title: Classe CDockSite | Microsoft Docs
ms.custom: ''
ms.date: 10/18/2018
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6f2ae2cd18543e2ad27cd41a36406efc75facceb
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50062620"
---
# <a name="cdocksite-class"></a>Classe CDockSite

Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.

Fornece a funcionalidade para organizar os painéis derivados de [classe CPane](../../mfc/reference/cpane-class.md) em conjuntos de linhas.

## <a name="syntax"></a>Sintaxe

```
class CDockSite: public CBasePane
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDockSite::AddRow](#addrow)||
|[CDockSite::AdjustDockingLayout](#adjustdockinglayout)|(Substitui [CBasePane::AdjustDockingLayout](../../mfc/reference/cbasepane-class.md#adjustdockinglayout).)|
|[CDockSite::AdjustLayout](#adjustlayout)|(Substitui [CBasePane::AdjustLayout](../../mfc/reference/cbasepane-class.md#adjustlayout).)|
|[CDockSite::AlignDockSite](#aligndocksite)||
|[CDockSite::CalcFixedLayout](#calcfixedlayout)|(Substitui [CBasePane::CalcFixedLayout](../../mfc/reference/cbasepane-class.md#calcfixedlayout).)|
|[CDockSite::CanAcceptPane](#canacceptpane)|(Substitui [CBasePane::CanAcceptPane](../../mfc/reference/cbasepane-class.md#canacceptpane).)|
|[CDockSite::CreateEx](#createex)|(Substitui [CBasePane::CreateEx](../../mfc/reference/cbasepane-class.md#createex).)|
|[CDockSite::CreateRow](#createrow)||
|[CDockSite::DockPane](#dockpane)|(Substitui [CBasePane::DockPane](../../mfc/reference/cbasepane-class.md#dockpane).)|
|[CDockSite::DoesAllowDynInsertBefore](#doesallowdyninsertbefore)|(Substitui [CBasePane::DoesAllowDynInsertBefore](../../mfc/reference/cbasepane-class.md#doesallowdyninsertbefore).)|
|[CDockSite::FindRowIndex](#findrowindex)||
|[CDockSite::FixupVirtualRects](#fixupvirtualrects)||
|[CDockSite::GetDockSiteID](#getdocksiteid)||
|[CDockSite::GetDockSiteRowsList](#getdocksiterowslist)||
|[CDockSite::IsAccessibilityCompatible](#isaccessibilitycompatible)|(Substitui `CBasePane::IsAccessibilityCompatible`.)|
|[CDockSite::IsDragMode](#isdragmode)||
|[CDockSite::IsLastRow](#islastrow)||
|[CDockSite::IsRectWithinDockSite](#isrectwithindocksite)||
|[CDockSite::IsResizable](#isresizable)|(Substitui [CBasePane::IsResizable](../../mfc/reference/cbasepane-class.md#isresizable).)|
|[CDockSite::MovePane](#movepane)||
|[CDockSite::OnInsertRow](#oninsertrow)||
|[CDockSite::OnRemoveRow](#onremoverow)||
|[CDockSite::OnResizeRow](#onresizerow)||
|[CDockSite::OnSetWindowPos](#onsetwindowpos)||
|[CDockSite::OnShowRow](#onshowrow)||
|[CDockSite::OnSizeParent](#onsizeparent)||
|[CDockSite::PaneFromPoint](#panefrompoint)|Retorna um painel que está encaixado no local de encaixe no ponto especificado pelo parâmetro fornecido.|
|[CDockSite::DockPaneLeftOf](#dockpaneleftof)|Encaixa um painel à esquerda de outro painel.|
|[CDockSite::FindPaneByID](#findpanebyid)|Retorna o painel que é identificado pela ID determinada.|
|[CDockSite::GetPaneList](#getpanelist)|Retorna uma lista de painéis que são encaixadas no local de encaixe.|
|[CDockSite::RectSideFromPoint](#rectsidefrompoint)||
|[CDockSite::RemovePane](#removepane)||
|[CDockSite::RemoveRow](#removerow)||
|[CDockSite::ReplacePane](#replacepane)||
|[CDockSite::RepositionPanes](#repositionpanes)||
|[CDockSite::ResizeDockSite](#resizedocksite)||
|[CDockSite::ResizeRow](#resizerow)||
|[CDockSite::ShowPane](#showpane)|Mostra o painel.|
|[CDockSite::ShowRow](#showrow)||
|[CDockSite::SwapRows](#swaprows)||

## <a name="remarks"></a>Comentários

A estrutura cria `CDockSite` objetos automaticamente quando você chama [CFrameWndEx::EnableDocking](../../mfc/reference/cframewndex-class.md#enabledocking). Encaixar janelas de site são posicionadas na borda da área de cliente na janela do quadro principal.

Você normalmente não precisa chamar os serviços fornecidos pelo local de encaixe, porque [classe CFrameWndEx](../../mfc/reference/cframewndex-class.md) lida com esses serviços.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como criar um objeto do `CDockSite` classe.

[!code-cpp[NVC_MFC_RibbonApp#27](../../mfc/reference/codesnippet/cpp/cdocksite-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md) [CCmdTarget](../../mfc/reference/ccmdtarget-class.md) [CWnd](../../mfc/reference/cwnd-class.md)

[CBasePane](../../mfc/reference/cbasepane-class.md) [CDockSite](../../mfc/reference/cdocksite-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxDockSite.h

##  <a name="addrow"></a>  CDockSite::AddRow

```
CDockingPanesRow* AddRow(
    POSITION pos,
    int nHeight);
```

### <a name="parameters"></a>Parâmetros

[in] *pos*<br/>

[in] *nHeight*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="adjustdockinglayout"></a>  CDockSite::AdjustDockingLayout

```
virtual void AdjustDockingLayout();
```

### <a name="remarks"></a>Comentários

##  <a name="adjustlayout"></a>  CDockSite::AdjustLayout

```
virtual void AdjustLayout();
```

### <a name="remarks"></a>Comentários

##  <a name="aligndocksite"></a>  CDockSite::AlignDockSite

```
void AlignDockSite(
    const CRect& rectToAlignBy,
    CRect& rectResult,
    BOOL bMoveImmediately);
```

### <a name="parameters"></a>Parâmetros

[in] *rectToAlignBy*<br/>

[in] *rectResult*<br/>

[in] *bMoveImmediately*<br/>

### <a name="remarks"></a>Comentários

##  <a name="calcfixedlayout"></a>  CDockSite::CalcFixedLayout

```
virtual CSize CalcFixedLayout(
    BOOL bStretch,
    BOOL bHorz);
```

### <a name="parameters"></a>Parâmetros

[in] *bStretch*<br/>

[in] *bHorz*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="canacceptpane"></a>  CDockSite::CanAcceptPane

```
virtual BOOL CanAcceptPane(const CBasePane* pBar) const;
```

### <a name="parameters"></a>Parâmetros

[in] *pBar*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="createex"></a>  CDockSite::CreateEx

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

[in] *dwStyleEx*<br/>

[in] *dwStyle*<br/>

[in] *rect*<br/>

[in] *pParentWnd*<br/>

[in] *dwControlBarStyle*<br/>

[in] *pContext*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="createrow"></a>  CDockSite::CreateRow

```
virtual CDockingPanesRow* CreateRow(
    CDockSite* pParentDockBar,
    int nOffset,
    int nRowHeight);
```

### <a name="parameters"></a>Parâmetros

[in] *pParentDockBar*<br/>

[in] *nOffset*<br/>

[in] *nRowHeight*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="dockpane"></a>  CDockSite::DockPane

```
virtual void DockPane(
    CPane* pWnd,
    AFX_DOCK_METHOD dockMethod,
    LPCRECT lpRect = NULL);
```

### <a name="parameters"></a>Parâmetros

[in] *Apropriei*<br/>

[in] *dockMethod*<br/>

[in] *lpRect*<br/>

### <a name="remarks"></a>Comentários

##  <a name="dockpaneleftof"></a>  CDockSite::DockPaneLeftOf

Encaixa um painel à esquerda de outro painel.

```
virtual BOOL DockPaneLeftOf(
    CPane* pBarToDock,
    CPane* pTargetBar);
```

### <a name="parameters"></a>Parâmetros

*pBarToDock*<br/>
[no, out] Um ponteiro para o painel para ser encaixado à esquerda do *pTargetBar*.

*pTargetBar*<br/>
[no, out] Um ponteiro para o painel de destino.

### <a name="return-value"></a>Valor de retorno

TRUE se o painel estiver encaixado com êxito; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="doesallowdyninsertbefore"></a>  CDockSite::DoesAllowDynInsertBefore

```
virtual BOOL DoesAllowDynInsertBefore() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="findpanebyid"></a>  CDockSite::FindPaneByID

Retorna o painel com a ID especificada.

```
CPane* FindPaneByID(UINT nID);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
[in] A ID de comando do painel a ser localizada.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o painel com o ID de comando especificada ou nulo se o painel não for encontrado.

### <a name="remarks"></a>Comentários

##  <a name="findrowindex"></a>  CDockSite::FindRowIndex

```
int FindRowIndex(CDockingPanesRow* pRow);
```

### <a name="parameters"></a>Parâmetros

[in] *pRow*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="fixupvirtualrects"></a>  CDockSite::FixupVirtualRects

```
virtual void FixupVirtualRects();
```

### <a name="remarks"></a>Comentários

##  <a name="getdocksiteid"></a>  CDockSite::GetDockSiteID

```
virtual UINT GetDockSiteID() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getdocksiterowslist"></a>  CDockSite::GetDockSiteRowsList

```
const CObList& GetDockSiteRowsList() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getpanelist"></a>  CDockSite::GetPaneList

Retorna uma lista de painéis que são encaixadas no local de encaixe.

```
const CObList& GetPaneList() const;
```

### <a name="return-value"></a>Valor de retorno

Uma referência somente leitura à lista de painéis encaixada atualmente na barra de encaixe.

##  <a name="isaccessibilitycompatible"></a>  CDockSite::IsAccessibilityCompatible

```
virtual BOOL IsAccessibilityCompatible();
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="isdragmode"></a>  CDockSite::IsDragMode

```
virtual BOOL IsDragMode() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="islastrow"></a>  CDockSite::IsLastRow

```
bool IsLastRow(CDockingPanesRow* pRow) const;
```

### <a name="parameters"></a>Parâmetros

[in] *pRow*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="isrectwithindocksite"></a>  CDockSite::IsRectWithinDockSite

```
BOOL IsRectWithinDockSite(
    CRect rect,
    CPoint& ptDelta);
```

### <a name="parameters"></a>Parâmetros

[in] *rect*<br/>

[in] *ptDelta*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="isresizable"></a>  CDockSite::IsResizable

```
virtual BOOL IsResizable() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="movepane"></a>  CDockSite::MovePane

```
virtual BOOL MovePane(
    CPane* pWnd,
    UINT nFlags,
    CPoint ptOffset);
```

### <a name="parameters"></a>Parâmetros

[in] *Apropriei*<br/>

[in] *nFlags*<br/>

[in] *ptOffset*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="oninsertrow"></a>  CDockSite::OnInsertRow

```
virtual void OnInsertRow(POSITION pos);
```

### <a name="parameters"></a>Parâmetros

[in] *pos*<br/>

### <a name="remarks"></a>Comentários

##  <a name="onremoverow"></a>  CDockSite::OnRemoveRow

```
virtual void OnRemoveRow(
    POSITION pos,
    BOOL bByShow = FALSE);
```

### <a name="parameters"></a>Parâmetros

[in] *pos*<br/>

[in] *bByShow*<br/>

### <a name="remarks"></a>Comentários

##  <a name="onresizerow"></a>  CDockSite::OnResizeRow

```
virtual int OnResizeRow(
    CDockingPanesRow* pRowToResize,
    int nOffset);
```

### <a name="parameters"></a>Parâmetros

[in] *pRowToResize*<br/>

[in] *nOffset*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="onsizeparent"></a>  CDockSite::OnSizeParent

```
virtual void OnSizeParent(
    CRect& rectAvailable,
    UINT nSide,
    BOOL bExpand,
    int nOffset);
```

### <a name="parameters"></a>Parâmetros

[in] *rectAvailable*<br/>

[in] *Xplorando o*<br/>

[in] *bExpand*<br/>

[in] *nOffset*<br/>

### <a name="remarks"></a>Comentários

##  <a name="onsetwindowpos"></a>  CDockSite::OnSetWindowPos

```
virtual BOOL OnSetWindowPos(
    const CWnd* pWndInsertAfter,
    const CRect& rectWnd,
    UINT nFlags);
```

### <a name="parameters"></a>Parâmetros

[in] *pWndInsertAfter*<br/>

[in] *rectWnd*<br/>

[in] *nFlags*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="onshowrow"></a>  CDockSite::OnShowRow

```
virtual void OnShowRow(
    POSITION pos,
    BOOL bShow);
```

### <a name="parameters"></a>Parâmetros

[in] *pos*<br/>

[in] *bMostrar*<br/>

### <a name="remarks"></a>Comentários

##  <a name="panefrompoint"></a>  CDockSite::PaneFromPoint

Retorna um painel que está encaixado no local de encaixe no ponto especificado pelo parâmetro fornecido.

```
virtual CPane* PaneFromPoint(CPoint pt);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
[in] Um ponto em coordenadas da tela, para o painel recuperar.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o painel, localizado no ponto especificado ou nulo se nenhum painel estava presente no ponto especificado.

### <a name="remarks"></a>Comentários

##  <a name="rectsidefrompoint"></a>  CDockSite::RectSideFromPoint

```
static int __stdcall RectSideFromPoint(
    const CRect& rect,
    const CPoint& point);
```

### <a name="parameters"></a>Parâmetros

[in] *rect*<br/>

[in] *ponto*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="removepane"></a>  CDockSite::RemovePane

```
virtual void RemovePane(
    CPane* pWnd,
    AFX_DOCK_METHOD dockMethod);
```

### <a name="parameters"></a>Parâmetros

[in] *Apropriei*<br/>

[in] *dockMethod*<br/>

### <a name="remarks"></a>Comentários

##  <a name="removerow"></a>  CDockSite::RemoveRow

```
void RemoveRow(CDockingPanesRow* pRow);
```

### <a name="parameters"></a>Parâmetros

[in] *pRow*<br/>

### <a name="remarks"></a>Comentários

##  <a name="replacepane"></a>  CDockSite::ReplacePane

```
BOOL ReplacePane(
    CPane* pOldBar,
    CPane* pNewBar);
```

### <a name="parameters"></a>Parâmetros

[in] *pOldBar*<br/>

[in] *pNewBar*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="repositionpanes"></a>  CDockSite::RepositionPanes

```
virtual void RepositionPanes(CRect& rectNewClientArea);
```

### <a name="parameters"></a>Parâmetros

[in] *rectNewClientArea*<br/>

### <a name="remarks"></a>Comentários

##  <a name="resizedocksite"></a>  CDockSite::ResizeDockSite

```
void ResizeDockSite(
    int nNewWidth,
    int nNewHeight);
```

### <a name="parameters"></a>Parâmetros

[in] *nNewWidth*<br/>

[in] *nNewHeight*<br/>

### <a name="remarks"></a>Comentários

##  <a name="resizerow"></a>  CDockSite::ResizeRow

```
int ResizeRow(
    CDockingPanesRow* pRow,
    int nNewSize,
    BOOL bAdjustLayout = TRUE);
```

### <a name="parameters"></a>Parâmetros

[in] *pRow*<br/>

[in] *nNewSize*<br/>

[in] *bAdjustLayout*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="showpane"></a>  CDockSite::ShowPane

Mostra o painel.

```
virtual BOOL ShowPane(
    CBasePane* pBar,
    BOOL bShow,
    BOOL bDelay,
    BOOL bActivate);
```

### <a name="parameters"></a>Parâmetros

*pBar*<br/>
[no, out] Um ponteiro para o painel para ser mostrado ou ocultado.

*bMostrar*<br/>
[in] TRUE para especificar que o painel deve ser exibido; FALSO para especificar que o painel deve ser ocultada.

*bDelay*<br/>
[in] TRUE para especificar que o layout do painel deve ser atrasado até que o painel é exibido; Caso contrário, FALSE.

*bActivate*<br/>
[in] Esse parâmetro não é usado.

### <a name="return-value"></a>Valor de retorno

TRUE se o painel foi mostrado ou ocultado com êxito. FALSE se o painel especificado não pertence a este site de encaixe.

### <a name="remarks"></a>Comentários

Chame esse método para mostrar ou ocultar painéis encaixados. Normalmente, você não precisa chamar `CDockSite::ShowPane` diretamente, porque ele é chamado pela janela de quadro pai ou pelo painel de base.

##  <a name="showrow"></a>  CDockSite::ShowRow

```
void ShowRow(
    CDockingPanesRow* pRow,
    BOOL bShow,
    BOOL bAdjustLayout);
```

### <a name="parameters"></a>Parâmetros

[in] *pRow*<br/>

[in] *bMostrar*<br/>

[in] *bAdjustLayout*<br/>

### <a name="remarks"></a>Comentários

##  <a name="swaprows"></a>  CDockSite::SwapRows

```
void SwapRows(
    CDockingPanesRow* pFirstRow,
    CDockingPanesRow* pSecondRow);
```

### <a name="parameters"></a>Parâmetros

[in] *pFirstRow*<br/>

[in] *pSecondRow*<br/>

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CBasePane](../../mfc/reference/cbasepane-class.md)
