---
title: Classe SchedulerPolicy
ms.date: 11/04/2016
f1_keywords:
- SchedulerPolicy
- concrt/concurrency::SchedulerPolicy
- concrt/concurrency::SchedulerPolicy::SchedulerPolicy
- concrt/concurrency::SchedulerPolicy::GetPolicyValue
- concrt/concurrency::SchedulerPolicy::SetConcurrencyLimits
- concrt/concurrency::SchedulerPolicy::SetPolicyValue
helpviewer_keywords:
- SchedulerPolicy class
ms.assetid: bcebf51a-65f8-45a3-809b-d1ff93527dc4
ms.openlocfilehash: b7b99dae2ffb58123c05a65872e4c71e149ac12c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219567"
---
# <a name="schedulerpolicy-class"></a>Classe SchedulerPolicy

A `SchedulerPolicy` classe contém um conjunto de pares chave/valor, um para cada elemento de política, que controla o comportamento de uma instância do Agendador.

## <a name="syntax"></a>Sintaxe

```cpp
class SchedulerPolicy;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[SchedulerPolicy](#ctor)|Sobrecarregado. Constrói uma nova política de Agendador e a preenche com valores para [chaves de política](concurrency-namespace-enums.md) com suporte pelos agendadores de tempo de execução de simultaneidade e pelo Gerenciador de recursos.|
|[~ Destruidor SchedulerPolicy](#dtor)|Destrói uma política do Agendador.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[GetPolicyValue](#getpolicyvalue)|Recupera o valor da chave de política fornecida como o `key` parâmetro.|
|[SetConcurrencyLimits](#setconcurrencylimits)|Define simultaneamente as `MinConcurrency` `MaxConcurrency` políticas e no `SchedulerPolicy` objeto.|
|[SetPolicyValue](#setpolicyvalue)|Define o valor da chave de política fornecida como o `key` parâmetro e retorna o valor antigo.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operador =](#operator_eq)|Atribui a política do Agendador de outra política do Agendador.|

## <a name="remarks"></a>Comentários

Para obter mais informações sobre as políticas que podem ser controladas usando a `SchedulerPolicy` classe, consulte [PolicyElementKey](concurrency-namespace-enums.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`SchedulerPolicy`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ConcRT. h, concrtrm. h

**Namespace:** simultaneidade

## <a name="getpolicyvalue"></a><a name="getpolicyvalue"></a>GetPolicyValue

Recupera o valor da chave de política fornecida como o `key` parâmetro.

```cpp
unsigned int GetPolicyValue(PolicyElementKey key) const;
```

### <a name="parameters"></a>parâmetros

*chave*<br/>
A chave de política para a qual recuperar um valor.

### <a name="return-value"></a>Valor retornado

Se a chave especificada pelo `key` parâmetro tiver suporte, o valor da política para a conversão de chave para um **`unsigned int`** .

### <a name="remarks"></a>Comentários

O método gerará [invalid_scheduler_policy_key](invalid-scheduler-policy-key-class.md) para uma chave de política inválida.

## <a name="operator"></a><a name="operator_eq"></a>operador =

Atribui a política do Agendador de outra política do Agendador.

```cpp
SchedulerPolicy& operator= (const SchedulerPolicy& _RhsPolicy);
```

### <a name="parameters"></a>parâmetros

*_RhsPolicy*<br/>
A política a ser atribuída a esta política.

### <a name="return-value"></a>Valor retornado

Uma referência à política do Agendador.

### <a name="remarks"></a>Comentários

Geralmente, a maneira mais conveniente de definir uma nova política de Agendador é copiar uma política existente e modificá-la usando `SetPolicyValue` os `SetConcurrencyLimits` métodos ou.

## <a name="schedulerpolicy"></a><a name="ctor"></a>SchedulerPolicy

Constrói uma nova política de Agendador e a preenche com valores para [chaves de política](concurrency-namespace-enums.md) com suporte pelos agendadores de tempo de execução de simultaneidade e pelo Gerenciador de recursos.

```cpp
SchedulerPolicy();

SchedulerPolicy(
    size_t _PolicyKeyCount,
...);

SchedulerPolicy(
    const SchedulerPolicy& _SrcPolicy);
```

### <a name="parameters"></a>parâmetros

*_PolicyKeyCount*<br/>
O número de pares de chave/valor que seguem o `_PolicyKeyCount` parâmetro.

*_SrcPolicy*<br/>
A política de origem a ser copiada.

### <a name="remarks"></a>Comentários

O primeiro construtor cria uma nova política de Agendador em que todas as políticas serão inicializadas para seus valores padrão.

O segundo construtor cria uma nova política de Agendador que usa um estilo de parâmetro nomeado de inicialização. Os valores após o `_PolicyKeyCount` parâmetro são fornecidos como pares de chave/valor. Qualquer chave de política que não for especificada neste Construtor terá seu valor padrão. Esse construtor pode lançar as exceções [invalid_scheduler_policy_key](invalid-scheduler-policy-key-class.md), [invalid_scheduler_policy_value](invalid-scheduler-policy-value-class.md) ou [invalid_scheduler_policy_thread_specification](invalid-scheduler-policy-thread-specification-class.md).

O terceiro construtor é um construtor de cópia. Geralmente, a maneira mais conveniente de definir uma nova política de Agendador é copiar uma política existente e modificá-la usando `SetPolicyValue` os `SetConcurrencyLimits` métodos ou.

## <a name="schedulerpolicy"></a><a name="dtor"></a>~ SchedulerPolicy

Destrói uma política do Agendador.

```cpp
~SchedulerPolicy();
```

## <a name="setconcurrencylimits"></a><a name="setconcurrencylimits"></a>SetConcurrencyLimits

Define simultaneamente as `MinConcurrency` `MaxConcurrency` políticas e no `SchedulerPolicy` objeto.

```cpp
void SetConcurrencyLimits(
    unsigned int _MinConcurrency,
    unsigned int _MaxConcurrency = MaxExecutionResources);
```

### <a name="parameters"></a>parâmetros

*_MinConcurrency*<br/>
O valor da `MinConcurrency` chave de política.

*_MaxConcurrency*<br/>
O valor da `MaxConcurrency` chave de política.

### <a name="remarks"></a>Comentários

O método gerará [invalid_scheduler_policy_thread_specification](invalid-scheduler-policy-thread-specification-class.md) se o valor especificado para a `MinConcurrency` política for maior que o especificado para a `MaxConcurrency` política.

O método também pode gerar [invalid_scheduler_policy_value](invalid-scheduler-policy-value-class.md) para outros valores inválidos.

## <a name="setpolicyvalue"></a><a name="setpolicyvalue"></a>SetPolicyValue

Define o valor da chave de política fornecida como o `key` parâmetro e retorna o valor antigo.

```cpp
unsigned int SetPolicyValue(
    PolicyElementKey key,
    unsigned int value);
```

### <a name="parameters"></a>parâmetros

*chave*<br/>
A chave de política para a qual definir um valor.

*value*<br/>
O valor para o qual definir a chave de política.

### <a name="return-value"></a>Valor retornado

Se a chave especificada pelo `key` parâmetro tiver suporte, o valor de política antigo para a conversão de chave para um **`unsigned int`** .

### <a name="remarks"></a>Comentários

O método gerará [invalid_scheduler_policy_key](invalid-scheduler-policy-key-class.md) para uma chave de política inválida ou qualquer chave de política cujo valor não possa ser definido pelo `SetPolicyValue` método.

O método gerará [invalid_scheduler_policy_value](invalid-scheduler-policy-value-class.md) para um valor que não tem suporte para a chave especificada pelo `key` parâmetro.

Observe que esse método não tem permissão para definir as `MinConcurrency` `MaxConcurrency` políticas ou. Para definir esses valores, use o método [SetConcurrencyLimits](#setconcurrencylimits) .

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[PolicyElementKey](concurrency-namespace-enums.md)<br/>
[Classe CurrentScheduler](currentscheduler-class.md)<br/>
[Classe do Agendador](scheduler-class.md)<br/>
[Agendador de Tarefas](../../../parallel/concrt/task-scheduler-concurrency-runtime.md)
