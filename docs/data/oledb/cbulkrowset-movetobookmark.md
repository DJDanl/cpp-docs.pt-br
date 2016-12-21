---
title: "CBulkRowset::MoveToBookmark | Microsoft Docs"
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
  - "CBulkRowset<TAccessor>::MoveToBookmark"
  - "CBulkRowset.MoveToBookmark"
  - "MoveToBookmark"
  - "ATL.CBulkRowset.MoveToBookmark"
  - "CBulkRowset::MoveToBookmark"
  - "ATL::CBulkRowset<TAccessor>::MoveToBookmark"
  - "ATL::CBulkRowset::MoveToBookmark"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método MoveToBookmark"
ms.assetid: 76aab025-819e-4ecd-ae0a-d8d3fb2d2099
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CBulkRowset::MoveToBookmark
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Busca a linha marcada por um medidor ou a linha em um deslocamento especificado \(`lSkip`\) desse indicador.  
  
## Sintaxe  
  
```  
  
      HRESULT MoveToBookmark(  
   const CBookmarkBase& bookmark,  
   DBCOUNTITEM lSkip = 0   
) throw( );  
```  
  
#### Parâmetros  
 `bookmark`  
 \[in\] indicador de que marca o local do qual você deseja buscar dados.  
  
 `lSkip`  
 \[in\] a contagem do número de linhas de indicador à linha de destino.  Se `lSkip` for zero, a primeira linha buscada será a linha com indicador.  Se `lSkip` for 1, a primeira linha buscada será a linha após a linha com indicador.  Se `lSkip` será – 1, a primeira linha buscada está a linha antes da linha com indicador.  
  
## Valor de retorno  
 Consulte [IRowset::GetData](https://msdn.microsoft.com/en-us/library/ms716988.aspx)*na referência do programador de OLE DB*.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CBulkRowset](../Topic/CBulkRowset%20Class.md)