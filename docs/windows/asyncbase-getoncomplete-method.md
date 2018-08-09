---
title: 'Método asyncbase:: Getoncomplete | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::AsyncBase::GetOnComplete
dev_langs:
- C++
helpviewer_keywords:
- GetOnComplete method
ms.assetid: f06ae02d-9a88-41d2-b749-bdc1a7ff8748
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ffe517b75df4e1cdd8172279c12256db940f0980
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39647031"
---
# <a name="asyncbasegetoncomplete-method"></a>Método AsyncBase::GetOnComplete
Copia o endereço do manipulador de eventos de conclusão atual para a variável especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
STDMETHOD(  
   GetOnComplete  
)(TComplete** completeHandler);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *completeHandler*  
 O local em que o endereço do manipulador de eventos de conclusão atual é armazenado.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, E_ILLEGAL_METHOD_CALL.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)