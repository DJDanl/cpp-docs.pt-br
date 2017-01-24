---
title: "Como selecionar tarefas conclu&#237;das | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "selecionando entre tarefas concluídas [Tempo de Execução de Simultaneidade]"
  - "tarefas concluídas, selecionando entre [tempo de execução de simultaneidade]"
ms.assetid: c8ccc160-043f-4599-847b-32ed270bb257
caps.latest.revision: 17
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como selecionar tarefas conclu&#237;das
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este exemplo mostra como usar as classes de [concurrency::choice](../../parallel/concrt/reference/choice-class.md) e de [concurrency::join](../Topic/join%20Class.md) para selecionar a primeira tarefa complete um algoritmo de pesquisa.  
  
## Exemplo  
 O exemplo a seguir executa dois algoritmos de busca em paralelo e seleciona o primeiro algoritmo para concluir.  Este exemplo define o tipo de `employee` , que contém um identificador numérico e um salário do funcionário.  A função de `find_employee` localiza o primeiro funcionário que tem o identificador fornecido ou o salário fornecido.  A função de `find_employee` também trata os casos em que nenhum funcionário tem o identificador ou o salário fornecido.  A função de `wmain` cria uma matriz de objetos do e pesquisas de `employee` para vários valores do identificador e o salário.  
  
 O exemplo usa um objeto de `choice` para selecionar entre os seguintes casos:  
  
1.  Um funcionário que tem o identificador fornecido existe.  
  
2.  Um funcionário que tem o salário fornecido existe.  
  
3.  Nenhum funcionário que tem o identificador ou o salário fornecido existe.  
  
 Para os dois primeiros casos, o exemplo usa para um objeto de [concurrency::single\_assignment](../../parallel/concrt/reference/single-assignment-class.md) conter o identificador e outro objeto `single_assignment` para manter o salário.  O exemplo usa um objeto de `join` para o terceiro casos.  O objeto de `join` é composto de dois objetos adicionais de `single_assignment` , um para as caixas em que nenhum funcionário que tem o identificador fornecido existe, e um para casos onde nenhum funcionário que possui o salário fornecido existe.  O objeto de `join` envia uma mensagem quando cada um de seus membros recebe uma mensagem.  Neste exemplo, o objeto de `join` envia uma mensagem quando nenhum funcionário que tem o identificador ou o salário fornecido existe.  
  
 O exemplo usa um objeto de [concurrency::structured\_task\_group](../../parallel/concrt/reference/structured-task-group-class.md) para ser executados em paralelo ambos os algoritmos de pesquisa.  Cada tarefa de pesquisa grava um dos objetos de `single_assignment` para indicar se o funcionário fornecido existe.  O exemplo a seguir usa a função de [concurrency::receive](../Topic/receive%20Function.md) para obter o índice do primeiro buffer que contém uma mensagem e um bloco de `switch` para imprimir o resultado.  
  
 [!code-cpp[concrt-find-employee#1](../../parallel/concrt/codesnippet/CPP/how-to-select-among-completed-tasks_1.cpp)]  
  
 O exemplo produz a seguinte saída.  
  
  **O funcionário com ID 14758 tem o salário 27780,00.**  
**O funcionário com rendas 29150,00 tem a ID 84345.**  
**O funcionário com ID 61935 tem o salário 29905,00.**  
**Nenhum funcionário tem a ID 899 ou o salário 31223,00.** Este exemplo usa a função auxiliar de [concurrency::make\_choice](../Topic/make_choice%20Function.md) para criar objetos de `choice` e a função auxiliar de [concurrency::make\_join](../Topic/make_join%20Function.md) para criar objetos de `join` .  
  
## Compilando o código  
 Copie o código de exemplo e cole\-o em um projeto do Visual Studio, ou cole\-o em um arquivo chamado `find-employee.cpp` e execute o comando a seguir em uma janela de prompt de comando do Visual Studio.  
  
 **cl.exe \/EHsc find\-employee.cpp**  
  
## Consulte também  
 [Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md)   
 [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)   
 [Funções de transmissão de mensagem](../../parallel/concrt/message-passing-functions.md)   
 [Classe choice](../../parallel/concrt/reference/choice-class.md)   
 [Classe join](../Topic/join%20Class.md)