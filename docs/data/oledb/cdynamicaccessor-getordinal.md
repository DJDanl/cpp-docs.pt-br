---
title: "CDynamicAccessor::GetOrdinal | Microsoft Docs"
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
  - "CDynamicAccessor.GetOrdinal"
  - "ATL::CDynamicAccessor::GetOrdinal"
  - "CDynamicAccessor::GetOrdinal"
  - "ATL.CDynamicAccessor.GetOrdinal"
  - "GetOrdinal"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetOrdinal"
ms.assetid: 2095b71c-a7a4-4034-89a1-77a78cb9633f
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDynamicAccessor::GetOrdinal
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Recupera o número de coluna recebe um nome de coluna.  
  
## Sintaxe  
  
```  
  
      bool GetOrdinal(  
   const CHAR* pColumnName,  
   DBORDINAL* pOrdinal   
) const throw( );  
bool GetOrdinal(  
   const WCHAR* pColumnName,  
   DBORDINAL* pOrdinal   
) const throw( );  
```  
  
#### Parâmetros  
 `pColumnName`  
 \[in\] de ponteiro para uma cadeia de caracteres que contém o nome da coluna.  
  
 *pOrdinal*  
 \[out\] ponteiro da o número da coluna.  
  
## Valor de retorno  
 Retorna **true** se uma coluna com o nome especificado for encontrada.  Caso contrário, essa função retornará **false**.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)