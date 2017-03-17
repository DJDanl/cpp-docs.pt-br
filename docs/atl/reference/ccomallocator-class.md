---
title: Classe CComAllocator | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComAllocator
- ATLBASE/ATL::CComAllocator
- ATLBASE/ATL::CComAllocator::Allocate
- ATLBASE/ATL::CComAllocator::Free
- ATLBASE/ATL::CComAllocator::Reallocate
dev_langs:
- C++
helpviewer_keywords:
- CComAllocator class
ms.assetid: 0cd706fd-0c7b-42d3-9054-febe2966fc8e
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
ms.openlocfilehash: d395d347e81b24462a41de5ae3b9d8791d7f82fd
ms.lasthandoff: 02/25/2017

---
# <a name="ccomallocator-class"></a>Classe CComAllocator
Essa classe fornece métodos para gerenciamento de memória usando rotinas de memória COM.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CComAllocator
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComAllocator::Allocate](#allocate)|Chame esse método estático para alocar memória.|  
|[CComAllocator::Free](#free)|Chame esse método estático para liberar a memória alocada.|  
|[CComAllocator::Reallocate](#reallocate)|Chame esse método estático para realocar a memória.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe é usada por [CComHeapPtr](../../atl/reference/ccomheapptr-class.md) para fornecer a memória COM rotinas de alocação. A classe equivalente, [CCRTAllocator](../../atl/reference/ccrtallocator-class.md), fornece os mesmos métodos usando rotinas de CRT.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  
  
##  <a name="allocate"></a>CComAllocator::Allocate  
 Chame essa função estática para alocar memória.  
  
```
static void* Allocate(size_t nBytes) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nBytes`  
 O número de bytes para alocar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro nulo para o espaço alocado, ou nulo se não houver memória suficiente disponível.  
  
### <a name="remarks"></a>Comentários  
 Aloca memória. Consulte [CoTaskMemAlloc](http://msdn.microsoft.com/library/windows/desktop/ms692727) para obter mais detalhes.  
  
##  <a name="free"></a>CComAllocator::Free  
 Chame essa função estática para liberar a memória alocada.  
  
```
static void Free(void* p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 Ponteiro para a memória alocada.  
  
### <a name="remarks"></a>Comentários  
 Libera a memória alocada. Consulte [CoTaskMemFree](http://msdn.microsoft.com/library/windows/desktop/ms680722) para obter mais detalhes.  
  
##  <a name="reallocate"></a>CComAllocator::Reallocate  
 Chame essa função estática para realocar a memória.  
  
```
static void* Reallocate(void* p, size_t nBytes) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 Ponteiro para a memória alocada.  
  
 `nBytes`  
 O número de bytes para realocar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro nulo para o espaço alocado, ou nulo se não houver memória insuficiente  
  
### <a name="remarks"></a>Comentários  
 Redimensiona a quantidade de memória alocada. Consulte [CoTaskMemRealloc](http://msdn.microsoft.com/library/windows/desktop/ms687280) para obter mais detalhes.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComHeapPtr](../../atl/reference/ccomheapptr-class.md)   
 [Classe CCRTAllocator](../../atl/reference/ccrtallocator-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

