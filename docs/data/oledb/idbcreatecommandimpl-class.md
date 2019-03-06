---
title: Classe IDBCreateCommandImpl
ms.date: 11/04/2016
f1_keywords:
- ATL::IDBCreateCommandImpl
- IDBCreateCommandImpl
- ATL.IDBCreateCommandImpl
- IDBCreateCommandImpl.CreateCommand
- CreateCommand
- IDBCreateCommandImpl::CreateCommand
helpviewer_keywords:
- IDBCreateCommandImpl class
- CreateCommand method
ms.assetid: eac4755e-1668-42e1-958e-a35620c385ae
ms.openlocfilehash: fda12332ef14cb95e9f11f8df0b94ccfffa0303d
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57425179"
---
# <a name="idbcreatecommandimpl-class"></a>Classe IDBCreateCommandImpl

Fornece uma implementação de [IDBCreateCommand](/previous-versions/windows/desktop/ms711625(v=vs.85)) interface.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class CommandClass >
class ATL_NO_VTABLE IDBCreateCommandImpl
   : public IDBCreateCommand
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O objeto de sessão é derivado de `IDBCreateCommandImpl`.

*CommandClass*<br/>
Sua classe de comando.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldb.h

## <a name="members"></a>Membros

### <a name="interface-methods"></a>Métodos de interface

|||
|-|-|
|[CreateCommand](#createcommand)|Cria um novo comando.|

## <a name="remarks"></a>Comentários

Uma interface opcional no objeto de sessão para obter um novo comando.

## <a name="createcommand"></a> IDBCreateCommandImpl::CreateCommand

Cria um novo comando e retorna a interface solicitada.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(CreateCommand)(IUnknown * pUnkOuter,
   REFIID riid,
   IUnknown ** ppvCommand);
```

#### <a name="parameters"></a>Parâmetros

Ver [idbcreatecommand:: CreateCommand](/previous-versions/windows/desktop/ms709772(v=vs.85)) na *referência do programador do OLE DB*.

Alguns parâmetros correspondem aos *referência do programador DB OLE* parâmetros de nomes diferentes, que são descritos em `IDBCreateCommand::CreateCommand`:

|Parâmetros de modelo de banco de dados OLE|*Referência do OLE DB Programmer* parâmetros|
|--------------------------------|------------------------------------------------|
|*ppvCommand*|*ppCommand*|

## <a name="see-also"></a>Consulte também

[Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)