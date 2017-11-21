---
title: "Método Asyncbase: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: async/Microsoft::WRL::AsyncBase::get_Status
dev_langs: C++
helpviewer_keywords: get_Status method
ms.assetid: 9823ecb9-212e-471d-b76f-7b8f21208905
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: f7ac7e7a42d0cde4507f812a270548acfb5a69e6
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="asyncbasegetstatus-method"></a>Método AsyncBase::get_Status
Recupera um valor que indica o status da operação assíncrona.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
STDMETHOD(  
   get_Status  
)(AsyncStatus *status) override;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `status`  
 O local em que o status a ser armazenado. Para obter mais informações, consulte a enumeração Windows::Foundation::AsyncStatus.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, E_ILLEGAL_METHOD_CALL.  
  
## <a name="remarks"></a>Comentários  
 Esse método implementa IAsyncInfo::get_Status.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)