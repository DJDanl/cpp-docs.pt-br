---
title: Classe IDBCreateSessionImpl
ms.date: 11/04/2016
f1_keywords:
- IDBCreateSessionImpl
- ATL.IDBCreateSessionImpl
- ATL::IDBCreateSessionImpl
- IDBCreateSessionImpl::CreateSession
- IDBCreateSessionImpl.CreateSession
- CreateSession
helpviewer_keywords:
- IDBCreateSessionImpl class
- CreateSession method
ms.assetid: 48c02c5c-8362-45ac-af8e-bb119cf8c5c7
ms.openlocfilehash: aeeca008499ca43cdcebd008390e5cb6c5a9e63c
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88845517"
---
# <a name="idbcreatesessionimpl-class"></a>Classe IDBCreateSessionImpl

Fornece uma implementação para a interface [IDBCreateSession](/previous-versions/windows/desktop/ms724076(v=vs.85)) .

## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class SessionClass>
class ATL_NO_VTABLE IDBCreateSessionImpl
   : public IDBCreateSession
```

### <a name="parameters"></a>parâmetros

*T*<br/>
SUA CLASSE, DERIVADA DE

*SessionClass*<br/>
O objeto de sessão.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="interface-methods"></a>Métodos de interface

| Nome | Descrição |
|-|-|
|[CreateSession](#createsession)|Cria uma nova sessão do objeto de fonte de dados e retorna a interface solicitada na sessão recém-criada.|

## <a name="remarks"></a>Comentários

Uma interface obrigatória em objetos de fonte de dados.

## <a name="idbcreatesessionimplcreatesession"></a><a name="createsession"></a> IDBCreateSessionImpl:: CreateSession

Cria uma nova sessão do objeto de fonte de dados e retorna a interface solicitada na sessão recém-criada.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(CreateSession)(IUnknown * pUnkOuter,
   REFIID riid,
   IUnknown ** ppDBSession);
```

#### <a name="parameters"></a>parâmetros

Consulte [IDBCreateSession:: CreateSession](/previous-versions/windows/desktop/ms714942(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="see-also"></a>Confira também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo de provedor de OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)
