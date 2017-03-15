---
title: "CCommand::Prepare | Microsoft Docs"
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
  - "CCommand.Prepare"
  - "CCommand::Prepare"
  - "Prepare"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Prepare"
ms.assetid: f0e473fc-2f7a-4d29-96c2-1328dc21e702
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CCommand::Prepare
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Valida e otimiza o comando atual.  
  
## Sintaxe  
  
```  
  
      HRESULT CCommandBase::Prepare(  
   ULONG cExpectedRuns = 0   
) throw( );  
```  
  
#### Parâmetros  
 *cExpectedRuns*  
 \[in\] o número de vezes que você espera executar o comando.  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Comentários  
 Esse método envolve o método [ICommandPrepare::Prepare](https://msdn.microsoft.com/en-us/library/ms718370.aspx)OLE DB.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CCommand](../../data/oledb/ccommand-class.md)