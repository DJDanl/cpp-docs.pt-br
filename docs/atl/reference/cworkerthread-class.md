---
title: Classe CWorkerThread | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CWorkerThread<ThreadTraits>
- ATL::CWorkerThread
- ATL.CWorkerThread
- ATL.CWorkerThread<ThreadTraits>
- CWorkerThread
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: ab1c92c1b7442025f91007ef971d81d087351212
ms.lasthandoff: 02/25/2017

---
# <a name="cworkerthread-class"></a>Classe CWorkerThread
Essa classe cria um thread de trabalho ou usa uma existente, espera um ou mais identificadores de objeto de kernel e executa uma função de cliente especificado quando uma das alças é sinalizada.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
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
|[CWorkerThread::AddHandle](#addhandle)|Chame esse método para adicionar o identificador de um objeto de espera à lista mantida pelo thread de trabalho.|  
|[CWorkerThread::AddTimer](#addtimer)|Chame esse método para adicionar um temporizador periódico de espera à lista mantida pelo thread de trabalho.|  
|[CWorkerThread::GetThreadHandle](#getthreadhandle)|Chame esse método para obter o identificador de thread do thread de trabalho.|  
|[CWorkerThread::GetThreadId](#getthreadid)|Chame esse método para obter a ID do thread do thread de trabalho.|  
|[CWorkerThread::Initialize](#initialize)|Chame esse método para inicializar o thread de trabalho.|  
|[CWorkerThread::RemoveHandle](#removehandle)|Chame esse método para remover um identificador da lista de objetos de espera.|  
|[CWorkerThread::Shutdown](#shutdown)|Chame esse método para desligar o thread de trabalho.|  
  
## <a name="remarks"></a>Comentários  
  
### <a name="to-use-cworkerthread"></a>Usar CWorkerThread  
  
1.  Crie uma instância dessa classe.  
  
2.  Chamar [CWorkerThread::Initialize](#initialize).  
  
3.  Chamar [CWorkerThread::AddHandle](#addhandle) com o identificador de um objeto de kernel e um ponteiro para uma implementação de [IWorkerThreadClient](../../atl/reference/iworkerthreadclient-interface.md).  
  
     – ou –  
  
     Chamar [CWorkerThread::AddTimer](#addtimer) com um ponteiro para uma implementação de [IWorkerThreadClient](../../atl/reference/iworkerthreadclient-interface.md).  
  
4.  Implementar [IWorkerThreadClient::Execute](../../atl/reference/iworkerthreadclient-interface.md#execute) para executar alguma ação quando o timer ou identificador é sinalizado.  
  
5.  Para remover um objeto da lista de objetos de espera, chame [CWorkerThread::RemoveHandle](#removehandle).  
  
6.  Para encerrar o thread, chame [CWorkerThread::Shutdown](#shutdown).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlutil.h  
  
##  <a name="a-nameaddhandlea--cworkerthreadaddhandle"></a><a name="addhandle"></a>CWorkerThread::AddHandle  
 Chame esse método para adicionar o identificador de um objeto de espera à lista mantida pelo thread de trabalho.  
  
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
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 [IWorkerThreadClient::Execute](../../atl/reference/iworkerthreadclient-interface.md#execute) será chamado por meio de `pClient` quando o identificador de `hObject`, é sinalizado.  
  
##  <a name="a-nameaddtimera--cworkerthreadaddtimer"></a><a name="addtimer"></a>CWorkerThread::AddTimer  
 Chame esse método para adicionar um temporizador periódico de espera à lista mantida pelo thread de trabalho.  
  
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
 [out] Endereço da variável de identificador que, em caso de sucesso, recebe o identificador para o temporizador recém-criado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 [IWorkerThreadClient::Execute](../../atl/reference/iworkerthreadclient-interface.md#execute) será chamado por meio de `pClient` quando o temporizador é sinalizado.  
  
 Passar o identificador de timer de `phTimer` para [CWorkerThread::RemoveHandle](#removehandle) para fechar o temporizador.  
  
##  <a name="a-namecworkerthreada--cworkerthreadcworkerthread"></a><a name="cworkerthread"></a>CWorkerThread::CWorkerThread  
 O construtor.  
  
```
CWorkerThread() throw();
```  
  
##  <a name="a-namedtora--cworkerthreadcworkerthread"></a><a name="dtor"></a>CWorkerThread:: ~ CWorkerThread  
 O destruidor.  
  
```
~CWorkerThread() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Chamadas [CWorkerThread::Shutdown](#shutdown).  
  
##  <a name="a-namegetthreadhandlea--cworkerthreadgetthreadhandle"></a><a name="getthreadhandle"></a>CWorkerThread::GetThreadHandle  
 Chame esse método para obter o identificador de thread do thread de trabalho.  
  
```
HANDLE GetThreadHandle() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o identificador de thread ou NULL se o thread de trabalho não foi inicializado.  
  
##  <a name="a-namegetthreadida--cworkerthreadgetthreadid"></a><a name="getthreadid"></a>CWorkerThread::GetThreadId  
 Chame esse método para obter a ID do thread do thread de trabalho.  
  
```
DWORD GetThreadId() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a ID do thread ou NULL se o thread de trabalho não foi inicializado.  
  
##  <a name="a-nameinitializea--cworkerthreadinitialize"></a><a name="initialize"></a>CWorkerThread::Initialize  
 Chame esse método para inicializar o thread de trabalho.  
  
```
HRESULT Initialize() throw();

HRESULT Initialize(CWorkerThread<ThreadTraits>* pThread) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pThread`  
 Um thread de trabalho existente.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Esse método deve ser chamado para inicializar o objeto após a criação ou após uma chamada para [CWorkerThread::Shutdown](#shutdown).  
  
 Ter dois ou mais `CWorkerThread` objetos usam o mesmo thread de trabalho, inicializar um sem passar argumentos, em seguida, passam um ponteiro para esse objeto para o `Initialize` métodos dos outros. Os objetos inicializados usando o ponteiro devem ser desligados antes do objeto usado para inicializá-los.  
  
 Consulte [CWorkerThread::Shutdown](#shutdown) para obter informações sobre como o comportamento do método muda quando inicializado usando um ponteiro para um objeto existente.  
  
##  <a name="a-nameremovehandlea--cworkerthreadremovehandle"></a><a name="removehandle"></a>CWorkerThread::RemoveHandle  
 Chame esse método para remover um identificador da lista de objetos de espera.  
  
```
HRESULT RemoveHandle(HANDLE hObject) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `hObject`  
 O identificador para remover.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Quando o identificador é removido [IWorkerThreadClient::CloseHandle](../../atl/reference/iworkerthreadclient-interface.md#closehandle) será chamado no objeto associado que foi passado para [AddHandle](#addhandle). Se essa chamada falhará, `CWorkerThread` chamará o Windows [CloseHandle](http://msdn.microsoft.com/library/windows/desktop/ms724211) função no identificador.  
  
##  <a name="a-nameshutdowna--cworkerthreadshutdown"></a><a name="shutdown"></a>CWorkerThread::Shutdown  
 Chame esse método para desligar o thread de trabalho.  
  
```
HRESULT Shutdown(DWORD dwWait = ATL_WORKER_THREAD_WAIT) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwWait`  
 O tempo em milissegundos para aguardar o thread de trabalho desligar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em sucesso, ou um erro HRESULT em caso de falha, como se o valor de tempo limite, `dwWait`, for excedido.  
  
### <a name="remarks"></a>Comentários  
 Para reutilizar o objeto, chame [CWorkerThread::Initialize](#initialize) depois de chamar esse método.  
  
 Observe que a chamada **desligamento** em um objeto inicializado com um ponteiro para outro `CWorkerThread` objeto não tem nenhum efeito e sempre retorna S_OK.  
  
## <a name="see-also"></a>Consulte também  
 [DefaultThreadTraits](atl-typedefs.md#defaultthreadtraits)   
 [Classes](../../atl/reference/atl-classes.md)   
 [Multithread: Criando Threads de trabalho](../../parallel/multithreading-creating-worker-threads.md)   
 [Interface IWorkerThreadClient](../../atl/reference/iworkerthreadclient-interface.md)

