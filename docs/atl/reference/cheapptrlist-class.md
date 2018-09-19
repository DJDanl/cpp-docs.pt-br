---
title: Classe CHeapPtrList | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CHeapPtrList
- ATLCOLL/ATL::CHeapPtrList
- ATLCOLL/ATL::CHeapPtrList::CHeapPtrList
dev_langs:
- C++
helpviewer_keywords:
- CHeapPtrList class
ms.assetid: cc70e585-362a-4007-81db-c705eb181226
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1990de6165e50397f11d84cb0486c1d5d5d67fce
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46089223"
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
