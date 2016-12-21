---
title: "CUsagePrivileges, CUsagePrivilegeInfo | Microsoft Docs"
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
  - "m_szObjectCatalog"
  - "CUsagePrivilegeInfo"
  - "m_bIsGrantable"
  - "OBJECT_NAME"
  - "m_szPrivilegeType"
  - "OBJECT_SCHEMA"
  - "IS_GRANTABLE"
  - "CUsagePrivileges"
  - "m_szGrantor"
  - "GRANTOR"
  - "GRANTEE"
  - "m_szObjectSchema"
  - "OBJECT_CATALOG"
  - "m_szObjectType"
  - "m_szObjectName"
  - "m_szGrantee"
  - "OBJECT_TYPE"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de parâmetro CUsagePrivilegeInfo"
  - "Classe CUsagePrivileges (typedef)"
  - "GRANTEE"
  - "GRANTOR"
  - "IS_GRANTABLE"
  - "m_bIsGrantable"
  - "m_szGrantee"
  - "m_szGrantor"
  - "m_szObjectCatalog"
  - "m_szObjectName"
  - "m_szObjectSchema"
  - "m_szObjectType"
  - "m_szPrivilegeType"
  - "OBJECT_CATALOG"
  - "OBJECT_NAME"
  - "OBJECT_SCHEMA"
  - "OBJECT_TYPE"
ms.assetid: 09460e7f-3947-4837-ad1e-407b94acedb8
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CUsagePrivileges, CUsagePrivilegeInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Chame a classe **CUsagePrivileges** do typedef para implementar a sua classe **CUsagePrivilegeInfo**do parâmetro.  
  
## Comentários  
 Consulte [Classes do conjunto de linhas de esquema e classes de Typedef](../Topic/Schema%20Rowset%20Classes%20and%20Typedef%20Classes.md) para obter mais informações sobre como usar classes do typedef.  
  
 Essa classe identifica os privilégios de PLAN nos objetos definidos no catálogo ao qual está disponível ou concedido por um determinado usuário.  
  
 A tabela a seguir lista os membros de dados da classe e suas colunas correspondentes OLE DB.  Consulte [Conjunto de linhas de USAGE\_PRIVILEGES](https://msdn.microsoft.com/en-us/library/ms722743.aspx)*na referência do programador de OLE DB* para obter mais informações sobre o esquema e de colunas.  
  
|Membros de dados|Colunas de OLE DB|  
|----------------------|-----------------------|  
|m\_szGrantor|GRANTOR|  
|m\_szGrantee|GRANTEE|  
|m\_szObjectCatalog|OBJECT\_CATALOG|  
|m\_szObjectSchema|OBJECT\_SCHEMA|  
|m\_szObjectName|OBJECT\_NAME|  
|m\_szObjectType|OBJECT\_TYPE|  
|m\_szPrivilegeType|PRIVILEGE\_TYPE|  
|m\_bIsGrantable|IS\_GRANTABLE|  
  
## Requisitos  
 **Header:** atldbsch.h  
  
## Consulte também  
 [Classe CRestrictions](../Topic/CRestrictions%20Class.md)