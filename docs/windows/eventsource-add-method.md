---
title: 'Método EventSource:: Add | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::EventSource::Add
dev_langs:
- C++
helpviewer_keywords:
- Add method
ms.assetid: 8bded85b-929e-4425-a464-e5de67bb774c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 65e8576f069cce7d7aec2eae18ad577820ca93a4
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39644736"
---
# <a name="eventsourceadd-method"></a>Método EventSource::Add
Acrescenta o manipulador de eventos representado pela interface delegado especificado ao conjunto de manipuladores de eventos para o atual **EventSource** objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
HRESULT Add(  
   _In_ TDelegateInterface* delegateInterface,  
   _Out_ EventRegistrationToken* token  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *delegateInterface*  
 A interface para um objeto delegado, que representa um manipulador de eventos.  
  
 *token*  
 Quando essa operação for concluída, um identificador que representa o evento. Usar esse token como o parâmetro para o [remove ()](../windows/eventsource-remove-method.md) método para descartar o manipulador de eventos.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Event. h  
  
 **Namespace:** Microsoft::WRL
 
 ## <a name="see-also"></a>Consulte também
 [Classe EventSource](../windows/eventsource-class.md)