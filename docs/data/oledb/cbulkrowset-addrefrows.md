---
title: "CBulkRowset::AddRefRows | Microsoft Docs"
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
  - "CBulkRowset::AddRefRows"
  - "AddRefRows"
  - "CBulkRowset.AddRefRows"
  - "ATL.CBulkRowset<TAccessor>.AddRefRows"
  - "ATL::CBulkRowset::AddRefRows"
  - "CBulkRowset<TAccessor>::AddRefRows"
  - "ATL.CBulkRowset.AddRefRows"
  - "ATL::CBulkRowset<TAccessor>::AddRefRows"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método AddRefRows"
ms.assetid: 014be991-50f8-4377-ba16-fec80b54b406
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CBulkRowset::AddRefRows
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Chamadas [IRowset::AddRefRows](https://msdn.microsoft.com/en-us/library/ms719619.aspx) para incrementar a contagem de referência para todas as linhas recuperadas no momento do conjunto de linhas em massa.  
  
## Sintaxe  
  
```  
  
HRESULT AddRefRows( ) throw( );  
  
```  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CBulkRowset](../Topic/CBulkRowset%20Class.md)   
 [CBulkRowset::ReleaseRows](../Topic/CBulkRowset::ReleaseRows.md)