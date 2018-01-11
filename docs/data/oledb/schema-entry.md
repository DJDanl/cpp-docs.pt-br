---
title: SCHEMA_ENTRY | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: SCHEMA_ENTRY
dev_langs: C++
helpviewer_keywords: SCHEMA_ENTRY macro
ms.assetid: e8bee479-80f3-417e-8f41-cdaddd49690c
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 12a4026e94ea5fe5e310e0aeec7cdad10d33d2bf
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="schemaentry"></a>SCHEMA_ENTRY
Associa um GUID de uma classe.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      SCHEMA_ENTRY(  
   guid,  
   rowsetClass   
);   
```  
  
#### <a name="parameters"></a>Parâmetros  
 `guid`  
 Um conjunto de linhas do esquema GUID. Consulte [IDBSchemaRowset](https://msdn.microsoft.com/en-us/library/ms713686.aspx) no *referência do programador de DB OLE* para obter uma lista de conjuntos de linhas de esquema e seus GUIDs.  
  
 *rowsetClass*  
 A classe que será criada para representar o conjunto de linhas de esquema.  
  
## <a name="remarks"></a>Comentários  
 [IDBSchemaRowsetImpl](../../data/oledb/idbschemarowsetimpl-class.md) pode, em seguida, consulta o mapa para obter uma lista de GUIDs, ou pode criar um conjunto de linhas se for fornecido um GUID. O conjunto de linhas de esquema `IDBSchemaRowsetImpl` cria é semelhante a um padrão `CRowsetImpl`-a classe derivada, exceto que ela deve fornecer um **Execute** método que tem a seguinte assinatura:  
  
```  
HRESULT Execute (
    LONG* pcRowsAffected,  
    ULONG cRestrictions,  
    const VARIANT* rgRestrictions);  
```  
  
 Isso **Execute** função preenche os dados do conjunto de linhas. O Assistente de projeto de ATL cria, conforme descrito em [IDBSchemaRowset](https://msdn.microsoft.com/en-us/library/ms713686.aspx) no *referência do programador de DB OLE*, três inicial conjuntos de linhas de esquema no projeto para cada um dos três esquemas de banco de dados OLE obrigatórios:  
  
-   `DBSCHEMA_TABLES`  
  
-   **DBSCHEMA_COLUMNS**  
  
-   **DBSCHEMA_PROVIDER_TYPES**  
  
 O assistente também adiciona três entradas correspondentes no mapa de esquema. Consulte [criando um provedor OLE DB modelo](../../data/oledb/creating-an-ole-db-provider.md) para obter mais informações sobre como usar o Assistente para criar um provedor.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros para modelos de provedor do OLE DB](../../data/oledb/macros-for-ole-db-provider-templates.md)   
 [BEGIN_SCHEMA_MAP](../../data/oledb/begin-schema-map.md)   
 [END_SCHEMA_MAP](../../data/oledb/end-schema-map.md)