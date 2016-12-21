---
title: "IRowsetUpdateImpl::Update | Microsoft Docs"
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
  - "ATL::IRowsetUpdateImpl::Update"
  - "IRowsetUpdateImpl::Update"
  - "IRowsetUpdateImpl.Update"
  - "ATL.IRowsetUpdateImpl.Update"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Update"
ms.assetid: 9ec6884d-aa9c-4871-a803-c048f162403c
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# IRowsetUpdateImpl::Update
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Passa todas as alterações feitas na linha desde que a busca ou a última atualização.  
  
## Sintaxe  
  
```  
  
      STDMETHOD ( Update )(  
   HCHAPTER /* hReserved */,  
   DBCOUNTITEM cRows,  
   const HROW rghRows[],  
   DBCOUNTITEM* pcRows,  
   HROW** prgRows,  
   DBROWSTATUS** prgRowStatus   
);  
```  
  
#### Parâmetros  
 `hReserved`  
 \[in\] corresponde ao parâmetro de `hChapter` em [IRowsetUpdate::Update](https://msdn.microsoft.com/en-us/library/ms719709.aspx).  
  
 Para outros parâmetros, consulte [IRowsetUpdate::Update](https://msdn.microsoft.com/en-us/library/ms719709.aspx)*na referência do programador de OLE DB*.  
  
## Comentários  
 As alterações são transmitidas chamando [IRowsetChangeImpl::FlushData](../../data/oledb/irowsetchangeimpl-flushdata.md).  O consumidor deve chamar [CRowset::Update](../Topic/CRowset::Update.md) para que as alterações entrem em vigor.  Definir *o prgRowstatus* a um valor apropriado conforme descrito em [Estados de linha](https://msdn.microsoft.com/en-us/library/ms722752.aspx)*na referência do programador de OLE DB*.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe IRowsetUpdateImpl](../Topic/IRowsetUpdateImpl%20Class.md)