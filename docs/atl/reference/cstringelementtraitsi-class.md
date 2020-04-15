---
title: Classe CstringElementTraitsI
ms.date: 11/04/2016
f1_keywords:
- CStringElementTraitsI
- ATLCOLL/ATL::CStringElementTraitsI
- ATLCOLL/ATL::CStringElementTraitsI::INARGTYPE
- ATLCOLL/ATL::CStringElementTraitsI::OUTARGTYPE
- ATLCOLL/ATL::CStringElementTraitsI::CompareElements
- ATLCOLL/ATL::CStringElementTraitsI::CompareElementsOrdered
- ATLCOLL/ATL::CStringElementTraitsI::Hash
helpviewer_keywords:
- CStringElementTraitsI class
ms.assetid: c23f92b1-91e5-400f-96ed-258b02622b7a
ms.openlocfilehash: 32980e19443cb17a3a688c85ff21195c60ed2124
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330599"
---
# <a name="cstringelementtraitsi-class"></a>Classe CstringElementTraitsI

Esta classe fornece funções estáticas relacionadas a strings armazenadas em objetos de classe de coleção. É semelhante ao [CStringElementTraits,](../../atl/reference/cstringelementtraits-class.md)mas realiza comparações insensíveis a casos.

## <a name="syntax"></a>Sintaxe

```
template <typename T, class CharTraits = CDefaultCharTraits<T ::XCHAR>>
class CStringElementTraitsI : public CElementTraitsBase<T>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados a serem armazenados na coleção.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CstringElementTraitsi::INARGTYPE](#inargtype)|O tipo de dados a ser usado para adicionar elementos ao objeto da classe de coleta.|
|[CstringElementTraitsi::OUTARGTYPE](#outargtype)|O tipo de dados a ser usado para recuperar elementos do objeto da classe de coleta.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CStringElementTraitsi::CompareElements](#compareelements)|Chame esta função estática para comparar dois elementos de cadeia para igualdade, ignorando diferenças no caso.|
|[CStringElementTraitsI:CompareElementsPedido](#compareelementsordered)|Chame esta função estática para comparar dois elementos de seqüência, ignorando diferenças no caso.|
|[CStringElementTraitsI::Hash](#hash)|Chame esta função estática para calcular um valor de hash para o determinado elemento de string.|

## <a name="remarks"></a>Comentários

Esta classe fornece funções estáticas para comparar strings e para criar um valor de hash. Essas funções são úteis ao usar uma classe de coleta para armazenar dados baseados em strings. Use [CStringRefElementTraits](../../atl/reference/cstringrefelementtraits-class.md) quando os objetos de seqüência devem ser tratados como referências.

Para obter mais informações, consulte [ATL Collection Classes](../../atl/atl-collection-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Celementtraitsbase](../../atl/reference/celementtraitsbase-class.md)

`CStringElementTraitsI`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

## <a name="cstringelementtraitsicompareelements"></a><a name="compareelements"></a>CStringElementTraitsi::CompareElements

Chame esta função estática para comparar dois elementos de cadeia para igualdade, ignorando diferenças no caso.

```
static bool CompareElements(INARGTYPE str1, INARGTYPE str2) throw();
```

### <a name="parameters"></a>Parâmetros

*str1*<br/>
O primeiro elemento de corda.

*str2*<br/>
O segundo elemento de corda.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se os elementos são iguais, falsos de outra forma.

### <a name="remarks"></a>Comentários

Comparações são casos insensíveis.

## <a name="cstringelementtraitsicompareelementsordered"></a><a name="compareelementsordered"></a>CStringElementTraitsI:CompareElementsPedido

Chame esta função estática para comparar dois elementos de seqüência, ignorando diferenças no caso.

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

### <a name="remarks"></a>Comentários

Comparações são casos insensíveis.

## <a name="cstringelementtraitsihash"></a><a name="hash"></a>CStringElementTraitsI::Hash

Chame esta função estática para calcular um valor de hash para o determinado elemento de string.

```
static ULONG Hash(INARGTYPE str) throw();
```

### <a name="parameters"></a>Parâmetros

*Str*<br/>
O elemento de cordas.

### <a name="return-value"></a>Valor retornado

Retorna um valor de hash, calculado usando o conteúdo da string.

## <a name="cstringelementtraitsiinargtype"></a><a name="inargtype"></a>CstringElementTraitsi::INARGTYPE

O tipo de dados a ser usado para adicionar elementos ao objeto da classe de coleta.

```
typedef T::PCXSTR INARGTYPE;
```

## <a name="cstringelementtraitsioutargtype"></a><a name="outargtype"></a>CstringElementTraitsi::OUTARGTYPE

O tipo de dados a ser usado para recuperar elementos do objeto da classe de coleta.

```
typedef T& OUTARGTYPE;
```

## <a name="see-also"></a>Confira também

[Classe CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe CStringElementTraits](../../atl/reference/cstringelementtraits-class.md)
