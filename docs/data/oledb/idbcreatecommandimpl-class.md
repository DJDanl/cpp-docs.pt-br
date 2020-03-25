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
ms.openlocfilehash: 4a4978401ba90e3a7a91ac40cc1b0668adf12ee8
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80210711"
---
# <a name="idbcreatecommandimpl-class"></a>Classe IDBCreateCommandImpl

Fornece uma implementação da interface [IDBCreateCommand](/previous-versions/windows/desktop/ms711625(v=vs.85)) .

## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class CommandClass >
class ATL_NO_VTABLE IDBCreateCommandImpl
   : public IDBCreateCommand
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O objeto de sessão derivado de `IDBCreateCommandImpl`.

*CommandClass*<br/>
Sua classe de comando.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="interface-methods"></a>Métodos de interface

|||
|-|-|
|[CreateCommand](#createcommand)|Cria um novo comando.|

## <a name="remarks"></a>Comentários

Uma interface opcional no objeto de sessão para obter um novo comando.

## <a name="idbcreatecommandimplcreatecommand"></a><a name="createcommand"></a>IDBCreateCommandImpl:: CreateCommand

Cria um novo comando e retorna a interface solicitada.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(CreateCommand)(IUnknown * pUnkOuter,
   REFIID riid,
   IUnknown ** ppvCommand);
```

#### <a name="parameters"></a>parâmetros

Consulte [IDBCreateCommand:: CreateCommand](/previous-versions/windows/desktop/ms709772(v=vs.85)) na *referência do programador de OLE DB*.

Alguns parâmetros correspondem a parâmetros de *referência do programador OLE DB* de nomes diferentes, que são descritos em `IDBCreateCommand::CreateCommand`:

|OLE DB parâmetros de modelo|Parâmetros *de referência do programador de OLE DB*|
|--------------------------------|------------------------------------------------|
|*ppvCommand*|*ppCommand*|

## <a name="see-also"></a>Confira também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)
