---
title: "CDynamicAccessor::SetLength | Microsoft Docs"
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
  - "ATL::CDynamicAccessor::SetLength"
  - "CDynamicAccessor.SetLength"
  - "CDynamicAccessor::SetLength"
  - "ATL.CDynamicAccessor.SetLength"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método SetLength"
ms.assetid: 8109ae73-04ec-4a47-be97-ba1e60080384
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDynamicAccessor::SetLength
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define o comprimento da coluna especificada.  
  
## Sintaxe  
  
```  
  
      bool SetLength(   
   DBORDINAL nColumn,   
   DBLENGTH nLength    
) throw( );  
bool SetLength(   
   const CHAR* pColumnName,   
   DBLENGTH nLength    
) throw( );  
bool SetLength(   
   const WCHAR* pColumnName,   
   DBLENGTH nLength    
) throw( );  
```  
  
#### Parâmetros  
 `nColumn`  
 \[in\] o número da coluna.  Início dos números de coluna com 1.  Um valor de 0 se refere à coluna do indicador, se houver.  
  
 `nLength`  
 \[in\] o tamanho da coluna em bytes.  
  
 `pColumnName`  
 \[in\] de ponteiro para uma cadeia de caracteres que contém o nome da coluna.  
  
## Valor de retorno  
 Retorna **true** se o comprimento da coluna especificada for definido com êxito.  Caso contrário, essa função retornará **false**.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)   
 [CDynamicAccessor::GetLength](../../data/oledb/cdynamicaccessor-getlength.md)