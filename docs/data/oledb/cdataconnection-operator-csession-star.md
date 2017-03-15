---
title: "CDataConnection::operator CSession* | Microsoft Docs"
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
  - "CDataConnection.operatorCSession*"
  - "CDataConnection::operatorCSession*"
  - "operatorCSession*"
  - "CSession*"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador CSession*"
  - "Operador CSession*"
ms.assetid: 0b0feede-5c3e-4835-be5b-03651597014d
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDataConnection::operator CSession*
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna um ponteiro para o objeto contido de `CSession` .  
  
## Sintaxe  
  
```  
  
operator const CSession*() throw( );  
  
```  
  
## Comentários  
 Esse operador retorna um ponteiro para o objeto contido de `CSession` , permitindo que você transmita um objeto de `CDataConnection` onde um ponteiro de `CSession` é esperado.  
  
## Exemplo  
 Consulte [operador CSession&](../../data/oledb/cdataconnection-operator-csession-amp.md) para obter um exemplo de uso.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDataConnection](../../data/oledb/cdataconnection-class.md)   
 [CDataConnection::operator CSession&](../../data/oledb/cdataconnection-operator-csession-amp.md)