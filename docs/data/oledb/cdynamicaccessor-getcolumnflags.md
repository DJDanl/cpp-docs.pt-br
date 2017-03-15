---
title: "CDynamicAccessor::GetColumnFlags | Microsoft Docs"
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
  - "CDynamicAccessor.GetColumnFlags"
  - "ATL::CDynamicAccessor::GetColumnFlags"
  - "ATL.CDynamicAccessor.GetColumnFlags"
  - "CDynamicAccessor::GetColumnFlags"
  - "GetColumnFlags"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetColumnFlags"
ms.assetid: b2ba2f3a-2c61-4a49-abfb-75823908ccf4
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDynamicAccessor::GetColumnFlags
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Recupera as características da coluna.  
  
## Sintaxe  
  
```  
  
      bool GetColumnFlags(   
   DBORDINAL nColumn,   
   DBCOLUMNFLAGS* pFlags    
) const throw( );  
```  
  
#### Parâmetros  
 `nColumn`  
 \[in\] o número da coluna.  Início dos números de coluna com 1.  Um valor de 0 se refere à coluna do indicador, se houver.  
  
 `pFlags`  
 \[out\] ponteiro da uma máscara de bits que descreve as características da coluna.  Consulte “tipo enumerado DBCOLUMNFLAGS” em [IColumnsInfo::GetColumnInfo](https://msdn.microsoft.com/en-us/library/ms722704.aspx)*na referência do programador de OLE DB*.  
  
## Valor de retorno  
 Retorna **true** se as características da coluna são recuperadas com êxito.  Caso contrário, retornará **false**.  
  
## Comentários  
 O número da coluna é deslocado de um.  A coluna zero é um caso especial; é o indexador se disponível.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)