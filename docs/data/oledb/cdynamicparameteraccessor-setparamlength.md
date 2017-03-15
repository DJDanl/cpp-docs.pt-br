---
title: "CDynamicParameterAccessor::SetParamLength | Microsoft Docs"
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
  - "ATL::CDynamicParameterAccessor::SetParamLength"
  - "CDynamicParameterAccessor.SetParamLength"
  - "ATL.CDynamicParameterAccessor.SetParamLength"
  - "CDynamicParameterAccessor::SetParamLength"
  - "SetParamLength"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método SetParamLength"
ms.assetid: d8e0bbfe-e1ae-4a8f-9567-584fbb0c8385
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDynamicParameterAccessor::SetParamLength
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define o comprimento do parâmetro especificado armazenado no buffer.  
  
## Sintaxe  
  
```  
  
      bool SetParamLength(  
   DBORDINAL nParam,  
   DBLENGTH length  
);  
```  
  
#### Parâmetros  
 `nParam`  
 \[in\] o número do parâmetro \(deslocamento de 1\).  O parâmetro 0 é reservado para valores de retorno.  O número do parâmetro for o índice do parâmetro com base na ordem de SQL ou na chamada do procedimento armazenado.  Consulte [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.  
  
 *length*  
 \[in\] o tamanho em bytes do parâmetro especificado.  
  
## Comentários  
 Retorna **true** no êxito ou **false** a falha.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)