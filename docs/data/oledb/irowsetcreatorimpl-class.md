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
ms.openlocfilehash: 8c4253d469c510f5e6eb996ed510ef836844899d
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "70311780"
---
# <a name="irowsetcreatorimpl-class"></a>Classe IRowsetCreatorImpl

Executa as mesmas funções que `IObjectWithSite` , mas também habilita as propriedades `DBPROPCANSCROLLBACKWARDS DBPROPCANFETCHBACKWARDS`OLE DB.

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

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[SetSite](#setsite)|Define o site que contém o objeto de conjunto de linhas.|

## <a name="remarks"></a>Comentários

Essa classe herda de [IObjectWithSite](/windows/win32/api/ocidl/nn-ocidl-iobjectwithsite) e substitui [IObjectWithSite:: SetSite](/windows/win32/api/ocidl/nf-ocidl-iobjectwithsite-setsite). Quando um comando de provedor ou objeto de sessão cria um conjunto de `QueryInterface` linhas, ele chama o objeto `IObjectWithSite` de conjunto `SetSite` de linhas procurando e chama `IUnkown` a interface do objeto de conjunto de linhas como a interface do site.

## <a name="setsite"></a> IRowsetCreatorImpl::SetSite

Define o site que contém o objeto de conjunto de linhas. Para obter mais informações, consulte [IObjectWithSite:: SetSite](/windows/win32/api/ocidl/nf-ocidl-iobjectwithsite-setsite).

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(SetSite )(IUnknown* pCreator);
```

#### <a name="parameters"></a>Parâmetros

*pCreator*<br/>
no Ponteiro para o `IUnknown` ponteiro de interface do site que gerencia o objeto de conjunto de linhas.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Além disso, `IRowsetCreatorImpl::SetSite` o habilita as `DBPROPCANSCROLLBACKWARDS DBPROPCANFETCHBACKWARDS` Propriedades de OLE DB.

## <a name="see-also"></a>Consulte também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)