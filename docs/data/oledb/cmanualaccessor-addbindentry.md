---
title: "CManualAccessor::AddBindEntry | Microsoft Docs"
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
  - "ATL::CManualAccessor::AddBindEntry"
  - "ATL.CManualAccessor.AddBindEntry"
  - "CManualAccessor::AddBindEntry"
  - "AddBindEntry"
  - "CManualAccessor.AddBindEntry"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método AddBindEntry"
ms.assetid: 8556dda9-dda1-4f67-96bc-6031e6c6a271
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CManualAccessor::AddBindEntry
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Adiciona uma entrada de associação para as colunas de saída.  
  
## Sintaxe  
  
```  
  
      void AddBindEntry(  
   DBORDINAL nOrdinal,  
   DBTYPE wType,  
   DBLENGTH nColumnSize,  
   void* pData,  
   void* pLength = NULL,  
   void* pStatus = NULL   
) throw ( );  
```  
  
#### Parâmetros  
 Consulte [DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx)*na referência do programador de OLE DB*.  
  
 `nOrdinal`  
 \[in\] número da coluna.  
  
 `wType`  
 \[in\] tipo de dados.  
  
 `nColumnSize`  
 \[in\] tamanho da coluna em bytes.  
  
 `pData`  
 \[in\] ponteiro da os dados da coluna são armazenadas no buffer.  
  
 `pLength`  
 \[in\] ponteiro do tamanho do campo, se necessário.  
  
 `pStatus`  
 \[in\] ponteiro da variável a ser associado ao status da coluna, se necessário.  
  
## Comentários  
 Para usar essa função, você deve primeiro chamar [CreateAccessor](../Topic/CManualAccessor::CreateAccessor.md).  Você não pode adicionar mais entradas do que o número de colunas especificado em `CreateAccessor`.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CManualAccessor](../Topic/CManualAccessor%20Class.md)   
 [Exemplo de DBViewer](../../top/visual-cpp-samples.md)