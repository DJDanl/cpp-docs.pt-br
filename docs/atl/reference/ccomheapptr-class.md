---
title: Classe CComHeapPtr
ms.date: 11/04/2016
f1_keywords:
- CComHeapPtr
- ATLBASE/ATL::CComHeapPtr
- ATLBASE/ATL::CComHeapPtr::CComHeapPtr
helpviewer_keywords:
- CComHeapPtr class
ms.assetid: bd08b53d-da2b-43ab-a79c-e7c8dbbc5994
ms.openlocfilehash: eaa21700f63ae07565dba4b8b3b5dabac69e0168
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50553721"
---
# <a name="ccomheapptr-class"></a>Classe CComHeapPtr

Uma classe de ponteiro inteligente para gerenciar os ponteiros de pilha.

## <a name="syntax"></a>Sintaxe

```
template<typename T>
class CComHeapPtr : public CHeapPtr<T, CComAllocator>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
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

*pData*<br/>
Um objeto `CComHeapPtr` existente.

### <a name="remarks"></a>Comentários

O ponteiro do heap, opcionalmente, pode ser criado usando uma existente `CComHeapPtr` objeto. Nesse caso, o novo `CComHeapPtr` objeto assume a responsabilidade por gerenciar o novo ponteiro e recursos.

## <a name="see-also"></a>Consulte também

[Classe CHeapPtr](../../atl/reference/cheapptr-class.md)<br/>
[Classe CHeapPtrBase](../../atl/reference/cheapptrbase-class.md)<br/>
[Classe CComAllocator](../../atl/reference/ccomallocator-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
