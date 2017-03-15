---
title: "IDBCreateCommandImpl::CreateCommand | Microsoft Docs"
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
  - "IDBCreateCommandImpl.CreateCommand"
  - "CreateCommand"
  - "IDBCreateCommandImpl::CreateCommand"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método CreateCommand"
ms.assetid: 50ffbf8b-2c07-4bcb-96c5-ffce4519c7f7
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# IDBCreateCommandImpl::CreateCommand
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Cria um novo comando e retorna a interface solicitada.  
  
## Sintaxe  
  
```  
  
      STDMETHOD(CreateCommand)(   
   IUnknown * pUnkOuter,   
   REFIID riid,   
   IUnknown ** ppvCommand    
);  
```  
  
#### Parâmetros  
 Consulte [IDBCreateCommand::CreateCommand](https://msdn.microsoft.com/en-us/library/ms709772.aspx)*na referência do programador de OLE DB*.  
  
 Alguns parâmetros correspondem aos *parâmetros de referência do programador de OLE DB* os nomes diferentes, que são descritos em **IDBCreateCommand::CreateCommand**:  
  
|Parâmetros do modelo de OLE DB|*Os parâmetros de referência do programador de OLE DB*|  
|------------------------------------|------------------------------------------------------------|  
|*ppvCommand*|*ppCommand*|  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe IDBCreateCommandImpl](../../data/oledb/idbcreatecommandimpl-class.md)