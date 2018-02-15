---
title: CDBErrorInfo::GetCustomErrorObject | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CDBErrorInfo::GetCustomErrorObject
- ATL.CDBErrorInfo.GetCustomErrorObject
- CDBErrorInfo.GetCustomErrorObject
- ATL::CDBErrorInfo::GetCustomErrorObject
- GetCustomErrorObject
dev_langs:
- C++
helpviewer_keywords:
- GetCustomErrorObject method
ms.assetid: 295c053c-b76c-47a5-adfb-333e65d2df0d
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 5b951e0748f8fcf6a8697f273a46a38472e81cfd
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="cdberrorinfogetcustomerrorobject"></a>CDBErrorInfo::GetCustomErrorObject
Chamadas [IErrorRecords::GetCustomErrorObject](https://msdn.microsoft.com/en-us/library/ms725417.aspx) para retornar um ponteiro para uma interface em um objeto de erro personalizada.  
  
## <a name="syntax"></a>Sintaxe  
  
```
HRESULT GetCustomErrorObject(ULONG ulRecordNum,   
   REFIID riid,IUnknown** ppObject) const throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Consulte [IErrorRecords::GetCustomErrorObject](https://msdn.microsoft.com/en-us/library/ms725417.aspx) no *referência do programador de OLE DB*.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDBErrorInfo](../../data/oledb/cdberrorinfo-class.md)