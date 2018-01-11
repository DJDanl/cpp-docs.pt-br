---
title: "Método: Putoncomplete | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: async/Microsoft::WRL::AsyncBase::PutOnComplete
dev_langs: C++
helpviewer_keywords: PutOnComplete method
ms.assetid: 1c469ff9-b2df-4637-bf05-01a617043149
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5ceda6a67053fb3d90dff1796c47c753b51f72e6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="asyncbaseputoncomplete-method"></a>Método AsyncBase::PutOnComplete
Define o endereço do manipulador de eventos de conclusão para o valor especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
STDMETHOD(  
   PutOnComplete  
)(TComplete* completeHandler);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `completeHandler`  
 O endereço para o qual o manipulador de eventos de conclusão é definido.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, E_ILLEGAL_METHOD_CALL.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)