---
title: Classe CComQIPtrElementTraits
ms.date: 11/04/2016
f1_keywords:
- CComQIPtrElementTraits
- ATLCOLL/ATL::CComQIPtrElementTraits
- ATLCOLL/ATL::CComQIPtrElementTraits::INARGTYPE
helpviewer_keywords:
- CComQIPtrElementTraits class
ms.assetid: 9df9250a-5413-4362-b133-332932a597c4
ms.openlocfilehash: 19f2669c157310be02f746672b22f6c0ed005075
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327404"
---
# <a name="ccomqiptrelementtraits-class"></a>Classe CComQIPtrElementTraits

Esta classe fornece métodos, funções estáticas e tipos úteis ao criar coleções de ponteiros de interface COM.

## <a name="syntax"></a>Sintaxe

```
template<typename I, const IID* piid=& __uuidof(I)>
class CComQIPtrElementTraits :
   public CDefaultElementTraits<ATL::CComQIPtr<I, piid>>
```

#### <a name="parameters"></a>Parâmetros

*Eu*<br/>
Uma interface COM especificando o tipo de ponteiro a ser armazenado.

*Piid*<br/>
Um ponteiro para o IID de *I*.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CComQIPtrElementTraits::INARGTYPE](#inargtype)|O tipo de dados a ser usado para adicionar elementos ao objeto da classe de coleta.|

## <a name="remarks"></a>Comentários

Esta classe deriva métodos e fornece um typedef útil ao criar uma classe de coleção de objetos de ponteiro de interface [CComQIPtr](../../atl/reference/ccomqiptr-class.md) COM. Esta classe é utilizada pelas classes [CInterfaceArray](../../atl/reference/cinterfacearray-class.md) e [CInterfaceList.](../../atl/reference/cinterfacelist-class.md)

Para obter mais informações, consulte [ATL Collection Classes](../../atl/atl-collection-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cdefaultcomparetraits](../../atl/reference/cdefaultcomparetraits-class.md)

[Cdefaulthashtraits](../../atl/reference/cdefaulthashtraits-class.md)

[Celementtraitsbase](../../atl/reference/celementtraitsbase-class.md)

[CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)

`CComQIPtrElementTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

## <a name="ccomqiptrelementtraitsinargtype"></a><a name="inargtype"></a>CComQIPtrElementTraits::INARGTYPE

O tipo de dados a ser usado para adicionar elementos ao objeto da classe de coleta.

```
typedef I* INARGTYPE;
```

## <a name="see-also"></a>Confira também

[Classe CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
