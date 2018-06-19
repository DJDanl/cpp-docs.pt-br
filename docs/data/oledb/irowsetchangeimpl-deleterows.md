---
title: IRowsetChangeImpl::DeleteRows | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL.IRowsetChangeImpl.DeleteRows
- ATL::IRowsetChangeImpl::DeleteRows
- IRowsetChangeImpl.DeleteRows
- DeleteRows
- IRowsetChangeImpl::DeleteRows
dev_langs:
- C++
helpviewer_keywords:
- DeleteRows method
ms.assetid: 462ad4f1-3b2a-4134-9733-be65708aa1d9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 6b8c8f361166d90d62aeec911aa0fd1df90b68af
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33101091"
---
# <a name="irowsetchangeimpldeleterows"></a>IRowsetChangeImpl::DeleteRows
Exclui linhas do conjunto de linhas.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      STDMETHOD (DeleteRows )(HCHAPTER /* hReserved */,  
   DBCOUNTITEM cRows,  
   const HROW rghRows[],  
   DBROWSTATUS rgRowStatus[]);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Consulte [IRowsetChange:: DeleteRows](https://msdn.microsoft.com/en-us/library/ms724362.aspx) no *referência do programador de OLE DB*.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IRowsetChangeImpl](../../data/oledb/irowsetchangeimpl-class.md)