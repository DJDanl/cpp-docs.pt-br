---
title: 'Irowsetimpl:: Addrefrows | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- IRowsetImpl::AddRefRows
- AddRefRows
- IRowsetImpl.AddRefRows
- ATL::IRowsetImpl::AddRefRows
- ATL.IRowsetImpl.AddRefRows
dev_langs: C++
helpviewer_keywords: AddRefRows method
ms.assetid: adc0989b-7592-432e-82d9-df4445431531
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: b890d549b6173982d4b63885f0a4ea5bf16e0007
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="irowsetimpladdrefrows"></a>IRowsetImpl::AddRefRows
Adiciona uma contagem de referência para um identificador de linha existente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      STDMETHOD( AddRefRows )(  
   DBCOUNTITEM cRows,  
   const HROW rghRows[],  
   DBREFCOUNT rgRefCounts[],  
   DBROWSTATUS rgRowStatus[]   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Consulte [IRowset::AddRefRows](https://msdn.microsoft.com/en-us/library/ms719619.aspx) no *referência do programador de OLE DB*.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IRowsetImpl](../../data/oledb/irowsetimpl-class.md)   
 [Irowsetimpl:: Refrows](../../data/oledb/irowsetimpl-refrows.md)   
 [Irowsetimpl:: GetNextRows](../../data/oledb/irowsetimpl-getnextrows.md)   
 [IRowsetImpl::ReleaseRows](../../data/oledb/irowsetimpl-releaserows.md)