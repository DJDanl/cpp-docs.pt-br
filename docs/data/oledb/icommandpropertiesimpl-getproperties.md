---
title: 'Icommandpropertiesimpl:: GetProperties | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ICommandPropertiesImpl::GetProperties
- ICommandPropertiesImpl.GetProperties
- GetProperties
dev_langs:
- C++
helpviewer_keywords:
- GetProperties method
ms.assetid: 1bee5f1b-bd08-435a-956a-e4cebcdf5d5e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 4a00cac292463251b89b314e7d4bd953480c505e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="icommandpropertiesimplgetproperties"></a>ICommandPropertiesImpl::GetProperties
Retorna todos os conjuntos de propriedade solicitada usando o mapa de propriedade do comando.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      STDMETHOD(GetProperties)(const ULONG cPropertyIDSets,   
   const DBPROPIDSET rgPropertyIDSets[],   
   ULONG * pcPropertySets,   
   DBPROPSET ** prgPropertySets);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Consulte [icommandproperties:: GetProperties](https://msdn.microsoft.com/en-us/library/ms723119.aspx) no *referência do programador de OLE DB*.  
  
## <a name="remarks"></a>Comentários  
 Consulte [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe ICommandPropertiesImpl](../../data/oledb/icommandpropertiesimpl-class.md)   
 [ICommandPropertiesImpl::SetProperties](../../data/oledb/icommandpropertiesimpl-setproperties.md)