---
title: IErrorRecordsImpl::GetErrorInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- GetErrorInfo
- IErrorRecordsImpl.GetErrorInfo
- IErrorRecordsImpl::GetErrorInfo
dev_langs:
- C++
helpviewer_keywords:
- GetErrorInfo method
ms.assetid: 44d0872f-f25f-4102-8f7f-a2cfb3eeb1a0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 20b9cfd0998a0cf3814ca8d5b1d96e7b95565f00
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33100441"
---
# <a name="ierrorrecordsimplgeterrorinfo"></a>IErrorRecordsImpl::GetErrorInfo
Retorna um [IErrorInfo](https://msdn.microsoft.com/en-us/library/ms718112.aspx) ponteiro de interface do registro especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      STDMETHOD(GetErrorInfo )(ULONG ulRecordNum,  
   LCID lcid,  
   IErrorInfo **ppErrorInfo);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Consulte [IErrorRecords::GetErrorInfo](https://msdn.microsoft.com/en-us/library/ms711230.aspx) no *referência do programador de OLE DB*.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IErrorRecordsImpl](../../data/oledb/ierrorrecordsimpl-class.md)