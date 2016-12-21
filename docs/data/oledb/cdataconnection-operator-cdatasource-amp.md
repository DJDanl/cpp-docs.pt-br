---
title: "CDataConnection::operator CDataSource&amp; | Microsoft Docs"
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
  - "CDataSource&"
  - "CDataConnection.operatorCDataSource&"
  - "operatorCDataSource&"
  - "CDataConnection::operatorCDataSource&"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador CDataSource&"
  - "Operador & (CDataSource)"
ms.assetid: 852faeee-f1b1-4465-9828-b261d1edf022
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDataConnection::operator CDataSource&amp;
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna uma referência ao objeto contido de `CDataSource` .  
  
## Sintaxe  
  
```  
  
operator const CDataSource&() throw( );  
  
```  
  
## Comentários  
 Esse operador retorna uma referência ao objeto contido de `CDataSource` , permitindo que você transmita um objeto de `CDataConnection` onde uma referência de `CDataSource` é esperada.  
  
## Exemplo  
 Se você tiver uma função \(como `func` abaixo\) que utiliza uma referência de `CDataSource` , você pode usar **CDataSource&** para passar em vez de um objeto de `CDataConnection` .  
  
 [!code-cpp[NVC_OLEDB_Consumer#3](../../data/oledb/codesnippet/CPP/cdataconnection-operator-cdatasource-amp_1.cpp)]  
  
 [!code-cpp[NVC_OLEDB_Consumer#4](../../data/oledb/codesnippet/CPP/cdataconnection-operator-cdatasource-amp_2.cpp)]  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDataConnection](../../data/oledb/cdataconnection-class.md)   
 [CDataConnection::operator CDataSource\*](../Topic/CDataConnection::operator%20CDataSource*.md)