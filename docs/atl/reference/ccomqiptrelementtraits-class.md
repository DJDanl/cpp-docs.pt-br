---
title: Classe CComQIPtrElementTraits | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComQIPtrElementTraits
- ATLCOLL/ATL::CComQIPtrElementTraits
- ATLCOLL/ATL::CComQIPtrElementTraits::INARGTYPE
dev_langs:
- C++
helpviewer_keywords:
- CComQIPtrElementTraits class
ms.assetid: 9df9250a-5413-4362-b133-332932a597c4
caps.latest.revision: 19
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 5a0c6a1062330f952bb8fa52bc934f6754465513
ms.openlocfilehash: d6405cc3ec04988d0e0d7dd9a98f22c271b3608d
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="ccomqiptrelementtraits-class"></a>Classe CComQIPtrElementTraits
Essa classe fornece métodos, funções estáticas e typedefs útil ao criar coleções de ponteiros de interface COM.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<typename I, const IID* piid=& __uuidof(I)>  
class CComQIPtrElementTraits : 
   public CDefaultElementTraits<ATL::CComQIPtr<I, piid>>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `I`  
 Uma interface COM especificando o tipo de ponteiro a ser armazenado.  
  
 `piid`  
 Um ponteiro para o IID da `I`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComQIPtrElementTraits::INARGTYPE](#inargtype)|O tipo de dados a ser usado para adicionar elementos para o objeto de classe de coleção.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe deriva de métodos e fornece um typedef útil ao criar uma classe de coleção de [CComQIPtr](../../atl/reference/ccomqiptr-class.md) objetos de ponteiro de interface COM. Essa classe é utilizada por ambos os [CInterfaceArray](../../atl/reference/cinterfacearray-class.md) e [CInterfaceList](../../atl/reference/cinterfacelist-class.md) classes.  
  
 Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CDefaultCompareTraits](../../atl/reference/cdefaultcomparetraits-class.md)  
  
 [CDefaultHashTraits](../../atl/reference/cdefaulthashtraits-class.md)  
  
 [CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)  
  
 [CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)  
  
 `CComQIPtrElementTraits`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcoll.h  
  
##  <a name="inargtype"></a>CComQIPtrElementTraits::INARGTYPE  
 O tipo de dados a ser usado para adicionar elementos para o objeto de classe de coleção.  
  
```
typedef I* INARGTYPE;
```  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

