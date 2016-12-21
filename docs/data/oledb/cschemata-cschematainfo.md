---
title: "CSchemata, CSchemataInfo | Microsoft Docs"
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
  - "DEFAULT_CHARACTER_SET_CATALOG"
  - "DEFAULT_CHARACTER_SET_SCHEMA"
  - "m_szCharName"
  - "CSchemataInfo"
  - "m_szCatalog"
  - "m_szCharCatalog"
  - "m_szOwner"
  - "m_szCharSchema"
  - "CSchemata"
  - "m_szName"
  - "DEFAULT_CHARACTER_SET_NAME"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe typedef CSchemata"
  - "Classe de parâmetro CSchemataInfo"
  - "DEFAULT_CHARACTER_SET_CATALOG"
  - "DEFAULT_CHARACTER_SET_NAME"
  - "DEFAULT_CHARACTER_SET_SCHEMA"
  - "m_szCatalog"
  - "m_szCharCatalog"
  - "m_szCharName"
  - "m_szCharSchema"
  - "m_szName"
  - "m_szOwner"
ms.assetid: 9d06d65a-c27b-446d-bc42-c7e487b0d9c5
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CSchemata, CSchemataInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Chame a classe **CSchemata** do typedef para implementar a sua classe **CSchemataInfo**do parâmetro.  
  
## Comentários  
 Consulte [Classes do conjunto de linhas de esquema e classes de Typedef](../Topic/Schema%20Rowset%20Classes%20and%20Typedef%20Classes.md) para obter mais informações sobre como usar classes do typedef.  
  
 Essa classe identifica os esquemas que são de propriedade de um determinado usuário.  
  
 A tabela a seguir lista os membros de dados da classe e suas colunas correspondentes OLE DB.  Consulte [Conjunto de linhas SCHEMATA](https://msdn.microsoft.com/en-us/library/ms716887.aspx)*na referência do programador de OLE DB* para obter mais informações sobre o esquema e de colunas.  
  
|Membros de dados|Colunas de OLE DB|  
|----------------------|-----------------------|  
|m\_szCatalog|CATALOG\_NAME|  
|m\_szName|SCHEMA\_NAME|  
|m\_szOwner|SCHEMA\_OWNER|  
|m\_szCharCatalog|DEFAULT\_CHARACTER\_SET\_CATALOG|  
|m\_szCharSchema|DEFAULT\_CHARACTER\_SET\_SCHEMA|  
|m\_szCharName|DEFAULT\_CHARACTER\_SET\_NAME|  
  
## Requisitos  
 **Header:** atldbsch.h  
  
## Consulte também  
 [Classe CRestrictions](../Topic/CRestrictions%20Class.md)