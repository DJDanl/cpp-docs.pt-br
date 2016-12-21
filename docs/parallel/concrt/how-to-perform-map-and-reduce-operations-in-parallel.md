---
title: "Como realizar opera&#231;&#245;es de mapa e redu&#231;&#227;o em paralelo | Microsoft Docs"
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
  - "função parallel_transform, por exemplo:"
  - "mapa e reduzir paralelo, exemplo"
  - "função parallel_reduce, por exemplo:"
ms.assetid: 9d19fac0-4ab6-4380-a375-3b18eeb87720
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como realizar opera&#231;&#245;es de mapa e redu&#231;&#227;o em paralelo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este exemplo mostra como usar o [concurrency::parallel_transform](../Topic/parallel_transform%20Function.md) e [concurrency::parallel_reduce](../Topic/parallel_reduce%20Function.md) algoritmos e [concurrency::concurrent_unordered_map](../../parallel/concrt/reference/concurrent-unordered-map-class.md) classe para contar as ocorrências de palavras nos arquivos.  
  
 Um *mapa* operação se aplica a uma função para cada valor em uma sequência. Um *reduzir* operação combina os elementos de uma sequência em um valor. Você pode usar o modelo Biblioteca STL (Standard) [std::transform](../Topic/transform.md)[std::accumulate](../Topic/accumulate.md) classes para executar o mapa e reduzir as operações. No entanto, para melhorar o desempenho de vários problemas, você pode usar o `parallel_transform` algoritmo para realizar a operação de mapa em paralelo e o `parallel_reduce` algoritmo para realizar a operação de redução em paralelo. Em alguns casos, você pode usar `concurrent_unordered_map` para executar o mapa e redução em uma única operação.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir conta as ocorrências de palavras nos arquivos. Ele usa [std:: Vector](../../standard-library/vector-class.md) para representar o conteúdo de dois arquivos. A operação de mapa calcula as ocorrências de cada palavra em cada vetor. A operação de redução acumula as contagens de palavras em ambos os vetores.  
  
 [!code-cpp[concrt-parallel-map-reduce#1](../../parallel/concrt/codesnippet/CPP/how-to-perform-map-and-reduce-operations-in-parallel_1.cpp)]  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Para compilar o código, copiá-lo e colá-lo em um projeto do Visual Studio ou colá-lo em um arquivo chamado `parallel-map-reduce.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc paralelo-map-reduce.cpp**  
  
## <a name="robust-programming"></a>Programação robusta  
 Neste exemplo, você pode usar o `concurrent_unordered_map` classe — que é definido em concurrent_unordered_map.h—to executar o mapa e reduzir em uma única operação.  
  
 [!code-cpp[concrt-parallel-map-reduce#2](../../parallel/concrt/codesnippet/CPP/how-to-perform-map-and-reduce-operations-in-parallel_2.cpp)]  
  
 Normalmente, você paralelizar apenas externo ou o loop interno. Se você tiver poucas arquivos e cada arquivo contém várias palavras, paralelizar o loop interno. Se você tiver muitos relativamente arquivos e cada arquivo contém algumas palavras, paralelizar o loop externo.  
  
## <a name="see-also"></a>Consulte também  
 [Algoritmos paralelos](../Topic/Parallel%20Algorithms.md)   
 [Função parallel_transform](../Topic/parallel_transform%20Function.md)   
 [Função parallel_reduce](../Topic/parallel_reduce%20Function.md)   
 [Classe concurrent_unordered_map](../../parallel/concrt/reference/concurrent-unordered-map-class.md)
