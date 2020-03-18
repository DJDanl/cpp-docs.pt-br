---
title: Classe IDBCreateCommandImpl
ms.date: 11/04/2016
f1_keywords:
- ATL::IDBCreateCommandImpl
- IDBCreateCommandImpl
- ATL.IDBCreateCommandImpl
- IDBCreateCommandImpl.CreateCommand
- IDBCreateCommandImpl::CreateCommand
helpviewer_keywords:
- IDBCreateCommandImpl class
- CreateCommand method
ms.assetid: eac4755e-1668-42e1-958e-a35620c385ae
ms.openlocfilehash: 27ca1fd20e8f358d936789da695611d96a6e7aa1
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446132"
---
# <a name="idbcreatecommandimpl-class"></a>Classe IDBCreateCommandImpl

Fornece uma implementação da interface [IDBCreateCommand](/previous-versions/windows/desktop/ms711625(v=vs.85)) .

## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class CommandClass >
class ATL_NO_VTABLE IDBCreateCommandImpl
   : public IDBCreateCommand
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O objeto de sessão derivado de `IDBCreateCommandImpl`.

*CommandClass*<br/>
Sua classe de comando.

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="interface-methods"></a>Métodos de interface

|||
|-|-|
|[CreateCommand](#createcommand)|Cria um novo comando.|

## <a name="remarks"></a>Comentários

Uma interface opcional no objeto de sessão para obter um novo comando.

## <a name="createcommand"></a>IDBCreateCommandImpl:: CreateCommand

Cria um novo comando e retorna a interface solicitada.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(CreateCommand)(IUnknown * pUnkOuter,
   REFIID riid,
   IUnknown ** ppvCommand);
```

#### <a name="parameters"></a>Parâmetros

Consulte [IDBCreateCommand:: CreateCommand](/previous-versions/windows/desktop/ms709772(v=vs.85)) na *referência do programador de OLE DB*.

Alguns parâmetros correspondem a parâmetros de *referência do programador OLE DB* de nomes diferentes, que são descritos em `IDBCreateCommand::CreateCommand`:

|OLE DB parâmetros de modelo|Parâmetros *de referência do programador de OLE DB*|
|--------------------------------|------------------------------------------------|
|*ppvCommand*|*ppCommand*|

## <a name="see-also"></a>Consulte também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)