---
title: Classe CD2DPointF | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CD2DPointF
- AFXRENDERTARGET/CD2DPointF
- AFXRENDERTARGET/CD2DPointF::CD2DPointF
dev_langs:
- C++
helpviewer_keywords:
- CD2DPointF [MFC], CD2DPointF
ms.assetid: 30f72083-1c8a-4f50-adb2-72dbbe3522d4
caps.latest.revision: 18
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 4a770b6508067913aec51b8b3878f33e30eed4bb
ms.openlocfilehash: 98435819aeb0e173074a4794939bee10b00b3233
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="cd2dpointf-class"></a>Classe CD2DPointF
Um wrapper para `D2D1_POINT_2F`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CD2DPointF : public D2D1_POINT_2F;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DPointF::CD2DPointF](#cd2dpointf)|Sobrecarregado. Constrói um `CD2DPointF` de objeto `D2D1_POINT_2F` objeto.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DPointF::Operator CPoint](#operator_cpoint)|Converte `CD2DPointF` para `CPoint` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `D2D1_POINT_2F`  
  
 `CD2DPointF`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="cd2dpointf"></a>CD2DPointF::CD2DPointF  
 Constrói um objeto CD2DPointF do objeto CPoint.  
  
```  
CD2DPointF(const CPoint& pt);    
CD2DPointF(const D2D1_POINT_2F& pt);    
CD2DPointF(const D2D1_POINT_2F* pt); 
CD2DPointF(FLOAT fX = 0., FLOAT fY = 0.);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pt`  
 ponto de origem  
  
 `fX`  
 fonte de X  
  
 `fY`  
 origem Y  
  
##  <a name="operator_cpoint"></a>CD2DPointF::Operator CPoint  
 Converte CD2DPointF CPoint objeto.  
  
```  
operator CPoint();
```   
  
### <a name="return-value"></a>Valor de retorno  
 Valor atual do ponto de D2D.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

