---
title: "CDynamicParameterAccessor::SetParamStatus | Microsoft Docs"
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
  - "CDynamicParameterAccessor::SetParamStatus"
  - "ATL.CDynamicParameterAccessor.SetParamStatus"
  - "ATL::CDynamicParameterAccessor::SetParamStatus"
  - "CDynamicParameterAccessor.SetParamStatus"
  - "SetParamStatus"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método SetParamStatus"
ms.assetid: 0c2271f6-457d-46ca-88b7-4590aadb20d7
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDynamicParameterAccessor::SetParamStatus
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define o status do parâmetro especificado armazenado no buffer.  
  
## Sintaxe  
  
```  
  
      bool SetParamStatus(  
   DBORDINAL nParam,  
   DBSTATUS status  
);  
```  
  
#### Parâmetros  
 `nParam`  
 \[in\] o número do parâmetro \(deslocamento de 1\).  O parâmetro 0 é reservado para valores de retorno.  O número do parâmetro for o índice do parâmetro com base na ordem de SQL ou na chamada do procedimento armazenado.  Consulte [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.  
  
 *status*  
 \[in\] o status de `DBSTATUS` do parâmetro especificado.  Para obter informações sobre valores de `DBSTATUS` , consulte [Status](https://msdn.microsoft.com/en-us/library/ms722617.aspx)*na referência do programador do*OLE DB, ou na pesquisa de `DBSTATUS` em oledb.h.  
  
## Comentários  
 Retorna **true** no êxito ou **false** a falha.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)