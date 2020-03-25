---
title: Classe AgileEventSource
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::AgileEventSource
helpviewer_keywords:
- AgileEventSource class
ms.openlocfilehash: 71a70f783d8f8967d755bb788f4aae4861340d64
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214182"
---
# <a name="agileeventsource-class"></a>Classe AgileEventSource

Representa um evento que é gerado por um componente ágil, que é um componente que pode ser acessado de qualquer thread. Herda de [EventSource](eventsource-class.md) e substitui a função de membro `Add` por um parâmetro de tipo adicional para especificar opções de como invocar o evento Agile.

## <a name="syntax"></a>Sintaxe

```cpp
template<
    typename TDelegateInterface,
    typename TEventSourceOptions = Microsoft::WRL::InvokeModeOptions<FireAll>
>
class AgileEventSource :
    public Microsoft::WRL::EventSource<
        TDelegateInterface, TEventSourceOptions>;
```

## <a name="parameters"></a>parâmetros

*TDelegateInterface*<br/>
A interface para um delegado que representa um manipulador de eventos.

*TEventSourceOptions*<br/>
Uma estrutura [InvokeModeOptions](invokemodeoptions-structure.md) cujo campo invokemode é definido como `InvokeMode::StopOnFirstError` ou `InvokeMode::FireAll`.

## <a name="remarks"></a>Comentários

A grande maioria dos componentes no Windows Runtime são componentes ágeis. Para obter mais informações, consulte [Threading e marshaling (C++/CX)](../../cppcx/threading-and-marshaling-c-cx.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`EventSource`

`AgileEventSource`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Event. h

**Namespace:** Microsoft:: WRL

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Método AgileEventSource:: Add](#add)|Acrescenta o manipulador de eventos Agile representado pela interface de delegação especificada ao conjunto de manipuladores de eventos para o objeto **AgileEventSource** atual.|

## <a name="agileeventsourceadd-method"></a><a name="add"></a>Método AgileEventSource:: Add

Acrescenta o manipulador de eventos representado pela interface de representante especificada ao conjunto de manipuladores de eventos para o objeto [EventSource](eventsource-class.md) atual.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Add(
   _In_ TDelegateInterface* delegateInterface,
   _Out_ EventRegistrationToken* token
);
```

### <a name="parameters"></a>parâmetros

*delegateInterface*<br/>
A interface para um objeto delegado, que representa um manipulador de eventos.

*token*<br/>
Quando essa operação for concluída, um identificador que representa o evento. Use esse token como o parâmetro para o método `Remove()` para descartar o manipulador de eventos.

### <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, um HRESULT que indica o erro.

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)
