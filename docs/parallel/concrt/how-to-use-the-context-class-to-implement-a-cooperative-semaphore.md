---
title: "Como: usar a classe de contexto para implementar um semáforo cooperativo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- cooperative semaphore implementing
- context class
ms.assetid: 22f4b9c0-ca22-4a68-90ba-39e99ea76696
caps.latest.revision: "18"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 03884d69877053976fdaf04e507c4c1c4214026e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-use-the-context-class-to-implement-a-cooperative-semaphore"></a>Como usar a classe de contexto para implementar um semáforo cooperativo
Este tópico mostra como usar a classe concurrency::Context para implementar uma classe de sinal cooperativo.  
  
 O `Context` classe permite que você bloqueie ou gera o contexto de execução atual. Bloquear ou gerando o contexto atual é útil quando o contexto atual não pode continuar porque um recurso não está disponível. Um *semáforo* é um exemplo de uma situação em que o contexto de execução atual deve aguardar um recurso se torne disponível. Um sinal, como um objeto de seção crítica, é um objeto de sincronização que permite que o código em um contexto para ter acesso exclusivo a um recurso. No entanto, ao contrário de um objeto de seção crítica, um semáforo permite que mais de um contexto acessar o recurso simultaneamente. Se o número máximo de contextos mantém um bloqueio de semáforo, cada contexto adicional deve aguardar outro contexto liberar o bloqueio.  
  
### <a name="to-implement-the-semaphore-class"></a>Para implementar a classe semaphore  
  
1.  Declarar uma classe denominada `semaphore`. Adicionar `public` e `private` seções para essa classe.  
  
 [!code-cpp[concrt-cooperative-semaphore#1](../../parallel/concrt/codesnippet/cpp/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_1.cpp)]  
  
2.  No `private` seção o `semaphore` classe, declare um [std::atomic](../../standard-library/atomic-structure.md) variável que contém a contagem de semáforo e um [concurrency::concurrent_queue](../../parallel/concrt/reference/concurrent-queue-class.md) objeto que contém os contextos que deve aguardar para adquirir o semáforo.  
  
 [!code-cpp[concrt-cooperative-semaphore#2](../../parallel/concrt/codesnippet/cpp/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_2.cpp)]  
  
3.  No `public` seção o `semaphore` classe, implemente o construtor. O construtor usa um `long long` valor que especifica o número máximo de contextos que simultaneamente pode manter o bloqueio.  
  
 [!code-cpp[concrt-cooperative-semaphore#3](../../parallel/concrt/codesnippet/cpp/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_3.cpp)]  

4.  No `public` seção o `semaphore` classe, implemente o `acquire` método. Decrementa este método o semáforo contam como uma operação atômica. Se a contagem de semáforo se torna negativa, adicione o contexto atual para o final da fila de espera e chamada de [concurrency::Context::Block](reference/context-class.md#block) método para bloquear o contexto atual.  
  
 [!code-cpp[concrt-cooperative-semaphore#4](../../parallel/concrt/codesnippet/cpp/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_4.cpp)]  
  
5.  No `public` seção o `semaphore` classe, implemente o `release` método. Esse método incrementa a contagem de semáforo como uma operação atômica. Se a contagem de semáforo for negativa antes da operação de incremento, há pelo menos um contexto que está aguardando o bloqueio. Nesse caso, desbloqueie o contexto que está na frente da fila de espera.  
  
 [!code-cpp[concrt-cooperative-semaphore#5](../../parallel/concrt/codesnippet/cpp/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_5.cpp)]  
  
## <a name="example"></a>Exemplo  
 O `semaphore` classe neste exemplo se comporta de forma cooperativa porque o `Context::Block` e `Context::Yield` métodos geram execução para que o tempo de execução poderá executar outras tarefas.  
  
 O `acquire` diminui método o contador, mas ele não pode terminar de adicionar o contexto para a fila de espera antes de outra chamada de contexto de `release` método. Conta para isso, o `release` método usa um loop de rotação que chama o [concurrency::Context::Yield](reference/context-class.md#yield) método para aguardar o `acquire` método para concluir a adição do contexto.  
  
 O `release` método pode chamar o `Context::Unblock` método antes do `acquire` chamadas de método de `Context::Block` método. Não é necessário que proteger contra essa condição de corrida porque o tempo de execução permite que esses métodos ser chamado em qualquer ordem. Se o `release` chamadas de método `Context::Unblock` antes do `acquire` chamadas de método `Context::Block` para o mesmo contexto, nesse contexto permanece desbloqueado. O tempo de execução só requer que cada chamada para `Context::Block` é correspondido com uma chamada correspondente para `Context::Unblock`.  
  
 O exemplo a seguir mostra o completo `semaphore` classe. O `wmain` função mostra o uso básico dessa classe. O `wmain` função usa o [concurrency::parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmo para criar várias tarefas que requerem acesso ao semáforo. Porque três threads podem manter o bloqueio a qualquer momento, algumas tarefas devem aguardar outra tarefa terminar e liberar o bloqueio.  
  
 [!code-cpp[concrt-cooperative-semaphore#6](../../parallel/concrt/codesnippet/cpp/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_6.cpp)]  
  
 Este exemplo produz a saída de exemplo a seguir.  
  
```Output  
In loop iteration 5...  
In loop iteration 0...  
In loop iteration 6...  
In loop iteration 1...  
In loop iteration 2...  
In loop iteration 7...  
In loop iteration 3...  
In loop iteration 8...  
In loop iteration 9...  
In loop iteration 4...  
```  
  
 Para obter mais informações sobre o `concurrent_queue` de classe, consulte [objetos e contêineres paralelos](../../parallel/concrt/parallel-containers-and-objects.md). Para obter mais informações sobre o `parallel_for` algoritmo, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `cooperative-semaphore.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc cooperativo-semaphore.cpp**  
  
## <a name="robust-programming"></a>Programação robusta  
 Você pode usar o *recurso aquisição é inicialização* padrão (RAII) para limitar o acesso a um `semaphore` objeto para um determinado escopo. Em padrão RAII, uma estrutura de dados é alocada na pilha. Essa estrutura de dados inicializa ou adquire um recurso quando ele é criado e destrói ou libera esse recurso quando a estrutura de dados é destruída. O padrão RAII garante que o destruidor é chamado antes de sair do escopo delimitador. Portanto, o recurso é gerenciado corretamente quando uma exceção é lançada ou quando uma função contém várias `return` instruções.  
  
 O exemplo a seguir define uma classe denominada `scoped_lock`, que é definido no `public` seção o `semaphore` classe. O `scoped_lock` é semelhante a [concurrency::critical_section::scoped_lock](reference/critical-section-class.md#critical_section__scoped_lock_class) e [concurrency::reader_writer_lock::scoped_lock](reference/reader-writer-lock-class.md#scoped_lock_class) classes. O construtor do `semaphore::scoped_lock` classe adquire acesso para o determinado `semaphore` objeto e o destruidor libera o acesso a esse objeto.  
  
 [!code-cpp[concrt-cooperative-semaphore#7](../../parallel/concrt/codesnippet/cpp/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_7.cpp)]    
 O exemplo a seguir modifica o corpo da função de trabalho que é passado para o `parallel_for` algoritmo assim que ele usa RAII para garantir que o sinal é liberado antes da função retorna. Essa técnica garante que a função de trabalho é seguro de exceção.  
  
 [!code-cpp[concrt-cooperative-semaphore#8](../../parallel/concrt/codesnippet/cpp/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_8.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Contextos](../../parallel/concrt/contexts.md)   
 [Contêineres e objetos em paralelo](../../parallel/concrt/parallel-containers-and-objects.md)

