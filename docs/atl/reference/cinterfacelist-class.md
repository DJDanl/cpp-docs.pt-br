---
title: Classe CInterfaceList
ms.date: 11/04/2016
f1_keywords:
- CInterfaceList
- ATLCOLL/ATL::CInterfaceList
- ATLCOLL/ATL::CInterfaceList::CInterfaceList
helpviewer_keywords:
- CInterfaceList class
ms.assetid: 2077764d-25e5-4b3d-96c8-08a287bbcd25
ms.openlocfilehash: 0a7fd781c63e4ea084cf078e49fc9efb9cfa2d85
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326790"
---
# <a name="cinterfacelist-class"></a>Classe CInterfaceList

Esta classe fornece métodos úteis ao construir uma lista de ponteiros de interface COM.

## <a name="syntax"></a>Sintaxe

```
template<class I, const IID* piid =& __uuidof(I)>
class CInterfaceList
   : public CAtlList<ATL::CComQIPtr<I, piid>,
                     CComQIPtrElementTraits<I, piid>>
```

#### <a name="parameters"></a>Parâmetros

*Eu*<br/>
Uma interface COM especificando o tipo de ponteiro a ser armazenado.

*Piid*<br/>
Um ponteiro para o IID de *I*.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Lista de cinterface::CInterfaceList](#cinterfacelist)|O construtor da lista de interface.|

## <a name="remarks"></a>Comentários

Esta classe fornece um método de construção e derivado para criar uma lista de ponteiros de interface COM. Use [CInterfaceArray](../../atl/reference/cinterfacearray-class.md) quando uma matriz for necessária.

Para obter mais informações, consulte [ATL Collection Classes](../../atl/atl-collection-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Catllist](../../atl/reference/catllist-class.md)

`CInterfaceList`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

## <a name="cinterfacelistcinterfacelist"></a><a name="cinterfacelist"></a>Lista de cinterface::CInterfaceList

O construtor da lista de interface.

```
CInterfaceList(UINT nBlockSize = 10) throw();
```

### <a name="parameters"></a>Parâmetros

*Nblocksize*<br/>
O tamanho do bloco, com um padrão de 10.

### <a name="remarks"></a>Comentários

O tamanho do bloco é uma medida da quantidade de memória alocada quando um novo elemento é necessário. Tamanhos de blocomaiores reduzem chamadas para rotinas de alocação de memória, mas usam mais recursos.

## <a name="see-also"></a>Confira também

[Classe CAtlList](../../atl/reference/catllist-class.md)<br/>
[Classe CComQIPtr](../../atl/reference/ccomqiptr-class.md)<br/>
[Classe CComQIPtrElementTraits](../../atl/reference/ccomqiptrelementtraits-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
