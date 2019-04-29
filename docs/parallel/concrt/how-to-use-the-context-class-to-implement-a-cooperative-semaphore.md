---
title: 'Como: Use a classe de contexto para implementar um semáforo cooperativo'
ms.date: 11/04/2016
helpviewer_keywords:
- cooperative semaphore implementing
- context class
ms.assetid: 22f4b9c0-ca22-4a68-90ba-39e99ea76696
ms.openlocfilehash: 92f77fade972bff1528bc9a22416670354c70f34
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62366700"
---
# <a name="how-to-use-the-context-class-to-implement-a-cooperative-semaphore"></a>Como: Use a classe de contexto para implementar um semáforo cooperativo

Este tópico mostra como usar a classe concurrency::Context para implementar uma classe de semáforo cooperativo.

O `Context` classe permite que você bloqueie ou gerar o contexto de execução atual. Bloquear ou produzindo o contexto atual é útil quando o contexto atual não pode continuar porque um recurso não está disponível. Um *semáforo* é um exemplo de uma situação em que o contexto de execução atual deve aguardar um recurso se torne disponível. Um semáforo, como um objeto de seção crítica, é um objeto de sincronização que permite que o código em um contexto para ter acesso exclusivo a um recurso. No entanto, diferentemente de um objeto de seção crítica, um semáforo permite que mais de um contexto acessar o recurso simultaneamente. Se o número máximo de contextos mantém um bloqueio de sinal, cada contexto adicional deve aguardar outro contexto liberar o bloqueio.

### <a name="to-implement-the-semaphore-class"></a>Para implementar a classe semaphore

1. Declarar uma classe chamada `semaphore`. Adicione `public` e `private` seções para essa classe.

[!code-cpp[concrt-cooperative-semaphore#1](../../parallel/concrt/codesnippet/cpp/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_1.cpp)]

1. No `private` seção o `semaphore` classe, declare um [std:: Atomic](../../standard-library/atomic-structure.md) variável que contém a contagem do semáforo e um [concurrency::concurrent_queue](../../parallel/concrt/reference/concurrent-queue-class.md) o objeto que mantém os contextos que deve aguardar para adquirir o semáforo.

[!code-cpp[concrt-cooperative-semaphore#2](../../parallel/concrt/codesnippet/cpp/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_2.cpp)]

1. No `public` seção o `semaphore` de classe, implemente o construtor. O construtor aceita um `long long` valor que especifica o número máximo de contextos que simultaneamente podem manter o bloqueio.

[!code-cpp[concrt-cooperative-semaphore#3](../../parallel/concrt/codesnippet/cpp/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_3.cpp)]

1. No `public` seção o `semaphore` classe, implemente o `acquire` método. Decrementa esse método o semáforo contam como uma operação atômica. Se a contagem do semáforo se torna negativa, adicione o contexto atual para o final da fila de espera e chamada a [concurrency::Context::Block](reference/context-class.md#block) para bloquear o contexto atual.

[!code-cpp[concrt-cooperative-semaphore#4](../../parallel/concrt/codesnippet/cpp/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_4.cpp)]

1. No `public` seção o `semaphore` classe, implemente o `release` método. Esse método incrementa a contagem do semáforo como uma operação atômica. Se a contagem do semáforo for negativa antes da operação de incremento, há pelo menos um contexto que está aguardando o bloqueio. Nesse caso, desbloqueie o contexto que está à frente da fila de espera.

[!code-cpp[concrt-cooperative-semaphore#5](../../parallel/concrt/codesnippet/cpp/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_5.cpp)]

## <a name="example"></a>Exemplo

O `semaphore` classe neste exemplo se comporta de forma cooperativa porque o `Context::Block` e `Context::Yield` métodos proporcionam a execução para que o tempo de execução poderá executar outras tarefas.

O `acquire` diminui de método, o contador, mas ele não pode concluir a adição de contexto para a fila de espera antes de outra chamada de contexto a `release` método. Para justificar isso, o `release` método usa um loop de rotação que chama o [concurrency::Context::Yield](reference/context-class.md#yield) aguardar o `acquire` método para concluir a adição do contexto.

O `release` método pode chamar o `Context::Unblock` método antes do `acquire` chamadas de método a `Context::Block` método. Não é necessário que proteger contra essa condição de corrida, pois permite que o tempo de execução para esses métodos sejam chamados em qualquer ordem. Se o `release` chamadas de método `Context::Unblock` antes do `acquire` chamadas de método `Context::Block` para o mesmo contexto, esse contexto permaneça desbloqueado. O tempo de execução só requer que cada chamada para `Context::Block` será combinado com uma chamada correspondente para `Context::Unblock`.

O exemplo a seguir mostra todo `semaphore` classe. O `wmain` função mostra o uso básico dessa classe. O `wmain` função usa o [Concurrency:: parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmo para criar várias tarefas que exigem acesso para o semáforo. Porque três threads podem manter o bloqueio a qualquer momento, algumas tarefas devem aguardar a conclusão e liberar o bloqueio de outra tarefa.

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

Para obter mais informações sobre o `concurrent_queue` classe, consulte [paralela contêineres e objetos](../../parallel/concrt/parallel-containers-and-objects.md). Para obter mais informações sobre o `parallel_for` algoritmo, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `cooperative-semaphore.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**cl.exe /EHsc cooperativo-semaphore.cpp**

## <a name="robust-programming"></a>Programação robusta

Você pode usar o *inicialização é de aquisição de recursos* padrão (RAII) para limitar o acesso a um `semaphore` objeto para um determinado escopo. Sob o padrão RAII, uma estrutura de dados é alocada na pilha. Essa estrutura de dados inicializa ou adquire um recurso quando ele é criado e destrói ou libera esse recurso quando a estrutura de dados é destruída. O padrão RAII garante que o destruidor é chamado antes de sair do escopo delimitador. Portanto, os recursos são gerenciados corretamente quando uma exceção é lançada ou quando uma função contém várias `return` instruções.

O exemplo a seguir define uma classe chamada `scoped_lock`, que é definido na `public` seção o `semaphore` classe. O `scoped_lock` é semelhante a [concurrency::critical_section::scoped_lock](reference/critical-section-class.md#critical_section__scoped_lock_class) e [concurrency::reader_writer_lock::scoped_lock](reference/reader-writer-lock-class.md#scoped_lock_class) classes. O construtor do `semaphore::scoped_lock` classe adquire acesso para o determinado `semaphore` objeto e o destruidor libera o acesso a esse objeto.

[!code-cpp[concrt-cooperative-semaphore#7](../../parallel/concrt/codesnippet/cpp/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_7.cpp)]
O exemplo a seguir modifica o corpo da função de trabalho que é passado para o `parallel_for` algoritmo para ele usar RAII para garantir que o sinal seja liberado antes da função retorna. Essa técnica garante que a função de trabalho é à prova de exceções.

[!code-cpp[concrt-cooperative-semaphore#8](../../parallel/concrt/codesnippet/cpp/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_8.cpp)]

## <a name="see-also"></a>Consulte também

[Contextos](../../parallel/concrt/contexts.md)<br/>
[Contêineres e objetos em paralelo](../../parallel/concrt/parallel-containers-and-objects.md)
