---
title: Classe CD2DSizeF | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CD2DSizeF
- AFXRENDERTARGET/CD2DSizeF
- AFXRENDERTARGET/CD2DSizeF::CD2DSizeF
- AFXRENDERTARGET/CD2DSizeF::IsNull
dev_langs:
- C++
helpviewer_keywords:
- CD2DSizeF [MFC], CD2DSizeF
- CD2DSizeF [MFC], IsNull
ms.assetid: f486a1e1-997d-4286-8cb9-26369dc82055
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0093c92604013e4c1aef4046f244d7bcd3f71958
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33353319"
---
# <a name="cd2dsizef-class"></a>Classe CD2DSizeF
Um wrapper para D2D1_SIZE_F.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CD2DSizeF : public D2D1_SIZE_F;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DSizeF::CD2DSizeF](#cd2dsizef)|Sobrecarregado. Constrói um `CD2DSizeF` de objeto `D2D1_SIZE_F` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DSizeF::IsNull](#isnull)|Retorna um `boolean` valor que indica se uma expressão não contém dados válidos ( `null`).|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DSizeF::Operator CSize](#operator_csize)|Converte `CD2DSizeF` para `CSize` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `D2D1_SIZE_F`  
  
 [CD2DSizeF](../../mfc/reference/cd2dsizef-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="cd2dsizef"></a>  CD2DSizeF::CD2DSizeF  
 Constrói um objeto CD2DSizeF do objeto CSize.  
  
```  
CD2DSizeF(const CSize& size);  
CD2DSizeF(const D2D1_SIZE_F& size);  
  CD2DSizeF(const D2D1_SIZE_F* size);

 
CD2DSizeF(
    FLOAT cx = 0.,  
    FLOAT cy = 0.);
```  
  
### <a name="parameters"></a>Parâmetros  
 `size`  
 tamanho da fonte  
  
 `cx`  
 largura de origem  
  
 `cy`  
 altura de origem  
  
##  <a name="isnull"></a>  CD2DSizeF::IsNull  
 Retorna um valor booliano que indica se uma expressão não contém dados válidos (nulo).  
  
```  
BOOL IsNull() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a largura e altura estão vazios. Caso contrário, FALSE.  
  
##  <a name="operator_csize"></a>  CD2DSizeF::Operator CSize  
 Converte CD2DSizeF CSize objeto.  
  
```  
operator CSize();
```   
  
### <a name="return-value"></a>Valor de retorno  
 Valor atual de tamanho D2D.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
