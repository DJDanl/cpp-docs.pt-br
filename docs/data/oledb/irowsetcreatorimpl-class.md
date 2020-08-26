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
ms.openlocfilehash: c1ad2c5e97dfe975a3b545e44b512dff7bf512a0
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88843438"
---
# <a name="irowsetcreatorimpl-class"></a>Classe IRowsetCreatorImpl

Executa as mesmas funções que `IObjectWithSite` , mas também habilita as propriedades OLE DB `DBPROPCANSCROLLBACKWARDS DBPROPCANFETCHBACKWARDS` .

## <a name="syntax"></a>Sintaxe

```cpp
template < class T >
class ATL_NO_VTABLE IRowsetCreatorImpl
   : public IObjectWithSiteImpl< T >
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Uma classe derivada de `IRowsetCreator` .

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

| Nome | Descrição |
|-|-|
|[SetSite](#setsite)|Define o site que contém o objeto de conjunto de linhas.|

## <a name="remarks"></a>Comentários

Essa classe herda de [IObjectWithSite](/windows/win32/api/ocidl/nn-ocidl-iobjectwithsite) e substitui [IObjectWithSite:: SetSite](/windows/win32/api/ocidl/nf-ocidl-iobjectwithsite-setsite). Quando um comando de provedor ou objeto de sessão cria um conjunto de linhas, ele chama `QueryInterface` o objeto de conjunto de linhas procurando `IObjectWithSite` e chama `SetSite` a interface do objeto de conjunto de linhas `IUnkown` como a interface do site.

## <a name="irowsetcreatorimplsetsite"></a><a name="setsite"></a> IRowsetCreatorImpl:: SetSite

Define o site que contém o objeto de conjunto de linhas. Para obter mais informações, consulte [IObjectWithSite:: SetSite](/windows/win32/api/ocidl/nf-ocidl-iobjectwithsite-setsite).

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(SetSite )(IUnknown* pCreator);
```

#### <a name="parameters"></a>parâmetros

*pCreator*<br/>
no Ponteiro para o `IUnknown` ponteiro de interface do site que gerencia o objeto de conjunto de linhas.

### <a name="return-value"></a>Valor Retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Além disso, `IRowsetCreatorImpl::SetSite` o habilita as `DBPROPCANSCROLLBACKWARDS DBPROPCANFETCHBACKWARDS` propriedades de OLE DB.

## <a name="see-also"></a>Confira também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo de provedor de OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)
