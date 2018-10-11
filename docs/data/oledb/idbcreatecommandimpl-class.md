---
title: Classe IDBCreateCommandImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL::IDBCreateCommandImpl
- IDBCreateCommandImpl
- ATL.IDBCreateCommandImpl
- IDBCreateCommandImpl.CreateCommand
- CreateCommand
- IDBCreateCommandImpl::CreateCommand
dev_langs:
- C++
helpviewer_keywords:
- IDBCreateCommandImpl class
- CreateCommand method
ms.assetid: eac4755e-1668-42e1-958e-a35620c385ae
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: b06d6c730562203cdef1191a9d73012c3b19c2c8
ms.sourcegitcommit: 3a141cf07b5411d5f1fdf6cf67c4ce928cf389c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/11/2018
ms.locfileid: "49083952"
---
# <a name="idbcreatecommandimpl-class"></a>Classe IDBCreateCommandImpl

Fornece uma implementação de [IDBCreateCommand](/previous-versions/windows/desktop/ms711625) interface.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class CommandClass >  
class ATL_NO_VTABLE IDBCreateCommandImpl   
   : public IDBCreateCommand  
```  
  
### <a name="parameters"></a>Parâmetros  

*T*<br/>
O objeto de sessão é derivado de `IDBCreateCommandImpl`.  
  
*Pkgmkcampo*<br/>
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

## <a name="createcommand"></a> Idbcreatecommandimpl:: CreateCommand

Cria um novo comando e retorna a interface solicitada.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD(CreateCommand)(IUnknown * pUnkOuter,   
   REFIID riid,   
   IUnknown ** ppvCommand);  
```  
  
#### <a name="parameters"></a>Parâmetros  

Ver [idbcreatecommand:: CreateCommand](/previous-versions/windows/desktop/ms709772) na *referência do programador do OLE DB*.  
  
Alguns parâmetros correspondem aos *referência do programador DB OLE* parâmetros de nomes diferentes, que são descritos em `IDBCreateCommand::CreateCommand`:  
  
|Parâmetros de modelo de banco de dados OLE|*Referência do OLE DB Programmer* parâmetros|  
|--------------------------------|------------------------------------------------|  
|*ppvCommand*|*ppCommand*|  
  
## <a name="see-also"></a>Consulte também  

[Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)