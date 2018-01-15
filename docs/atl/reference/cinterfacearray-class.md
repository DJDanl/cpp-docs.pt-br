---
title: Classe CInterfaceArray | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CInterfaceArray
- ATLCOLL/ATL::CInterfaceArray
- ATLCOLL/ATL::CInterfaceArray::CInterfaceArray
dev_langs: C++
helpviewer_keywords: CInterfaceArray class
ms.assetid: 1f29cf66-a086-4a7b-b6a8-64f73da39f79
caps.latest.revision: "18"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ece9858d0be171febaeb52e820e922665ac2a351
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cinterfacearray-class"></a>Classe CInterfaceArray
Essa classe fornece métodos úteis ao construir uma matriz de ponteiros de interface COM.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class I, const IID* piid=& __uuidof(I)>  
class CInterfaceArray : 
   public CAtlArray<ATL::CComQIPtr<I, piid>,
                    CComQIPtrElementTraits<I, piid>>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `I`  
 Uma interface COM especificando o tipo de ponteiro para ser armazenado.  
  
 `piid`  
 Um ponteiro para o IID da `I`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CInterfaceArray::CInterfaceArray](#cinterfacearray)|O construtor para a matriz de interface.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece um construtor e métodos derivados para criar uma matriz de ponteiros de interface COM. Use [CInterfaceList](../../atl/reference/cinterfacelist-class.md) quando uma lista é necessária.  
  
 Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CAtlArray`  
  
 `CInterfaceArray`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcoll.h  
  
##  <a name="cinterfacearray"></a>CInterfaceArray::CInterfaceArray  
 O construtor.  
  
```
CInterfaceArray() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Inicializa a matriz de ponteiro inteligente.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CAtlArray](../../atl/reference/catlarray-class.md)   
 [Classe CComQIPtr](../../atl/reference/ccomqiptr-class.md)   
 [Classe CComQIPtrElementTraits](../../atl/reference/ccomqiptrelementtraits-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
