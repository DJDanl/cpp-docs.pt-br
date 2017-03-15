---
title: "CDynamicAccessor::GetStatus | Microsoft Docs"
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
  - "ATL::CDynamicAccessor::GetStatus"
  - "CDynamicAccessor.GetStatus"
  - "ATL.CDynamicAccessor.GetStatus"
  - "CDynamicAccessor::GetStatus"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetStatus"
ms.assetid: 8f1aba69-5c2c-4ca7-ad84-7b4b27995eb8
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDynamicAccessor::GetStatus
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Recupera o status da coluna especificada.  
  
## Sintaxe  
  
```  
  
      bool GetStatus(   
   DBORDINAL nColumn,   
   DBSTATUS* pStatus    
) const throw( );  
bool GetStatus(  
   const CHAR* pColumnName,  
   DBSTATUS* pStatus   
) const throw( );  
bool GetStatus(  
   const WCHAR* pColumnName,  
   DBSTATUS* pStatus   
) const throw( );  
```  
  
#### Parâmetros  
 `nColumn`  
 \[in\] o número da coluna.  Início dos números de coluna com 1.  Um valor de 0 se refere à coluna do indicador, se houver.  
  
 `pColumnName`  
 \[in\] de ponteiro para uma cadeia de caracteres que contém o nome da coluna.  
  
 `pStatus`  
 \[out\] ponteiro da variável que contém o status da coluna.  Consulte [DBSTATUS](https://msdn.microsoft.com/en-us/library/ms722617.aspx)*na referência do programador de OLE DB* para obter mais informações.  
  
## Valor de retorno  
 Retorna **true** se a coluna especificada for encontrada.  Caso contrário, essa função retornará **false**.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)   
 [CDynamicAccessor::SetStatus](../Topic/CDynamicAccessor::SetStatus.md)