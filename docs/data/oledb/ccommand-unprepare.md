---
title: "CCommand::Unprepare | Microsoft Docs"
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
  - "Unprepare"
  - "CCommand.Unprepare"
  - "CCommand::Unprepare"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Unprepare"
ms.assetid: 4fe59988-fe51-4c7c-a156-72b68e3d642b
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CCommand::Unprepare
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Descarta o plano de execução real do comando.  
  
## Sintaxe  
  
```  
  
HRESULT CCommandBase::Unprepare( ) throw( );  
  
```  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Comentários  
 Esse método envolve o método [ICommandPrepare::Unprepare](https://msdn.microsoft.com/en-us/library/ms719635.aspx)OLE DB.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CCommand](../../data/oledb/ccommand-class.md)