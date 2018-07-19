---
title: Classe CCRTAllocator | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CCRTAllocator
- ATLCORE/ATL::CCRTAllocator
- ATLCORE/ATL::CCRTAllocator::Allocate
- ATLCORE/ATL::CCRTAllocator::Free
- ATLCORE/ATL::CCRTAllocator::Reallocate
dev_langs:
- C++
helpviewer_keywords:
- CCRTAllocator class
ms.assetid: 3e1b8cb0-859a-41ab-8e93-6f0b5ceca49d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3f026610469c75f37e49df6f42358a3ff378cb0e
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37879579"
---
# <a name="ccrtallocator-class"></a>Classe CCRTAllocator
Essa classe fornece métodos para gerenciamento de memória usando rotinas de memória do CRT.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class ATL::CCRTAllocator
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCRTAllocator::Allocate](#allocate)|(Estático) Chame esse método para alocar memória.|  
|[CCRTAllocator::Free](#free)|(Estático) Chame esse método para liberar memória.|  
|[CCRTAllocator::Reallocate](#reallocate)|(Estático) Chame esse método para realocar a memória.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe é usada pelo [CHeapPtr](../../atl/reference/cheapptr-class.md) para fornecer rotinas de alocação de memória CRT. A classe de contraparte [CComAllocator](../../atl/reference/ccomallocator-class.md), fornece os mesmos métodos usando rotinas de COM.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcore.h  
  
##  <a name="allocate"></a>  CCRTAllocator::Allocate  
 Chame essa função estática para alocar memória.  
  
```
static __declspec(allocator) void* Allocate(size_t nBytes) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *nBytes*  
 O número de bytes para alocar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro nulo para o espaço alocado ou nulo se não houver memória suficiente disponível.  
  
### <a name="remarks"></a>Comentários  
 Aloca memória. Ver [malloc](../../c-runtime-library/reference/malloc.md) para obter mais detalhes.  
  
##  <a name="free"></a>  CCRTAllocator::Free  
 Chame essa função estática para liberar memória.  
  
```
static void Free(void* p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *p*  
 Ponteiro para a memória alocada.  
  
### <a name="remarks"></a>Comentários  
 Libera a memória alocada. Ver [livre](../../c-runtime-library/reference/free.md) para obter mais detalhes.  
  
##  <a name="reallocate"></a>  CCRTAllocator::Reallocate  
 Chame essa função estática para realocar a memória.  
  
```
static __declspec(allocator) void* Reallocate(void* p, size_t nBytes) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *p*  
 Ponteiro para a memória alocada.  
  
 *nBytes*  
 O número de bytes para realocar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro nulo para o espaço alocado ou nulo se não houver memória insuficiente.  
  
### <a name="remarks"></a>Comentários  
 Redimensiona a quantidade de memória alocada. Ver [realloc](../../c-runtime-library/reference/realloc.md) para obter mais detalhes.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CHeapPtr](../../atl/reference/cheapptr-class.md)   
 [Classe CComAllocator](../../atl/reference/ccomallocator-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
