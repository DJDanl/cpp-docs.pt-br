---
title: "Como usar a classe de contexto para implementar um sem&#225;foro cooperativo | Microsoft Docs"
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
  - "implementação de sinal cooperativo"
  - "Classe de contexto"
ms.assetid: 22f4b9c0-ca22-4a68-90ba-39e99ea76696
caps.latest.revision: 18
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como usar a classe de contexto para implementar um sem&#225;foro cooperativo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico mostra como usar a classe concurrency::Context para implementar uma classe de sinal cooperativo.  
  
 O `Context` classe permite que você bloqueie ou gerar o contexto de execução atual. Bloqueando ou gerando o contexto atual é útil quando o contexto atual não pode continuar porque um recurso não está disponível. Um *semáforo* é um exemplo de uma situação em que o contexto de execução atual deve aguardar até que um recurso se torne disponível. Um sinal, como um objeto da seção crítica, é um objeto de sincronização que permite que o código em um contexto para ter acesso exclusivo a um recurso. No entanto, diferentemente de um objeto de seção crítica, um semáforo permite que mais de um contexto acessar o recurso simultaneamente. Se o número máximo de contextos mantém um bloqueio de sinal, cada contexto adicional deve aguardar outro contexto liberar o bloqueio.  
  
### <a name="to-implement-the-semaphore-class"></a>Para implementar a classe semaphore  
  
1.  Declare uma classe denominada `semaphore`. Adicionar `public` e `private` seções para essa classe.  
  
 [!code-cpp[concrt-cooperative-semaphore#1](../../parallel/concrt/codesnippet/CPP/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_1.cpp)]  
  
2.  No `private` seção o `semaphore` da classe, declare um [std:: Atomic](../../standard-library/atomic-structure.md) variável que contém a contagem do semáforo e um [concurrency::concurrent_queue](../Topic/concurrent_queue%20Class.md) objeto que mantém os contextos devem aguardar para adquirir o sinal.  
  
 [!code-cpp[concrt-cooperative-semaphore#2](../../parallel/concrt/codesnippet/CPP/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_2.cpp)]  
  
3.  No `public` seção o `semaphore` da classe, implemente o construtor. O construtor aceita um `long long` valor que especifica o número máximo de contextos que simultaneamente podem manter o bloqueio.  
  
 [!code-cpp[concrt-cooperative-semaphore#3](../../parallel/concrt/codesnippet/CPP/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_3.cpp)]  
  
4.  No `public` seção o `semaphore` da classe, implemente o `acquire` método. Contagem de sinal do diminui esse método como uma operação atômica. Se a contagem de sinais se torna negativa, adicione o contexto atual para o final da fila de espera e chamada de [concurrency::Context::Block](../Topic/Context::Block%20Method.md) método para bloquear o contexto atual.  
  
 [!code-cpp[concrt-cooperative-semaphore#4](../../parallel/concrt/codesnippet/CPP/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_4.cpp)]  
  
5.  No `public` seção o `semaphore` da classe, implemente o `release` método. Esse método incrementa a contagem de sinal como uma operação atômica. Se a contagem do semáforo é negativa antes da operação de incremento, há pelo menos um contexto que está aguardando o bloqueio. Nesse caso, desbloquear o contexto que está na frente da fila de espera.  
  
 [!code-cpp[concrt-cooperative-semaphore#5](../../parallel/concrt/codesnippet/CPP/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_5.cpp)]  
  
## <a name="example"></a>Exemplo  
 O `semaphore` classe nesse exemplo se comporta de forma cooperativa porque o `Context::Block` e `Context::Yield` métodos proporcionam a execução para que o tempo de execução pode executar outras tarefas.  
  
 O `acquire` diminui de método, o contador, mas ele não pode concluir a adição de contexto para a fila de espera antes de outra chamada de contexto de `release` método. Conta para isso, o `release` método usa um loop de rotação que chama o [concurrency::Context::Yield](../Topic/Context::Yield%20Method.md) método aguardar o `acquire` método para concluir a adição do contexto.  
  
 O `release` método pode chamar o `Context::Unblock` método antes de `acquire` chamadas de método o `Context::Block` método. Você não precisa proteger contra essa condição de corrida porque permite que o tempo de execução para esses métodos sejam chamados em qualquer ordem. Se o `release` chamadas de método `Context::Unblock` antes de `acquire` chamadas de método `Context::Block` para o mesmo contexto, que o contexto permanecerá desbloqueado. O tempo de execução exige apenas que cada chamada para `Context::Block` é correspondida com uma chamada correspondente para `Context::Unblock`.  
  
 O exemplo a seguir mostra a conclusão `semaphore` classe. O `wmain` função mostra o uso básico dessa classe. O `wmain` função usa o [concurrency::parallel_for](../Topic/parallel_for%20Function.md) algoritmo para criar várias tarefas que precisam de acesso para o sinal. Como três threads podem manter o bloqueio a qualquer momento, algumas tarefas devem aguardar outra tarefa terminar e liberar o bloqueio.  
  
 [!code-cpp[concrt-cooperative-semaphore#6](../../parallel/concrt/codesnippet/CPP/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_6.cpp)]  
  
 Este exemplo produz a seguinte saída de exemplo.  
  
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
  
 Para obter mais informações sobre o `concurrent_queue` de classe, consulte [paralela contêineres e objetos](../../parallel/concrt/parallel-containers-and-objects.md). Para obter mais informações sobre o `parallel_for` algoritmo, consulte [algoritmos paralelos](../Topic/Parallel%20Algorithms.md).  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `cooperative-semaphore.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc cooperativo-semaphore.cpp**  
  
## <a name="robust-programming"></a>Programação robusta  
 Você pode usar o *recurso aquisição é inicialização* padrão (RAII) para limitar o acesso a um `semaphore` objeto para um determinado escopo. Em padrão RAII, uma estrutura de dados é alocada na pilha. Essa estrutura de dados inicializa ou obtém um recurso quando ele é criado e destrói ou libera esse recurso quando a estrutura de dados é destruída. O padrão RAII garante que o destruidor é chamado antes de sair do escopo delimitador. Portanto, o recurso esteja corretamente gerenciado quando uma exceção é lançada ou quando uma função contém várias `return` instruções.  
  
 O exemplo a seguir define uma classe chamada `scoped_lock`, que é definido na `public` seção o `semaphore` classe. O `scoped_lock` classe é semelhante a [concurrency::critical_section::scoped_lock](../Topic/critical_section::scoped_lock%20Class.md) e [concurrency::reader_writer_lock::scoped_lock](../Topic/reader_writer_lock::scoped_lock%20Class.md) classes. O construtor do `semaphore::scoped_lock` classe adquire acessem o determinado `semaphore` objeto e o destruidor libera o acesso a esse objeto.  
  
 [!code-cpp[concrt-cooperative-semaphore#7](../../parallel/concrt/codesnippet/CPP/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_7.cpp)]  
  
 O exemplo a seguir modifica o corpo da função de trabalho que é passado para o `parallel_for` algoritmo para ele usar RAII para garantir que o sinal seja liberado antes que a função retorna. Essa técnica garante que a função de trabalho é seguro de exceção.  
  
 [!code-cpp[concrt-cooperative-semaphore#8](../../parallel/concrt/codesnippet/CPP/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_8.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Contextos](../../parallel/concrt/contexts.md)   
 [Objetos e contêineres em paralelo](../../parallel/concrt/parallel-containers-and-objects.md)

