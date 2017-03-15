---
title: "CColumnPrivileges, CColumnPrivilegeInfo | Microsoft Docs"
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
  - "m_szTableSchema"
  - "CColumnPrivileges"
  - "m_bIsGrantable"
  - "m_nColumnPropID"
  - "m_szPrivilegeType"
  - "COLUMN_GUID"
  - "IS_GRANTABLE"
  - "m_szColumnName"
  - "m_szTableCatalog"
  - "m_szGrantor"
  - "GRANTOR"
  - "GRANTEE"
  - "COLUMN_PROPID"
  - "m_guidColumn"
  - "COLUMN_PRIVILEGES"
  - "m_szTableName"
  - "CColumnPrivilegeInfo"
  - "m_szGrantee"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de parâmetro CColumnPrivilegeInfo"
  - "Classe CColumnPrivileges (typedef)"
  - "COLUMN_GUID"
  - "COLUMN_NAME"
  - "COLUMN_PRIVILEGES"
  - "COLUMN_PROPID"
  - "GRANTEE"
  - "GRANTOR"
  - "IS_GRANTABLE"
  - "m_bIsGrantable"
  - "m_guidColumn"
  - "m_nColumnPropID"
  - "m_szColumnName"
  - "m_szGrantee"
  - "m_szGrantor"
  - "m_szPrivilegeType"
  - "m_szTableCatalog"
  - "m_szTableName"
  - "m_szTableSchema"
  - "TABLE_CATALOG"
  - "TABLE_NAME"
  - "TABLE_SCHEMA"
ms.assetid: 245df365-421f-43c6-9fcd-fb2197c871c6
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CColumnPrivileges, CColumnPrivilegeInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Chame a classe **CColumnPrivileges** do typedef para implementar a sua classe **CColumnPrivilegeInfo**do parâmetro.  
  
## Comentários  
 Consulte [Classes do conjunto de linhas de esquema e classes de Typedef](../Topic/Schema%20Rowset%20Classes%20and%20Typedef%20Classes.md) para obter mais informações sobre como usar classes do typedef.  
  
 Essa classe identifica os privilégios em colunas de tabelas, definidas no catálogo, que está disponível ou concedido por um determinado usuário.  
  
 A tabela a seguir lista os membros de dados da classe e suas colunas correspondentes OLE DB.  Consulte [Conjunto de linhas COLUMN\_PRIVILEGES](https://msdn.microsoft.com/en-us/library/ms715800.aspx)*na referência do programador de OLE DB* para obter mais informações sobre o esquema e de colunas.  
  
|Membros de dados|Colunas de OLE DB|  
|----------------------|-----------------------|  
|m\_szGrantor|GRANTOR|  
|m\_szGrantee|GRANTEE|  
|m\_szTableCatalog|TABLE\_CATALOG|  
|m\_szTableSchema|TABLE\_SCHEMA|  
|m\_szTableName|TABLE\_NAME|  
|m\_szColumnName|COLUMN\_NAME|  
|m\_guidColumn|COLUMN\_GUID|  
|m\_nColumnPropID|COLUMN\_PROPID|  
|m\_szPrivilegeType|PRIVILEGE\_TYPE|  
|m\_bIsGrantable|IS\_GRANTABLE|  
  
## Requisitos  
 **Header:** atldbsch.h  
  
## Consulte também  
 [Classe CRestrictions](../Topic/CRestrictions%20Class.md)