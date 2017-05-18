---
title: Classe CAutoPtrList | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CAutoPtrList
- ATLCOLL/ATL::CAutoPtrList
- ATLCOLL/ATL::CAutoPtrList::CAutoPtrList
dev_langs:
- C++
helpviewer_keywords:
- CAutoPtrList class
ms.assetid: 11de4aca-28b0-4ff2-a74a-cb602312ffbd
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 5a0c6a1062330f952bb8fa52bc934f6754465513
ms.openlocfilehash: b39c3c08cf2970036bf8690c46a4f3518a7a55e1
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cautoptrlist-class"></a>Classe CAutoPtrList
Essa classe fornece métodos úteis ao construir uma lista de ponteiros inteligentes.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<typename E>  
class CAutoPtrList : 
   public CAtlList<ATL::CAutoPtr<E>, CAutoPtrElementTraits<E>>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `E`  
 O tipo de ponteiro.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAutoPtrList::CAutoPtrList](#cautoptrlist)|O construtor.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece um construtor e deriva de métodos de [CAtlList](../../atl/reference/catllist-class.md) e [CAutoPtrElementTraits](../../atl/reference/cautoptrelementtraits-class.md) para ajudar na criação de um objeto de lista armazenar ponteiros inteligentes. A classe [CAutoPtrArray](../../atl/reference/cautoptrarray-class.md) fornece uma função semelhante para um objeto de matriz.  
  
 Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CAtlList](../../atl/reference/catllist-class.md)  
  
 `CAutoPtrList`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcoll.h  
  
##  <a name="cautoptrlist"></a>CAutoPtrList::CAutoPtrList  
 O construtor.  
  
```
CAutoPtrList(UINT nBlockSize = 10) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nBlockSize`  
 O tamanho do bloco, com um padrão de 10.  
  
### <a name="remarks"></a>Comentários  
 O tamanho do bloco é uma medida da quantidade de memória alocada quando um novo elemento é necessário. Tamanhos maiores de bloco reduzem chamadas para rotinas de alocação de memória, mas usam mais recursos.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CAtlList](../../atl/reference/catllist-class.md)   
 [Classe CAutoPtrElementTraits](../../atl/reference/cautoptrelementtraits-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

