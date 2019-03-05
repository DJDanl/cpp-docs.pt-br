---
title: 'Como: Selecionar tarefas concluídas'
ms.date: 11/04/2016
helpviewer_keywords:
- selecting among completed tasks [Concurrency Runtime]
- completed tasks, selecting among [Concurrency Runtime]
ms.assetid: c8ccc160-043f-4599-847b-32ed270bb257
ms.openlocfilehash: 0d31f9bd16aaa70cc773e60e4f1193e66ec520f0
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57278022"
---
# <a name="how-to-select-among-completed-tasks"></a>Como: Selecionar tarefas concluídas

Este exemplo mostra como usar o [concurrency::choice](../../parallel/concrt/reference/choice-class.md) e [concurrency::join](../../parallel/concrt/reference/join-class.md) classes para selecionar a primeira tarefa para concluir um algoritmo de pesquisa.

## <a name="example"></a>Exemplo

O exemplo a seguir executa dois algoritmos de pesquisa em paralelo e seleciona o algoritmo primeiro para concluir. Este exemplo define o `employee` tipo, que contém um identificador numérico e um salário de um funcionário. O `find_employee` função localiza o primeiro funcionário que tem o identificador fornecido ou o salário fornecido. O `find_employee` função também controla o caso em que nenhum funcionário tem o identificador fornecido ou salário. O `wmain` função cria uma matriz de `employee` objetos e pesquisas para vários valores de identificador e salário.

O exemplo usa um `choice` objeto para selecionar entre os seguintes casos:

1. Existe um funcionário que tem o identificador fornecido.

1. Existe um funcionário que possui o salário fornecido.

1. Nenhum funcionário que tem o identificador fornecido ou salário existe.

Para os dois primeiros casos, o exemplo usa uma [concurrency::single_assignment](../../parallel/concrt/reference/single-assignment-class.md) objeto para conter o identificador e outro `single_assignment` objeto para manter o salário. O exemplo usa um `join` objeto para o terceiro caso. O `join` objeto é composto de dois adicionais `single_assignment` objetos, um para o caso em que nenhum funcionário que tem o identificador fornecido existe e um para o caso em que nenhum funcionário que possui o salário fornecido existe. O `join` objeto envia uma mensagem quando cada um dos seus membros recebe uma mensagem. Neste exemplo, o `join` objeto envia uma mensagem quando nenhum funcionário que tem o identificador fornecido ou salário existe.

O exemplo usa uma [Concurrency:: structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) objeto para executar ambos os algoritmos de pesquisa em paralelo. Cada tarefa de pesquisa grava em um do `single_assignment` objetos para indicar se o funcionário especificado existe. O exemplo usa o [Concurrency:: Receive](reference/concurrency-namespace-functions.md#receive) função para obter o índice do primeiro buffer que contém uma mensagem e um `switch` bloco para imprimir o resultado.

[!code-cpp[concrt-find-employee#1](../../parallel/concrt/codesnippet/cpp/how-to-select-among-completed-tasks_1.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
Employee with id 14758 has salary 27780.00.
Employee with salary 29150.00 has id 84345.
Employee with id 61935 has salary 29905.00.
No employee has id 899 or salary 31223.00.
```

Este exemplo usa o [concurrency::make_choice](reference/concurrency-namespace-functions.md#make_choice) função auxiliar para criar `choice` objetos e a [concurrency::make_join](reference/concurrency-namespace-functions.md#make_join) função auxiliar para criar `join` objetos.

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `find-employee.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**cl.exe /EHsc find-employee.cpp**

## <a name="see-also"></a>Consulte também

[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)<br/>
[Classe choice](../../parallel/concrt/reference/choice-class.md)<br/>
[Classe join](../../parallel/concrt/reference/join-class.md)
