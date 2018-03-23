---
title: Classe AgileEventSource | Microsoft Docs
ms.custom: ''
ms.date: 03/22/2018
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::AgileEventSource
- event/Microsoft::WRL::InvokeModeOptions
dev_langs:
- C++
helpviewer_keywords:
- AgileEventSource class
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 7d025fc2be86fb5b59107d1deee39962c3c6db04
ms.sourcegitcommit: 1d11412c8f5e6ddf4edded89e0ef5097cc89f812
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/22/2018
---
# <a name="agileeventsource-class"></a>Classe AgileEventSource
Representa um evento agile. Herda de [EventSource](eventsource-class.md) e substitui o `Add` função membro com um parâmetro de tipo adicionais para especificar opções chamar o evento agile.
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename TDelegateInterface, typename TEventSourceOptions = Microsoft::WRL::InvokeModeOptions<FireAll>>
class AgileEventSource
    : public Microsoft::WRL::EventSource<TDelegateInterface, TEventSourceOptions>;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `TDelegateInterface`  
 A interface para um delegado que representa um manipulador de eventos.

 `TEventSourceOptions` Um [InvokeModeOptions](invokemodeoptions-structure.md) estrutura cujo campo invokeMode é definido como `InvokeMode::StopOnFirstError` ou `InvokeMode::FireAll`.

## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método AgileEventSource::Add](#add)|Anexa o manipulador de eventos agile representado pela interface delegado especificado para o conjunto de manipuladores de eventos para o objeto AgileEventSource atual.|  

## <a name="add"></a> Método AgileEventSource::Add

Anexa o manipulador de eventos representado pela interface delegado especificado para o conjunto de manipuladores de eventos para o objeto de EventSource atual.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Add(  
   _In_ TDelegateInterface* delegateInterface,  
   _Out_ EventRegistrationToken* token  
);
```

### <a name="parameters"></a>Parâmetros

*delegateInterface*

A interface para um objeto de representante, que representa um manipulador de eventos.

*token* quando a operação for concluída, um identificador que representa o evento. Use esse token como o parâmetro para o método Remove para descartar o manipulador de eventos.

### <a name="return-value"></a>Valor de retorno
S_OK se bem-sucedido; Caso contrário, o HRESULT que indica o erro.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `EventSource`  
 `AgileEventSource`
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)