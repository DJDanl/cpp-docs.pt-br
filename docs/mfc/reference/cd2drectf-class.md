---
title: Classe CD2DRectF | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CD2DRectF
- AFXRENDERTARGET/CD2DRectF
- AFXRENDERTARGET/CD2DRectF::CD2DRectF
- AFXRENDERTARGET/CD2DRectF::IsNull
dev_langs:
- C++
helpviewer_keywords:
- CD2DRectF [MFC], CD2DRectF
- CD2DRectF [MFC], IsNull
ms.assetid: 87c12d87-9d18-4a19-ba14-0f51d6b6835a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1f96adf519eb710d412465a9db4cbd7313f91f41
ms.sourcegitcommit: 6408139d5f5ff8928f056bde93d20eecb3520361
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/02/2018
ms.locfileid: "37338266"
---
# <a name="cd2drectf-class"></a>Classe CD2DRectF
Um wrapper para `D2D1_RECT_F`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CD2DRectF : public D2D1_RECT_F;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DRectF::CD2DRectF](#cd2drectf)|Sobrecarregado. Constrói uma `CD2DRectF` do objeto de `D2D1_RECT_F` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DRectF::IsNull](#isnull)|Retorna um **boolean** valor que indica se uma expressão não contém dados válidos (nulo).|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DRectF::Operator CRect](#operator_crect)|Converte `CD2DRectF` para `CRect` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `D2D1_RECT_F`  
  
 `CD2DRectF`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="cd2drectf"></a>  CD2DRectF::CD2DRectF  
 Constrói um objeto CD2DRectF objeto CRect.  
  
```  
CD2DRectF(const CRect& rect);  
CD2DRectF(const D2D1_RECT_F& rect);  
  CD2DRectF(const D2D1_RECT_F* rect);

 
CD2DRectF(
    FLOAT fLeft = 0.,  
    FLOAT fTop = 0.,  
    FLOAT fRight = 0.,  
    FLOAT fBottom = 0.);
```  
  
### <a name="parameters"></a>Parâmetros  
 *Rect*  
 retângulo de origem  
  
 *fLeft*  
 coordenada esquerda do código-fonte  
  
 *fTop*  
 coordenada superior do código-fonte  
  
 *baterão*  
 origem de coordenada direita  
  
 *fBottom*  
 coordenada inferior de origem  
  
##  <a name="isnull"></a>  CD2DRectF::IsNull  
 Retorna um valor booliano que indica se uma expressão não contém dados válidos (nulo).  
  
```  
BOOL IsNull() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a parte superior, esquerda, inferior e valores corretos do retângulo são todas iguais a 0; Caso contrário, FALSE.  
  
##  <a name="operator_crect"></a>  CD2DRectF::Operator CRect  
 Converte CD2DRectF objeto CRect.  
  
```  
operator CRect();
```   
  
### <a name="return-value"></a>Valor de retorno  
 Valor atual do retângulo D2D.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
