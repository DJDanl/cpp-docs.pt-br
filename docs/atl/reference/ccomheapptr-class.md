---
title: Classe CComHeapPtr | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CComHeapPtr
- ATL.CComHeapPtr<T>
- ATL::CComHeapPtr<T>
- CComHeapPtr
- ATL.CComHeapPtr
dev_langs:
- C++
helpviewer_keywords:
- CComHeapPtr class
ms.assetid: bd08b53d-da2b-43ab-a79c-e7c8dbbc5994
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
ms.sourcegitcommit: 5a0c6a1062330f952bb8fa52bc934f6754465513
ms.openlocfilehash: 0e5196a98b8fd76b2e7e791fd2cd9549099a1cc9
ms.lasthandoff: 02/25/2017

---
# <a name="ccomheapptr-class"></a>Classe CComHeapPtr
Uma classe de ponteiro inteligente para gerenciar os ponteiros de pilha.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<typename T>  
class CComHeapPtr : public CHeapPtr<T, CComAllocator>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de objeto a ser armazenado no heap.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComHeapPtr::CComHeapPtr](#ccomheapptr)|O construtor.|  
  
## <a name="remarks"></a>Comentários  
 `CComHeapPtr`deriva de `CHeapPtr`, mas usa [CComAllocator](../../atl/reference/ccomallocator-class.md) para alocar memória usando rotinas de COM. Consulte [CHeapPtr](../../atl/reference/cheapptr-class.md) e [CHeapPtrBase](../../atl/reference/cheapptrbase-class.md) para os métodos disponíveis.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CHeapPtrBase](../../atl/reference/cheapptrbase-class.md)  
  
 [CHeapPtr](../../atl/reference/cheapptr-class.md)  
  
 `CComHeapPtr`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  
  
##  <a name="a-nameccomheapptra--ccomheapptrccomheapptr"></a><a name="ccomheapptr"></a>CComHeapPtr::CComHeapPtr  
 O construtor.  
  
```
CComHeapPtr() throw();
explicit CComHeapPtr(T* pData) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pData`  
 Um objeto `CComHeapPtr` existente.  
  
### <a name="remarks"></a>Comentários  
 O ponteiro de pilha, opcionalmente, pode ser criado usando uma existente `CComHeapPtr` objeto. Nesse caso, o novo `CComHeapPtr` objeto assume a responsabilidade de gerenciar o novo ponteiro e recursos.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CHeapPtr](../../atl/reference/cheapptr-class.md)   
 [Classe CHeapPtrBase](../../atl/reference/cheapptrbase-class.md)   
 [Classe CComAllocator](../../atl/reference/ccomallocator-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

