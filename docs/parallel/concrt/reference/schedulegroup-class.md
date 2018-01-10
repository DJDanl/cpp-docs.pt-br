---
title: Classe ScheduleGroup | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ScheduleGroup
- CONCRT/concurrency::ScheduleGroup
- CONCRT/concurrency::ScheduleGroup::Id
- CONCRT/concurrency::ScheduleGroup::Reference
- CONCRT/concurrency::ScheduleGroup::Release
- CONCRT/concurrency::ScheduleGroup::ScheduleTask
dev_langs: C++
helpviewer_keywords: ScheduleGroup class
ms.assetid: 86d380ff-f2e8-411c-b1a8-22bd3079824a
caps.latest.revision: "20"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f1ca427842245701c1d8dfbcef946ef1586acbf0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="schedulegroup-class"></a>Classe ScheduleGroup
Representa uma abstração para um grupo de agendamento. Organizam os grupos de agendamento de um conjunto de trabalho relacionados que se beneficia de ser agendado próximas temporariamente, por outra tarefa em execução no mesmo grupo antes de passar para outro grupo ou espacialmente, executando vários itens dentro do mesmo grupo no mesmo Nó NUMA ou soquete físico.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class ScheduleGroup;
```  
  
## <a name="members"></a>Membros  
  
### <a name="protected-constructors"></a>Construtores Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[~ Destruidor ScheduleGroup](#dtor)||  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[ID](#id)|Retorna um identificador para o grupo de agenda que é exclusivo no Agendador ao qual pertence o grupo.|  
|[Referência](#reference)|Incrementa a contagem de referência do grupo de agendamento.|  
|[Versão](#release)|Diminui a Agendador grupo contagem de referência.|  
|[ScheduleTask](#scheduletask)|Agenda uma tarefa leve dentro do grupo de agendamento.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ScheduleGroup`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="id"></a>ID 

 Retorna um identificador para o grupo de agenda que é exclusivo no Agendador ao qual pertence o grupo.  
  
```
virtual unsigned int Id() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o grupo de agenda que é exclusivo no Agendador ao qual pertence o grupo.  
  
##  <a name="operator_delete"></a>operador delete 

 Um `ScheduleGroup` objeto é destruído internamente pelo tempo de execução quando todas as referências externas a ele são liberadas. Ele não pode ser excluído explicitamente.  
  
```
void operator delete(
    void* _PObject);

void operator delete(
    void* _PObject,
    int,
 const char *,
    int);
```    
  
### <a name="parameters"></a>Parâmetros  
 `_PObject`  
 Um ponteiro para o objeto a ser excluído.  
  
##  <a name="reference"></a>Referência 

 Incrementa a contagem de referência do grupo de agendamento.  
  
```
virtual unsigned int Reference() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 A contagem de referência recentemente incrementado.  
  
### <a name="remarks"></a>Comentários  
 Isso normalmente é usado para gerenciar o tempo de vida do grupo de agendamento de composição. Quando a contagem de referência de um grupo de agendamento cair para zero, o grupo de agendamento é excluído pelo tempo de execução. Um grupo de agendamento criado usando o [: Createschedulegroup](currentscheduler-class.md#createschedulegroup) método, ou o [: createschedulegroup](scheduler-class.md#createschedulegroup) método começa com uma contagem de referência de um.  
  
##  <a name="release"></a>Versão 

 Diminui a Agendador grupo contagem de referência.  
  
```
virtual unsigned int Release() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 A contagem de referência recentemente diminuído.  
  
### <a name="remarks"></a>Comentários  
 Isso normalmente é usado para gerenciar o tempo de vida do grupo de agendamento de composição. Quando a contagem de referência de um grupo de agendamento cair para zero, o grupo de agendamento é excluído pelo tempo de execução. Depois de ter chamado o `Release` o número específico de vezes para remover a criação do método fazem referência contagem e as referências adicionais inseridas usando o `Reference` método, você não pode utilizar o grupo de programação. Isso resultará em um comportamento indefinido.  
  
 Um grupo de agendamento está associado uma instância específica do Agendador. Certifique-se de que todas as referências para o grupo de agendamento são liberadas antes de todas as referências para o Agendador são lançadas, porque o último pode resultar no Agendador de destruição. Fazendo resulta em um comportamento indefinido.  
  
##  <a name="dtor"></a>~ ScheduleGroup 

```
virtual ~ScheduleGroup();
```  
  
##  <a name="scheduletask"></a>ScheduleTask 

 Agenda uma tarefa leve dentro do grupo de agendamento.  
  
```
virtual void ScheduleTask(
    TaskProc _Proc,
    _Inout_opt_ void* _Data) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Proc`  
 Um ponteiro para a função a ser executada para executar o corpo da tarefa leve.  
  
 `_Data`  
 Um ponteiro nulo para os dados que serão passados como um parâmetro para o corpo da tarefa.  
  
### <a name="remarks"></a>Comentários  
 Chamar o `ScheduleTask` método implicitamente coloca uma contagem de referência no grupo de agenda que foi removido pelo tempo de execução em um momento apropriado depois que a tarefa será executada.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe CurrentScheduler](currentscheduler-class.md)   
 [Classe de Agendador](scheduler-class.md)   
 [Agendador de tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md)



