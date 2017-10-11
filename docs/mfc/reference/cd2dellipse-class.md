---
title: Classe CD2DEllipse | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CD2DEllipse
- AFXRENDERTARGET/CD2DEllipse
- AFXRENDERTARGET/CD2DEllipse::CD2DEllipse
dev_langs:
- C++
helpviewer_keywords:
- CD2DEllipse [MFC], CD2DEllipse
ms.assetid: e9f02f54-acf2-427e-b349-db50cd9a77df
caps.latest.revision: 18
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 4a770b6508067913aec51b8b3878f33e30eed4bb
ms.openlocfilehash: 97a14391eda7716b71560a5f1e65a4bd65a329d1
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="cd2dellipse-class"></a>Classe CD2DEllipse
Um wrapper para `D2D1_ELLIPSE`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CD2DEllipse : public D2D1_ELLIPSE;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DEllipse::CD2DEllipse](#cd2dellipse)|Sobrecarregado. Constrói um `CD2DEllipse` de objeto `D2D1_ELLIPSE` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `D2D1_ELLIPSE`  
  
 `CD2DEllipse`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="cd2dellipse"></a>CD2DEllipse::CD2DEllipse  
 Constrói um objeto CD2DEllipse do objeto CD2DRectF.  
  
```  
CD2DEllipse(const CD2DRectF& rect);  
CD2DEllipse(const D2D1_ELLIPSE& ellipse);  
  CD2DEllipse(const D2D1_ELLIPSE* ellipse);

 
CD2DEllipse(
    const CD2DPointF& ptCenter,  
    const CD2DSizeF& sizeRadius);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rect`  
 retângulo de origem  
  
 `ellipse`  
 elipse de origem  
  
 `ptCenter`  
 O ponto central da elipse.  
  
 `sizeRadius`  
 O raio X e radius de Y da elipse.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

