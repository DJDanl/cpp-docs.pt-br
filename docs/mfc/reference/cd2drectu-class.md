---
title: Classe CD2DRectU | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CD2DRectU
- AFXRENDERTARGET/CD2DRectU
- AFXRENDERTARGET/CD2DRectU::CD2DRectU
- AFXRENDERTARGET/CD2DRectU::IsNull
dev_langs:
- C++
helpviewer_keywords:
- CD2DRectU [MFC], CD2DRectU
- CD2DRectU [MFC], IsNull
ms.assetid: a62f17d1-011d-4867-8f51-fd7e7c00561d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 36d960cfc0ce3d9d5632edd3a1b42903f3cdd0f6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33352012"
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
  
##  <a name="cd2drectu"></a>  CD2DRectU::CD2DRectU  
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
  
##  <a name="isnull"></a>  CD2DRectU::IsNull  
 Retorna um valor booliano que indica se uma expressão não contém dados válidos (nulo).  
  
```  
BOOL IsNull() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a parte superior do retângulo, esquerdo, inferior e valores corretos são todos iguais a 0; Caso contrário, FALSE.  
  
##  <a name="operator_crect"></a>  CD2DRectU::Operator CRect  
 Converte CD2DRectU CRect objeto.  
  
```  
operator CRect();
```   
  
### <a name="return-value"></a>Valor de retorno  
 Valor atual do retângulo D2D.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
