---
title: 'Método EventSource: | Microsoft Docs'
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
ms.openlocfilehash: 92af8746b4d2b5ba2f379cc8660b5345b2c5f175
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33873232"
---
# <a name="eventsourceadd-method"></a>Método EventSource::Add
Anexa o manipulador de eventos representado pela interface delegado especificado para o conjunto de manipuladores de eventos para o objeto de EventSource atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
HRESULT Add(  
   _In_ TDelegateInterface* delegateInterface,  
   _Out_ EventRegistrationToken* token  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `delegateInterface`  
 A interface para um objeto de representante, que representa um manipulador de eventos.  
  
 `token`  
 Quando essa operação for concluída, um identificador que representa o evento. Usar esse token como parâmetro para o [remove](../windows/eventsource-remove-method.md) método para descartar o manipulador de eventos.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, o HRESULT que indica o erro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft::WRL
 
 ## <a name="see-also"></a>Consulte também
 [Classe EventSource](../windows/eventsource-class.md)