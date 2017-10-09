---
title: Classe CD2DGradientBrush | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CD2DGradientBrush
- AFXRENDERTARGET/CD2DGradientBrush
- AFXRENDERTARGET/CD2DGradientBrush::CD2DGradientBrush
- AFXRENDERTARGET/CD2DGradientBrush::Destroy
- AFXRENDERTARGET/CD2DGradientBrush::m_arGradientStops
- AFXRENDERTARGET/CD2DGradientBrush::m_colorInterpolationGamma
- AFXRENDERTARGET/CD2DGradientBrush::m_extendMode
- AFXRENDERTARGET/CD2DGradientBrush::m_pGradientStops
dev_langs:
- C++
helpviewer_keywords:
- CD2DGradientBrush [MFC], CD2DGradientBrush
- CD2DGradientBrush [MFC], Destroy
- CD2DGradientBrush [MFC], m_arGradientStops
- CD2DGradientBrush [MFC], m_colorInterpolationGamma
- CD2DGradientBrush [MFC], m_extendMode
- CD2DGradientBrush [MFC], m_pGradientStops
ms.assetid: 5bf133e6-16b7-4e3a-845d-0ce63fafe5ec
caps.latest.revision: 17
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 4a770b6508067913aec51b8b3878f33e30eed4bb
ms.openlocfilehash: 0fdfbf838b8c0e294c8ddbd550a982c89b129df2
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="cd2dgradientbrush-class"></a>Classe CD2DGradientBrush
A classe base do CD2DLinearGradientBrush e as classes de CD2DRadialGradientBrush.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CD2DGradientBrush : public CD2DBrush;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DGradientBrush::CD2DGradientBrush](#cd2dgradientbrush)|Constrói um objeto CD2DGradientBrush.|  
|[CD2DGradientBrush:: ~ CD2DGradientBrush](#cd2dgradientbrush__~cd2dgradientbrush)|O destruidor. Chamado quando um objeto de um pincel de gradiente D2D está sendo destruído.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DGradientBrush::Destroy](#destroy)|Destrói um objeto CD2DGradientBrush. (Substitui [CD2DBrush::Destroy](../../mfc/reference/cd2dbrush-class.md#destroy).)|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DGradientBrush::m_arGradientStops](#m_argradientstops)|Matriz de estruturas de D2D1_GRADIENT_STOP.|  
|[CD2DGradientBrush::m_colorInterpolationGamma](#m_colorinterpolationgamma)|O espaço no qual cor interpolação entre os limites de gradiente é executada.|  
|[CD2DGradientBrush::m_extendMode](#m_extendmode)|O comportamento do gradiente fora do intervalo [0,1] de normalizado.|  
|[CD2DGradientBrush::m_pGradientStops](#m_pgradientstops)|Um ponteiro para uma matriz de estruturas de D2D1_GRADIENT_STOP.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CD2DResource](../../mfc/reference/cd2dresource-class.md)  
  
 [CD2DBrush](../../mfc/reference/cd2dbrush-class.md)  
  
 `CD2DGradientBrush`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="_dtorcd2dgradientbrush"></a>CD2DGradientBrush:: ~ CD2DGradientBrush  
 O destruidor. Chamado quando um objeto de um pincel de gradiente D2D está sendo destruído.  
  
```  
virtual ~CD2DGradientBrush();
```  
  
##  <a name="cd2dgradientbrush"></a>CD2DGradientBrush::CD2DGradientBrush  
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
 O espaço no qual cor interpolação entre os limites de gradiente é executada.  
  
 `extendMode`  
 O comportamento do gradiente fora do intervalo [0,1] de normalizado.  
  
 `pBrushProperties`  
 Um ponteiro para a opacidade e a transformação de um pincel.  
  
 `bAutoDestroy`  
 Indica se o objeto será destruído pelo proprietário (pParentTarget).  
  
##  <a name="destroy"></a>CD2DGradientBrush::Destroy  
 Destrói um objeto CD2DGradientBrush.  
  
```  
virtual void Destroy();
```  
  
##  <a name="m_argradientstops"></a>CD2DGradientBrush::m_arGradientStops  
 Matriz de estruturas de D2D1_GRADIENT_STOP.  
  
```  
CArray<D2D1_GRADIENT_STOP, D2D1_GRADIENT_STOP> m_arGradientStops;  
```  
  
##  <a name="m_colorinterpolationgamma"></a>CD2DGradientBrush::m_colorInterpolationGamma  
 O espaço no qual cor interpolação entre os limites de gradiente é executada.  
  
```  
D2D1_GAMMA m_colorInterpolationGamma;  
```  
  
##  <a name="m_extendmode"></a>CD2DGradientBrush::m_extendMode  
 O comportamento do gradiente fora do intervalo [0,1] de normalizado.  
  
```  
D2D1_EXTEND_MODE m_extendMode;  
```  
  
##  <a name="m_pgradientstops"></a>CD2DGradientBrush::m_pGradientStops  
 Um ponteiro para uma matriz de estruturas de D2D1_GRADIENT_STOP.  
  
```  
ID2D1GradientStopCollection* m_pGradientStops;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

