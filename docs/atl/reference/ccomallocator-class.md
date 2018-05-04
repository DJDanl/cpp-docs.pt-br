---
title: Classe CComAllocator | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3606df325bfd41dabf99bb790ff154b383ab987f
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="ccomallocator-class"></a>Classe CComAllocator
Essa classe fornece métodos para o gerenciamento de memória usando COM rotinas de memória.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CComAllocator
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComAllocator::Allocate](#allocate)|Chame este método estático para alocar memória.|  
|[CComAllocator::Free](#free)|Chame este método estático para liberar a memória alocada.|  
|[CComAllocator::Reallocate](#reallocate)|Chame este método estático para realocar a memória.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe é usada por [CComHeapPtr](../../atl/reference/ccomheapptr-class.md) para fornecer a memória COM as rotinas de alocação. A classe correspondente, [CCRTAllocator](../../atl/reference/ccrtallocator-class.md), fornece os mesmos métodos usando rotinas do CRT.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  
  
##  <a name="allocate"></a>  CComAllocator::Allocate  
 Chame a função estática para alocar memória.  
  
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
  
##  <a name="free"></a>  CComAllocator::Free  
 Chame a função estática para liberar a memória alocada.  
  
```
static void Free(void* p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 Ponteiro para a memória alocada.  
  
### <a name="remarks"></a>Comentários  
 Libera a memória alocada. Consulte [CoTaskMemFree](http://msdn.microsoft.com/library/windows/desktop/ms680722) para obter mais detalhes.  
  
##  <a name="reallocate"></a>  CComAllocator::Reallocate  
 Chame a função estática para realocar a memória.  
  
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
