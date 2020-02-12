---
title: Classe task_handle
ms.date: 03/27/2019
f1_keywords:
- task_handle
- PPL/concurrency::task_handle
- PPL/concurrency::task_handle::task_handle
helpviewer_keywords:
- task_handle class
ms.assetid: 74a34b15-708b-4231-a509-947874292b13
ms.openlocfilehash: a61e72f14448d5033d5be9069ffeec7d3bb08061
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142548"
---
# <a name="task_handle-class"></a>Classe task_handle

A classe `task_handle` representa um item de trabalho paralelo individual. Ele encapsula as instruções e os dados necessários para executar uma parte do trabalho.

## <a name="syntax"></a>Sintaxe

```cpp
template<
    typename _Function
>
class task_handle : public ::Concurrency::details::_UnrealizedChore;
```

### <a name="parameters"></a>Parâmetros

*_Function*<br/>
O tipo do objeto de função que será invocado para executar o trabalho representado pelo objeto `task_handle`.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[task_handle](#task_handle)|Constrói um novo objeto `task_handle`. O trabalho da tarefa é executado invocando a função especificada como um parâmetro para o construtor.|
|[~ task_handle destruidor](#dtor)|Destrói o objeto `task_handle`.|

### <a name="public-operators"></a>Operadores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[operator()](#task_handle__operator_call)|O operador de chamada de função que o tempo de execução invoca para executar o trabalho do identificador de tarefa.|

## <a name="remarks"></a>Comentários

`task_handle` objetos podem ser usados em conjunto com um `structured_task_group` ou um objeto `task_group` mais geral, para decompor o trabalho em tarefas paralelas. Para obter mais informações, consulte [paralelismo de tarefas](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).

Observe que o criador de um objeto `task_handle` é responsável por manter o tempo de vida do objeto de `task_handle` criado até que ele não seja mais exigido pelo Tempo de Execução de Simultaneidade. Normalmente, isso significa que o objeto `task_handle` não deve ser destruido até que o método `wait` ou `run_and_wait` do `task_group` ou `structured_task_group` ao qual ele foi enfileirado tenha sido chamado.

os objetos de `task_handle` geralmente são usados em C++ conjunto com lambdas. Como você não sabe o tipo true do lambda, a função [make_task](concurrency-namespace-functions.md#make_task) normalmente é usada para criar um objeto `task_handle`.

O tempo de execução cria uma cópia da função de trabalho que você passa para um objeto `task_handle`. Portanto, todas as alterações de estado que ocorrem em um objeto de função que você passa para um objeto de `task_handle` não aparecerão na sua cópia desse objeto de função.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`task_handle`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ppl. h

**Namespace:** simultaneidade

## <a name="task_handle__operator_call"></a>operador ()

O operador de chamada de função que o tempo de execução invoca para executar o trabalho do identificador de tarefa.

```cpp
void operator()() const;
```

## <a name="task_handle"></a>task_handle

Constrói um novo objeto `task_handle`. O trabalho da tarefa é executado invocando a função especificada como um parâmetro para o construtor.

```cpp
task_handle(const _Function& _Func);
```

### <a name="parameters"></a>Parâmetros

*_Func*<br/>
A função que será invocada para executar o trabalho representado pelo objeto `task_handle`. Isso pode ser um functor lambda, um ponteiro para uma função ou qualquer objeto que ofereça suporte a uma versão do operador de chamada de função com a assinatura `void operator()()`.

### <a name="remarks"></a>Comentários

O tempo de execução cria uma cópia da função de trabalho que você passa para o construtor. Portanto, todas as alterações de estado que ocorrem em um objeto de função que você passa para um objeto de `task_handle` não aparecerão na sua cópia desse objeto de função.

## <a name="dtor"></a>~ task_handle

Destrói o objeto `task_handle`.

```cpp
~task_handle();
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe task_group](task-group-class.md)<br/>
[Classe structured_task_group](structured-task-group-class.md)
