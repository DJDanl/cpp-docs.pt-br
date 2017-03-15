---
title: "CBookmark::operator = | Microsoft Docs"
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
  - "CBookmark<0>::operator="
  - "CBookmark<0>.operator="
  - "ATL.CBookmark.operator="
  - "CBookmark::operator="
  - "ATL.CBookmark<0>.operator="
  - "ATL::CBookmark<0>::operator="
  - "CBookmark.operator="
  - "ATL::CBookmark::operator="
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador =, com modelos OLE DB"
  - "Operador =, indicadores"
  - "operator=, indicadores"
ms.assetid: 23805af4-aedd-47ad-bef4-21d902463797
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CBookmark::operator =
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Atribui um objeto de `CBookmark` para outro.  
  
## Sintaxe  
  
```  
  
      CBookmark& operator =(   
   const CBookmark& bookmark    
) throw( );  
```  
  
## Comentários  
 Esse operador é necessário apenas em **CBookmark\<0\>**.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CBookmark](../../data/oledb/cbookmark-class.md)