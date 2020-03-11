---
title: Classe CWorkerThread
ms.date: 11/04/2016
f1_keywords:
- CWorkerThread
- ATLUTIL/ATL::CWorkerThread
- ATLUTIL/ATL::CWorkerThread::CWorkerThread
- ATLUTIL/ATL::CWorkerThread::AddHandle
- ATLUTIL/ATL::CWorkerThread::AddTimer
- ATLUTIL/ATL::CWorkerThread::GetThreadHandle
- ATLUTIL/ATL::CWorkerThread::GetThreadId
- ATLUTIL/ATL::CWorkerThread::Initialize
- ATLUTIL/ATL::CWorkerThread::RemoveHandle
- ATLUTIL/ATL::CWorkerThread::Shutdown
helpviewer_keywords:
- CWorkerThread class
ms.assetid: be79a832-1345-4a36-a13e-a406cc65286f
ms.openlocfilehash: f1aa76514b98bbf12f8e516d3d54f68e8ef4dd7d
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78862900"
---
# <a name="cworkerthread-class"></a>Classe CWorkerThread

Essa classe cria um thread de trabalho ou usa um existente, aguarda em um ou mais identificadores de objeto de kernel e executa uma função de cliente especificada quando um dos identificadores é sinalizado.

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template <class ThreadTraits = DefaultThreadTraits>
class CWorkerThread
```

### <a name="parameters"></a>parâmetros

*ThreadTraits*<br/>
A classe que fornece a função de criação de thread, como [CRTThreadTraits](../../atl/reference/crtthreadtraits-class.md) ou [Win32ThreadTraits](../../atl/reference/win32threadtraits-class.md).

## <a name="members"></a>Membros

### <a name="protected-structures"></a>Estruturas protegidas

|Nome|DESCRIÇÃO|
|----------|-----------------|
|`WorkerClientEntry`||

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CWorkerThread::CWorkerThread](#cworkerthread)|O construtor para o thread de trabalho.|
|[CWorkerThread:: ~ CWorkerThread](#dtor)|O destruidor para o thread de trabalho.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CWorkerThread:: AddHandle](#addhandle)|Chame esse método para adicionar um identificador de objeto de espera à lista mantida pelo thread de trabalho.|
|[CWorkerThread:: AddTimer](#addtimer)|Chame esse método para adicionar um temporizador de espera periódico à lista mantida pelo thread de trabalho.|
|[CWorkerThread::GetThreadHandle](#getthreadhandle)|Chame esse método para obter o identificador de thread do thread de trabalho.|
|[CWorkerThread:: GetThreadId](#getthreadid)|Chame esse método para obter a ID de thread do thread de trabalho.|
|[CWorkerThread:: Initialize](#initialize)|Chame esse método para inicializar o thread de trabalho.|
|[CWorkerThread::RemoveHandle](#removehandle)|Chame esse método para remover um identificador da lista de objetos que esperam.|
|[CWorkerThread:: Shutdown](#shutdown)|Chame esse método para desligar o thread de trabalho.|

## <a name="remarks"></a>Comentários

### <a name="to-use-cworkerthread"></a>Para usar o CWorkerThread

1. Crie uma instância dessa classe.

1. Chame [CWorkerThread:: Initialize](#initialize).

1. Chame [CWorkerThread:: AddHandle](#addhandle) com o identificador de um objeto de kernel e um ponteiro para uma implementação de [IWorkerThreadClient](../../atl/reference/iworkerthreadclient-interface.md).

   \- ou –

   Chame [CWorkerThread:: AddTimer](#addtimer) com um ponteiro para uma implementação de [IWorkerThreadClient](../../atl/reference/iworkerthreadclient-interface.md).

1. Implemente [IWorkerThreadClient:: execute](../../atl/reference/iworkerthreadclient-interface.md#execute) para executar alguma ação quando o identificador ou o temporizador for sinalizado.

1. Para remover um objeto da lista de objetos que esperam, chame [CWorkerThread:: RemoveHandle](#removehandle).

1. Para encerrar o thread, chame [CWorkerThread:: Shutdown](#shutdown).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil. h

##  <a name="addhandle"></a>CWorkerThread:: AddHandle

Chame esse método para adicionar um identificador de objeto de espera à lista mantida pelo thread de trabalho.

```
HRESULT AddHandle(
    HANDLE hObject,
    IWorkerThreadClient* pClient,
    DWORD_PTR dwParam) throw();
```

### <a name="parameters"></a>parâmetros

*hObject*<br/>
O identificador para um objeto que é possível aguardar.

*pClient*<br/>
O ponteiro para a interface [IWorkerThreadClient](../../atl/reference/iworkerthreadclient-interface.md) no objeto a ser chamado quando o identificador é sinalizado.

*dwParam*<br/>
O parâmetro a ser passado para [IWorkerThreadClient:: execute](../../atl/reference/iworkerthreadclient-interface.md#execute) quando o identificador é sinalizado.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

[IWorkerThreadClient:: execute](../../atl/reference/iworkerthreadclient-interface.md#execute) será chamado por meio de *pClient* quando o Handle, *hObject*, for sinalizado.

##  <a name="addtimer"></a>CWorkerThread:: AddTimer

Chame esse método para adicionar um temporizador de espera periódico à lista mantida pelo thread de trabalho.

```
HRESULT AddTimer(
    DWORD dwInterval,
    IWorkerThreadClient* pClient,
    DWORD_PTR dwParam,
    HANDLE* phTimer) throw();
```

### <a name="parameters"></a>parâmetros

*dwInterval*<br/>
Especifica o período do temporizador em milissegundos.

*pClient*<br/>
O ponteiro para a interface [IWorkerThreadClient](../../atl/reference/iworkerthreadclient-interface.md) no objeto a ser chamado quando o identificador é sinalizado.

*dwParam*<br/>
O parâmetro a ser passado para [IWorkerThreadClient:: execute](../../atl/reference/iworkerthreadclient-interface.md#execute) quando o identificador é sinalizado.

*phTimer*<br/>
fora Endereço da variável de identificador que, em êxito, recebe o identificador para o temporizador recém-criado.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

[IWorkerThreadClient:: execute](../../atl/reference/iworkerthreadclient-interface.md#execute) será chamado por meio de *pClient* quando o timer for sinalizado.

Passe o identificador de temporizador de *phTimer* para [CWorkerThread:: RemoveHandle](#removehandle) para fechar o temporizador.

##  <a name="cworkerthread"></a>CWorkerThread::CWorkerThread

O construtor.

```
CWorkerThread() throw();
```

##  <a name="dtor"></a>CWorkerThread:: ~ CWorkerThread

O destruidor.

```
~CWorkerThread() throw();
```

### <a name="remarks"></a>Comentários

Chama [CWorkerThread:: Shutdown](#shutdown).

##  <a name="getthreadhandle"></a>CWorkerThread::GetThreadHandle

Chame esse método para obter o identificador de thread do thread de trabalho.

```
HANDLE GetThreadHandle() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o identificador de thread ou nulo se o thread de trabalho não tiver sido inicializado.

##  <a name="getthreadid"></a>CWorkerThread:: GetThreadId

Chame esse método para obter a ID de thread do thread de trabalho.

```
DWORD GetThreadId() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a ID do thread ou NULL se o thread de trabalho não tiver sido inicializado.

##  <a name="initialize"></a>CWorkerThread:: Initialize

Chame esse método para inicializar o thread de trabalho.

```
HRESULT Initialize() throw();

HRESULT Initialize(CWorkerThread<ThreadTraits>* pThread) throw();
```

### <a name="parameters"></a>parâmetros

*pThread*<br/>
Um thread de trabalho existente.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Esse método deve ser chamado para inicializar o objeto após a criação ou após uma chamada para [CWorkerThread:: Shutdown](#shutdown).

Para que dois ou mais objetos de `CWorkerThread` usem o mesmo thread de trabalho, inicialize um deles sem passar nenhum argumento e, em seguida, passe um ponteiro para esse objeto para os métodos `Initialize` dos outros. Os objetos inicializados usando o ponteiro devem ser desligados antes do objeto usado para inicializá-los.

Consulte [CWorkerThread:: Shutdown](#shutdown) para obter informações sobre como o comportamento desse método é alterado quando inicializado usando um ponteiro para um objeto existente.

##  <a name="removehandle"></a>CWorkerThread::RemoveHandle

Chame esse método para remover um identificador da lista de objetos que esperam.

```
HRESULT RemoveHandle(HANDLE hObject) throw();
```

### <a name="parameters"></a>parâmetros

*hObject*<br/>
O identificador a ser removido.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Quando o identificador é removido, [IWorkerThreadClient:: CloseHandle](../../atl/reference/iworkerthreadclient-interface.md#closehandle) será chamado no objeto associado que foi passado para [AddHandle](#addhandle). Se essa chamada falhar, `CWorkerThread` chamará a função [CloseHandle](/windows/win32/api/handleapi/nf-handleapi-closehandle) do Windows na alça.

##  <a name="shutdown"></a>CWorkerThread:: Shutdown

Chame esse método para desligar o thread de trabalho.

```
HRESULT Shutdown(DWORD dwWait = ATL_WORKER_THREAD_WAIT) throw();
```

### <a name="parameters"></a>parâmetros

*dwWait*<br/>
O tempo em milissegundos para aguardar o encerramento do thread de trabalho. ATL_WORKER_THREAD_WAIT usa 10 segundos como padrão. Se necessário, você pode definir seu próprio valor para esse símbolo antes de incluir atlutil. h.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha, como se o valor de tempo limite, *dwWait*, for excedido.

### <a name="remarks"></a>Comentários

Para reutilizar o objeto, chame [CWorkerThread:: Initialize](#initialize) depois de chamar esse método.

Observe que a chamada de `Shutdown` em um objeto inicializado com um ponteiro para outro objeto `CWorkerThread` não tem nenhum efeito e sempre retorna S_OK.

## <a name="see-also"></a>Confira também

[DefaultThreadTraits](atl-typedefs.md#defaultthreadtraits)<br/>
[Classes](../../atl/reference/atl-classes.md)<br/>
[Multithreading: criando threads de trabalho](../../parallel/multithreading-creating-worker-threads.md)<br/>
[Interface IWorkerThreadClient](../../atl/reference/iworkerthreadclient-interface.md)
