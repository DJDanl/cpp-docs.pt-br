---
title: 'Passo a passo: Implementando futuros | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- implementing futures [Concurrency Runtime]
- futures, implementing [Concurrency Runtime]
ms.assetid: 82ea75cc-aaec-4452-b10d-8abce0a87e5b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 12f2bd5897945dec0045019462c2faeb665a19e4
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="walkthrough-implementing-futures"></a>Instruções passo a passo: implementando futuros
Este tópico mostra como implementar futuros em seu aplicativo. O tópico demonstra como combinar a funcionalidade existente no tempo de execução de simultaneidade em algo que faz mais.  
  
> [!IMPORTANT]
>  Este tópico ilustra o conceito de futuros para fins de demonstração. Recomendamos que você use [std::future](../../standard-library/future-class.md) ou [Concurrency:: Task](../../parallel/concrt/reference/task-class.md) quando você precisa de uma tarefa assíncrona que calcula um valor para uso posterior.  
  
 Um *tarefa* é um cálculo que pode ser decomposto em cálculos adicionais e mais refinados,. Um *futuros* é uma tarefa assíncrona que calcula um valor para uso posterior.  
  
 Para implementar futuros, este tópico define o `async_future` classe. O `async_future` classe usa esses componentes de tempo de execução de simultaneidade: o [concurrency::task_group](reference/task-group-class.md) classe e o [concurrency::single_assignment](../../parallel/concrt/reference/single-assignment-class.md) classe. O `async_future` classe usa a `task_group` classe para calcular um valor de forma assíncrona e o `single_assignment` classe para armazenar o resultado da computação. O construtor do `async_future` classe usa uma função de trabalho que calcula o resultado e o `get` método recupera o resultado.  
  
### <a name="to-implement-the-asyncfuture-class"></a>Para implementar a classe async_future  
  
1.  Declarar uma classe de modelo chamada `async_future` que parâmetros é definido no tipo de computação resultante. Adicionar `public` e `private` seções para essa classe.  
  
 [!code-cpp[concrt-futures#2](../../parallel/concrt/codesnippet/cpp/walkthrough-implementing-futures_1.cpp)]  
  
2.  No `private` seção o `async_future` classe, declare um `task_group` e um `single_assignment` membro de dados.  
  
 [!code-cpp[concrt-futures#3](../../parallel/concrt/codesnippet/cpp/walkthrough-implementing-futures_2.cpp)]  
  

3.  No `public` seção o `async_future` classe, implemente o construtor. O construtor é um modelo com parâmetros na função de trabalho que calcula o resultado. O construtor executa de forma assíncrona a função de trabalho no `task_group` membro de dados e usa o [concurrency::send](reference/concurrency-namespace-functions.md#send) função para gravar o resultado para o `single_assignment` membro de dados.  
  
 [!code-cpp[concrt-futures#4](../../parallel/concrt/codesnippet/cpp/walkthrough-implementing-futures_3.cpp)]  
  
4.  No `public` seção o `async_future` classe, implemente o destruidor. O destruidor aguarda a tarefa seja concluída.  
  
 [!code-cpp[concrt-futures#5](../../parallel/concrt/codesnippet/cpp/walkthrough-implementing-futures_4.cpp)]  
  

5.  No `public` seção o `async_future` classe, implemente o `get` método. Esse método usa o [concurrency::receive](reference/concurrency-namespace-functions.md#receive) função para recuperar o resultado da função de trabalho.  

  
 [!code-cpp[concrt-futures#6](../../parallel/concrt/codesnippet/cpp/walkthrough-implementing-futures_5.cpp)]  
  
## <a name="example"></a>Exemplo  
  
### <a name="description"></a>Descrição  
 O exemplo a seguir mostra o completo `async_future` classe e um exemplo de seu uso. O `wmain` função cria um std::[vetor](../../standard-library/vector-class.md) objeto que contém valores de número aleatório 10.000. Ele então usa `async_future` objetos a localizar os valores menores e maiores que estão contidos no `vector` objeto.  
  
### <a name="code"></a>Código  
 [!code-cpp[concrt-futures#1](../../parallel/concrt/codesnippet/cpp/walkthrough-implementing-futures_6.cpp)]  
  
### <a name="comments"></a>Comentários  
 Este exemplo gera a seguinte saída:  
  
```Output  
smallest: 0  
largest:  9999  
average:  4981  
```  
  
 O exemplo usa o `async_future::get` método para recuperar os resultados da computação. O `async_future::get` método aguarda a computação concluir se a computação ainda está ativa.  
  
## <a name="robust-programming"></a>Programação robusta  


 Para estender o `async_future` classe para manipular exceções lançadas pela função de trabalho, modifique o `async_future::get` método para chamar o [concurrency::task_group::wait](reference/task-group-class.md#wait) método. O `task_group::wait` método emite as exceções geradas pela função de trabalho.  


  
 O exemplo a seguir mostra a versão modificada do `async_future` classe. O `wmain` função usa um `try` - `catch` bloco para imprimir o resultado da `async_future` objeto ou para imprimir o valor da exceção que é gerado pela função de trabalho.  
  
 [!code-cpp[concrt-futures-with-eh#1](../../parallel/concrt/codesnippet/cpp/walkthrough-implementing-futures_7.cpp)]  
  
 Este exemplo gera a seguinte saída:  
  
```Output  
caught exception: error  
```  
  
 Para obter mais informações sobre o modelo de tratamento de exceção no tempo de execução de simultaneidade, consulte [tratamento de exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `futures.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc futures.cpp**  
  
## <a name="see-also"></a>Consulte também  
 [Explicações passo a passo de tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)   
 [Tratamento de exceções](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md)   
 [Classe task_group](reference/task-group-class.md)   
 [Classe single_assignment](../../parallel/concrt/reference/single-assignment-class.md)
