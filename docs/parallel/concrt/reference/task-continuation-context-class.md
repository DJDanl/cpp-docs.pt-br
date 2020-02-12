---
title: Classe task_continuation_context
ms.date: 11/04/2016
f1_keywords:
- task_continuation_context
- PPLTASKS/concurrency::task_continuation_context
- PPLTASKS/concurrency::task_continuation_context::get_current_winrt_context
- PPLTASKS/concurrency::task_continuation_context::use_arbitrary
- PPLTASKS/concurrency::task_continuation_context::use_current
- PPLTASKS/concurrency::task_continuation_context::use_default
- PPLTASKS/concurrency::task_continuation_context::use_synchronous_execution
helpviewer_keywords:
- task_continuation_context class
ms.assetid: 1fb5a76a-3682-45c2-a615-8b6b527741f0
ms.openlocfilehash: ae8ac425f035839cdddc0b19f4f40d3b6369202a
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142585"
---
# <a name="task_continuation_context-class"></a>Classe task_continuation_context

A classe `task_continuation_context` permite que você especifique onde gostaria que uma continuação fosse executada. Só é útil usar essa classe de um aplicativo Windows Runtime. Para aplicativos não Windows Runtime, o contexto de execução da continuação da tarefa é determinado pelo tempo de execução e não é configurável.

## <a name="syntax"></a>Sintaxe

```cpp
class task_continuation_context : public details::_ContextCallback;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[get_current_winrt_context](#get_current_winrt_context)|Retorna um objeto de contexto de continuação de tarefa que representa o contexto de thread winrt atual.|
|[use_arbitrary](#use_arbitrary)|Cria um contexto de continuação da tarefa que permite que o Runtime escolha o contexto de execução para uma continuação.|
|[use_current](#use_current)|Retorna um objeto de contexto de continuação da tarefa que representa o contexto de execução atual.|
|[use_default](#use_default)|Cria o contexto de continuação da tarefa padrão.|
|[use_synchronous_execution](#use_synchronous_execution)|Retorna um objeto de contexto de continuação de tarefa que representa o contexto de execução síncrona.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`_ContextCallback`

`task_continuation_context`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ppltasks. h

**Namespace:** simultaneidade

## <a name="get_current_winrt_context"></a>get_current_winrt_context

Retorna um objeto de contexto de continuação de tarefa que representa o contexto de thread WinRT atual.

### <a name="syntax"></a>Sintaxe

```cpp
static task_continuation_context get_current_winrt_context();
```

### <a name="return-value"></a>Valor retornado

O contexto de thread de Windows Runtime atual. Retorna um task_continuation_context vazio se chamado de um contexto não Windows Runtime.

### <a name="remarks"></a>Comentários

O método `get_current_winrt_context` captura o contexto de thread Windows Runtime do chamador. Ele retorna um contexto vazio para chamadores não Windows Runtime.

O valor retornado por `get_current_winrt_context` pode ser usado para indicar ao tempo de execução que a continuação deve ser executada no modelo de apartamento do contexto capturado (STA vs MTA), independentemente de a tarefa Antecedent ser ciente de apartamento. Uma tarefa com reconhecimento de apartamento é uma tarefa que desenvolve um Windows Runtime `IAsyncInfo` interface ou uma tarefa que é decrescente dessa tarefa.

Esse método é semelhante ao método `use_current`, mas também está disponível para código nativo C++ sem C++suporte à extensão/CX. Ele é destinado ao uso por usuários avançados que C++gravam o código da biblioteca/CX-Agnostic para chamadores nativos e Windows Runtime. A menos que você precise dessa funcionalidade, recomendamos o método `use_current`, que está disponível C++somente para clientes do/CX.

## <a name="use_arbitrary"></a>use_arbitrary

Cria um contexto de continuação da tarefa que permite que o Runtime escolha o contexto de execução para uma continuação.

### <a name="syntax"></a>Sintaxe

```cpp
static task_continuation_context use_arbitrary();
```

### <a name="return-value"></a>Valor retornado

Um contexto de continuação de tarefa que representa um local arbitrário.

### <a name="remarks"></a>Comentários

Quando esse contexto de continuação for usado, a continuação será executada em um contexto que o tempo de execução escolherá mesmo se a tarefa Antecedent for de reconhecimento de apartamento.

`use_arbitrary` pode ser usado para desativar o comportamento padrão para uma continuação em uma tarefa de reconhecimento de apartamento criada em um STA.

Esse método só está disponível para Windows Runtime aplicativos.

## <a name="use_current"></a>use_current

Retorna um objeto de contexto de continuação da tarefa que representa o contexto de execução atual.

```cpp
static task_continuation_context use_current();
```

### <a name="return-value"></a>Valor retornado

O contexto atual da execução.

### <a name="remarks"></a>Comentários

Esse método captura o contexto de Windows Runtime do chamador para que as continuaçãos possam ser executadas no apartamento correto.

O valor retornado por `use_current` pode ser usado para indicar ao tempo de execução que a continuação deve ser executada no contexto capturado (STA vs MTA), independentemente da tarefa antecedenta estar ciente de apartamento ou não. Uma tarefa com reconhecimento de apartamento é uma tarefa que desenvolve um Windows Runtime `IAsyncInfo` interface ou uma tarefa que é decrescente dessa tarefa.

Esse método só está disponível para Windows Runtime aplicativos.

## <a name="use_default"></a>use_default

Cria o contexto de continuação da tarefa padrão.

```cpp
static task_continuation_context use_default();
```

### <a name="return-value"></a>Valor retornado

O contexto de continuação padrão.

### <a name="remarks"></a>Comentários

O contexto padrão será usado se você não especificar um contexto de continuação ao chamar o método `then`. Em aplicativos do Windows para Windows 7 e inferior, bem como aplicativos de área de trabalho no Windows 8 e superior, o tempo de execução determina onde as continuações de tarefa serão executadas. No entanto, em um aplicativo Windows Runtime, o contexto de continuação padrão para uma continuação em uma tarefa com reconhecimento de apartamento é o apartamento em que `then` é invocado.

Uma tarefa com reconhecimento de apartamento é uma tarefa que desenvolve um Windows Runtime `IAsyncInfo` interface ou uma tarefa que é decrescente dessa tarefa. Portanto, se você agendar uma continuação em uma tarefa de reconhecimento de apartamento em um Windows Runtime STA, a continuação será executada nesse STA.

Uma continuação em uma tarefa sem reconhecimento de apartamento será executada em um contexto escolhido pelo tempo de execução.

## <a name="use_synchronous_execution"></a>task_continuation_context:: use_synchronous_execution

Retorna um objeto de contexto de continuação de tarefa que representa o contexto de execução síncrona.

### <a name="syntax"></a>Sintaxe

```cpp
static task_continuation_context use_synchronous_execution();
```

### <a name="return-value"></a>Valor retornado

O contexto de execução síncrona.

### <a name="remarks"></a>Comentários

O método `use_synchronous_execution` força a execução síncrona da tarefa de continuação no contexto, causando a conclusão da tarefa antecedente.

Se a tarefa Antecedent já tiver sido concluída quando a continuação for anexada, a continuação será executada de forma síncrona no contexto que anexa a continuação.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
