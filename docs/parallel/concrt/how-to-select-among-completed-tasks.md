---
title: "Como: selecionar tarefas concluídas | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- selecting among completed tasks [Concurrency Runtime]
- completed tasks, selecting among [Concurrency Runtime]
ms.assetid: c8ccc160-043f-4599-847b-32ed270bb257
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4cce496f205052bdb6986abc0cee158622e93545
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-select-among-completed-tasks"></a>Como selecionar tarefas concluídas
Este exemplo mostra como usar o [concurrency::choice](../../parallel/concrt/reference/choice-class.md) e [concurrency::join](../../parallel/concrt/reference/join-class.md) classes para selecionar a primeira tarefa para concluir um algoritmo de pesquisa.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir executa dois algoritmos de pesquisa em paralelo e seleciona o algoritmo primeiro para concluir. Este exemplo define o `employee` tipo, que contém um identificador numérico e um salário para um funcionário. O `find_employee` função localiza o primeiro funcionário que possui o identificador fornecido ou o salário fornecido. O `find_employee` função também controla quando nenhum funcionário tem o identificador fornecido ou o salário. O `wmain` função cria uma matriz de `employee` objetos e pesquisas para vários valores de identificador e salário.  
  
 O exemplo usa um `choice` objeto para selecionar entre os seguintes casos:  
  
1.  Existe um funcionário que tem o identificador fornecido.  
  
2.  Existe um funcionário que possui o salário fornecido.  
  
3.  Nenhum funcionário que possui o identificador fornecido ou o salário existe.  
  
 Para os dois primeiros casos, o exemplo usa um [concurrency::single_assignment](../../parallel/concrt/reference/single-assignment-class.md) objeto para manter o identificador e outro `single_assignment` objeto para manter o salário. O exemplo usa um `join` objeto para o terceiro caso. O `join` objeto é composto de dois adicionais `single_assignment` objetos, uma para o caso onde não existe nenhum funcionário com o identificador fornecido e outra para o caso onde não existe nenhum funcionário que possui o salário fornecido. O `join` objeto envia uma mensagem quando cada um de seus membros recebe uma mensagem. Neste exemplo, o `join` objeto envia uma mensagem quando nenhum funcionário com o identificador fornecido ou salário existe.  
  
 O exemplo usa um [concurrency::structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) objeto para executar ambos os algoritmos de pesquisa em paralelo. Cada tarefa de pesquisa grava em um do `single_assignment` objetos para indicar se o funcionário especificado existe. O exemplo usa o [concurrency::receive](reference/concurrency-namespace-functions.md#receive) função para obter o índice do primeiro buffer que contém uma mensagem e um `switch` bloco para imprimir o resultado.  
  
 [!code-cpp[concrt-find-employee#1](../../parallel/concrt/codesnippet/cpp/how-to-select-among-completed-tasks_1.cpp)]  
  
 Este exemplo gerencia a seguinte saída.  
  
```Output  
Employee with id 14758 has salary 27780.00.  
Employee with salary 29150.00 has id 84345.  
Employee with id 61935 has salary 29905.00.  
No employee has id 899 or salary 31223.00.  
```  
  
 Este exemplo usa o [concurrency::make_choice](reference/concurrency-namespace-functions.md#make_choice) função auxiliar para criar `choice` objetos e o [concurrency::make_join](reference/concurrency-namespace-functions.md#make_join) função auxiliar para criar `join` objetos.  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `find-employee.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc find-employee.cpp**  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)   
 [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)   
 [Funções de transmissão de mensagens](../../parallel/concrt/message-passing-functions.md)   
 [Classe Choice](../../parallel/concrt/reference/choice-class.md)   
 [Classe join](../../parallel/concrt/reference/join-class.md)
