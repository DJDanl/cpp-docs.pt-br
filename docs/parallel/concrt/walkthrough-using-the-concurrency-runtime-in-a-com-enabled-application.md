---
title: 'Passo a passo: Usando o Tempo de Execução de Simultaneidade em um aplicativo habilitado para COM'
ms.date: 04/25/2019
helpviewer_keywords:
- Concurrency Runtime, use with COM
- COM, use with the Concurrency Runtime
ms.assetid: a7c798b8-0fc8-4bee-972f-22ef158f7f48
ms.openlocfilehash: 23488522287ab5767c88cd3a3e90c09392634f46
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69512104"
---
# <a name="walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application"></a>Passo a passo: Usando o Tempo de Execução de Simultaneidade em um aplicativo habilitado para COM

Este documento demonstra como usar o Tempo de Execução de Simultaneidade em um aplicativo que usa a Component Object Model (COM).

## <a name="prerequisites"></a>Pré-requisitos

Leia os seguintes documentos antes de iniciar este passo a passos:

- [Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)

- [Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)

- [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)

- [Tratamento de Exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md)

Para obter mais informações sobre COM, consulte [Component Object Model (com)](/windows/win32/com/component-object-model--com--portal).

## <a name="managing-the-lifetime-of-the-com-library"></a>Gerenciando o Tempo de Vida da Biblioteca COM

Embora o uso de COM com a Tempo de Execução de Simultaneidade siga os mesmos princípios de qualquer outro mecanismo de simultaneidade, as diretrizes a seguir podem ajudá-lo a usar essas bibliotecas COM eficiência.

- Um thread deve chamar [CoInitializeEx](/windows/win32/api/combaseapi/nf-combaseapi-coinitializeex) antes de usar a biblioteca com.

- Um thread pode chamar `CoInitializeEx` várias vezes, desde que forneça os mesmos argumentos a cada chamada.

- Para cada chamada para `CoInitializeEx`, um thread também deve chamar [CoUninitialize](/windows/win32/api/combaseapi/nf-combaseapi-couninitialize). Em outras palavras, chamadas para `CoInitializeEx` e `CoUninitialize` devem ser equilibradas.

- Para alternar de um thread apartment para outro, um thread deve liberar completamente a biblioteca com antes de chamar `CoInitializeEx` a nova especificação de Threading.

Outros princípios de COM se aplicam quando você usa com com o Tempo de Execução de Simultaneidade. Por exemplo, um aplicativo que cria um objeto em um STA (single-threaded apartment) e realiza marshaling desse objeto para outro apartamento também deve fornecer um loop de mensagem para processar mensagens de entrada. Lembre-se também de que o marshaling de objetos entre Apartments pode diminuir o desempenho.

### <a name="using-com-with-the-parallel-patterns-library"></a>Usar COM com a Biblioteca de Padrões Paralela

Ao usar com com um componente na ppl (biblioteca de padrões paralelos), por exemplo, um grupo de tarefas ou algoritmo paralelo, `CoInitializeEx` chame antes de usar a biblioteca com durante cada tarefa ou iteração e `CoUninitialize` chame antes de cada tarefa ou iteração ser concluída . O exemplo a seguir mostra como gerenciar o tempo de vida da biblioteca com com um objeto [Concurrency:: structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) .

[!code-cpp[concrt-parallel-scripts#1](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_1.cpp)]

Você deve verificar se a biblioteca COM foi liberada corretamente quando uma tarefa ou um algoritmo paralelo é cancelado ou quando o corpo da tarefa gera uma exceção. Para garantir que a tarefa seja `CoUninitialize` chamada antes de ser encerrada, `try-finally` use um padrão de bloco ou de RAII ( *aquisição de recursos é inicialização* ). O exemplo a seguir usa `try-finally` um bloco para liberar a biblioteca com quando a tarefa é concluída ou cancelada, ou quando uma exceção é lançada.

[!code-cpp[concrt-parallel-scripts#2](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_2.cpp)]

O exemplo a seguir usa o padrão RAII para definir `CCoInitializer` a classe, que gerencia o tempo de vida da biblioteca com em um determinado escopo.

[!code-cpp[concrt-parallel-scripts#3](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_3.cpp)]

Você pode usar a `CCoInitializer` classe para liberar automaticamente a biblioteca com quando a tarefa for encerrada, como a seguir.

[!code-cpp[concrt-parallel-scripts#4](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_4.cpp)]

Para obter mais informações sobre o cancelamento na Tempo de Execução de Simultaneidade, consulte cancelamento [na ppl](cancellation-in-the-ppl.md).

### <a name="using-com-with-asynchronous-agents"></a>Usando COM com Agentes Assíncronos

Ao usar com com agentes assíncronos, chame `CoInitializeEx` antes de usar a biblioteca com no método [Concurrency:: Agent:: execute](reference/agent-class.md#run) para seu agente. Em seguida `CoUninitialize` , chame `run` antes de o método retornar. Não use rotinas de gerenciamento COM no construtor ou destruidor do seu agente e não substitua os métodos [Concurrency:: Agent:: Start](reference/agent-class.md#start) ou [Concurrency:: Agent::d um](reference/agent-class.md#done) , pois esses métodos são chamados de um thread diferente do `run` método.

O exemplo a seguir mostra uma classe básica de agente `CCoAgent`, chamada, que gerencia a biblioteca com `run` no método.

[!code-cpp[concrt-parallel-scripts#5](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_5.cpp)]

Um exemplo completo é fornecido posteriormente neste passo a passos.

### <a name="using-com-with-lightweight-tasks"></a>Usando COM com Tarefas Leves

O documento [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md) descreve a função das tarefas leves no tempo de execução de simultaneidade. Você pode usar com com uma tarefa leve da mesma forma que faria com qualquer rotina de thread passada para a `CreateThread` função na API do Windows. Isso é mostrado no exemplo a seguir.

[!code-cpp[concrt-parallel-scripts#6](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_6.cpp)]

## <a name="an-example-of-a-com-enabled-application"></a>Um Exemplo de um Aplicativo Habilitado para COM

Esta seção mostra um aplicativo habilitado para com completo que usa a `IScriptControl` interface para executar um script que computa o número n<sup>ésimo</sup> Fibonacci. Este exemplo primeiro chama o script do thread principal e, em seguida, usa a PPL e os agentes para chamar o script simultaneamente.

Considere a seguinte função auxiliar, `RunScriptProcedure`, que chama um procedimento em um `IScriptControl` objeto.

[!code-cpp[concrt-parallel-scripts#7](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_7.cpp)]

A `wmain` função cria um `IScriptControl` objeto, adiciona o código de script a ele que computa o número n<sup>ésimo</sup> Fibonacci e, em seguida `RunScriptProcedure` , chama a função para executar esse script.

[!code-cpp[concrt-parallel-scripts#8](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_8.cpp)]

### <a name="calling-the-script-from-the-ppl"></a>Chamando o Script da PPL

A função a seguir `ParallelFibonacci`,, usa o algoritmo [Concurrency::p arallel_for](reference/concurrency-namespace-functions.md#parallel_for) para chamar o script em paralelo. Essa função usa a `CCoInitializer` classe para gerenciar o tempo de vida da biblioteca com durante cada iteração da tarefa.

[!code-cpp[concrt-parallel-scripts#9](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_9.cpp)]

Para usar a `ParallelFibonacci` função com o exemplo, adicione o código a seguir antes `wmain` que a função retorne.

[!code-cpp[concrt-parallel-scripts#10](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_10.cpp)]

### <a name="calling-the-script-from-an-agent"></a>Chamando o Script de um Agente

O exemplo a seguir mostra `FibonacciScriptAgent` a classe, que chama um procedimento de script para calcular o número n<sup>ésimo</sup> Fibonacci. A `FibonacciScriptAgent` classe usa a passagem de mensagens para receber, do programa principal, valores de entrada para a função script. O `run` método gerencia o tempo de vida da biblioteca com em toda a tarefa.

[!code-cpp[concrt-parallel-scripts#11](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_11.cpp)]

A função a seguir `AgentFibonacci`,, cria `FibonacciScriptAgent` vários objetos e usa a passagem de mensagens para enviar vários valores de entrada para esses objetos.

[!code-cpp[concrt-parallel-scripts#12](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_12.cpp)]

Para usar a `AgentFibonacci` função com o exemplo, adicione o código a seguir antes `wmain` que a função retorne.

[!code-cpp[concrt-parallel-scripts#13](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_13.cpp)]

### <a name="the-complete-example"></a>O Exemplo Completo

O código a seguir mostra o exemplo completo, que usa algoritmos paralelos e agentes assíncronos para chamar um procedimento de script que computa números Fibonaccis.

[!code-cpp[concrt-parallel-scripts#14](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_14.cpp)]

O exemplo produz a saída de exemplo a seguir.

```Output
Main Thread:
fib(15) = 610

Parallel Fibonacci:
fib(15) = 610
fib(10) = 55
fib(16) = 987
fib(18) = 2584
fib(11) = 89
fib(17) = 1597
fib(19) = 4181
fib(12) = 144
fib(13) = 233
fib(14) = 377

Agent Fibonacci:
fib(30) = 832040
fib(22) = 17711
fib(10) = 55
fib(12) = 144
```

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo `parallel-scripts.cpp` chamado e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

**CL. exe/EHsc Parallel-scripts. cpp/link Ole32. lib**

## <a name="see-also"></a>Consulte também

[Instruções passo a passo do tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)<br/>
[Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)<br/>
[Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)<br/>
[Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)<br/>
[Tratamento de Exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md)<br/>
[Cancelamento no PPL](cancellation-in-the-ppl.md)<br/>
[Agendador de Tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)
