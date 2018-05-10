---
title: 'Como: usar cancelamento para parar um loop paralelo | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- writing a parallel search algorithm [Concurrency Runtime]
- parallel search algorithm, writing [Concurrency Runtime]
ms.assetid: 421cd2de-f058-465f-b890-dd8fcc0df273
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b1b5153c225c3bb3a67be4265cf8303da2121c2b
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="how-to-use-cancellation-to-break-from-a-parallel-loop"></a>Como usar cancelamento para parar um loop paralelo
Este exemplo mostra como usar cancelamento para implementar um algoritmo de pesquisa paralela básica.  
  
## <a name="example"></a>Exemplo  

 O exemplo a seguir usa cancelamento para procurar um elemento em uma matriz. O `parallel_find_any` função usa o [concurrency::parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmo e o [concurrency::run_with_cancellation_token](reference/concurrency-namespace-functions.md#run_with_cancellation_token) função para pesquisar a posição que contém o valor especificado. Quando o loop paralelo localiza o valor, ele chama o [concurrency::cancellation_token_source::cancel](reference/cancellation-token-source-class.md#cancel) método para cancelar o trabalho futuras.  


  
 [!code-cpp[concrt-parallel-array-search#1](../../parallel/concrt/codesnippet/cpp/how-to-use-cancellation-to-break-from-a-parallel-loop_1.cpp)]  
  

 O [concurrency::parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmo funciona ao mesmo tempo. Portanto, ele não executa as operações em uma ordem predeterminada. Se a matriz contém várias instâncias do valor, o resultado pode ser qualquer uma das suas posições.  

  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `parallel-array-search.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc paralelo-matriz-search.cpp**  
  
## <a name="see-also"></a>Consulte também  
 [Cancelamento no PPL](cancellation-in-the-ppl.md)   
 [Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)   
 [Função parallel_for](reference/concurrency-namespace-functions.md#parallel_for)   
 [Classe cancellation_token_source](../../parallel/concrt/reference/cancellation-token-source-class.md)
