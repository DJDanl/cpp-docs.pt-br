---
title: "Classe CNoMultipleResults | Microsoft Docs"
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
  - "CNoMultipleResults"
  - "ATL.CNoMultipleResults"
  - "ATL::CNoMultipleResults"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CNoMultipleResults"
ms.assetid: 343e77c4-b319-476e-b592-901ab9b2f34e
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CNoMultipleResults
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usado como um argumento de modelo \(*TMultiple*\) a [CCommand](../../data/oledb/ccommand-class.md) para criar um comando otimizado que manipula um único conjunto de resultados.  
  
## Sintaxe  
  
```  
class CNoMultipleResults  
```  
  
## Comentários  
 Se você desejar um comando tratar vários conjuntos de resultados, use [CMultipleResults](../../data/oledb/cmultipleresults-class.md) em vez disso.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência dos modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md)