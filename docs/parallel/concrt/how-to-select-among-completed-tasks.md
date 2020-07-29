---
title: Como selecionar tarefas concluídas
ms.date: 11/04/2016
helpviewer_keywords:
- selecting among completed tasks [Concurrency Runtime]
- completed tasks, selecting among [Concurrency Runtime]
ms.assetid: c8ccc160-043f-4599-847b-32ed270bb257
ms.openlocfilehash: fd9940dad0cd2f202bdc734a81a7eb37cd79420c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226718"
---
# <a name="how-to-select-among-completed-tasks"></a>Como selecionar tarefas concluídas

Este exemplo mostra como usar as classes [Concurrency:: Choice](../../parallel/concrt/reference/choice-class.md) e [Concurrency:: join](../../parallel/concrt/reference/join-class.md) para selecionar a primeira tarefa para concluir um algoritmo de pesquisa.

## <a name="example"></a>Exemplo

O exemplo a seguir executa dois algoritmos de pesquisa em paralelo e seleciona o primeiro algoritmo a ser concluído. Este exemplo define o `employee` tipo, que contém um identificador numérico e um salário para um funcionário. A `find_employee` função localiza o primeiro funcionário que tem o identificador fornecido ou o salário fornecido. A `find_employee` função também manipula o caso em que nenhum funcionário tem o identificador ou salário fornecido. A `wmain` função cria uma matriz de `employee` objetos e procura vários valores de identificador e salário.

O exemplo usa um `choice` objeto para selecionar entre os seguintes casos:

1. Existe um funcionário que tem o identificador fornecido.

1. Existe um funcionário que tem o salário fornecido.

1. Não existe nenhum funcionário com o identificador ou salário fornecido.

Para os dois primeiros casos, o exemplo usa um objeto [Concurrency:: single_assignment](../../parallel/concrt/reference/single-assignment-class.md) para manter o identificador e outro `single_assignment` objeto para manter o salário. O exemplo usa um `join` objeto para o terceiro caso. O `join` objeto é composto `single_assignment` por dois objetos adicionais, um para o caso em que nenhum funcionário com o identificador fornecido existe e outro para o caso em que não há funcionário com o salário fornecido. O `join` objeto envia uma mensagem quando cada um de seus membros recebe uma mensagem. Neste exemplo, o `join` objeto envia uma mensagem quando não existe nenhum funcionário com o identificador ou salário fornecido.

O exemplo usa um objeto [Concurrency:: structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) para executar ambos os algoritmos de pesquisa em paralelo. Cada tarefa de pesquisa grava em um dos `single_assignment` objetos para indicar se o funcionário fornecido existe. O exemplo usa a função [Concurrency:: Receive](reference/concurrency-namespace-functions.md#receive) para obter o índice do primeiro buffer que contém uma mensagem e um **`switch`** bloco para imprimir o resultado.

[!code-cpp[concrt-find-employee#1](../../parallel/concrt/codesnippet/cpp/how-to-select-among-completed-tasks_1.cpp)]

Este exemplo gerencia a seguinte saída.

```Output
Employee with id 14758 has salary 27780.00.
Employee with salary 29150.00 has id 84345.
Employee with id 61935 has salary 29905.00.
No employee has id 899 or salary 31223.00.
```

Este exemplo usa a função auxiliar [Concurrency:: make_choice](reference/concurrency-namespace-functions.md#make_choice) para criar `choice` objetos e a função auxiliar [Concurrency:: make_join](reference/concurrency-namespace-functions.md#make_join) para criar `join` objetos.

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `find-employee.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **cl.exe/EHsc Find-Employee. cpp**

## <a name="see-also"></a>Confira também

[Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Funções de passagem de mensagens](../../parallel/concrt/message-passing-functions.md)<br/>
[Classe Choice](../../parallel/concrt/reference/choice-class.md)<br/>
[Classe de junção](../../parallel/concrt/reference/join-class.md)
