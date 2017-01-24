---
title: "Como converter um loop OpenMP que usa tratamento de exce&#231;&#245;es para usar o tempo de execu&#231;&#227;o de simultaneidade | Microsoft Docs"
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
  - "exceção de manipulação, convertendo de OpenMP no tempo de execução de simultaneidade"
  - "Convertendo de OpenMP no tempo de execução de simultaneidade, tratamento de exceção"
ms.assetid: 03c28196-21ba-439e-8641-afab1c283e1a
caps.latest.revision: 11
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como converter um loop OpenMP que usa tratamento de exce&#231;&#245;es para usar o tempo de execu&#231;&#227;o de simultaneidade
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este exemplo demonstra como converter um loop OpenMP [paralela](../../parallel/openmp/reference/parallel.md)[para](../Topic/for%20\(OpenMP\).md) que executa a manipulação de exceção para usar o mecanismo de manipulação de exceção em tempo de execução de simultaneidade.  
  
 Em OpenMP, uma exceção que é lançada em uma região paralela deve ser capturada e tratado da mesma região pelo mesmo thread.  Uma exceção que escape a região paralela é capturada pelo manipulador de exceção sem\-tratamento, que encerra o processo por padrão.  
  
 Em tempo de execução de simultaneidade, quando você gerencie uma exceção no corpo de uma função de trabalho que você transmita a um grupo de trabalho como um objeto de [concurrency::task\_group](../Topic/task_group%20Class.md) ou de [concurrency::structured\_task\_group](../../parallel/concrt/reference/structured-task-group-class.md) , ou um algoritmo paralelo como [concurrency::parallel\_for](../Topic/parallel_for%20Function.md), o tempo de execução que armazena exceção e realiza marshaling ao contexto aguardando o grupo de trabalho ou o algoritmo para concluir.  Para grupos de trabalho, o contexto de espera é o contexto que chama [concurrency::task\_group::wait](../Topic/task_group::wait%20Method.md), [concurrency::structured\_task\_group::wait](../Topic/structured_task_group::wait%20Method.md), [concurrency::task\_group::run\_and\_wait](../Topic/task_group::run_and_wait%20Method.md), ou [concurrency::structured\_task\_group::run\_and\_wait](../Topic/structured_task_group::run_and_wait%20Method.md).  Para um algoritmo paralelo, o contexto de espera é o contexto que chamou esse algoritmo.  O tempo de execução também para todas as tarefas ativas que estão no grupo de trabalho, inclusive aqueles em grupos de trabalho filhos, e em descarta todas as tarefas que ainda não sejam iniciados.  
  
## Exemplo  
 Este exemplo demonstra como tratar exceções em uma região OpenMP em `parallel` e uma chamada para `parallel_for`.  A função de `do_work` executa uma solicitação de alocação de memória que não tenha êxito e em virtude disso gerará uma exceção do tipo [std::bad\_alloc](../../standard-library/bad-alloc-class.md).  Na versão que usa OpenMP, o thread que gerou a exceção também deve capturar\-la.  Ou seja cada iteração do loop paralelos OpenMP deve controlar a exceção.  Na versão que usa o tempo de execução de simultaneidade, o thread principal captura uma exceção que é lançada por outro thread.  
  
 [!code-cpp[concrt-openmp#3](../../parallel/concrt/codesnippet/CPP/convert-an-openmp-loop-that uses-exception-handling_1.cpp)]  
  
 O exemplo produz a seguinte saída.  
  
  **Usando OpenMP…**  
**Um erro de tipo de “std::bad\_alloc classe” ocorreu.**  
**Um erro de tipo de “std::bad\_alloc classe” ocorreu.**  
**Um erro de tipo de “std::bad\_alloc classe” ocorreu.**  
**Um erro de tipo de “std::bad\_alloc classe” ocorreu.**  
**Um erro de tipo de “std::bad\_alloc classe” ocorreu.**  
**Um erro de tipo de “std::bad\_alloc classe” ocorreu.**  
**Um erro de tipo de “std::bad\_alloc classe” ocorreu.**  
**Um erro de tipo de “std::bad\_alloc classe” ocorreu.**  
**Um erro de tipo de “std::bad\_alloc classe” ocorreu.**  
**Um erro de tipo de “std::bad\_alloc classe” ocorreu.**  
**Usando o tempo de execução de simultaneidade…**  
**Um erro de tipo de “std::bad\_alloc classe” ocorreu.** Na versão deste exemplo que usa OpenMP, a exceção ocorre no e é tratada por cada iteração do loop.  Na versão que usa o tempo de execução de simultaneidade, os repositórios de tempo de execução a exceção, para todas tarefas ativas, em descarta algumas tarefas que ainda não sejam iniciados, e em realiza marshaling a exceção ao contexto que chama `parallel_for`.  
  
 Se você precisar que a versão que usa OpenMP terminar depois que a exceção ocorre, você pode usar um sinalizador booliano para sinalizar a outras interações do loop que o erro ocorreu.  Como no exemplo no tópico [Como converter um loop OpenMP que usa cancelamento para usar o tempo de execução de simultaneidade](../../parallel/concrt/convert-an-openmp-loop-that-uses-cancellation.md), as iterações subsequentes do loop não criam nada se o sinalizador é definido.  Por outro lado, se você requer que o loop que usa o tempo de execução de simultaneidade continuará depois que a exceção ocorre, o tratará a exceção no corpo de loop paralelo em si.  
  
 Outros componentes de tempo de execução de simultaneidade, como agentes assíncronas e tarefas de peso leve, não transmitem exceções.  Em vez disso, as exceção sem\-tratamento são capturadas pelo manipulador de exceção sem\-tratamento, que encerra o processo por padrão.  Para obter mais informações sobre a manipulação de exceções, consulte [Tratamento de Exceção](../Topic/Exception%20Handling%20in%20the%20Concurrency%20Runtime.md).  
  
 Para obter mais informações sobre como `parallel_for` e outros algoritmos paralelos, consulte [Algoritmos paralelos](../Topic/Parallel%20Algorithms.md).  
  
## Compilando o código  
 Copie o código de exemplo e cole\-o em um projeto do Visual Studio, ou cole\-o em um arquivo chamado `concrt-omp-exceptions.cpp` e execute o comando a seguir em uma janela de prompt de comando do Visual Studio.  
  
 **cl.exe \/EHsc \/openmp concrt\-omp\-exceptions.cpp**  
  
## Consulte também  
 [Migrando de OpenMP no Tempo de Execução de Simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md)   
 [Tratamento de Exceção](../Topic/Exception%20Handling%20in%20the%20Concurrency%20Runtime.md)   
 [Algoritmos paralelos](../Topic/Parallel%20Algorithms.md)