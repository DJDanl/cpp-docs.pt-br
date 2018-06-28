---
title: Classe CMFCDragFrameImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCDragFrameImpl
dev_langs:
- C++
helpviewer_keywords:
- CMFCDragFrameImpl class [MFC]
ms.assetid: 500cd824-8188-43c2-8754-b7bb46b5648a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 458288ecff0b457205ba1735494ad8106c3feae7
ms.sourcegitcommit: f1b051abb1de3fe96350be0563aaf4e960da13c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/27/2018
ms.locfileid: "37040942"
---
# <a name="cmfcdragframeimpl-class"></a>Classe CMFCDragFrameImpl
O `CMFCDragFrameImpl` classe desenha arrastar retângulo que é exibido quando o usuário arrasta um painel no modo padrão de encaixe.  
   [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
   
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCDragFrameImpl  
```  
  
## <a name="remarks"></a>Comentários  
 Um objeto dessa classe é inserido em cada [CPane classe](../../mfc/reference/cpane-class.md) objeto. Assim, cada painel que usa o `CanFloat` método exibe um retângulo de arrastar quando o usuário arrasta-lo.  
  
 Você pode controlar a espessura do retângulo arrastar usando [AFX_GLOBAL_DATA::m_nDragFrameThicknessFloat](afx-global-data-structure.md#m_ndragframethicknessfloat) e [AFX_GLOBAL_DATA::m_nDragFrameThicknessDock](afx-global-data-structure.md#m_ndragframethicknessdock).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CMFCDragFrameImpl](../../mfc/reference/cmfcdragframeimpl-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdragframeimpl.h  
  
##  <a name="enddrawdragframe"></a>  CMFCDragFrameImpl::EndDrawDragFrame  

  
```  
void EndDrawDragFrame(BOOL bClearInternalRects = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bClearInternalRects*  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="init"></a>  CMFCDragFrameImpl::Init  

  
```  
void Init(CWnd* pDraggedWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pDraggedWnd*  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="movedragframe"></a>  CMFCDragFrameImpl::MoveDragFrame  

  
```  
void MoveDragFrame(BOOL bForceMove = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bForceMove*  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="placetabpredocking"></a>  CMFCDragFrameImpl::PlaceTabPreDocking  

  
```  
void PlaceTabPreDocking(
    CBaseTabbedPane* pTabbedBar,  
    BOOL bFirstTime);  
  
void PlaceTabPreDocking(CWnd* pCBarToPlaceOn);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pTabbedBar*  
 [in] *bFirstTime*  
 [in] *pCBarToPlaceOn*  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="removetabpredocking"></a>  CMFCDragFrameImpl::RemoveTabPreDocking  

  
```  
void RemoveTabPreDocking(CDockablePane* pOldTargetBar = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pOldTargetBar*  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="resetstate"></a>  CMFCDragFrameImpl::ResetState  

  
```  
void ResetState();
```  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CPane](../../mfc/reference/cpane-class.md)