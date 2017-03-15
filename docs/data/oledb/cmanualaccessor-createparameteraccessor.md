---
title: "CManualAccessor::CreateParameterAccessor | Microsoft Docs"
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
  - "ATL::CManualAccessor::CreateParameterAccessor"
  - "ATL.CManualAccessor.CreateParameterAccessor"
  - "CManualAccessor.CreateParameterAccessor"
  - "CreateParameterAccessor"
  - "CManualAccessor::CreateParameterAccessor"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método CreateParameterAccessor"
ms.assetid: d0a2095b-b37c-4472-accc-45ef365a18c8
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CManualAccessor::CreateParameterAccessor
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Aloca memória para o associar ao parâmetro estrutura e inicializa os membros de dados do parâmetro.  
  
## Sintaxe  
  
```  
  
      HRESULT CreateParameterAccessor(   
   int nBindEntries,   
   void* pBuffer,   
   DBLENGTH nBufferSize    
) throw( );  
```  
  
#### Parâmetros  
 `nBindEntries`  
 \[in\] número de colunas.  
  
 `pBuffer`  
 \[in\] ponteiro do buffer em que as colunas de entrada são armazenadas.  
  
 `nBufferSize`  
 \[in\] o tamanho do buffer em bytes.  
  
## Valor de retorno  
 Um dos valores padrão de `HRESULT` .  
  
## Comentários  
 Você deve chamar essa função antes de chamar [AddParameterEntry](../Topic/CManualAccessor::AddParameterEntry.md).  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CManualAccessor](../Topic/CManualAccessor%20Class.md)   
 [CManualAccessor::CreateAccessor](../Topic/CManualAccessor::CreateAccessor.md)   
 [CManualAccessor::AddParameterEntry](../Topic/CManualAccessor::AddParameterEntry.md)