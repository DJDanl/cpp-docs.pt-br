---
title: Como usar a classe de contexto para implementar um semáforo cooperativo
ms.date: 11/04/2016
helpviewer_keywords:
- cooperative semaphore implementing
- context class
ms.assetid: 22f4b9c0-ca22-4a68-90ba-39e99ea76696
ms.openlocfilehash: 77cf33288761c75d056649ebe27f9d74c6fa62dc
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230383"
---
# <a name="how-to-use-the-context-class-to-implement-a-cooperative-semaphore"></a>Como usar a classe de contexto para implementar um semáforo cooperativo

Este tópico mostra como usar a classe Concurrency:: Context para implementar uma classe de semáforo cooperativo.

## <a name="remarks"></a>Comentários

A `Context` classe permite que você bloqueie ou gere o contexto de execução atual. O bloqueio ou o rendimento do contexto atual é útil quando o contexto atual não pode continuar porque um recurso não está disponível. Um *semáforo* é um exemplo de uma situação em que o contexto de execução atual deve aguardar que um recurso fique disponível. Um semáforo, como um objeto de seção crítica, é um objeto de sincronização que permite que o código em um contexto tenha acesso exclusivo a um recurso. No entanto, ao contrário de um objeto de seção crítica, um semáforo permite que mais de um contexto acesse o recurso simultaneamente. Se o número máximo de contextos mantiver um bloqueio de semáforo, cada contexto adicional deverá aguardar outro contexto para liberar o bloqueio.

### <a name="to-implement-the-semaphore-class"></a>Para implementar a classe semaphore

1. Declare uma classe que é nomeada `semaphore` . Adicione **`public`** **`private`** seções e a esta classe.

[!code-cpp[concrt-cooperative-semaphore#1](../../parallel/concrt/codesnippet/cpp/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_1.cpp)]

1. Na **`private`** seção da `semaphore` classe, declare uma variável [std:: Atomic](../../standard-library/atomic-structure.md) que contém a contagem de semáforo e um objeto [Concurrency:: concurrent_queue](../../parallel/concrt/reference/concurrent-queue-class.md) que contém os contextos que devem aguardar para adquirir o semáforo.

[!code-cpp[concrt-cooperative-semaphore#2](../../parallel/concrt/codesnippet/cpp/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_2.cpp)]

1. Na **`public`** seção da `semaphore` classe, implemente o construtor. O construtor usa um **`long long`** valor que especifica o número máximo de contextos que podem manter o bloqueio simultaneamente.

[!code-cpp[concrt-cooperative-semaphore#3](../../parallel/concrt/codesnippet/cpp/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_3.cpp)]

1. Na **`public`** seção da `semaphore` classe, implemente o `acquire` método. Esse método diminui a contagem de semáforo como uma operação atômica. Se a contagem de semáforo se tornar negativa, adicione o contexto atual ao final da fila de espera e chame o método [Concurrency:: Context:: Block](reference/context-class.md#block) para bloquear o contexto atual.

[!code-cpp[concrt-cooperative-semaphore#4](../../parallel/concrt/codesnippet/cpp/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_4.cpp)]

1. Na **`public`** seção da `semaphore` classe, implemente o `release` método. Esse método incrementa a contagem de semáforo como uma operação atômica. Se a contagem de semáforo for negativa antes da operação de incremento, haverá pelo menos um contexto que está aguardando o bloqueio. Nesse caso, desbloqueie o contexto que está na frente da fila de espera.

[!code-cpp[concrt-cooperative-semaphore#5](../../parallel/concrt/codesnippet/cpp/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_5.cpp)]

## <a name="example"></a>Exemplo

A `semaphore` classe neste exemplo se comporta de forma cooperativa porque os `Context::Block` métodos e `Context::Yield` geram execução para que o tempo de execução possa executar outras tarefas.

O `acquire` método Decrementa o contador, mas pode não terminar de adicionar o contexto à fila de espera antes que outro contexto chame o `release` método. Para considerar isso, o `release` método usa um loop de rotação que chama o método [Concurrency:: Context:: yield](reference/context-class.md#yield) para aguardar que o `acquire` método termine de adicionar o contexto.

O `release` método pode chamar o `Context::Unblock` método antes que o `acquire` método chame o `Context::Block` método. Você não precisa se proteger contra essa condição de corrida porque o tempo de execução permite que esses métodos sejam chamados em qualquer ordem. Se o `release` método chamar `Context::Unblock` antes do `acquire` método chamar `Context::Block` para o mesmo contexto, esse contexto permanecerá desbloqueado. O tempo de execução requer apenas que cada chamada para `Context::Block` seja correspondida com uma chamada correspondente para `Context::Unblock` .

O exemplo a seguir mostra a `semaphore` classe completa. A `wmain` função mostra o uso básico dessa classe. A `wmain` função usa o algoritmo [concurrency::p arallel_for](reference/concurrency-namespace-functions.md#parallel_for) para criar várias tarefas que exigem acesso ao semáforo. Como três threads podem manter o bloqueio a qualquer momento, algumas tarefas devem aguardar a conclusão de outra tarefa e liberar o bloqueio.

[!code-cpp[concrt-cooperative-semaphore#6](../../parallel/concrt/codesnippet/cpp/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_6.cpp)]

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

Para obter mais informações sobre a `concurrent_queue` classe, consulte [contêineres e objetos paralelos](../../parallel/concrt/parallel-containers-and-objects.md). Para obter mais informações sobre o `parallel_for` algoritmo, consulte [algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md).

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `cooperative-semaphore.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **cl.exe/EHsc Cooperative-Semaphore. cpp**

## <a name="robust-programming"></a>Programação robusta

Você pode usar o padrão RAII ( *aquisição de recursos é inicialização* ) para limitar o acesso a um `semaphore` objeto para um determinado escopo. No padrão RAII, uma estrutura de dados é alocada na pilha. Essa estrutura de dados inicializa ou adquire um recurso quando ele é criado e destrói ou libera esse recurso quando a estrutura de dados é destruída. O padrão RAII garante que o destruidor seja chamado antes da saída do escopo delimitador. Portanto, o recurso é gerenciado corretamente quando uma exceção é lançada ou quando uma função contém várias **`return`** instruções.

O exemplo a seguir define uma classe chamada `scoped_lock` , que é definida na **`public`** seção da `semaphore` classe. A `scoped_lock` classe é semelhante às classes [Concurrency:: critical_section:: scoped_lock](reference/critical-section-class.md#critical_section__scoped_lock_class) e [Concurrency:: reader_writer_lock:: scoped_lock](reference/reader-writer-lock-class.md#scoped_lock_class) . O construtor da `semaphore::scoped_lock` classe adquire o acesso ao `semaphore` objeto fornecido e o destruidor libera o acesso a esse objeto.

[!code-cpp[concrt-cooperative-semaphore#7](../../parallel/concrt/codesnippet/cpp/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_7.cpp)]
O exemplo a seguir modifica o corpo da função de trabalho que é passada para o `parallel_for` algoritmo para que ele use RAII para garantir que o semáforo seja liberado antes que a função retorne. Essa técnica garante que a função de trabalho seja segura para exceções.

[!code-cpp[concrt-cooperative-semaphore#8](../../parallel/concrt/codesnippet/cpp/how-to-use-the-context-class-to-implement-a-cooperative-semaphore_8.cpp)]

## <a name="see-also"></a>Confira também

[Contextos](../../parallel/concrt/contexts.md)<br/>
[Contêineres e objetos paralelos](../../parallel/concrt/parallel-containers-and-objects.md)
