---
title: "CDataConnection::operator BOOL | Microsoft Docs"
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
  - "CDataConnection::operatorBOOL"
  - "ATL::CDataConnection::operatorBOOL"
  - "CDataConnection.operatorBOOL"
  - "ATL.CDataConnection.operatorBOOL"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador BOOL"
  - "Operador bool"
ms.assetid: ad0bea7f-61ff-47f7-8127-32a31e3e9b9d
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDataConnection::operator BOOL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determina se a sessão atual será aberta ou não.  
  
## Sintaxe  
  
```  
  
operator BOOL( ) throw( );  
  
```  
  
## Comentários  
 Valor de **BOOL** de retorna o typedef \(MFC\).  **Verdadeiro** significa que a sessão atual está aberta; **Falso** significa que a sessão atual está fechada.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDataConnection](../../data/oledb/cdataconnection-class.md)   
 [Bool CDataConnection::operator](../../data/oledb/cdataconnection-operator-bool-ole-db.md)