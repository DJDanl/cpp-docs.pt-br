---
title: "Como: especificar políticas de Agendador específicas | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- specifying scheduler policies [Concurrency Runtime]
- scheduler policies, specifying [Concurrency Runtime]
ms.assetid: 9c5149f9-ac34-4ff3-9e79-0bad103e4e6b
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: af30b38a89eb7e4b50c7d31be2d3ba6572843b1e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-specify-specific-scheduler-policies"></a>Como especificar políticas de agendador específicas
Políticas de Agendador permitem que você controle a estratégia que o Agendador usa quando ele gerencia as tarefas. Este tópico mostra como usar uma política de Agendador para aumentar a prioridade de thread de uma tarefa que imprime um indicador de progresso para o console.  
  
 Para obter um exemplo que usa políticas de Agendador personalizado juntamente com agentes assíncronos, consulte [como: criar políticas de Agendador específicas que Use a agentes](../../parallel/concrt/how-to-create-agents-that-use-specific-scheduler-policies.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir executa duas tarefas em paralelo. A primeira tarefa calcula o n<sup>th</sup> Fibonacci número. A segunda tarefa imprime um indicador de progresso para o console.  
  
 A primeira tarefa usa Decomposição recursiva para calcular o número de Fibonacci. Ou seja, cada tarefa recursivamente cria subtarefas para calcular o resultado geral. Uma tarefa que usa a decomposição recursiva pode usar todos os recursos disponíveis e assim enfraquecer outras tarefas. Neste exemplo, a tarefa que imprime o indicador de progresso pode não receber acesso imediato a recursos de computação.  
  
 Para fornecer a tarefa que imprime um acesso razoável de mensagem de progresso para recursos de computação, este exemplo usa as etapas descritas em [como: gerenciar uma instância de Agendador](../../parallel/concrt/how-to-manage-a-scheduler-instance.md) para criar uma instância de agendador que tem uma política personalizada. A política personalizada Especifica a prioridade de thread para a classe de prioridade mais alta.  
  
 Este exemplo usa o [concurrency::call](../../parallel/concrt/reference/call-class.md) e [concurrency::timer](../../parallel/concrt/reference/timer-class.md) classes para imprimir o indicador de progresso. Essas classes têm versões dos seus construtores que usam uma referência a um [concurrency::Scheduler](../../parallel/concrt/reference/scheduler-class.md) objeto que agenda-los. O exemplo usa o agendador padrão para agendar a tarefa que calcula o número de Fibonacci e a instância de Agendador para agendar a tarefa que imprime o indicador de progresso.  
  
 Para ilustrar os benefícios de usar um agendador que tem uma política personalizada, este exemplo executa a tarefa duas vezes. Primeiro, o exemplo usa o agendador padrão para agendar as duas tarefas. O exemplo usa o agendador padrão para agendar a primeira tarefa e um agendador que tem uma política personalizada para agendar a tarefa de segundo.  
  
 [!code-cpp[concrt-scheduler-policy#1](../../parallel/concrt/codesnippet/cpp/how-to-specify-specific-scheduler-policies_1.cpp)]  
  
 Este exemplo gerencia a seguinte saída.  
  
```Output  
Default scheduler:  
...........................................................................done  
Scheduler that has a custom policy:  
...........................................................................done  
```  
  
 Embora os dois conjuntos de tarefas produzem o mesmo resultado, a versão que usa uma política personalizada permite que a tarefa que imprime o indicador de progresso seja executada em uma prioridade com privilégios elevados para que ele se comporta mais responsively.  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `scheduler-policy.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe /EHsc Agendador-policy.cpp**  
  
## <a name="see-also"></a>Consulte também  
 [Políticas de Agendador](../../parallel/concrt/scheduler-policies.md)   
 [Como: gerenciar uma instância de Agendador](../../parallel/concrt/how-to-manage-a-scheduler-instance.md)   
 [Como criar agentes que usam políticas de agendador específicas](../../parallel/concrt/how-to-create-agents-that-use-specific-scheduler-policies.md)

