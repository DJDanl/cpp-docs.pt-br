---
title: Classe CPaneDivider | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CPaneDivider
- AFXPANEDIVIDER/CPaneDivider
- AFXPANEDIVIDER/CPaneDivider::CPaneDivider
- AFXPANEDIVIDER/CPaneDivider::AddPaneContainer
- AFXPANEDIVIDER/CPaneDivider::AddPane
- AFXPANEDIVIDER/CPaneDivider::AddRecentPane
- AFXPANEDIVIDER/CPaneDivider::CalcExpectedDockedRect
- AFXPANEDIVIDER/CPaneDivider::CalcFixedLayout
- AFXPANEDIVIDER/CPaneDivider::CheckVisibility
- AFXPANEDIVIDER/CPaneDivider::CreateEx
- AFXPANEDIVIDER/CPaneDivider::DoesAllowDynInsertBefore
- AFXPANEDIVIDER/CPaneDivider::DoesContainFloatingPane
- AFXPANEDIVIDER/CPaneDivider::FindPaneContainer
- AFXPANEDIVIDER/CPaneDivider::FindTabbedPane
- AFXPANEDIVIDER/CPaneDivider::GetDefaultWidth
- AFXPANEDIVIDER/CPaneDivider::GetFirstPane
- AFXPANEDIVIDER/CPaneDivider::GetPaneDividerStyle
- AFXPANEDIVIDER/CPaneDivider::GetRootContainerRect
- AFXPANEDIVIDER/CPaneDivider::GetWidth
- AFXPANEDIVIDER/CPaneDivider::Init
- AFXPANEDIVIDER/CPaneDivider::InsertPane
- AFXPANEDIVIDER/CPaneDivider::IsAutoHideMode
- AFXPANEDIVIDER/CPaneDivider::IsDefault
- AFXPANEDIVIDER/CPaneDivider::IsHorizontal
- AFXPANEDIVIDER/CPaneDivider::Move
- AFXPANEDIVIDER/CPaneDivider::NotifyAboutRelease
- AFXPANEDIVIDER/CPaneDivider::OnShowPane
- AFXPANEDIVIDER/CPaneDivider::ReleaseEmptyPaneContainers
- AFXPANEDIVIDER/CPaneDivider::RemovePane
- AFXPANEDIVIDER/CPaneDivider::ReplacePane
- AFXPANEDIVIDER/CPaneDivider::RepositionPanes
- AFXPANEDIVIDER/CPaneDivider::Serialize
- AFXPANEDIVIDER/CPaneDivider::SetAutoHideMode
- AFXPANEDIVIDER/CPaneDivider::SetPaneContainerManager
- AFXPANEDIVIDER/CPaneDivider::ShowWindow
- AFXPANEDIVIDER/CPaneDivider::StoreRecentDockSiteInfo
- AFXPANEDIVIDER/CPaneDivider::StoreRecentTabRelatedInfo
- AFXPANEDIVIDER/CPaneDivider::GetPanes
- AFXPANEDIVIDER/CPaneDivider::GetPaneDividers
- AFXPANEDIVIDER/CPaneDivider::m_nDefaultWidth
- AFXPANEDIVIDER/CPaneDivider::m_pSliderRTC
dev_langs:
- C++
helpviewer_keywords:
- CPaneDivider [MFC], CPaneDivider
- CPaneDivider [MFC], AddPaneContainer
- CPaneDivider [MFC], AddPane
- CPaneDivider [MFC], AddRecentPane
- CPaneDivider [MFC], CalcExpectedDockedRect
- CPaneDivider [MFC], CalcFixedLayout
- CPaneDivider [MFC], CheckVisibility
- CPaneDivider [MFC], CreateEx
- CPaneDivider [MFC], DoesAllowDynInsertBefore
- CPaneDivider [MFC], DoesContainFloatingPane
- CPaneDivider [MFC], FindPaneContainer
- CPaneDivider [MFC], FindTabbedPane
- CPaneDivider [MFC], GetDefaultWidth
- CPaneDivider [MFC], GetFirstPane
- CPaneDivider [MFC], GetPaneDividerStyle
- CPaneDivider [MFC], GetRootContainerRect
- CPaneDivider [MFC], GetWidth
- CPaneDivider [MFC], Init
- CPaneDivider [MFC], InsertPane
- CPaneDivider [MFC], IsAutoHideMode
- CPaneDivider [MFC], IsDefault
- CPaneDivider [MFC], IsHorizontal
- CPaneDivider [MFC], Move
- CPaneDivider [MFC], NotifyAboutRelease
- CPaneDivider [MFC], OnShowPane
- CPaneDivider [MFC], ReleaseEmptyPaneContainers
- CPaneDivider [MFC], RemovePane
- CPaneDivider [MFC], ReplacePane
- CPaneDivider [MFC], RepositionPanes
- CPaneDivider [MFC], Serialize
- CPaneDivider [MFC], SetAutoHideMode
- CPaneDivider [MFC], SetPaneContainerManager
- CPaneDivider [MFC], ShowWindow
- CPaneDivider [MFC], StoreRecentDockSiteInfo
- CPaneDivider [MFC], StoreRecentTabRelatedInfo
- CPaneDivider [MFC], GetPanes
- CPaneDivider [MFC], GetPaneDividers
- CPaneDivider [MFC], m_nDefaultWidth
- CPaneDivider [MFC], m_pSliderRTC
ms.assetid: 8e828a5d-232f-4127-b8e3-7fa45a7a476e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b51eccb4c76a3888eaa9e46faccdf00d3c2ade39
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46441766"
---
# <a name="cpanedivider-class"></a>Classe CPaneDivider

Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.

O `CPaneDivider` classe divide dois painéis, dois grupos de painéis ou separa um grupo de painéis da área de cliente da janela do quadro principal.

## <a name="syntax"></a>Sintaxe

```
class CPaneDivider : public CBasePane
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPaneDivider::CPaneDivider](#cpanedivider)||

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CPaneDivider::AddPaneContainer](#addpanecontainer)||
|[CPaneDivider::AddPane](#addpane)||
|[CPaneDivider::AddRecentPane](#addrecentpane)||
|[CPaneDivider::CalcExpectedDockedRect](#calcexpecteddockedrect)||
|[CPaneDivider::CalcFixedLayout](#calcfixedlayout)|(Substitui [CBasePane::CalcFixedLayout](../../mfc/reference/cbasepane-class.md#calcfixedlayout).)|
|[CPaneDivider::CheckVisibility](#checkvisibility)||
|[CPaneDivider::CreateEx](#createex)|(Substitui [CBasePane::CreateEx](../../mfc/reference/cbasepane-class.md#createex).)|
|[CPaneDivider::DoesAllowDynInsertBefore](#doesallowdyninsertbefore)|(Substitui [CBasePane::DoesAllowDynInsertBefore](../../mfc/reference/cbasepane-class.md#doesallowdyninsertbefore).)|
|[CPaneDivider::DoesContainFloatingPane](#doescontainfloatingpane)||
|[CPaneDivider::FindPaneContainer](#findpanecontainer)||
|[CPaneDivider::FindTabbedPane](#findtabbedpane)||
|[CPaneDivider::GetDefaultWidth](#getdefaultwidth)||
|[CPaneDivider::GetFirstPane](#getfirstpane)||
|[CPaneDivider::GetPaneDividerStyle](#getpanedividerstyle)||
|[CPaneDivider::GetRootContainerRect](#getrootcontainerrect)||
|[CPaneDivider::GetWidth](#getwidth)||
|[CPaneDivider::Init](#init)||
|[CPaneDivider::InsertPane](#insertpane)||
|[CPaneDivider::IsAutoHideMode](#isautohidemode)|(Substitui [CBasePane::IsAutoHideMode](../../mfc/reference/cbasepane-class.md#isautohidemode).)|
|[CPaneDivider::IsDefault](#isdefault)||
|[CPaneDivider::IsHorizontal](#ishorizontal)|(Substitui [CBasePane::IsHorizontal](../../mfc/reference/cbasepane-class.md#ishorizontal).)|
|[CPaneDivider::Move](#move)||
|[CPaneDivider::NotifyAboutRelease](#notifyaboutrelease)||
|[CPaneDivider::OnShowPane](#onshowpane)||
|[CPaneDivider::ReleaseEmptyPaneContainers](#releaseemptypanecontainers)||
|[CPaneDivider::RemovePane](#removepane)||
|[CPaneDivider::ReplacePane](#replacepane)||
|[CPaneDivider::RepositionPanes](#repositionpanes)||
|[CPaneDivider::Serialize](#serialize)|(Substitui `CBasePane::Serialize`.)|
|[CPaneDivider::SetAutoHideMode](#setautohidemode)||
|[CPaneDivider::SetPaneContainerManager](#setpanecontainermanager)||
|[CPaneDivider::ShowWindow](#showwindow)||
|[CPaneDivider::StoreRecentDockSiteInfo](#storerecentdocksiteinfo)||
|[CPaneDivider::StoreRecentTabRelatedInfo](#storerecenttabrelatedinfo)||

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CPaneDivider::GetPanes](#getpanes)|Retorna a lista de painéis que residem na [classe CPaneContainer](../../mfc/reference/cpanecontainer-class.md). Esse método deve ser chamado apenas para divisores de painel padrão.|
|[CPaneDivider::GetPaneDividers](#getpanedividers)|Retorna a lista de divisores de painel que residem na [classe CPaneContainer](../../mfc/reference/cpanecontainer-class.md). Esse método deve ser chamado apenas para divisores de painel padrão.|

### <a name="data-members"></a>Membros de Dados

|Nome|Descrição|
|----------|-----------------|
|[CPaneDivider::m_nDefaultWidth](#m_ndefaultwidth)|Especifica a largura padrão, em pixels, de todos os divisores de painel no aplicativo.|
|[CPaneDivider::m_pSliderRTC](#m_psliderrtc)|Contém um ponteiro para as informações de classe de tempo de execução sobre um `CPaneDivider`-objeto derivado.|

## <a name="remarks"></a>Comentários

A estrutura cria `CPaneDivider` objetos automaticamente quando um painel está encaixado.

Há dois tipos de divisores de painel:

- um divisor do painel padrão é criado quando um grupo de painéis é encaixado para um lado da janela do quadro principal. O divisor do painel padrão contém um ponteiro para o [classe CPaneContainerManager](../../mfc/reference/cpanecontainermanager-class.md) e redireciona a maioria das operações no grupo de painéis (como redimensionar um painel ou encaixando outro painel ou um contêiner) para o Gerenciador de contêiner. Cada painel ancorado mantém um ponteiro para o divisor do painel padrão.

- Um divisor do painel regular apenas divide dois painéis em um contêiner. Para obter mais informações, consulte [classe CPaneContainer](../../mfc/reference/cpanecontainer-class.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como obter um `CPaneDivider` do objeto de um `CWorkspaceBar` objeto. Este trecho de código faz parte de [amostra de demonstração de guias MDI](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_MDITabsDemo#5](../../mfc/reference/codesnippet/cpp/cpanedivider-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md) [CCmdTarget](../../mfc/reference/ccmdtarget-class.md) [CWnd](../../mfc/reference/cwnd-class.md)

[CBasePane](../../mfc/reference/cbasepane-class.md) [CPaneDivider](../../mfc/reference/cpanedivider-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxPaneDivider.h

##  <a name="setautohidemode"></a>  CPaneDivider::SetAutoHideMode


```
void SetAutoHideMode(BOOL bMode);
```

### <a name="parameters"></a>Parâmetros

[in] *bMode*

### <a name="remarks"></a>Comentários

##  <a name="setpanecontainermanager"></a>  CPaneDivider::SetPaneContainerManager


```
void SetPaneContainerManager(CPaneContainerManager* p);
```

### <a name="parameters"></a>Parâmetros

[in] *p*

### <a name="remarks"></a>Comentários

##  <a name="addpane"></a>  CPaneDivider::AddPane


```
virtual void AddPane(CDockablePane* pBar);
```

### <a name="parameters"></a>Parâmetros

[in] *pBar*

### <a name="remarks"></a>Comentários

##  <a name="addpanecontainer"></a>  CPaneDivider::AddPaneContainer


```
virtual BOOL AddPaneContainer(
    CPaneContainerManager& barContainerManager,
    BOOL bOuterEdge);


virtual BOOL AddPaneContainer(
    CDockablePane* pTargetBar,
    CPaneContainerManager& barContainerManager,
    DWORD dwAlignment);
```

### <a name="parameters"></a>Parâmetros

*barContainerManager*<br/>
[in] [in] *bOuterEdge*
*pTargetBar*<br/>
[in] [in] *dwAlignment*

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="addrecentpane"></a>  CPaneDivider::AddRecentPane


```
virtual CDockablePane* AddRecentPane(CDockablePane* pBar);
```

### <a name="parameters"></a>Parâmetros

[in] *pBar*

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="calcexpecteddockedrect"></a>  CPaneDivider::CalcExpectedDockedRect


```
virtual void CalcExpectedDockedRect(
    CWnd* pWndToDock,
    CPoint ptMouse,
    CRect& rectResult,
    BOOL& bDrawTab,
    CDockablePane** ppTargetBar);
```

### <a name="parameters"></a>Parâmetros

*pWndToDock*<br/>
[in] [in] *ptMouse*
*rectResult*<br/>
[in] [in] *bDrawTab* [in] *ppTargetBar*

### <a name="remarks"></a>Comentários

##  <a name="calcfixedlayout"></a>  CPaneDivider::CalcFixedLayout


```
virtual CSize CalcFixedLayout(
    BOOL bStretch,
    BOOL bHorz);
```

### <a name="parameters"></a>Parâmetros

*bStretch*<br/>
[in] [in] *bHorz*

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="checkvisibility"></a>  CPaneDivider::CheckVisibility


```
virtual BOOL CheckVisibility();
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="cpanedivider"></a>  CPaneDivider::CPaneDivider


```
CPaneDivider();


CPaneDivider(
    BOOL bDefaultSlider,
    CWnd* pParent = NULL);
```

### <a name="parameters"></a>Parâmetros

*bDefaultSlider*<br/>
[in] [in] *pParent*

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="createex"></a>  CPaneDivider::CreateEx


```
virtual BOOL CreateEx(
    DWORD dwStyleEx,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID,
    CCreateContext* pContext);
```

### <a name="parameters"></a>Parâmetros

*dwStyleEx*<br/>
[in] [in] *dwStyle*
*rect*<br/>
[in] [in] *pParentWnd*
*nID*<br/>
[in] [in] *pContext*

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="doesallowdyninsertbefore"></a>  CPaneDivider::DoesAllowDynInsertBefore


```
virtual BOOL DoesAllowDynInsertBefore() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="doescontainfloatingpane"></a>  CPaneDivider::DoesContainFloatingPane


```
virtual BOOL DoesContainFloatingPane();
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="findpanecontainer"></a>  CPaneDivider::FindPaneContainer


```
CPaneContainer* FindPaneContainer(
    CDockablePane* pBar,
    BOOL& bLeftBar);
```

### <a name="parameters"></a>Parâmetros

*pBar*<br/>
[in] [in] *bLeftBar*

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="findtabbedpane"></a>  CPaneDivider::FindTabbedPane


```
CDockablePane* FindTabbedPane(UINT nID);
```

### <a name="parameters"></a>Parâmetros

[in] *nID*

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getdefaultwidth"></a>  CPaneDivider::GetDefaultWidth


```
static int __stdcall GetDefaultWidth();
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getfirstpane"></a>  CPaneDivider::GetFirstPane


```
const CBasePane* GetFirstPane() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getpanedividers"></a>  CPaneDivider::GetPaneDividers

Retorna a lista de divisores de painel que residem na [classe CPaneContainer](../../mfc/reference/cpanecontainer-class.md). Esse método deve ser chamado apenas para divisores de painel padrão.

```
void GetPaneDividers(CObList& lstSliders);
```

### <a name="parameters"></a>Parâmetros

*lstSliders*<br/>
[out] Contém a lista de divisores de painel que residem no contêiner do painel.

### <a name="remarks"></a>Comentários

Esse método deve ser chamado para apenas divisores de painel padrão. Um divisor do painel padrão é um divisor que redimensiona o contêiner de todo o painel.

##  <a name="getpanedividerstyle"></a>  CPaneDivider::GetPaneDividerStyle


```
DWORD GetPaneDividerStyle() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getpanes"></a>  CPaneDivider::GetPanes

Retorna a lista de painéis que residem na [classe CPaneContainer](../../mfc/reference/cpanecontainer-class.md). Esse método deve ser chamado apenas para recuperar os divisores de painel padrão.

```
void GetPanes(CObList& lstBars);
```

### <a name="parameters"></a>Parâmetros

*lstBars*<br/>
[out] Contém a lista de painéis que residem no contêiner do painel.

### <a name="remarks"></a>Comentários

Esse método deve ser chamado para apenas divisores de painel padrão. Um divisor do painel padrão é um divisor que redimensiona o contêiner de todo o painel.

##  <a name="getrootcontainerrect"></a>  CPaneDivider::GetRootContainerRect


```
CRect GetRootContainerRect();
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getwidth"></a>  CPaneDivider::GetWidth


```
int GetWidth() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="init"></a>  CPaneDivider::Init


```
void Init(
    BOOL bDefaultSlider = FALSE,
    CWnd* pParent = NULL);
```

### <a name="parameters"></a>Parâmetros

*bDefaultSlider*<br/>
[in] [in] *pParent*

### <a name="remarks"></a>Comentários

##  <a name="insertpane"></a>  CPaneDivider::InsertPane


```
virtual BOOL InsertPane(
    CDockablePane* pBarToInsert,
    CDockablePane* pTargetBar,
    DWORD dwAlignment,
    LPCRECT lpRect = NULL);
```

### <a name="parameters"></a>Parâmetros

*pBarToInsert*<br/>
[in] [in] *pTargetBar*
*dwAlignment*<br/>
[in] [in] *lpRect*

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="isautohidemode"></a>  CPaneDivider::IsAutoHideMode


```
BOOL IsAutoHideMode() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="isdefault"></a>  CPaneDivider::IsDefault


```
BOOL IsDefault() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="ishorizontal"></a>  CPaneDivider::IsHorizontal


```
BOOL IsHorizontal() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="m_ndefaultwidth"></a>  CPaneDivider::m_nDefaultWidth

Especifica a largura padrão, em pixels, de todos os divisores de painel no aplicativo.

```
AFX_IMPORT_DATA static int m_nDefaultWidth;
```

##  <a name="move"></a>  CPaneDivider::Move


```
virtual void Move(
    CPoint& ptOffset,
    BOOL bAdjustLayout = TRUE);
```

### <a name="parameters"></a>Parâmetros

*ptOffset*<br/>
[in] [in] *bAdjustLayout*

### <a name="remarks"></a>Comentários

##  <a name="m_psliderrtc"></a>  CPaneDivider::m_pSliderRTC

Contém um ponteiro para informações de classe de tempo de execução sobre um `CPaneDivider`-objeto derivado.

```
AFX_IMPORT_DATA static CRuntimeClass* m_pSliderRTC;
```

### <a name="remarks"></a>Comentários

Se você criar um divisor de painel personalizado, defina essa variável de membro. Isso permite que o framework para criar seu divisor do painel quando o painel é desenhado.

### <a name="example"></a>Exemplo

O exemplo a seguir mostra como definir o `m_pSliderRTC` variável de membro:

```
class CMySplitter : public CPaneDivider
{
...
};

CPaneDivider::m_pSliderRTC = RUNTIME_CLASS(CMySpliter);
```

##  <a name="notifyaboutrelease"></a>  CPaneDivider::NotifyAboutRelease


```
virtual void NotifyAboutRelease();
```

### <a name="remarks"></a>Comentários

##  <a name="onshowpane"></a>  CPaneDivider::OnShowPane


```
virtual void OnShowPane(
    CDockablePane* pBar,
    BOOL bShow);
```

### <a name="parameters"></a>Parâmetros

*pBar*<br/>
[in] [in] *bMostrar*

### <a name="remarks"></a>Comentários

##  <a name="releaseemptypanecontainers"></a>  CPaneDivider::ReleaseEmptyPaneContainers


```
void ReleaseEmptyPaneContainers();
```

### <a name="remarks"></a>Comentários

##  <a name="removepane"></a>  CPaneDivider::RemovePane


```
virtual void RemovePane(CDockablePane* pBar);
```

### <a name="parameters"></a>Parâmetros

[in] *pBar*

### <a name="remarks"></a>Comentários

##  <a name="replacepane"></a>  CPaneDivider::ReplacePane


```
virtual BOOL ReplacePane(
    CDockablePane* pBarToReplace,
    CDockablePane* pBarToReplaceWith);
```

### <a name="parameters"></a>Parâmetros

*pBarToReplace*<br/>
[in] [in] *pBarToReplaceWith*

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="repositionpanes"></a>  CPaneDivider::RepositionPanes


```
virtual void RepositionPanes(
    CRect& rectNew,
    HDWP& hdwp);
```

### <a name="parameters"></a>Parâmetros

*rectNew*<br/>
[in] [in] *hdwp*

### <a name="remarks"></a>Comentários

##  <a name="serialize"></a>  CPaneDivider::Serialize


```
void Serialize(CArchive& ar);
```

### <a name="parameters"></a>Parâmetros

[in] *ar*

### <a name="remarks"></a>Comentários

##  <a name="showwindow"></a>  CPaneDivider::ShowWindow


```
void ShowWindow(int nCmdShow);
```

### <a name="parameters"></a>Parâmetros

[in] *nCmdShow*

### <a name="remarks"></a>Comentários

##  <a name="storerecentdocksiteinfo"></a>  CPaneDivider::StoreRecentDockSiteInfo


```
void StoreRecentDockSiteInfo(CDockablePane* pBar);
```

### <a name="parameters"></a>Parâmetros

[in] *pBar*

### <a name="remarks"></a>Comentários

##  <a name="storerecenttabrelatedinfo"></a>  CPaneDivider::StoreRecentTabRelatedInfo


```
void StoreRecentTabRelatedInfo(
    CDockablePane* pDockingBar,
    CDockablePane* pTabbedBar);
```

### <a name="parameters"></a>Parâmetros

*pDockingBar*<br/>
[in] [in] *pTabbedBar*

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CPaneContainerManager](../../mfc/reference/cpanecontainermanager-class.md)<br/>
[Classe CPaneContainer](../../mfc/reference/cpanecontainer-class.md)<br/>
[Classe CDockingManager](../../mfc/reference/cdockingmanager-class.md)<br/>
[Classe CBasePane](../../mfc/reference/cbasepane-class.md)
