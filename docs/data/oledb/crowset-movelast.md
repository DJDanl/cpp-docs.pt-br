---
title: "CRowset::MoveLast | Microsoft Docs"
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
  - "ATL::CRowset<TAccessor>::MoveLast"
  - "CRowset<TAccessor>::MoveLast"
  - "ATL.CRowset.MoveLast"
  - "ATL::CRowset::MoveLast"
  - "CRowset<TAccessor>.MoveLast"
  - "MoveLast"
  - "CRowset::MoveLast"
  - "ATL.CRowset<TAccessor>.MoveLast"
  - "CRowset.MoveLast"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método MoveLast"
ms.assetid: 81063578-ae9d-467b-8c88-81d8fc66e020
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CRowset::MoveLast
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Move o cursor até a última linha.  
  
## Sintaxe  
  
```  
  
HRESULT MoveLast( ) throw( );  
  
```  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Comentários  
 As chamadas para [IRowset::RestartPosition](https://msdn.microsoft.com/en-us/library/ms712877.aspx) reposicionar o local da próxima busca à última posição e recuperam a última linha.  
  
 Esse método exige que você **DBPROP\_CANSCROLLBACKWARDS** definido como `VARIANT_TRUE` antes de chamar **Abrir** na tabela ou o comando que contém o conjunto de linhas. \(Para melhor desempenho, você também pode definir **DBPROP\_QUICKRESTART** a `VARIANT_TRUE`.\)  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CRowset](../Topic/CRowset%20Class.md)   
 [CRowset::MoveNext](../../data/oledb/crowset-movenext.md)   
 [IRowset::RestartPosition](https://msdn.microsoft.com/en-us/library/ms712877.aspx)   
 [CRowset::MovePrev](../../data/oledb/crowset-moveprev.md)