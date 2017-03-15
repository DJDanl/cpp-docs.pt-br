---
title: "Classe CArrayRowset | Microsoft Docs"
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
  - "ATL.CArrayRowset<TAccessor>"
  - "ATL.CArrayRowset"
  - "CArrayRowset"
  - "ATL::CArrayRowset"
  - "ATL::CArrayRowset<TAccessor>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CArrayRowset"
ms.assetid: 511427e1-73ca-4fd8-9ba1-ae9463557cb6
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CArrayRowset
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Acessa os elementos de um conjunto de linhas usando a sintaxe da matriz.  
  
## Sintaxe  
  
```  
template < class TAccessor >  
class CArrayRowset :   
   public CVirtualBuffer <TAccessor>,   
   protected CBulkRowset <TAccessor>  
```  
  
#### Parâmetros  
 `TAccessor`  
 O tipo de classe do acessador que você deseja que o conjunto de linhas para usar.  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[CArrayRowset](../../data/oledb/carrayrowset-carrayrowset.md)|Construtor.|  
|[Instantâneo](../../data/oledb/carrayrowset-snapshot.md)|Lê o conjunto de linhas inteiro na memória.|  
  
### Operadores  
  
|||  
|-|-|  
|[Operador &#91;&#93;](../Topic/CArrayRowset::operator.md)|Acessa um elemento do conjunto de linhas.|  
  
### Membros de dados  
  
|||  
|-|-|  
|[CArrayRowset::m\_nRowsRead](../../data/oledb/carrayrowset-m-nrowsread.md)|O número de linhas já lido.|  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência dos modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md)   
 [Classe CRowset](../Topic/CRowset%20Class.md)