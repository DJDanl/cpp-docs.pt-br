---
title: "PROVIDER_COLUMN_ENTRY | Microsoft Docs"
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
  - "PROVIDER_COLUMN_ENTRY"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro PROVIDER_COLUMN_ENTRY"
ms.assetid: 7921cfc1-aa9c-493e-8fc4-9d4294cafe72
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# PROVIDER_COLUMN_ENTRY
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa uma coluna específica com suporte do provedor.  
  
## Sintaxe  
  
```  
  
PROVIDER_COLUMN_ENTRY (  
name  
, ordinal, member )  
```  
  
#### Parâmetros  
 *nome*  
 \[in\] o nome da coluna.  
  
 `ordinal`  
 \[in\] o número da coluna.  A menos que a coluna é uma coluna do indicador, o número da coluna não deve ser 0.  
  
 `member`  
 \[in\] a variável de membro em `dataClass` que corresponde à coluna.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Macros para modelos de provedor de banco de dados OLE](../../data/oledb/macros-for-ole-db-provider-templates.md)   
 [Modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)   
 [Criando um provedor de banco de dados OLE](../../data/oledb/creating-an-ole-db-provider.md)