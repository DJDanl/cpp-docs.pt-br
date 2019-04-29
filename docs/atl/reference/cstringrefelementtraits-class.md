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
ms.openlocfilehash: c57fda64689a80dfa548977e56b0416641bb4360
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62277396"
---
# <a name="cstringrefelementtraits-class"></a>Classe CStringRefElementTraits

Essa classe fornece funções estáticas relacionadas a cadeias de caracteres armazenadas em objetos de classe de coleção. Os objetos de cadeia de caracteres são tratados como referências.

## <a name="syntax"></a>Sintaxe

```
template <typename T>
class CStringRefElementTraits : public CElementTraitsBase<T>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados a serem armazenados na coleção.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CStringRefElementTraits::CompareElements](#compareelements)|Chame essa função estática para comparar dois elementos de cadeia de caracteres quanto à igualdade.|
|[CStringRefElementTraits::CompareElementsOrdered](#compareelementsordered)|Chame essa função estática para comparar dois elementos de cadeia de caracteres.|
|[CStringRefElementTraits::Hash](#hash)|Chame essa função estática para calcular um valor de hash para o elemento de cadeia de caracteres fornecida.|

## <a name="remarks"></a>Comentários

Essa classe fornece funções estáticas para comparar cadeias de caracteres e para a criação de um valor de hash. Essas funções são úteis ao usar uma classe de coleção para armazenar dados com base em cadeia de caracteres. Diferentemente [CStringElementTraits](../../atl/reference/cstringelementtraits-class.md) e [CStringElementTraitsI](../../atl/reference/cstringelementtraitsi-class.md), `CStringRefElementTraits` faz com que o `CString` argumentos a serem passados como **const** `CString&` faz referência.

Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)

`CStringRefElementTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

##  <a name="compareelements"></a>  CStringRefElementTraits::CompareElements

Chame essa função estática para comparar dois elementos de cadeia de caracteres quanto à igualdade.

```
static bool CompareElements(INARGTYPE element1, INARGTYPE element2) throw();
```

### <a name="parameters"></a>Parâmetros

*element1*<br/>
O primeiro elemento da cadeia de caracteres.

*element2*<br/>
O segundo elemento de cadeia de caracteres.

### <a name="return-value"></a>Valor de retorno

Retorna true se os elementos são iguais, caso contrário, false.

##  <a name="compareelementsordered"></a>  CStringRefElementTraits::CompareElementsOrdered

Chame essa função estática para comparar dois elementos de cadeia de caracteres.

```
static int CompareElementsOrdered(INARGTYPE str1, INARGTYPE str2) throw();
```

### <a name="parameters"></a>Parâmetros

*str1*<br/>
O primeiro elemento da cadeia de caracteres.

*str2*<br/>
O segundo elemento de cadeia de caracteres.

### <a name="return-value"></a>Valor de retorno

Zero se as cadeias de caracteres são idênticas, < 0 se *str1* é menor que *str2*, ou > 0 se *str1* é maior que *str2*. O [CStringT::Compare](../../atl-mfc-shared/reference/cstringt-class.md#compare) método é usado para realizar as comparações.

##  <a name="hash"></a>  CStringRefElementTraits::Hash

Chame essa função estática para calcular um valor de hash para o elemento de cadeia de caracteres fornecida.

```
static ULONG Hash(INARGTYPE str) throw();
```

### <a name="parameters"></a>Parâmetros

*str*<br/>
O elemento de cadeia de caracteres.

### <a name="return-value"></a>Valor de retorno

Retorna um valor de hash, calculado usando o conteúdo da cadeia de caracteres.

## <a name="see-also"></a>Consulte também

[Classe CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
