---
title: Classe IGetDataSourceImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- IGetDataSourceImpl
- ATL.IGetDataSourceImpl<T>
- ATL.IGetDataSourceImpl
- ATL::IGetDataSourceImpl
- ATL::IGetDataSourceImpl<T>
dev_langs: C++
helpviewer_keywords: IGetDataSourceImpl class
ms.assetid: d63f3178-d663-4f01-8c09-8aab2dd6805a
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: c83ab71b7b19d410dd0157f3400ebc1a58a63916
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="igetdatasourceimpl-class"></a>Classe IGetDataSourceImpl
Fornece uma implementação de [IGetDataSource](https://msdn.microsoft.com/en-us/library/ms709721.aspx) objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class T>  
class ATL_NO_VTABLE IGetDataSourceImpl : public IGetDataSource  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe derivada de `IGetDataSourceImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="interface-methods"></a>Métodos de interface  
  
|||  
|-|-|  
|[GetDataSource](../../data/oledb/igetdatasourceimpl-getdatasource.md)|Retorna um ponteiro de interface no objeto de fonte de dados que criou a sessão.|  
  
## <a name="remarks"></a>Comentários  
 Isso é uma interface obrigatória na sessão para obter um ponteiro de interface para o objeto de fonte de dados.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)