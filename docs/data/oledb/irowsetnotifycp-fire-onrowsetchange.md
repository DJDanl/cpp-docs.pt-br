---
title: "IRowsetNotifyCP::Fire_OnRowsetChange | Microsoft Docs"
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
  - "Fire_OnRowsetChange"
  - "IRowsetNotifyCP::Fire_OnRowsetChange"
  - "IRowsetNotifyCP.Fire_OnRowsetChange"
  - "ATL::IRowsetNotifyCP::Fire_OnRowsetChange"
  - "ATL.IRowsetNotifyCP.Fire_OnRowsetChange"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Fire_OnRowsetChange"
ms.assetid: 412a9ec2-5041-4c56-acda-dc8f8e9b35f3
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# IRowsetNotifyCP::Fire_OnRowsetChange
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Passa um evento de [OnRowsetChange](https://msdn.microsoft.com/en-us/library/ms722669.aspx) a todas as escutas no ponto de conexão **IID\_IRowsetNotify** para notificar consumidores de uma alteração que afeta todo o conjunto de linhas.  
  
## Sintaxe  
  
```  
  
      HRESULT Fire_OnRowsetChange(  
   IRowset* pRowset,  
   DBREASON eReason,  
   DBEVENTPHASE ePhase,  
   BOOL fCantDeny   
);  
```  
  
#### Parâmetros  
 Consulte [IRowsetNotify::OnRowsetChange](https://msdn.microsoft.com/en-us/library/ms722669.aspx)*na referência do programador de OLE DB*.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe IRowsetNotifyCP](../../data/oledb/irowsetnotifycp-class.md)