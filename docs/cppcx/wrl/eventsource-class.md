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
ms.openlocfilehash: 1350e51ff609a888b6a8ad6841be6856b68c7994
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78865724"
---
# <a name="eventsource-class"></a>Classe EventSource

Representa um evento não ágil. `EventSource` funções membro adicionam, removem e chamam manipuladores de eventos. Para eventos Agile, use [AgileEventSource](agileeventsource-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
template<typename TDelegateInterface>
class EventSource;
```

### <a name="parameters"></a>Parâmetros

*TDelegateInterface*<br/>
A interface para um delegado que representa um manipulador de eventos.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

| {1&gt;Nome&lt;1}                                     | Descrição                                            |
| ---------------------------------------- | ------------------------------------------------------ |
| [EventSource:: EventSource](#eventsource) | Inicializa uma nova instância da classe `EventSource`. |

### <a name="public-methods"></a>Métodos públicos

| {1&gt;Nome&lt;1}                                 | Descrição                                                                                                                                                      |
| ------------------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [EventSource:: Adicionar](#add)             | Acrescenta o manipulador de eventos representado pela interface de representante especificada ao conjunto de manipuladores de eventos para o objeto de `EventSource` atual.                     |
| [EventSource:: GetSize](#getsize)     | Recupera o número de manipuladores de eventos associados ao objeto de `EventSource` atual.                                                                         |
| [EventSource:: InvokeAll](#invokeall) | Chama cada manipulador de eventos associado ao objeto de `EventSource` atual usando os argumentos e tipos de argumento especificados.                                      |
| [EventSource:: remover](#remove)       | Exclui o manipulador de eventos representado pelo token de registro de evento especificado do conjunto de manipuladores de eventos associados ao objeto de `EventSource` atual. |

### <a name="protected-data-members"></a>Membros de Dados Protegidos

| {1&gt;Nome&lt;1}                                                    | Descrição                                                                                                                       |
| ------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------- |
| [EventSource:: addRemoveLock_](#addremovelock)           | Sincroniza o acesso à matriz de [targets_](#targets) ao adicionar, remover ou invocar manipuladores de eventos.                          |
| [EventSource:: targets_](#targets)                       | Uma matriz de um ou mais manipuladores de eventos.                                                                                           |
| [EventSource:: targetsPointerLock_](#targetspointerlock) | Sincroniza o acesso a membros de dados internos mesmo que os manipuladores de eventos para essa EventSource estejam sendo adicionados, removidos ou invocados. |

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`EventSource`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Event. h

**Namespace:** Microsoft:: WRL

## <a name="add"></a>EventSource:: Adicionar

Acrescenta o manipulador de eventos representado pela interface de representante especificada ao conjunto de manipuladores de eventos para o objeto de `EventSource` atual.

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
Quando essa operação for concluída, um identificador que representa o evento. Use esse token como o parâmetro para o método [Remove ()](#remove) para descartar o manipulador de eventos.

### <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, um HRESULT que indica o erro.

## <a name="addremovelock"></a>EventSource:: addRemoveLock_

Sincroniza o acesso à matriz de [targets_](#targets) ao adicionar, remover ou invocar manipuladores de eventos.

```cpp
Wrappers::SRWLock addRemoveLock_;
```

## <a name="eventsource"></a>EventSource:: EventSource

Inicializa uma nova instância da classe `EventSource`.

```cpp
EventSource();
```

## <a name="getsize"></a>EventSource:: GetSize

Recupera o número de manipuladores de eventos associados ao objeto de `EventSource` atual.

```cpp
size_t GetSize() const;
```

### <a name="return-value"></a>Valor retornado

O número de manipuladores de eventos no [targets_](#targets).

## <a name="invokeall"></a>EventSource:: InvokeAll

Chama cada manipulador de eventos associado ao objeto de `EventSource` atual usando os argumentos e tipos de argumento especificados.

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
O tipo do argumento do manipulador de eventos inicial.

*T1*<br/>
O tipo do primeiro argumento do manipulador de eventos.

*T2*<br/>
O tipo do segundo argumento do manipulador de eventos.

*T3*<br/>
O tipo do terceiro argumento do manipulador de eventos.

*T4*<br/>
O tipo do quarto argumento do manipulador de eventos.

*T5*<br/>
O tipo do quinto argumento do manipulador de eventos.

*T6*<br/>
O tipo do sexto argumento do manipulador de eventos.

*T7*<br/>
O tipo do sétimo argumento do manipulador de eventos.

*T8*<br/>
O tipo do oitavo argumento do manipulador de eventos.

*T9*<br/>
O tipo do argumento nono manipulador de eventos.

*arg0*<br/>
O argumento do manipulador de eventos inicial.

*arg1*<br/>
O primeiro argumento do manipulador de eventos.

*arg2*<br/>
O segundo argumento do manipulador de eventos.

*Arg3*<br/>
O terceiro argumento do manipulador de eventos.

*arg4*<br/>
O quarto argumento do manipulador de eventos.

*arg5*<br/>
O quinto argumento do manipulador de eventos.

*arg6*<br/>
O sexto argumento do manipulador de eventos.

*arg7*<br/>
O sétimo argumento do manipulador de eventos.

*arg8*<br/>
O oitavo argumento do manipulador de eventos.

*arg9*<br/>
O nono argumento do manipulador de eventos.

## <a name="remove"></a>EventSource:: remover

Exclui o manipulador de eventos representado pelo token de registro de evento especificado do conjunto de manipuladores de eventos associados ao objeto de `EventSource` atual.

```cpp
HRESULT Remove(
   EventRegistrationToken token
);
```

### <a name="parameters"></a>Parâmetros

*token*<br/>
Um identificador que representa um manipulador de eventos. Esse token foi retornado quando o manipulador de eventos foi registrado pelo método [Add ()](#add) .

### <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, um HRESULT que indica o erro.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre a estrutura de `EventRegistrationToken`, consulte o tópico **Windows:: Foundation:: EventRegistrationToken Structure** na documentação de referência do **Windows Runtime** .

## <a name="targets"></a>EventSource:: targets_

Uma matriz de um ou mais manipuladores de eventos.

```cpp
ComPtr<Details::EventTargetArray> targets_;
```

### <a name="remarks"></a>Comentários

Quando o evento que é representado pelo objeto de `EventSource` atual ocorre, os manipuladores de eventos são chamados.

## <a name="targetspointerlock"></a>EventSource:: targetsPointerLock_

Sincroniza o acesso a membros de dados internos mesmo que os manipuladores de eventos para esse `EventSource` estejam sendo adicionados, removidos ou invocados.

```cpp
Wrappers::SRWLock targetsPointerLock_;
```
