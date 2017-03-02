---
title: Classe CPaneContainer | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CPaneContainer
dev_langs:
- C++
helpviewer_keywords:
- CPaneContainer class
ms.assetid: beb79e08-f611-4d66-ba04-053baa79bf86
caps.latest.revision: 32
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: c6db2e98d9c9301559d8a689cc4094a5a423aa7f
ms.lasthandoff: 02/25/2017

---
# <a name="cpanecontainer-class"></a>Classe CPaneContainer
O `CPaneContainer` classe é um componente básico do modelo de encaixe implementado pelo MFC. Um objeto dessa classe armazena ponteiros para os dois painéis de encaixe ou duas instâncias do `CPaneContainer.` , ele também armazena um ponteiro para a linha divisória que separa os painéis (ou os contêineres). Por aninhamento contêineres dentro de contêineres, a estrutura pode criar uma árvore binária que representa os layouts complexos de encaixe. A raiz da árvore binária é armazenada em uma [CPaneContainerManager](../../mfc/reference/cpanecontainermanager-class.md) objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CPaneContainer : public CObject    
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPaneContainer::CPaneContainer](#cpanecontainer)|Construtor padrão.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPaneContainer::AddPane](#addpane)||  
|[CPaneContainer::AddRef](#addref)||  
|[CPaneContainer::AddSubPaneContainer](#addsubpanecontainer)||  
|[CPaneContainer::CalcAvailablePaneSpace](#calcavailablepanespace)||  
|[CPaneContainer::CalcAvailableSpace](#calcavailablespace)||  
|[CPaneContainer::CalculateRecentSize](#calculaterecentsize)||  
|[CPaneContainer::CheckPaneDividerVisibility](#checkpanedividervisibility)||  
|[CPaneContainer::Copy](#copy)||  
|[CPaneContainer::DeletePane](#deletepane)||  
|[CPaneContainer::FindSubPaneContainer](#findsubpanecontainer)||  
|[CPaneContainer::FindTabbedPane](#findtabbedpane)||  
|[CPaneContainer::GetAssociatedSiblingPaneIDs](#getassociatedsiblingpaneids)||  
|[CPaneContainer::GetLeftPane](#getleftpane)||  
|[CPaneContainer::GetLeftPaneContainer](#getleftpanecontainer)||  
|[CPaneContainer::GetMinSize](#getminsize)||  
|[CPaneContainer::GetMinSizeLeft](#getminsizeleft)||  
|[CPaneContainer::GetMinSizeRight](#getminsizeright)||  
|[CPaneContainer::GetNodeCount](#getnodecount)||  
|[CPaneContainer::GetPaneDivider](#getpanedivider)||  
|[CPaneContainer::GetParentPaneContainer](#getparentpanecontainer)||  
|[CPaneContainer::GetRecentPaneDividerRect](#getrecentpanedividerrect)||  
|[CPaneContainer::GetRecentPaneDividerStyle](#getrecentpanedividerstyle)||  
|[CPaneContainer::GetRecentPercent](#getrecentpercent)||  
|[CPaneContainer::GetRefCount](#getrefcount)||  
|[CPaneContainer::GetResizeStep](#getresizestep)||  
|[CPaneContainer::GetRightPane](#getrightpane)||  
|[CPaneContainer::GetRightPaneContainer](#getrightpanecontainer)||  
|[CPaneContainer::GetTotalReferenceCount](#gettotalreferencecount)||  
|[CPaneContainer::GetWindowRect](#getwindowrect)||  
|[CPaneContainer::IsDisposed](#isdisposed)||  
|[CPaneContainer::IsEmpty](#isempty)||  
|[CPaneContainer::IsLeftPane](#isleftpane)||  
|[CPaneContainer::IsLeftPaneContainer](#isleftpanecontainer)||  
|[CPaneContainer::IsLeftPartEmpty](#isleftpartempty)||  
|[CPaneContainer::IsRightPartEmpty](#isrightpartempty)||  
|[CPaneContainer::IsVisible](#isvisible)||  
|[CPaneContainer::Move](#move)||  
|[CPaneContainer::OnDeleteHidePane](#ondeletehidepane)||  
|[CPaneContainer::OnMoveInternalPaneDivider](#onmoveinternalpanedivider)||  
|[CPaneContainer::OnShowPane](#onshowpane)||  
|[CPaneContainer::Release](#release)||  
|[CPaneContainer::ReleaseEmptyPaneContainer](#releaseemptypanecontainer)||  
|[CPaneContainer::RemoveNonValidPanes](#removenonvalidpanes)||  
|[CPaneContainer::RemovePane](#removepane)||  
|[CPaneContainer::Resize](#resize)||  
|[CPaneContainer::ResizePane](#resizepane)||  
|[CPaneContainer::ResizePartOfPaneContainer](#resizepartofpanecontainer)||  
|[CPaneContainer::Serialize](#serialize)|Lê ou grava este objeto de ou para um arquivo morto. (Substitui [CObject::Serialize](../../mfc/reference/cobject-class.md#serialize).)|  
|[CPaneContainer::SetPane](#setpane)||  
|[CPaneContainer::SetPaneContainer](#setpanecontainer)||  
|[CPaneContainer::SetPaneDivider](#setpanedivider)||  
|[CPaneContainer::SetParentPaneContainer](#setparentpanecontainer)||  
|[CPaneContainer::SetRecentPercent](#setrecentpercent)||  
|[CPaneContainer::SetUpByID](#setupbyid)||  
|[CPaneContainer::StoreRecentDockSiteInfo](#storerecentdocksiteinfo)||  
|[CPaneContainer::StretchPaneContainer](#stretchpanecontainer)||  
  
### <a name="remarks"></a>Comentários  
 `CPaneContainer`objetos são criados automaticamente pela estrutura.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como construir uma instância de `CPaneContainer` classe. Este trecho de código é parte do [exemplo Definir tamanho do painel](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_SetPaneSize n º&2;](../../mfc/reference/codesnippet/cpp/cpanecontainer-class_1.h)]  
[!code-cpp[NVC_MFC_SetPaneSize n º&1;](../../mfc/reference/codesnippet/cpp/cpanecontainer-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CPaneContainer](../../mfc/reference/cpanecontainer-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxpanecontainer.h  
  
##  <a name="a-nameaddpanea--cpanecontaineraddpane"></a><a name="addpane"></a>CPaneContainer::AddPane  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
CDockablePane* AddPane(CDockablePane* pBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameaddrefa--cpanecontaineraddref"></a><a name="addref"></a>CPaneContainer::AddRef  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void AddRef();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameaddsubpanecontainera--cpanecontaineraddsubpanecontainer"></a><a name="addsubpanecontainer"></a>CPaneContainer::AddSubPaneContainer  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL AddSubPaneContainer(
    CPaneContainer* pContainer,  
    BOOL bRightNodeNew);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pContainer`  
 [in] `bRightNodeNew`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namecalcavailablepanespacea--cpanecontainercalcavailablepanespace"></a><a name="calcavailablepanespace"></a>CPaneContainer::CalcAvailablePaneSpace  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual int CalcAvailablePaneSpace(
    int nRequiredOffset,  
    CPane* pBar,  
    CPaneContainer* pContainer,  
    BOOL bLeftBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nRequiredOffset`  
 [in] `pBar`  
 [in] `pContainer`  
 [in] `bLeftBar`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namecalcavailablespacea--cpanecontainercalcavailablespace"></a><a name="calcavailablespace"></a>CPaneContainer::CalcAvailableSpace  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual CSize CalcAvailableSpace(
    CSize sizeStretch,  
    BOOL bLeftBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `sizeStretch`  
 [in] `bLeftBar`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namecalculaterecentsizea--cpanecontainercalculaterecentsize"></a><a name="calculaterecentsize"></a>CPaneContainer::CalculateRecentSize  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void CalculateRecentSize();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namecheckpanedividervisibilitya--cpanecontainercheckpanedividervisibility"></a><a name="checkpanedividervisibility"></a>CPaneContainer::CheckPaneDividerVisibility  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void CheckPaneDividerVisibility();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namecopya--cpanecontainercopy"></a><a name="copy"></a>CPaneContainer::Copy  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual CPaneContainer* Copy(CPaneContainer* pParentContainer);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pParentContainer`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namecpanecontainera--cpanecontainercpanecontainer"></a><a name="cpanecontainer"></a>CPaneContainer::CPaneContainer  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
CPaneContainer(
    CPaneContainerManager* pManager = NULL,  
    CDockablePane* pLeftBar = NULL,  
    CDockablePane* pRightBar = NULL,  
    CPaneDivider* pSlider = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pManager`  
 [in] `pLeftBar`  
 [in] `pRightBar`  
 [in] `pSlider`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namedeletepanea--cpanecontainerdeletepane"></a><a name="deletepane"></a>CPaneContainer::DeletePane  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void DeletePane(
    CDockablePane* pBar,  
    BC_FIND_CRITERIA barType);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
 [in] `barType`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namefindsubpanecontainera--cpanecontainerfindsubpanecontainer"></a><a name="findsubpanecontainer"></a>CPaneContainer::FindSubPaneContainer  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
CPaneContainer* FindSubPaneContainer(
    const CObject* pObject,  
    BC_FIND_CRITERIA findCriteria);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pObject`  
 [in] `findCriteria`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namefindtabbedpanea--cpanecontainerfindtabbedpane"></a><a name="findtabbedpane"></a>CPaneContainer::FindTabbedPane  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
CDockablePane* FindTabbedPane(UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nID`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetassociatedsiblingpaneidsa--cpanecontainergetassociatedsiblingpaneids"></a><a name="getassociatedsiblingpaneids"></a>CPaneContainer::GetAssociatedSiblingPaneIDs  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
CList<UINT, UINT>* GetAssociatedSiblingPaneIDs(CDockablePane* pBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetleftpanea--cpanecontainergetleftpane"></a><a name="getleftpane"></a>CPaneContainer::GetLeftPane  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
const CDockablePane* GetLeftPane() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetleftpanecontainera--cpanecontainergetleftpanecontainer"></a><a name="getleftpanecontainer"></a>CPaneContainer::GetLeftPaneContainer  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
const CPaneContainer* GetLeftPaneContainer() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetminsizea--cpanecontainergetminsize"></a><a name="getminsize"></a>CPaneContainer::GetMinSize  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void GetMinSize(CSize& size) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `size`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetminsizelefta--cpanecontainergetminsizeleft"></a><a name="getminsizeleft"></a>CPaneContainer::GetMinSizeLeft  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void GetMinSizeLeft(CSize& size) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `size`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetminsizerighta--cpanecontainergetminsizeright"></a><a name="getminsizeright"></a>CPaneContainer::GetMinSizeRight  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void GetMinSizeRight(CSize& size) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `size`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetnodecounta--cpanecontainergetnodecount"></a><a name="getnodecount"></a>CPaneContainer::GetNodeCount  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
int GetNodeCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetpanedividera--cpanecontainergetpanedivider"></a><a name="getpanedivider"></a>CPaneContainer::GetPaneDivider  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
const CPaneDivider* GetPaneDivider() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetparentpanecontainera--cpanecontainergetparentpanecontainer"></a><a name="getparentpanecontainer"></a>CPaneContainer::GetParentPaneContainer  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
CPaneContainer* GetParentPaneContainer() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetrecentpanedividerrecta--cpanecontainergetrecentpanedividerrect"></a><a name="getrecentpanedividerrect"></a>CPaneContainer::GetRecentPaneDividerRect  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
CRect GetRecentPaneDividerRect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetrecentpanedividerstylea--cpanecontainergetrecentpanedividerstyle"></a><a name="getrecentpanedividerstyle"></a>CPaneContainer::GetRecentPaneDividerStyle  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
DWORD GetRecentPaneDividerStyle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetrecentpercenta--cpanecontainergetrecentpercent"></a><a name="getrecentpercent"></a>CPaneContainer::GetRecentPercent  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
int GetRecentPercent();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetrefcounta--cpanecontainergetrefcount"></a><a name="getrefcount"></a>CPaneContainer::GetRefCount  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
LONG GetRefCount();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetresizestepa--cpanecontainergetresizestep"></a><a name="getresizestep"></a>CPaneContainer::GetResizeStep  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual int GetResizeStep() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetrightpanea--cpanecontainergetrightpane"></a><a name="getrightpane"></a>CPaneContainer::GetRightPane  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
const CDockablePane* GetRightPane() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetrightpanecontainera--cpanecontainergetrightpanecontainer"></a><a name="getrightpanecontainer"></a>CPaneContainer::GetRightPaneContainer  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
const CPaneContainer* GetRightPaneContainer() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegettotalreferencecounta--cpanecontainergettotalreferencecount"></a><a name="gettotalreferencecount"></a>CPaneContainer::GetTotalReferenceCount  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
int GetTotalReferenceCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetwindowrecta--cpanecontainergetwindowrect"></a><a name="getwindowrect"></a>CPaneContainer::GetWindowRect  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void GetWindowRect(
    CRect& rect,  
    BOOL bIgnoreVisibility = FALSE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `rect`  
 [in] `bIgnoreVisibility`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameisdisposeda--cpanecontainerisdisposed"></a><a name="isdisposed"></a>CPaneContainer::IsDisposed  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL IsDisposed() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameisemptya--cpanecontainerisempty"></a><a name="isempty"></a>CPaneContainer::IsEmpty  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL IsEmpty() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameisleftpanea--cpanecontainerisleftpane"></a><a name="isleftpane"></a>CPaneContainer::IsLeftPane  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL IsLeftPane(CDockablePane* pBar) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameisleftpanecontainera--cpanecontainerisleftpanecontainer"></a><a name="isleftpanecontainer"></a>CPaneContainer::IsLeftPaneContainer  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL IsLeftPaneContainer() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameisleftpartemptya--cpanecontainerisleftpartempty"></a><a name="isleftpartempty"></a>CPaneContainer::IsLeftPartEmpty  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL IsLeftPartEmpty(BOOL bCheckVisibility = FALSE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bCheckVisibility`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameisrightpartemptya--cpanecontainerisrightpartempty"></a><a name="isrightpartempty"></a>CPaneContainer::IsRightPartEmpty  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL IsRightPartEmpty(BOOL bCheckVisibility = FALSE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bCheckVisibility`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameisvisiblea--cpanecontainerisvisible"></a><a name="isvisible"></a>CPaneContainer::IsVisible  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL IsVisible() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namemovea--cpanecontainermove"></a><a name="move"></a>CPaneContainer::Move  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void Move(CPoint ptNewLeftTop);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `ptNewLeftTop`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameondeletehidepanea--cpanecontainerondeletehidepane"></a><a name="ondeletehidepane"></a>CPaneContainer::OnDeleteHidePane  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void OnDeleteHidePane(
    CDockablePane* pBar,  
    BOOL bHide);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
 [in] `bHide`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameonmoveinternalpanedividera--cpanecontaineronmoveinternalpanedivider"></a><a name="onmoveinternalpanedivider"></a>CPaneContainer::OnMoveInternalPaneDivider  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual int OnMoveInternalPaneDivider(
    int nOffset,  
    HDWP& hdwp);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nOffset`  
 [in] `hdwp`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameonshowpanea--cpanecontaineronshowpane"></a><a name="onshowpane"></a>CPaneContainer::OnShowPane  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void OnShowPane(
    CDockablePane* pBar,  
    BOOL bShow);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
 [in] `bShow`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namereleasea--cpanecontainerrelease"></a><a name="release"></a>CPaneContainer::Release  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
DWORD Release();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namereleaseemptypanecontainera--cpanecontainerreleaseemptypanecontainer"></a><a name="releaseemptypanecontainer"></a>CPaneContainer::ReleaseEmptyPaneContainer  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void ReleaseEmptyPaneContainer();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameremovenonvalidpanesa--cpanecontainerremovenonvalidpanes"></a><a name="removenonvalidpanes"></a>CPaneContainer::RemoveNonValidPanes  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void RemoveNonValidPanes();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameremovepanea--cpanecontainerremovepane"></a><a name="removepane"></a>CPaneContainer::RemovePane  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void RemovePane(CDockablePane* pBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameresizea--cpanecontainerresize"></a><a name="resize"></a>CPaneContainer::Resize  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void Resize(
    CRect rect,  
    HDWP& hdwp,  
    BOOL bRedraw = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `rect`  
 [in] `hdwp`  
 [in] `bRedraw`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameresizepanea--cpanecontainerresizepane"></a><a name="resizepane"></a>CPaneContainer::ResizePane  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void ResizePane(
    int nOffset,  
    CPane* pBar,  
    CPaneContainer* pContainer,  
    BOOL bHorz,  
    BOOL bLeftBar,  
    HDWP& hdwp);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nOffset`  
 [in] `pBar`  
 [in] `pContainer`  
 [in] `bHorz`  
 [in] `bLeftBar`  
 [in] `hdwp`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameresizepartofpanecontainera--cpanecontainerresizepartofpanecontainer"></a><a name="resizepartofpanecontainer"></a>CPaneContainer::ResizePartOfPaneContainer  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void ResizePartOfPaneContainer(
    int nOffset,  
    BOOL bLeftPart,  
    HDWP& hdwp);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nOffset`  
 [in] `bLeftPart`  
 [in] `hdwp`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameserializea--cpanecontainerserialize"></a><a name="serialize"></a>CPaneContainer::Serialize  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void Serialize(CArchive& ar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `ar`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetpanea--cpanecontainersetpane"></a><a name="setpane"></a>CPaneContainer::SetPane  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void SetPane(
    CDockablePane* pBar,  
    BOOL bLeft);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
 [in] `bLeft`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetpanecontainera--cpanecontainersetpanecontainer"></a><a name="setpanecontainer"></a>CPaneContainer::SetPaneContainer  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void SetPaneContainer(
    CPaneContainer* pContainer,  
    BOOL bLeft);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pContainer`  
 [in] `bLeft`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetpanedividera--cpanecontainersetpanedivider"></a><a name="setpanedivider"></a>CPaneContainer::SetPaneDivider  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void SetPaneDivider(CPaneDivider* pSlider);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pSlider`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetparentpanecontainera--cpanecontainersetparentpanecontainer"></a><a name="setparentpanecontainer"></a>CPaneContainer::SetParentPaneContainer  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void SetParentPaneContainer(CPaneContainer* p);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `p`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetrecentpercenta--cpanecontainersetrecentpercent"></a><a name="setrecentpercent"></a>CPaneContainer::SetRecentPercent  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void SetRecentPercent(int nRecentPercent);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nRecentPercent`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetupbyida--cpanecontainersetupbyid"></a><a name="setupbyid"></a>CPaneContainer::SetUpByID  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL SetUpByID(
    UINT nID,  
    CDockablePane* pBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nID`  
 [in] `pBar`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namestorerecentdocksiteinfoa--cpanecontainerstorerecentdocksiteinfo"></a><a name="storerecentdocksiteinfo"></a>CPaneContainer::StoreRecentDockSiteInfo  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void StoreRecentDockSiteInfo(CDockablePane* pBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namestretchpanecontainera--cpanecontainerstretchpanecontainer"></a><a name="stretchpanecontainer"></a>CPaneContainer::StretchPaneContainer  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual int StretchPaneContainer(
    int nOffset,  
    BOOL bStretchHorz,  
    BOOL bLeftBar,  
    BOOL bMoveSlider,  
    HDWP& hdwp);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nOffset`  
 [in] `bStretchHorz`  
 [in] `bLeftBar`  
 [in] `bMoveSlider`  
 [in] `hdwp`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Classe CPaneContainerManager](../../mfc/reference/cpanecontainermanager-class.md)

