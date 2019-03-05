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
ms.openlocfilehash: e535afb3a49a5720c8394cc1ab9186c360527fea
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57257274"
---
# <a name="cheapptrelementtraits-class"></a>Classe CHeapPtrElementTraits

Essa classe fornece métodos, funções estáticas e definições de tipo útil durante a criação de coleções de ponteiros de pilha.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<typename T, class Allocator = ATL::CCRTAllocator>
class CHeapPtrElementTraits :
   public CDefaultElementTraits<ATL::CHeapPtr<T, Allocator>>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de objeto a ser armazenado na classe da coleção.

*Allocator*<br/>
A classe de alocação de memória para usar. O padrão é [CCRTAllocator](../../atl/reference/ccrtallocator-class.md).

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CHeapPtrElementTraits::INARGTYPE](#inargtype)|O tipo de dados a ser usado para adicionar elementos ao objeto de classe da coleção.|
|[CHeapPtrElementTraits::OUTARGTYPE](#outargtype)|O tipo de dados a ser usado para recuperar os elementos do objeto de classe da coleção.|

## <a name="remarks"></a>Comentários

Essa classe fornece métodos, funções estáticas e definições de tipo para auxiliar a criação de objetos de classe de coleção que contém ponteiros de pilha. A classe `CHeapPtrList` deriva `CHeapPtrElementTraits`.

Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CDefaultCompareTraits](../../atl/reference/cdefaultcomparetraits-class.md)

[CDefaultHashTraits](../../atl/reference/cdefaulthashtraits-class.md)

[CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)

[CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)

`CHeapPtrElementTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

##  <a name="inargtype"></a>  CHeapPtrElementTraits::INARGTYPE

O tipo de dados a ser usado para adicionar elementos ao objeto de classe da coleção.

```
typedef CHeapPtr<T, Allocator>& INARGTYPE;
```

##  <a name="outargtype"></a>  CHeapPtrElementTraits::OUTARGTYPE

O tipo de dados a ser usado para recuperar os elementos do objeto de classe da coleção.

```
typedef T *& OUTARGTYPE;
```

## <a name="see-also"></a>Consulte também

[Classe CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)<br/>
[Classe CComHeapPtr](../../atl/reference/ccomheapptr-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
