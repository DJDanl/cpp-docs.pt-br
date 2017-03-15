---
title: Classe CD2DSizeU | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CD2DSizeU
- afxrendertarget/CD2DSizeU
dev_langs:
- C++
helpviewer_keywords:
- CD2DSizeU class
ms.assetid: 6e679ba8-2112-43c3-8275-70b660856f02
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
ms.openlocfilehash: a43ea5448a0b0d09d4cf27eafb01a4d4b610e4f5
ms.lasthandoff: 02/25/2017

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
|[CD2DSizeU::CD2DSizeU](#cd2dsizeu)|Sobrecarregado. Constrói uma `CD2DSizeU` de objeto `D2D1_SIZE_U` objeto.|  
  
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
  
##  <a name="a-namecd2dsizeua--cd2dsizeucd2dsizeu"></a><a name="cd2dsizeu"></a>CD2DSizeU::CD2DSizeU  
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
  
##  <a name="a-nameisnulla--cd2dsizeuisnull"></a><a name="isnull"></a>CD2DSizeU::IsNull  
 Retorna um valor booliano que indica se uma expressão não contém dados válidos (nulo).  
  
```  
BOOL IsNull() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a largura e altura são vazios. Caso contrário, FALSE.  
  
##  <a name="a-nameoperatorcsizea--cd2dsizeuoperator-csize"></a><a name="operator_csize"></a>CD2DSizeU::Operator CSize  
 Converte CD2DSizeU CSize objeto.  
  
```  
operator CSize();
```   
  
### <a name="return-value"></a>Valor de retorno  
 Valor atual de tamanho D2D.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

