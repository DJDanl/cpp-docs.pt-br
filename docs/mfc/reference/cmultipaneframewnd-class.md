---
title: Classe CMultiPaneFrameWnd | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMultiPaneFrameWnd
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::AddPane
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::AddRecentPane
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::AdjustLayout
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::AdjustPaneFrames
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::CalcExpectedDockedRect
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::CanBeAttached
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::CanBeDockedToPane
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::CheckGripperVisibility
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::CloseMiniFrame
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::ConvertToTabbedDocument
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::DockFrame
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::DockPane
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::DockRecentPaneToMainFrame
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::GetCaptionText
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::GetPaneContainerManager
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::GetFirstVisiblePane
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::GetPane
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::GetPaneCount
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::GetVisiblePaneCount
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::InsertPane
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::LoadState
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::OnDockToRecentPos
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::OnKillRollUpTimer
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::OnPaneRecalcLayout
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::OnSetRollUpTimer
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::OnShowPane
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::PaneFromPoint
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::RemoveNonValidPanes
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::RemovePane
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::ReplacePane
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::SaveState
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::Serialize
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::SetDockState
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::SetLastFocusedPane
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::SetPreDockState
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::StoreRecentDockSiteInfo
- AFXMULTIPANEFRAMEWND/CMultiPaneFrameWnd::StoreRecentTabRelatedInfo
dev_langs:
- C++
helpviewer_keywords:
- CMultiPaneFrameWnd [MFC], AddPane
- CMultiPaneFrameWnd [MFC], AddRecentPane
- CMultiPaneFrameWnd [MFC], AdjustLayout
- CMultiPaneFrameWnd [MFC], AdjustPaneFrames
- CMultiPaneFrameWnd [MFC], CalcExpectedDockedRect
- CMultiPaneFrameWnd [MFC], CanBeAttached
- CMultiPaneFrameWnd [MFC], CanBeDockedToPane
- CMultiPaneFrameWnd [MFC], CheckGripperVisibility
- CMultiPaneFrameWnd [MFC], CloseMiniFrame
- CMultiPaneFrameWnd [MFC], ConvertToTabbedDocument
- CMultiPaneFrameWnd [MFC], DockFrame
- CMultiPaneFrameWnd [MFC], DockPane
- CMultiPaneFrameWnd [MFC], DockRecentPaneToMainFrame
- CMultiPaneFrameWnd [MFC], GetCaptionText
- CMultiPaneFrameWnd [MFC], GetPaneContainerManager
- CMultiPaneFrameWnd [MFC], GetFirstVisiblePane
- CMultiPaneFrameWnd [MFC], GetPane
- CMultiPaneFrameWnd [MFC], GetPaneCount
- CMultiPaneFrameWnd [MFC], GetVisiblePaneCount
- CMultiPaneFrameWnd [MFC], InsertPane
- CMultiPaneFrameWnd [MFC], LoadState
- CMultiPaneFrameWnd [MFC], OnDockToRecentPos
- CMultiPaneFrameWnd [MFC], OnKillRollUpTimer
- CMultiPaneFrameWnd [MFC], OnPaneRecalcLayout
- CMultiPaneFrameWnd [MFC], OnSetRollUpTimer
- CMultiPaneFrameWnd [MFC], OnShowPane
- CMultiPaneFrameWnd [MFC], PaneFromPoint
- CMultiPaneFrameWnd [MFC], RemoveNonValidPanes
- CMultiPaneFrameWnd [MFC], RemovePane
- CMultiPaneFrameWnd [MFC], ReplacePane
- CMultiPaneFrameWnd [MFC], SaveState
- CMultiPaneFrameWnd [MFC], Serialize
- CMultiPaneFrameWnd [MFC], SetDockState
- CMultiPaneFrameWnd [MFC], SetLastFocusedPane
- CMultiPaneFrameWnd [MFC], SetPreDockState
- CMultiPaneFrameWnd [MFC], StoreRecentDockSiteInfo
- CMultiPaneFrameWnd [MFC], StoreRecentTabRelatedInfo
ms.assetid: 989a548e-0d70-46b7-a513-8cf740e1be3e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ceb88a5d9ceb0265e3c86737cbe2ff27e6a34cf5
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50066442"
---
# <a name="cmultipaneframewnd-class"></a>Classe CMultiPaneFrameWnd

O `CMultiPaneFrameWnd` classe estende [classe CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md). Ele pode suportar vários painéis. Em vez de um único manipulador inserido para uma barra de controle `CMultiPaneFrameWnd` contém uma [classe CPaneContainerManager](../../mfc/reference/cpanecontainermanager-class.md) objeto que permite que o usuário encaixe um `CMultiPaneFrameWnd` para outro e dinamicamente criar vários flutuante, com guias Windows.

Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.

## <a name="syntax"></a>Sintaxe

```
class CMultiPaneFrameWnd : public CPaneFrameWnd
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMultiPaneFrameWnd::AddPane](#addpane)|Adiciona um painel. (Substitui [CPaneFrameWnd::AddPane](../../mfc/reference/cpaneframewnd-class.md#addpane).)|
|[CMultiPaneFrameWnd::AddRecentPane](#addrecentpane)||
|[CMultiPaneFrameWnd::AdjustLayout](#adjustlayout)|Ajusta o layout da janela com minimoldura. (Substitui [CPaneFrameWnd::AdjustLayout](../../mfc/reference/cpaneframewnd-class.md#adjustlayout).)|
|[CMultiPaneFrameWnd::AdjustPaneFrames](#adjustpaneframes)|(Substitui [CPaneFrameWnd::AdjustPaneFrames](../../mfc/reference/cpaneframewnd-class.md#adjustpaneframes).)|
|[CMultiPaneFrameWnd::CalcExpectedDockedRect](#calcexpecteddockedrect)|Calcula o retângulo esperado de uma janela encaixada. (Substitui [CPaneFrameWnd::CalcExpectedDockedRect](../../mfc/reference/cpaneframewnd-class.md#calcexpecteddockedrect).)|
|[CMultiPaneFrameWnd::CanBeAttached](#canbeattached)|Determina se o painel atual pode encaixar em outra janela do painel ou quadro. (Substitui [CPaneFrameWnd::CanBeAttached](../../mfc/reference/cpaneframewnd-class.md#canbeattached).)|
|[CMultiPaneFrameWnd::CanBeDockedToPane](#canbedockedtopane)|Determina se a janela com minimoldura pode encaixar um painel. (Substitui [CPaneFrameWnd::CanBeDockedToPane](../../mfc/reference/cpaneframewnd-class.md#canbedockedtopane).)|
|[CMultiPaneFrameWnd::CheckGripperVisibility](#checkgrippervisibility)|(Substitui [CPaneFrameWnd::CheckGripperVisibility](../../mfc/reference/cpaneframewnd-class.md#checkgrippervisibility).)|
|[CMultiPaneFrameWnd::CloseMiniFrame](#closeminiframe)|(Substitui `CPaneFrameWnd::CloseMiniFrame`.)|
|[CMultiPaneFrameWnd::ConvertToTabbedDocument](#converttotabbeddocument)|Converte o painel em um documento com guias. (Substitui [CPaneFrameWnd::ConvertToTabbedDocument](../../mfc/reference/cpaneframewnd-class.md#converttotabbeddocument).)|
|[CMultiPaneFrameWnd::DockFrame](#dockframe)||
|[CMultiPaneFrameWnd::DockPane](#dockpane)|Encaixa o painel. (Substitui [CPaneFrameWnd::DockPane](../../mfc/reference/cpaneframewnd-class.md#dockpane).)|
|[CMultiPaneFrameWnd::DockRecentPaneToMainFrame](#dockrecentpanetomainframe)||
|[CMultiPaneFrameWnd::GetCaptionText](#getcaptiontext)|Retorna o texto da legenda. (Substitui [CPaneFrameWnd::GetCaptionText](../../mfc/reference/cpaneframewnd-class.md#getcaptiontext).)|
|[CMultiPaneFrameWnd::GetPaneContainerManager](#getpanecontainermanager)|Retorna uma referência para o objeto do Gerenciador de contêiner interno.|
|[CMultiPaneFrameWnd::GetFirstVisiblePane](#getfirstvisiblepane)|Retorna o primeiro painel visível que está contido em uma janela com minimoldura. (Substitui [CPaneFrameWnd::GetFirstVisiblePane](../../mfc/reference/cpaneframewnd-class.md#getfirstvisiblepane).)|
|[CMultiPaneFrameWnd::GetPane](#getpane)|Retorna um painel que está contido na janela com minimoldura. (Substitui [CPaneFrameWnd::GetPane](../../mfc/reference/cpaneframewnd-class.md#getpane).)|
|[CMultiPaneFrameWnd::GetPaneCount](#getpanecount)|Retorna o número de painéis que estão contidos em uma janela com minimoldura. (Substitui [CPaneFrameWnd::GetPaneCount](../../mfc/reference/cpaneframewnd-class.md#getpanecount).)|
|[CMultiPaneFrameWnd::GetVisiblePaneCount](#getvisiblepanecount)|Retorna o número de painéis visíveis que estão contidos em uma janela com minimoldura. (Substitui [CPaneFrameWnd::GetVisiblePaneCount](../../mfc/reference/cpaneframewnd-class.md#getvisiblepanecount).)|
|[CMultiPaneFrameWnd::InsertPane](#insertpane)||
|[CMultiPaneFrameWnd::LoadState](#loadstate)|Carrega o estado do painel do registro. (Substitui [CPaneFrameWnd::LoadState](../../mfc/reference/cpaneframewnd-class.md#loadstate).)|
|[CMultiPaneFrameWnd::OnDockToRecentPos](#ondocktorecentpos)|Encaixa a janela com minimoldura na sua posição mais recente. (Substitui [CPaneFrameWnd::OnDockToRecentPos](../../mfc/reference/cpaneframewnd-class.md#ondocktorecentpos).)|
|[CMultiPaneFrameWnd::OnKillRollUpTimer](#onkillrolluptimer)|Interrompe o temporizador de pacote cumulativo de atualizações. (Substitui [CPaneFrameWnd::OnKillRollUpTimer](../../mfc/reference/cpaneframewnd-class.md#onkillrolluptimer).)|
|[CMultiPaneFrameWnd::OnPaneRecalcLayout](#onpanerecalclayout)|Ajusta o layout de um painel de dentro de uma janela com minimoldura. (Substitui [CPaneFrameWnd::OnPaneRecalcLayout](../../mfc/reference/cpaneframewnd-class.md#onpanerecalclayout).)|
|[CMultiPaneFrameWnd::OnSetRollUpTimer](#onsetrolluptimer)|Define o temporizador de pacote cumulativo de atualizações. (Substitui [CPaneFrameWnd::OnSetRollUpTimer](../../mfc/reference/cpaneframewnd-class.md#onsetrolluptimer).)|
|[CMultiPaneFrameWnd::OnShowPane](#onshowpane)|Chamado pelo framework quando um painel da janela com minimoldura é ocultado ou exibido. (Substitui [CPaneFrameWnd::OnShowPane](../../mfc/reference/cpaneframewnd-class.md#onshowpane).)|
|[CMultiPaneFrameWnd::PaneFromPoint](#panefrompoint)|Retorna um painel se ele contiver um ponto fornecido pelo usuário dentro de uma janela com minimoldura. (Substitui [CPaneFrameWnd::PaneFromPoint](../../mfc/reference/cpaneframewnd-class.md#panefrompoint).)|
|[CMultiPaneFrameWnd::RemoveNonValidPanes](#removenonvalidpanes)|Chamado pelo framework para remover os painéis não válido. (Substitui [CPaneFrameWnd::RemoveNonValidPanes](../../mfc/reference/cpaneframewnd-class.md#removenonvalidpanes).)|
|[CMultiPaneFrameWnd::RemovePane](#removepane)|Remove um painel de janela com minimoldura. (Substitui [CPaneFrameWnd::RemovePane](../../mfc/reference/cpaneframewnd-class.md#removepane).)|
|[CMultiPaneFrameWnd::ReplacePane](#replacepane)|Substitui um painel com outra. (Substitui [CPaneFrameWnd::ReplacePane](../../mfc/reference/cpaneframewnd-class.md#replacepane).)|
|[CMultiPaneFrameWnd::SaveState](#savestate)|Salva o estado do painel no registro. (Substitui [CPaneFrameWnd::SaveState](../../mfc/reference/cpaneframewnd-class.md#savestate).)|
|[CMultiPaneFrameWnd::Serialize](#serialize)|(Substitui `CPaneFrameWnd::Serialize`.)|
|[CMultiPaneFrameWnd::SetDockState](#setdockstate)|Define o estado de encaixe. (Substitui [CPaneFrameWnd::SetDockState](../../mfc/reference/cpaneframewnd-class.md#setdockstate).)|
|[CMultiPaneFrameWnd::SetLastFocusedPane](#setlastfocusedpane)||
|[CMultiPaneFrameWnd::SetPreDockState](#setpredockstate)|Define o estado predocking. (Substitui [CPaneFrameWnd::SetPreDockState](../../mfc/reference/cpaneframewnd-class.md#setpredockstate).)|
|[CMultiPaneFrameWnd::StoreRecentDockSiteInfo](#storerecentdocksiteinfo)|(Substitui [CPaneFrameWnd::StoreRecentDockSiteInfo](../../mfc/reference/cpaneframewnd-class.md#storerecentdocksiteinfo).)|
|[CMultiPaneFrameWnd::StoreRecentTabRelatedInfo](#storerecenttabrelatedinfo)|(Substitui [CPaneFrameWnd::StoreRecentTabRelatedInfo](../../mfc/reference/cpaneframewnd-class.md#storerecenttabrelatedinfo).)|

## <a name="remarks"></a>Comentários

A maioria dos métodos nessa classe substituir métodos na [classe CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md) classe.

Se um painel usa o estilo AFX_CBRS_AUTO_ROLLUP e o usuário encaixa esse painel para uma janela do quadro de vários painéis, o usuário pode acumular a janela independentemente das configurações de estilo dos outros painéis encaixados.

O framework cria automaticamente um `CMultiPaneFrameWnd` objeto quando o usuário flutua um painel que usa o estilo CBRS_FLOAT_MULTI.

Para obter informações sobre uma classe a partir de `CPaneFrameWnd` de classe e criar dinamicamente, consulte [CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como recuperar um ponteiro para um `CMultiPaneFrameWnd` objeto. Este trecho de código é parte do [exemplo de definir o tamanho do painel](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_SetPaneSize#4](../../mfc/reference/codesnippet/cpp/cmultipaneframewnd-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md)

[CMultiPaneFrameWnd](../../mfc/reference/cmultipaneframewnd-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxMultiPaneFrameWnd.h

##  <a name="addpane"></a>  CMultiPaneFrameWnd::AddPane

```
virtual void AddPane(CBasePane* pWnd);
```

### <a name="parameters"></a>Parâmetros

[in] *Apropriei*<br/>

### <a name="remarks"></a>Comentários

##  <a name="addrecentpane"></a>  CMultiPaneFrameWnd::AddRecentPane

```
virtual BOOL AddRecentPane(CDockablePane* pBar);
```

### <a name="parameters"></a>Parâmetros

[in] *pBar*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="adjustlayout"></a>  CMultiPaneFrameWnd::AdjustLayout

```
virtual void AdjustLayout();
```

### <a name="remarks"></a>Comentários

##  <a name="adjustpaneframes"></a>  CMultiPaneFrameWnd::AdjustPaneFrames

```
virtual void AdjustPaneFrames();
```

### <a name="remarks"></a>Comentários

##  <a name="calcexpecteddockedrect"></a>  CMultiPaneFrameWnd::CalcExpectedDockedRect

```
virtual void CalcExpectedDockedRect(
    CWnd* pWndToDock,
    CPoint ptMouse,
    CRect& rectResult,
    BOOL& bDrawTab,
    CDockablePane** ppTargetBar);
```

### <a name="parameters"></a>Parâmetros

[in] *pWndToDock*<br/>
[in] *ptMouse*<br/>
[in] *rectResult*<br/>
[in] *bDrawTab*<br/>
[in] *ppTargetBar*<br/>

### <a name="remarks"></a>Comentários

##  <a name="canbeattached"></a>  CMultiPaneFrameWnd::CanBeAttached

```
virtual BOOL CanBeAttached() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="canbedockedtopane"></a>  CMultiPaneFrameWnd::CanBeDockedToPane

```
virtual BOOL CanBeDockedToPane(const CDockablePane* pDockingBar) const;
```

### <a name="parameters"></a>Parâmetros

[in] *pDockingBar*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="checkgrippervisibility"></a>  CMultiPaneFrameWnd::CheckGripperVisibility

```
virtual void CheckGripperVisibility();
```

### <a name="remarks"></a>Comentários

##  <a name="closeminiframe"></a>  CMultiPaneFrameWnd::CloseMiniFrame

```
virtual void CloseMiniFrame();
```

### <a name="remarks"></a>Comentários

##  <a name="converttotabbeddocument"></a>  CMultiPaneFrameWnd::ConvertToTabbedDocument

```
virtual void ConvertToTabbedDocument();
```

### <a name="remarks"></a>Comentários

##  <a name="dockframe"></a>  CMultiPaneFrameWnd::DockFrame

```
virtual BOOL DockFrame(
    CPaneFrameWnd* pDockedFrame,
    AFX_DOCK_METHOD dockMethod);
```

### <a name="parameters"></a>Parâmetros

[in] *pDockedFrame*<br/>
[in] *dockMethod*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="dockpane"></a>  CMultiPaneFrameWnd::DockPane

```
virtual BOOL DockPane(CDockablePane* pDockedBar);
```

### <a name="parameters"></a>Parâmetros

[in] *pDockedBar*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="dockrecentpanetomainframe"></a>  CMultiPaneFrameWnd::DockRecentPaneToMainFrame

```
virtual void DockRecentPaneToMainFrame(CDockablePane* pBar);
```

### <a name="parameters"></a>Parâmetros

[in] *pBar*<br/>

### <a name="remarks"></a>Comentários

##  <a name="getcaptiontext"></a>  CMultiPaneFrameWnd::GetCaptionText

```
virtual CString GetCaptionText();
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getfirstvisiblepane"></a>  CMultiPaneFrameWnd::GetFirstVisiblePane

```
virtual CWnd* GetFirstVisiblePane() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getpane"></a>  CMultiPaneFrameWnd::GetPane

```
virtual CWnd* GetPane() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getpanecontainermanager"></a>  CMultiPaneFrameWnd::GetPaneContainerManager

Retorna uma referência para o objeto do Gerenciador de contêiner interno.

```
CPaneContainerManager& GetPaneContainerManager();
```

### <a name="return-value"></a>Valor de retorno

Uma referência para o objeto do Gerenciador de contêiner interno.

### <a name="remarks"></a>Comentários

Esse método pode ser usado para acessar o interno [classe CPaneContainerManager](../../mfc/reference/cpanecontainermanager-class.md) objeto.

##  <a name="getpanecount"></a>  CMultiPaneFrameWnd::GetPaneCount

```
virtual int GetPaneCount() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getvisiblepanecount"></a>  CMultiPaneFrameWnd::GetVisiblePaneCount

```
virtual int GetVisiblePaneCount() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="insertpane"></a>  CMultiPaneFrameWnd::InsertPane

```
virtual BOOL InsertPane(
    CBasePane* pControlBar,
    CBasePane* pTarget,
    BOOL bAfter);
```

### <a name="parameters"></a>Parâmetros

[in] *pControlBar*<br/>
[in] *pTarget*<br/>
[in] *bDepois*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="loadstate"></a>  CMultiPaneFrameWnd::LoadState

```
virtual BOOL LoadState(
    LPCTSTR lpszProfileName = NULL,
    UINT uiID = (UINT) -1);
```

### <a name="parameters"></a>Parâmetros

[in] *lpszProfileName*<br/>
[in] *uiID*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="ondocktorecentpos"></a>  CMultiPaneFrameWnd::OnDockToRecentPos

```
virtual void OnDockToRecentPos();
```

### <a name="remarks"></a>Comentários

##  <a name="onkillrolluptimer"></a>  CMultiPaneFrameWnd::OnKillRollUpTimer

```
virtual void OnKillRollUpTimer();
```

### <a name="remarks"></a>Comentários

##  <a name="onpanerecalclayout"></a>  CMultiPaneFrameWnd::OnPaneRecalcLayout

```
virtual void OnPaneRecalcLayout();
```

### <a name="remarks"></a>Comentários

##  <a name="onsetrolluptimer"></a>  CMultiPaneFrameWnd::OnSetRollUpTimer

```
virtual void OnSetRollUpTimer();
```

### <a name="remarks"></a>Comentários

##  <a name="onshowpane"></a>  CMultiPaneFrameWnd::OnShowPane

```
virtual void OnShowPane(
    CDockablePane* pBar,
    BOOL bShow);
```

### <a name="parameters"></a>Parâmetros

[in] *pBar*<br/>
[in] *bMostrar*<br/>

### <a name="remarks"></a>Comentários

##  <a name="panefrompoint"></a>  CMultiPaneFrameWnd::PaneFromPoint

```
virtual CBasePane* PaneFromPoint(
    CPoint point,
    int nSensitivity,
    BOOL bCheckVisibility);
```

### <a name="parameters"></a>Parâmetros

[in] *ponto*<br/>
[in] *nSensitivity*<br/>
[in] *bCheckVisibility*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="removenonvalidpanes"></a>  CMultiPaneFrameWnd::RemoveNonValidPanes

```
virtual void RemoveNonValidPanes();
```

### <a name="remarks"></a>Comentários

##  <a name="removepane"></a>  CMultiPaneFrameWnd::RemovePane

```
virtual void RemovePane(
    CBasePane* pBar,
    BOOL bDestroy = FALSE,
    BOOL bNoDelayedDestroy = TRUE);
```

### <a name="parameters"></a>Parâmetros

[in] *pBar*<br/>
[in] *bDestroy*<br/>
[in] *bNoDelayedDestroy*<br/>

### <a name="remarks"></a>Comentários

##  <a name="replacepane"></a>  CMultiPaneFrameWnd::ReplacePane

```
virtual void ReplacePane(
    CBasePane* pBarOrg,
    CBasePane* pBarReplaceWith);
```

### <a name="parameters"></a>Parâmetros

[in] *pBarOrg*<br/>
[in] *pBarReplaceWith*<br/>

### <a name="remarks"></a>Comentários

##  <a name="savestate"></a>  CMultiPaneFrameWnd::SaveState

```
virtual BOOL SaveState(
    LPCTSTR lpszProfileName = NULL,
    UINT uiID = (UINT) -1);
```

### <a name="parameters"></a>Parâmetros

[in] *lpszProfileName*<br/>
[in] *uiID*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="serialize"></a>  CMultiPaneFrameWnd::Serialize

```
virtual void Serialize(CArchive& ar);
```

### <a name="parameters"></a>Parâmetros

[in] *ar*<br/>

### <a name="remarks"></a>Comentários

##  <a name="setdockstate"></a>  CMultiPaneFrameWnd::SetDockState

```
virtual void SetDockState(CDockingManager* pDockManager);
```

### <a name="parameters"></a>Parâmetros

[in] *pDockManager*<br/>

### <a name="remarks"></a>Comentários

##  <a name="setlastfocusedpane"></a>  CMultiPaneFrameWnd::SetLastFocusedPane

```
void SetLastFocusedPane(HWND hwnd);
```

### <a name="parameters"></a>Parâmetros

[in] *hwnd*<br/>

### <a name="remarks"></a>Comentários

##  <a name="setpredockstate"></a>  CMultiPaneFrameWnd::SetPreDockState

```
virtual BOOL SetPreDockState(
    AFX_PREDOCK_STATE preDockState,
    CBasePane* pBarToDock = NULL,
    AFX_DOCK_METHOD dockMethod = DM_MOUSE);
```

### <a name="parameters"></a>Parâmetros

[in] *preDockState*<br/>
[in] *pBarToDock*<br/>
[in] *dockMethod*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="storerecentdocksiteinfo"></a>  CMultiPaneFrameWnd::StoreRecentDockSiteInfo

```
virtual void StoreRecentDockSiteInfo(CPane* pBar);
```

### <a name="parameters"></a>Parâmetros

[in] *pBar*<br/>

### <a name="remarks"></a>Comentários

##  <a name="storerecenttabrelatedinfo"></a>  CMultiPaneFrameWnd::StoreRecentTabRelatedInfo

```
virtual void StoreRecentTabRelatedInfo(
    CDockablePane* pDockingBar,
    CDockablePane* pTabbedBar);
```

### <a name="parameters"></a>Parâmetros

[in] *pDockingBar*<br/>
[in] *pTabbedBar*<br/>

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md)
