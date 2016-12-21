---
title: "CSimpleRow::Compare | Microsoft Docs"
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
  - "CSimpleRow.Compare"
  - "CSimpleRow::Compare"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método compare"
ms.assetid: 0bb65f09-c7bc-449b-aa4e-c828cac13510
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CSimpleRow::Compare
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Compara duas linhas para ver se elas se referem à mesma instância de linha.  
  
## Sintaxe  
  
```  
  
      HRESULT Compare(   
   CSimpleRow* pRow    
);  
```  
  
#### Parâmetros  
 `pRow`  
 Um ponteiro para um objeto de `CSimpleRow` .  
  
## Valor de retorno  
 Um valor de `HRESULT` , geralmente `S_OK`, indicando as duas linhas é a mesma instância de linha, ou **S\_FALSE**, indicando as duas linhas é diferente.  Consulte [IRowsetIdentity::IsSameRow](https://msdn.microsoft.com/en-us/library/ms719629.aspx)*na referência do programador de OLE DB* para outros valores de retorno possíveis.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe CSimpleRow](../Topic/CSimpleRow%20Class.md)   
 [CSimpleRow::ReleaseRow](../Topic/CSimpleRow::ReleaseRow.md)   
 [IRowsetImpl::RefRows](../../data/oledb/irowsetimpl-refrows.md)