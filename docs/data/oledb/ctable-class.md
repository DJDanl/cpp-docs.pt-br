---
title: "Classe CTable | Microsoft Docs"
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
  - "ATL::CTable"
  - "ATL.CTable"
  - "CTable"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CTable"
ms.assetid: f13fdaa3-e198-4557-977d-54b0bbc3454d
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CTable
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece um meio acessar diretamente um conjunto de linhas simples sem parâmetros \(um\).  
  
## Sintaxe  
  
```  
template <   
   class TAccessor = CNoAccessor,    
   template <typename T> class TRowset = CRowset    
>  
class CTable :    
   public CAccessorRowset <   
      TAccessor,    
      TRowset    
   >  
```  
  
#### Parâmetros  
 `TAccessor`  
 Uma classe do acessador.  
  
 `TRowset`  
 Uma classe do conjunto de linhas.  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[Abrir](../../data/oledb/ctable-open.md)|Abre a tabela.|  
  
## Comentários  
 Consulte [CCommand](../../data/oledb/ccommand-class.md) para obter informações sobre como executar um comando acessar um conjunto de linhas.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência dos modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md)   
 [IOpenRowset::OpenRowset](https://msdn.microsoft.com/en-us/library/ms716724.aspx)