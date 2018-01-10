---
title: Estrutura IThreadProxy | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- IThreadProxy
- CONCRTRM/concurrency::IThreadProxy
- CONCRTRM/concurrency::IThreadProxy::IThreadProxy::GetId
- CONCRTRM/concurrency::IThreadProxy::IThreadProxy::SwitchOut
- CONCRTRM/concurrency::IThreadProxy::IThreadProxy::SwitchTo
- CONCRTRM/concurrency::IThreadProxy::IThreadProxy::YieldToSystem
dev_langs: C++
helpviewer_keywords: IThreadProxy structure
ms.assetid: feb89241-a555-4e61-ad48-40add54daeca
caps.latest.revision: "21"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: bc0808d7b6eae3db64695d2d3e0b40d092361a6c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ithreadproxy-structure"></a>Estrutura IThreadProxy
Uma abstração para um thread de execução. Dependendo do `SchedulerType` chave da diretiva do Agendador que você criar o Gerenciador de recursos será conceder a você um proxy de thread que é apoiado por um thread de Win32 regular ou um thread (UMS) agendáveis do modo de usuário. Threads UMS são com suporte em sistemas operacionais de 64 bits com a versão do Windows 7 e superior.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct IThreadProxy;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Ithreadproxy](#getid)|Retorna um identificador exclusivo para o proxy de thread.|  
|[Ithreadproxy](#switchout)|Desassocia o contexto da raiz do processador virtual subjacente.|  
|[: Switchto](#switchto)|Executa uma alternância de contexto cooperativo do contexto de execução atual para outro.|  
|[: Yieldtosystem](#yieldtosystem)|Faz com que o thread de chamada conceda a execução para outro thread que está pronto para ser executado no processador atual. O sistema operacional seleciona o próximo segmento a ser executado.|  
  
## <a name="remarks"></a>Comentários  
 Proxies de thread estão ligados a contextos de execução representados pela interface `IExecutionContext` como um meio de despacho de trabalho.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IThreadProxy`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="getid"></a>Método Ithreadproxy:  
 Retorna um identificador exclusivo para o proxy de thread.  
  
```
virtual unsigned int GetId() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador inteiro exclusivo.  
  
##  <a name="switchout"></a>Método Ithreadproxy:  
 Desassocia o contexto da raiz do processador virtual subjacente.  
  
```
virtual void SwitchOut(SwitchingProxyState switchState = Blocking) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `switchState`  
 Indica o estado do proxy do thread que está executando a opção. O parâmetro é do tipo `SwitchingProxyState`.  
  
### <a name="remarks"></a>Comentários  
 Use `SwitchOut` se você precisa desassociar um contexto da raiz do processador virtual está em execução, por qualquer motivo. Dependendo do valor você passar para o parâmetro `switchState`, e se ele está em execução em uma raiz de processador virtual, ou não a chamada será retornado imediatamente ou bloquear o proxy de thread associado ao contexto. Erro ao chamar `SwitchOut` com o parâmetro definido `Idle`. Isso resultará em um [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção.  
  
 `SwitchOut`é útil quando você deseja reduzir o número de raízes de processador virtual que tem o Agendador, porque o Gerenciador de recursos tem instruído a fazer isso, ou porque você solicitou uma raiz de temporário processador virtual assinadas e terminar com ele. Nesse caso, você deve chamar o método [IVirtualProcessorRoot::Remove](http://msdn.microsoft.com/en-us/ad699b4a-1972-4390-97ee-9c083ba7d9e4) na raiz do processador virtual, antes de fazer uma chamada para `SwitchOut` com o parâmetro `switchState` definido como `Blocking`. Isso bloqueará o proxy de thread e ele continuará a execução quando uma raiz de processador virtual diferente no Agendador está disponível para executá-lo. O proxy de segmento de bloqueio pode ser retomado chamando a função `SwitchTo` para alternar para o contexto de execução do proxy esse thread. Você também pode retomar o proxy de thread, usando seu contexto associado para ativar uma raiz de processador virtual. Para obter mais informações sobre como fazer isso, consulte [Ivirtualprocessorroot](ivirtualprocessorroot-structure.md#activate).  
  
 `SwitchOut`também pode ser usado quando você deseja reinicializar o processador virtual para que ele pode ser ativado no futuro enquanto o bloqueio do proxy de thread ou temporariamente desconectá-lo da raiz do processador virtual está em execução no e o Agendador que ele está distribuindo trabalho para. Use `SwitchOut` com o parâmetro `switchState` definida como `Blocking` se você deseja bloquear o proxy de thread. Ela mais tarde poderá ser retomada usando `SwitchTo` ou `IVirtualProcessorRoot::Activate` conforme observado acima. Use `SwitchOut` com o parâmetro definido `Nesting` quando você quer desanexar temporariamente esse proxy de thread da raiz virtual processador estiver executando no e o Agendador de processador virtual é associado. Chamando `SwitchOut` com o parâmetro `switchState` definida como `Nesting` enquanto ele está em execução em uma raiz de processador virtual fará com que a raiz sejam reinicializadas e o proxy do thread atual para continuar a executar sem a necessidade de um. O proxy de thread é considerado deixou o Agendador até que ele chama o [Ithreadproxy](#switchout) método com `Blocking` em um momento posterior. A segunda chamada para `SwitchOut` com o parâmetro definido `Blocking` destina-se para retornar o contexto para um estado bloqueado para que ele possa ser retomado pelo `SwitchTo` ou `IVirtualProcessorRoot::Activate` no Agendador do qual ele desanexado do. Porque ele não estava em execução em uma raiz de processador virtual, nenhuma reinicialização ocorre.  
  
 Uma raiz de processador virtual reinicializada não é diferente de uma nova raiz de processador virtual que o Agendador recebeu pelo Gerenciador de recursos. Você pode usá-lo para execução pelo ativá-lo com um contexto de execução usando `IVirtualProcessorRoot::Activate`.  
  
 `SwitchOut`deve ser chamado no `IThreadProxy` interface que representa o thread atualmente em execução ou os resultados serão indefinidos.  
  
 Em bibliotecas e cabeçalhos que acompanham o Visual Studio 2010, esse método não continha um parâmetro e não reinicializar a raiz do processador virtual. Para preservar o comportamento antigo, o valor de parâmetro padrão de `Blocking` é fornecido.  
  
##  <a name="switchto"></a>Método: Switchto  
 Executa uma alternância de contexto cooperativo do contexto de execução atual para outro.  
  
```
virtual void SwitchTo(
    _Inout_ IExecutionContext* pContext,
    SwitchingProxyState switchState) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pContext`  
 O contexto de execução para alternar de forma cooperativa para.  
  
 `switchState`  
 Indica o estado do proxy do thread que está executando a opção. O parâmetro é do tipo `SwitchingProxyState`.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para alternar do contexto de execução de um para outro, do [Iexecutioncontext](iexecutioncontext-structure.md#dispatch) método do contexto de execução primeiro. O método associa o contexto de execução `pContext` com um proxy de thread se ele não ainda estiver associado a um. A propriedade do proxy do thread atual é determinada pelo valor especificado para o `switchState` argumento.  
  
 Use o valor `Idle` quando você quiser retornar o proxy de thread em execução no momento para o Gerenciador de recursos. Chamando `SwitchTo` com o parâmetro `switchState` definida como `Idle` fará com que o contexto de execução `pContext` para iniciar a execução do recurso de execução subjacente. Propriedade desse proxy de thread é transferida para o Gerenciador de recursos, e você deve retornar a partir do contexto de execução `Dispatch` método logo após `SwitchTo` retorna, para concluir a transferência. O contexto de execução que o proxy de thread foi expedição é desassociado do proxy de thread, e o Agendador está livre para reutilizá-la ou destruída conforme desejar.  
  
 Use o valor `Blocking` quando você quiser que este proxy de thread para entrar em um estado bloqueado. Chamando `SwitchTo` com o parâmetro `switchState` definida como `Blocking` fará com que o contexto de execução `pContext` para iniciar a execução e bloquear o proxy do thread atual até que ela seja retomada. O Agendador reterá a propriedade do proxy thread quando o proxy de thread está no `Blocking` estado. O proxy de segmento de bloqueio pode ser retomado chamando a função `SwitchTo` para alternar para o contexto de execução do proxy esse thread. Você também pode retomar o proxy de thread, usando seu contexto associado para ativar uma raiz de processador virtual. Para obter mais informações sobre como fazer isso, consulte [Ivirtualprocessorroot](ivirtualprocessorroot-structure.md#activate).  
  
 Use o valor `Nesting` quando você quer desanexar temporariamente esse proxy de thread da raiz do processador virtual estiver em execução e o Agendador que ele está distribuindo trabalho para. Chamando `SwitchTo` com o parâmetro `switchState` definida como `Nesting` fará com que o contexto de execução `pContext` para iniciar a execução e o atual proxy thread também continua executando sem a necessidade de uma raiz de processador virtual. O proxy de thread é considerado deixou o Agendador até que ele chama o [Ithreadproxy](#switchout) método em um momento posterior. O `IThreadProxy::SwitchOut` método pode bloquear o proxy de thread até uma raiz de processador virtual está disponível para reprogramar a ele.  
  
 `SwitchTo`deve ser chamado no `IThreadProxy` interface que representa o thread atualmente em execução ou os resultados serão indefinidos. A função gera `invalid_argument` se o parâmetro `pContext` é definido como `NULL`.  
  
##  <a name="yieldtosystem"></a>Método: Yieldtosystem  
 Faz com que o thread de chamada conceda a execução para outro thread que está pronto para ser executado no processador atual. O sistema operacional seleciona o próximo segmento a ser executado.  
  
```
virtual void YieldToSystem() = 0;
```  
  
### <a name="remarks"></a>Comentários  
 Quando chamado por um proxy de thread sustentado por um thread do Windows regular, `YieldToSystem` se comporta exatamente como a função do Windows `SwitchToThread`. No entanto, quando chamado de modo de usuário agendáveis threads (UMS), o `SwitchToThread` função delega a tarefa de separação o próximo segmento para executar o Agendador de modo de usuário, não o sistema operacional. Para obter o efeito desejado de alternar para outro thread pronto no sistema, use `YieldToSystem`.  
  
 `YieldToSystem`deve ser chamado no `IThreadProxy` interface que representa o thread atualmente em execução ou os resultados serão indefinidos.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Estrutura IExecutionContext](iexecutioncontext-structure.md)   
 [Estrutura IScheduler](ischeduler-structure.md)   
 [Estrutura IVirtualProcessorRoot](ivirtualprocessorroot-structure.md)
