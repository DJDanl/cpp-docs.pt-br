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
ms.openlocfilehash: 0b970915aa07fe2d1af2b3a07345d5b19826be69
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330561"
---
# <a name="cthreadpool-class"></a>Classe CThreadPool

Esta classe fornece um pool de threads de trabalhadores que processam uma fila de itens de trabalho.

## <a name="syntax"></a>Sintaxe

```
template <class Worker, class ThreadTraits = DefaultThreadTraits>
class CThreadPool : public IThreadPoolConfig
```

#### <a name="parameters"></a>Parâmetros

*Trabalho*<br/>
A classe está em conformidade com o [arquétipo](../../atl/reference/worker-archetype.md) do trabalhador que fornece o código usado para processar itens de trabalho enfileirados no pool de segmentos.

*Traços de linha*<br/>
A classe fornece a função usada para criar os segmentos na piscina.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CThreadPool::CThreadPool](#cthreadpool)|O construtor da piscina de fios.|
|[CThreadPool::~CThreadPool](#dtor)|O destruidor da piscina de fios.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[cthreadpool::Addref](#addref)|Implementação de `IUnknown::AddRef`.|
|[CThreadPool::GetNumThreads](#getnumthreads)|Ligue para este método para obter o número de threads na piscina.|
|[CThreadPool::GetQueueHandle](#getqueuehandle)|Chame este método para obter o cabo da porta de conclusão do IO usado para enfileirar itens de trabalho.|
|[CThreadPool::GetSize](#getsize)|Ligue para este método para obter o número de threads na piscina.|
|[CThreadPool::GetTimeout](#gettimeout)|Chame este método para obter o tempo máximo em milissegundos que a piscina de roscas esperará por um fio para desligar.|
|[CThreadPool::Inicializar](#initialize)|Chame este método para inicializar o pool de segmentos.|
|[CThreadPool::QueryInterface](#queryinterface)|Implementação de `IUnknown::QueryInterface`.|
|[CThreadPool::Consultasolicitação](#queuerequest)|Chame este método para enfileirar um item de trabalho a ser manuseado por um segmento na piscina.|
|[CThreadPool::Lançamento](#release)|Implementação de `IUnknown::Release`.|
|[cThreadPool::SetSize](#setsize)|Chame este método para definir o número de threads na piscina.|
|[CThreadPool::SetTimeout](#settimeout)|Chame este método para definir o tempo máximo em milissegundos que o pool de segmentos esperará por um fio para desligar.|
|[CThreadPool::Desligamento](#shutdown)|Chame este método para desligar a piscina de segmentos.|

## <a name="remarks"></a>Comentários

Os segmentos na piscina são criados e destruídos quando a piscina é inicializada, redimensionada ou desligada. Uma instância de classe *Trabalhador* será criada na pilha de cada segmento de trabalhador no pool. Cada instância viverá durante toda a vida do fio.

Imediatamente após a criação de um`Initialize` segmento, o *Trabalhador*:: será chamado sobre o objeto associado a esse segmento. Imediatamente antes da destruição *Worker*de`Terminate` um fio, Operário :: será chamado. Ambos os métodos devem aceitar um argumento **nulo.** <strong>\*</strong> O valor deste argumento é passado para o pool de segmentos através do parâmetro *pvWorkerParam* do [CThreadPool::Initialize](#initialize).

Quando houver itens de trabalho na fila e segmentos de trabalhador disponíveis para o trabalho, um `Execute` segmento de trabalhador puxará um item da fila e chamará o método do objeto *Trabalhador* para esse segmento. Três itens são então passados para o método: o item da fila, o `pvWorkerParam` mesmo passado para *Otrabalhador* `Initialize` :: e *Trabalhador*:: `Terminate`, e um ponteiro para a estrutura [SOBREPOSTA](/windows/win32/api/minwinbase/ns-minwinbase-overlapped) usada para a fila de conclusão do IO.

A classe *Trabalhadora* declara o tipo de itens que serão enfileirados no pool de segmentos, fornecendo um typedef, *Worker*:: `RequestType`. Este tipo deve ser capaz de ser lançado de e para uma ULONG_PTR.

Um exemplo de *classe Trabalhadora* é [cnonstatelessWorker class](../../atl/reference/cnonstatelessworker-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IUnknown`

[Ithreadpoolconfig](../../atl/reference/ithreadpoolconfig-interface.md)

`CThreadPool`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil.h

## <a name="cthreadpooladdref"></a><a name="addref"></a>cthreadpool::Addref

Implementação de `IUnknown::AddRef`.

```
ULONG STDMETHODCALLTYPE AddRef() throw();
```

### <a name="return-value"></a>Valor retornado

Sempre retorna 1.

### <a name="remarks"></a>Comentários

Esta classe não implementa o controle vitalício usando a contagem de referências.

## <a name="cthreadpoolcthreadpool"></a><a name="cthreadpool"></a>CThreadPool::CThreadPool

O construtor da piscina de fios.

```
CThreadPool() throw();
```

### <a name="remarks"></a>Comentários

Inicializa o valor de tempo para ATLS_DEFAULT_THREADPOOLSHUTDOWNTIMEOUT. O tempo padrão é de 36 segundos. Se necessário, você pode definir seu próprio valor inteiro positivo para este símbolo antes de incluir atlutil.h.

## <a name="cthreadpoolcthreadpool"></a><a name="dtor"></a>CThreadPool::~CThreadPool

O destruidor da piscina de fios.

```
~CThreadPool() throw();
```

### <a name="remarks"></a>Comentários

Chama [CThreadPool:::Shutdown](#shutdown).

## <a name="cthreadpoolgetnumthreads"></a><a name="getnumthreads"></a>CThreadPool::GetNumThreads

Ligue para este método para obter o número de threads na piscina.

```
int GetNumThreads() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o número de threads na piscina.

## <a name="cthreadpoolgetqueuehandle"></a><a name="getqueuehandle"></a>CThreadPool::GetQueueHandle

Chame este método para obter o cabo da porta de conclusão do IO usado para enfileirar itens de trabalho.

```
HANDLE GetQueueHandle() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a alça da fila ou NULL se o pool de segmentos não tiver sido inicializado.

## <a name="cthreadpoolgetsize"></a><a name="getsize"></a>CThreadPool::GetSize

Ligue para este método para obter o número de threads na piscina.

```
HRESULT STDMETHODCALLTYPE GetSize(int* pnNumThreads) throw();
```

### <a name="parameters"></a>Parâmetros

*pnNumThreads*<br/>
[fora] Endereço da variável que, no sucesso, recebe o número de threads no pool.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cthreadpoolgettimeout"></a><a name="gettimeout"></a>CThreadPool::GetTimeout

Chame este método para obter o tempo máximo em milissegundos que a piscina de roscas esperará por um fio para desligar.

```
HRESULT STDMETHODCALLTYPE GetTimeout(DWORD* pdwMaxWait) throw();
```

### <a name="parameters"></a>Parâmetros

*pdwMaxWait*<br/>
[fora] Endereço da variável que, no sucesso, recebe o tempo máximo em milissegundos que o pool de segmentos esperará por um segmento para desligar.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Este valor de tempo é usado por [CThreadPool::Shutdown](#shutdown) se nenhum outro valor for fornecido a esse método.

## <a name="cthreadpoolinitialize"></a><a name="initialize"></a>CThreadPool::Inicializar

Chame este método para inicializar o pool de segmentos.

```
HRESULT Initialize(
    void* pvWorkerParam = NULL,
    int nNumThreads = 0,
    DWORD dwStackSize = 0,
    HANDLE hCompletion = INVALID_HANDLE_VALUE) throw();
```

### <a name="parameters"></a>Parâmetros

*pvWorkerParam*<br/>
O parâmetro do trabalhador a ser passado `Initialize`para `Execute`os `Terminate` métodos e métodos do objeto de rosca do trabalhador.

*Nnumthreads*<br/>
O número solicitado de fios na piscina.

Se *nNumThreads* for negativo, seu valor absoluto será multiplicado pelo número de processadores na máquina para obter o número total de threads.

Se *nNumThreads* for zero, ATLS_DEFAULT_THREADSPERPROC será multiplicado pelo número de processadores na máquina para obter o número total de threads.  O padrão é 2 threads por processador. Se necessário, você pode definir seu próprio valor inteiro positivo para este símbolo antes de incluir atlutil.h.

*dwStackSize*<br/>
O tamanho da pilha para cada rosca na piscina.

*hConclusão*<br/>
A alça de um objeto para associar com a porta de conclusão.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="cthreadpoolqueryinterface"></a><a name="queryinterface"></a>CThreadPool::QueryInterface

Implementação de `IUnknown::QueryInterface`.

```
HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppv) throw();
```

### <a name="remarks"></a>Comentários

Objetos desta classe podem ser consultados com sucesso para as `IUnknown` interfaces [IThreadPoolConfig.](../../atl/reference/ithreadpoolconfig-interface.md)

## <a name="cthreadpoolqueuerequest"></a><a name="queuerequest"></a>CThreadPool::Consultasolicitação

Chame este método para enfileirar um item de trabalho a ser manuseado por um segmento na piscina.

```
BOOL QueueRequest(Worker::RequestType request) throw();
```

### <a name="parameters"></a>Parâmetros

*Solicitação*<br/>
O pedido para ser enfileirado.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Este método adiciona um item de trabalho à fila. Os threads na piscina escolhem itens da fila na ordem em que são recebidos.

## <a name="cthreadpoolrelease"></a><a name="release"></a>CThreadPool::Lançamento

Implementação de `IUnknown::Release`.

```
ULONG STDMETHODCALLTYPE Release() throw();
```

### <a name="return-value"></a>Valor retornado

Sempre retorna 1.

### <a name="remarks"></a>Comentários

Esta classe não implementa o controle vitalício usando a contagem de referências.

## <a name="cthreadpoolsetsize"></a><a name="setsize"></a>cThreadPool::SetSize

Chame este método para definir o número de threads na piscina.

```
HRESULT STDMETHODCALLTYPE SetSizeint nNumThreads) throw();
```

### <a name="parameters"></a>Parâmetros

*Nnumthreads*<br/>
O número solicitado de fios na piscina.

Se *nNumThreads* for negativo, seu valor absoluto será multiplicado pelo número de processadores na máquina para obter o número total de threads.

Se *nNumThreads* for zero, ATLS_DEFAULT_THREADSPERPROC será multiplicado pelo número de processadores na máquina para obter o número total de threads. O padrão é 2 threads por processador. Se necessário, você pode definir seu próprio valor inteiro positivo para este símbolo antes de incluir atlutil.h.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Se o número de threads especificados for menor do que o número de threads atualmente no pool, o objeto colocará uma mensagem de desligamento na fila a ser captada por um segmento de espera. Quando um segmento de espera puxa a mensagem para fora da fila, ele notifica o pool de segmentos e sai do procedimento de rosca. Esse processo é repetido até que o número de threads na piscina atinja o número especificado ou até que nenhum segmento tenha saído dentro do período especificado pelo [GetTimeout](#gettimeout)/ [SetTimeout](#settimeout). Nesta situação, o método retornará um HRESULT correspondente ao WAIT_TIMEOUT e a mensagem de desligamento pendente é cancelada.

## <a name="cthreadpoolsettimeout"></a><a name="settimeout"></a>CThreadPool::SetTimeout

Chame este método para definir o tempo máximo em milissegundos que o pool de segmentos esperará por um fio para desligar.

```
HRESULT STDMETHODCALLTYPE SetTimeout(DWORD dwMaxWait) throw();
```

### <a name="parameters"></a>Parâmetros

*dwMaxWait*<br/>
O tempo máximo solicitado em milissegundos para que a piscina de segmentos espere um fio ser desligado.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

O tempo háde é inicializado para ATLS_DEFAULT_THREADPOOLSHUTDOWNTIMEOUT. O tempo padrão é de 36 segundos. Se necessário, você pode definir seu próprio valor inteiro positivo para este símbolo antes de incluir atlutil.h.

Observe que *dwMaxWait* é o momento em que o pool esperará o desligamento de um único segmento. O tempo máximo que poderia ser levado para remover vários segmentos do pool pode ser ligeiramente menor que *o dwMaxWait* multiplicado pelo número de threads.

## <a name="cthreadpoolshutdown"></a><a name="shutdown"></a>CThreadPool::Desligamento

Chame este método para desligar a piscina de segmentos.

```
void Shutdown(DWORD dwMaxWait = 0) throw();
```

### <a name="parameters"></a>Parâmetros

*dwMaxWait*<br/>
O tempo máximo solicitado em milissegundos para que a piscina de segmentos espere um fio ser desligado. Se 0 ou nenhum valor for fornecido, este método usará o tempo definido por [CThreadPool::SetTimeout](#settimeout).

### <a name="remarks"></a>Comentários

Este método posta uma solicitação de desligamento em todos os segmentos da piscina. Se o tempo expirar, este método chamará [TerminateThread](/windows/win32/api/processthreadsapi/nf-processthreadsapi-terminatethread) em qualquer segmento que não tenha saído. Este método é chamado automaticamente do destruidor da classe.

## <a name="see-also"></a>Confira também

[IThreadPoolConfig Interface](../../atl/reference/ithreadpoolconfig-interface.md)<br/>
[Padrão'SThreadTraits](atl-typedefs.md#defaultthreadtraits)<br/>
[Classes](../../atl/reference/atl-classes.md)
