---
title: "ICommandImpl::Execute | Microsoft Docs"
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
  - "ICommandImpl::Execute"
  - "ICommandImpl.Execute"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Execute"
ms.assetid: 033e0d4e-256b-4eed-9215-70e0bebb768c
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# ICommandImpl::Execute
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Executa o comando.  
  
## Sintaxe  
  
```  
  
      HRESULT Execute(  
   IUnknown* pUnkOuter,  
   REFIID riid,  
   DBPARAMS* pParams,  
   DBROWCOUNT* pcRowsAffected,  
   IUnknown** ppRowset   
);  
```  
  
#### Parâmetros  
 Consulte [ICommand::Execute](https://msdn.microsoft.com/en-us/library/ms718095.aspx)*na referência do programador de OLE DB*.  
  
## Comentários  
 A interface de saída será solicitada uma interface adquirida do objeto de conjunto de linhas que essa função cria.  
  
 chamadas [CreateRowset](../Topic/ICommandImpl::CreateRowset.md)de**Executar** .  Substitua a implementação padrão para criar mais de um conjunto de linhas ou para fornecer suas próprias condições para criar conjuntos de linhas diferentes.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe ICommandImpl](../Topic/ICommandImpl%20Class.md)   
 [ICommandImpl::CancelExecution](../../data/oledb/icommandimpl-cancelexecution.md)