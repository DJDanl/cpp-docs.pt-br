---
title: "CSession::Commit | Microsoft Docs"
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
  - "CSession.Commit"
  - "ATL.CSession.Commit"
  - "ATL::CSession::Commit"
  - "CSession::Commit"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Commit"
ms.assetid: 1d5f56b9-000c-4bae-a975-89d3452f499f
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CSession::Commit
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Confirma a transação.  
  
## Sintaxe  
  
```  
  
      HRESULT Commit(   
   BOOL bRetaining = FALSE,   
   DWORD grfTC = XACTTC_SYNC,   
   DWORD grfRM = 0    
) const throw( );  
```  
  
#### Parâmetros  
 Consulte [ITransaction::Commit](https://msdn.microsoft.com/en-us/library/ms713008.aspx)*na referência do programador de OLE DB*.  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Comentários  
 Para obter mais informações, consulte [ITransaction::Commit](https://msdn.microsoft.com/en-us/library/ms713008.aspx).  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CSession](../../data/oledb/csession-class.md)