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
ms.openlocfilehash: 78cadfff9a278cf080393ab919f3891b201c91aa
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327770"
---
# <a name="ccomheapptr-class"></a>Classe CComHeapPtr

Uma classe de ponteiro inteligente para gerenciar ponteiros de pilha.

## <a name="syntax"></a>Sintaxe

```
template<typename T>
class CComHeapPtr : public CHeapPtr<T, CComAllocator>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de objeto a ser armazenado no heap.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComHeapPtr::CComHeapPtr](#ccomheapptr)|O construtor.|

## <a name="remarks"></a>Comentários

`CComHeapPtr`deriva de `CHeapPtr`, mas usa [CComAllocator](../../atl/reference/ccomallocator-class.md) para alocar memória usando rotinas COM. Consulte [CHeapPtr](../../atl/reference/cheapptr-class.md) e [CHeapPtrBase](../../atl/reference/cheapptrbase-class.md) para ver os métodos disponíveis.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cheapptrbase](../../atl/reference/cheapptrbase-class.md)

[Cheapptr](../../atl/reference/cheapptr-class.md)

`CComHeapPtr`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="ccomheapptrccomheapptr"></a><a name="ccomheapptr"></a>CComHeapPtr::CComHeapPtr

O construtor.

```
CComHeapPtr() throw();
explicit CComHeapPtr(T* pData) throw();
```

### <a name="parameters"></a>Parâmetros

*Pdata*<br/>
Um objeto `CComHeapPtr` existente.

### <a name="remarks"></a>Comentários

O ponteiro de pilha pode ser criado `CComHeapPtr` opcionalmente usando um objeto existente. Nesse caso, o `CComHeapPtr` novo objeto assume a responsabilidade de gerenciar o novo ponteiro e os recursos.

## <a name="see-also"></a>Confira também

[Classe CHeapPtr](../../atl/reference/cheapptr-class.md)<br/>
[Classe CHeapptrBase](../../atl/reference/cheapptrbase-class.md)<br/>
[Classe CComAllocator](../../atl/reference/ccomallocator-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
