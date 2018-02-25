---
title: 'Idbpropertiesimpl:: GetProperties | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IDBPropertiesImpl::GetProperties
- IDBPropertiesImpl.GetProperties
- GetProperties
dev_langs:
- C++
helpviewer_keywords:
- GetProperties method
ms.assetid: ab24aebd-366d-49a1-b49b-bb46c6d90f05
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 47286d409f6bc9ffe99faffe46db58245c958f92
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="idbpropertiesimplgetproperties"></a>IDBPropertiesImpl::GetProperties
Retorna os valores das propriedades dos grupos de propriedade de inicialização de fonte de dados e informações de fonte de dados que estão atualmente definidas no objeto de fonte de dados ou os valores das propriedades do grupo de propriedade de inicialização que estão atualmente definidas do enumerador.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      STDMETHOD(GetProperties)(ULONG cPropertySets,   
   const DBPROPIDSET rgPropertySets[],   
   ULONG * pcProperties,   
   DBPROPSET ** prgProperties);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Consulte [IDBProperties::GetProperties](https://msdn.microsoft.com/en-us/library/ms714344.aspx) no *referência do programador de OLE DB*.  
  
 Alguns parâmetros correspondem a *referência do programador de DB OLE* parâmetros de nomes diferentes, que são descritos em **IDBProperties::GetProperties**:  
  
|Parâmetros de modelo de banco de dados OLE|*Referência do programador DB OLE* parâmetros|  
|--------------------------------|------------------------------------------------|  
|`cPropertySets`|`cPropertyIDSets`|  
|`rgPropertySets`|`rgPropertyIDSets`|  
|*pcProperties*|*pcPropertySets*|  
|*prgProperties*|*prgPropertySets*|  
  
## <a name="remarks"></a>Comentários  
 Se o provedor é inicializado, esse método retorna os valores das propriedades de **DBPROPSET_DATASOURCE**, **DBPROPSET_DATASOURCEINFO**, **DBPROPSET_DBINIT** grupos de propriedades que estão atualmente definidos no objeto de fonte de dados. Se o provedor não é inicializado, ele retorna **DBPROPSET_DBINIT** somente propriedades do grupo.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IDBPropertiesImpl](../../data/oledb/idbpropertiesimpl-class.md)   
 [IDBPropertiesImpl::GetPropertyInfo](../../data/oledb/idbpropertiesimpl-getpropertyinfo.md)   
 [IDBPropertiesImpl::SetProperties](../../data/oledb/idbpropertiesimpl-setproperties.md)