---
title: "Como: usar Combinável para combinar conjuntos | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- combinable class, example
- combining sets with combinable [Concurrency Runtime]
ms.assetid: 66ffe8e3-6bbb-4e9f-b790-b612922a68a7
caps.latest.revision: "14"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8bbd36e9536707bc639e8f80cc019b7fda18f793
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-use-combinable-to-combine-sets"></a>Como usar combinável para combinar conjuntos
Este tópico mostra como usar o [concurrency::combinable](../../parallel/concrt/reference/combinable-class.md) classe para calcular o conjunto de números primos.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir calcula o conjunto de números primos duas vezes. Cada cálculo armazena o resultado em uma [std::bitset](../../standard-library/bitset-class.md) objeto. O exemplo primeiro calcula o conjunto em série e, em seguida, calcula o conjunto em paralelo. O exemplo também imprime no console o tempo necessário para executar ambos os cálculos.  
  
 Este exemplo usa o [concurrency::parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmo e uma `combinable` objeto para gerar conjuntos de local de thread. Ele usa o [concurrency::combinable::combine_each](reference/combinable-class.md#combine_each) método para combinar os conjuntos de local de thread para o conjunto final.  

  
 [!code-cpp[concrt-parallel-combine-primes#1](../../parallel/concrt/codesnippet/cpp/how-to-use-combinable-to-combine-sets_1.cpp)]  
  
 A seguinte saída de exemplo é para um computador com quatro processadores.  
  
```Output  
serial time: 312 ms  
 
parallel time: 78 ms  
```  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `parallel-combine-primes.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc paralelo-combinar-primes.cpp**  
  
## <a name="see-also"></a>Consulte também  
 [Objetos e contêineres paralelos](../../parallel/concrt/parallel-containers-and-objects.md)   
 [Classe combinable](../../parallel/concrt/reference/combinable-class.md)   
 [combinable:: método combine_each](reference/combinable-class.md#combine_each)


