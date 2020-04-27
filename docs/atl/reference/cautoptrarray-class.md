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
ms.openlocfilehash: 11f39eac8b8d080fd840f6454f393e33ebcb9e1c
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82167652"
---
# <a name="cautoptrarray-class"></a>Classe CAutoPtrArray

Essa classe fornece métodos úteis ao construir uma matriz de ponteiros inteligentes.

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename E>
class CAutoPtrArray : public CAtlArray<
                        ATL::CAutoPtr<E>,
                        CAutoPtrElementTraits<E>>
```

### <a name="parameters"></a>Parâmetros

*Oriental*<br/>
O tipo de ponteiro.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoPtrArray::CAutoPtrArray](#cautoptrarray)|O construtor.|

## <a name="remarks"></a>Comentários

Essa classe fornece um construtor e deriva métodos de [CAtlArray](../../atl/reference/catlarray-class.md) e [CAutoPtrElementTraits](../../atl/reference/cautoptrelementtraits-class.md) para auxiliar na criação de um objeto de classe de coleção que armazena ponteiros inteligentes.

Para obter mais informações, consulte [classes de coleção do ATL](../../atl/atl-collection-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CAtlArray`

`CAutoPtrArray`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll. h

## <a name="cautoptrarraycautoptrarray"></a><a name="cautoptrarray"></a>CAutoPtrArray::CAutoPtrArray

O construtor.

```cpp
CAutoPtrArray() throw();
```

### <a name="remarks"></a>Comentários

Inicializa a matriz de ponteiro inteligente.

## <a name="see-also"></a>Confira também

[Classe CAtlArray](../../atl/reference/catlarray-class.md)<br/>
[Classe CAutoPtrElementTraits](../../atl/reference/cautoptrelementtraits-class.md)<br/>
[Classe CAutoPtrList](../../atl/reference/cautoptrlist-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
