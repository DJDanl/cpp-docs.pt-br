---
title: Classe IRowsetCreatorImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL::IRowsetCreatorImpl
- ATL.IRowsetCreatorImpl
- ATL::IRowsetCreatorImpl<T>
- ATL.IRowsetCreatorImpl<T>
- IRowsetCreatorImpl
dev_langs: C++
helpviewer_keywords: IRowsetCreatorImpl class
ms.assetid: 92cc950f-7978-4754-8d9a-defa63867d82
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 3a1a1c17ad9469ff31b5520ffadb3349f86827ad
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="irowsetcreatorimpl-class"></a>Classe IRowsetCreatorImpl
Executa as mesmas funções `IObjectWithSite` , mas também permite que as propriedades de OLE DB **DBPROPCANSCROLLBACKWARDS DBPROPCANFETCHBACKWARDS**.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
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