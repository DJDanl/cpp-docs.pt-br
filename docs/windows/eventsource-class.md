---
title: Classe EventSource
ms.date: 09/12/2018
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::EventSource
- event/Microsoft::WRL::EventSource::Add
- event/Microsoft::WRL::EventSource::addRemoveLock_
- event/Microsoft::WRL::EventSource::EventSource
- event/Microsoft::WRL::EventSource::GetSize
- event/Microsoft::WRL::EventSource::InvokeAll
- event/Microsoft::WRL::EventSource::Remove
- event/Microsoft::WRL::EventSource::targets_
- event/Microsoft::WRL::EventSource::targetsPointerLock_
helpviewer_keywords:
- Microsoft::WRL::EventSource class
- Microsoft::WRL::EventSource::Add method
- Microsoft::WRL::EventSource::addRemoveLock_ data member
- Microsoft::WRL::EventSource::EventSource, constructor
- Microsoft::WRL::EventSource::GetSize method
- Microsoft::WRL::EventSource::InvokeAll method
- Microsoft::WRL::EventSource::Remove method
- Microsoft::WRL::EventSource::targets_ data member
- Microsoft::WRL::EventSource::targetsPointerLock_ data member
ms.assetid: 91f1c072-6af4-44e6-b6d8-ac6d0c688dde
ms.openlocfilehash: e9070fe756410e3e1bb1e5840eb3f06e29c2f46b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50561272"
---
# <a name="eventsource-class"></a>Classe EventSource

Representa um evento não agile. `EventSource` funções de membro, adicionar, remover e invocar manipuladores de eventos. Para eventos agile, use [AgileEventSource](agileeventsource-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
template<typename TDelegateInterface>
class EventSource;
```

### <a name="parameters"></a>Parâmetros

*TDelegateInterface*<br/>
A interface para um delegado que representa um manipulador de eventos.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

| Nome                                     | Descrição                                            |
| ---------------------------------------- | ------------------------------------------------------ |
| [EventSource:: EventSource](#eventsource) | Inicializa uma nova instância da classe `EventSource`. |

### <a name="public-methods"></a>Métodos públicos

| Nome                                 | Descrição                                                                                                                                                      |
| ------------------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [EventSource:: Add](#add)             | Acrescenta o manipulador de eventos representado pela interface delegado especificado ao conjunto de manipuladores de eventos para o atual `EventSource` objeto.                     |
| [EventSource:: GetSize](#getsize)     | Recupera o número de manipuladores de eventos associados ao atual `EventSource` objeto.                                                                         |
| [EventSource:: Invokeall](#invokeall) | Chama cada manipulador de eventos associado ao atual `EventSource` usando os argumentos e tipos de argumento especificados do objeto.                                      |
| [EventSource:: remove](#remove)       | Exclui o manipulador de eventos, representado pelo token de registro de evento especificado do conjunto de manipuladores de eventos associados ao atual `EventSource` objeto. |

### <a name="protected-data-members"></a>Membros de dados protegidos

| Nome                                                    | Descrição                                                                                                                       |
| ------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------- |
| [EventSource::addRemoveLock_](#addremovelock)           | Sincroniza o acesso para o [targets _](#targets) matriz ao adicionar, remover ou invocar manipuladores de eventos.                          |
| [EventSource::targets_](#targets)                       | Uma matriz de um ou mais manipuladores de eventos.                                                                                           |
| [EventSource::targetsPointerLock_](#targetspointerlock) | Sincroniza o acesso a membros de dados internos, mesmo quando os manipuladores de eventos para esse EventSource estão sendo adicionados, removidos ou invocado. |

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`EventSource`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Event. h

**Namespace:** Microsoft::WRL

## <a name="add"></a>EventSource:: Add

Acrescenta o manipulador de eventos representado pela interface delegado especificado ao conjunto de manipuladores de eventos para o atual `EventSource` objeto.

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
Quando essa operação for concluída, um identificador que representa o evento. Usar esse token como o parâmetro para o [remove ()](#remove) método para descartar o manipulador de eventos.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

## <a name="addremovelock"></a>EventSource::addRemoveLock_

Sincroniza o acesso para o [targets _](#targets) matriz ao adicionar, remover ou invocar manipuladores de eventos.

```cpp
Wrappers::SRWLock addRemoveLock_;
```

## <a name="eventsource"></a>EventSource:: EventSource

Inicializa uma nova instância da classe `EventSource`.

```cpp
EventSource();
```

## <a name="getsize"></a>EventSource:: GetSize

Recupera o número de manipuladores de eventos associados ao atual `EventSource` objeto.

```cpp
size_t GetSize() const;
```

### <a name="return-value"></a>Valor de retorno

O número de manipuladores de eventos em [targets _](#targets).

## <a name="invokeall"></a>EventSource:: Invokeall

Chama cada manipulador de eventos associado ao atual `EventSource` usando os argumentos e tipos de argumento especificados do objeto.

```cpp
void InvokeAll();
template <
   typename T0
>
void InvokeAll(
   T0arg0
);
template <
   typename T0,
   typename T1
>
void InvokeAll(
   T0arg0,
   T1arg1
);
template <
   typename T0,
   typename T1,
   typename T2
>
void InvokeAll(
   T0arg0,
   T1arg1,
   T2arg2
);
template <
   typename T0,
   typename T1,
   typename T2,
   typename T3
>
void InvokeAll(
   T0arg0,
   T1arg1,
   T2arg2,
   T3arg3
);
template <
   typename T0,
   typename T1,
   typename T2,
   typename T3,
   typename T4
>
void InvokeAll(
   T0arg0,
   T1arg1,
   T2arg2,
   T3arg3,
   T4arg4
);
template <
   typename T0,
   typename T1,
   typename T2,
   typename T3,
   typename T4,
   typename T5
>
void InvokeAll(
   T0arg0,
   T1arg1,
   T2arg2,
   T3arg3,
   T4arg4,
   T5arg5
);
template <
   typename T0,
   typename T1,
   typename T2,
   typename T3,
   typename T4,
   typename T5,
   typename T6
>
void InvokeAll(
   T0arg0,
   T1arg1,
   T2arg2,
   T3arg3,
   T4arg4,
   T5arg5,
   T6arg6
);
template <
   typename T0,
   typename T1,
   typename T2,
   typename T3,
   typename T4,
   typename T5,
   typename T6,
   typename T7
>
void InvokeAll(
   T0arg0,
   T1arg1,
   T2arg2,
   T3arg3,
   T4arg4,
   T5arg5,
   T6arg6,
   T7arg7
);
template <
   typename T0,
   typename T1,
   typename T2,
   typename T3,
   typename T4,
   typename T5,
   typename T6,
   typename T7,
   typename T8
>
void InvokeAll(
   T0arg0,
   T1arg1,
   T2arg2,
   T3arg3,
   T4arg4,
   T5arg5,
   T6arg6,
   T7arg7,
   T8arg8
);
template <
   typename T0,
   typename T1,
   typename T2,
   typename T3,
   typename T4,
   typename T5,
   typename T6,
   typename T7,
   typename T8,
   typename T9
>
void InvokeAll(
   T0arg0,
   T1arg1,
   T2arg2,
   T3arg3,
   T4arg4,
   T5arg5,
   T6arg6,
   T7arg7,
   T8arg8,
   T9arg9
);
```

### <a name="parameters"></a>Parâmetros

*T0*<br/>
O tipo de argumento do manipulador de evento inicial.

*T1*<br/>
O tipo do primeiro argumento do manipulador de eventos.

*T2*<br/>
O tipo do segundo argumento do manipulador de eventos.

*T3*<br/>
O tipo do terceiro argumento de manipulador de eventos.

*T4*<br/>
O tipo do quarto argumento de manipulador de eventos.

*T5*<br/>
O tipo do quinto argumento do manipulador de eventos.

*T6*<br/>
O tipo do sexto argumento do manipulador de eventos.

*T7*<br/>
O tipo do sétimo argumento do manipulador de eventos.

*T8*<br/>
O tipo de argumento do manipulador de evento oitava.

*T9*<br/>
O tipo do nono argumento do manipulador de eventos.

*arg0*<br/>
O argumento do manipulador de evento inicial.

*arg1*<br/>
O primeiro argumento de manipulador de eventos.

*Arg2*<br/>
O segundo argumento de manipulador de eventos.

*arg3*<br/>
O terceiro argumento de manipulador de eventos.

*Arg4*<br/>
O quarto argumento de manipulador de eventos.

*arg5*<br/>
O quinto argumento de manipulador de eventos.

*arg6*<br/>
O sexto argumento de manipulador de eventos.

*arg7*<br/>
O sétimo argumento de manipulador de eventos.

*arg8*<br/>
O argumento de manipulador de eventos do oitavo.

*arg9*<br/>
O nono argumento de manipulador de eventos.

## <a name="remove"></a>EventSource:: remove

Exclui o manipulador de eventos, representado pelo token de registro de evento especificado do conjunto de manipuladores de eventos associados ao atual `EventSource` objeto.

```cpp
HRESULT Remove(
   EventRegistrationToken token
);
```

### <a name="parameters"></a>Parâmetros

*token*<br/>
Um identificador que representa um manipulador de eventos. Esse token foi retornado quando o manipulador de eventos foi registrado pela [Add ()](#add) método.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o `EventRegistrationToken` estrutura, consulte a **Windows::Foundation::EventRegistrationToken estrutura** tópico no **tempo de execução do Windows** documentação de referência.

## <a name="targets"></a>EventSource::targets_

Uma matriz de um ou mais manipuladores de eventos.

```cpp
ComPtr<Details::EventTargetArray> targets_;
```

### <a name="remarks"></a>Comentários

Quando o evento que é representado por atual `EventSource` objeto ocorre, os manipuladores de eventos são chamados.

## <a name="targetspointerlock"></a>EventSource::targetsPointerLock_

Sincroniza o acesso a membros de dados internos, mesmo durante a manipuladores de eventos para este `EventSource` estão sendo adicionados, removidos ou invocado.

```cpp
Wrappers::SRWLock targetsPointerLock_;
```
