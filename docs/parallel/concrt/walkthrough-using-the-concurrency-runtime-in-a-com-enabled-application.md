---
title: "Instru&#231;&#245;es passo a passo: usando o Tempo de Execu&#231;&#227;o de Simultaneidade em um aplicativo habilitado para COM | Microsoft Docs"
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
  - "Tempo de execução de simultaneidade, uso com"
  - "COM, use com o tempo de execução de simultaneidade"
ms.assetid: a7c798b8-0fc8-4bee-972f-22ef158f7f48
caps.latest.revision: 14
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: usando o Tempo de Execu&#231;&#227;o de Simultaneidade em um aplicativo habilitado para COM
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este documento demonstra como usar o tempo de execução de simultaneidade em um aplicativo que usa o Component Object Model \(COM\).  
  
## Pré-requisitos  
 Leia os seguintes documentos antes de iniciar esta explicação passo a passo:  
  
-   [Paralelismo da tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md)  
  
-   [Algoritmos paralelos](../Topic/Parallel%20Algorithms.md)  
  
-   [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)  
  
-   [Tratamento de Exceção](../Topic/Exception%20Handling%20in%20the%20Concurrency%20Runtime.md)  
  
 Para obter mais informações sobre como COM o, consulte [Component Object Model \(COM\)](http://msdn.microsoft.com/library/windows/desktop/ms680573).  
  
## Gerenciando o Tempo de Vida da Biblioteca COM  
 Embora o uso da com o tempo de execução de simultaneidade siga os mesmos princípios que qualquer outro mecanismo de simultaneidade, as diretrizes a seguir poderão ajudá\-lo a usar essas bibliotecas junto com eficiência.  
  
-   Um thread deve chamar [CoInitializeEx](http://msdn.microsoft.com/library/windows/desktop/ms695279) antes que usa a biblioteca COM.  
  
-   Um thread pode chamar `CoInitializeEx` várias vezes enquanto fornece os mesmos argumentos a cada chamada.  
  
-   Para cada chamada a `CoInitializeEx`, um thread também deve chamar [CoUninitialize](http://msdn.microsoft.com/library/windows/desktop/ms688715).  Ou seja as chamadas a `CoInitializeEx` e `CoUninitialize` devem ser equilibrados.  
  
-   Para alternar de um STA. de thread para outro, um thread deve completamente liberar a biblioteca COM antes de chamar `CoInitializeEx` com a nova especificação de threading.  
  
 Outros fundamentos de COM se aplicam quando você usa COM com o tempo de execução de simultaneidade.  Por exemplo, um aplicativo que cria um objeto em um STA. de thread único \(STA\) e em que realiza marshaling objeto para outro STA. também deve fornecer um loop de mensagem para mensagens de entrada do processo.  Lembre\-se também que o marshaling objetos entre construção pode diminuir o desempenho.  
  
### Usar COM com a Biblioteca de Padrões Paralela  
 Quando você usa COM com um componente em paralelo da biblioteca \(PPL\), por exemplo, um grupo de trabalho ou um algoritmo paralelo, uma chamada `CoInitializeEx` antes de usar a biblioteca COM durante cada tarefa ou iteração, e uma chamada `CoUninitialize` antes de cada tarefa ou de conclusão da iteração.  O exemplo a seguir mostra como gerenciar o tempo de vida da biblioteca COM com um objeto de [concurrency::structured\_task\_group](../../parallel/concrt/reference/structured-task-group-class.md) .  
  
 [!code-cpp[concrt-parallel-scripts#1](../../parallel/concrt/codesnippet/CPP/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_1.cpp)]  
  
 Você deve ter certeza de que a biblioteca COM é liberada corretamente quando uma tarefa ou um algoritmo paralelo será cancelado ou quando o corpo da tarefa gerencie uma exceção.  Para garantir que a tarefa chame `CoUninitialize` antes de encerrar, use um bloco `try-finally` ou o padrão *Aquisição de recursos é inicialização* \(RAII\).  O exemplo a seguir usa um bloco de `try-finally` para liberar a biblioteca COM quando a tarefa é concluída ou será cancelada, ou quando uma exceção será lançada.  
  
 [!code-cpp[concrt-parallel-scripts#2](../../parallel/concrt/codesnippet/CPP/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_2.cpp)]  
  
 O exemplo a seguir usa o padrão de RAII para definir a classe de `CCoInitializer` , que gerencia o tempo de vida da biblioteca COM em um escopo fornecido.  
  
 [!code-cpp[concrt-parallel-scripts#3](../../parallel/concrt/codesnippet/CPP/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_3.cpp)]  
  
 Você pode usar a classe de `CCoInitializer` para liberar automaticamente como segue a biblioteca COM quando a tarefa é encerrado.  
  
 [!code-cpp[concrt-parallel-scripts#4](../../parallel/concrt/codesnippet/CPP/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_4.cpp)]  
  
 Para obter mais informações sobre de cancelamento em tempo de execução de simultaneidade, consulte [Cancelamento](../../parallel/concrt/cancellation-in-the-ppl.md).  
  
### Usando COM com Agentes Assíncronos  
 Quando você usar COM agentes com assíncronas, chame `CoInitializeEx` antes de usar a biblioteca com no método de [concurrency::agent::run](../Topic/agent::run%20Method.md) para o agente.  Na chamada `CoUninitialize` antes do método de `run` retorna.  Não use rotinas de gerenciamento do no ou no construtor destruidor do agent, e não substituir os métodos de [concurrency::agent::start](../Topic/agent::start%20Method.md) ou de [concurrency::agent::done](../Topic/agent::done%20Method.md) uma vez que esses métodos são chamados de um thread diferente do método de `run` .  
  
 O exemplo a seguir mostra uma classe básica do agent, `CCoAgent`nomeado, que gerencia a biblioteca COM no método de `run` .  
  
 [!code-cpp[concrt-parallel-scripts#5](../../parallel/concrt/codesnippet/CPP/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_5.cpp)]  
  
 Um exemplo completo é fornecida posteriormente neste passo a passo.  
  
### Usando COM com Tarefas Leves  
 O documento [Agendador de Tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md) descreve a função de tarefas de peso leve em tempo de execução de simultaneidade.  Você pode usar COM a uma tarefa de peso leve exatamente como você faria com qualquer a rotina de thread que você passar à função de `CreateThread` na API do windows.  Isso é mostrado no exemplo a seguir.  
  
 [!code-cpp[concrt-parallel-scripts#6](../../parallel/concrt/codesnippet/CPP/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_6.cpp)]  
  
## Um Exemplo de um Aplicativo Habilitado para COM  
 Esta seção mostra um aplicativo COM\- habilitado completo que usa a interface de `IScriptControl` para executar um script que calcula o número<sup>º</sup> de Fibonacci em.  As chamadas desse exemplo primeiro o script do thread principal, e usar o PPL e os agentes para chamar simultaneamente o script.  
  
 Considere a seguinte função auxiliar, `RunScriptProcedure`, que chama um procedimento em um objeto de `IScriptControl` .  
  
 [!code-cpp[concrt-parallel-scripts#7](../../parallel/concrt/codesnippet/CPP/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_7.cpp)]  
  
 A função de `wmain` cria um objeto de `IScriptControl` , adicionar o código de script que computa o<sup>º</sup> número de Fibonacci em, e chame a função de `RunScriptProcedure` para executar esse script.  
  
 [!code-cpp[concrt-parallel-scripts#8](../../parallel/concrt/codesnippet/CPP/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_8.cpp)]  
  
### Chamando o Script da PPL  
 A seguinte função, `ParallelFibonacci`, o usa o algoritmo de [concurrency::parallel\_for](../Topic/parallel_for%20Function.md) para chamar em paralelo o script.  Essa função usa a classe de `CCoInitializer` para gerenciar o tempo de vida da biblioteca COM durante cada iteração da tarefa.  
  
 [!code-cpp[concrt-parallel-scripts#9](../../parallel/concrt/codesnippet/CPP/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_9.cpp)]  
  
 Para usar a função de `ParallelFibonacci` com o exemplo, adicione o seguinte código antes que a função de `wmain` retorna.  
  
 [!code-cpp[concrt-parallel-scripts#10](../../parallel/concrt/codesnippet/CPP/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_10.cpp)]  
  
### Chamando o Script de um Agente  
 O exemplo a seguir mostra a classe de `FibonacciScriptAgent` , que chama um procedimento de script para calcular o número<sup>º</sup> de Fibonacci em.  A classe de `FibonacciScriptAgent` usa a mensagem que transmite para receber, o programa principal, valores de entrada à função de script.  O método de `run` gerencia o tempo de vida da biblioteca COM durante toda a tarefa.  
  
 [!code-cpp[concrt-parallel-scripts#11](../../parallel/concrt/codesnippet/CPP/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_11.cpp)]  
  
 A seguinte função, `AgentFibonacci`, criar vários objetos de `FibonacciScriptAgent` e usa a mensagem que transmite para enviar vários valores de entrada 2 esses objetos.  
  
 [!code-cpp[concrt-parallel-scripts#12](../../parallel/concrt/codesnippet/CPP/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_12.cpp)]  
  
 Para usar a função de `AgentFibonacci` com o exemplo, adicione o seguinte código antes que a função de `wmain` retorna.  
  
 [!code-cpp[concrt-parallel-scripts#13](../../parallel/concrt/codesnippet/CPP/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_13.cpp)]  
  
### O Exemplo Completo  
 O código a seguir mostra o exemplo completo, que usa algoritmos paralelos e agentes assíncronas para chamar um procedimento de script que calcula números de Fibonacci.  
  
 [!code-cpp[concrt-parallel-scripts#14](../../parallel/concrt/codesnippet/CPP/walkthrough-using-the-concurrency-runtime-in-a-com-enabled-application_14.cpp)]  
  
 O exemplo gerencia a seguinte saída de exemplo.  
  
  **Thread principal:**  
**mentir \(15\) \= 610**  
**Os Fibonacci:**  
**mentir \(15\) \= 610**  
**mentir \(10\) \= 55**  
**mentir \(16\) \= 987**  
**mentir \(18\) \= 2584**  
**mentir \(11\) \= 89**  
**mentir \(17\) \= 1597**  
**mentir \(19\) \= 4181**  
**mentir \(12\) \= 144**  
**mentir \(13\) \= 233**  
**mentir \(14\) \= 377**  
**Agente Fibonacci:**  
**mentir \(30\) \= 832040**  
**mentir \(22\) \= 17711**  
**mentir \(10\) \= 55**  
**mentir \(12\) \= 144**   
## Compilando o código  
 Copie o código de exemplo e cole\-o em um projeto do Visual Studio, ou cole\-o em um arquivo chamado `parallel-scripts.cpp` e execute o comando a seguir em uma janela de prompt de comando do Visual Studio.  
  
 **cl.exe \/EHsc parallel\-scripts.cpp \/link ole32.lib**  
  
## Consulte também  
 [Instruções passo a passo do Tempo de Execução de Simultaneidade](../Topic/Concurrency%20Runtime%20Walkthroughs.md)   
 [Paralelismo da tarefa](../../parallel/concrt/task-parallelism-concurrency-runtime.md)   
 [Algoritmos paralelos](../Topic/Parallel%20Algorithms.md)   
 [Agentes assíncronos](../../parallel/concrt/asynchronous-agents.md)   
 [Tratamento de Exceção](../Topic/Exception%20Handling%20in%20the%20Concurrency%20Runtime.md)   
 [Cancelamento](../../parallel/concrt/cancellation-in-the-ppl.md)   
 [Agendador de Tarefas](../../parallel/concrt/task-scheduler-concurrency-runtime.md)