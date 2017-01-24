---
title: "PROVIDER_COLUMN_ENTRY_GN | Microsoft Docs"
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
  - "PROVIDER_COLUMN_ENTRY_GN"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro PROVIDER_COLUMN_ENTRY_GN"
ms.assetid: be77ba85-634c-4e28-832f-d2fa40413254
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# PROVIDER_COLUMN_ENTRY_GN
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa uma coluna específica com suporte do provedor.  
  
## Sintaxe  
  
```  
  
PROVIDER_COLUMN_ENTRY_GN (  
name  
, ordinal, flags, colSize, dbtype, precision, scale, guid )  
```  
  
#### Parâmetros  
 *nome*  
 \[in\] o nome da coluna.  
  
 `ordinal`  
 \[in\] o número da coluna.  A menos que a coluna é uma coluna do indicador, o número da coluna não deve ser 0.  
  
 `flags`  
 \[in\] especifica como os dados são retornados.  Consulte a descrição de `dwFlags` em [Estruturas DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx).  
  
 *colSize*  
 \[in\] o tamanho da coluna.  
  
 `dbtype`  
 \[in\] indica o tipo de dados do valor.  Consulte a descrição de **wType** em [Estruturas DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx).  
  
 *precisão*  
 \[in\] indica a precisão a ser usado quando obtendo dados se *o dbType* é `DBTYPE_NUMERIC` ou **DBTYPE\_DECIMAL**.  Consulte a descrição de **bPrecision** em [Estruturas DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx).  
  
 `scale`  
 \[in\] indica a escala a ser usado quando obtendo dados se o dbType é `DBTYPE_NUMERIC` ou **DBTYPE\_DECIMAL**.  Consulte a descrição de **bScale** em [Estruturas DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx).  
  
 `guid`  
 Um conjunto de linhas de esquema GUID.  Consulte [IDBSchemaRowset](https://msdn.microsoft.com/en-us/library/ms713686.aspx)*na referência do programador de OLE DB* para obter uma lista de conjuntos de linhas de esquema e dos respectivos GUIDs.  
  
## Comentários  
 Permite que você especifique o tamanho, o tipo de dados, precisão, escala, e o conjunto de linhas de esquema GUID da coluna.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Macros para modelos de provedor de banco de dados OLE](../../data/oledb/macros-for-ole-db-provider-templates.md)   
 [Modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)   
 [Criando um provedor de banco de dados OLE](../../data/oledb/creating-an-ole-db-provider.md)