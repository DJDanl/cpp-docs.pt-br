---
title: Classe AgileEventSource
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::AgileEventSource
- event/Microsoft::WRL::InvokeModeOptions
helpviewer_keywords:
- AgileEventSource class
ms.openlocfilehash: fa1e0a72d865b2993e149f6e4d2b57fe13463a61
ms.sourcegitcommit: b8c22e6d555cf833510753cba7a368d57e5886db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/29/2020
ms.locfileid: "76821734"
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

## <a name="parameters"></a>Parâmetros

*TDelegateInterface*<br/>
A interface para um delegado que representa um manipulador de eventos.

*TEventSourceOptions*<br/>
Uma estrutura [InvokeModeOptions](invokemodeoptions-structure.md) cujo campo invokemode é definido como `InvokeMode::StopOnFirstError` ou `InvokeMode::FireAll`.

## <a name="remarks"></a>Comentários

A grande maioria dos componentes no Windows Runtime são componentes ágeis. Para obter mais informações, consulte [Threading e marshaling (C++/CX)](../../cppcx/threading-and-marshaling-c-cx.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de Herança

`EventSource`

`AgileEventSource`

## <a name="requirements"></a>Requisitos do

**Cabeçalho:** Event. h

**Namespace:** Microsoft::WRL

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Name|Descrição|
|----------|-----------------|
|[Método AgileEventSource:: Add](#add)|Acrescenta o manipulador de eventos Agile representado pela interface de delegação especificada ao conjunto de manipuladores de eventos para o objeto **AgileEventSource** atual.|

## <a name="add"></a>Método AgileEventSource:: Add

Acrescenta o manipulador de eventos representado pela interface de representante especificada ao conjunto de manipuladores de eventos para o objeto [EventSource](eventsource-class.md) atual.

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
Quando essa operação for concluída, um identificador que representa o evento. Use esse token como o parâmetro para o método `Remove()` para descartar o manipulador de eventos.

### <a name="return-value"></a>Valor de retorno

S_OK se for bem-sucedido; caso contrário, um HRESULT que indica o erro.

## <a name="see-also"></a>Veja também

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)