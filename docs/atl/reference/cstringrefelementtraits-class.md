---
title: Classe CStringRefElementTraits
ms.date: 11/04/2016
f1_keywords:
- CStringRefElementTraits
- ATLCOLL/ATL::CStringRefElementTraits
- ATLCOLL/ATL::CStringRefElementTraits::CompareElements
- ATLCOLL/ATL::CStringRefElementTraits::CompareElementsOrdered
- ATLCOLL/ATL::CStringRefElementTraits::Hash
helpviewer_keywords:
- CStringRefElementTraits class
ms.assetid: cc15062d-5627-46cc-ac2b-1744afdc2dbd
ms.openlocfilehash: 6fa8772033a5a82940cf30b2a73d6ea356269d67
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226549"
---
# <a name="cstringrefelementtraits-class"></a>Classe CStringRefElementTraits

Essa classe fornece funções estáticas relacionadas a cadeias de caracteres armazenadas em objetos de classe de coleção. Os objetos de cadeia de caracteres são tratados como referências.

## <a name="syntax"></a>Sintaxe

```
template <typename T>
class CStringRefElementTraits : public CElementTraitsBase<T>
```

#### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo de dados a ser armazenado na coleção.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CStringRefElementTraits::CompareElements](#compareelements)|Chame essa função estática para comparar dois elementos de cadeia de caracteres para igualdade.|
|[CStringRefElementTraits::CompareElementsOrdered](#compareelementsordered)|Chame essa função estática para comparar dois elementos de cadeia de caracteres.|
|[CStringRefElementTraits:: hash](#hash)|Chame essa função estática para calcular um valor de hash para o elemento de cadeia de caracteres fornecido.|

## <a name="remarks"></a>Comentários

Essa classe fornece funções estáticas para comparar cadeias de caracteres e para criar um valor de hash. Essas funções são úteis ao usar uma classe de coleção para armazenar dados baseados em cadeia de caracteres. Ao contrário de [CStringElementTraits](../../atl/reference/cstringelementtraits-class.md) e [CStringElementTraitsI](../../atl/reference/cstringelementtraitsi-class.md), faz com que `CStringRefElementTraits` os `CString` argumentos sejam passados como **`const`** `CString&` referências.

Para obter mais informações, consulte [classes de coleção do ATL](../../atl/atl-collection-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)

`CStringRefElementTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll. h

## <a name="cstringrefelementtraitscompareelements"></a><a name="compareelements"></a>CStringRefElementTraits::CompareElements

Chame essa função estática para comparar dois elementos de cadeia de caracteres para igualdade.

```
static bool CompareElements(INARGTYPE element1, INARGTYPE element2) throw();
```

### <a name="parameters"></a>parâmetros

*Element1*<br/>
O primeiro elemento String.

*element2*<br/>
O segundo elemento de cadeia de caracteres.

### <a name="return-value"></a>Valor retornado

Retornará true se os elementos forem iguais; caso contrário, false.

## <a name="cstringrefelementtraitscompareelementsordered"></a><a name="compareelementsordered"></a>CStringRefElementTraits::CompareElementsOrdered

Chame essa função estática para comparar dois elementos de cadeia de caracteres.

```
static int CompareElementsOrdered(INARGTYPE str1, INARGTYPE str2) throw();
```

### <a name="parameters"></a>parâmetros

*str1*<br/>
O primeiro elemento String.

*str2*<br/>
O segundo elemento de cadeia de caracteres.

### <a name="return-value"></a>Valor retornado

Zero se as cadeias de caracteres forem idênticas, < 0 se *str1* for menor que *str2*, ou > 0 se *str1* for maior que *str2*. O método [CStringT:: Compare](../../atl-mfc-shared/reference/cstringt-class.md#compare) é usado para executar as comparações.

## <a name="cstringrefelementtraitshash"></a><a name="hash"></a>CStringRefElementTraits:: hash

Chame essa função estática para calcular um valor de hash para o elemento de cadeia de caracteres fornecido.

```
static ULONG Hash(INARGTYPE str) throw();
```

### <a name="parameters"></a>parâmetros

*str*<br/>
O elemento String.

### <a name="return-value"></a>Valor retornado

Retorna um valor de hash, calculado usando o conteúdo da cadeia de caracteres.

## <a name="see-also"></a>Confira também

[Classe CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
