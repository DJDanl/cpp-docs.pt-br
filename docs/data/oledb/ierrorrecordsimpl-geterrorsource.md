---
title: 'Ierrorrecordsimpl:: Geterrorsource | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- IErrorRecordsImpl.GetErrorSource
- GetErrorSource
- IErrorRecordsImpl::GetErrorSource
dev_langs:
- C++
helpviewer_keywords:
- GetErrorSource method
ms.assetid: 5436f1ce-c5a4-403b-a62b-c58e70e5c925
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: f076bb7c7d436e65473aadb197a90eae51b07fd4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33100376"
---
# <a name="ierrorrecordsimplgeterrorsource"></a>IErrorRecordsImpl::GetErrorSource
Obtém o código-fonte que causou o erro de um registro de erro.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      LPOLESTR GetErrorSource(ERRORINFO& rCurError);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `rCurError`  
 Um `ERRORINFO` registro em um **IErrorInfo** interface.  
  
## <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma cadeia de caracteres que contém o código-fonte para o erro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IErrorRecordsImpl](../../data/oledb/ierrorrecordsimpl-class.md)