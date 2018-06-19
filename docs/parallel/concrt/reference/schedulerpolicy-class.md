---
title: Classe SchedulerPolicy | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- SchedulerPolicy
- concrt/concurrency::SchedulerPolicy
- concrt/concurrency::SchedulerPolicy::SchedulerPolicy
- concrt/concurrency::SchedulerPolicy::GetPolicyValue
- concrt/concurrency::SchedulerPolicy::SetConcurrencyLimits
- concrt/concurrency::SchedulerPolicy::SetPolicyValue
dev_langs:
- C++
helpviewer_keywords:
- SchedulerPolicy class
ms.assetid: bcebf51a-65f8-45a3-809b-d1ff93527dc4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9f23e95bafa9920c520fa7c01518873769945770
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33691775"
---
# <a name="schedulerpolicy-class"></a>Classe SchedulerPolicy
O `SchedulerPolicy` classe contém um conjunto de pares chave/valor, um para cada elemento de diretiva que controlam o comportamento de uma instância do Agendador.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class SchedulerPolicy;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[SchedulerPolicy](#ctor)|Sobrecarregado. Constrói uma nova política de agendador e o preenche com os valores para [chaves política](concurrency-namespace-enums.md) agendadores de tempo de execução de simultaneidade e o Gerenciador de recursos de suporte.|  
|[~ Destruidor SchedulerPolicy](#dtor)|Destrói a uma política do Agendador.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[GetPolicyValue](#getpolicyvalue)|Recupera o valor da chave de política fornecido como o `key` parâmetro.|  
|[SetConcurrencyLimits](#setconcurrencylimits)|Define simultaneamente a `MinConcurrency` e `MaxConcurrency` políticas no `SchedulerPolicy` objeto.|  
|[SetPolicyValue](#setpolicyvalue)|Define o valor da chave de política fornecido como o `key` parâmetro e retorna o valor antigo.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operator=](#operator_eq)|Atribui a política do Agendador de outra política do Agendador.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações sobre as políticas que podem ser controlados usando o `SchedulerPolicy` de classe, consulte [PolicyElementKey](concurrency-namespace-enums.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `SchedulerPolicy`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h, concrtrm.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="getpolicyvalue"></a> GetPolicyValue 

 Recupera o valor da chave de política fornecido como o `key` parâmetro.  
  
```
unsigned int GetPolicyValue(PolicyElementKey key) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `key`  
 A chave de política para recuperar um valor.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a chave especificada o `key` parâmetro tem suporte, o valor de política para a chave de conversão para um `unsigned int`.  
  
### <a name="remarks"></a>Comentários  
 O método lançará [invalid_scheduler_policy_key](invalid-scheduler-policy-key-class.md) para uma chave de política inválido.  
  
##  <a name="operator_eq"></a> operador = 

 Atribui a política do Agendador de outra política do Agendador.  
  
```
SchedulerPolicy& operator= (const SchedulerPolicy& _RhsPolicy);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_RhsPolicy`  
 A política para atribuir a essa política.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência à política de Agendador.  
  
### <a name="remarks"></a>Comentários  
 Normalmente, a maneira mais conveniente de definir uma nova política de Agendador é copiar uma política existente e modificá-lo usando o `SetPolicyValue` ou `SetConcurrencyLimits` métodos.  
  
##  <a name="ctor"></a> SchedulerPolicy 

 Constrói uma nova política de agendador e o preenche com os valores para [chaves política](concurrency-namespace-enums.md) agendadores de tempo de execução de simultaneidade e o Gerenciador de recursos de suporte.  
  
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
 O construtor primeiro cria uma nova política de Agendador onde todas as políticas serão inicializadas com seus valores padrão.  
  
 O segundo construtor cria uma nova política de agendador que usa um estilo de parâmetro de chamada da inicialização. Os valores após a `_PolicyKeyCount` parâmetro são fornecidos como pares chave/valor. Nenhuma chave de política que não é especificado nesse construtor terá seu valor padrão. Esse construtor pode gerar exceções [invalid_scheduler_policy_key](invalid-scheduler-policy-key-class.md), [invalid_scheduler_policy_value](invalid-scheduler-policy-value-class.md) ou [invalid_scheduler_policy_thread_specification](invalid-scheduler-policy-thread-specification-class.md).  
  
 O construtor de terceiro é um construtor de cópia. Normalmente, a maneira mais conveniente de definir uma nova política de Agendador é copiar uma política existente e modificá-lo usando o `SetPolicyValue` ou `SetConcurrencyLimits` métodos.  
  
##  <a name="dtor"></a> ~ SchedulerPolicy 

 Destrói a uma política do Agendador.  
  
```
~SchedulerPolicy();
```  
  
##  <a name="setconcurrencylimits"></a> SetConcurrencyLimits 

 Define simultaneamente a `MinConcurrency` e `MaxConcurrency` políticas no `SchedulerPolicy` objeto.  
  
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
 O método lançará [invalid_scheduler_policy_thread_specification](invalid-scheduler-policy-thread-specification-class.md) se o valor especificado para o `MinConcurrency` política é maior do que o especificado para o `MaxConcurrency` política.  
  
 O método também pode lançar [invalid_scheduler_policy_value](invalid-scheduler-policy-value-class.md) para outros valores inválidos.  
  
##  <a name="setpolicyvalue"></a> SetPolicyValue 

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
 O método lançará [invalid_scheduler_policy_key](invalid-scheduler-policy-key-class.md) para uma chave de política inválida ou qualquer chave de política cujo valor não pode ser definido pelo `SetPolicyValue` método.  
  
 O método lançará [invalid_scheduler_policy_value](invalid-scheduler-policy-value-class.md) para um valor que não há suporte para a chave especificada pelo `key` parâmetro.  
  
 Observe que esse método não é permitido definir o `MinConcurrency` ou `MaxConcurrency` políticas. Para definir esses valores, use o [SetConcurrencyLimits](#setconcurrencylimits) método.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [PolicyElementKey](concurrency-namespace-enums.md)   
 [Classe CurrentScheduler](currentscheduler-class.md)   
 [Classe de Agendador](scheduler-class.md)   
 [Agendador de tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md)



