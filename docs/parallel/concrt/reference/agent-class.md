---
title: Classe agente | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- agents/concurrency::agent
dev_langs:
- C++
helpviewer_keywords:
- agent class
ms.assetid: 1b09e3d2-5e37-4966-b016-907ef1512456
caps.latest.revision: 20
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: fc190feb08d9b221cd1cc21a9c91ad567c86c848
ms.openlocfilehash: 640e1d66a879e8eb73428b50339d6a325cfd7cb2
ms.lasthandoff: 02/25/2017

---
# <a name="agent-class"></a>Classe agente
Uma classe deve ser usada como uma classe base para todos os agentes independentes. Ele é usado para ocultar o estado dos outros agentes e interagir com a transmissão de mensagens.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class agent;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Agente de construtor](#ctor)|Sobrecarregado. Constrói um agente.|  
|[~ agente destruidor](#dtor)|Destrói o agente.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método Cancel](#cancel)|Move um agente do `agent_created` ou `agent_runnable` estados a `agent_canceled` estado.|  
|[Método Start](#start)|Move um agente do `agent_created` estado de `agent_runnable` de estado e agenda para execução.|  
|[status do método](#status)|Uma fonte síncrona de informações de status do agente.|  
|[Método status_port](#status_port)|Uma fonte assíncrona das informações de status do agente.|  
|[Método Wait](#wait)|Espera por um agente concluir a tarefa.|  
|[Método wait_for_all](#wait_for_all)|Aguarda até que todos os agentes especificados para concluir suas tarefas.|  
|[Método wait_for_one](#wait_for_one)|Espera por qualquer um dos agentes para concluir a tarefa especificados.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método Done](#done)|Move um agente para o `agent_done` estado, indicando que o agente foi concluído.|  
|[o método Run](#run)|Representa a tarefa principal de um agente. `run`deve ser substituído em uma classe derivada e especifica que o agente deve fazer depois que ele foi iniciado.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [agentes assíncronos](../../../parallel/concrt/asynchronous-agents.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `agent`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namectora-agent"></a><a name="ctor"></a>agente 

 Constrói um agente.  
  
```
agent();

agent(Scheduler& _PScheduler);

agent(ScheduleGroup& _PGroup);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PScheduler`  
 O `Scheduler` do objeto no qual a tarefa de execução do agente está agendada.  
  
 `_PGroup`  
 O `ScheduleGroup` do objeto no qual a tarefa de execução do agente está agendada. O `Scheduler` objeto usado é indicado pelo grupo de agendamento.  
  
### <a name="remarks"></a>Comentários  
 O tempo de execução usa o agendador padrão se você não especificar o `_PScheduler` ou `_PGroup` parâmetros.  
  
##  <a name="a-namedtora-agent"></a><a name="dtor"></a>~ agent 

 Destrói o agente.  
  
```
virtual ~agent();
```  
  
### <a name="remarks"></a>Comentários  
 Erro ao destruir um agente não está em um estado terminal (tanto `agent_done` ou `agent_canceled`). Isso pode ser evitado aguardando o agente atingir um estado terminal no destruidor de uma classe que herda de `agent` classe.  
  
##  <a name="a-namecancela-cancel"></a><a name="cancel"></a>Cancelar 

 Move um agente do `agent_created` ou `agent_runnable` estados a `agent_canceled` estado.  
  
```
bool cancel();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o agente tiver sido cancelado, `false` caso contrário. Um agente não pode ser cancelado se ele já a execução foi iniciada ou já foi concluída.  
  
##  <a name="a-namedonea-done"></a><a name="done"></a>feito 

 Move um agente para o `agent_done` estado, indicando que o agente foi concluído.  
  
```
bool done();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o agente for movido para o `agent_done` estado, `false` caso contrário. Um agente que foi cancelado não pode ser movido para o `agent_done` estado.  
  
### <a name="remarks"></a>Comentários  
 Esse método deve ser chamado no final o `run` método, quando você souber que a execução do seu agente foi concluída.  
  
##  <a name="a-nameruna-run"></a><a name="run"></a>executar 

 Representa a tarefa principal de um agente. `run`deve ser substituído em uma classe derivada e especifica que o agente deve fazer depois que ele foi iniciado.  
  
```
virtual void run() = 0;
```  
  
### <a name="remarks"></a>Comentários  
 O status do agente é alterado para `agent_started` direita antes que esse método é chamado. O método deve chamar `done` no agente com um status apropriado antes de retornar e não podem lançar exceções.  
  
##  <a name="a-namestarta-start"></a><a name="start"></a>Iniciar 

 Move um agente do `agent_created` estado de `agent_runnable` de estado e agenda para execução.  
  
```
bool start();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o agente foi iniciado corretamente, `false` caso contrário. Não é possível iniciar um agente que foi cancelado.  
  
##  <a name="a-namestatusa-status"></a><a name="status"></a>status 

 Uma fonte síncrona de informações de status do agente.  
  
```
agent_status status();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o estado atual do agente. Observe que esse estado retornado pode ser alterados imediatamente após serem retornados.  
  
##  <a name="a-namestatusporta-statusport"></a><a name="status_port"></a>status_port 

 Uma fonte assíncrona das informações de status do agente.  
  
```
ISource<agent_status>* status_port();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma fonte de mensagem que pode enviar mensagens sobre o estado atual do agente.  
  
##  <a name="a-namewaita-wait"></a><a name="wait"></a>Aguarde 

 Espera por um agente concluir a tarefa.  
  
```
static agent_status __cdecl wait(
    _Inout_ agent* _PAgent,
    unsigned int _Timeout = COOPERATIVE_TIMEOUT_INFINITE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PAgent`  
 Um ponteiro para o agente aguardar.  
  
 `_Timeout`  
 O tempo máximo para o qual espera, em milissegundos.  
  
### <a name="return-value"></a>Valor de retorno  
 O `agent_status` do agente quando a espera for concluída. Isso pode ser `agent_canceled` ou `agent_done`.  
  
### <a name="remarks"></a>Comentários  
 Uma tarefa do agente é concluída quando o agente entra o `agent_canceled` ou `agent_done` estados.  
  
 Se o parâmetro `_Timeout` tem um valor que não seja a constante `COOPERATIVE_TIMEOUT_INFINITE`, a exceção [operation_timed_out](operation-timed-out-class.md) será lançada se o período de tempo especificado expirar antes que o agente concluiu a tarefa.  
  
##  <a name="a-namewaitforalla-waitforall"></a><a name="wait_for_all"></a>wait_for_all 

 Aguarda até que todos os agentes especificados para concluir suas tarefas.  
  
```
static void __cdecl wait_for_all(
    size_t count,
    _In_reads_(count) agent** _PAgents,
    _Out_writes_opt_(count) agent_status* _PStatus = NULL,
    unsigned int _Timeout = COOPERATIVE_TIMEOUT_INFINITE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `count`  
 O número de ponteiros de agente presentes na matriz `_PAgents`.  
  
 `_PAgents`  
 Uma matriz de ponteiros para os agentes para aguardar.  
  
 `_PStatus`  
 Um ponteiro para uma matriz de status do agente. Cada valor de status representará o status do agente correspondente quando o método retorna.  
  
 `_Timeout`  
 O tempo máximo para o qual espera, em milissegundos.  
  
### <a name="remarks"></a>Comentários  
 Uma tarefa do agente é concluída quando o agente entra o `agent_canceled` ou `agent_done` estados.  
  
 Se o parâmetro `_Timeout` tem um valor que não seja a constante `COOPERATIVE_TIMEOUT_INFINITE`, a exceção [operation_timed_out](operation-timed-out-class.md) será lançada se o período de tempo especificado expirar antes que o agente concluiu a tarefa.  
  
##  <a name="a-namewaitforonea-waitforone"></a><a name="wait_for_one"></a>wait_for_one 

 Espera por qualquer um dos agentes para concluir a tarefa especificados.  
  
```
static void __cdecl wait_for_one(
    size_t count,
    _In_reads_(count) agent** _PAgents,
    agent_status& _Status,
    size_t& _Index,
    unsigned int _Timeout = COOPERATIVE_TIMEOUT_INFINITE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `count`  
 O número de ponteiros de agente presentes na matriz `_PAgents`.  
  
 `_PAgents`  
 Uma matriz de ponteiros para os agentes para aguardar.  
  
 `_Status`  
 Uma referência a uma variável em que o status do agente será colocado.  
  
 `_Index`  
 Uma referência a uma variável onde o índice de agente será colocado.  
  
 `_Timeout`  
 O tempo máximo para o qual espera, em milissegundos.  
  
### <a name="remarks"></a>Comentários  
 Uma tarefa do agente é concluída quando o agente entra o `agent_canceled` ou `agent_done` estados.  
  
 Se o parâmetro `_Timeout` tem um valor que não seja a constante `COOPERATIVE_TIMEOUT_INFINITE`, a exceção [operation_timed_out](operation-timed-out-class.md) será lançada se o período de tempo especificado expirar antes que o agente concluiu a tarefa.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)

