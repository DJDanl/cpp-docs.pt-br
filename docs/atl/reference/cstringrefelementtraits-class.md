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
ms.openlocfilehash: b4dd76b9592b255a1553be3ca7a249f58fb2672e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330579"
---
# <a name="cstringrefelementtraits-class"></a>Classe CStringRefElementTraits

Esta classe fornece funções estáticas relacionadas a strings armazenadas em objetos de classe de coleção. Os objetos de corda são tratados como referências.

## <a name="syntax"></a>Sintaxe

```
template <typename T>
class CStringRefElementTraits : public CElementTraitsBase<T>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados a serem armazenados na coleção.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CStringRefElementoTraits::CompareElementos](#compareelements)|Chame esta função estática para comparar dois elementos de seqüência para igualdade.|
|[CStringRefElementoS::CompareElementosOrdenado](#compareelementsordered)|Chame esta função estática para comparar dois elementos de seqüência.|
|[CStringRefElementTraits::Hash](#hash)|Chame esta função estática para calcular um valor de hash para o determinado elemento de string.|

## <a name="remarks"></a>Comentários

Esta classe fornece funções estáticas para comparar strings e para criar um valor de hash. Essas funções são úteis ao usar uma classe de coleta para armazenar dados baseados em strings. Ao contrário [de CStringElementTraits](../../atl/reference/cstringelementtraits-class.md) e `CStringRefElementTraits` [CStringElementTraitsI,](../../atl/reference/cstringelementtraitsi-class.md)faz com que os `CString` argumentos sejam passados como referências **const.** `CString&`

Para obter mais informações, consulte [ATL Collection Classes](../../atl/atl-collection-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Celementtraitsbase](../../atl/reference/celementtraitsbase-class.md)

`CStringRefElementTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

## <a name="cstringrefelementtraitscompareelements"></a><a name="compareelements"></a>CStringRefElementoTraits::CompareElementos

Chame esta função estática para comparar dois elementos de seqüência para igualdade.

```
static bool CompareElements(INARGTYPE element1, INARGTYPE element2) throw();
```

### <a name="parameters"></a>Parâmetros

*elemento1*<br/>
O primeiro elemento de corda.

*elemento2*<br/>
O segundo elemento de corda.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se os elementos são iguais, falsos de outra forma.

## <a name="cstringrefelementtraitscompareelementsordered"></a><a name="compareelementsordered"></a>CStringRefElementoS::CompareElementosOrdenado

Chame esta função estática para comparar dois elementos de seqüência.

```
static int CompareElementsOrdered(INARGTYPE str1, INARGTYPE str2) throw();
```

### <a name="parameters"></a>Parâmetros

*str1*<br/>
O primeiro elemento de corda.

*str2*<br/>
O segundo elemento de corda.

### <a name="return-value"></a>Valor retornado

Zero se as cordas forem idênticas, < 0 se *str1* for menor que *str2*, ou > 0 se *str1* for maior que *str2*. O método [CStringT::Compare](../../atl-mfc-shared/reference/cstringt-class.md#compare) é usado para realizar as comparações.

## <a name="cstringrefelementtraitshash"></a><a name="hash"></a>CStringRefElementTraits::Hash

Chame esta função estática para calcular um valor de hash para o determinado elemento de string.

```
static ULONG Hash(INARGTYPE str) throw();
```

### <a name="parameters"></a>Parâmetros

*Str*<br/>
O elemento de cordas.

### <a name="return-value"></a>Valor retornado

Retorna um valor de hash, calculado usando o conteúdo da string.

## <a name="see-also"></a>Confira também

[Classe CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
