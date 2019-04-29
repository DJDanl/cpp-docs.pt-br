---
title: Classe CAutoVectorPtrElementTraits
ms.date: 11/04/2016
f1_keywords:
- CAutoVectorPtrElementTraits
- ATLCOLL/ATL::CAutoVectorPtrElementTraits
- ATLCOLL/ATL::CAutoVectorPtrElementTraits::INARGTYPE
- ATLCOLL/ATL::CAutoVectorPtrElementTraits::OUTARGTYPE
helpviewer_keywords:
- CAutoVectorPtrElementTraits class
ms.assetid: 16b81a56-55fb-46ca-b376-66a1884231a6
ms.openlocfilehash: 168670709470d7b7fdd77edb3c29d5a9f4049ca3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62260078"
---
# <a name="cautovectorptrelementtraits-class"></a>Classe CAutoVectorPtrElementTraits

Essa classe fornece métodos, funções estáticas e definições de tipo útil durante a criação de coleções de ponteiros inteligentes usando o vetor novo e excluir operadores.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

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
|[CAutoVectorPtrElementTraits::INARGTYPE](#inargtype)|O tipo de dados a ser usado para adicionar elementos ao objeto de classe da coleção.|
|[CAutoVectorPtrElementTraits::OUTARGTYPE](#outargtype)|O tipo de dados a ser usado para recuperar os elementos do objeto de classe da coleção.|

## <a name="remarks"></a>Comentários

Essa classe fornece métodos, funções estáticas e definições de tipo para auxiliar a criação de objetos de classe de coleção que contém ponteiros inteligentes. Diferentemente [CAutoPtrElementTraits](../../atl/reference/cautoptrelementtraits-class.md), essa classe usa vetor novo e excluir operadores.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CDefaultCompareTraits](../../atl/reference/cdefaultcomparetraits-class.md)

[CDefaultHashTraits](../../atl/reference/cdefaulthashtraits-class.md)

[CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)

[CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)

`CAutoVectorPtrElementTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

##  <a name="inargtype"></a>  CAutoVectorPtrElementTraits::INARGTYPE

O tipo de dados a ser usado para adicionar elementos ao objeto de classe da coleção.

```
typedef CAutoVectorPtr<T>& INARGTYPE;
```

##  <a name="outargtype"></a>  CAutoVectorPtrElementTraits::OUTARGTYPE

O tipo de dados a ser usado para recuperar os elementos do objeto de classe da coleção.

```
typedef T*& OUTARGTYPE;
```

## <a name="see-also"></a>Consulte também

[Classe CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)<br/>
[Classe CAutoVectorPtr](../../atl/reference/cautovectorptr-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
