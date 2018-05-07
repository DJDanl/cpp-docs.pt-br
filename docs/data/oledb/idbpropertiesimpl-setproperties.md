---
title: 'Idbpropertiesimpl:: SetProperties | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- IDBPropertiesImpl.SetProperties
- SetProperties
- IDBPropertiesImpl::SetProperties
dev_langs:
- C++
helpviewer_keywords:
- SetProperties method
ms.assetid: 2f9fc1de-7f35-4bca-bab3-7b427bf92c26
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 5067173da531bb8a4f437666ccfc9c9c61bb47f2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="idbpropertiesimplsetproperties"></a>IDBPropertiesImpl::SetProperties
Define propriedades em grupos de propriedade fonte de dados e de inicialização, para objetos de fonte de dados, ou o grupo de propriedades de inicialização para enumeradores.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      STDMETHOD(SetProperties)(ULONG cPropertySets,   
   DBPROPSET rgPropertySets[]);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Consulte [idbproperties:: SetProperties](https://msdn.microsoft.com/en-us/library/ms723049.aspx) no *referência do programador de OLE DB*.  
  
## <a name="remarks"></a>Comentários  
 Se o provedor é inicializado, esse método define os valores das propriedades de **DBPROPSET_DATASOURCE**, **DBPROPSET_DATASOURCEINFO**, **DBPROPSET_DBINIT** propriedade grupos para o objeto de fonte de dados. Se o provedor não é inicializado, ele define **DBPROPSET_DBINIT** somente propriedades do grupo.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IDBPropertiesImpl](../../data/oledb/idbpropertiesimpl-class.md)   
 [IDBPropertiesImpl::GetProperties](../../data/oledb/idbpropertiesimpl-getproperties.md)   
 [IDBPropertiesImpl::GetPropertyInfo](../../data/oledb/idbpropertiesimpl-getpropertyinfo.md)