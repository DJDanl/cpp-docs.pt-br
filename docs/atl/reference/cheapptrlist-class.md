---
title: Classe CHeapPtrList | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CHeapPtrList
- ATLCOLL/ATL::CHeapPtrList
- ATLCOLL/ATL::CHeapPtrList::CHeapPtrList
dev_langs:
- C++
helpviewer_keywords:
- CHeapPtrList class
ms.assetid: cc70e585-362a-4007-81db-c705eb181226
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
ms.openlocfilehash: 9acf18d0e0a72f27a335cefca81341c95d530ae5
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cheapptrlist-class"></a>Classe CHeapPtrList
Essa classe fornece métodos úteis ao construir uma lista dos ponteiros de pilha.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<typename E, class Allocator = ATL::CCRTAllocator>  
class CHeapPtrList 
   : public CAtlList<ATL::CHeapPtr<E, Allocator>,
                     CHeapPtrElementTraits<E, Allocator>>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `E`  
 O tipo de objeto a ser armazenado na classe da coleção.  
  
 `Allocator`  
 A classe de alocação de memória para usar. O padrão é [CCRTAllocator](../../atl/reference/ccrtallocator-class.md).  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHeapPtrList::CHeapPtrList](#cheapptrlist)|O construtor.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece um construtor e deriva de métodos de [CAtlList](../../atl/reference/catllist-class.md) e [CHeapPtrElementTraits](../../atl/reference/cheapptrelementtraits-class.md) para ajudar na criação de um objeto de classe de coleção armazenar ponteiros de pilha.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CAtlList](../../atl/reference/catllist-class.md)  
  
 `CHeapPtrList`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcoll.h  
  
##  <a name="cheapptrlist"></a>CHeapPtrList::CHeapPtrList  
 O construtor.  
  
```
CHeapPtrList(UINT nBlockSize = 10) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nBlockSize`  
 O tamanho do bloco.  
  
### <a name="remarks"></a>Comentários  
 O tamanho do bloco é uma medida da quantidade de memória alocada quando um novo elemento é necessário. Tamanhos maiores de bloco reduzem chamadas para rotinas de alocação de memória, mas usam mais recursos.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CAtlList](../../atl/reference/catllist-class.md)   
 [Classe CHeapPtr](../../atl/reference/cheapptr-class.md)   
 [Classe CHeapPtrElementTraits](../../atl/reference/cheapptrelementtraits-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

