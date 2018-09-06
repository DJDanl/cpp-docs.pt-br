---
title: Classe CAutoPtrArray | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CAutoPtrArray
- ATLCOLL/ATL::CAutoPtrArray
- ATLCOLL/ATL::CAutoPtrArray::CAutoPtrArray
dev_langs:
- C++
helpviewer_keywords:
- CAutoPtrArray class
ms.assetid: 880a70da-8c81-4427-8ac6-49aa8d424244
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 85cd1a9a50d57ececb2d12dca8faa6dc914972f5
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43763026"
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

`E`  
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

[Classe CAtlArray](../../atl/reference/catlarray-class.md)   
[Classe CAutoPtrElementTraits](../../atl/reference/cautoptrelementtraits-class.md)   
[Classe CAutoPtrList](../../atl/reference/cautoptrlist-class.md)   
[Visão geral da classe](../../atl/atl-class-overview.md)
