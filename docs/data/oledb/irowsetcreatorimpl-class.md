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
ms.openlocfilehash: a53cd653258980d21e9dd297ae61c458732b7250
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80210542"
---
# <a name="irowsetcreatorimpl-class"></a>Classe IRowsetCreatorImpl

Executa as mesmas funções que `IObjectWithSite`, mas também habilita as propriedades OLE DB `DBPROPCANSCROLLBACKWARDS DBPROPCANFETCHBACKWARDS`.

## <a name="syntax"></a>Sintaxe

```cpp
template < class T >
class ATL_NO_VTABLE IRowsetCreatorImpl
   : public IObjectWithSiteImpl< T >
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Uma classe derivada de `IRowsetCreator`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[SetSite](#setsite)|Define o site que contém o objeto de conjunto de linhas.|

## <a name="remarks"></a>Comentários

Essa classe herda de [IObjectWithSite](/windows/win32/api/ocidl/nn-ocidl-iobjectwithsite) e substitui [IObjectWithSite:: SetSite](/windows/win32/api/ocidl/nf-ocidl-iobjectwithsite-setsite). Quando um comando de provedor ou objeto de sessão cria um conjunto de linhas, ele chama `QueryInterface` no objeto de conjunto de linhas procurando `IObjectWithSite` e chamadas `SetSite` passando a interface de `IUnkown` do objeto de conjunto de linhas como a interface do site.

## <a name="irowsetcreatorimplsetsite"></a><a name="setsite"></a>IRowsetCreatorImpl:: SetSite

Define o site que contém o objeto de conjunto de linhas. Para obter mais informações, consulte [IObjectWithSite:: SetSite](/windows/win32/api/ocidl/nf-ocidl-iobjectwithsite-setsite).

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(SetSite )(IUnknown* pCreator);
```

#### <a name="parameters"></a>parâmetros

*pCreator*<br/>
no Ponteiro para o `IUnknown` ponteiro de interface do site que gerencia o objeto de conjunto de linhas.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Além disso, `IRowsetCreatorImpl::SetSite` habilita as propriedades de `DBPROPCANSCROLLBACKWARDS DBPROPCANFETCHBACKWARDS` de OLE DB.

## <a name="see-also"></a>Confira também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)
