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
ms.openlocfilehash: 6a2457ed01214750091bd9ec5a59c9aeac819357
ms.sourcegitcommit: 889a75be1232817150be1e0e8d4d7f48f5993af2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/30/2018
ms.locfileid: "39336987"
---
# <a name="idbcreatecommandimpl-class"></a>Classe IDBCreateCommandImpl
Fornece uma implementação de [IDBCreateCommand](https://msdn.microsoft.com/library/ms711625.aspx) interface.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class CommandClass >  
class ATL_NO_VTABLE IDBCreateCommandImpl   
   : public IDBCreateCommand  
```  
  
### <a name="parameters"></a>Parâmetros  
 *T*  
 O objeto de sessão é derivado de `IDBCreateCommandImpl`.  
  
 *Pkgmkcampo*  
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
 Ver [idbcreatecommand:: CreateCommand](https://msdn.microsoft.com/library/ms709772.aspx) na *referência do programador do OLE DB*.  
  
 Alguns parâmetros correspondem aos *referência do programador DB OLE* parâmetros de nomes diferentes, que são descritos em `IDBCreateCommand::CreateCommand`:  
  
|Parâmetros de modelo de banco de dados OLE|*Referência do OLE DB Programmer* parâmetros|  
|--------------------------------|------------------------------------------------|  
|*ppvCommand*|*ppCommand*|  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)