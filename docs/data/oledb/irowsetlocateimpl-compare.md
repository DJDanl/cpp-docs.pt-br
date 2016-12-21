---
title: "IRowsetLocateImpl::Compare | Microsoft Docs"
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
  - "ATL.IRowsetLocateImpl.Compare"
  - "IRowsetLocateImpl::Compare"
  - "IRowsetLocateImpl.Compare"
  - "ATL::IRowsetLocateImpl::Compare"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método compare"
ms.assetid: 6f84052c-c68c-480a-982f-03748faa7d5d
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# IRowsetLocateImpl::Compare
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Compara dois medidores.  
  
## Sintaxe  
  
```  
  
      STDMETHOD ( Compare )(  
   HCHAPTER /* hReserved */,  
   DBBKMARK cbBookmark1,  
   const BYTE* pBookmark1,  
   DBBKMARK cbBookmark2,  
   const BYTE* pBookmark2,  
   DBCOMPARE* pComparison   
);  
```  
  
#### Parâmetros  
 Consulte [IRowsetLocate::Compare](https://msdn.microsoft.com/en-us/library/ms709539.aspx)*na referência do programador de OLE DB*.  
  
## Comentários  
 Qualquer um dos indicadores pode ser definido [indexador padrão](https://msdn.microsoft.com/en-us/library/ms712954.aspx) db\-library OLE padrão \(**DBBMK\_FIRST**, **DBBMK\_LAST**, ou **DBBMK\_INVALID**\).  O valor retornado em `pComparison` indica a relação entre os dois medidores:  
  
-   **DBCOMPARE\_LT** \(`cbBookmark1` é antes de `cbBookmark2`.\)  
  
-   **DBCOMPARE\_EQ** \(`cbBookmark1` é igual a `cbBookmark2`.\)  
  
-   **DBCOMPARE\_GT** \(`cbBookmark1` está depois de `cbBookmark2`.\)  
  
-   **DBCOMPARE\_NE** \(indicadores são iguais e não ordenados.\)  
  
-   **DBCOMPARE\_NOTCOMPARABLE** \(os indicadores não podem ser comparados.\)  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe IRowsetLocateImpl](../../data/oledb/irowsetlocateimpl-class.md)