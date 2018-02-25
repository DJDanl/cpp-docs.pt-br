---
title: IRowsetImpl::RefRows | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::IRowsetImpl::RefRows
- ATL.IRowsetImpl.RefRows
- IRowsetImpl.RefRows
- RefRows
- IRowsetImpl::RefRows
dev_langs:
- C++
helpviewer_keywords:
- RefRows method
ms.assetid: 1c048a2a-65dc-4bba-9c81-a23c0dc249c8
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: db2ae7e068f3c253e546274dbdfe693889a06504
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="irowsetimplrefrows"></a>IRowsetImpl::RefRows
Chamado pelo [AddRefRows](../../data/oledb/irowsetimpl-addrefrows.md) e [ReleaseRows](../../data/oledb/irowsetimpl-releaserows.md) para incrementar ou liberar uma contagem de referência para um identificador de linha existente.  
  
## <a name="syntax"></a>Sintaxe  
  
```
HRESULT RefRows(DBCOUNTITEM cRows,  
   const HROWrghRows[],  
   DBREFCOUNT rgRefCounts[],  
   DBROWSTATUS rgRowStatus[],  
   BOOL bAdd);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Consulte [IRowset::AddRefRows](https://msdn.microsoft.com/en-us/library/ms719619.aspx) no *referência do programador de OLE DB*.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IRowsetImpl](../../data/oledb/irowsetimpl-class.md)   
 [Classe CSimpleRow](../../data/oledb/csimplerow-class.md)