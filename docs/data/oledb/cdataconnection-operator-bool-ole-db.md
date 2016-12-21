---
title: "CDataConnection::operator bool (banco de dados OLE) | Microsoft Docs"
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
ms.assetid: e0791faf-2ed2-4dbb-9e68-3b9b5da2b7a7
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDataConnection::operator bool (banco de dados OLE)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determina se a sessão atual será aberta ou não.  
  
## Sintaxe  
  
```  
  
operator bool( ) throw( );  
  
```  
  
## Comentários  
 Retorna um valor de `bool` \(tipo de dados do C\+\+\).  **true** significa que a sessão atual está aberta; **false** significa que a sessão atual está fechada.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDataConnection](../../data/oledb/cdataconnection-class.md)   
 [CDataConnection::operator BOOL](../../data/oledb/cdataconnection-operator-bool.md)