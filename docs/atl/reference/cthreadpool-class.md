---
title: Classe CThreadPool
ms.date: 11/04/2016
f1_keywords:
- CThreadPool
- ATLUTIL/ATL::CThreadPool
- ATLUTIL/ATL::CThreadPool::CThreadPool
- ATLUTIL/ATL::CThreadPool::AddRef
- ATLUTIL/ATL::CThreadPool::GetNumThreads
- ATLUTIL/ATL::CThreadPool::GetQueueHandle
- ATLUTIL/ATL::CThreadPool::GetSize
- ATLUTIL/ATL::CThreadPool::GetTimeout
- ATLUTIL/ATL::CThreadPool::Initialize
- ATLUTIL/ATL::CThreadPool::QueryInterface
- ATLUTIL/ATL::CThreadPool::QueueRequest
- ATLUTIL/ATL::CThreadPool::Release
- ATLUTIL/ATL::CThreadPool::SetSize
- ATLUTIL/ATL::CThreadPool::SetTimeout
- ATLUTIL/ATL::CThreadPool::Shutdown
helpviewer_keywords:
- CThreadPool class
ms.assetid: 06683718-01b9-413c-9481-2dc1734ec70f
ms.openlocfilehash: 07fd470a6aeab0575f2733d72650bd695b8e2752
ms.sourcegitcommit: 46d24d6e70c03e05484923d9efc6ed5150e96a64
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2019
ms.locfileid: "68915683"
---
# <a name="cthreadpool-class"></a>Classe CThreadPool

Essa classe fornece um pool de threads de trabalho que processam uma fila de itens de trabalho.

## <a name="syntax"></a>Sintaxe

```
template <class Worker, class ThreadTraits = DefaultThreadTraits>
class CThreadPool : public IThreadPoolConfig
```

#### <a name="parameters"></a>Parâmetros

*Funcionários*<br/>
A classe que está em conformidade com o [arquétipo de trabalho](../../atl/reference/worker-archetype.md) fornecendo o código usado para processar itens de trabalho na fila no pool de threads.

*ThreadTraits*<br/>
A classe que fornece a função usada para criar os threads no pool.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CThreadPool::CThreadPool](#cthreadpool)|O construtor do pool de threads.|
|[CThreadPool::~CThreadPool](#dtor)|O destruidor para o pool de threads.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CThreadPool::AddRef](#addref)|Implementação de `IUnknown::AddRef`.|
|[CThreadPool::GetNumThreads](#getnumthreads)|Chame esse método para obter o número de threads no pool.|
|[CThreadPool::GetQueueHandle](#getqueuehandle)|Chame esse método para obter o identificador da porta de conclusão de e/s usada para enfileirar itens de trabalho.|
|[CThreadPool::GetSize](#getsize)|Chame esse método para obter o número de threads no pool.|
|[CThreadPool::GetTimeout](#gettimeout)|Chame esse método para obter o tempo máximo em milissegundos que o pool de threads aguardará até que um thread seja desligado.|
|[CThreadPool::Initialize](#initialize)|Chame esse método para inicializar o pool de threads.|
|[CThreadPool::QueryInterface](#queryinterface)|Implementação de `IUnknown::QueryInterface`.|
|[CThreadPool::QueueRequest](#queuerequest)|Chame esse método para enfileirar um item de trabalho a ser manipulado por um thread no pool.|
|[CThreadPool::Release](#release)|Implementação de `IUnknown::Release`.|
|[CThreadPool::SetSize](#setsize)|Chame esse método para definir o número de threads no pool.|
|[CThreadPool::SetTimeout](#settimeout)|Chame esse método para definir o tempo máximo em milissegundos que o pool de threads aguardará até que um thread seja desligado.|
|[CThreadPool::Shutdown](#shutdown)|Chame esse método para desligar o pool de threads.|

## <a name="remarks"></a>Comentários

Os threads no pool são criados e destruídos quando o pool é inicializado, redimensionado ou desligado. Uma instância da classe *Worker* será criada na pilha de cada thread de trabalho no pool. Cada instância residirá durante o tempo de vida do thread.

Imediatamente após a criação de um thread, *Worker*:`Initialize` : será chamado no objeto associado a esse thread. Imediatamente antes da destruição de um thread, *Worker*:`Terminate` : será chamado. Ambos os métodos devem aceitar um argumento **void** <strong>\*</strong> . O valor desse argumento é passado para o pool de threads por meio do parâmetro *pvWorkerParam* de [CThreadPool:: Initialize](#initialize).

Quando há itens de trabalho na fila e threads de trabalho disponíveis para trabalho, um thread de trabalho efetuará pull de um item da fila `Execute` e chamará o método do objeto de *trabalho* para esse thread. Três itens são passados para o método: o item da fila, `pvWorkerParam` o mesmo passado para *Worker*:: `Initialize` e *Worker*:: `Terminate`e um ponteiro para a estrutura [sobreposta](/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) usada para a fila de portas de conclusão de e/s .

A classe *Worker* declara o tipo dos itens que serão enfileirados no pool de threads fornecendo um typedef, *Worker*:: `RequestType`. Esse tipo deve ser capaz de ser convertido de e para um ULONG_PTR.

Um exemplo de uma classe de *trabalho* é a [classe CNonStatelessWorker](../../atl/reference/cnonstatelessworker-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IUnknown`

[IThreadPoolConfig](../../atl/reference/ithreadpoolconfig-interface.md)

`CThreadPool`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil. h

##  <a name="addref"></a>  CThreadPool::AddRef

Implementação de `IUnknown::AddRef`.

```
ULONG STDMETHODCALLTYPE AddRef() throw();
```

### <a name="return-value"></a>Valor de retorno

Sempre retorna 1.

### <a name="remarks"></a>Comentários

Essa classe não implementa o controle de tempo de vida usando a contagem de referência.

##  <a name="cthreadpool"></a>  CThreadPool::CThreadPool

O construtor do pool de threads.

```
CThreadPool() throw();
```

### <a name="remarks"></a>Comentários

Inicializa o valor de tempo limite para ATLS_DEFAULT_THREADPOOLSHUTDOWNTIMEOUT. O tempo padrão é de 36 segundos. Se necessário, você pode definir seu próprio valor inteiro positivo para esse símbolo antes de incluir atlutil. h.

##  <a name="dtor"></a>CThreadPool:: ~ CThreadPool

O destruidor para o pool de threads.

```
~CThreadPool() throw();
```

### <a name="remarks"></a>Comentários

Chama [CThreadPool:: Shutdown](#shutdown).

##  <a name="getnumthreads"></a>  CThreadPool::GetNumThreads

Chame esse método para obter o número de threads no pool.

```
int GetNumThreads() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna o número de threads no pool.

##  <a name="getqueuehandle"></a>  CThreadPool::GetQueueHandle

Chame esse método para obter o identificador da porta de conclusão de e/s usada para enfileirar itens de trabalho.

```
HANDLE GetQueueHandle() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna o identificador de fila ou nulo se o pool de threads não foi inicializado.

##  <a name="getsize"></a>  CThreadPool::GetSize

Chame esse método para obter o número de threads no pool.

```
HRESULT STDMETHODCALLTYPE GetSize(int* pnNumThreads) throw();
```

### <a name="parameters"></a>Parâmetros

*pnNumThreads*<br/>
fora Endereço da variável que, em caso de êxito, recebe o número de threads no pool.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

##  <a name="gettimeout"></a>  CThreadPool::GetTimeout

Chame esse método para obter o tempo máximo em milissegundos que o pool de threads aguardará até que um thread seja desligado.

```
HRESULT STDMETHODCALLTYPE GetTimeout(DWORD* pdwMaxWait) throw();
```

### <a name="parameters"></a>Parâmetros

*pdwMaxWait*<br/>
fora Endereço da variável que, em caso de êxito, recebe o tempo máximo em milissegundos que o pool de threads aguardará até que um thread seja desligado.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Esse valor de tempo limite é usado por [CThreadPool:: Shutdown](#shutdown) se nenhum outro valor for fornecido a esse método.

##  <a name="initialize"></a>  CThreadPool::Initialize

Chame esse método para inicializar o pool de threads.

```
HRESULT Initialize(
    void* pvWorkerParam = NULL,
    int nNumThreads = 0,
    DWORD dwStackSize = 0,
    HANDLE hCompletion = INVALID_HANDLE_VALUE) throw();
```

### <a name="parameters"></a>Parâmetros

*pvWorkerParam*<br/>
O parâmetro de trabalho a ser passado para os métodos, `Initialize` `Execute`e `Terminate` do objeto de thread de trabalho.

*nNumThreads*<br/>
O número de threads solicitado no pool.

Se *nNumThreads* for negativo, seu valor absoluto será multiplicado pelo número de processadores no computador para obter o número total de threads.

Se *nNumThreads* for zero, ATLS_DEFAULT_THREADSPERPROC será multiplicado pelo número de processadores no computador para obter o número total de threads.  O padrão é 2 threads por processador. Se necessário, você pode definir seu próprio valor inteiro positivo para esse símbolo antes de incluir atlutil. h.

*dwStackSize*<br/>
O tamanho da pilha para cada thread no pool.

*hCompletion*<br/>
O identificador de um objeto a ser associado à porta de conclusão.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

##  <a name="queryinterface"></a>  CThreadPool::QueryInterface

Implementação de `IUnknown::QueryInterface`.

```
HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppv) throw();
```

### <a name="remarks"></a>Comentários

Os objetos dessa classe podem ser consultados com êxito para as `IUnknown` interfaces e [IThreadPoolConfig](../../atl/reference/ithreadpoolconfig-interface.md) .

##  <a name="queuerequest"></a>  CThreadPool::QueueRequest

Chame esse método para enfileirar um item de trabalho a ser manipulado por um thread no pool.

```
BOOL QueueRequest(Worker::RequestType request) throw();
```

### <a name="parameters"></a>Parâmetros

*Quest*<br/>
A solicitação a ser enfileirada.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Esse método adiciona um item de trabalho à fila. Os threads no pool selecionam itens da fila na ordem em que são recebidos.

##  <a name="release"></a>  CThreadPool::Release

Implementação de `IUnknown::Release`.

```
ULONG STDMETHODCALLTYPE Release() throw();
```

### <a name="return-value"></a>Valor de retorno

Sempre retorna 1.

### <a name="remarks"></a>Comentários

Essa classe não implementa o controle de tempo de vida usando a contagem de referência.

##  <a name="setsize"></a>  CThreadPool::SetSize

Chame esse método para definir o número de threads no pool.

```
HRESULT STDMETHODCALLTYPE SetSizeint nNumThreads) throw();
```

### <a name="parameters"></a>Parâmetros

*nNumThreads*<br/>
O número de threads solicitado no pool.

Se *nNumThreads* for negativo, seu valor absoluto será multiplicado pelo número de processadores no computador para obter o número total de threads.

Se *nNumThreads* for zero, ATLS_DEFAULT_THREADSPERPROC será multiplicado pelo número de processadores no computador para obter o número total de threads. O padrão é 2 threads por processador. Se necessário, você pode definir seu próprio valor inteiro positivo para esse símbolo antes de incluir atlutil. h.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Se o número de threads especificado for menor que o número de threads atualmente no pool, o objeto colocará uma mensagem de desligamento na fila a ser coletada por um thread em espera. Quando um thread em espera puxa a mensagem para fora da fila, ele notifica o pool de threads e sai do procedimento de thread. Esse processo é repetido até que o número de threads no pool atinja o número especificado ou até que nenhum thread tenha sido encerrado dentro do período especificado por [getTime out](#gettimeout)/ [SetTimeout](#settimeout). Nessa situação, o método retornará um HRESULT correspondente a WAIT_TIMEOUT e a mensagem de desligamento pendente será cancelada.

##  <a name="settimeout"></a>  CThreadPool::SetTimeout

Chame esse método para definir o tempo máximo em milissegundos que o pool de threads aguardará até que um thread seja desligado.

```
HRESULT STDMETHODCALLTYPE SetTimeout(DWORD dwMaxWait) throw();
```

### <a name="parameters"></a>Parâmetros

*dwMaxWait*<br/>
O tempo máximo solicitado em milissegundos que o pool de threads aguardará até que um thread seja desligado.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

O tempo limite é inicializado para ATLS_DEFAULT_THREADPOOLSHUTDOWNTIMEOUT. O tempo padrão é de 36 segundos. Se necessário, você pode definir seu próprio valor inteiro positivo para esse símbolo antes de incluir atlutil. h.

Observe que *dwMaxWait* é a hora em que o pool aguardará a desligamento de um único thread. O tempo máximo que poderia ser levado para remover vários threads do pool poderia ser um pouco menor que *dwMaxWait* multiplicado pelo número de threads.

##  <a name="shutdown"></a>  CThreadPool::Shutdown

Chame esse método para desligar o pool de threads.

```
void Shutdown(DWORD dwMaxWait = 0) throw();
```

### <a name="parameters"></a>Parâmetros

*dwMaxWait*<br/>
O tempo máximo solicitado em milissegundos que o pool de threads aguardará até que um thread seja desligado. Se 0 ou nenhum valor for fornecido, esse método usará o tempo limite definido por [CThreadPool::](#settimeout)SetTimeout.

### <a name="remarks"></a>Comentários

Esse método posta uma solicitação de desligamento para todos os threads no pool. Se o tempo limite expirar, esse método chamará [TerminateThread](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-terminatethread) em qualquer thread que não foi encerrado. Esse método é chamado automaticamente do destruidor da classe.

## <a name="see-also"></a>Consulte também

[Interface IThreadPoolConfig](../../atl/reference/ithreadpoolconfig-interface.md)<br/>
[DefaultThreadTraits](atl-typedefs.md#defaultthreadtraits)<br/>
[Classes](../../atl/reference/atl-classes.md)
