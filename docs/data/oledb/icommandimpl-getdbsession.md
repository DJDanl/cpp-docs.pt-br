---
title: "ICommandImpl::GetDBSession | Microsoft Docs"
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
  - "ICommandImpl::GetDBSession"
  - "GetDBSession"
  - "ICommandImpl.GetDBSession"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetDBSession"
ms.assetid: e5b1cb13-453f-4698-90bf-f6bfe6814a54
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# ICommandImpl::GetDBSession
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna um ponteiro de interface para a sessão que criou o comando.  
  
## Sintaxe  
  
```  
  
      STDMETHOD (GetDBSession) (  
   REFIID riid,  
   IUnknown** ppSession   
);  
```  
  
#### Parâmetros  
 Consulte [ICommand::GetDBSession](https://msdn.microsoft.com/en-us/library/ms719622.aspx)*na referência do programador de OLE DB*.  
  
## Comentários  
 Útil para recuperar as propriedades da sessão.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe ICommandImpl](../Topic/ICommandImpl%20Class.md)