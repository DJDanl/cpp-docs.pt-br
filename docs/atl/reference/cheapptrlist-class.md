---
title: Classe CHeapPtrList
ms.date: 11/04/2016
f1_keywords:
- CHeapPtrList
- ATLCOLL/ATL::CHeapPtrList
- ATLCOLL/ATL::CHeapPtrList::CHeapPtrList
helpviewer_keywords:
- CHeapPtrList class
ms.assetid: cc70e585-362a-4007-81db-c705eb181226
ms.openlocfilehash: ef0224ccb9e2592daecb94204db5e1a8c785c7b7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50676974"
---
# <a name="cheapptrlist-class"></a>Classe CHeapPtrList

Essa classe fornece métodos úteis ao construir uma lista de ponteiros de pilha.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<typename E, class Allocator = ATL::CCRTAllocator>
class CHeapPtrList
   : public CAtlList<ATL::CHeapPtr<E, Allocator>,
                     CHeapPtrElementTraits<E, Allocator>>
```

#### <a name="parameters"></a>Parâmetros

*E*<br/>
O tipo de objeto a ser armazenado na classe da coleção.

*Alocador*<br/>
A classe de alocação de memória para usar. O padrão é [CCRTAllocator](../../atl/reference/ccrtallocator-class.md).

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CHeapPtrList::CHeapPtrList](#cheapptrlist)|O construtor.|

## <a name="remarks"></a>Comentários

Essa classe fornece um construtor e deriva de métodos de [CAtlList](../../atl/reference/catllist-class.md) e [CHeapPtrElementTraits](../../atl/reference/cheapptrelementtraits-class.md) para ajudar na criação de um objeto de classe de coleção armazenar ponteiros de pilha.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CAtlList](../../atl/reference/catllist-class.md)

`CHeapPtrList`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

##  <a name="cheapptrlist"></a>  CHeapPtrList::CHeapPtrList

O construtor.

```
CHeapPtrList(UINT nBlockSize = 10) throw();
```

### <a name="parameters"></a>Parâmetros

*nBlockSize*<br/>
O tamanho do bloco.

### <a name="remarks"></a>Comentários

O tamanho do bloco é uma medida da quantidade de memória alocada quando um novo elemento é necessário. Tamanhos de bloco maiores reduzem chamadas para rotinas de alocação de memória, mas usam mais recursos.

## <a name="see-also"></a>Consulte também

[Classe CAtlList](../../atl/reference/catllist-class.md)<br/>
[Classe CHeapPtr](../../atl/reference/cheapptr-class.md)<br/>
[Classe CHeapPtrElementTraits](../../atl/reference/cheapptrelementtraits-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
