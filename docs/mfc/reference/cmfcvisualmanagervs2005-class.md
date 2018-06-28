---
title: Classe CMFCVisualManagerVS2005 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCVisualManagerVS2005
- AFXVISUALMANAGERVS2005/CMFCVisualManagerVS2005
- AFXVISUALMANAGERVS2005/CMFCVisualManagerVS2005::GetDockingTabsBordersSize
- AFXVISUALMANAGERVS2005/CMFCVisualManagerVS2005::GetMDITabsBordersSize
- AFXVISUALMANAGERVS2005/CMFCVisualManagerVS2005::GetPropertyGridGroupColor
- AFXVISUALMANAGERVS2005/CMFCVisualManagerVS2005::GetTabFrameColors
- AFXVISUALMANAGERVS2005/CMFCVisualManagerVS2005::HasOverlappedAutoHideButtons
- AFXVISUALMANAGERVS2005/CMFCVisualManagerVS2005::OnDrawAutoHideButtonBorder
- AFXVISUALMANAGERVS2005/CMFCVisualManagerVS2005::OnDrawCaptionButton
- AFXVISUALMANAGERVS2005/CMFCVisualManagerVS2005::OnDrawPaneCaption
- AFXVISUALMANAGERVS2005/CMFCVisualManagerVS2005::OnDrawSeparator
- AFXVISUALMANAGERVS2005/CMFCVisualManagerVS2005::OnDrawTab
- AFXVISUALMANAGERVS2005/CMFCVisualManagerVS2005::OnDrawToolBoxFrame
- AFXVISUALMANAGERVS2005/CMFCVisualManagerVS2005::OnEraseTabsArea
- AFXVISUALMANAGERVS2005/CMFCVisualManagerVS2005::OnFillAutoHideButtonBackground
- AFXVISUALMANAGERVS2005/CMFCVisualManagerVS2005::OnFillHighlightedArea
- AFXVISUALMANAGERVS2005/CMFCVisualManagerVS2005::OnFillMiniFrameCaption
- AFXVISUALMANAGERVS2005/CMFCVisualManagerVS2005::OnUpdateSystemColors
dev_langs:
- C++
helpviewer_keywords:
- CMFCVisualManagerVS2005 [MFC], GetDockingTabsBordersSize
- CMFCVisualManagerVS2005 [MFC], GetMDITabsBordersSize
- CMFCVisualManagerVS2005 [MFC], GetPropertyGridGroupColor
- CMFCVisualManagerVS2005 [MFC], GetTabFrameColors
- CMFCVisualManagerVS2005 [MFC], HasOverlappedAutoHideButtons
- CMFCVisualManagerVS2005 [MFC], OnDrawAutoHideButtonBorder
- CMFCVisualManagerVS2005 [MFC], OnDrawCaptionButton
- CMFCVisualManagerVS2005 [MFC], OnDrawPaneCaption
- CMFCVisualManagerVS2005 [MFC], OnDrawSeparator
- CMFCVisualManagerVS2005 [MFC], OnDrawTab
- CMFCVisualManagerVS2005 [MFC], OnDrawToolBoxFrame
- CMFCVisualManagerVS2005 [MFC], OnEraseTabsArea
- CMFCVisualManagerVS2005 [MFC], OnFillAutoHideButtonBackground
- CMFCVisualManagerVS2005 [MFC], OnFillHighlightedArea
- CMFCVisualManagerVS2005 [MFC], OnFillMiniFrameCaption
- CMFCVisualManagerVS2005 [MFC], OnUpdateSystemColors
ms.assetid: ea39b9ae-327e-4a51-bce7-dc84c78f005b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c7282730779360ecc0bb93f0ae827b46ddff19d0
ms.sourcegitcommit: f1b051abb1de3fe96350be0563aaf4e960da13c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/27/2018
ms.locfileid: "37038055"
---
# <a name="cmfcvisualmanagervs2005-class"></a>Classe CMFCVisualManagerVS2005
`CMFCVisualManagerVS2005` Fornece um aplicativo com uma aparência do Microsoft Visual Studio 2005.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCVisualManagerVS2005 : public CMFCVisualManagerOffice2003  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCVisualManagerVS2005::GetDockingTabsBordersSize](#getdockingtabsborderssize)|O framework chama este método quando ele desenha um painel encaixado e com guias. (Substitui [CMFCVisualManager::GetDockingTabsBordersSize](../../mfc/reference/cmfcvisualmanager-class.md#getdockingtabsborderssize).)|  
|[CMFCVisualManagerVS2005::GetMDITabsBordersSize](#getmditabsborderssize)|O framework chama esse método para determinar o tamanho da borda de uma janela /mditabs antes que ele se baseia a janela. (Substitui [CMFCVisualManager::GetMDITabsBordersSize](../../mfc/reference/cmfcvisualmanager-class.md#getmditabsborderssize).)|  
|[CMFCVisualManagerVS2005::GetPropertyGridGroupColor](#getpropertygridgroupcolor)|(Substitui [CMFCVisualManagerOffice2003::GetPropertyGridGroupColor](../../mfc/reference/cmfcvisualmanageroffice2003-class.md#getpropertygridgroupcolor).)|  
|[CMFCVisualManagerVS2005::GetTabFrameColors](#gettabframecolors)|(Substitui [CMFCVisualManagerOffice2003::GetTabFrameColors](../../mfc/reference/cmfcvisualmanageroffice2003-class.md#gettabframecolors).)|  
|[CMFCVisualManagerVS2005::HasOverlappedAutoHideButtons](#hasoverlappedautohidebuttons)|Retorna se botões de ocultar automaticamente se sobrepõem no Gerenciador de visual atual. (Substitui [CMFCVisualManager::HasOverlappedAutoHideButtons](../../mfc/reference/cmfcvisualmanager-class.md#hasoverlappedautohidebuttons).)|  
|[CMFCVisualManagerVS2005::OnDrawAutoHideButtonBorder](#ondrawautohidebuttonborder)|(Substitui [CMFCVisualManagerOffice2003::OnDrawAutoHideButtonBorder](../../mfc/reference/cmfcvisualmanageroffice2003-class.md#ondrawautohidebuttonborder).)|  
|[CMFCVisualManagerVS2005::OnDrawCaptionButton](#ondrawcaptionbutton)|(Substitui `CMFCVisualManagerOfficeXP::OnDrawCaptionButton`.)|  
|[CMFCVisualManagerVS2005::OnDrawPaneCaption](#ondrawpanecaption)|(Substitui [CMFCVisualManagerOffice2003::OnDrawPaneCaption](../../mfc/reference/cmfcvisualmanageroffice2003-class.md#ondrawpanecaption).)|  
|[CMFCVisualManagerVS2005::OnDrawSeparator](#ondrawseparator)|(Substitui [CMFCVisualManagerOffice2003::OnDrawSeparator](../../mfc/reference/cmfcvisualmanageroffice2003-class.md#ondrawseparator).)|  
|[CMFCVisualManagerVS2005::OnDrawTab](#ondrawtab)|(Substitui [CMFCVisualManagerOffice2003::OnDrawTab](../../mfc/reference/cmfcvisualmanageroffice2003-class.md#ondrawtab).)|  
|[CMFCVisualManagerVS2005::OnDrawToolBoxFrame](#ondrawtoolboxframe)|(Substitui [CMFCVisualManager::OnDrawToolBoxFrame](../../mfc/reference/cmfcvisualmanager-class.md#ondrawtoolboxframe).)|  
|[CMFCVisualManagerVS2005::OnEraseTabsArea](#onerasetabsarea)|(Substitui [CMFCVisualManagerOffice2003::OnEraseTabsArea](../../mfc/reference/cmfcvisualmanageroffice2003-class.md#onerasetabsarea).)|  
|[CMFCVisualManagerVS2005::OnFillAutoHideButtonBackground](#onfillautohidebuttonbackground)|(Substitui [CMFCVisualManagerOffice2003::OnFillAutoHideButtonBackground](../../mfc/reference/cmfcvisualmanageroffice2003-class.md#onfillautohidebuttonbackground).)|  
|[CMFCVisualManagerVS2005::OnFillHighlightedArea](#onfillhighlightedarea)|(Substitui [CMFCVisualManagerOffice2003::OnFillHighlightedArea](../../mfc/reference/cmfcvisualmanageroffice2003-class.md#onfillhighlightedarea).)|  
|[CMFCVisualManagerVS2005::OnFillMiniFrameCaption](#onfillminiframecaption)|(Substitui `CMFCVisualManagerOfficeXP::OnFillMiniFrameCaption`.)|  
|[CMFCVisualManagerVS2005::OnUpdateSystemColors](#onupdatesystemcolors)|(Substitui [CMFCVisualManagerOffice2003::OnUpdateSystemColors](../../mfc/reference/cmfcvisualmanageroffice2003-class.md#onupdatesystemcolors).)|  
  
## <a name="remarks"></a>Comentários  
 Use a classe CMFCVisualManagerVS2005 para alterar a aparência visual do seu aplicativo para ser semelhante a do [!INCLUDE[vsprvsext](../../mfc/reference/includes/vsprvsext_md.md)].  
  
 Todos os membros dessa classe são funções virtuais que são derivadas do ancestral dessa classe, [CMFCVisualManager classe](../../mfc/reference/cmfcvisualmanager-class.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o Gerenciador de visual VS 2005. Este trecho de código é parte do [exemplo de demonstração de alerta de área de trabalho](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_DesktopAlertDemo#9](../../mfc/reference/codesnippet/cpp/cmfcvisualmanagervs2005-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCBaseVisualManager](../../mfc/reference/cmfcbasevisualmanager-class.md)  
  
 [CMFCVisualManager](../../mfc/reference/cmfcvisualmanager-class.md)  
  
 [CMFCVisualManagerOfficeXP](../../mfc/reference/cmfcvisualmanagerofficexp-class.md)  
  
 [CMFCVisualManagerOffice2003](../../mfc/reference/cmfcvisualmanageroffice2003-class.md)  
  
 [CMFCVisualManagerVS2005](../../mfc/reference/cmfcvisualmanagervs2005-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxvisualmanagervs2005.h  
  
##  <a name="getdockingtabsborderssize"></a>  CMFCVisualManagerVS2005::GetDockingTabsBordersSize  

  
```  
virtual int GetDockingTabsBordersSize();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getmditabsborderssize"></a>  CMFCVisualManagerVS2005::GetMDITabsBordersSize  

  
```  
virtual int GetMDITabsBordersSize();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getpropertygridgroupcolor"></a>  CMFCVisualManagerVS2005::GetPropertyGridGroupColor  

  
```  
virtual COLORREF GetPropertyGridGroupColor(CMFCPropertyGridCtrl* pPropList);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pPropList*  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="gettabframecolors"></a>  CMFCVisualManagerVS2005::GetTabFrameColors  

  
```  
virtual void GetTabFrameColors(
    const CMFCBaseTabCtrl* pTabWnd,  
    COLORREF& clrDark,  
    COLORREF& clrBlack,  
    COLORREF& clrHighlight,  
    COLORREF& clrFace,  
    COLORREF& clrDarkShadow,  
    COLORREF& clrLight,  
    CBrush*& pbrFace,  
    CBrush*& pbrBlack);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pTabWnd*  
 [in] *clrDark*  
 [in] *clrBlack*  
 [in] *clrHighlight*  
 [in] *clrFace*  
 [in] *clrDarkShadow*  
 [in] *clrLight*  
 [in] *pbrFace*  
 [in] *pbrBlack*  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="hasoverlappedautohidebuttons"></a>  CMFCVisualManagerVS2005::HasOverlappedAutoHideButtons  

  
```  
virtual BOOL HasOverlappedAutoHideButtons() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ondrawautohidebuttonborder"></a>  CMFCVisualManagerVS2005::OnDrawAutoHideButtonBorder  

  
```  
virtual void OnDrawAutoHideButtonBorder(
    CDC* pDC,  
    CRect rectBounds,  
    CRect rectBorderSize,  
    CMFCAutoHideButton* pButton);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pDC*  
 [in] *rectBounds*  
 [in] *rectBorderSize*  
 [in] *pButton*  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ondrawcaptionbutton"></a>  CMFCVisualManagerVS2005::OnDrawCaptionButton  

  
```  
virtual void OnDrawCaptionButton(
    CDC* pDC,  
    CMFCCaptionButton* pButton,  
    BOOL bActive,  
    BOOL bHorz,  
    BOOL bMaximized,  
    BOOL bDisabled,  
    int nImageID = -1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pDC*  
 [in] *pButton*  
 [in] *bScripts Ativos*  
 [in] *bHorz*  
 [in] *bMaximized*  
 [in] *bDesabilitado*  
 [in] *nImageID*  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ondrawpanecaption"></a>  CMFCVisualManagerVS2005::OnDrawPaneCaption  

  
```  
virtual COLORREF OnDrawPaneCaption(
    CDC* pDC,  
    CDockablePane* pBar,  
    BOOL bActive,  
    CRect rectCaption,  
    CRect rectButtons);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pDC*  
 [in] *pBar*  
 [in] *bScripts Ativos*  
 [in] *rectCaption*  
 [in] *rectButtons*  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ondrawseparator"></a>  CMFCVisualManagerVS2005::OnDrawSeparator  

  
```  
virtual void OnDrawSeparator(
    CDC* pDC,  
    CBasePane* pBar,  
    CRect rect,  
    BOOL bIsHoriz);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pDC*  
 [in] *pBar*  
 [in] *rect*  
 [in] *bIsHoriz*  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ondrawtab"></a>  CMFCVisualManagerVS2005::OnDrawTab  

  
```  
virtual void OnDrawTab(
    CDC* pDC,  
    CRect rectTab,  
    int iTab,  
    BOOL bIsActive,  
    const CMFCBaseTabCtrl* pTabWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pDC*  
 [in] *rectTab*  
 [in] *iTab*  
 [in] *bIsActive*  
 [in] *pTabWnd*  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ondrawtoolboxframe"></a>  CMFCVisualManagerVS2005::OnDrawToolBoxFrame  

  
```  
virtual void OnDrawToolBoxFrame(
    CDC* pDC,  
    const CRect& rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pDC*  
 [in] *rect*  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onerasetabsarea"></a>  CMFCVisualManagerVS2005::OnEraseTabsArea  

  
```  
virtual void OnEraseTabsArea(
    CDC* pDC,  
    CRect rect,  
    const CMFCBaseTabCtrl* pTabWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pDC*  
 [in] *rect*  
 [in] *pTabWnd*  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onfillautohidebuttonbackground"></a>  CMFCVisualManagerVS2005::OnFillAutoHideButtonBackground  

  
```  
virtual void OnFillAutoHideButtonBackground(
    CDC* pDC,  
    CRect rect,  
    CMFCAutoHideButton* pButton);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pDC*  
 [in] *rect*  
 [in] *pButton*  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onfillhighlightedarea"></a>  CMFCVisualManagerVS2005::OnFillHighlightedArea  

  
```  
virtual void OnFillHighlightedArea(
    CDC* pDC,  
    CRect rect,  
    CBrush* pBrush,  
    CMFCToolBarButton* pButton);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pDC*  
 [in] *rect*  
 [in] *pBrush*  
 [in] *pButton*  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onfillminiframecaption"></a>  CMFCVisualManagerVS2005::OnFillMiniFrameCaption  

  
```  
virtual COLORREF OnFillMiniFrameCaption(
    CDC* pDC,  
    CRect rectCaption,  
    CPaneFrameWnd* pFrameWnd,  
    BOOL bActive);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pDC*  
 [in] *rectCaption*  
 [in] *pFrameWnd*  
 [in] *bScripts Ativos*  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onupdatesystemcolors"></a>  CMFCVisualManagerVS2005::OnUpdateSystemColors  

  
```  
virtual void OnUpdateSystemColors();
```  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCVisualManager](../../mfc/reference/cmfcvisualmanager-class.md)   
 [Classe CMFCVisualManagerOfficeXP](../../mfc/reference/cmfcvisualmanagerofficexp-class.md)   
 [Classe CMFCVisualManagerWindows](../../mfc/reference/cmfcvisualmanagerwindows-class.md)   
 [Classe CMFCVisualManagerOffice2003](../../mfc/reference/cmfcvisualmanageroffice2003-class.md)