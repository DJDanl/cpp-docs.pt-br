---
title: IRowsetImpl::RefRows | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 9aa841444f9cfa2758e8d5a8d8d4ec831a531d6f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33101546"
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