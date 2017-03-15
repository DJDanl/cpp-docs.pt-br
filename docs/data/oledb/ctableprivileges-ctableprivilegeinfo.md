---
title: "CTablePrivileges, CTablePrivilegeInfo | Microsoft Docs"
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
  - "m_szCatalog"
  - "m_bIsGrantable"
  - "IS_GRANTABLE"
  - "m_szType"
  - "m_szSchema"
  - "m_szGrantor"
  - "GRANTOR"
  - "GRANTEE"
  - "CTablePrivileges"
  - "CTablePrivilegeInfo"
  - "m_szName"
  - "m_szGrantee"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de parâmetro CTablePrivilegeInfo"
  - "Classe CTablePrivileges (typedef)"
  - "GRANTEE"
  - "GRANTOR"
  - "IS_GRANTABLE"
  - "m_bIsGrantable"
  - "m_szCatalog"
  - "m_szGrantee"
  - "m_szGrantor"
  - "m_szName"
  - "m_szSchema"
  - "m_szType"
  - "TABLE_CATALOG"
  - "TABLE_NAME"
  - "TABLE_SCHEMA"
ms.assetid: ffcd6f73-022e-452a-8342-f2b9362d256b
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CTablePrivileges, CTablePrivilegeInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Chame a classe **CTablePrivileges** do typedef para implementar a sua classe **CTablePrivilegeInfo**do parâmetro.  
  
## Comentários  
 Consulte [Classes do conjunto de linhas de esquema e classes de Typedef](../Topic/Schema%20Rowset%20Classes%20and%20Typedef%20Classes.md) para obter mais informações sobre como usar classes do typedef.  
  
 Essa classe identifica as tabelas definidas no catálogo que são acessíveis para um determinado usuário.  
  
 A tabela a seguir lista os membros de dados da classe e suas colunas correspondentes OLE DB.  Consulte [Conjunto de linhas de TABLE\_PRIVILEGES](https://msdn.microsoft.com/en-us/library/ms725428.aspx)*na referência do programador de OLE DB* para obter mais informações sobre o esquema e de colunas.  
  
|Membros de dados|Colunas de OLE DB|  
|----------------------|-----------------------|  
|m\_szGrantor|GRANTOR|  
|m\_szGrantee|GRANTEE|  
|m\_szCatalog|TABLE\_CATALOG|  
|m\_szSchema|TABLE\_SCHEMA|  
|m\_szName|TABLE\_NAME|  
|m\_szType|PRIVILEGE\_TYPE|  
|m\_bIsGrantable|IS\_GRANTABLE|  
  
## Requisitos  
 **Header:** atldbsch.h  
  
## Consulte também  
 [Classe CRestrictions](../Topic/CRestrictions%20Class.md)