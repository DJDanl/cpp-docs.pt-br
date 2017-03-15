---
title: "IRowsetUpdateImpl::Undo | Microsoft Docs"
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
  - "ATL.IRowsetUpdateImpl.Undo"
  - "ATL::IRowsetUpdateImpl::Undo"
  - "IRowsetUpdateImpl::Undo"
  - "IRowsetUpdateImpl.Undo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Undo"
ms.assetid: f3dc7764-050c-4322-9b2f-9ca772a0fb88
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# IRowsetUpdateImpl::Undo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Desfaz todas as alterações na linha desde que a busca ou a última atualização.  
  
## Sintaxe  
  
```  
  
      STDMETHOD ( Undo )(  
   HCHAPTER /* hReserved */,  
   DBCOUNTITEM cRows,  
   const HROW rghRows[ ],  
   DBCOUNTITEM* pcRowsUndone,  
   HROW** prgRowsUndone,  
   DBROWSTATUS** prgRowStatus   
);  
```  
  
#### Parâmetros  
 `hReserved`  
 \[in\] corresponde ao parâmetro de `hChapter` em [IRowsetUpdate::Undo](https://msdn.microsoft.com/en-us/library/ms719655.aspx).  
  
 *pcRowsUndone*  
 \[out\] corresponde ao parâmetro de `pcRows` em [IRowsetUpdate::Undo](https://msdn.microsoft.com/en-us/library/ms719655.aspx).  
  
 *prgRowsUndone*  
 \[in\] corresponde ao parâmetro *de prgRows* em [IRowsetUpdate::Undo](https://msdn.microsoft.com/en-us/library/ms719655.aspx).  
  
 Para outros parâmetros, consulte [IRowsetUpdate::Undo](https://msdn.microsoft.com/en-us/library/ms719655.aspx)*na referência do programador de OLE DB*.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe IRowsetUpdateImpl](../Topic/IRowsetUpdateImpl%20Class.md)