---
title: BEGIN_SCHEMA_MAP | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- BEGIN_SCHEMA_MAP
dev_langs:
- C++
helpviewer_keywords:
- BEGIN_SCHEMA_MAP macro
ms.assetid: 4e751023-35bc-4efd-9018-5448dd1ad751
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: f16ff89dc80728b40bdee1772c91d3c52e5e1c09
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="beginschemamap"></a>BEGIN_SCHEMA_MAP
Indica o início de um mapa de esquema.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      BEGIN_SCHEMA_MAP(SchemaClass);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *SchemaClass*  
 A classe que contém o mapa. Normalmente, essa será a classe de sessão.  
  
## <a name="remarks"></a>Comentários  
 Consulte [IDBSchemaRowset](https://msdn.microsoft.com/en-us/library/ms713686.aspx) no SDK do Windows para obter mais informações sobre conjuntos de linhas de esquema.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros para modelos de provedor do OLE DB](../../data/oledb/macros-for-ole-db-provider-templates.md)   
 [SCHEMA_ENTRY](../../data/oledb/schema-entry.md)   
 [END_SCHEMA_MAP](../../data/oledb/end-schema-map.md)   
 [Classe IDBSchemaRowsetImpl](../../data/oledb/idbschemarowsetimpl-class.md)