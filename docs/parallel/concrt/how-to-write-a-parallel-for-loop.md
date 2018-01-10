---
title: 'Como: gravar um Loop parallel_for | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- writing a parallel_for loop [Concurrency Runtime]
- parallel_for function, example
ms.assetid: adb4d64e-5514-4b70-8dcb-b9210e6b5a1c
caps.latest.revision: "15"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 60ae6b7f496f86bde91801e486315587fb693436
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-write-a-parallelfor-loop"></a>Como gravar um loop parallel_for
Este exemplo demonstra como usar [concurrency::parallel_for](reference/concurrency-namespace-functions.md#parallel_for) para calcular o produto de duas matrizes.  
  
## <a name="example"></a>Exemplo  
 A exemplo a seguir mostra o `matrix_multiply` função, que calcula o produto de duas matrizes.  
  
 [!code-cpp[concrt-parallel-matrix-multiply#1](../../parallel/concrt/codesnippet/cpp/how-to-write-a-parallel-for-loop_1.cpp)]  
  
## <a name="example"></a>Exemplo  
 A exemplo a seguir mostra o `parallel_matrix_multiply` função, que usa o `parallel_for` algoritmo para realizar o loop externo em paralelo.  
  
 [!code-cpp[concrt-parallel-matrix-multiply#2](../../parallel/concrt/codesnippet/cpp/how-to-write-a-parallel-for-loop_2.cpp)]  
  
 Este exemplo parallelizes o loop externo apenas porque ele executa trabalho suficiente para se beneficiar com a sobrecarga de processamento paralelo. Se você paralelizar o loop interno, você não receberá um ganho de desempenho porque a pequena quantidade de trabalho que executa o loop interno não superar a sobrecarga de processamento paralelo. Portanto, a paralelização do loop externo é apenas a melhor forma de maximizar os benefícios de simultaneidade na maioria dos sistemas.  
  
## <a name="example"></a>Exemplo  
 O seguinte exemplo mais completo compara o desempenho do `matrix_multiply` função o `parallel_matrix_multiply` função.  
  
 [!code-cpp[concrt-parallel-matrix-multiply#3](../../parallel/concrt/codesnippet/cpp/how-to-write-a-parallel-for-loop_3.cpp)]  
  
 A seguinte saída de exemplo é para um computador com quatro processadores.  
  
```Output  
serial: 3853  
parallel: 1311  
```  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Para compilar o código, copiá-lo e, em seguida, cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `parallel-matrix-multiply.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc paralelo-matriz-multiply.cpp**  
  
## <a name="see-also"></a>Consulte também  
 [Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)   
 [Função parallel_for](reference/concurrency-namespace-functions.md#parallel_for)


