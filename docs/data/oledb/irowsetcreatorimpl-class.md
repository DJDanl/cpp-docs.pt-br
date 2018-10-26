---
title: Classe IRowsetCreatorImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL::IRowsetCreatorImpl
- ATL.IRowsetCreatorImpl
- ATL::IRowsetCreatorImpl<T>
- ATL.IRowsetCreatorImpl<T>
- IRowsetCreatorImpl
- IRowsetCreatorImpl.SetSite
- IRowsetCreatorImpl<T>::SetSite
- IRowsetCreatorImpl::SetSite
- SetSite
- ATL.IRowsetCreatorImpl.SetSite
- ATL::IRowsetCreatorImpl<T>::SetSite
- ATL::IRowsetCreatorImpl::SetSite
- ATL.IRowsetCreatorImpl<T>.SetSite
dev_langs:
- C++
helpviewer_keywords:
- IRowsetCreatorImpl class
- SetSite method
ms.assetid: 92cc950f-7978-4754-8d9a-defa63867d82
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 34fc1304fe4fad1196b5f204e6ba241093e03f32
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50066208"
---
# <a name="irowsetcreatorimpl-class"></a>Classe IRowsetCreatorImpl

Executa as mesmas funções como `IObjectWithSite` , mas também permite que as propriedades de OLE DB `DBPROPCANSCROLLBACKWARDS DBPROPCANFETCHBACKWARDS`.

## <a name="syntax"></a>Sintaxe

```cpp
template < class T >
class ATL_NO_VTABLE IRowsetCreatorImpl
   : public IObjectWithSiteImpl< T >
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Uma classe derivada de `IRowsetCreator`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldb.h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[SetSite](#setsite)|Define o site que contém o objeto de conjunto de linhas.|

## <a name="remarks"></a>Comentários

Essa classe herda de [IObjectWithSite](/windows/desktop/api/ocidl/nn-ocidl-iobjectwithsite) e substitui [IObjectWithSite::SetSite](/windows/desktop/api/ocidl/nf-ocidl-iobjectwithsite-setsite). Quando um objeto de comando ou sessão do provedor cria um conjunto de linhas, ele chama `QueryInterface` no objeto de conjunto de linhas procurando `IObjectWithSite` e chama `SetSite` passando o objeto de conjunto de linhas `IUnkown` interface como a interface de site.

## <a name="setsite"></a> Irowsetcreatorimpl:: SetSite

Define o site que contém o objeto de conjunto de linhas. Para obter mais informações, consulte [IObjectWithSite::SetSite](/windows/desktop/api/ocidl/nf-ocidl-iobjectwithsite-setsite).

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(SetSite )(IUnknown* pCreator);
```

#### <a name="parameters"></a>Parâmetros

*pCreator*<br/>
[in] Ponteiro para o `IUnknown` ponteiro de interface do site Gerenciando o objeto de conjunto de linhas.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Além disso, `IRowsetCreatorImpl::SetSite` permite que o OLE DB `DBPROPCANSCROLLBACKWARDS DBPROPCANFETCHBACKWARDS` propriedades.

## <a name="see-also"></a>Consulte também

[Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)