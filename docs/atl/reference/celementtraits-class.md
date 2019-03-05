---
title: Classe CElementTraits
ms.date: 11/04/2016
f1_keywords:
- CElementTraits
- atlcoll/ATL::CElementTraits
helpviewer_keywords:
- CElementTraits class
ms.assetid: 496528e5-7f80-4b45-be0c-6f646feb43c5
ms.openlocfilehash: 646b445aed93c9041932c60442f61792f5e1a7e8
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57298796"
---
# <a name="celementtraits-class"></a>Classe CElementTraits

Essa classe é usada pelas classes de coleção para fornecer funções e métodos para mover, copiar, comparação e operações de hash.

## <a name="syntax"></a>Sintaxe

```
template<typename T>
class CElementTraits : public CDefaultElementTraits<T>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados a serem armazenados na coleção.

## <a name="remarks"></a>Comentários

Essa classe fornece métodos e funções estáticas de padrão para mover, copiar, comparando e armazenados em um objeto de classe de coleção de elementos de hash. `CElementTraits` é especificado como o provedor padrão, essas operações pelas classes de coleção [CAtlArray](../../atl/reference/catlarray-class.md), [CAtlList](../../atl/reference/catllist-class.md), [CRBMap](../../atl/reference/crbmap-class.md), [CRBMultiMap](../../atl/reference/crbmultimap-class.md), e [CRBTree](../../atl/reference/crbtree-class.md).

As implementações padrão serão suficiente para tipos de dados simples, mas se as classes de coleção são usadas para armazenar objetos mais complexos, as funções e os métodos devem ser substituídos por implementações fornecida pelo usuário.

Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

## <a name="see-also"></a>Consulte também

[Classe CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
