---
title: "Classe CAccessorBase | Microsoft Docs"
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
  - "CAccessorBase"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CAccessorBase"
ms.assetid: 389b65be-11ca-4ae0-9290-60c621c4982b
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CAccessorBase
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Todos os acessadores em modelos OLE DB derivam dessa classe.  `CAccessorBase` permite que um conjunto de linhas gerencia vários acessadores.  O também fornece a associação de parâmetros e colunas de saída.  
  
## Sintaxe  
  
```  
// Replace with syntax  
```  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[Fechar](../../data/oledb/caccessorbase-close.md)|Fecha os acessadores.|  
|[GetHAccessor](../../data/oledb/caccessorbase-gethaccessor.md)|Recupera o identificador do acessador.|  
|[GetNumAccessors](../../data/oledb/caccessorbase-getnumaccessors.md)|Recupera o número de acessadores criados pela classe.|  
|[IsAutoAccessor](../../data/oledb/caccessorbase-isautoaccessor.md)|Testa se o acessador especificado é um autoaccessor.|  
|[ReleaseAccessors](../../data/oledb/caccessorbase-releaseaccessors.md)|Libera os acessadores.|  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência dos modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md)