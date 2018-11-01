---
title: Classe CElementTraitsBase
ms.date: 11/04/2016
f1_keywords:
- CElementTraitsBase
- ATLCOLL/ATL::CElementTraitsBase
- ATLCOLL/ATL::CElementTraitsBase::INARGTYPE
- ATLCOLL/ATL::CElementTraitsBase::OUTARGTYPE
- ATLCOLL/ATL::CElementTraitsBase::CopyElements
- ATLCOLL/ATL::CElementTraitsBase::RelocateElements
helpviewer_keywords:
- CElementTraitsBase class
ms.assetid: 75284caf-347e-4355-a7d8-efc708dd514a
ms.openlocfilehash: 769fa5abff223ad570847b8bf68378ce85df664e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50508999"
---
# <a name="celementtraitsbase-class"></a>Classe CElementTraitsBase

Essa classe fornece uma cópia padrão e move os métodos para uma classe de coleção.

## <a name="syntax"></a>Sintaxe

```
template<typename T>
class CElementTraitsBase
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados a serem armazenados na coleção.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CElementTraitsBase::INARGTYPE](#inargtype)|O tipo de dados a ser usado para adicionar elementos ao objeto de classe da coleção.|
|[CElementTraitsBase::OUTARGTYPE](#outargtype)|O tipo de dados a ser usado para recuperar os elementos do objeto de classe da coleção.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CElementTraitsBase::CopyElements](#copyelements)|Chame esse método para copiar elementos armazenados em um objeto de classe de coleção.|
|[CElementTraitsBase::RelocateElements](#relocateelements)|Chame esse método para realocar os elementos armazenados em um objeto de classe de coleção.|

## <a name="remarks"></a>Comentários

Essa classe base define métodos para copiar e realocação de elementos em uma classe de coleção. Ele é utilizado pelas classes [CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md), [CStringRefElementTraits](../../atl/reference/cstringrefelementtraits-class.md), e [CStringElementTraitsI](../../atl/reference/cstringelementtraitsi-class.md).

Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

##  <a name="copyelements"></a>  CElementTraitsBase::CopyElements

Chame esse método para copiar elementos armazenados em um objeto de classe de coleção.

```
static void CopyElements(
    T* pDest,
    const T* pSrc,
    size_t nElements);
```

### <a name="parameters"></a>Parâmetros

*pDest*<br/>
Ponteiro para o primeiro elemento que receberá os dados copiados.

*pSrc*<br/>
Ponteiro para o primeiro elemento para copiar.

*nElements*<br/>
O número de elementos a serem copiados.

### <a name="remarks"></a>Comentários

Os elementos de origem e de destino não devem se sobrepor.

##  <a name="inargtype"></a>  CElementTraitsBase::INARGTYPE

O tipo de dados a ser usado para adicionar elementos à coleção.

```
typedef const T& INARGTYPE;
```

##  <a name="outargtype"></a>  CElementTraitsBase::OUTARGTYPE

O tipo de dados a ser usado para recuperar os elementos da coleção.

```
typedef T& OUTARGTYPE;
```

##  <a name="relocateelements"></a>  CElementTraitsBase::RelocateElements

Chame esse método para realocar os elementos armazenados em um objeto de classe de coleção.

```
static void RelocateElements(
    T* pDest,
    T* pSrc,
    size_t nElements);
```

### <a name="parameters"></a>Parâmetros

*pDest*<br/>
Ponteiro para o primeiro elemento que receberá os dados realocados.

*pSrc*<br/>
Ponteiro para o primeiro elemento para realocar.

*nElements*<br/>
O número de elementos para realocar.

### <a name="remarks"></a>Comentários

Este método chama [memmove](../../c-runtime-library/reference/memmove-wmemmove.md), que é suficiente para a maioria dos tipos de dados. Se os objetos que estão sendo movidos contêm ponteiros para os seus próprios membros, esse método precisará ser substituído.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
