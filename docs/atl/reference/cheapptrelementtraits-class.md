---
title: Classe CHeapPtrElementTraits
ms.date: 11/04/2016
f1_keywords:
- CHeapPtrElementTraits
- ATLCOLL/ATL::CHeapPtrElementTraits
- ATLCOLL/ATL::CHeapPtrElementTraits::INARGTYPE
- ATLCOLL/ATL::CHeapPtrElementTraits::OUTARGTYPE
helpviewer_keywords:
- CHeapPtrElementTraits class
ms.assetid: 910e0e06-3c8b-4242-bf00-b57eb74fbc77
ms.openlocfilehash: f09da968b264463eba759372e4e0756397e9978e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326871"
---
# <a name="cheapptrelementtraits-class"></a>Classe CHeapPtrElementTraits

Esta classe fornece métodos, funções estáticas e tipos úteis ao criar coleções de ponteiros de pilha.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<typename T, class Allocator = ATL::CCRTAllocator>
class CHeapPtrElementTraits :
   public CDefaultElementTraits<ATL::CHeapPtr<T, Allocator>>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de objeto a ser armazenado na classe de coleta.

*Alocador*<br/>
A classe de alocação de memória para usar. O padrão é [CCRTAllocator](../../atl/reference/ccrtallocator-class.md).

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CHeapPtrElementTraits::INARGTYPE](#inargtype)|O tipo de dados a ser usado para adicionar elementos ao objeto da classe de coleta.|
|[CHeapPtrElementTraits::OUTARGTYPE](#outargtype)|O tipo de dados a ser usado para recuperar elementos do objeto da classe de coleta.|

## <a name="remarks"></a>Comentários

Esta classe fornece métodos, funções estáticas e tipos para ajudar na criação de objetos de classe de coleta contendo ponteiros de pilha. A `CHeapPtrList` classe deriva `CHeapPtrElementTraits`de .

Para obter mais informações, consulte [ATL Collection Classes](../../atl/atl-collection-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cdefaultcomparetraits](../../atl/reference/cdefaultcomparetraits-class.md)

[Cdefaulthashtraits](../../atl/reference/cdefaulthashtraits-class.md)

[Celementtraitsbase](../../atl/reference/celementtraitsbase-class.md)

[CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)

`CHeapPtrElementTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

## <a name="cheapptrelementtraitsinargtype"></a><a name="inargtype"></a>CHeapPtrElementTraits::INARGTYPE

O tipo de dados a ser usado para adicionar elementos ao objeto da classe de coleta.

```
typedef CHeapPtr<T, Allocator>& INARGTYPE;
```

## <a name="cheapptrelementtraitsoutargtype"></a><a name="outargtype"></a>CHeapPtrElementTraits::OUTARGTYPE

O tipo de dados a ser usado para recuperar elementos do objeto da classe de coleta.

```
typedef T *& OUTARGTYPE;
```

## <a name="see-also"></a>Confira também

[Classe CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)<br/>
[Classe CComHeapPtr](../../atl/reference/ccomheapptr-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
