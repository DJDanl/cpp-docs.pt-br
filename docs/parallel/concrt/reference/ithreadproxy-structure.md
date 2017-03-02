---
title: Estrutura IThreadProxy | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- concrtrm/concurrency::IThreadProxy
dev_langs:
- C++
helpviewer_keywords:
- IThreadProxy structure
ms.assetid: feb89241-a555-4e61-ad48-40add54daeca
caps.latest.revision: 21
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
ms.sourcegitcommit: fa774c7f025b581d65c28d65d83e22ff2d798230
ms.openlocfilehash: baa3266d1068672df96595fa8b9bcc974d52e7fa
ms.lasthandoff: 02/25/2017

---
# <a name="ithreadproxy-structure"></a>Estrutura IThreadProxy
Uma abstração de um thread de execução. Dependendo do `SchedulerType` chave da diretiva do Agendador é criar o Gerenciador de recursos concederá a você um proxy de thread é apoiado por um thread do Win32 regular ou um thread (UMS) agendáveis do modo de usuário. Threads UMS são suportados em sistemas operacionais de 64 bits com a versão do Windows 7 e superior.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct IThreadProxy;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método Ithreadproxy::](#getid)|Retorna um identificador exclusivo para o proxy de thread.|  
|[Método Ithreadproxy::](#switchout)|Desassocia o contexto da raiz do processador virtual subjacente.|  
|[Método Ithreadproxy::](#switchto)|Executa uma alternância de contexto cooperativo do contexto de execução atual para outro.|  
|[Método Ithreadproxy::](#yieldtosystem)|Faz com que o thread de chamada conceda a execução para outro thread que está pronto para ser executado no processador atual. O sistema operacional seleciona o próximo segmento a ser executado.|  
  
## <a name="remarks"></a>Comentários  
 Proxies de thread estão ligados aos contextos de execução representados pela interface `IExecutionContext` como um meio de expedição de trabalho.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IThreadProxy`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm. h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namegetida--ithreadproxygetid-method"></a><a name="getid"></a>Método Ithreadproxy::  
 Retorna um identificador exclusivo para o proxy de thread.  
  
```
virtual unsigned int GetId() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador inteiro exclusivo.  
  
##  <a name="a-nameswitchouta--ithreadproxyswitchout-method"></a><a name="switchout"></a>Método Ithreadproxy::  
 Desassocia o contexto da raiz do processador virtual subjacente.  
  
```
virtual void SwitchOut(SwitchingProxyState switchState = Blocking) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `switchState`  
 Indica o estado do proxy do thread que está executando o comutador. O parâmetro é do tipo `SwitchingProxyState`.  
  
### <a name="remarks"></a>Comentários  
 Use `SwitchOut` se você precisar desassociar um contexto da raiz do processador virtual está em execução, por qualquer motivo. Dependendo do valor você passa para o parâmetro `switchState`, e se ou não está em execução em uma raiz virtual do processador, a chamada irá retornar imediatamente ou bloquear o proxy thread associado ao contexto. Erro ao chamar `SwitchOut` com o parâmetro definido `Idle`. Isso resultará em uma [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção.  
  
 `SwitchOut`é útil quando você deseja reduzir o número de raízes do processador virtual que tem o Agendador, porque o Gerenciador de recursos foi instruído a fazer isso, ou porque foi solicitada uma raiz temporário processador virtual assinadas e terminar com ele. Nesse caso, você deve chamar o método [IVirtualProcessorRoot::Remove método](http://msdn.microsoft.com/en-us/ad699b4a-1972-4390-97ee-9c083ba7d9e4) na raiz do processador virtual, antes de fazer uma chamada para `SwitchOut` com o parâmetro `switchState` definida como `Blocking`. Isso bloqueará o proxy de thread e retomará a execução quando uma raiz de processador virtual diferente do Agendador está disponível para executá-lo. O proxy de segmento de bloqueio pode ser retomado chamando a função `SwitchTo` para alternar para o contexto de execução do proxy esse thread. Você também pode retomar o proxy de thread, usando seu contexto associado para ativar uma raiz de processador virtual. Para obter mais informações sobre como fazer isso, consulte [Ivirtualprocessorroot](ivirtualprocessorroot-structure.md#activate).  
  
 `SwitchOut`também pode ser usado quando você deseja reinicializar o processador virtual para que ele pode ser ativado no futuro enquanto tanto bloqueando o proxy thread ou desconectá-lo temporariamente na raiz do processador virtual está em execução no Agendador ele está distribuindo o trabalho para. Use `SwitchOut` com o parâmetro `switchState` definida como `Blocking` se você deseja bloquear o proxy de thread. Ele pode posteriormente ser retomado usando `SwitchTo` ou `IVirtualProcessorRoot::Activate` conforme mencionado acima. Use `SwitchOut` com o parâmetro definido `Nesting` quando você deseja desanexar temporariamente esse proxy thread na raiz do processador virtual está em execução no e o Agendador do processador virtual está associado. Chamando `SwitchOut` com o parâmetro `switchState` definida como `Nesting` enquanto ele está em execução em uma raiz de processador virtual fará com que a raiz seja reiniciada e o proxy do thread atual para continuar a execução sem a necessidade de um. O proxy de thread é considerado abandonou o Agendador até que ele chama o [Ithreadproxy](#switchout) método `Blocking` em um momento posterior. A segunda chamada para `SwitchOut` com o parâmetro definido `Blocking` destina-se para retornar o contexto para um estado bloqueado para que ele possa ser retomado pelo `SwitchTo` ou `IVirtualProcessorRoot::Activate` do Agendador que ele desanexado do. Como não estava sendo executado em uma raiz virtual do processador, nenhuma reinicialização ocorre.  
  
 Uma raiz de processador virtual reinicializada não é diferente de uma nova raiz de processador virtual que o Agendador recebeu pelo Gerenciador de recursos. Você pode usá-lo para execução ativando-o com um contexto de execução usando `IVirtualProcessorRoot::Activate`.  
  
 `SwitchOut`deve ser chamado no `IThreadProxy` interface que representa o thread atualmente em execução ou os resultados são indefinidos.  
  
 Em bibliotecas e cabeçalhos que acompanha o Visual Studio 2010, esse método não continha um parâmetro e não reinicializar a raiz do processador virtual. Para preservar o comportamento antigo, o valor de parâmetro padrão de `Blocking` é fornecido.  
  
##  <a name="a-nameswitchtoa--ithreadproxyswitchto-method"></a><a name="switchto"></a>Método Ithreadproxy::  
 Executa uma alternância de contexto cooperativo do contexto de execução atual para outro.  
  
```
virtual void SwitchTo(
    _Inout_ IExecutionContext* pContext,
    SwitchingProxyState switchState) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pContext`  
 O contexto de execução de forma cooperativa alternar para.  
  
 `switchState`  
 Indica o estado do proxy do thread que está executando o comutador. O parâmetro é do tipo `SwitchingProxyState`.  
  
### <a name="remarks"></a>Comentários  
 Use este método para alternar do contexto de execução para outro, do [Iexecutioncontext](iexecutioncontext-structure.md#dispatch) método do contexto de execução do primeiro. O método associa o contexto de execução `pContext` com um proxy de thread se ele não ainda estiver associado a um. A propriedade do proxy do thread atual é determinada pelo valor especificado para o `switchState` argumento.  
  
 Use o valor `Idle` quando quiser retornar o proxy thread atualmente em execução para o Gerenciador de recursos. Chamando `SwitchTo` com o parâmetro `switchState` definida como `Idle` fará com que o contexto de execução `pContext` para iniciar a execução do recurso de execução subjacente. A propriedade de proxy esse thread é transferida para o Gerenciador de recursos, e você deverá retornar a partir do contexto de execução `Dispatch` método logo após `SwitchTo` retorna, para concluir a transferência. O contexto de execução que o proxy de thread foi expedição é dissociado do proxy thread e o Agendador está livre para reutilizá-lo ou destruí-lo conforme desejar.  
  
 Use o valor `Blocking` quando deseja que esse proxy de thread para entrar em um estado bloqueado. Chamando `SwitchTo` com o parâmetro `switchState` definida como `Blocking` fará com que o contexto de execução `pContext` para iniciar a execução e bloquear o proxy do thread atual até que ele seja reiniciado. O Agendador reterá a propriedade do proxy thread quando o proxy thread está no `Blocking` estado. O proxy de segmento de bloqueio pode ser retomado chamando a função `SwitchTo` para alternar para o contexto de execução do proxy esse thread. Você também pode retomar o proxy de thread, usando seu contexto associado para ativar uma raiz de processador virtual. Para obter mais informações sobre como fazer isso, consulte [Ivirtualprocessorroot](ivirtualprocessorroot-structure.md#activate).  
  
 Use o valor `Nesting` quando você deseja desanexar temporariamente esse proxy thread na raiz do processador virtual está em execução no e o Agendador ele está distribuindo o trabalho. Chamando `SwitchTo` com o parâmetro `switchState` definida como `Nesting` fará com que o contexto de execução `pContext` para iniciar a execução e o atual proxy thread também continua executando sem a necessidade de uma raiz do processador virtual. O proxy de thread é considerado abandonou o Agendador até que ele chama o [Ithreadproxy](#switchout) método em um momento posterior. O `IThreadProxy::SwitchOut` método poderia bloquear o proxy thread até uma raiz de processador virtual está disponível para reprogramar a ele.  
  
 `SwitchTo`deve ser chamado no `IThreadProxy` interface que representa o thread atualmente em execução ou os resultados são indefinidos. A função gera `invalid_argument` se o parâmetro `pContext` é definido como `NULL`.  
  
##  <a name="a-nameyieldtosystema--ithreadproxyyieldtosystem-method"></a><a name="yieldtosystem"></a>Método Ithreadproxy::  
 Faz com que o thread de chamada conceda a execução para outro thread que está pronto para ser executado no processador atual. O sistema operacional seleciona o próximo segmento a ser executado.  
  
```
virtual void YieldToSystem() = 0;
```  
  
### <a name="remarks"></a>Comentários  
 Quando chamado por um proxy thread apoiado por um thread do Windows regular, `YieldToSystem` se comporta exatamente como a função do Windows `SwitchToThread`. No entanto, quando chamado de modo de usuário agendáveis (UMS) threads, o `SwitchToThread` função delega a tarefa de escolher o próximo segmento a ser executado para o Agendador de modo de usuário, não o sistema operacional. Para obter o efeito desejado de alternar para outro thread pronto no sistema, use `YieldToSystem`.  
  
 `YieldToSystem`deve ser chamado no `IThreadProxy` interface que representa o thread atualmente em execução ou os resultados são indefinidos.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Estrutura IExecutionContext](iexecutioncontext-structure.md)   
 [Estrutura IScheduler](ischeduler-structure.md)   
 [Estrutura IVirtualProcessorRoot](ivirtualprocessorroot-structure.md)

