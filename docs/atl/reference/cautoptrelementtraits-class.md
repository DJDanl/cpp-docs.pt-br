---
title: Classe CAutoPtrElementTraits | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL.CAutoPtrElementTraits
- CAutoPtrElementTraits
- ATL::CAutoPtrElementTraits<T>
- ATL.CAutoPtrElementTraits<T>
- ATL::CAutoPtrElementTraits
dev_langs:
- C++
helpviewer_keywords:
- CAutoPtrElementTraits class
ms.assetid: 777c1b14-6ab7-491f-b9a5-be149e71d4a2
caps.latest.revision: 20
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
ms.openlocfilehash: 1c543eaa678d86e083207915bcb4f43766ee23c5
ms.lasthandoff: 02/25/2017

---
# <a name="cautoptrelementtraits-class"></a>Classe CAutoPtrElementTraits
Essa classe fornece métodos, funções estáticas e typedefs útil ao criar coleções de ponteiros inteligentes.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<typename T>  
class CAutoPtrElementTraits 
    : public CDefaultElementTraits<ATL::CAutoPtr<T>>
```    
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de ponteiro.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAutoPtrElementTraits::INARGTYPE](#inargtype)|O tipo de dados a ser usado para adicionar elementos para o objeto de classe de coleção.|  
|[CAutoPtrElementTraits::OUTARGTYPE](#outargtype)|O tipo de dados a ser usado para recuperar os elementos do objeto de classe de coleção.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece métodos, funções estáticas e definições de tipo para auxílio a criação de objetos de classe de coleção que contém ponteiros inteligentes. As classes [CAutoPtrArray](../../atl/reference/cautoptrarray-class.md) e [CAutoPtrList](../../atl/reference/cautoptrlist-class.md) derivam de `CAutoPtrElementTraits`. Se criar uma coleção de ponteiros inteligentes que requer novo vetor e operadores de exclusão, use [CAutoVectorPtrElementTraits](../../atl/reference/cautovectorptrelementtraits-class.md) em vez disso.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CDefaultCompareTraits](../../atl/reference/cdefaultcomparetraits-class.md)  
  
 [CDefaultHashTraits](../../atl/reference/cdefaulthashtraits-class.md)  
  
 [CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)  
  
 [CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)  
  
 `CAutoPtrElementTraits`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcoll.h  
  
##  <a name="a-nameinargtypea--cautoptrelementtraitsinargtype"></a><a name="inargtype"></a>CAutoPtrElementTraits::INARGTYPE  
 O tipo de dados a ser usado para adicionar elementos para o objeto de classe de coleção.  
  
```
typedef CAutoPtr<T>& INARGTYPE;
```  
  
##  <a name="a-nameoutargtypea--cautoptrelementtraitsoutargtype"></a><a name="outargtype"></a>CAutoPtrElementTraits::OUTARGTYPE  
 O tipo de dados a ser usado para recuperar os elementos do objeto de classe de coleção.  
  
```
typedef T *& OUTARGTYPE;
```  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

