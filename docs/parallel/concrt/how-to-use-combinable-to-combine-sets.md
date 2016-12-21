---
title: "Como usar combin&#225;vel para combinar conjuntos | Microsoft Docs"
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
  - "classe podem ser combinada, por exemplo:"
  - "combinando conjuntos com combinable [Tempo de Execução de Simultaneidade]"
ms.assetid: 66ffe8e3-6bbb-4e9f-b790-b612922a68a7
caps.latest.revision: 14
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como usar combin&#225;vel para combinar conjuntos
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico mostra como usar a classe de [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) para computar o conjunto de números à esquerda.  
  
## Exemplo  
 O exemplo a seguir calcula o conjunto de números principais duas vezes em.  Cada cálculo armazena o resultado em um objeto de [std::bitset](../Topic/bitset%20Class.md) .  O exemplo a seguir calcula o primeiro conjunto em série e computa o conjunto em paralelo.  O exemplo também imprime ao console o tempo necessário para executar computações ambas.  
  
 Este exemplo usa o algoritmo de [concurrency::parallel\_for](../Topic/parallel_for%20Function.md) e um objeto de `combinable` para gerar conjuntos de thread local.  Usa o método de [concurrency::combinable::combine\_each](../Topic/combinable::combine_each%20Method.md) para combinar os conjuntos de thread local no conjunto final.  
  
 [!code-cpp[concrt-parallel-combine-primes#1](../../parallel/concrt/codesnippet/CPP/how-to-use-combinable-to-combine-sets_1.cpp)]  
  
 A seguinte saída de exemplo é para um computador que tem quatro processadores.  
  
  **tempo seriais: 312 ms**  
**tempo paralelos: 78 ms**   
## Compilando o código  
 Copie o código de exemplo e cole\-o em um projeto do Visual Studio, ou cole\-o em um arquivo chamado `parallel-combine-primes.cpp` e execute o comando a seguir em uma janela de prompt de comando do Visual Studio.  
  
 **cl.exe \/EHsc parallel\-combine\-primes.cpp**  
  
## Consulte também  
 [Contêineres e objetos em paralelo](../../parallel/concrt/parallel-containers-and-objects.md)   
 [Classe combinable](../../parallel/concrt/reference/combinable-class.md)   
 [Método combinable::combine\_each](../Topic/combinable::combine_each%20Method.md)