---
title: Classe CComHeapPtr | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CComHeapPtr
- ATLBASE/ATL::CComHeapPtr
- ATLBASE/ATL::CComHeapPtr::CComHeapPtr
dev_langs:
- C++
helpviewer_keywords:
- CComHeapPtr class
ms.assetid: bd08b53d-da2b-43ab-a79c-e7c8dbbc5994
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c3cc64804dbd628669b31de070b0f30aa92a77a3
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37884776"
---
# <a name="ccomheapptr-class"></a>Classe CComHeapPtr
Uma classe de ponteiro inteligente para gerenciar os ponteiros de pilha.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<typename T>  
class CComHeapPtr : public CHeapPtr<T, CComAllocator>
```  
  
#### <a name="parameters"></a>Parâmetros  
 *T*  
 O tipo de objeto a ser armazenado no heap.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComHeapPtr::CComHeapPtr](#ccomheapptr)|O construtor.|  
  
## <a name="remarks"></a>Comentários  
 `CComHeapPtr` deriva `CHeapPtr`, mas usa [CComAllocator](../../atl/reference/ccomallocator-class.md) para alocar memória usando as rotinas de COM. Ver [CHeapPtr](../../atl/reference/cheapptr-class.md) e [CHeapPtrBase](../../atl/reference/cheapptrbase-class.md) para os métodos disponíveis.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CHeapPtrBase](../../atl/reference/cheapptrbase-class.md)  
  
 [CHeapPtr](../../atl/reference/cheapptr-class.md)  
  
 `CComHeapPtr`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  
  
##  <a name="ccomheapptr"></a>  CComHeapPtr::CComHeapPtr  
 O construtor.  
  
```
CComHeapPtr() throw();
explicit CComHeapPtr(T* pData) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *pData*  
 Um objeto `CComHeapPtr` existente.  
  
### <a name="remarks"></a>Comentários  
 O ponteiro do heap, opcionalmente, pode ser criado usando uma existente `CComHeapPtr` objeto. Nesse caso, o novo `CComHeapPtr` objeto assume a responsabilidade por gerenciar o novo ponteiro e recursos.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CHeapPtr](../../atl/reference/cheapptr-class.md)   
 [Classe CHeapPtrBase](../../atl/reference/cheapptrbase-class.md)   
 [Classe CComAllocator](../../atl/reference/ccomallocator-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
