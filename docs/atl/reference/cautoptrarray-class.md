---
title: Classe CAutoPtrArray
ms.date: 11/04/2016
f1_keywords:
- CAutoPtrArray
- ATLCOLL/ATL::CAutoPtrArray
- ATLCOLL/ATL::CAutoPtrArray::CAutoPtrArray
helpviewer_keywords:
- CAutoPtrArray class
ms.assetid: 880a70da-8c81-4427-8ac6-49aa8d424244
ms.openlocfilehash: 93fc5cfea4ea655e57e785ca234df59fe10d6570
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318894"
---
# <a name="cautoptrarray-class"></a>Classe CAutoPtrArray

Esta classe fornece métodos úteis ao construir uma matriz de ponteiros inteligentes.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <typename E>
class CAutoPtrArray : public CAtlArray<
                        ATL::CAutoPtr<E>,
                        CAutoPtrElementTraits<E>>
```

#### <a name="parameters"></a>Parâmetros

*E*<br/>
O tipo de ponteiro.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoPtrArray::CAutoPtrArray](#cautoptrarray)|O construtor.|

## <a name="remarks"></a>Comentários

Esta classe fornece um construtor e deriva métodos do [CAtlArray](../../atl/reference/catlarray-class.md) e [cAutoPtrElementTraits](../../atl/reference/cautoptrelementtraits-class.md) para ajudar a criação de um objeto de classe de coleção armazenando ponteiros inteligentes.

Para obter mais informações, consulte [ATL Collection Classes](../../atl/atl-collection-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CAtlArray`

`CAutoPtrArray`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

## <a name="cautoptrarraycautoptrarray"></a><a name="cautoptrarray"></a>CAutoPtrArray::CAutoPtrArray

O construtor.

```
CAutoPtrArray() throw();
```

### <a name="remarks"></a>Comentários

Inicializa a matriz de ponteiros inteligentes.

## <a name="see-also"></a>Confira também

[Classe CAtlArray](../../atl/reference/catlarray-class.md)<br/>
[Classe CAutoPtrElementTraits](../../atl/reference/cautoptrelementtraits-class.md)<br/>
[Classe CAutoPtrList](../../atl/reference/cautoptrlist-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
