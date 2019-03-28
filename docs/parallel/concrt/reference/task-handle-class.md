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
ms.openlocfilehash: 8528bc212603484be9325ed967e9475e4faa1348
ms.sourcegitcommit: 309dc532f13242854b47759cef846de59bb807f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/28/2019
ms.locfileid: "58565094"
---
# <a name="taskhandle-class"></a>Classe task_handle

O `task_handle` classe representa um item de trabalho paralelas individuais. Ele encapsula as instruções e os dados necessários para executar um trabalho.

## <a name="syntax"></a>Sintaxe

```
template<
    typename _Function
>
class task_handle : public ::Concurrency::details::_UnrealizedChore;
```

#### <a name="parameters"></a>Parâmetros

*_Function*<br/>
O tipo do objeto de função que será chamado para executar o trabalho representado pelo `task_handle` objeto.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[task_handle](#task_handle)|Constrói um novo objeto `task_handle`. O trabalho da tarefa é executado invocando a função especificada como um parâmetro para o construtor.|
|[~ task_handle destruidor](#dtor)|Destrói o `task_handle` objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operator()](#task_handle__operator_call)|O operador de chamada de função que o tempo de execução invoca para realizar o trabalho do identificador de tarefa.|

## <a name="remarks"></a>Comentários

`task_handle` objetos podem ser usados em conjunto com um `structured_task_group` ou um mais geral `task_group` objeto, decompor o trabalho em tarefas paralelas. Para obter mais informações, consulte [paralelismo de tarefas](../../../parallel/concrt/task-parallelism-concurrency-runtime.md).

Observe que o criador de um `task_handle` objeto é responsável por manter o tempo de vida de criado `task_handle` objeto até que ele não é exigido pelo tempo de execução de simultaneidade. Normalmente, isso significa que o `task_handle` objeto não deve destruir até que o `wait` ou `run_and_wait` método da `task_group` ou `structured_task_group` para que ele está na fila tiver sido chamado.

`task_handle` Normalmente, os objetos são usados em conjunto com lambdas de C++. Porque você não souber o tipo true de lambda, o [make_task](concurrency-namespace-functions.md#make_task) função normalmente é usada para criar um `task_handle` objeto.

O tempo de execução cria uma cópia da função de trabalho que você passa para um `task_handle` objeto. Portanto, as alterações de estado que ocorrem em uma função de objeto que você passar para um `task_handle` objeto não aparecerá na sua cópia desse objeto de função.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`task_handle`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ppl.h

**Namespace:** simultaneidade

##  <a name="task_handle__operator_call"></a> operator()

O operador de chamada de função que o tempo de execução invoca para realizar o trabalho do identificador de tarefa.

```
void operator()() const;
```

## <a name="taskhandle"></a>task_handle

Constrói um novo objeto `task_handle`. O trabalho da tarefa é executado invocando a função especificada como um parâmetro para o construtor.

```
task_handle(const _Function& _Func);
```

### <a name="parameters"></a>Parâmetros

*_Func*<br/>
A função que será invocada para executar o trabalho representado pelo `task_handle` objeto. Isso pode ser um funtor lambda, um ponteiro para uma função, ou qualquer objeto que dá suporte a uma versão do operador de chamada de função com a assinatura `void operator()()`.

### <a name="remarks"></a>Comentários

O tempo de execução cria uma cópia da função de trabalho que você passa ao construtor. Portanto, as alterações de estado que ocorrem em uma função de objeto que você passar para um `task_handle` objeto não aparecerá na sua cópia desse objeto de função.

##  <a name="dtor"></a> ~task_handle

Destrói o `task_handle` objeto.

```
~task_handle();
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe task_group](task-group-class.md)<br/>
[Classe structured_task_group](structured-task-group-class.md)
