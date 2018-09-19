---
title: Classe CComQIPtrElementTraits | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CComQIPtrElementTraits
- ATLCOLL/ATL::CComQIPtrElementTraits
- ATLCOLL/ATL::CComQIPtrElementTraits::INARGTYPE
dev_langs:
- C++
helpviewer_keywords:
- CComQIPtrElementTraits class
ms.assetid: 9df9250a-5413-4362-b133-332932a597c4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6dbc0e10f2747b9a9a2ad3ff345a580d4797ea72
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46079304"
---
# <a name="ccomqiptrelementtraits-class"></a>Classe CComQIPtrElementTraits

Essa classe fornece métodos, funções estáticas e definições de tipo útil durante a criação de coleções de ponteiros de interface COM.

## <a name="syntax"></a>Sintaxe

```
template<typename I, const IID* piid=& __uuidof(I)>
class CComQIPtrElementTraits : 
   public CDefaultElementTraits<ATL::CComQIPtr<I, piid>>
```

#### <a name="parameters"></a>Parâmetros

*I*<br/>
Uma interface COM especificando o tipo de ponteiro a ser armazenado.

*piid*<br/>
Um ponteiro para o IID da *eu*.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CComQIPtrElementTraits::INARGTYPE](#inargtype)|O tipo de dados a ser usado para adicionar elementos ao objeto de classe da coleção.|

## <a name="remarks"></a>Comentários

Essa classe é derivada de métodos e fornece um typedef útil durante a criação de uma classe de coleção de [CComQIPtr](../../atl/reference/ccomqiptr-class.md) objetos de ponteiro de interface COM. Essa classe é utilizada por ambos os [CInterfaceArray](../../atl/reference/cinterfacearray-class.md) e [CInterfaceList](../../atl/reference/cinterfacelist-class.md) classes.

Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CDefaultCompareTraits](../../atl/reference/cdefaultcomparetraits-class.md)

[CDefaultHashTraits](../../atl/reference/cdefaulthashtraits-class.md)

[CElementTraitsBase](../../atl/reference/celementtraitsbase-class.md)

[CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)

`CComQIPtrElementTraits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

##  <a name="inargtype"></a>  CComQIPtrElementTraits::INARGTYPE

O tipo de dados a ser usado para adicionar elementos ao objeto de classe da coleção.

```
typedef I* INARGTYPE;
```

## <a name="see-also"></a>Consulte também

[Classe CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
