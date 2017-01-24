---
title: "Instru&#231;&#245;es passo a passo: implementando futuros | Microsoft Docs"
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
  - "implementando futuros [Tempo de Execução de Simultaneidade]"
  - "futuros, Implementando [tempo de execução de simultaneidade]"
ms.assetid: 82ea75cc-aaec-4452-b10d-8abce0a87e5b
caps.latest.revision: 25
caps.handback.revision: 25
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: implementando futuros
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico mostra como implementar futuros em seu aplicativo. O tópico demonstra como combinar a funcionalidade existente em tempo de execução de simultaneidade em algo que faz mais.  
  
> [!IMPORTANT]
>  Este tópico ilustra o conceito de futuros para fins de demonstração. É recomendável que você use [std::future](../../standard-library/future-class.md) ou [Concurrency:: Task](../../parallel/concrt/reference/task-class-concurrency-runtime.md) quando você precisa de uma tarefa assíncrona que calcula um valor para uso posterior.  
  
 Um *tarefa* uma computação pode ser decomposto em adicionais, mais refinados, cálculos. Um *futuros* é uma tarefa assíncrona que calcula um valor para uso posterior.  
  
 Para implementar futuros, este tópico define o `async_future` classe. O `async_future` classe usa esses componentes de tempo de execução de simultaneidade: o [concurrency::task_group](../Topic/task_group%20Class.md) classe e o [concurrency::single_assignment](../../parallel/concrt/reference/single-assignment-class.md) classe. O `async_future` classe usa o `task_group` classe para calcular um valor de forma assíncrona e a `single_assignment` classe para armazenar o resultado do cálculo. O construtor do `async_future` classe usa uma função de trabalho que calcula o resultado e o `get` método recupera o resultado.  
  
### <a name="to-implement-the-asyncfuture-class"></a>Para implementar a classe async_future  
  
1.  Declare uma classe de modelo chamada `async_future` que é parametrizado no tipo de cálculo resultante. Adicionar `public` e `private` seções para essa classe.  
  
 [!code-cpp[concrt-futures#2](../../parallel/concrt/codesnippet/CPP/walkthrough-implementing-futures_1.cpp)]  
  
2.  No `private` seção o `async_future` da classe, declare um `task_group` e um `single_assignment` membro de dados.  
  
 [!code-cpp[concrt-futures#3](../../parallel/concrt/codesnippet/CPP/walkthrough-implementing-futures_2.cpp)]  
  
3.  No `public` seção o `async_future` da classe, implemente o construtor. O construtor é um modelo com parâmetros na função de trabalho que calcula o resultado. O construtor de forma assíncrona executa a função de trabalho no `task_group` membro de dados e usa o [concurrency::send](../Topic/send%20Function.md) função para gravar o resultado para o `single_assignment` membro de dados.  
  
 [!code-cpp[concrt-futures#4](../../parallel/concrt/codesnippet/CPP/walkthrough-implementing-futures_3.cpp)]  
  
4.  No `public` seção o `async_future` da classe, implemente o destruidor. O destruidor aguarda a tarefa seja concluída.  
  
 [!code-cpp[concrt-futures#5](../../parallel/concrt/codesnippet/CPP/walkthrough-implementing-futures_4.cpp)]  
  
5.  No `public` seção o `async_future` da classe, implemente o `get` método. Esse método usa o [concurrency::receive](../Topic/receive%20Function.md) função para recuperar o resultado da função de trabalho.  
  
 [!code-cpp[concrt-futures#6](../../parallel/concrt/codesnippet/CPP/walkthrough-implementing-futures_5.cpp)]  
  
## <a name="example"></a>Exemplo  
  
### <a name="description"></a>Descrição  
 O exemplo a seguir mostra a conclusão `async_future` classe e um exemplo de seu uso. O `wmain` função cria um std::[vetor](../../standard-library/vector-class.md) objeto que contém valores de número aleatório de 10.000. Ele usa `async_future` objetos para localizar os valores menores e maiores que estão contidos no `vector` objeto.  
  
### <a name="code"></a>Código  
 [!code-cpp[concrt-futures#1](../../parallel/concrt/codesnippet/CPP/walkthrough-implementing-futures_6.cpp)]  
  
### <a name="comments"></a>Comentários  
 Este exemplo produz a seguinte saída:  
  
```Output  
smallest: 0  
largest:  9999  
average:  4981  
```  
  
 O exemplo usa o `async_future::get` método para recuperar os resultados do cálculo. O `async_future::get` método aguarda o cálculo concluir se a computação ainda está ativa.  
  
## <a name="robust-programming"></a>Programação robusta  
 Para estender o `async_future` classe para tratar exceções que são geradas pela função de trabalho, modifique o `async_future::get` método para chamar o [concurrency::task_group::wait](../Topic/task_group::wait%20Method.md) método. O `task_group::wait` método emite as exceções geradas pela função de trabalho.  
  
 O exemplo a seguir mostra a versão modificada do `async_future` classe. O `wmain` função usa um `try`-`catch` bloco para imprimir o resultado do `async_future` objeto ou para imprimir o valor da exceção que é gerado pela função de trabalho.  
  
 [!code-cpp[concrt-futures-with-eh#1](../../parallel/concrt/codesnippet/CPP/walkthrough-implementing-futures_7.cpp)]  
  
 Este exemplo produz a seguinte saída:  
  
```Output  
caught exception: error  
```  
  
 Para obter mais informações sobre o modelo de manipulação de exceção em tempo de execução de simultaneidade, consulte [Exception Handling](../Topic/Exception%20Handling%20in%20the%20Concurrency%20Runtime.md).  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `futures.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc futures.cpp**  
  
## <a name="see-also"></a>Consulte também  
 [Explicações passo a passo de tempo de execução de simultaneidade](../Topic/Concurrency%20Runtime%20Walkthroughs.md)   
 [Tratamento de exceção](../Topic/Exception%20Handling%20in%20the%20Concurrency%20Runtime.md)   
 [Classe task_group](../Topic/task_group%20Class.md)   
 [Classe single_assignment](../../parallel/concrt/reference/single-assignment-class.md)
