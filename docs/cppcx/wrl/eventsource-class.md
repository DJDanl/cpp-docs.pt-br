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
ms.openlocfilehash: bb9151e55d133e3e5d8bf10baeb8448101ad6ce0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371535"
---
# <a name="eventsource-class"></a>Classe EventSource

Representa um evento não ágil. `EventSource`as funções de membro adicionam, removem e invocam manipuladores de eventos. Para eventos ágeis, use [AgileEventSource](agileeventsource-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
template<typename TDelegateInterface>
class EventSource;
```

### <a name="parameters"></a>Parâmetros

*Interface de TDelegate*<br/>
A interface para um delegado que representa um manipulador de eventos.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

| Nome                                     | Descrição                                            |
| ---------------------------------------- | ------------------------------------------------------ |
| [EventSource::EventSource](#eventsource) | Inicia uma nova instância da classe `EventSource`. |

### <a name="public-methods"></a>Métodos públicos

| Nome                                 | Descrição                                                                                                                                                      |
| ------------------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [EventSource::Add](#add)             | Anexa o manipulador de eventos representado pela interface de delegado especificada `EventSource` para o conjunto de manipuladores de eventos para o objeto atual.                     |
| [EventSource::GetSize](#getsize)     | Recupera o número de manipuladores de `EventSource` eventos associados ao objeto atual.                                                                         |
| [EventSource::InvokeAll](#invokeall) | Chama cada manipulador de `EventSource` eventos associado ao objeto atual usando os tipos e argumentos de argumento especificados.                                      |
| [EventSource::Remove](#remove)       | Exclui o manipulador de eventos representado pelo token de registro de evento `EventSource` especificado do conjunto de manipuladores de eventos associados ao objeto atual. |

### <a name="protected-data-members"></a>Membros de Dados Protegidos

| Nome                                                    | Descrição                                                                                                                       |
| ------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------- |
| [EventSource::addRemoveLock_](#addremovelock)           | Sincroniza o acesso à [matriz targets_](#targets) ao adicionar, remover ou invocar manipuladores de eventos.                          |
| [EventSource::targets_](#targets)                       | Uma matriz de um ou mais manipuladores de eventos.                                                                                           |
| [EventSource::targetsPointerLock_](#targetspointerlock) | Sincroniza o acesso a membros de dados internos mesmo enquanto os manipuladores de eventos para este EventSource estão sendo adicionados, removidos ou invocados. |

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`EventSource`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** event.h

**Espaço de nome:** Microsoft::WRL

## <a name="eventsourceadd"></a><a name="add"></a>EventSource::Add

Anexa o manipulador de eventos representado pela interface de delegado especificada `EventSource` para o conjunto de manipuladores de eventos para o objeto atual.

```cpp
HRESULT Add(
   _In_ TDelegateInterface* delegateInterface,
   _Out_ EventRegistrationToken* token
);
```

### <a name="parameters"></a>Parâmetros

*delegateInterface*<br/>
A interface para um objeto de delegado, que representa um manipulador de eventos.

*Token*<br/>
Quando esta operação for concluída, uma alça que represente o evento. Use este token como parâmetro para [remover()](#remove) o método Remover () para descartar o manipulador de eventos.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que indica o erro.

## <a name="eventsourceaddremovelock_"></a><a name="addremovelock"></a>EventSource::addRemoveLock_

Sincroniza o acesso à [matriz targets_](#targets) ao adicionar, remover ou invocar manipuladores de eventos.

```cpp
Wrappers::SRWLock addRemoveLock_;
```

## <a name="eventsourceeventsource"></a><a name="eventsource"></a>EventSource::EventSource

Inicia uma nova instância da classe `EventSource`.

```cpp
EventSource();
```

## <a name="eventsourcegetsize"></a><a name="getsize"></a>EventSource::GetSize

Recupera o número de manipuladores de `EventSource` eventos associados ao objeto atual.

```cpp
size_t GetSize() const;
```

### <a name="return-value"></a>Valor retornado

O número de manipuladores de eventos em [targets_](#targets).

## <a name="eventsourceinvokeall"></a><a name="invokeall"></a>EventSource::InvokeAll

Chama cada manipulador de `EventSource` eventos associado ao objeto atual usando os tipos e argumentos de argumento especificados.

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
O tipo de argumento do manipulador de eventos zero.

*T1*<br/>
O tipo do primeiro argumento de manipulador de eventos.

*T2*<br/>
O tipo do argumento do segundo manipulador de eventos.

*T3*<br/>
O tipo do argumento do terceiro manipulador de eventos.

*T4*<br/>
O tipo do argumento do manipulador do quarto evento.

*T5*<br/>
O tipo do quinto argumento manipulador de eventos.

*T6*<br/>
O tipo do sexto argumento de manipulador de eventos.

*T7*<br/>
O tipo do sétimo argumento manipulador de eventos.

*T8*<br/>
O tipo do oitavo argumento de manipulador de eventos.

*T9*<br/>
O tipo do nono argumento de manipulador de eventos.

*arg0*<br/>
O argumento do manipulador de eventos zero.

*arg1*<br/>
O primeiro argumento manipulador de eventos.

*arg2*<br/>
O segundo argumento do manipulador de eventos.

*arg3*<br/>
O argumento do terceiro manipulador de eventos.

*arg4*<br/>
O argumento do treinador do quarto evento.

*arg5*<br/>
O quinto argumento manipulador de eventos.

*arg6*<br/>
O sexto argumento manipulador de eventos.

*arg7*<br/>
O sétimo argumento manipulador de eventos.

*arg8*<br/>
O oitavo argumento de manipulador de eventos.

*arg9*<br/>
O nono argumento manipulador de eventos.

## <a name="eventsourceremove"></a><a name="remove"></a>EventSource::Remove

Exclui o manipulador de eventos representado pelo token de registro de evento `EventSource` especificado do conjunto de manipuladores de eventos associados ao objeto atual.

```cpp
HRESULT Remove(
   EventRegistrationToken token
);
```

### <a name="parameters"></a>Parâmetros

*Token*<br/>
Uma alça que representa um manipulador de eventos. Este token foi devolvido quando o manipulador de eventos foi registrado pelo método [Add().](#add)

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que indica o erro.

### <a name="remarks"></a>Comentários

Para obter mais `EventRegistrationToken` informações sobre a estrutura, consulte o tópico **Estrutura do Windows::Foundation::EventRegistrationToken structure** na documentação de referência do Windows **Runtime.**

## <a name="eventsourcetargets_"></a><a name="targets"></a>EventSource::targets_

Uma matriz de um ou mais manipuladores de eventos.

```cpp
ComPtr<Details::EventTargetArray> targets_;
```

### <a name="remarks"></a>Comentários

Quando o evento representado pelo `EventSource` objeto atual ocorre, os manipuladores de eventos são chamados.

## <a name="eventsourcetargetspointerlock_"></a><a name="targetspointerlock"></a>EventSource::targetsPointerLock_

Sincroniza o acesso a membros de dados internos `EventSource` mesmo enquanto os manipuladores de eventos para isso estão sendo adicionados, removidos ou invocados.

```cpp
Wrappers::SRWLock targetsPointerLock_;
```
