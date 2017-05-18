---
title: Classe de contexto | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- Context
- CONCRT/concurrency::Context
- CONCRT/concurrency::Context::Block
- CONCRT/concurrency::Context::CurrentContext
- CONCRT/concurrency::Context::GetId
- CONCRT/concurrency::Context::GetScheduleGroupId
- CONCRT/concurrency::Context::GetVirtualProcessorId
- CONCRT/concurrency::Context::Id
- CONCRT/concurrency::Context::IsCurrentTaskCollectionCanceling
- CONCRT/concurrency::Context::IsSynchronouslyBlocked
- CONCRT/concurrency::Context::Oversubscribe
- CONCRT/concurrency::Context::ScheduleGroupId
- CONCRT/concurrency::Context::Unblock
- CONCRT/concurrency::Context::VirtualProcessorId
- CONCRT/concurrency::Context::Yield
dev_langs:
- C++
helpviewer_keywords:
- Context class
ms.assetid: c0d553f3-961d-4ecd-9a29-4fa4351673b8
caps.latest.revision: 20
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: fd6f59e1e94329ef73e8fdbe946ec22241815e2e
ms.contentlocale: pt-br
ms.lasthandoff: 03/17/2017

---
# <a name="context-class"></a>Classe Context
Representa uma abstração de um contexto de execução.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class Context;
```  
  
## <a name="members"></a>Membros  
  
### <a name="protected-constructors"></a>Construtores Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[~ Destruidor contexto](#dtor)||  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Bloco](#block)|Bloqueia o contexto atual.|  
|[CurrentContext](#currentcontext)|Retorna um ponteiro para o contexto atual.|  
|[GetId](#getid)|Retorna um identificador de contexto que seja exclusivo dentro do Agendador ao qual pertence o contexto.|  
|[GetScheduleGroupId](#getschedulegroupid)|Retorna um identificador para o grupo de programação que o contexto está trabalhando no momento.|  
|[GetVirtualProcessorId](#getvirtualprocessorid)|Retorna um identificador para o processador virtual atualmente em execução no contexto.|  
|[ID](#id)|Retorna um identificador para o contexto atual é exclusivo dentro do Agendador ao qual pertence o contexto atual.|  
|[IsCurrentTaskCollectionCanceling](#iscurrenttaskcollectioncanceling)|Retorna uma indicação se a coleção de tarefa que está em execução atualmente embutido no contexto atual está no meio de um cancelamento ativo (ou estarão em breve).|  
|[IsSynchronouslyBlocked](#issynchronouslyblocked)|Determina se ou não o contexto de forma síncrona está bloqueado. Um contexto é considerado sincronicamente ser bloqueado se ele explicitamente executou uma ação que levou ao bloqueio.|  
|[Subscrever](#oversubscribe)|Injeta um processador virtual adicional em um agendador para a duração de um bloco de código quando invocado em um contexto de execução em um dos processadores virtuais em que o Agendador.|  
|[ScheduleGroupId](#schedulegroupid)|Retorna um identificador para o grupo de programação que o contexto atual está trabalhando.|  
|[Desbloquear](#unblock)|Desbloqueia o contexto e faz com que ele se torne executável.|  
|[VirtualProcessorId](#virtualprocessorid)|Retorna um identificador para o processador virtual que está em execução no contexto atual.|  
|[Yield](#yield)|Gera a execução para que possa executar outro contexto. Se nenhum outro contexto estiver disponível para produzir a, o Agendador pode gerar para outro thread do sistema operacional.|  
  
## <a name="remarks"></a>Comentários  
 O Agendador de tempo de execução de simultaneidade (consulte [Agendador](scheduler-class.md)) contextos de execução usa para executar o trabalho em fila para ele pelo seu aplicativo. Um thread do Win32 é um exemplo de um contexto de execução em um sistema operacional Windows.  
  
 A qualquer momento, o nível de simultaneidade de um agendador é igual ao número de processadores virtuais concedidas a ele pelo Gerenciador de recursos. Um processador virtual é uma abstração para um recurso de processamento e é mapeado para um thread de hardware no sistema subjacente. Um contexto de Agendador único pode executar em um processador virtual em um determinado momento.  
  
 O Agendador é cooperativo por natureza e um contexto de execução pode gerar seu processador virtual para um contexto diferente a qualquer momento, se desejar entrar em um estado de espera. Quando sua espera que ele atendidas, ele não pode continuar até que um processador virtual disponível do Agendador começa a executá-lo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `Context`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="block"></a>Bloco 

 Bloqueia o contexto atual.  
  
```
static void __cdecl Block();
```  
  
### <a name="remarks"></a>Comentários  
 Este método resultará no Agendador de padrão do processo que está sendo criado e/ou anexados ao contexto de chamada se não houver nenhum Agendador atualmente associado ao contexto de chamada.  
  
 Se o contexto de chamada está em execução em um processador virtual, o processador virtual encontrará outro contexto executável para executar ou pode criar um novo.  
  
 Após o `Block` método foi chamado ou será chamado, você deve combiná-lo com uma chamada para o [desbloquear](#unblock) método de outro contexto de execução em ordem para que ele execute novamente. Lembre-se de que há um período crítico entre o ponto onde seu código publica seu contexto para outro thread para chamar o `Unblock` método e o ponto em que o método real é chamada para `Block` é feita. Durante esse período, você não deve chamar qualquer método que por sua vez pode bloquear e desbloquear por suas próprias razões (por exemplo, adquirir um bloqueio). Chamadas para o `Block` e `Unblock` método não rastrear o motivo do bloqueio e desbloqueio. Apenas um objeto deve ter a propriedade de um `Block` -  `Unblock` par.  
  
 Esse método pode acionar uma variedade de exceções, incluindo [scheduler_resource_allocation_error](scheduler-resource-allocation-error-class.md).  
  
##  <a name="dtor"></a>~ Contexto de 

```
virtual ~Context();
```  
  
##  <a name="currentcontext"></a>CurrentContext 

 Retorna um ponteiro para o contexto atual.  
  
```
static Context* __cdecl CurrentContext();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o contexto atual.  
  
### <a name="remarks"></a>Comentários  
 Este método resultará no Agendador de padrão do processo que está sendo criado e/ou anexados ao contexto de chamada se não houver nenhum Agendador atualmente associado ao contexto de chamada.  
  
##  <a name="getid"></a>GetId 

 Retorna um identificador de contexto que seja exclusivo dentro do Agendador ao qual pertence o contexto.  
  
```
virtual unsigned int GetId() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o contexto que seja exclusivo dentro do Agendador ao qual pertence o contexto.  
  
##  <a name="getschedulegroupid"></a>GetScheduleGroupId 

 Retorna um identificador para o grupo de programação que o contexto está trabalhando no momento.  
  
```
virtual unsigned int GetScheduleGroupId() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o grupo de agenda que o contexto está trabalhando no momento.  
  
### <a name="remarks"></a>Comentários  
 O valor de retorno desse método é uma amostragem instantânea do grupo de agendamento que o contexto está em execução. Se esse método for chamado em um contexto diferente do contexto atual, o valor pode ser atualizado no momento em que ele é retornado e não pode ser considerado. Normalmente, esse método é usado para depuração ou apenas para fins de rastreamento.  
  
##  <a name="getvirtualprocessorid"></a>GetVirtualProcessorId 

 Retorna um identificador para o processador virtual atualmente em execução no contexto.  
  
```
virtual unsigned int GetVirtualProcessorId() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o contexto está sendo executado em um processador virtual, um identificador para o processador virtual que o contexto está sendo executado Caso contrário, o valor `-1`.  
  
### <a name="remarks"></a>Comentários  
 O valor de retorno desse método é uma amostragem instantânea do processador virtual que o contexto está em execução. Esse valor pode ser atualizado no momento em que ele é retornado e não pode ser considerado. Normalmente, esse método é usado para depuração ou apenas para fins de rastreamento.  
  
##  <a name="id"></a>ID 

 Retorna um identificador para o contexto atual é exclusivo dentro do Agendador ao qual pertence o contexto atual.  
  
```
static unsigned int __cdecl Id();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o contexto atual é anexado a um agendador, um identificador para o contexto atual é exclusivo dentro do Agendador ao qual pertence o contexto atual; Caso contrário, o valor `-1`.  
  
##  <a name="iscurrenttaskcollectioncanceling"></a>IsCurrentTaskCollectionCanceling 

 Retorna uma indicação se a coleção de tarefa que está em execução atualmente embutido no contexto atual está no meio de um cancelamento ativo (ou estarão em breve).  
  
```
static bool __cdecl IsCurrentTaskCollectionCanceling();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se um agendador está anexado ao contexto de chamada e um grupo de tarefas está executando uma tarefa em linha nesse contexto, uma indicação se esse grupo de tarefas está no meio de um cancelamento ativo (ou estarão em breve); Caso contrário, o valor `false`.  
  
##  <a name="issynchronouslyblocked"></a>IsSynchronouslyBlocked 

 Determina se ou não o contexto de forma síncrona está bloqueado. Um contexto é considerado sincronicamente ser bloqueado se ele explicitamente executou uma ação que levou ao bloqueio.  
  
```
virtual bool IsSynchronouslyBlocked() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o contexto de forma síncrona é bloqueado.  
  
### <a name="remarks"></a>Comentários  
 Um contexto é considerado sincronicamente ser bloqueado se ele explicitamente executou uma ação que levou ao bloqueio. O Agendador de threads, isso indica que uma chamada direta para o `Context::Block` método ou um objeto de sincronização que foi criado usando o `Context::Block` método.  
  
 O valor de retorno desse método é um exemplo de instantâneo de se o contexto de forma síncrona está bloqueado. Esse valor pode ser atualizado no momento em que ele é retornado e só pode ser usado em circunstâncias muito específicas.  
  
##  <a name="operator_delete"></a>operador delete 

 Um `Context` objeto é destruído internamente pelo tempo de execução. Ele não pode ser explicitamente excluído.  
  
```
void operator delete(void* _PObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PObject`  
 Um ponteiro para o objeto a ser excluído.  
  
##  <a name="oversubscribe"></a>Subscrever 

 Injeta um processador virtual adicional em um agendador para a duração de um bloco de código quando invocado em um contexto de execução em um dos processadores virtuais em que o Agendador.  
  
```
static void __cdecl Oversubscribe(bool _BeginOversubscription);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_BeginOversubscription`  
 Se `true`, uma indicação de que um processador virtual extra deve ser adicionado durante o excesso de assinatura. Se `false`, uma indicação de que o excesso de assinatura deve terminar e o processador virtual adicionado anteriormente deve ser removido.  
  
##  <a name="schedulegroupid"></a>ScheduleGroupId 

 Retorna um identificador para o grupo de programação que o contexto atual está trabalhando.  
  
```
static unsigned int __cdecl ScheduleGroupId();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o contexto atual é anexado a um agendador e trabalhando em um grupo de programação, um identificador para o Agendador de grupo que o contexto atual está funcionando Caso contrário, o valor `-1`.  
  
##  <a name="unblock"></a>Desbloquear 

 Desbloqueia o contexto e faz com que ele se torne executável.  
  
```
virtual void Unblock() = 0;
```  
  
### <a name="remarks"></a>Comentários  
 É perfeitamente legal para chamar o `Unblock` método vir antes de uma chamada correspondente para o [bloco](#block) método. Desde que as chamadas para o `Block` e `Unblock` métodos estão emparelhados corretamente, o runtime manipula adequadamente a corrida natural de qualquer ordenação. Um `Unblock` chamada antes de uma `Block` chamada simplesmente anula o efeito do `Block` chamar.  
  
 Há várias exceções que podem ser geradas a partir desse método. Se um contexto de tentar chamar o `Unblock` método em si, uma [context_self_unblock](context-self-unblock-class.md) exceção será lançada. Se chama `Block` e `Unblock` não estão emparelhados corretamente (por exemplo, duas chamadas para `Unblock` são feitas para um contexto que está sendo executado), um [context_unblock_unbalanced](context-unblock-unbalanced-class.md) exceção será lançada.  
  
 Lembre-se de que há um período crítico entre o ponto onde seu código publica seu contexto para outro thread para chamar o `Unblock` método e o ponto em que o método real é chamada para `Block` é feita. Durante esse período, você não deve chamar qualquer método que por sua vez pode bloquear e desbloquear por suas próprias razões (por exemplo, adquirir um bloqueio). Chamadas para o `Block` e `Unblock` método não rastrear o motivo do bloqueio e desbloqueio. Apenas um objeto deve ter a propriedade de um `Block` e `Unblock` par.  
  
##  <a name="virtualprocessorid"></a>VirtualProcessorId 

 Retorna um identificador para o processador virtual que está em execução no contexto atual.  
  
```
static unsigned int __cdecl VirtualProcessorId();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o contexto atual é anexado a um agendador, um identificador para o processador virtual que o contexto atual está em execução; Caso contrário, o valor `-1`.  
  
### <a name="remarks"></a>Comentários  
 O valor de retorno desse método é uma amostragem instantânea do processador virtual que está em execução no contexto atual. Esse valor pode ser atualizado no momento em que ele é retornado e não pode ser considerado. Normalmente, esse método é usado para depuração ou apenas para fins de rastreamento.  
  
##  <a name="yield"></a>Yield 

 Gera a execução para que possa executar outro contexto. Se nenhum outro contexto estiver disponível para produzir a, o Agendador pode gerar para outro thread do sistema operacional.  
  
```
static void __cdecl Yield();
```  
  
### <a name="remarks"></a>Comentários  
 Este método resultará no Agendador de padrão do processo que está sendo criado e/ou anexados ao contexto de chamada se não houver nenhum Agendador atualmente associado ao contexto de chamada.  
  
##  <a name="yieldexecution"></a>YieldExecution 

 Gera a execução para que possa executar outro contexto. Se nenhum outro contexto estiver disponível para produzir a, o Agendador pode gerar para outro thread do sistema operacional.  
  
```
static void __cdecl YieldExecution();
```  
  
### <a name="remarks"></a>Comentários  
 Este método resultará no Agendador de padrão do processo que está sendo criado e/ou anexados ao contexto de chamada se não houver nenhum Agendador atualmente associado ao contexto de chamada.  
  
 Essa função é nova no [!INCLUDE[vs_dev14](../../../ide/includes/vs_dev14_md.md)] e é idêntico do [gerar](#yield) funcionar, mas não entra em conflito com a macro Yield no Windows. h.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe de Agendador](scheduler-class.md)   
 [Agendador de tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md)




