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
ms.openlocfilehash: 5a29e8778cf2f3400df25b55574950a005bad995
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326999"
---
# <a name="celementtraitsbase-class"></a>Classe CElementTraitsBase

Esta classe fornece métodos padrão de cópia e movimento para uma classe de coleta.

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
|[CElementTraitsBase::INARGTYPE](#inargtype)|O tipo de dados a ser usado para adicionar elementos ao objeto da classe de coleta.|
|[CElementTraitsBase::OUTARGTYPE](#outargtype)|O tipo de dados a ser usado para recuperar elementos do objeto da classe de coleta.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CElementTraitsBase::CopyElements](#copyelements)|Chame este método para copiar elementos armazenados em um objeto de classe de coleção.|
|[CElementTraitsBase::Realocar elementos](#relocateelements)|Chame este método para realocar elementos armazenados em um objeto de classe de coleção.|

## <a name="remarks"></a>Comentários

Esta classe base define métodos para copiar e realocar elementos em uma classe de coleção. É utilizado pelas classes [CDefaultElementTraits,](../../atl/reference/cdefaultelementtraits-class.md) [CStringRefElementTraits](../../atl/reference/cstringrefelementtraits-class.md)e [CStringElementTraitsI](../../atl/reference/cstringelementtraitsi-class.md).

Para obter mais informações, consulte [ATL Collection Classes](../../atl/atl-collection-classes.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

## <a name="celementtraitsbasecopyelements"></a><a name="copyelements"></a>CElementTraitsBase::CopyElements

Chame este método para copiar elementos armazenados em um objeto de classe de coleção.

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

## <a name="celementtraitsbaseinargtype"></a><a name="inargtype"></a>CElementTraitsBase::INARGTYPE

O tipo de dados a ser usado para adicionar elementos à coleção.

```
typedef const T& INARGTYPE;
```

## <a name="celementtraitsbaseoutargtype"></a><a name="outargtype"></a>CElementTraitsBase::OUTARGTYPE

O tipo de dados a ser usado para recuperar elementos da coleta.

```
typedef T& OUTARGTYPE;
```

## <a name="celementtraitsbaserelocateelements"></a><a name="relocateelements"></a>CElementTraitsBase::Realocar elementos

Chame este método para realocar elementos armazenados em um objeto de classe de coleção.

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

Este método chama [memmove](../../c-runtime-library/reference/memmove-wmemmove.md), que é suficiente para a maioria dos tipos de dados. Se os objetos que estão sendo movidos contiverem ponteiros para seus próprios membros, este método precisará ser substituído.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
