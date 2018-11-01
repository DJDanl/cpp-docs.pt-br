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
ms.openlocfilehash: 4d13ca8e3de00a49e15e5acbc35c6301b9d7eae2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50476512"
---
# <a name="cautoptrelementtraits-class"></a>Classe CAutoPtrElementTraits

Essa classe fornece métodos, funções estáticas e definições de tipo útil durante a criação de coleções de ponteiros inteligentes.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

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
|[CAutoPtrElementTraits::INARGTYPE](#inargtype)|O tipo de dados a ser usado para adicionar elementos ao objeto de classe da coleção.|
|[CAutoPtrElementTraits::OUTARGTYPE](#outargtype)|O tipo de dados a ser usado para recuperar os elementos do objeto de classe da coleção.|

## <a name="remarks"></a>Comentários

Essa classe fornece métodos, funções estáticas e definições de tipo para auxiliar a criação de objetos de classe de coleção que contém ponteiros inteligentes. As classes [CAutoPtrArray](../../atl/reference/cautoptrarray-class.md) e [CAutoPtrList](../../atl/reference/cautoptrlist-class.md) derivam `CAutoPtrElementTraits`. Se a criação de uma coleção de ponteiros inteligentes que requer um vetor novo e operadores de exclusão, use [CAutoVectorPtrElementTraits](../../atl/reference/cautovectorptrelementtraits-class.md) em vez disso.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CDefaultCompareTraits](../../atl/reference/cdefaultcomparetraits-class.md)

[CDefaultHashTraits](../../atl/reference/cdefaulthashtraits-class.md)

[CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)

[CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)

`CAutoPtrElementTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

##  <a name="inargtype"></a>  CAutoPtrElementTraits::INARGTYPE

O tipo de dados a ser usado para adicionar elementos ao objeto de classe da coleção.

```
typedef CAutoPtr<T>& INARGTYPE;
```

##  <a name="outargtype"></a>  CAutoPtrElementTraits::OUTARGTYPE

O tipo de dados a ser usado para recuperar os elementos do objeto de classe da coleção.

```
typedef T *& OUTARGTYPE;
```

## <a name="see-also"></a>Consulte também

[Classe CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
