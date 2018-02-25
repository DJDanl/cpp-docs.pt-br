---
title: Classe IRowsetCreatorImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::IRowsetCreatorImpl
- ATL.IRowsetCreatorImpl
- ATL::IRowsetCreatorImpl<T>
- ATL.IRowsetCreatorImpl<T>
- IRowsetCreatorImpl
dev_langs:
- C++
helpviewer_keywords:
- IRowsetCreatorImpl class
ms.assetid: 92cc950f-7978-4754-8d9a-defa63867d82
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 51d984f2254c8a2a135b5ecb386e8f195946366b
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="irowsetcreatorimpl-class"></a>Classe IRowsetCreatorImpl
Executa as mesmas funções `IObjectWithSite` , mas também permite que as propriedades de OLE DB **DBPROPCANSCROLLBACKWARDS DBPROPCANFETCHBACKWARDS**.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template < class T >  
class ATL_NO_VTABLE IRowsetCreatorImpl   
   : public IObjectWithSiteImpl< T >  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Uma classe derivada de **IRowsetCreator**.  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[SetSite](../../data/oledb/irowsetcreatorimpl-setsite.md)|Define o local que contém o objeto de conjunto de linhas.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe herda de [IObjectWithSite](http://msdn.microsoft.com/library/windows/desktop/ms693765) e substituições [IObjectWithSite::SetSite](http://msdn.microsoft.com/library/windows/desktop/ms683869). Quando um objeto de comando ou uma sessão do provedor cria um conjunto de linhas, ele chama `QueryInterface` no objeto de conjunto de linhas procurando `IObjectWithSite` e chamadas `SetSite` passando o objeto de conjunto de linhas **IUnkown** interface como a interface de site.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)