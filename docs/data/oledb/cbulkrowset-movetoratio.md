---
title: "CBulkRowset::MoveToRatio | Microsoft Docs"
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
  - "CBulkRowset.MoveToRatio"
  - "ATL::CBulkRowset::MoveToRatio"
  - "MoveToRatio"
  - "CBulkRowset::MoveToRatio"
  - "ATL.CBulkRowset<TAccessor>.MoveToRatio"
  - "ATL::CBulkRowset<TAccessor>::MoveToRatio"
  - "ATL.CBulkRowset.MoveToRatio"
  - "CBulkRowset<TAccessor>::MoveToRatio"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método MoveToRatio"
ms.assetid: 86be60f5-9341-44c1-8e1e-9174c082d0d5
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CBulkRowset::MoveToRatio
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Buscar linhas a partir de uma posição fracionário no conjunto de linhas.  
  
## Sintaxe  
  
```  
  
      HRESULT MoveToRatio(  
   DBCOUNTITEM nNumerator,  
   DBCOUNTITEM nDenominator   
) throw( );  
```  
  
#### Parâmetros  
 `nNumerator`  
 \[in\] o numerador usado para determinar a posição fracionária de que buscar dados.  
  
 `nDenominator`  
 \[in\] o denominador usado para determinar a posição fracionária de que buscar dados.  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Comentários  
 `MoveToRatio` busca as linhas aproximadamente de acordo com a seguinte fórmula:  
  
 `( nNumerator *  RowsetSize ) / nDenominator`  
  
 Onde `RowsetSize` é o tamanho do conjunto de linhas, medido nas linhas.  A precisão dessa fórmula depende do provedor específico.  Para obter detalhes, consulte [IRowsetScroll::GetRowsAtRatio](https://msdn.microsoft.com/en-us/library/ms709602.aspx)*na referência do programador de OLE DB*.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CBulkRowset](../Topic/CBulkRowset%20Class.md)