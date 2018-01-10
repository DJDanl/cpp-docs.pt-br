---
title: Classe CThreadPool | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs: C++
helpviewer_keywords: CThreadPool class
ms.assetid: 06683718-01b9-413c-9481-2dc1734ec70f
caps.latest.revision: "22"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 6739e179843864c952a5e864de1389b466d7ca7c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cthreadpool-class"></a>Classe CThreadPool
Essa classe fornece um pool de threads de trabalho que processam uma fila de itens de trabalho.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Worker, class ThreadTraits = DefaultThreadTraits>  
class CThreadPool : public IThreadPoolConfig
```  
  
#### <a name="parameters"></a>Parâmetros  
 *Operador*  
 A classe de acordo com o [arquétipo trabalho](../../atl/reference/worker-archetype.md) fornecendo o código usado para processar itens em fila no pool de threads de trabalho.  
  
 `ThreadTraits`  
 A classe que fornece a função usada para criar os threads no pool.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CThreadPool::CThreadPool](#cthreadpool)|O construtor para o pool de threads.|  
|[CThreadPool:: ~ CThreadPool](#dtor)|O destruidor para o pool de threads.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CThreadPool::AddRef](#addref)|Implementação de `IUnknown::AddRef`.|  
|[CThreadPool::GetNumThreads](#getnumthreads)|Chame este método para obter o número de threads no pool.|  
|[CThreadPool::GetQueueHandle](#getqueuehandle)|Chame este método para obter o identificador da porta de conclusão de e/s usada para enfileirar itens de trabalho.|  
|[CThreadPool::GetSize](#getsize)|Chame este método para obter o número de threads no pool.|  
|[CThreadPool::GetTimeout](#gettimeout)|Chame este método para obter o tempo máximo em milissegundos que o pool de threads esperará por um thread desligar.|  
|[CThreadPool::Initialize](#initialize)|Chame este método para inicializar o pool de threads.|  
|[CThreadPool::QueryInterface](#queryinterface)|Implementação de **IUnknown:: QueryInterface**.|  
|[CThreadPool::QueueRequest](#queuerequest)|Chame esse método para enfileirar um item de trabalho a ser manipulada por um thread do pool.|  
|[CThreadPool::Release](#release)|Implementação de `IUnknown::Release`.|  
|[CThreadPool::SetSize](#setsize)|Chame esse método para definir o número de threads no pool.|  
|[CThreadPool::SetTimeout](#settimeout)|Chame esse método para definir o tempo máximo em milissegundos que o pool de threads esperará por um thread desligar.|  
|[CThreadPool::Shutdown](#shutdown)|Chame este método para desligar o pool de threads.|  
  
## <a name="remarks"></a>Comentários  
 Threads no pool são criados e destruídos quando o pool é inicializado, redimensionado ou desligado. Uma instância da classe *trabalho* será criado na pilha de cada thread de trabalho no pool. Cada instância ficará ativo para o tempo de vida do thread.  
  
 Imediatamente após a criação de um segmento, *trabalho*:: `Initialize` será chamado no objeto associado a esse thread. Imediatamente antes de destruição de um thread, *trabalho*:: `Terminate` será chamado. Ambos os métodos devem aceitar uma **void\***  argumento. O valor desse argumento é passado para o pool de threads por meio de `pvWorkerParam` parâmetro [CThreadPool::Initialize](#initialize).  
  
 Quando há itens de trabalho em threads de fila e de trabalho disponível para o trabalho, um thread de trabalho extrairá um item de fila e a chamada a **Execute** método o *trabalho* objeto para esse thread. Três itens, em seguida, são passados para o método: o item da fila, o mesmo `pvWorkerParam` passado para *trabalho*:: `Initialize` e *trabalho*:: `Terminate`e um ponteiro para o [OVERLAPPED](http://msdn.microsoft.com/library/windows/desktop/ms684342) estrutura usada para a fila de porta de conclusão de e/s.  
  
 O *trabalho* classe declara o tipo dos itens que serão enfileiradas no pool de threads, fornecendo um typedef *trabalho*:: `RequestType`. Esse tipo deve ser capaz de conversão para e de um **ULONG_PTR**.  
  
 Um exemplo de um *trabalho* classe é [CNonStatelessWorker classe](../../atl/reference/cnonstatelessworker-class.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IUnknown`  
  
 [IThreadPoolConfig](../../atl/reference/ithreadpoolconfig-interface.md)  
  
 `CThreadPool`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlutil.h  
  
##  <a name="addref"></a>CThreadPool::AddRef  
 Implementação de `IUnknown::AddRef`.  
  
```
ULONG STDMETHODCALLTYPE AddRef() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna 1.  
  
### <a name="remarks"></a>Comentários  
 Essa classe não implementa o controle de tempo de vida usando contagem de referência.  
  
##  <a name="cthreadpool"></a>CThreadPool::CThreadPool  
 O construtor para o pool de threads.  
  
```
CThreadPool() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Inicializa o valor de tempo limite para `ATLS_DEFAULT_THREADPOOLSHUTDOWNTIMEOUT`. O tempo padrão é de 36 segundos. Se necessário, você pode definir seu próprio valor inteiro positivo para esse símbolo antes de incluir atlutil.h.  
  
##  <a name="dtor"></a>CThreadPool:: ~ CThreadPool  
 O destruidor para o pool de threads.  
  
```
~CThreadPool() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Chamadas [CThreadPool::Shutdown](#shutdown).  
  
##  <a name="getnumthreads"></a>CThreadPool::GetNumThreads  
 Chame este método para obter o número de threads no pool.  
  
```
int GetNumThreads() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de threads no pool.  
  
##  <a name="getqueuehandle"></a>CThreadPool::GetQueueHandle  
 Chame este método para obter o identificador da porta de conclusão de e/s usada para enfileirar itens de trabalho.  
  
```
HANDLE GetQueueHandle() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o identificador da fila ou nulo se o pool de thread não foi inicializado.  
  
##  <a name="getsize"></a>CThreadPool::GetSize  
 Chame este método para obter o número de threads no pool.  
  
```
HRESULT STDMETHODCALLTYPE GetSize(int* pnNumThreads) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pnNumThreads`  
 [out] Endereço da variável que, em caso de sucesso, recebe o número de threads no pool.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
##  <a name="gettimeout"></a>CThreadPool::GetTimeout  
 Chame este método para obter o tempo máximo em milissegundos que o pool de threads esperará por um thread desligar.  
  
```
HRESULT STDMETHODCALLTYPE GetTimeout(DWORD* pdwMaxWait) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pdwMaxWait`  
 [out] Endereço da variável que, em caso de sucesso, recebe o tempo máximo, em milissegundos, que aguarda um thread desligar o pool de threads.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Esse valor de tempo limite é usado pelo [CThreadPool::Shutdown](#shutdown) se nenhum outro valor for fornecido para esse método.  
  
##  <a name="initialize"></a>CThreadPool::Initialize  
 Chame este método para inicializar o pool de threads.  
  
```
HRESULT Initialize(
    void* pvWorkerParam = NULL,
    int nNumThreads = 0,
    DWORD dwStackSize = 0,
    HANDLE hCompletion = INVALID_HANDLE_VALUE) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pvWorkerParam`  
 O parâmetro de trabalho a ser passado para o objeto de thread de trabalho `Initialize`, **Execute**, e `Terminate` métodos.  
  
 `nNumThreads`  
 O número solicitado de threads no pool.  
  
 Se `nNumThreads` for negativo, seu valor absoluto será multiplicado pelo número de processadores na máquina para obter o número total de threads.  
  
 Se `nNumThreads` for zero, `ATLS_DEFAULT_THREADSPERPROC` será multiplicado pelo número de processadores na máquina para obter o número total de threads.  O padrão é 2 threads por processador. Se necessário, você pode definir seu próprio valor inteiro positivo para esse símbolo antes de incluir atlutil.h.
  
 `dwStackSize`  
 O tamanho da pilha para cada thread do pool.  
  
 *hCompletion*  
 O identificador de um objeto para associar a porta de conclusão.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
##  <a name="queryinterface"></a>CThreadPool::QueryInterface  
 Implementação de **IUnknown:: QueryInterface**.  
  
```
HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppv) throw();
```  
  
### <a name="remarks"></a>Comentários  
 Objetos desta classe podem ser consultados com êxito para o **IUnknown** e [IThreadPoolConfig](../../atl/reference/ithreadpoolconfig-interface.md) interfaces.  
  
##  <a name="queuerequest"></a>CThreadPool::QueueRequest  
 Chame esse método para enfileirar um item de trabalho a ser manipulada por um thread do pool.  
  
```
BOOL QueueRequest(Worker::RequestType request) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `request`  
 A solicitação a ser enfileirado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro no caso de sucesso, falso em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Este método adiciona um item de trabalho para a fila. Os threads no pool de escolher itens da fila na ordem em que são recebidos.  
  
##  <a name="release"></a>CThreadPool::Release  
 Implementação de `IUnknown::Release`.  
  
```
ULONG STDMETHODCALLTYPE Release() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna 1.  
  
### <a name="remarks"></a>Comentários  
 Essa classe não implementa o controle de tempo de vida usando contagem de referência.  
  
##  <a name="setsize"></a>CThreadPool::SetSize  
 Chame esse método para definir o número de threads no pool.  
  
```
HRESULT STDMETHODCALLTYPE SetSizeint nNumThreads) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nNumThreads`  
 O número solicitado de threads no pool.  
  
 Se `nNumThreads` for negativo, seu valor absoluto será multiplicado pelo número de processadores na máquina para obter o número total de threads.  
  
 Se `nNumThreads` for zero, `ATLS_DEFAULT_THREADSPERPROC` será multiplicado pelo número de processadores na máquina para obter o número total de threads. O padrão é 2 threads por processador. Se necessário, você pode definir seu próprio valor inteiro positivo para esse símbolo antes de incluir atlutil.h.
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Se o número de threads especificado é menor que o número de threads atualmente no pool, o objeto coloca uma mensagem de desligamento na fila para serem selecionadas por um thread de espera. Quando um thread de espera obtém a mensagem da fila, ele notifica o pool de threads e finaliza o procedimento de thread. Esse processo é repetido até que o número de threads no pool de atinge o número especificado ou até que nenhum thread foi encerrado dentro do período especificado pelo [GetTimeout](#gettimeout)/ [SetTimeout](#settimeout). Nessa situação o método retornará um HRESULT correspondente ao **WAIT_TIMEOUT** e a mensagem de desligamento pendente é cancelada.  
  
##  <a name="settimeout"></a>CThreadPool::SetTimeout  
 Chame esse método para definir o tempo máximo em milissegundos que o pool de threads esperará por um thread desligar.  
  
```
HRESULT STDMETHODCALLTYPE SetTimeout(DWORD dwMaxWait) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwMaxWait`  
 O tempo máximo solicitado em milissegundos que o pool de threads esperará por um thread desligar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O tempo limite é inicializado como `ATLS_DEFAULT_THREADPOOLSHUTDOWNTIMEOUT`. O tempo padrão é de 36 segundos. Se necessário, você pode definir seu próprio valor inteiro positivo para esse símbolo antes de incluir atlutil.h. 
  
 Observe que `dwMaxWait` é a hora em que o pool esperará por um único thread desligar. O tempo máximo que pode ser tomado para remover vários threads do pool pode ser um pouco menos de `dwMaxWait` multiplicado pelo número de threads.  
  
##  <a name="shutdown"></a>CThreadPool::Shutdown  
 Chame este método para desligar o pool de threads.  
  
```
void Shutdown(DWORD dwMaxWait = 0) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwMaxWait`  
 O tempo máximo solicitado em milissegundos que o pool de threads esperará por um thread desligar. Se 0 ou nenhum valor for fornecido, esse método usará o tempo limite definido [CThreadPool::SetTimeout](#settimeout).  
  
### <a name="remarks"></a>Comentários  
 Esse método envia uma solicitação de desligamento para todos os threads no pool. Se o tempo limite expirar, esse método chamará [TerminateThread](http://msdn.microsoft.com/library/windows/desktop/ms686717) em qualquer thread que não foi encerrado. Este método é chamado automaticamente do destruidor da classe.  
  
## <a name="see-also"></a>Consulte também  
 [Interface IThreadPoolConfig](../../atl/reference/ithreadpoolconfig-interface.md)   
 [DefaultThreadTraits](atl-typedefs.md#defaultthreadtraits)   
 [Classes](../../atl/reference/atl-classes.md)
