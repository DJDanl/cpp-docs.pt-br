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
ms.openlocfilehash: 5d7d92fcd1bb00513b9e05030afa56726e87183b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62212851"
---
# <a name="taskcontinuationcontext-class"></a>Classe task_continuation_context

A classe `task_continuation_context` permite que você especifique onde gostaria que uma continuação fosse executada. Ele só é útil usar essa classe de um aplicativo de tempo de execução do Windows. Para aplicativos não - Windows Runtime, o contexto de execução da continuação da tarefa é determinado pelo tempo de execução e não é configurável.

## <a name="syntax"></a>Sintaxe

```
class task_continuation_context : public details::_ContextCallback;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[get_current_winrt_context](#get_current_winrt_context)|Retorna um objeto de contexto de continuação de tarefa que representa o contexto de thread atual do winrt.|
|[use_arbitrary](#use_arbitrary)|Cria um contexto de continuação da tarefa que permite que o Tempo de execução escolha o contexto de execução para uma continuação.|
|[use_current](#use_current)|Retorna um objeto de contexto de continuação da tarefa que representa o contexto de execução atual.|
|[use_default](#use_default)|Cria o contexto de continuação da tarefa padrão.|
|[use_synchronous_execution](#use_synchronous_execution)|Retorna um objeto de contexto de continuação de tarefa que representa o contexto de execução síncrona.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`_ContextCallback`

`task_continuation_context`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ppltasks. h

**Namespace:** simultaneidade

## <a name="get_current_winrt_context"></a> get_current_winrt_context

Retorna um objeto de contexto de continuação de tarefa que representa o contexto de thread atual do WinRT.

## <a name="syntax"></a>Sintaxe

```
static task_continuation_context get_current_winrt_context();
```

## <a name="return-value"></a>Valor de retorno

O contexto de thread atual do tempo de execução do Windows. Retorna um task_continuation_context vazio se for chamado em um contexto de não - Windows Runtime.

## <a name="remarks"></a>Comentários

O `get_current_winrt_context` método captura o contexto do thread de tempo de execução do Windows do chamador. Ele retorna um contexto vazio para chamadores não - Windows Runtime.

O valor retornado por `get_current_winrt_context` pode ser usado para indicar ao tempo de execução que a continuação deve ser executada no modelo de apartment de contexto capturado (STA contra o MTA), independentemente da tarefa antecedente está ciente de segmentação. Um apartment com suporte a tarefa é uma tarefa que desempacota um tempo de execução do Windows `IAsyncInfo` interface ou uma tarefa que é descendente de tal tarefa.

Esse método é semelhante para o `use_current` método, mas ele também está disponível para nativo C++ o código sem C++suporte à extensão /CX. Ele destina-se para uso por usuários avançados de gravação C++código de biblioteca /CX-agnostic para nativo e chamadores de tempo de execução do Windows. A menos que você precisa dessa funcionalidade, recomendamos a `use_current` método, que está disponível apenas para C++/CX clientes.

##  <a name="use_arbitrary"></a> use_arbitrary

Cria um contexto de continuação da tarefa que permite que o Tempo de execução escolha o contexto de execução para uma continuação.

```
static task_continuation_context use_arbitrary();
```

### <a name="return-value"></a>Valor de retorno

Um contexto de continuação de tarefa que representa um local arbitrário.

### <a name="remarks"></a>Comentários

Quando esse contexto de continuação é usado, a continuação será executada em um contexto de que tempo de execução escolhe mesmo se a tarefa for ciente de segmentação.

`use_arbitrary` pode ser usado para desativar o comportamento padrão para uma continuação em uma tarefa de segmentação criada em um STA.

Esse método só está disponível para aplicativos do Windows Runtime.

##  <a name="use_current"></a> use_current

Retorna um objeto de contexto de continuação da tarefa que representa o contexto de execução atual.

```
static task_continuation_context use_current();
```

### <a name="return-value"></a>Valor de retorno

O contexto de execução atual.

### <a name="remarks"></a>Comentários

Este método captura o contexto de tempo de execução do Windows do chamador para que as continuações podem ser executadas no apartment direito.

O valor retornado por `use_current` pode ser usado para indicar ao tempo de execução que a continuação deve ser executada no contexto capturado (STA contra o MTA) independentemente de estarem ou não a tarefa for ciente de segmentação. Um apartment com suporte a tarefa é uma tarefa que desempacota um tempo de execução do Windows `IAsyncInfo` interface ou uma tarefa que é descendente de tal tarefa.

Esse método só está disponível para aplicativos do Windows Runtime.

##  <a name="use_default"></a> use_default

Cria o contexto de continuação da tarefa padrão.

```
static task_continuation_context use_default();
```

### <a name="return-value"></a>Valor de retorno

O contexto padrão.

### <a name="remarks"></a>Comentários

O contexto padrão será usado se você não especificar um contexto de continuação ao chamar o `then` método. Em aplicativos do Windows para o Windows 7 e abaixo, bem como aplicativos da área de trabalho no Windows 8 e superior, o tempo de execução determina onde as continuações de tarefa serão executada. No entanto, em um aplicativo de tempo de execução do Windows, o contexto padrão para uma continuação em uma tarefa de segmentação é a segmentação onde `then` é invocado.

Um apartment com suporte a tarefa é uma tarefa que desempacota um tempo de execução do Windows `IAsyncInfo` interface ou uma tarefa que é descendente de tal tarefa. Portanto, se você agendar uma continuação em uma tarefa de segmentação em um STA de tempo de execução do Windows, a continuação será executada naquele STA.

Uma continuação em uma tarefa ciente de não-apartment será executada em um contexto que escolhe o tempo de execução.

## <a name="use_synchronous_execution"></a> task_continuation_context::use_synchronous_execution

Retorna um objeto de contexto de continuação de tarefa que representa o contexto de execução síncrona.

## <a name="syntax"></a>Sintaxe

```
static task_continuation_context use_synchronous_execution();
```

## <a name="return-value"></a>Valor de retorno

O contexto de execução síncrona.

## <a name="remarks"></a>Comentários

O `use_synchronous_execution` método força a tarefa de continuação para executar de forma síncrona no contexto, fazendo com que a conclusão da sua tarefa antecedente.

Se a tarefa antecedente já foi concluída quando a continuação é anexada, a continuação é executada de forma síncrona no contexto de que anexa a continuação.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
