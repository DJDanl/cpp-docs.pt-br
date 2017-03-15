---
title: "CSession::StartTransaction | Microsoft Docs"
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
  - "CSession::StartTransaction"
  - "StartTransaction"
  - "ATL.CSession.StartTransaction"
  - "CSession.StartTransaction"
  - "ATL::CSession::StartTransaction"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método StartTransaction"
ms.assetid: cd7bd2be-fad1-4e2b-932b-79d308efb8fb
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CSession::StartTransaction
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Começa uma nova transação para essa sessão.  
  
## Sintaxe  
  
```  
  
      HRESULT StartTransaction(  
   ISOLEVEL isoLevel = ISOLATIONLEVEL_READCOMMITTED,  
   ULONG isoFlags = 0,  
   ITransactionOptions* pOtherOptions = NULL,  
   ULONG* pulTransactionLevel = NULL   
) const throw( );  
```  
  
#### Parâmetros  
 Consulte [ITransactionLocal::StartTransaction](https://msdn.microsoft.com/en-us/library/ms709786.aspx)*na referência do programador de OLE DB*.  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Comentários  
 Para obter mais informações, consulte [ITransactionLocal::StartTransaction](https://msdn.microsoft.com/en-us/library/ms709786.aspx)*na referência do programador de OLE DB*.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CSession](../../data/oledb/csession-class.md)