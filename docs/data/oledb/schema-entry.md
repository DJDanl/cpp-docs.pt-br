---
title: "SCHEMA_ENTRY | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "SCHEMA_ENTRY"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro SCHEMA_ENTRY"
ms.assetid: e8bee479-80f3-417e-8f41-cdaddd49690c
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# SCHEMA_ENTRY
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Associa um GUID com uma classe.  
  
## Sintaxe  
  
```  
  
      SCHEMA_ENTRY(  
   guid,  
   rowsetClass   
);   
```  
  
#### Parâmetros  
 `guid`  
 Um conjunto de linhas de esquema GUID.  Consulte [IDBSchemaRowset](https://msdn.microsoft.com/en-us/library/ms713686.aspx)*na referência do programador de OLE DB* para obter uma lista de conjuntos de linhas de esquema e dos respectivos GUIDs.  
  
 *rowsetClass*  
 A classe que será criada para representar o conjunto de linhas de esquema.  
  
## Comentários  
 [IDBSchemaRowsetImpl](../../data/oledb/idbschemarowsetimpl-class.md) poderá ver o mapa para obter uma lista dos GUIDs, ou pode criar um conjunto de linhas se é determinada GUID.  O conjunto de linhas de esquema `IDBSchemaRowsetImpl` cria é semelhante a `CRowsetImpl`padrão \- classe derivada, a não ser que deve fornecer um método de **Executar** que tenha a seguinte assinatura:  
  
 `HRESULT Execute (LONG* pcRowsAffected, ULONG cRestrictions,`  
  
 `const VARIANT* rgRestrictions)`  
  
 Essa função de **Executar** popula os dados do conjunto de linhas.  O assistente de projeto de ATL cria, conforme descrito em [IDBSchemaRowset](https://msdn.microsoft.com/en-us/library/ms713686.aspx)*na referência do programador do*OLE DB, três conjuntos de linhas de esquema inicial no projeto para cada um dos três esquemas obrigatórios OLE DB:  
  
-   `DBSCHEMA_TABLES`  
  
-   **DBSCHEMA\_COLUMNS**  
  
-   **DBSCHEMA\_PROVIDER\_TYPES**  
  
 O assistente também adiciona três entradas correspondentes no esquema.  Consulte [Criando um provedor OLE DB do modelo](../../data/oledb/creating-an-ole-db-provider.md) para obter mais informações sobre como usar o assistente para criar um provedor.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Macros para modelos de provedor de banco de dados OLE](../../data/oledb/macros-for-ole-db-provider-templates.md)   
 [BEGIN\_SCHEMA\_MAP](../../data/oledb/begin-schema-map.md)   
 [END\_SCHEMA\_MAP](../../data/oledb/end-schema-map.md)