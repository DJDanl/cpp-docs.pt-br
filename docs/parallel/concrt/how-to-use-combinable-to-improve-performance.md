---
title: "Como: usar Combinável para melhorar o desempenho | Microsoft Docs"
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
- combinable class, example
- improving parallel performance with combinable [Concurrency Runtime]
ms.assetid: fa730580-1c94-4b2d-8aec-57c91dc0497e
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: dea28bd31812449e34bb481d316070f8f21aaede
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-use-combinable-to-improve-performance"></a>Como usar combinável para melhorar o desempenho
Este exemplo mostra como usar o [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) classe para calcular a soma dos números em uma [std:: array](../../standard-library/array-class-stl.md) objeto são primos. O `combinable` classe melhora o desempenho, eliminando o estado compartilhado.  
  
> [!TIP]
>  Em alguns casos, paralelo de mapa ([concurrency::parallel_transform](reference/concurrency-namespace-functions.md#parallel_transform)) e reduzir ([concurrency:: parallel_reduce](reference/concurrency-namespace-functions.md#parallel_reduce)) pode oferecer melhorias de desempenho ao longo `combinable`. Para obter um exemplo que usa mapear e reduzir as operações para produzir os mesmos resultados que neste exemplo, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir usa o [std::accumulate](../../standard-library/numeric-functions.md#accumulate) função para calcular a soma dos elementos em uma matriz que são o principal. Neste exemplo, `a` é um `array` objeto e o `is_prime` função determina se o valor de entrada é primos.  
  
 [!code-cpp[concrt-parallel-sum-of-primes#1](../../parallel/concrt/codesnippet/cpp/how-to-use-combinable-to-improve-performance_1.cpp)]  
  
## <a name="example"></a>Exemplo  

 O exemplo a seguir mostra uma maneira simples para efetuar a paralelização do exemplo anterior. Este exemplo usa o [Concurrency:: parallel_for_each](reference/concurrency-namespace-functions.md#parallel_for_each) algoritmo para processar a matriz em paralelo e um [concurrency::critical_section](../../parallel/concrt/reference/critical-section-class.md) objeto para sincronizar o acesso a `prime_sum` variável . Este exemplo não são dimensionadas porque cada thread deve esperar para o recurso compartilhado se torne disponível.  
  
 [!code-cpp[concrt-parallel-sum-of-primes#2](../../parallel/concrt/codesnippet/cpp/how-to-use-combinable-to-improve-performance_2.cpp)]  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir usa uma `combinable` objeto para melhorar o desempenho do exemplo anterior. Este exemplo elimina a necessidade para objetos de sincronização. ele pode ser expandido porque o `combinable` objeto permite que cada thread realizar sua tarefa de forma independente.  
  
 Um `combinable` objeto é usado normalmente em duas etapas. Primeiro, gerar uma série de cálculos refinadas executando o trabalho em paralelo. Em seguida, combinar ou reduzir os cálculos em um resultado final. Este exemplo usa o [concurrency::combinable::local](reference/combinable-class.md#local) método para obter uma referência à soma local. Ele usa o [concurrency::combinable::combine](reference/combinable-class.md#combine) método e uma [std::plus](../../standard-library/plus-struct.md) objeto para combinar os cálculos de locais para o resultado final.  

  
 [!code-cpp[concrt-parallel-sum-of-primes#3](../../parallel/concrt/codesnippet/cpp/how-to-use-combinable-to-improve-performance_3.cpp)]  
  
## <a name="example"></a>Exemplo  
 O exemplo completo a seguir calcula a soma de números primos para ambos os em série e em paralelo. O exemplo imprime no console o tempo necessário para executar ambos os cálculos.  
  
 [!code-cpp[concrt-parallel-sum-of-primes#4](../../parallel/concrt/codesnippet/cpp/how-to-use-combinable-to-improve-performance_4.cpp)]  
  
 A seguinte saída de exemplo é para um computador com quatro processadores.  
  
```Output  
1709600813  
serial time: 6178 ms  
 
1709600813  
parallel time: 1638 ms  
```  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Para compilar o código, copiá-lo e, em seguida, cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `parallel-sum-of-primes.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc paralelo-soma-de-primes.cpp**  
  
## <a name="robust-programming"></a>Programação robusta  
 Para obter um exemplo que usa mapear e reduzir as operações para produzir os mesmos resultados, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).  
  
## <a name="see-also"></a>Consulte também  
 [Objetos e contêineres paralelos](../../parallel/concrt/parallel-containers-and-objects.md)   
 [Classe combinable](../../parallel/concrt/reference/combinable-class.md)   
 [Classe critical_section](../../parallel/concrt/reference/critical-section-class.md)
