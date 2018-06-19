---
title: IRowsetImpl::AddRefRows | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- IRowsetImpl::AddRefRows
- AddRefRows
- IRowsetImpl.AddRefRows
- ATL::IRowsetImpl::AddRefRows
- ATL.IRowsetImpl.AddRefRows
dev_langs:
- C++
helpviewer_keywords:
- AddRefRows method
ms.assetid: adc0989b-7592-432e-82d9-df4445431531
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 687ee3630e5ba579f40ace30ca32ac0ed9fc16fc
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33102287"
---
# <a name="irowsetimpladdrefrows"></a>IRowsetImpl::AddRefRows
Adiciona uma contagem de referência em um identificador de linha existente.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      STDMETHOD(AddRefRows )(DBCOUNTITEM cRows,  
   const HROW rghRows[],  
   DBREFCOUNT rgRefCounts[],  
   DBROWSTATUS rgRowStatus[]);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Consulte [IRowset::AddRefRows](https://msdn.microsoft.com/en-us/library/ms719619.aspx) no *referência do programador de OLE DB*.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IRowsetImpl](../../data/oledb/irowsetimpl-class.md)   
 [IRowsetImpl::RefRows](../../data/oledb/irowsetimpl-refrows.md)   
 [IRowsetImpl::GetNextRows](../../data/oledb/irowsetimpl-getnextrows.md)   
 [IRowsetImpl::ReleaseRows](../../data/oledb/irowsetimpl-releaserows.md)