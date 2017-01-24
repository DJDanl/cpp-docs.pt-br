---
title: "Como converter um loop OpenMP que usa cancelamento para usar o tempo de execu&#231;&#227;o de simultaneidade | Microsoft Docs"
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
  - "Convertendo de OpenMP no tempo de execução de simultaneidade, cancelamento"
  - "cancelamento, convertendo de OpenMP no tempo de execução de simultaneidade"
ms.assetid: 4b0b3c33-bfa9-4e96-ae08-aef245a39cbb
caps.latest.revision: 11
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como converter um loop OpenMP que usa cancelamento para usar o tempo de execu&#231;&#227;o de simultaneidade
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Alguns loop paralelos não requerem que todas as iterações serão executadas.  Por exemplo, um algoritmo que pesquise por um valor pode terminar depois do valor for encontrado.  OpenMP não fornece um mecanismo para estoirar de um loop paralelo.  Entretanto, você pode usar um valor booliano, ou o sinalizador, para habilitar a iteração do loop para indicar que a solução esteve localizada.  O tempo de execução de simultaneidade fornece a funcionalidade que permite uma tarefa cancelar outras tarefas que ainda não foram iniciados.  
  
 Este exemplo demonstra como converter um loop OpenMP [paralela](../../parallel/openmp/reference/parallel.md)[para](../Topic/for%20\(OpenMP\).md) que não solicite que todas as iterações executa para usar o cancelamento do mecanismo de tempo de execução de simultaneidade.  
  
## Exemplo  
 Este exemplo usa OpenMP e o tempo de execução de simultaneidade para implementar uma versão paralela do algoritmo de [std::any\_of](../Topic/any_of.md) .  A versão OpenMP esse exemplo usa um sinalizador para coordenar entre todas as iterações paralelas loop for que a condição esteve atendida.  A versão que usa o tempo de execução de simultaneidade usa o método de [concurrency::structured\_task\_group::cancel](../Topic/structured_task_group::cancel%20Method.md) para interromper a operação total quando a condição for atendida.  
  
 [!code-cpp[concrt-openmp#2](../../parallel/concrt/codesnippet/CPP/convert-an-openmp-loop-that-uses-cancellation_1.cpp)]  
  
 O exemplo produz a seguinte saída.  
  
  **Usando OpenMP…**  
**9114046 estão na matriz.**  
**Usando o tempo de execução de simultaneidade…**  
**9114046 estão na matriz.** Na versão do usa OpenMP, todas as interações do loop é executado, mesmo quando o sinalizador é definido.  Além disso, se uma tarefa teve ter quaisquer tarefas filhos, o sinalizador também deveriam estar disponível 2 essas tarefas filhos comunicar o cancelamento.  Em tempo de execução da simultaneidade, quando um grupo de trabalho for cancelado, o tempo de execução cancela toda a árvore de trabalho, incluindo tarefas filhos.  As tarefas do usa o algoritmo de [concurrency::parallel\_for\_each](../Topic/parallel_for_each%20Function.md) executar o trabalho.  Em virtude disso, quando uma iteração do loop cancela a tarefa raiz, a árvore inteira de computação é cancelada também.  Quando uma árvore de trabalho for cancelada, o tempo de execução não inicia novas tarefas.  No entanto, o tempo de execução permite que as tarefas que têm iniciado já para concluir.  Em virtude disso, no caso do algoritmo de `parallel_for_each` , as iterações ativos de loop podem limpar seus recursos.  
  
 Em ambas as versões desse exemplo, se a matriz contém mais de uma cópia de valor para pesquisar por, várias interações do loop abrange cada um definem simultaneamente o resultado e cancelar a operação total.  Você pode usar um primitivo de sincronização, como uma seção crítica, se seu problema que requer apenas uma tarefa executa o trabalho quando uma condição for atendida.  
  
 Você também pode usar a manipulação de exceção para cancelar as tarefas que usam o PPL.  Para obter mais informações sobre cancelamento, consulte [Cancelamento](../../parallel/concrt/cancellation-in-the-ppl.md).  
  
 Para obter mais informações sobre como `parallel_for_each` e outros algoritmos paralelos, consulte [Algoritmos paralelos](../Topic/Parallel%20Algorithms.md).  
  
## Compilando o código  
 Copie o código de exemplo e cole\-o em um projeto do Visual Studio, ou cole\-o em um arquivo chamado `concrt-omp-parallel-any-of.cpp` e execute o comando a seguir em uma janela de prompt de comando do Visual Studio.  
  
 **cl.exe \/EHsc \/openmp concrt\-omp\-parallel\-any\-of.cpp**  
  
## Consulte também  
 [Migrando de OpenMP no Tempo de Execução de Simultaneidade](../../parallel/concrt/migrating-from-openmp-to-the-concurrency-runtime.md)   
 [Cancelamento](../../parallel/concrt/cancellation-in-the-ppl.md)   
 [Algoritmos paralelos](../Topic/Parallel%20Algorithms.md)