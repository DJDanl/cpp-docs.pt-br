---
title: Classe CWorkerThread | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- CWorkerThread class
ms.assetid: be79a832-1345-4a36-a13e-a406cc65286f
caps.latest.revision: 24
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: 25d102e7e47898ee2f93326756b3d50e8bb3bbff
ms.lasthandoff: 04/01/2017

---
# <a name="cworkerthread-class"></a>Classe CWorkerThread
Essa classe cria um thread de trabalho ou usa um existente, espera um ou mais identificadores de objeto kernel e executa uma função de cliente especificado quando uma das alças é sinalizada.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class ThreadTraits = DefaultThreadTraits>  
class CWorkerThread
```  
  
#### <a name="parameters"></a>Parâmetros  
 `ThreadTraits`  
 A classe que fornece a função de criação de thread, como [CRTThreadTraits](../../atl/reference/crtthreadtraits-class.md) ou [Win32ThreadTraits](../../atl/reference/win32threadtraits-class.md).  
  
## <a name="members"></a>Membros  
  
### <a name="protected-structures"></a>Estruturas protegidas  
  
|Nome|Descrição|  
|----------|-----------------|  
|`WorkerClientEntry`||  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWorkerThread::CWorkerThread](#cworkerthread)|O construtor para o thread de trabalho.|  
|[CWorkerThread:: ~ CWorkerThread](#dtor)|O destruidor para o thread de trabalho.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWorkerThread::AddHandle](#addhandle)|Chame este método para adicionar o identificador de um objeto de espera à lista mantida pelo thread de trabalho.|  
|[CWorkerThread::AddTimer](#addtimer)|Chame esse método para adicionar um temporizador de espera periódico à lista mantida pelo thread de trabalho.|  
|[CWorkerThread::GetThreadHandle](#getthreadhandle)|Chame este método para obter o identificador de thread do thread de trabalho.|  
|[CWorkerThread::GetThreadId](#getthreadid)|Chame este método para obter a ID do thread do thread de trabalho.|  
|[CWorkerThread::Initialize](#initialize)|Chame este método para inicializar o thread de trabalho.|  
|[CWorkerThread::RemoveHandle](#removehandle)|Chame esse método para remover um identificador da lista de objetos de espera.|  
|[CWorkerThread::Shutdown](#shutdown)|Chame este método para desligar o thread de trabalho.|  
  
## <a name="remarks"></a>Comentários  
  
### <a name="to-use-cworkerthread"></a>Para usar CWorkerThread  
  
1.  Crie uma instância dessa classe.  
  
2.  Chamar [CWorkerThread::Initialize](#initialize).  
  
3.  Chamar [CWorkerThread::AddHandle](#addhandle) com o identificador de um objeto de kernel e um ponteiro para uma implementação de [IWorkerThreadClient](../../atl/reference/iworkerthreadclient-interface.md).  
  
     - ou –  
  
     Chamar [CWorkerThread::AddTimer](#addtimer) com um ponteiro para uma implementação de [IWorkerThreadClient](../../atl/reference/iworkerthreadclient-interface.md).  
  
4.  Implementar [IWorkerThreadClient::Execute](../../atl/reference/iworkerthreadclient-interface.md#execute) para executar alguma ação quando o identificador ou um temporizador é sinalizado.  
  
5.  Para remover um objeto da lista de objetos de espera, chame [CWorkerThread::RemoveHandle](#removehandle).  
  
6.  Para encerrar o thread, chame [CWorkerThread::Shutdown](#shutdown).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlutil.h  
  
##  <a name="addhandle"></a>CWorkerThread::AddHandle  
 Chame este método para adicionar o identificador de um objeto de espera à lista mantida pelo thread de trabalho.  
  
```
HRESULT AddHandle(
    HANDLE hObject,
    IWorkerThreadClient* pClient,
    DWORD_PTR dwParam) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `hObject`  
 O identificador para um objeto de espera.  
  
 `pClient`  
 O ponteiro para o [IWorkerThreadClient](../../atl/reference/iworkerthreadclient-interface.md) interface no objeto a ser chamado quando o identificador é sinalizado.  
  
 `dwParam`  
 O parâmetro a ser passado para [IWorkerThreadClient::Execute](../../atl/reference/iworkerthreadclient-interface.md#execute) quando o identificador é sinalizado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 [IWorkerThreadClient::Execute](../../atl/reference/iworkerthreadclient-interface.md#execute) será chamado por meio de `pClient` quando o identificador de `hObject`, é sinalizado.  
  
##  <a name="addtimer"></a>CWorkerThread::AddTimer  
 Chame esse método para adicionar um temporizador de espera periódico à lista mantida pelo thread de trabalho.  
  
```
HRESULT AddTimer(
    DWORD dwInterval,
    IWorkerThreadClient* pClient,
    DWORD_PTR dwParam,
    HANDLE* phTimer) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwInterval*  
 Especifica o período do temporizador em milissegundos.  
  
 `pClient`  
 O ponteiro para o [IWorkerThreadClient](../../atl/reference/iworkerthreadclient-interface.md) interface no objeto a ser chamado quando o identificador é sinalizado.  
  
 `dwParam`  
 O parâmetro a ser passado para [IWorkerThreadClient::Execute](../../atl/reference/iworkerthreadclient-interface.md#execute) quando o identificador é sinalizado.  
  
 `phTimer`  
 [out] Endereço da variável de identificador que, em caso de sucesso, recebe o identificador para o timer recém-criado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 [IWorkerThreadClient::Execute](../../atl/reference/iworkerthreadclient-interface.md#execute) será chamado por meio de `pClient` quando o timer é sinalizado.  
  
 Passar o identificador de timer de `phTimer` para [CWorkerThread::RemoveHandle](#removehandle) para fechar o timer.  
  
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
 Chamadas [CWorkerThread::Shutdown](#shutdown).  
  
##  <a name="getthreadhandle"></a>CWorkerThread::GetThreadHandle  
 Chame este método para obter o identificador de thread do thread de trabalho.  
  
```
HANDLE GetThreadHandle() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o identificador de thread ou NULL se o thread de trabalho não foi inicializado.  
  
##  <a name="getthreadid"></a>CWorkerThread::GetThreadId  
 Chame este método para obter a ID do thread do thread de trabalho.  
  
```
DWORD GetThreadId() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a ID do thread ou nulo se o thread de trabalho não foi inicializado.  
  
##  <a name="initialize"></a>CWorkerThread::Initialize  
 Chame este método para inicializar o thread de trabalho.  
  
```
HRESULT Initialize() throw();

HRESULT Initialize(CWorkerThread<ThreadTraits>* pThread) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pThread`  
 Um thread de trabalho existente.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Esse método deve ser chamado para inicializar o objeto após a criação ou após uma chamada para [CWorkerThread::Shutdown](#shutdown).  
  
 Ter dois ou mais `CWorkerThread` objetos usam o mesmo thread de trabalho, inicializar um sem passar argumentos, em seguida, passam um ponteiro para o objeto para o `Initialize` métodos dos outros. Os objetos inicializados usando o ponteiro devem ser desligados antes do objeto usado para inicializá-los.  
  
 Consulte [CWorkerThread::Shutdown](#shutdown) para obter informações sobre como o comportamento desse método muda quando inicializada usando um ponteiro para um objeto existente.  
  
##  <a name="removehandle"></a>CWorkerThread::RemoveHandle  
 Chame esse método para remover um identificador da lista de objetos de espera.  
  
```
HRESULT RemoveHandle(HANDLE hObject) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `hObject`  
 O identificador a ser removido.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Quando o identificador é removido [IWorkerThreadClient::CloseHandle](../../atl/reference/iworkerthreadclient-interface.md#closehandle) será chamado no objeto associado foi passado para [AddHandle](#addhandle). Se essa chamada falhar, `CWorkerThread` chamará o Windows [CloseHandle](http://msdn.microsoft.com/library/windows/desktop/ms724211) função no identificador.  
  
##  <a name="shutdown"></a>CWorkerThread::Shutdown  
 Chame este método para desligar o thread de trabalho.  
  
```
HRESULT Shutdown(DWORD dwWait = ATL_WORKER_THREAD_WAIT) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwWait`  
 O tempo em milissegundos para aguardar o thread de trabalho desligar. ATL_WORKER_THREAD_WAIT padrão é 10 segundos. Se necessário, você pode definir seu próprio valor para esse símbolo antes de incluir atlutil.h. 
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK no sucesso ou erro HRESULT em caso de falha, como se o valor de tempo limite, `dwWait`, foi excedido.  
  
### <a name="remarks"></a>Comentários  
 Para reutilizar o objeto, chame [CWorkerThread::Initialize](#initialize) depois de chamar esse método.  
  
 Observe que a chamada **desligamento** em um objeto inicializado com um ponteiro para outro `CWorkerThread` objeto não tem nenhum efeito e sempre retorna S_OK.  
  
## <a name="see-also"></a>Consulte também  
 [DefaultThreadTraits](atl-typedefs.md#defaultthreadtraits)   
 [Classes](../../atl/reference/atl-classes.md)   
 [Multithread: Criando Threads de trabalho](../../parallel/multithreading-creating-worker-threads.md)   
 [Interface IWorkerThreadClient](../../atl/reference/iworkerthreadclient-interface.md)

