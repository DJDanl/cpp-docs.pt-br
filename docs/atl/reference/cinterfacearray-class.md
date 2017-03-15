---
title: Classe CInterfaceArray | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL.CInterfaceArray
- CInterfaceArray
- ATL::CInterfaceArray
dev_langs:
- C++
helpviewer_keywords:
- CInterfaceArray class
ms.assetid: 1f29cf66-a086-4a7b-b6a8-64f73da39f79
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
ms.sourcegitcommit: 5a0c6a1062330f952bb8fa52bc934f6754465513
ms.openlocfilehash: a2a99eb3cff4f2381d4c58e4d1a7aaa167e83896
ms.lasthandoff: 02/25/2017

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
 Uma interface COM especificando o tipo de ponteiro a ser armazenado.  
  
 `piid`  
 Um ponteiro para o IID da `I`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
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
  
##  <a name="a-namecinterfacearraya--cinterfacearraycinterfacearray"></a><a name="cinterfacearray"></a>CInterfaceArray::CInterfaceArray  
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

