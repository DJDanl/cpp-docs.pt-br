---
title: "PROVIDER_COLUMN_ENTRY_TYPE_LENGTH | Microsoft Docs"
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
  - "PROVIDER_COLUMN_ENTRY_TYPE_LENGTH"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro PROVIDER_COLUMN_ENTRY_TYPE_LENGTH"
ms.assetid: a60b1a8b-0903-4ff4-91ec-ed62126449fb
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# PROVIDER_COLUMN_ENTRY_TYPE_LENGTH
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa uma coluna específica com suporte do provedor.  
  
## Sintaxe  
  
```  
  
PROVIDER_COLUMN_ENTRY_TYPE_LENGTH(  
name  
, ordinal, dbtype, size, member )  
```  
  
#### Parâmetros  
 *name*  
  
 \[in\] o nome da coluna.  
  
 `ordinal`  
 \[in\] o número da coluna.  A menos que a coluna é uma coluna do indicador, o número da coluna não deve ser 0.  
  
 `dbtype`  
 \[in\] o tipo de dados em [DBTYPE](https://msdn.microsoft.com/en-us/library/ms711251.aspx).  
  
 `size`  
 \[in\] o tamanho da coluna em bytes.  
  
 `member`  
 \[in\] a variável de membro na classe de dados que armazena os dados.  
  
## Comentários  
 Semelhante a [PROVIDER\_COLUMN\_ENTRY\_LENGTH](../../data/oledb/provider-column-entry-length.md) mas também permite que você especifique o tipo de dados assim como o tamanho da coluna.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Macros para modelos de provedor de banco de dados OLE](../../data/oledb/macros-for-ole-db-provider-templates.md)   
 [Modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)   
 [Criando um provedor de banco de dados OLE](../../data/oledb/creating-an-ole-db-provider.md)