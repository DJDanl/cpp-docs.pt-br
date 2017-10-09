---
title: Classe CD2DSizeU | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CD2DSizeU
- AFXRENDERTARGET/CD2DSizeU
- AFXRENDERTARGET/CD2DSizeU::CD2DSizeU
- AFXRENDERTARGET/CD2DSizeU::IsNull
dev_langs:
- C++
helpviewer_keywords:
- CD2DSizeU [MFC], CD2DSizeU
- CD2DSizeU [MFC], IsNull
ms.assetid: 6e679ba8-2112-43c3-8275-70b660856f02
caps.latest.revision: 18
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 4a770b6508067913aec51b8b3878f33e30eed4bb
ms.openlocfilehash: 270d668cba8e2628f4386df391a368fef8557fad
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="cd2dsizeu-class"></a>Classe CD2DSizeU
Um wrapper para D2D1_SIZE_U.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CD2DSizeU : public D2D1_SIZE_U;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DSizeU::CD2DSizeU](#cd2dsizeu)|Sobrecarregado. Constrói um `CD2DSizeU` de objeto `D2D1_SIZE_U` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DSizeU::IsNull](#isnull)|Retorna um `boolean` valor que indica se uma expressão não contém dados válidos ( `null`).|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DSizeU::Operator CSize](#operator_csize)|Converte `CD2DSizeU` para `CSize` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `D2D1_SIZE_U`  
  
 [CD2DSizeU](../../mfc/reference/cd2dsizeu-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="cd2dsizeu"></a>CD2DSizeU::CD2DSizeU  
 Constrói um objeto CD2DSizeU do objeto CSize.  
  
```  
CD2DSizeU(const CSize& size);  
CD2DSizeU(const D2D1_SIZE_U& size);  
  CD2DSizeU(const D2D1_SIZE_U* size);

 
CD2DSizeU(
    UINT32 cx = 0,  
    UINT32 cy = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `size`  
 tamanho da fonte  
  
 `cx`  
 largura de origem  
  
 `cy`  
 altura de origem  
  
##  <a name="isnull"></a>CD2DSizeU::IsNull  
 Retorna um valor booliano que indica se uma expressão não contém dados válidos (nulo).  
  
```  
BOOL IsNull() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a largura e altura estão vazios. Caso contrário, FALSE.  
  
##  <a name="operator_csize"></a>CD2DSizeU::Operator CSize  
 Converte CD2DSizeU CSize objeto.  
  
```  
operator CSize();
```   
  
### <a name="return-value"></a>Valor de retorno  
 Valor atual de tamanho D2D.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

