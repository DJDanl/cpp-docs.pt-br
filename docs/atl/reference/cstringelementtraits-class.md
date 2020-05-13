---
title: Classe CStringElementTraits
ms.date: 11/04/2016
f1_keywords:
- CStringElementTraits
- CSTRINGT/ATL::CStringElementTraits
- CSTRINGT/ATL::CStringElementTraits::INARGTYPE
- CSTRINGT/ATL::CStringElementTraits::OUTARGTYPE
- CSTRINGT/ATL::CStringElementTraits::CompareElements
- CSTRINGT/ATL::CStringElementTraits::CompareElementsOrdered
- CSTRINGT/ATL::CStringElementTraits::CopyElements
- CSTRINGT/ATL::CStringElementTraits::Hash
- CSTRINGT/ATL::CStringElementTraits::RelocateElements
helpviewer_keywords:
- CStringElementTraits class
ms.assetid: 74d7134b-099d-4455-bf91-3e68ccbf95bc
ms.openlocfilehash: 078cfd5ff93bfcd8acc747904ea05e6a2e762bc1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330614"
---
# <a name="cstringelementtraits-class"></a>Classe CStringElementTraits

Esta classe fornece funções estáticas `CString` usadas pelas classes de coleta armazenando objetos.

## <a name="syntax"></a>Sintaxe

```
template <typename T>
class CStringElementTraits
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados a serem armazenados na coleção.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CStringElementTraits::INARGTYPE](#inargtype)|O tipo de dados a ser usado para adicionar elementos ao objeto da classe de coleta.|
|[CStringElementTraits::OUTARGTYPE](#outargtype)|O tipo de dados a ser usado para recuperar elementos do objeto da classe de coleta.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CStringElementTraits::CompareElements](#compareelements)|(Estática) Chame esta função para comparar dois elementos de seqüência para igualdade.|
|[CStringElementTraits::CompareElementsPedido](#compareelementsordered)|(Estática) Chame esta função para comparar dois elementos de seqüência.|
|[CStringElementTraits::CopyElements](#copyelements)|(Estática) Chame esta função `CString` para copiar elementos armazenados em um objeto de classe de coleção.|
|[CStringElementTraits::Hash](#hash)|(Estática) Chame esta função para calcular um valor de hash para o elemento de seqüência dado.|
|[CStringElementTraits::Realocar elementos](#relocateelements)|(Estática) Chame esta função `CString` para realocar elementos armazenados em um objeto de classe de coleção.|

## <a name="remarks"></a>Comentários

Esta classe fornece funções estáticas para copiar, mover e comparar strings e para criar um valor de hash. Essas funções são úteis ao usar uma classe de coleta para armazenar dados baseados em strings. Use [CStringElementTraitsI](../../atl/reference/cstringelementtraitsi-class.md) quando forem necessárias comparações insensíveis a casos. Use [CStringRefElementTraits](../../atl/reference/cstringrefelementtraits-class.md) quando os objetos de seqüência devem ser tratados como referências.

Para obter mais informações, consulte [ATL Collection Classes](../../atl/atl-collection-classes.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** cstringt.h

## <a name="cstringelementtraitscompareelements"></a><a name="compareelements"></a>CStringElementTraits::CompareElements

Chame esta função estática para comparar dois elementos de seqüência para igualdade.

```
static bool CompareElements(INARGTYPE str1, INARGTYPE str2);
```

### <a name="parameters"></a>Parâmetros

*str1*<br/>
O primeiro elemento de corda.

*str2*<br/>
O segundo elemento de corda.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se os elementos são iguais, falsos de outra forma.

## <a name="cstringelementtraitscompareelementsordered"></a><a name="compareelementsordered"></a>CStringElementTraits::CompareElementsPedido

Chame esta função estática para comparar dois elementos de seqüência.

```
static int CompareElementsOrdered(INARGTYPE str1, INARGTYPE str2);
```

### <a name="parameters"></a>Parâmetros

*str1*<br/>
O primeiro elemento de corda.

*str2*<br/>
O segundo elemento de corda.

### <a name="return-value"></a>Valor retornado

Zero se as cordas forem idênticas, < 0 se *str1* for menor que *str2*, ou > 0 se *str1* for maior que *str2*. O método [CStringT::Compare](../../atl-mfc-shared/reference/cstringt-class.md#compare) é usado para realizar as comparações.

## <a name="cstringelementtraitscopyelements"></a><a name="copyelements"></a>CStringElementTraits::CopyElements

Chame esta função `CString` estática para copiar elementos armazenados em um objeto de classe de coleção.

```
static void CopyElements(
    T* pDest,
    const T* pSrc,
    size_t nElements);
```

### <a name="parameters"></a>Parâmetros

*pDest*<br/>
Ponteiro para o primeiro elemento que receberá os dados copiados.

*Psrc*<br/>
Ponteiro para o primeiro elemento a copiar.

*nElementos*<br/>
O número de elementos a serem copiados.

### <a name="remarks"></a>Comentários

Os elementos de origem e destino não devem se sobrepor.

## <a name="cstringelementtraitshash"></a><a name="hash"></a>CStringElementTraits::Hash

Chame esta função estática para calcular um valor de hash para o determinado elemento de string.

```
static ULONG Hash(INARGTYPE str);
```

### <a name="parameters"></a>Parâmetros

*Str*<br/>
O elemento de cordas.

### <a name="return-value"></a>Valor retornado

Retorna um valor de hash, calculado usando o conteúdo da string.

## <a name="cstringelementtraitsinargtype"></a><a name="inargtype"></a>CStringElementTraits::INARGTYPE

O tipo de dados a ser usado para adicionar elementos ao objeto da classe de coleta.

```
typedef T::PCXSTR INARGTYPE;
```

## <a name="cstringelementtraitsoutargtype"></a><a name="outargtype"></a>CStringElementTraits::OUTARGTYPE

O tipo de dados a ser usado para recuperar elementos do objeto da classe de coleta.

```
typedef T& OUTARGTYPE;
```

## <a name="cstringelementtraitsrelocateelements"></a><a name="relocateelements"></a>CStringElementTraits::Realocar elementos

Chame esta função `CString` estática para realocar elementos armazenados em um objeto de classe de coleção.

```
static void RelocateElements(
    T* pDest,
    T* pSrc,
    size_t nElements);
```

### <a name="parameters"></a>Parâmetros

*pDest*<br/>
Ponteiro para o primeiro elemento que receberá os dados realocados.

*Psrc*<br/>
Ponteiro para o primeiro elemento a ser realocado.

*nElementos*<br/>
O número de elementos para realocar.

### <a name="remarks"></a>Comentários

Esta função estática chama [memmove](../../c-runtime-library/reference/memmove-wmemmove.md), o que é suficiente para a maioria dos tipos de dados. Se os objetos que estão sendo movidos contiverem ponteiros para seus próprios membros, esta função estática precisará ser substituída.

## <a name="see-also"></a>Confira também

[Classe CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)<br/>
[Classe CstringElementTraitsI](../../atl/reference/cstringelementtraitsi-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
