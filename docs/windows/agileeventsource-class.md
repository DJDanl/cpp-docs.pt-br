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
ms.openlocfilehash: 4f8ef724c78bdc61ef470199fbb5e956e374493f
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46405226"
---
# <a name="agileeventsource-class"></a>Classe AgileEventSource

Representa um evento que é gerado por um componente do agile, que é um componente que pode ser acessado de qualquer thread. Herda de [EventSource](eventsource-class.md) e substitui o `Add` função membro com um parâmetro de tipo adicionais para especificar opções chamar o evento agile.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename TDelegateInterface, typename TEventSourceOptions = Microsoft::WRL::InvokeModeOptions<FireAll>>
class AgileEventSource
    : public Microsoft::WRL::EventSource<TDelegateInterface, TEventSourceOptions>;
```

## <a name="parameters"></a>Parâmetros

*TDelegateInterface*<br/>
A interface para um delegado que representa um manipulador de eventos.

*TEventSourceOptions*<br/>
Uma [InvokeModeOptions](invokemodeoptions-structure.md) estrutura cujo campo invokeMode é definido como `InvokeMode::StopOnFirstError` ou `InvokeMode::FireAll`.

## <a name="remarks"></a>Comentários

A grande maioria dos componentes em tempo de execução do Windows são componentes agile. Para obter mais informações, consulte [Threading e Marshaling (C + + c++ /CX)](../cppcx/threading-and-marshaling-c-cx.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`EventSource`

`AgileEventSource`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Event. h

**Namespace:** Microsoft::WRL

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[Método AgileEventSource::Add](#add)|Acrescenta o manipulador de eventos agile representado pela interface delegado especificado ao conjunto de manipuladores de eventos para o atual **AgileEventSource** objeto.|

## <a name="add"></a> Método AgileEventSource::Add

Acrescenta o manipulador de eventos representado pela interface delegado especificado ao conjunto de manipuladores de eventos para o atual [EventSource](eventsource-class.md) objeto.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Add(
   _In_ TDelegateInterface* delegateInterface,
   _Out_ EventRegistrationToken* token
);
```

### <a name="parameters"></a>Parâmetros

*delegateInterface*<br/>
A interface para um objeto delegado, que representa um manipulador de eventos.

*token*<br/>
Quando essa operação for concluída, um identificador que representa o evento. Usar esse token como o parâmetro para o `Remove()` método para descartar o manipulador de eventos.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.


## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)