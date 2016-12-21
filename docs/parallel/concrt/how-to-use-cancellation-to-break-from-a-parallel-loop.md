---
title: "Como usar cancelamento para parar um loop paralelo | Microsoft Docs"
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
  - "algoritmo de pesquisa paralela, gravando [Tempo de Execução de Simultaneidade]"
  - "gravando um algoritmo de pesquisa paralela [Tempo de Execução de Simultaneidade]"
ms.assetid: 421cd2de-f058-465f-b890-dd8fcc0df273
caps.latest.revision: 19
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como usar cancelamento para parar um loop paralelo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este exemplo mostra como usar o cancelar para implementar um algoritmo de pesquisa paralela básico.  
  
## Exemplo  
 O exemplo a seguir usa em cancelar para pesquisar por um elemento em uma matriz.  A função de `parallel_find_any` usa o algoritmo de [concurrency::parallel\_for](../Topic/parallel_for%20Function.md) e a função de [concurrency::run\_with\_cancellation\_token](../Topic/run_with_cancellation_token%20Function.md) para pesquisar pela posição que contém o valor fornecido.  Quando o loop paralelo localiza o valor, ele chama o método de [concurrency::cancellation\_token\_source::cancel](../Topic/cancellation_token_source::cancel%20Method.md) para cancelar o trabalho futuro.  
  
 [!code-cpp[concrt-parallel-array-search#1](../../parallel/concrt/codesnippet/CPP/how-to-use-cancellation-to-break-from-a-parallel-loop_1.cpp)]  
  
 O algoritmo de [concurrency::parallel\_for](../Topic/parallel_for%20Function.md) atua simultaneamente.  Consequentemente, não executa operações em uma ordem índice.  Se a matriz contém várias instâncias do valor, o resultado pode ser de qualquer uma de suas posições.  
  
## Compilando o código  
 Copie o código de exemplo e cole\-o em um projeto do Visual Studio, ou cole\-o em um arquivo chamado `parallel-array-search.cpp` e execute o comando a seguir em uma janela de prompt de comando do Visual Studio.  
  
 **cl.exe \/EHsc parallel\-array\-search.cpp**  
  
## Consulte também  
 [Cancelamento](../../parallel/concrt/cancellation-in-the-ppl.md)   
 [Algoritmos paralelos](../Topic/Parallel%20Algorithms.md)   
 [Função parallel\_for](../Topic/parallel_for%20Function.md)   
 [Classe cancellation\_token\_source](../../parallel/concrt/reference/cancellation-token-source-class.md)