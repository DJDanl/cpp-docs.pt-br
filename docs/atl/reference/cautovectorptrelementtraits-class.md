---
title: CAutoVectorPtrElementTraits Class
ms.date: 11/04/2016
f1_keywords:
- CAutoVectorPtrElementTraits
- ATLCOLL/ATL::CAutoVectorPtrElementTraits
- ATLCOLL/ATL::CAutoVectorPtrElementTraits::INARGTYPE
- ATLCOLL/ATL::CAutoVectorPtrElementTraits::OUTARGTYPE
helpviewer_keywords:
- CAutoVectorPtrElementTraits class
ms.assetid: 16b81a56-55fb-46ca-b376-66a1884231a6
ms.openlocfilehash: 956fe39c4d3ba89bb9def2f996dca59905753edb
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318749"
---
# <a name="cautovectorptrelementtraits-class"></a>CAutoVectorPtrElementTraits Class

Esta classe fornece métodos, funções estáticas e tipos úteis ao criar coleções de ponteiros inteligentes usando novos vetoriais e excluir operadores.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <typename T>
class CAutoVectorPtrElementTraits :
   public CDefaultElementTraits<ATL::CAutoVectorPtr<T>>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de ponteiro.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoVectorPtrElementTraits::INARGTYPE](#inargtype)|O tipo de dados a ser usado para adicionar elementos ao objeto da classe de coleta.|
|[CAutoVectorPtrElementTraits::OUTARGTYPE](#outargtype)|O tipo de dados a ser usado para recuperar elementos do objeto da classe de coleta.|

## <a name="remarks"></a>Comentários

Esta classe fornece métodos, funções estáticas e tipos para ajudar na criação de objetos de classe de coleta contendo ponteiros inteligentes. Ao contrário [do CAutoPtrElementTraits,](../../atl/reference/cautoptrelementtraits-class.md)esta classe usa operadores vetoriais novos e excluem.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cdefaultcomparetraits](../../atl/reference/cdefaultcomparetraits-class.md)

[Cdefaulthashtraits](../../atl/reference/cdefaulthashtraits-class.md)

[Celementtraitsbase](../../atl/reference/celementtraitsbase-class.md)

[CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)

`CAutoVectorPtrElementTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

## <a name="cautovectorptrelementtraitsinargtype"></a><a name="inargtype"></a>CAutoVectorPtrElementTraits::INARGTYPE

O tipo de dados a ser usado para adicionar elementos ao objeto da classe de coleta.

```
typedef CAutoVectorPtr<T>& INARGTYPE;
```

## <a name="cautovectorptrelementtraitsoutargtype"></a><a name="outargtype"></a>CAutoVectorPtrElementTraits::OUTARGTYPE

O tipo de dados a ser usado para recuperar elementos do objeto da classe de coleta.

```
typedef T*& OUTARGTYPE;
```

## <a name="see-also"></a>Confira também

[Classe CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)<br/>
[Classe CAutoVectorPtr](../../atl/reference/cautovectorptr-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
