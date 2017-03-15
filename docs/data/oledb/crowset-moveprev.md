---
title: "CRowset::MovePrev | Microsoft Docs"
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
  - "CRowset<TAccessor>.MovePrev"
  - "CRowset.MovePrev"
  - "MovePrev"
  - "CRowset::MovePrev"
  - "ATL.CRowset.MovePrev"
  - "ATL::CRowset<TAccessor>::MovePrev"
  - "ATL::CRowset::MovePrev"
  - "ATL.CRowset<TAccessor>.MovePrev"
  - "CRowset<TAccessor>::MovePrev"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método MovePrev"
ms.assetid: 7ced2bfb-f556-40fc-97ea-0d4e7213e114
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CRowset::MovePrev
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Move o cursor para o registro anterior.  
  
## Sintaxe  
  
```  
  
HRESULT MovePrev( ) throw( );  
  
```  
  
## Valor de retorno  
 Um padrão `HRESULT`.  
  
## Comentários  
 Este método requer que você defina **DBPROP\_CANFETCHBACKWARDS** ou **DBPROP\_CANSCROLLBACKWARDS** para `VARIANT_TRUE` antes de chamar **Abrir** na tabela ou que contém o conjunto de linhas de comando.  
  
## Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## Consulte também  
 [Classe CRowset](../Topic/CRowset%20Class.md)   
 [CRowset::MoveNext](../../data/oledb/crowset-movenext.md)   
 [CRowset::MoveToBookmark](../../data/oledb/crowset-movetobookmark.md)   
 [CRowset::MoveLast](../../data/oledb/crowset-movelast.md)