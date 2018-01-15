---
title: Classe CD2DRectU | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CD2DRectU
- AFXRENDERTARGET/CD2DRectU
- AFXRENDERTARGET/CD2DRectU::CD2DRectU
- AFXRENDERTARGET/CD2DRectU::IsNull
dev_langs: C++
helpviewer_keywords:
- CD2DRectU [MFC], CD2DRectU
- CD2DRectU [MFC], IsNull
ms.assetid: a62f17d1-011d-4867-8f51-fd7e7c00561d
caps.latest.revision: "18"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2bf261f31f470862a506466a8815daef796743f6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cd2drectu-class"></a>Classe CD2DRectU
Um wrapper para `D2D1_RECT_U`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CD2DRectU : public D2D1_RECT_U;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DRectU::CD2DRectU](#cd2drectu)|Sobrecarregado. Constrói um `CD2DRectU` de objeto `D2D1_RECT_U` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DRectU::IsNull](#isnull)|Retorna um `boolean` valor que indica se uma expressão não contém dados válidos ( `null`).|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DRectU::Operator CRect](#operator_crect)|Converte `CD2DRectU` para `CRect` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `D2D1_RECT_U`  
  
 `CD2DRectU`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="cd2drectu"></a>CD2DRectU::CD2DRectU  
 Constrói um objeto CD2DRectU do objeto CRect.  
  
```  
CD2DRectU(const CRect& rect);  
CD2DRectU(const D2D1_RECT_U& rect);  
  CD2DRectU(const D2D1_RECT_U* rect);

 
CD2DRectU(
    UINT32 uLeft = 0,  
    UINT32 uTop = 0,  
    UINT32 uRight = 0,  
    UINT32 uBottom = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rect`  
 retângulo de origem  
  
 `uLeft`  
 coordenada esquerda do código-fonte  
  
 `uTop`  
 coordenada superior do código-fonte  
  
 `uRight`  
 fonte de coordenada direita  
  
 `uBottom`  
 coordenada inferior de origem  
  
##  <a name="isnull"></a>CD2DRectU::IsNull  
 Retorna um valor booliano que indica se uma expressão não contém dados válidos (nulo).  
  
```  
BOOL IsNull() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a parte superior do retângulo, esquerdo, inferior e valores corretos são todos iguais a 0; Caso contrário, FALSE.  
  
##  <a name="operator_crect"></a>CD2DRectU::Operator CRect  
 Converte CD2DRectU CRect objeto.  
  
```  
operator CRect();
```   
  
### <a name="return-value"></a>Valor de retorno  
 Valor atual do retângulo D2D.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
