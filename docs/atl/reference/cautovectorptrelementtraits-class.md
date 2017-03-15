---
title: Classe CAutoVectorPtrElementTraits | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CAutoVectorPtrElementTraits<T>
- ATL.CAutoVectorPtrElementTraits
- ATL.CAutoVectorPtrElementTraits<T>
- ATL::CAutoVectorPtrElementTraits
- CAutoVectorPtrElementTraits
dev_langs:
- C++
helpviewer_keywords:
- CAutoVectorPtrElementTraits class
ms.assetid: 16b81a56-55fb-46ca-b376-66a1884231a6
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
translationtype: Machine Translation
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: d7b7418b713993f539f56e70715296d5af265d28
ms.lasthandoff: 02/25/2017

---
# <a name="cautovectorptrelementtraits-class"></a>Classe CAutoVectorPtrElementTraits
Essa classe fornece métodos, funções estáticas e typedefs útil ao criar coleções de ponteiros inteligentes usando o vetor novo e excluir operadores.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <typename T>  
class CAutoVectorPtrElementTraits : 
   public CDefaultElementTraits<ATL::CAutoVectorPtr<T>>
```    
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de ponteiro.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAutoVectorPtrElementTraits::INARGTYPE](#inargtype)|O tipo de dados a ser usado para adicionar elementos para o objeto de classe de coleção.|  
|[CAutoVectorPtrElementTraits::OUTARGTYPE](#outargtype)|O tipo de dados a ser usado para recuperar os elementos do objeto de classe de coleção.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece métodos, funções estáticas e definições de tipo para auxílio a criação de objetos de classe de coleção que contém ponteiros inteligentes. Ao contrário de [CAutoPtrElementTraits](../../atl/reference/cautoptrelementtraits-class.md), esse usa classe vector novos e excluir operadores.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CDefaultCompareTraits](../../atl/reference/cdefaultcomparetraits-class.md)  
  
 [CDefaultHashTraits](../../atl/reference/cdefaulthashtraits-class.md)  
  
 [CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)  
  
 [CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)  
  
 `CAutoVectorPtrElementTraits`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcoll.h  
  
##  <a name="a-nameinargtypea--cautovectorptrelementtraitsinargtype"></a><a name="inargtype"></a>CAutoVectorPtrElementTraits::INARGTYPE  
 O tipo de dados a ser usado para adicionar elementos para o objeto de classe de coleção.  
  
```
typedef CAutoVectorPtr<T>& INARGTYPE;
```  
  
##  <a name="a-nameoutargtypea--cautovectorptrelementtraitsoutargtype"></a><a name="outargtype"></a>CAutoVectorPtrElementTraits::OUTARGTYPE  
 O tipo de dados a ser usado para recuperar os elementos do objeto de classe de coleção.  
  
```
typedef T*& OUTARGTYPE;
```  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)   
 [Classe CAutoVectorPtr](../../atl/reference/cautovectorptr-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

