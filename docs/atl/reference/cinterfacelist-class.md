---
title: Classe CInterfaceList | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CInterfaceList
- ATLCOLL/ATL::CInterfaceList
- ATLCOLL/ATL::CInterfaceList::CInterfaceList
dev_langs:
- C++
helpviewer_keywords:
- CInterfaceList class
ms.assetid: 2077764d-25e5-4b3d-96c8-08a287bbcd25
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fdf3ae7adf36ad471b5cab09d0f13a4d5e18f7a7
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50075561"
---
# <a name="cinterfacelist-class"></a>Classe CInterfaceList

Essa classe fornece métodos úteis ao construir uma lista de ponteiros de interface COM.

## <a name="syntax"></a>Sintaxe

```
template<class I, const IID* piid =& __uuidof(I)>
class CInterfaceList
   : public CAtlList<ATL::CComQIPtr<I, piid>,
                     CComQIPtrElementTraits<I, piid>>
```

#### <a name="parameters"></a>Parâmetros

*I*<br/>
Uma interface COM especificando o tipo de ponteiro a ser armazenado.

*piid*<br/>
Um ponteiro para o IID da *eu*.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CInterfaceList::CInterfaceList](#cinterfacelist)|O construtor para a lista de interface.|

## <a name="remarks"></a>Comentários

Essa classe fornece um construtor e métodos derivados para criar uma lista de ponteiros de interface COM. Use [CInterfaceArray](../../atl/reference/cinterfacearray-class.md) quando uma matriz é necessária.

Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CAtlList](../../atl/reference/catllist-class.md)

`CInterfaceList`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

##  <a name="cinterfacelist"></a>  CInterfaceList::CInterfaceList

O construtor para a lista de interface.

```
CInterfaceList(UINT nBlockSize = 10) throw();
```

### <a name="parameters"></a>Parâmetros

*nBlockSize*<br/>
O tamanho do bloco, com um padrão de 10.

### <a name="remarks"></a>Comentários

O tamanho do bloco é uma medida da quantidade de memória alocada quando um novo elemento é necessário. Tamanhos de bloco maiores reduzem chamadas para rotinas de alocação de memória, mas usam mais recursos.

## <a name="see-also"></a>Consulte também

[Classe CAtlList](../../atl/reference/catllist-class.md)<br/>
[Classe CComQIPtr](../../atl/reference/ccomqiptr-class.md)<br/>
[Classe CComQIPtrElementTraits](../../atl/reference/ccomqiptrelementtraits-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
