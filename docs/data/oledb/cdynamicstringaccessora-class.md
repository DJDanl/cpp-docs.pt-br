---
title: "Classe CDynamicStringAccessorA | Microsoft Docs"
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
  - "CDynamicStringAccessorA"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CDynamicStringAccessorA"
ms.assetid: ed0d9821-a655-41f1-a902-43c3042ac49c
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CDynamicStringAccessorA
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Permite acessar uma fonte de dados quando você não tem conhecimento do esquema de base de dados \(estrutura subjacente\).  
  
## Sintaxe  
  
```  
typedef CDynamicStringAccessorT<CHAR, DBTYPE_STR> CDynamicStringAccessorA;  
```  
  
## Comentários  
 Eles ambos solicitação que a busca do provedor todos os dados acessados no repositório de dados como dados de cadeia de caracteres, mas dados de cadeia de caracteres ANSI de solicitações de `CDynamicStringAccessor` .  
  
 `CDynamicStringAccessorA` herda **GetString** e `SetString` de `CDynamicStringAccessor`.  Quando você usa esses métodos em `CDynamicStringAccessorA` objeto, ***BaseType*** são **CHAR**.  
  
## Requisitos  
 **Cabeçalho**: atldbcli.h  
  
## Consulte também  
 [Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência dos modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md)   
 [Classe CAccessor](../Topic/CAccessor%20Class.md)   
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)   
 [Classe CManualAccessor](../Topic/CManualAccessor%20Class.md)   
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)   
 [Classe CDynamicStringAccessor](../../data/oledb/cdynamicstringaccessor-class.md)