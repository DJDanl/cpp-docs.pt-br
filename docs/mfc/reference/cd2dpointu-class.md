---
title: Classe CD2DPointU | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CD2DPointU
- AFXRENDERTARGET/CD2DPointU
- AFXRENDERTARGET/CD2DPointU::CD2DPointU
dev_langs:
- C++
helpviewer_keywords:
- CD2DPointU class
ms.assetid: 04733f96-b6de-4a89-82e3-caad1e8087a9
caps.latest.revision: 18
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
ms.openlocfilehash: 605415ad5a2739d8f8ac3a6a47c562796d55a813
ms.lasthandoff: 02/25/2017

---
# <a name="cd2dpointu-class"></a>Classe CD2DPointU
Um wrapper para `D2D1_POINT_2U`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CD2DPointU : public D2D1_POINT_2U;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DPointU::CD2DPointU](#cd2dpointu)|Sobrecarregado. Constrói uma `CD2DPointU` de objeto `D2D1_POINT_2U` objeto.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DPointU::Operator CPoint](#operator_cpoint)|Converte `CD2DPointU` para `CPoint` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `D2D1_POINT_2U`  
  
 `CD2DPointU`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="cd2dpointu"></a>CD2DPointU::CD2DPointU  
 Constrói um objeto CD2DPointU do objeto CPoint.  
  
```  
CD2DPointU(const CPoint& pt);  
CD2DPointU(const D2D1_POINT_2U& pt);  
  CD2DPointU(const D2D1_POINT_2U* pt);  
CD2DPointU(UINT32 uX = 0, UINT32 uY = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pt`  
 ponto de origem  
  
 `uX`  
 fonte de X  
  
 `uY`  
 origem Y  
  
##  <a name="operator_cpoint"></a>CD2DPointU::Operator CPoint  
 Converte CD2DPointU CPoint objeto.  
  
```  
operator CPoint();
```   
  
### <a name="return-value"></a>Valor de retorno  
 Valor atual de D2D ponto.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

