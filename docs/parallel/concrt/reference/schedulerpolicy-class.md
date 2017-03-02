---
title: Classe SchedulerPolicy | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- concrt/concurrency::SchedulerPolicy
- concrtrm/concurrency::SchedulerPolicy
dev_langs:
- C++
helpviewer_keywords:
- SchedulerPolicy class
ms.assetid: bcebf51a-65f8-45a3-809b-d1ff93527dc4
caps.latest.revision: 22
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
ms.sourcegitcommit: fc190feb08d9b221cd1cc21a9c91ad567c86c848
ms.openlocfilehash: 68707be387590cf04745d5a53872558d7af8da8c
ms.lasthandoff: 02/25/2017

---
# <a name="schedulerpolicy-class"></a>Classe SchedulerPolicy
O `SchedulerPolicy` classe contém um conjunto de pares chave/valor, um para cada elemento de diretiva que controlam o comportamento de uma instância de Agendador.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class SchedulerPolicy;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor SchedulerPolicy](#ctor)|Sobrecarregado. Constrói uma nova política de agendador e o preenche com valores de [chaves de política](concurrency-namespace-enums.md) agendadores de tempo de execução de simultaneidade e o Gerenciador de recursos de suporte.|  
|[~ Destruidor SchedulerPolicy](#dtor)|Destrói uma política do Agendador.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método GetPolicyValue](#getpolicyvalue)|Recupera o valor da chave de política fornecido como o `key` parâmetro.|  
|[Método SetConcurrencyLimits](#setconcurrencylimits)|Define simultaneamente o `MinConcurrency` e `MaxConcurrency` diretivas no `SchedulerPolicy` objeto.|  
|[Método SetPolicyValue](#setpolicyvalue)|Define o valor da chave de política fornecido como o `key` parâmetro e retorna o valor antigo.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operador Operator =](#operator_eq)|Atribui a política do Agendador de outra política de Agendador.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações sobre as políticas que pode ser controlado usando o `SchedulerPolicy` classe, consulte [enumeração PolicyElementKey](concurrency-namespace-enums.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `SchedulerPolicy`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h, concrtrm. h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namegetpolicyvaluea-getpolicyvalue"></a><a name="getpolicyvalue"></a>GetPolicyValue 

 Recupera o valor da chave de política fornecido como o `key` parâmetro.  
  
```
unsigned int GetPolicyValue(PolicyElementKey key) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 A chave de política para recuperar um valor de.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a chave especificada o `key` parâmetro tem suporte, o valor de política para a chave de conversão para um `unsigned int`.  
  
### <a name="remarks"></a>Comentários  
 O método gerará [invalid_scheduler_policy_key](invalid-scheduler-policy-key-class.md) de uma chave de política inválido.  
  
##  <a name="a-nameoperatoreqa-operator"></a><a name="operator_eq"></a>operador = 

 Atribui a política do Agendador de outra política de Agendador.  
  
```
SchedulerPolicy& operator= (const SchedulerPolicy& _RhsPolicy);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_RhsPolicy`  
 A política para atribuir a esta política.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência à política de Agendador.  
  
### <a name="remarks"></a>Comentários  
 Em geral, a maneira mais conveniente para definir uma nova diretiva do Agendador é copiar uma política existente e modificá-lo usando o `SetPolicyValue` ou `SetConcurrencyLimits` métodos.  
  
##  <a name="a-namectora-schedulerpolicy"></a><a name="ctor"></a>SchedulerPolicy 

 Constrói uma nova política de agendador e o preenche com valores de [chaves de política](concurrency-namespace-enums.md) agendadores de tempo de execução de simultaneidade e o Gerenciador de recursos de suporte.  
  
```
SchedulerPolicy();

SchedulerPolicy(
    size_t _PolicyKeyCount,
 ...);

SchedulerPolicy(
    const SchedulerPolicy& _SrcPolicy);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_PolicyKeyCount`  
 O número de chave/valor pares seguir o `_PolicyKeyCount` parâmetro.  
  
 `_SrcPolicy`  
 A política de origem para copiar.  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor cria uma nova política de Agendador onde todas as políticas serão inicializadas com seus valores padrão.  
  
 O segundo construtor cria uma nova política de agendador que usa um estilo de parâmetro nomeado de inicialização. Valores após a `_PolicyKeyCount` parâmetro são fornecidos como pares chave/valor. Qualquer chave de política que não é especificado nesse construtor terá seu valor padrão. Este construtor pode lançar exceções [invalid_scheduler_policy_key](invalid-scheduler-policy-key-class.md), [invalid_scheduler_policy_value](invalid-scheduler-policy-value-class.md) ou [invalid_scheduler_policy_thread_specification](invalid-scheduler-policy-thread-specification-class.md).  
  
 O terceiro construtor é um construtor de cópia. Em geral, a maneira mais conveniente para definir uma nova diretiva do Agendador é copiar uma política existente e modificá-lo usando o `SetPolicyValue` ou `SetConcurrencyLimits` métodos.  
  
##  <a name="a-namedtora-schedulerpolicy"></a><a name="dtor"></a>~ SchedulerPolicy 

 Destrói uma política do Agendador.  
  
```
~SchedulerPolicy();
```  
  
##  <a name="a-namesetconcurrencylimitsa-setconcurrencylimits"></a><a name="setconcurrencylimits"></a>SetConcurrencyLimits 

 Define simultaneamente o `MinConcurrency` e `MaxConcurrency` diretivas no `SchedulerPolicy` objeto.  
  
```
void SetConcurrencyLimits(
    unsigned int _MinConcurrency,
    unsigned int _MaxConcurrency = MaxExecutionResources);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_MinConcurrency`  
 O valor para o `MinConcurrency` chave de política.  
  
 `_MaxConcurrency`  
 O valor para o `MaxConcurrency` chave de política.  
  
### <a name="remarks"></a>Comentários  
 O método gerará [invalid_scheduler_policy_thread_specification](invalid-scheduler-policy-thread-specification-class.md) se o valor especificado para o `MinConcurrency` política é maior do que o especificado para o `MaxConcurrency` política.  
  
 O método também pode lançar [invalid_scheduler_policy_value](invalid-scheduler-policy-value-class.md) para outros valores inválidos.  
  
##  <a name="a-namesetpolicyvaluea-setpolicyvalue"></a><a name="setpolicyvalue"></a>SetPolicyValue 

 Define o valor da chave de política fornecido como o `key` parâmetro e retorna o valor antigo.  
  
```
unsigned int SetPolicyValue(
    PolicyElementKey key,
    unsigned int value);
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 A chave de política para definir um valor.  
  
 `value`  
 O valor para definir a chave de política.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a chave especificada o `key` parâmetro tem suporte, o valor antigo da política para a chave é convertido em um `unsigned int`.  
  
### <a name="remarks"></a>Comentários  
 O método gerará [invalid_scheduler_policy_key](invalid-scheduler-policy-key-class.md) para uma chave de diretiva inválida ou cujo valor não pode ser definido por qualquer chave de política de `SetPolicyValue` método.  
  
 O método gerará [invalid_scheduler_policy_value](invalid-scheduler-policy-value-class.md) para um valor que não há suporte para a chave especificada pelo `key` parâmetro.  
  
 Observe que esse método não é permitido definir o `MinConcurrency` ou `MaxConcurrency` políticas. Para definir esses valores, use o [SetConcurrencyLimits](#setconcurrencylimits) método.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Enumeração PolicyElementKey](concurrency-namespace-enums.md)   
 [Classe CurrentScheduler](currentscheduler-class.md)   
 [Classe de Agendador](scheduler-class.md)   
 [Agendador de tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md)




