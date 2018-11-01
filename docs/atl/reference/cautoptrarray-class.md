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
ms.openlocfilehash: c7a2a7e9592b120204582334f69e27e72cd7364f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50677936"
---
# <a name="cautoptrarray-class"></a>Classe CAutoPtrArray

Essa classe fornece métodos úteis ao construir uma matriz de ponteiros inteligentes.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

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

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoPtrArray::CAutoPtrArray](#cautoptrarray)|O construtor.|

## <a name="remarks"></a>Comentários

Essa classe fornece um construtor e deriva de métodos de [CAtlArray](../../atl/reference/catlarray-class.md) e [CAutoPtrElementTraits](../../atl/reference/cautoptrelementtraits-class.md) para ajudar na criação de um objeto de classe de coleção armazenar ponteiros inteligentes.

Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CAtlArray`

`CAutoPtrArray`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

##  <a name="cautoptrarray"></a>  CAutoPtrArray::CAutoPtrArray

O construtor.

```
CAutoPtrArray() throw();
```

### <a name="remarks"></a>Comentários

Inicializa a matriz de ponteiro inteligente.

## <a name="see-also"></a>Consulte também

[Classe CAtlArray](../../atl/reference/catlarray-class.md)<br/>
[Classe CAutoPtrElementTraits](../../atl/reference/cautoptrelementtraits-class.md)<br/>
[Classe CAutoPtrList](../../atl/reference/cautoptrlist-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
