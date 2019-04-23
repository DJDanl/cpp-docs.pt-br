---
title: Classe IRowsetCreatorImpl
ms.date: 11/04/2016
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
helpviewer_keywords:
- IRowsetCreatorImpl class
- SetSite method
ms.assetid: 92cc950f-7978-4754-8d9a-defa63867d82
ms.openlocfilehash: 3dc5cb06b3eb7f01667e4e1ec09dd60f9befae77
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59026598"
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

## <a name="setsite"></a> IRowsetCreatorImpl::SetSite

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