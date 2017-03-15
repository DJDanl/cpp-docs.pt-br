---
title: "ICommandTextImpl::GetCommandText | Microsoft Docs"
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
  - "GetCommandText"
  - "ICommandTextImpl.GetCommandText"
  - "ICommandTextImpl::GetCommandText"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetCommandText"
ms.assetid: 0f8da470-b1c3-4573-974f-1acc111e3984
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# ICommandTextImpl::GetCommandText
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna o comando de texto definido pela última chamada a [SetCommandText](../../data/oledb/icommandtextimpl-setcommandtext.md).  
  
## Sintaxe  
  
```  
  
      STDMETHOD(GetCommandText)(   
   GUID * pguidDialect,   
   LPOLESTR * ppwszCommand    
);  
```  
  
#### Parâmetros  
 Consulte [ICommandText::GetCommandText](https://msdn.microsoft.com/en-us/library/ms709825.aspx)*na referência do programador de OLE DB*.  O parâmetro *de pguidDialect* é ignorado por padrão.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe ICommandTextImpl](../../data/oledb/icommandtextimpl-class.md)