---
title: Classe CD2DEllipse | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b4c4a801952c6b29779c381237c291232ce2ef25
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33347741"
---
# <a name="cd2dellipse-class"></a>Classe CD2DEllipse
Um wrapper para `D2D1_ELLIPSE`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CD2DEllipse : public D2D1_ELLIPSE;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DEllipse::CD2DEllipse](#cd2dellipse)|Sobrecarregado. Constrói um `CD2DEllipse` de objeto `D2D1_ELLIPSE` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `D2D1_ELLIPSE`  
  
 `CD2DEllipse`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="cd2dellipse"></a>  CD2DEllipse::CD2DEllipse  
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
