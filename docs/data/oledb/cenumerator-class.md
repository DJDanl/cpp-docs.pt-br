---
title: "Classe CEnumerator | Microsoft Docs"
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
  - "CEnumerator"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CEnumerator"
ms.assetid: 25805f1b-26e3-402f-af83-1b5fe5ddebf7
caps.latest.revision: 14
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CEnumerator
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usa um objeto de enumerador do OLE DB, que expõe a interface de [ISourcesRowset](https://msdn.microsoft.com/en-us/library/ms715969.aspx) para retornar um conjunto de linhas que descreve todas as fontes de dados e enumeradores.  
  
## Sintaxe  
  
```  
class CEnumerator :   
   public CAccessorRowset< CAccessor <CEnumeratorAccessor >>  
```  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[Localizar](../Topic/CEnumerator::Find.md)|Pesquisas por meio dos provedores disponíveis \(fontes de dados\) que procuram um com o nome especificado.|  
|[GetMoniker](../../data/oledb/cenumerator-getmoniker.md)|Recupera a interface de `IMoniker` para o registro atual.|  
|[Abrir](../Topic/CEnumerator::Open.md)|Abre o enumerador.|  
  
## Comentários  
 Você pode recuperar os dados de **ISourcesRowset** indiretamente dessa classe.  
  
## Requisitos  
 **Header:**atldbcli.h  
  
## Consulte também  
 [DBViewer](../../top/visual-cpp-samples.md)   
 [Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência dos modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md)