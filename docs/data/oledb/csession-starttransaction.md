---
title: 'Csession:: Starttransaction | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CSession::StartTransaction
- StartTransaction
- ATL.CSession.StartTransaction
- CSession.StartTransaction
- ATL::CSession::StartTransaction
dev_langs:
- C++
helpviewer_keywords:
- StartTransaction method
ms.assetid: cd7bd2be-fad1-4e2b-932b-79d308efb8fb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: cddd3596befcba1e409d0f1575796438ee8c7011
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="csessionstarttransaction"></a>CSession::StartTransaction
Inicia uma nova transação para esta sessão.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT StartTransaction(ISOLEVEL isoLevel = ISOLATIONLEVEL_READCOMMITTED,  
   ULONG isoFlags = 0,  
   ITransactionOptions* pOtherOptions = NULL,  
   ULONG* pulTransactionLevel = NULL) const throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Consulte [itransactionlocal:: Starttransaction](https://msdn.microsoft.com/en-us/library/ms709786.aspx) no *referência do programador de OLE DB*.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [itransactionlocal:: Starttransaction](https://msdn.microsoft.com/en-us/library/ms709786.aspx) no *referência do programador de DB OLE*.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CSession](../../data/oledb/csession-class.md)