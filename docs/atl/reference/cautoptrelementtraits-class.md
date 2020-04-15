---
title: Classe CAutoPtrElementTraits
ms.date: 11/04/2016
f1_keywords:
- CAutoPtrElementTraits
- ATLCOLL/ATL::CAutoPtrElementTraits
- ATLCOLL/ATL::CAutoPtrElementTraits::INARGTYPE
- ATLCOLL/ATL::CAutoPtrElementTraits::OUTARGTYPE
helpviewer_keywords:
- CAutoPtrElementTraits class
ms.assetid: 777c1b14-6ab7-491f-b9a5-be149e71d4a2
ms.openlocfilehash: ac29116dc9beedf587c42cc0e52f8c9dbaf3d782
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318886"
---
# <a name="cautoptrelementtraits-class"></a>Classe CAutoPtrElementTraits

Esta classe fornece métodos, funções estáticas e tipos úteis ao criar coleções de ponteiros inteligentes.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<typename T>
class CAutoPtrElementTraits
    : public CDefaultElementTraits<ATL::CAutoPtr<T>>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de ponteiro.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoPtrElementTraits::INARGTYPE](#inargtype)|O tipo de dados a ser usado para adicionar elementos ao objeto da classe de coleta.|
|[CAutoPtrElementTraits::OUTARGTYPE](#outargtype)|O tipo de dados a ser usado para recuperar elementos do objeto da classe de coleta.|

## <a name="remarks"></a>Comentários

Esta classe fornece métodos, funções estáticas e tipos para ajudar na criação de objetos de classe de coleta contendo ponteiros inteligentes. As classes [CAutoPtrArray](../../atl/reference/cautoptrarray-class.md) e [CAutoPtrList](../../atl/reference/cautoptrlist-class.md) derivam de `CAutoPtrElementTraits`. Se construir uma coleção de ponteiros inteligentes que exijam novos vetoriais e excluir operadores, use [CAutoVectorPtrElementTraits.](../../atl/reference/cautovectorptrelementtraits-class.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cdefaultcomparetraits](../../atl/reference/cdefaultcomparetraits-class.md)

[Cdefaulthashtraits](../../atl/reference/cdefaulthashtraits-class.md)

[Celementtraitsbase](../../atl/reference/celementtraitsbase-class.md)

[CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)

`CAutoPtrElementTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

## <a name="cautoptrelementtraitsinargtype"></a><a name="inargtype"></a>CAutoPtrElementTraits::INARGTYPE

O tipo de dados a ser usado para adicionar elementos ao objeto da classe de coleta.

```
typedef CAutoPtr<T>& INARGTYPE;
```

## <a name="cautoptrelementtraitsoutargtype"></a><a name="outargtype"></a>CAutoPtrElementTraits::OUTARGTYPE

O tipo de dados a ser usado para recuperar elementos do objeto da classe de coleta.

```
typedef T *& OUTARGTYPE;
```

## <a name="see-also"></a>Confira também

[Classe CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
