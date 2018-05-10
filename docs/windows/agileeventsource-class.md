---
title: Classe AgileEventSource | Microsoft Docs
ms.custom: ''
ms.date: 03/22/2018
ms.technology:
- cpp-windows
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
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 58eb96e3a0268d3ba70b60d9c315e935e19485f3
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="agileeventsource-class"></a>Classe AgileEventSource

Representa um evento que é gerado por um componente agile, que é um componente que pode ser acessado de qualquer thread. Herda de [EventSource](eventsource-class.md) e substitui o `Add` função membro com um parâmetro de tipo adicionais para especificar opções chamar o evento agile.

## <a name="syntax"></a>Sintaxe

```
template<typename TDelegateInterface, typename TEventSourceOptions = Microsoft::WRL::InvokeModeOptions<FireAll>>
class AgileEventSource
    : public Microsoft::WRL::EventSource<TDelegateInterface, TEventSourceOptions>;
```

## <a name="parameters"></a>Parâmetros  
 `TDelegateInterface`  

 A interface para um delegado que representa um manipulador de eventos.

 `TEventSourceOptions`  
 Um [InvokeModeOptions](invokemodeoptions-structure.md) estrutura cujo campo invokeMode é definido como `InvokeMode::StopOnFirstError` ou `InvokeMode::FireAll`.

## <a name="remarks"></a>Comentários

A maioria dos componentes em tempo de execução do Windows são componentes agile. Para obter mais informações, consulte [de Threading e Marshaling (C + + CX)](../cppcx/threading-and-marshaling-c-cx.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

 `EventSource` `AgileEventSource`

## <a name="requirements"></a>Requisitos

 **Cabeçalho:** event.h

 **Namespace:** Microsoft::WRL

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[Método AgileEventSource::Add](#add)|Anexa o manipulador de eventos agile representado pela interface delegado especificado para o conjunto de manipuladores de eventos para o objeto AgileEventSource atual.|

## <a name="add"></a> Método AgileEventSource::Add

Acrescenta o manipulador de eventos representado pela interface delegado especificado para o conjunto de manipuladores de eventos para o atual [EventSource](eventsource-class.md) objeto.

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


## <a name="see-also"></a>Consulte também

 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)
