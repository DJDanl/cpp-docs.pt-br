---
title: "CViews, CViewInfo | Microsoft Docs"
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
  - "m_bCheckOption"
  - "CViews"
  - "CHECK_OPTION"
  - "CViewInfo"
  - "m_szTableCatalog"
  - "IS_UPDATABLE"
  - "m_szDefinition"
  - "m_szTableName"
  - "m_bIsUpdatable"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "CHECK_OPTION"
  - "Classe de parâmetro CViewInfo"
  - "Classe typedef CViews"
  - "Membro de dados de classe DESCRIPTION"
  - "IS_UPDATABLE"
  - "m_bCheckOption"
  - "m_bIsUpdatable"
  - "m_szDefinition"
  - "m_szDescription"
  - "m_szTableCatalog"
  - "m_szTableName"
  - "m_szTableSchema"
  - "TABLE_CATALOG"
  - "TABLE_NAME"
  - "TABLE_SCHEMA"
ms.assetid: ad864181-4fab-4919-b0fd-45df5da230d9
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CViews, CViewInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Chame a classe **CViews** do typedef para implementar a sua classe **CViewInfo**do parâmetro.  
  
## Comentários  
 Consulte [Classes do conjunto de linhas de esquema e classes de Typedef](../Topic/Schema%20Rowset%20Classes%20and%20Typedef%20Classes.md) para obter mais informações sobre como usar classes do typedef.  
  
 Essa classe identifica as tabelas em que as tabelas exibidas, definidas no catálogo e que são propriedade de um determinado usuário, são dependentes.  
  
 A tabela a seguir lista os membros de dados da classe e suas colunas correspondentes OLE DB.  Consulte [Conjunto de linhas VIEWS](https://msdn.microsoft.com/en-us/library/ms723122.aspx)*na referência do programador de OLE DB* para obter mais informações sobre o esquema e de colunas.  
  
|Membros de dados|Colunas de OLE DB|  
|----------------------|-----------------------|  
|m\_szTableCatalog|TABLE\_CATALOG|  
|m\_szTableSchema|TABLE\_SCHEMA|  
|m\_szTableName|TABLE\_NAME|  
|m\_szDefinition|VIEW\_DEFINITION|  
|m\_bCheckOption|CHECK\_OPTION|  
|m\_bIsUpdatable|IS\_UPDATABLE|  
|m\_szDescription|DESCRIÇÃO|  
  
## Requisitos  
 **Header:** atldbsch.h  
  
## Consulte também  
 [Classe CRestrictions](../Topic/CRestrictions%20Class.md)