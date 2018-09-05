---
title: 'Passo a passo: Usando o tempo de execução de simultaneidade em um aplicativo habilitado para COM | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Concurrency Runtime, use with COM
- COM, use with the Concurrency Runtime
ms.assetid: a7c798b8-0fc8-4bee-972f-22ef158f7f48
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ed404bcbbdd62c051b0f93e2607d1278bfbf0204
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43691829"
---
# <a name="walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application"></a>Instruções passo a passo: usando o Tempo de Execução de Simultaneidade em um aplicativo habilitado para COM
Este documento demonstra como usar o tempo de execução de simultaneidade em um aplicativo que usa o modelo de objeto de componente (COM).  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Leia os documentos a seguir antes de começar este passo a passo:  
  
- [Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)  
  
- [Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)  
  
- [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)  
  
- [Tratamento de Exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md)  
  
 Para obter mais informações sobre o COM, consulte [(COM Component Object Model)](/windows/desktop/com/component-object-model--com--portal).  
  
## <a name="managing-the-lifetime-of-the-com-library"></a>Gerenciando o Tempo de Vida da Biblioteca COM  
 Embora o uso do COM o tempo de execução de simultaneidade segue os mesmos princípios como qualquer outro mecanismo de simultaneidade, as diretrizes a seguir podem ajudá-lo a usar essas bibliotecas em conjunto com eficiência.  
  
-   Um thread deve chamar [CoInitializeEx](/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) antes de usar a biblioteca COM.  
  
-   Um thread pode chamar `CoInitializeEx` várias vezes, desde que ele fornece os mesmos argumentos para todas as chamadas.  
  
-   Para cada chamada para `CoInitializeEx`, um thread também deve chamar [CoUninitialize](/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize). Em outras palavras, chamadas para `CoInitializeEx` e `CoUninitialize` deve ser equilibrada.  
  
-   Para alternar do apartment de um thread para outro, um thread deve liberar completamente a biblioteca COM antes de chamar `CoInitializeEx` com a nova especificação de threading.  
  
 Outros princípios COM se aplicam quando você usa COM o tempo de execução de simultaneidade. Por exemplo, um aplicativo que cria um objeto em um single-threaded apartment (STA) e realiza marshaling desse objeto para outro apartment também deve fornecer um loop de mensagem para processar mensagens de entrada. Lembre-se também de marshaling de objetos entre apartments pode diminuir o desempenho.  
  
### <a name="using-com-with-the-parallel-patterns-library"></a>Usar COM com a Biblioteca de Padrões Paralela  
 Quando você usa COM um componente na paralela padrões PPL (biblioteca), por exemplo, um grupo de tarefas ou o algoritmo paralelo, chame `CoInitializeEx` antes de usar a biblioteca COM durante cada tarefa ou a iteração e a chamada `CoUninitialize` antes de concluir cada tarefa ou uma iteração . O exemplo a seguir mostra como gerenciar o tempo de vida da biblioteca COM um [Concurrency:: structured_task_group](../../parallel/concrt/reference/structured-task-group-class.md) objeto.  
  
 [!code-cpp[concrt-parallel-scripts#1](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_1.cpp)]  
  
 Certifique-se de que a biblioteca COM corretamente é liberada quando um algoritmo paralelo ou a tarefa for cancelado ou quando o corpo da tarefa gera uma exceção. Para garantir que a tarefa chama `CoUninitialize` antes de sair, use uma `try-finally` bloco ou o *recursos aquisição é inicialização* padrão (RAII). O exemplo a seguir usa um `try-finally` bloco para liberar a biblioteca COM quando a tarefa concluída ou cancelada, ou quando uma exceção é lançada.  
  
 [!code-cpp[concrt-parallel-scripts#2](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_2.cpp)]  
  
 O exemplo a seguir usa o padrão RAII para definir o `CCoInitializer` classe, que gerencia o tempo de vida da biblioteca COM em um determinado escopo.  
  
 [!code-cpp[concrt-parallel-scripts#3](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_3.cpp)]  
  
 Você pode usar o `CCoInitializer` classe liberar automaticamente a biblioteca COM quando a tarefa é encerrada, da seguinte maneira.  
  
 [!code-cpp[concrt-parallel-scripts#4](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_4.cpp)]  
  
 Para obter mais informações sobre o cancelamento no tempo de execução de simultaneidade, consulte [cancelamento no PPL](cancellation-in-the-ppl.md).  
  
### <a name="using-com-with-asynchronous-agents"></a>Usando COM com Agentes Assíncronos  

 Quando você usa COM agentes assíncronos, chame `CoInitializeEx` antes de usar a biblioteca de COM em de [concurrency::agent::run](reference/agent-class.md#run) método para seu agente. Em seguida, chame `CoUninitialize` antes do `run` retorno do método. Não use rotinas de gerenciamento COM no construtor ou destruidor do seu agente e não substituem as [concurrency::agent::start](reference/agent-class.md#start) ou [concurrency::agent:: feito](reference/agent-class.md#done) métodos porque esses métodos são chamado a partir de um thread diferente do `run` método.  

  
 O exemplo a seguir mostra uma classe de agente básica, denominada `CCoAgent`, que gerencia a biblioteca de COM no `run` método.  
  
 [!code-cpp[concrt-parallel-scripts#5](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_5.cpp)]  
  
 Um exemplo completo é fornecido posteriormente neste passo a passo.  
  
### <a name="using-com-with-lightweight-tasks"></a>Usando COM com Tarefas Leves  
 O documento [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md) descreve a função de tarefas leves no tempo de execução de simultaneidade. Você pode usar COM uma tarefa leve, assim como faria com qualquer rotina de thread que você passa para o `CreateThread` função na API do Windows. Isso é mostrado no exemplo a seguir.  
  
 [!code-cpp[concrt-parallel-scripts#6](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_6.cpp)]  
  
## <a name="an-example-of-a-com-enabled-application"></a>Um Exemplo de um Aplicativo Habilitado para COM  
 Esta seção mostra um aplicativo habilitado para COM completo que usa o `IScriptControl` interface para executar um script que calcula o n<sup>th</sup> número Fibonacci. Este exemplo primeiro chama o script do thread principal e, em seguida, usa os agentes e PPL para chamar o script simultaneamente.  
  
 Considere a seguinte função auxiliar, `RunScriptProcedure`, que chama um procedimento um `IScriptControl` objeto.  
  
 [!code-cpp[concrt-parallel-scripts#7](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_7.cpp)]  
  
 O `wmain` função cria um `IScriptControl` do objeto, adiciona o código de script que calcula o n<sup>th</sup> número de Fibonacci e, em seguida, chama o `RunScriptProcedure` função para executar esse script.  
  
 [!code-cpp[concrt-parallel-scripts#8](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_8.cpp)]  
  
### <a name="calling-the-script-from-the-ppl"></a>Chamando o Script da PPL  

 A seguinte função, `ParallelFibonacci`, usa o [Concurrency:: parallel_for](reference/concurrency-namespace-functions.md#parallel_for) algoritmo para chamar o script em paralelo. Essa função usa o `CCoInitializer` classe para gerenciar o tempo de vida da biblioteca COM durante cada iteração da tarefa.  

  
 [!code-cpp[concrt-parallel-scripts#9](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_9.cpp)]  
  
 Para usar o `ParallelFibonacci` funcionar com o exemplo, adicione o seguinte código antes do `wmain` retornos de função.  
  
 [!code-cpp[concrt-parallel-scripts#10](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_10.cpp)]  
  
### <a name="calling-the-script-from-an-agent"></a>Chamando o Script de um Agente  
 A exemplo a seguir mostra a `FibonacciScriptAgent` classe, que chama um procedimento de script para computar o n<sup>th</sup> número Fibonacci. O `FibonacciScriptAgent` classe usa a mensagem passando para receber do programa principal, inserir valores para a função de script. O `run` método gerencia a vida útil de biblioteca COM em toda a tarefa.  
  
 [!code-cpp[concrt-parallel-scripts#11](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_11.cpp)]  
  
 A seguinte função, `AgentFibonacci`, cria vários `FibonacciScriptAgent` objetos e usa a mensagem passando para enviar vários valores para esses objetos de entrada.  
  
 [!code-cpp[concrt-parallel-scripts#12](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_12.cpp)]  
  
 Para usar o `AgentFibonacci` funcionar com o exemplo, adicione o seguinte código antes do `wmain` retornos de função.  
  
 [!code-cpp[concrt-parallel-scripts#13](../../parallel/concrt/codesnippet/cpp/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_13.cpp)]  
  
### <a name="the-complete-example"></a>O Exemplo Completo  
 O código a seguir mostra o exemplo completo, que usa algoritmos paralelos e agentes assíncronos para chamar um procedimento de script que calcula números de Fibonacci.  
  
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
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `parallel-scripts.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc /link paralelo scripts.cpp ole32.lib**  
  
## <a name="see-also"></a>Consulte também  
 [Instruções passo a passo de tempo de execução de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)   
 [Paralelismo de tarefas](../../parallel/concrt/task-parallelism-concurrency-runtime.md)   
 [Algoritmos paralelos](../../parallel/concrt/parallel-algorithms.md)   
 [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)   
 [Tratamento de exceções](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md)   
 [Cancelamento no PPL](cancellation-in-the-ppl.md)   
 [Agendador de tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)

