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
ms.openlocfilehash: 2f92ae3f4041b143a8cc4d58b1060c7d5b9a7bb4
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32363441"
---
# <a name="ccrtallocator-class"></a>Classe CCRTAllocator
Essa classe fornece métodos para o gerenciamento de memória usando as rotinas de memória do CRT.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class ATL::CCRTAllocator
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCRTAllocator::Allocate](#allocate)|(Estático) Chame esse método para alocar memória.|  
|[CCRTAllocator::Free](#free)|(Estático) Chame este método para liberar memória.|  
|[CCRTAllocator::Reallocate](#reallocate)|(Estático) Chame este método para realocar a memória.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe é usada por [CHeapPtr](../../atl/reference/cheapptr-class.md) para fornecer a memória de CRT rotinas de alocação. A classe correspondente, [CComAllocator](../../atl/reference/ccomallocator-class.md), fornece os mesmos métodos usando rotinas de COM.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcore.h  
  
##  <a name="allocate"></a>  CCRTAllocator::Allocate  
 Chame a função estática para alocar memória.  
  
```
static __declspec(allocator) void* Allocate(size_t nBytes) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nBytes`  
 O número de bytes para alocar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro nulo para o espaço alocado, ou nulo se não houver memória suficiente disponível.  
  
### <a name="remarks"></a>Comentários  
 Aloca memória. Consulte [malloc](../../c-runtime-library/reference/malloc.md) para obter mais detalhes.  
  
##  <a name="free"></a>  CCRTAllocator::Free  
 Chame a função estática para liberar memória.  
  
```
static void Free(void* p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 Ponteiro para a memória alocada.  
  
### <a name="remarks"></a>Comentários  
 Libera a memória alocada. Consulte [livre](../../c-runtime-library/reference/free.md) para obter mais detalhes.  
  
##  <a name="reallocate"></a>  CCRTAllocator::Reallocate  
 Chame a função estática para realocar a memória.  
  
```
static __declspec(allocator) void* Reallocate(void* p, size_t nBytes) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 Ponteiro para a memória alocada.  
  
 `nBytes`  
 O número de bytes para realocar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro nulo para o espaço alocado, ou nulo se não houver memória suficiente.  
  
### <a name="remarks"></a>Comentários  
 Redimensiona a quantidade de memória alocada. Consulte [realloc](../../c-runtime-library/reference/realloc.md) para obter mais detalhes.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CHeapPtr](../../atl/reference/cheapptr-class.md)   
 [Classe CComAllocator](../../atl/reference/ccomallocator-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
