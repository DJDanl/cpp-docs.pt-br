---
title: Classe CD2DGradientBrush | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CD2DGradientBrush
- afxrendertarget/CD2DGradientBrush
dev_langs:
- C++
helpviewer_keywords:
- CD2DGradientBrush class
ms.assetid: 5bf133e6-16b7-4e3a-845d-0ce63fafe5ec
caps.latest.revision: 17
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
ms.sourcegitcommit: 73410ae17465880f455e5b15026f6cc010803c19
ms.openlocfilehash: 0b0a692ef2b5194daf7b38eed9ebe3b2f4eda448
ms.lasthandoff: 02/25/2017

---
# <a name="cd2dgradientbrush-class"></a>Classe CD2DGradientBrush
A classe base das classes CD2DRadialGradientBrush e o CD2DLinearGradientBrush.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CD2DGradientBrush : public CD2DBrush;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DGradientBrush::CD2DGradientBrush](#cd2dgradientbrush)|Constrói um objeto CD2DGradientBrush.|  
|[CD2DGradientBrush:: ~ CD2DGradientBrush](#cd2dgradientbrush__~cd2dgradientbrush)|O destruidor. Chamado quando um objeto de pincel de gradiente D2D está sendo destruído.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DGradientBrush::Destroy](#destroy)|Destrói um objeto CD2DGradientBrush. (Substitui [CD2DBrush::Destroy](../../mfc/reference/cd2dbrush-class.md#destroy).)|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DGradientBrush::m_arGradientStops](#m_argradientstops)|Matriz de estruturas de D2D1_GRADIENT_STOP.|  
|[CD2DGradientBrush::m_colorInterpolationGamma](#m_colorinterpolationgamma)|O espaço no qual cor interpolação entre as paradas de gradiente é executada.|  
|[CD2DGradientBrush::m_extendMode](#m_extendmode)|O comportamento do gradiente fora do intervalo [0,1] de normalizado.|  
|[CD2DGradientBrush::m_pGradientStops](#m_pgradientstops)|Um ponteiro para uma matriz de estruturas de D2D1_GRADIENT_STOP.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CD2DResource](../../mfc/reference/cd2dresource-class.md)  
  
 [CD2DBrush](../../mfc/reference/cd2dbrush-class.md)  
  
 `CD2DGradientBrush`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="a-namedtorcd2dgradientbrusha--cd2dgradientbrushcd2dgradientbrush"></a><a name="_dtorcd2dgradientbrush"></a>CD2DGradientBrush:: ~ CD2DGradientBrush  
 O destruidor. Chamado quando um objeto de pincel de gradiente D2D está sendo destruído.  
  
```  
virtual ~CD2DGradientBrush();
```  
  
##  <a name="a-namecd2dgradientbrusha--cd2dgradientbrushcd2dgradientbrush"></a><a name="cd2dgradientbrush"></a>CD2DGradientBrush::CD2DGradientBrush  
 Constrói um objeto CD2DGradientBrush.  
  
```  
CD2DGradientBrush(
    CRenderTarget* pParentTarget,  
    const D2D1_GRADIENT_STOP* gradientStops,  
    UINT gradientStopsCount,  
    D2D1_GAMMA colorInterpolationGamma = D2D1_GAMMA_2_2,  
    D2D1_EXTEND_MODE extendMode = D2D1_EXTEND_MODE_CLAMP,  
    CD2DBrushProperties* pBrushProperties = NULL,  
    BOOL bAutoDestroy = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pParentTarget`  
 Um ponteiro para o destino de renderização.  
  
 `gradientStops`  
 Um ponteiro para uma matriz de estruturas de D2D1_GRADIENT_STOP.  
  
 `gradientStopsCount`  
 Um valor maior que ou igual a 1 que especifica o número de paradas de gradiente na matriz gradientStops.  
  
 `colorInterpolationGamma`  
 O espaço no qual cor interpolação entre as paradas de gradiente é executada.  
  
 `extendMode`  
 O comportamento do gradiente fora do intervalo [0,1] de normalizado.  
  
 `pBrushProperties`  
 Um ponteiro para a opacidade e a transformação de um pincel.  
  
 `bAutoDestroy`  
 Indica que o objeto será destruído pelo proprietário (pParentTarget).  
  
##  <a name="a-namedestroya--cd2dgradientbrushdestroy"></a><a name="destroy"></a>CD2DGradientBrush::Destroy  
 Destrói um objeto CD2DGradientBrush.  
  
```  
virtual void Destroy();
```  
  
##  <a name="a-namemargradientstopsa--cd2dgradientbrushmargradientstops"></a><a name="m_argradientstops"></a>CD2DGradientBrush::m_arGradientStops  
 Matriz de estruturas de D2D1_GRADIENT_STOP.  
  
```  
CArray<D2D1_GRADIENT_STOP, D2D1_GRADIENT_STOP> m_arGradientStops;  
```  
  
##  <a name="a-namemcolorinterpolationgammaa--cd2dgradientbrushmcolorinterpolationgamma"></a><a name="m_colorinterpolationgamma"></a>CD2DGradientBrush::m_colorInterpolationGamma  
 O espaço no qual cor interpolação entre as paradas de gradiente é executada.  
  
```  
D2D1_GAMMA m_colorInterpolationGamma;  
```  
  
##  <a name="a-namemextendmodea--cd2dgradientbrushmextendmode"></a><a name="m_extendmode"></a>CD2DGradientBrush::m_extendMode  
 O comportamento do gradiente fora do intervalo [0,1] de normalizado.  
  
```  
D2D1_EXTEND_MODE m_extendMode;  
```  
  
##  <a name="a-namempgradientstopsa--cd2dgradientbrushmpgradientstops"></a><a name="m_pgradientstops"></a>CD2DGradientBrush::m_pGradientStops  
 Um ponteiro para uma matriz de estruturas de D2D1_GRADIENT_STOP.  
  
```  
ID2D1GradientStopCollection* m_pGradientStops;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

