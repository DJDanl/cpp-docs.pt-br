---
title: "Como usar parallel_invoke para escrever uma rotina de classifica&#231;&#227;o em paralelo | Microsoft Docs"
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
  - "classe task_handle, por exemplo:"
  - "classe task_group, por exemplo:"
  - "função make_task, por exemplo:"
  - "classe structured_task_group, por exemplo:"
  - "melhorando o desempenho paralelo com grupos de tarefas [Tempo de Execução de Simultaneidade]"
ms.assetid: 53979a2a-525d-4437-8952-f1ff85b37673
caps.latest.revision: 23
caps.handback.revision: 20
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como usar parallel_invoke para escrever uma rotina de classifica&#231;&#227;o em paralelo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este documento descreve como usar o algoritmo de [parallel\_invoke](../Topic/parallel_invoke%20Function.md) para melhorar o desempenho do algoritmo de tipo bitonic.  O algoritmo de tipo bitonic divide recursivamente a sequência de entrada em partições menores classificados.  O algoritmo de tipo bitonic pode ser executados em paralelo porque cada operação de partição é independente de todas as outras operações.  
  
 Embora o tipo bitonic é um exemplo *de uma rede de classificação* que classifica todas as combinações de sequências de entrada, as sequências de tipos desse exemplo com comprimento é uma potência de dois.  
  
> [!NOTE]
>  Este exemplo usa uma rotina o tipo parallel para ilustração.  Você também pode usar algoritmos de classificação internas que o fornece PPL: [concurrency::parallel\_sort](../Topic/parallel_sort%20Function.md), [concurrency::parallel\_buffered\_sort](../Topic/parallel_buffered_sort%20Function.md), e [concurrency::parallel\_radixsort](../Topic/parallel_radixsort%20Function.md).  Para obter mais informações, consulte [Algoritmos paralelos](../Topic/Parallel%20Algorithms.md).  
  
##  <a name="top"></a> Seções  
 Este documento descreve as seguintes tarefas:  
  
-   [Realizando Classificação Bitonic em Série](#serial)  
  
-   [Usando parallel\_invoke para Realizar Classificação Bitonic em Paralelo](#parallel)  
  
##  <a name="serial"></a> Realizando Classificação Bitonic em Série  
 O exemplo a seguir mostra a versão serial do algoritmo de tipo bitonic.  A função de `bitonic_sort` divide a sequência em duas partições, classifica essas partições em direções opostas, e então mescla os resultados.  Este chamadas de função próprias duas vezes classificar recursivamente cada partição.  
  
 [!CODE [concrt-parallel-bitonic-sort#1](../CodeSnippet/VS_Snippets_ConcRT/concrt-parallel-bitonic-sort#1)]  
  
 \[[Superior](#top)\]  
  
##  <a name="parallel"></a> Usando parallel\_invoke para Realizar Classificação Bitonic em Paralelo  
 Esta seção descreve como usar o algoritmo de `parallel_invoke` para ser executados em paralelo o algoritmo de tipo bitonic.  
  
### Procedimentos  
  
##### Para realizar o algoritmo de classificação bitonic em paralelo  
  
1.  Adicionar uma política de `#include` para o arquivo de cabeçalho ppl.h.  
  
     [!CODE [concrt-parallel-bitonic-sort#10](../CodeSnippet/VS_Snippets_ConcRT/concrt-parallel-bitonic-sort#10)]  
  
2.  Adicionar uma política de `using` para o namespace de `concurrency` .  
  
     [!CODE [concrt-parallel-bitonic-sort#11](../CodeSnippet/VS_Snippets_ConcRT/concrt-parallel-bitonic-sort#11)]  
  
3.  Crie uma nova função, `parallel_bitonic_mege`chamado, que usa o algoritmo de `parallel_invoke` para mesclar em paralelo as sequências se houver uma quantidade suficiente de trabalho para executar.  Se não, chame `bitonic_merge` para mesclar as sequências em série.  
  
     [!CODE [concrt-parallel-bitonic-sort#2](../CodeSnippet/VS_Snippets_ConcRT/concrt-parallel-bitonic-sort#2)]  
  
4.  Executar um processo semelhante ao da etapa anterior, mas para a função de `bitonic_sort` .  
  
     [!CODE [concrt-parallel-bitonic-sort#3](../CodeSnippet/VS_Snippets_ConcRT/concrt-parallel-bitonic-sort#3)]  
  
5.  Crie uma versão sobrecarregada da função de `parallel_bitonic_sort` que classifica a matriz em ordem crescente.  
  
     [!CODE [concrt-parallel-bitonic-sort#4](../CodeSnippet/VS_Snippets_ConcRT/concrt-parallel-bitonic-sort#4)]  
  
 O algoritmo de `parallel_invoke` reduz a sobrecarga executando o último da série de tarefas no contexto de chamada.  Por exemplo, na função de `parallel_bitonic_sort` , a primeira tarefa é executada em um contexto separado, e a segunda tarefa é executado no contexto de chamada.  
  
 [!CODE [concrt-parallel-bitonic-sort#5](../CodeSnippet/VS_Snippets_ConcRT/concrt-parallel-bitonic-sort#5)]  
  
 O exemplo completo executa as versões e seriais paralelas do algoritmo de tipo bitonic.  O exemplo também imprime ao console o tempo necessário para executar cada cálculo.  
  
 [!CODE [concrt-parallel-bitonic-sort#8](../CodeSnippet/VS_Snippets_ConcRT/concrt-parallel-bitonic-sort#8)]  
  
 A seguinte saída de exemplo é para um computador que tem quatro processadores.  
  
  **tempo seriais: 4353**  
**tempo paralelos: 1248** \[[Superior](#top)\]  
  
## Compilando o código  
 Para compilar o código, copie\-a e cole\-o em um projeto do Visual Studio, ou cole\-o em um arquivo chamado `parallel-bitonic-sort.cpp` e execute o comando a seguir em uma janela de prompt de comando do Visual Studio.  
  
 **cl.exe \/EHsc parallel\-bitonic\-sort.cpp**  
  
## Programação robusta  
 Este exemplo usa o algoritmo de `parallel_invoke` em vez da classe de [concurrency::task\_group](../Topic/task_group%20Class.md) porque o tempo de vida de cada grupo de trabalho não exceda de uma função.  Recomendamos que você use `parallel_invoke` quando é possível porque tem menos sobrecarga de execução que objetos de `task group` , e em virtude disso permite escrever um código mais de desempenho.  
  
 As versões paralelas de alguns algoritmos executam melhor apenas quando há um trabalho suficiente para executar.  Por exemplo, as chamadas de função de `parallel_bitonic_merge` a versão de série, `bitonic_merge`, se houver 500 ou menos elementos na sequência.  Você também pode planejar sua estratégia geral de classificação com base na quantidade de trabalho.  Por exemplo, pode ser mais eficiente usar a versão serial do algoritmo de tipo rápido quando a matriz tiver menos de 500 itens, como mostrado no seguinte exemplo:  
  
 [!CODE [concrt-parallel-bitonic-sort#9](../CodeSnippet/VS_Snippets_ConcRT/concrt-parallel-bitonic-sort#9)]  
  
 Como com qualquer algoritmo paralelo, recomendamos que você analisa e ajustamos seu código conforme apropriado.  
  
## Consulte também  
 [Paralelismo da tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md)   
 [Função parallel\_invoke](../Topic/parallel_invoke%20Function.md)