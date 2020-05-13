---
title: Classe CworkerThread
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
ms.openlocfilehash: 05e6b432d44927fa7e276792643e29c80c42d822
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330215"
---
# <a name="cworkerthread-class"></a>Classe CworkerThread

Essa classe cria um segmento de trabalhador ou usa um já existente, espera em uma ou mais alças de objeto do kernel e executa uma função cliente especificada quando uma das alças é sinalizada.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class ThreadTraits = DefaultThreadTraits>
class CWorkerThread
```

### <a name="parameters"></a>Parâmetros

*Traços de linha*<br/>
A classe que fornece a função de criação de threads, como [CRTThreadTraits](../../atl/reference/crtthreadtraits-class.md) ou [Win32ThreadTraits](../../atl/reference/win32threadtraits-class.md).

## <a name="members"></a>Membros

### <a name="protected-structures"></a>Estruturas Protegidas

|Nome|Descrição|
|----------|-----------------|
|`WorkerClientEntry`||

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CWorkerThread::CWorkerThread](#cworkerthread)|O construtor para o fio do trabalhador.|
|[CWorkerThread::~CWorkerThread](#dtor)|O destruidor para o fio do trabalhador.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[cworkerthread::AddHandle](#addhandle)|Chame este método para adicionar uma alça de objeto aguardável à lista mantida pelo segmento do trabalhador.|
|[CWorkerThread::AddTimer](#addtimer)|Chame este método para adicionar um temporizador de espera periódico à lista mantida pelo segmento do trabalhador.|
|[cworkerthread::getthreadhandle](#getthreadhandle)|Chame este método para obter a alça de rosca do segmento do trabalhador.|
|[CWorkerThread::GetThreadId](#getthreadid)|Chame este método para obter o ID de rosca do segmento do trabalhador.|
|[CWorkerThread::Inicializar](#initialize)|Chame este método para inicializar o segmento do trabalhador.|
|[cworkerthread::removehandle](#removehandle)|Chame este método para remover uma alça da lista de objetos aguardados.|
|[CWorkerThread::Desligamento](#shutdown)|Chame este método para desligar o segmento do trabalhador.|

## <a name="remarks"></a>Comentários

### <a name="to-use-cworkerthread"></a>Para usar cworkerthread

1. Crie uma instância dessa classe.

1. Chamar [CWorkerThread::Inicializar](#initialize).

1. Chamada [CWorkerThread::AddHandle](#addhandle) com a alça de um objeto de kernel e um ponteiro para uma implementação do [IWorkerThreadClient](../../atl/reference/iworkerthreadclient-interface.md).

   \- ou –

   Ligue para [o CWorkerThread::AddTimer](#addtimer) com um ponteiro para uma implementação do [IWorkerThreadClient](../../atl/reference/iworkerthreadclient-interface.md).

1. Implementar [iWorkerThreadClient::Execute](../../atl/reference/iworkerthreadclient-interface.md#execute) para tomar alguma ação quando o punho ou temporizador for sinalizado.

1. Para remover um objeto da lista de objetos aguardáveis, ligue para [CWorkerThread::RemoveHandle](#removehandle).

1. Para encerrar o segmento, ligue para [CWorkerThread::Shutdown](#shutdown).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil.h

## <a name="cworkerthreadaddhandle"></a><a name="addhandle"></a>cworkerthread::AddHandle

Chame este método para adicionar uma alça de objeto aguardável à lista mantida pelo segmento do trabalhador.

```
HRESULT AddHandle(
    HANDLE hObject,
    IWorkerThreadClient* pClient,
    DWORD_PTR dwParam) throw();
```

### <a name="parameters"></a>Parâmetros

*Hobject*<br/>
A alça de um objeto esperando.

*pClient*<br/>
O ponteiro para a interface [IWorkerThreadClient](../../atl/reference/iworkerthreadclient-interface.md) no objeto a ser chamado quando a alça é sinalizada.

*Dwparam*<br/>
O parâmetro a ser passado para [iWorkerThreadClient::Execute](../../atl/reference/iworkerthreadclient-interface.md#execute) quando a alça for sinalizada.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

[iWorkerThreadClient::Execute](../../atl/reference/iworkerthreadclient-interface.md#execute) será chamado através *de pClient* quando a alça, *hObject*, for sinalizada.

## <a name="cworkerthreadaddtimer"></a><a name="addtimer"></a>CWorkerThread::AddTimer

Chame este método para adicionar um temporizador de espera periódico à lista mantida pelo segmento do trabalhador.

```
HRESULT AddTimer(
    DWORD dwInterval,
    IWorkerThreadClient* pClient,
    DWORD_PTR dwParam,
    HANDLE* phTimer) throw();
```

### <a name="parameters"></a>Parâmetros

*dwInterval*<br/>
Especifica o período do temporizador em milissegundos.

*pClient*<br/>
O ponteiro para a interface [IWorkerThreadClient](../../atl/reference/iworkerthreadclient-interface.md) no objeto a ser chamado quando a alça é sinalizada.

*Dwparam*<br/>
O parâmetro a ser passado para [iWorkerThreadClient::Execute](../../atl/reference/iworkerthreadclient-interface.md#execute) quando a alça for sinalizada.

*phTimer*<br/>
[fora] Endereço da variável HANDLE que, com sucesso, recebe a alça para o temporizador recém-criado.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

[iWorkerThreadClient::Execute](../../atl/reference/iworkerthreadclient-interface.md#execute) será chamado através *de pClient* quando o temporizador for sinalizado.

Passe a alça do temporizador de *phTimer* para [CWorkerThread::RemoveHandle](#removehandle) para fechar o temporizador.

## <a name="cworkerthreadcworkerthread"></a><a name="cworkerthread"></a>CWorkerThread::CWorkerThread

O construtor.

```
CWorkerThread() throw();
```

## <a name="cworkerthreadcworkerthread"></a><a name="dtor"></a>CWorkerThread::~CWorkerThread

O destruidor.

```
~CWorkerThread() throw();
```

### <a name="remarks"></a>Comentários

Chama [CWorkerThread::Shutdown](#shutdown).

## <a name="cworkerthreadgetthreadhandle"></a><a name="getthreadhandle"></a>cworkerthread::getthreadhandle

Chame este método para obter a alça de rosca do segmento do trabalhador.

```
HANDLE GetThreadHandle() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a alça de rosca ou NULL se a rosca do trabalhador não tiver sido inicializada.

## <a name="cworkerthreadgetthreadid"></a><a name="getthreadid"></a>CWorkerThread::GetThreadId

Chame este método para obter o ID de rosca do segmento do trabalhador.

```
DWORD GetThreadId() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o ID de segmento ou NULL se o segmento do trabalhador não tiver sido inicializado.

## <a name="cworkerthreadinitialize"></a><a name="initialize"></a>CWorkerThread::Inicializar

Chame este método para inicializar o segmento do trabalhador.

```
HRESULT Initialize() throw();

HRESULT Initialize(CWorkerThread<ThreadTraits>* pThread) throw();
```

### <a name="parameters"></a>Parâmetros

*Pthread*<br/>
Um segmento de trabalhadores existente.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Esse método deve ser chamado para inicializar o objeto após a criação ou após uma chamada para [CWorkerThread::Shutdown](#shutdown).

Para ter dois `CWorkerThread` ou mais objetos use o mesmo segmento de trabalhador, inicialize um `Initialize` deles sem passar nenhum argumento e passe um ponteiro para esse objeto para os métodos dos outros. Os objetos inicializados usando o ponteiro devem ser desligados antes do objeto usado para inicializá-los.

Consulte [CWorkerThread::Shutdown](#shutdown) para obter informações sobre como o comportamento desse método muda quando inicializado usando um ponteiro para um objeto existente.

## <a name="cworkerthreadremovehandle"></a><a name="removehandle"></a>cworkerthread::removehandle

Chame este método para remover uma alça da lista de objetos aguardados.

```
HRESULT RemoveHandle(HANDLE hObject) throw();
```

### <a name="parameters"></a>Parâmetros

*Hobject*<br/>
A pega para remover.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Quando a alça for removida [IWorkerThreadClient::CloseHandle](../../atl/reference/iworkerthreadclient-interface.md#closehandle) será chamado no objeto associado que foi passado para [AddHandle](#addhandle). Se essa chamada `CWorkerThread` falhar, chamará a função [Windows CloseHandle](/windows/win32/api/handleapi/nf-handleapi-closehandle) na alça.

## <a name="cworkerthreadshutdown"></a><a name="shutdown"></a>CWorkerThread::Desligamento

Chame este método para desligar o segmento do trabalhador.

```
HRESULT Shutdown(DWORD dwWait = ATL_WORKER_THREAD_WAIT) throw();
```

### <a name="parameters"></a>Parâmetros

*dwWait*<br/>
A hora em milissegundos de esperar o fio do trabalhador ser desligado. ATL_WORKER_THREAD_WAIT padrão para 10 segundos. Se necessário, você pode definir seu próprio valor para este símbolo antes de incluir atlutil.h.

### <a name="return-value"></a>Valor retornado

Os retornos S_OK no sucesso, ou um erro HRESULT na falha, como se o valor de tempo, *dwWait,* for excedido.

### <a name="remarks"></a>Comentários

Para reutilizar o objeto, ligue para [CWorkerThread::Inicialize](#initialize) depois de chamar esse método.

Observe que `Shutdown` chamar um objeto inicializado `CWorkerThread` com um ponteiro para outro objeto não tem efeito e sempre retorna S_OK.

## <a name="see-also"></a>Confira também

[Padrão'SThreadTraits](atl-typedefs.md#defaultthreadtraits)<br/>
[Classes](../../atl/reference/atl-classes.md)<br/>
[Multithreading: criando threads de trabalho](../../parallel/multithreading-creating-worker-threads.md)<br/>
[Interface do cliente do iWorkerThread](../../atl/reference/iworkerthreadclient-interface.md)
